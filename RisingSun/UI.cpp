/******************************************************************************
Module:  readDFCF.cpp
Notices: Copyright (c) 2008 Jeffrey Richter & Christophe Nasarre
******************************************************************************/

#include "..\CommonFiles\CmnHdr.h"     /* See Appendix A. */
#include "..\CommonFiles\Toolhelp.h"
#include <windowsx.h>
#include <tchar.h>
#include <strsafe.h>
#include "Resource.h"
#include <string.h>
#include <stdio.h>
#include <malloc.h>        // For alloca
#include <TlHelp32.h>
#include "..\RisingSun\constant.h"
#include "Data.h"
#include "UI.h"

//#include "..\RisingSun\TechAnalyse.h"

extern CDISPLAY  g_usrDisplay;
//CINTEGER_QUEUE	  g_usrReadDFCFQueue;  //��ȡ�����Ƹ���Ϣ���У���ReadDFCFThread�߳�ʹ��
int		g_nAutoClickMode = 0;
POINT	m_ptCorPos;//�Զ��ظ�click��λ��
HWND	m_hWnd = 0;
int     g_nAllStocksCount = 0;

void   AddData2ReadDFCFThreadQueue(int i1=0, int i2 = 0, int i3 = 0 )
{
	//g_usrReadDFCFQueue.PushData(i1, i2, i3);
}


void OnSize(HWND hWnd, UINT state, int cx, int cy) {

   SetWindowPos(GetDlgItem(hWnd, IDC_INFO), NULL, 
      0, 0, cx, cy, SWP_NOZORDER);
}

void OnCommand(HWND hWnd, int id, HWND hWndCtl, UINT codeNotify) {

   switch (id) {
      case IDCANCEL:
         EndDialog(hWnd, id);
         break;
   }
}

int FindStockInL2Ticks(CSTOCKDATAS *pStockData, int nStockCode)
{
	int nReturn = -1;
	static int nCount = 0;

	if (nStockCode > 0)
	{
		for (nReturn = 0; nReturn < nCount && pStockData[nReturn].m_nStockCode>0; nReturn++)
			if (pStockData[nReturn].m_nStockCode == nStockCode)
				break;

		if (nReturn == nCount )
		{
			nCount++;
			if (nCount >= MAXSTOCKS)
			{
				nCount = 0;
				nReturn = 0;//ѭ��ʹ���б�
			}
		}
	}

	return nReturn;
}

///////////////////////////////////////////////////////////////////////////////
//����ע��Ĵ���ķ��ص���Ϣ

BOOL OnCopyData(HWND hWnd, HWND hWndFrom, PCOPYDATASTRUCT pcds) {
	static int nStockCode = 0, nTradeDate = 0, nStockIndex=0;
	char  szTmp[260] = {0};
	switch (pcds->dwData)
	{
	case 0x99:
		nStockCode = *(DWORD*)(((BYTE*)pcds->lpData));
		nTradeDate = *(DWORD*)(((BYTE*)pcds->lpData+4));
		nStockIndex =FindStockInL2Ticks(g_usrStockData, nStockCode);
		break;

	case 0x100:
		//���ڲɼ�ticksģʽ�¼�¼���� && g_nAutoClickMode==ID_HOT_GET_L2TICKS
		if (nStockIndex > -1 && nStockCode>0  )
		{
			g_usrStockData[nStockIndex].m_nStockCode = nStockCode;
			g_usrStockData[nStockIndex].m_nTradeDate = nTradeDate;
			if(g_usrStockData[nStockIndex].AddL2Ticks(pcds))
				if (g_usrStockData[nStockIndex].SaveTicksData())
				{
					sprintf_s(szTmp, "SAVE %06d  ticks data,Index=%d",
						g_usrStockData[nStockIndex].m_nStockCode,g_nAllStocksCount);

					g_usrDisplay.AddMsg(hWnd, szTmp);
				}
		}
		
		break;

	case 0x101:
		//�ʽ�����Ϣ
		if (nStockIndex > -1  && nStockCode>0/*&& g_nAutoClickMode == ID_HOT_GET_CAPITAL*/)
		{
			g_usrStockData[nStockIndex].m_nStockCode = nStockCode;
			g_usrStockData[nStockIndex].m_nTradeDate = nTradeDate;
			if (g_usrStockData[nStockIndex].AddCapitalFlow(pcds))
			{
				
				if (g_usrStockData[nStockIndex].SaveCapitalData())
				{
					sprintf_s(szTmp, "SAVE %06d  flow data,Index=%d",
						g_usrStockData[nStockIndex].m_nStockCode,g_nAllStocksCount);

					g_usrDisplay.AddMsg(hWnd, szTmp);
				}
				
				//g_usrTAQueue.PushData(nStockIndex, STOCKDATACHANGE_CAPITALFLOW);
			}
				

		}
		break;
	case 0x102:
		//K������Ϣ
		break;
	case 0x201:
		//��TradeThread������Ϣ���ﵽһ���̶Ȼᶪ���ݣ�����  todo  �����Ƕ��߳������µ�����ʾ��Ϣ��ͻ
		
		//g_usrDisplay.AddMsg(hWnd, (char*)pcds->lpData);
		break;
	}

   SetWindowPos(m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
   return(TRUE);
}


///////////////////////////////////////////////////////////////////////////////

BOOL OnInitDialog(HWND hWnd, HWND hWndFocus, LPARAM lParam) {

	chSETDLGICONS(hWnd, IDI_LASTMSGBOXINFO);
	char		szTmp[260] = { 0 };
	
	char szModName[MAX_PATH * 10] = { 0 };
	regVirtualMouseHotKey(hWnd);
	g_nAutoClickMode = 0;
	m_hWnd = hWnd;

	sprintf_s(szTmp, "��CTRL-F10 ��ȡ���洢�ʽ���,CTRL-F11��ȡ���洢�ֱ�����,CTRL-F12 ��ȡ���洢�ʽ��K�����ݣ�");
	g_usrDisplay.AddMsg(hWnd, szTmp);

	return(TRUE);
}

INT_PTR WINAPI DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	char		szTmp[260] = { 0 };

	switch (uMsg) 
	{
		chHANDLE_DLGMSG(hWnd, WM_COPYDATA, OnCopyData);
		chHANDLE_DLGMSG(hWnd, WM_INITDIALOG, OnInitDialog);
		chHANDLE_DLGMSG(hWnd, WM_SIZE, OnSize);
		chHANDLE_DLGMSG(hWnd, WM_COMMAND, OnCommand);

		case WM_CREATE:						//��������ʱ����س�ʼ��
			regVirtualMouseHotKey(hWnd);
			break;
		case WM_HOTKEY:						//�����ȼ���Ϣ
			dealWithHotKey(hWnd, wParam);			
			return 0;
		case WM_ACTIVATE:
			/*sprintf_s(szTmp, "���ݱ�����ϣ���CTRL---F10/F11�������ݲ���");
			g_usrDisplay.AddMsg(hWnd, szTmp);*/
			break;
	}
	return(FALSE);
}

void CALLBACK OnTimer(
	HWND hwnd,
	UINT message,
	UINT idTimer,
	DWORD dwTime)
{
	static bool bNewData = false;
	static int nLastMode = 0;
	char szTmp[260] = { 0 };
	if (g_nAutoClickMode)
	{
		SetCursorPos(m_ptCorPos.x, m_ptCorPos.y);
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		bNewData = true;
		g_nAllStocksCount++;
		if (g_nAllStocksCount>4000)
		{
			g_nAutoClickMode = 0;
			g_nAllStocksCount = 0;// ȫ����Ʊ��ѯ���Զ�ֹͣ��ѯ
		}
	}

	if(bNewData &&  g_nAutoClickMode==0)
	{
		bNewData = false;
		g_nAllStocksCount = 0;
	}

	nLastMode = g_nAutoClickMode;//use for check status changed

}
	
//////////////////////////////////////////////////////////////////////////

//ע���ȼ�
void regVirtualMouseHotKey(HWND hwnd)
{
	RegisterHotKey(hwnd, ID_HOT_GET_CAPITAL, MOD_CONTROL, VK_F10);			//ע�� Ctrl + f10 , �ʽ�����ȡ
	RegisterHotKey(hwnd, ID_HOT_GET_L2TICKS, MOD_CONTROL, VK_F11);			//ע�� Ctrl + f11 , L2 ticks
	RegisterHotKey(hwnd, ID_HOT_GET_CAPITAL_AND_KLINE, MOD_CONTROL, VK_F12);			//ע�� Ctrl + 12 , ID_HOT_GET_CAPITAL_AND_KLINE
}


//����ע����ȼ�
void destroyRegedHotKey(HWND hwnd)
{
	int hotID = ID_HOT_UP;
	for (hotID; hotID <= ID_HOT_MIDDLE_PRESS; hotID++)
		UnregisterHotKey(hwnd, hotID);
}



//�����ȼ���Ϣ
void dealWithHotKey(HWND hwnd, WPARAM wParam)
{
	POINT ptCorPos;
	GetCursorPos(&ptCorPos);

	switch (wParam)
	{
		/*
		case ID_HOT_GET_CAPITAL_AND_KLINE:		//��ͣ\������ȡ�ʽ���+k LINE��Ϣ  f12
			if (!g_nAutoClickMode)
			{
				g_nAllStocksCount = 0;
				g_nAutoClickMode = ID_HOT_GET_CAPITAL_AND_KLINE;
				SetWindowPos(m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
				GetCursorPos(&m_ptCorPos);
				SetTimer(NULL, ID_HOT_GET_CAPITAL_AND_KLINE, 2500, OnTimer);

			}
			else if (g_nAutoClickMode == ID_HOT_GET_CAPITAL_AND_KLINE)
			{
				KillTimer(NULL, ID_HOT_GET_CAPITAL_AND_KLINE);
				g_nAutoClickMode = 0;
			}
			break;
		*/
		case ID_HOT_GET_CAPITAL:			//��ͣ\������ȡ�ʽ�����Ϣ  f10
			if (!g_nAutoClickMode)
			{
				g_nAllStocksCount = 0;
				g_nAutoClickMode = ID_HOT_GET_CAPITAL;
				SetWindowPos(m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
				GetCursorPos(&m_ptCorPos);
				SetTimer(NULL, ID_HOT_GET_CAPITAL, 1500, OnTimer);
				
			}
			else if (g_nAutoClickMode == ID_HOT_GET_CAPITAL)
			{
				KillTimer(NULL, ID_HOT_GET_CAPITAL);
				g_nAutoClickMode = 0;
			}
			
			break;

		case ID_HOT_GET_L2TICKS:			//��ͣ\������ȡL2 TICKS��Ϣ  f11
			if (!g_nAutoClickMode)
			{
				g_nAutoClickMode = ID_HOT_GET_L2TICKS;
				g_nAllStocksCount = 0;
				SetWindowPos(m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
				GetCursorPos(&m_ptCorPos);
				KillTimer(NULL, ID_HOT_GET_L2TICKS);
				SetTimer(NULL, ID_HOT_GET_L2TICKS, 1500, OnTimer);
			}
			else if(g_nAutoClickMode== ID_HOT_GET_L2TICKS)
			{
				KillTimer(NULL, 1);
				g_nAutoClickMode = 0;
			}

			break;
	}
	
}

int  InitUI(HINSTANCE hInstExe) {
	
	/*THREADPARAMETERS  usrReadDFCFThreadParam =
	{ &g_usrReadDFCFQueue,NULL,NULL,NULL };

	HANDLE hTAThread = CreateThread(NULL, 0, ReadDFCFThread, &usrReadDFCFThreadParam, 0, 0);*/
	//����һ��ģ̬���壬��dfcf��ȫ��������Ϣ��ע�뵽DFCF��ַ�ؼ���DLLʵ�֡�
	//���������Զ��ע����ں�̨�����������б�Ҫʱ�ö����߳���������������������������
	DialogBox(hInstExe, MAKEINTRESOURCE(IDD_LASTMSGBOXINFO), NULL, DlgProc);

	return(0);
}





//////////////////////////////// End of File //////////////////////////////////
