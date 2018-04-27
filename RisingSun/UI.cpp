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
//CINTEGER_QUEUE	  g_usrReadDFCFQueue;  //读取东方财富信息队列，由ReadDFCFThread线程使用
int		g_nAutoClickMode = 0;
POINT	m_ptCorPos;//自动重复click的位置
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
				nReturn = 0;//循环使用列表
			}
		}
	}

	return nReturn;
}

///////////////////////////////////////////////////////////////////////////////
//处理被注入的窗体的返回的信息

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
		//仅在采集ticks模式下记录数据 && g_nAutoClickMode==ID_HOT_GET_L2TICKS
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
		//资金流信息
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
		//K线流信息
		break;
	case 0x201:
		//从TradeThread来的信息量达到一定程度会丢数据，待查  todo  可能是多线程条件下调度显示信息冲突
		
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

	sprintf_s(szTmp, "按CTRL-F10 读取并存储资金流,CTRL-F11读取并存储分笔数据,CTRL-F12 读取并存储资金和K线数据，");
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

		case WM_CREATE:						//创建创建时的相关初始化
			regVirtualMouseHotKey(hWnd);
			break;
		case WM_HOTKEY:						//处理热键消息
			dealWithHotKey(hWnd, wParam);			
			return 0;
		case WM_ACTIVATE:
			/*sprintf_s(szTmp, "数据保存完毕，按CTRL---F10/F11启动数据捕获");
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
			g_nAllStocksCount = 0;// 全部股票查询后自动停止查询
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

//注册热键
void regVirtualMouseHotKey(HWND hwnd)
{
	RegisterHotKey(hwnd, ID_HOT_GET_CAPITAL, MOD_CONTROL, VK_F10);			//注册 Ctrl + f10 , 资金流获取
	RegisterHotKey(hwnd, ID_HOT_GET_L2TICKS, MOD_CONTROL, VK_F11);			//注册 Ctrl + f11 , L2 ticks
	RegisterHotKey(hwnd, ID_HOT_GET_CAPITAL_AND_KLINE, MOD_CONTROL, VK_F12);			//注册 Ctrl + 12 , ID_HOT_GET_CAPITAL_AND_KLINE
}


//撤销注册的热键
void destroyRegedHotKey(HWND hwnd)
{
	int hotID = ID_HOT_UP;
	for (hotID; hotID <= ID_HOT_MIDDLE_PRESS; hotID++)
		UnregisterHotKey(hwnd, hotID);
}



//处理热键消息
void dealWithHotKey(HWND hwnd, WPARAM wParam)
{
	POINT ptCorPos;
	GetCursorPos(&ptCorPos);

	switch (wParam)
	{
		/*
		case ID_HOT_GET_CAPITAL_AND_KLINE:		//暂停\继续读取资金流+k LINE信息  f12
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
		case ID_HOT_GET_CAPITAL:			//暂停\继续读取资金流信息  f10
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

		case ID_HOT_GET_L2TICKS:			//暂停\继续读取L2 TICKS信息  f11
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
	//生成一个模态窗体，与dfcf的全部交互信息由注入到DFCF地址控件的DLL实现。
	//本程序完成远程注入后在后台工作，将来有必要时用独立线程启动，主程序继续完成其他工作
	DialogBox(hInstExe, MAKEINTRESOURCE(IDD_LASTMSGBOXINFO), NULL, DlgProc);

	return(0);
}





//////////////////////////////// End of File //////////////////////////////////
