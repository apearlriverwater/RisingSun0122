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
#include "constant.h"
#include "Data.h"
#include "UI.h"
#include "InjDFCF.h"
//#include "gmTrade.h"
//#include "TechAnalyse.h"

// The head of the linked-list of CAPIHook objects
CAPIHook* CAPIHook::sm_pHead = NULL;

// By default, the module containing the CAPIHook() is not hooked
BOOL CAPIHook::ExcludeAPIHookMod = TRUE;

//CRISINGSUNTRADER	g_usrTrader;
//CINTEGER_QUEUE		g_usrTradeQueue;  //���������������,��¼��������������У���TradeThread�߳�ʹ��
//CINTEGER_QUEUE		g_usrTAQueue;  //������������,��¼������ı�Ĵ�����У���TAThread�߳�ʹ��

CSTOCKDATAS			g_usrStockData[MAXSTOCKS];
CDISPLAY			g_usrDisplay;

//THREADPARAMETERS  g_usrTradeThreadParam =
//{ &g_usrTAQueue,&g_usrTradeQueue,
//g_usrStockData,&g_usrTrader };
extern int  g_nAutoClickMode, g_nAllStocksCount;;

//int  InitUI(HINSTANCE hInstExe);

//���������߳�
/*
DWORD WINAPI TAThread(LPVOID lpParam)
{
	THREADPARAMETERS	*pThreadParam = (THREADPARAMETERS  *)lpParam;
	CINTEGER_QUEUE		*pTAMsgQ = (CINTEGER_QUEUE *)pThreadParam->pTAMsgQ;
	CSTOCKDATAS			*pStockDatas = (CSTOCKDATAS*)pThreadParam->pStockDatas;
	CRISINGSUNTRADER	*pTrader = (CRISINGSUNTRADER  *)pThreadParam->pTrader;
	char	szBuf[260] = {0};
	KLINEDATA pKLineBuffer[MAX_KLINE_COUNT];

	while (true)
	{
		
		if (pTAMsgQ->HasData())  //�鿴�����Ƿ��й�Ʊ����Ϣ�����仯
		{
			int	nStockIndex, nChangedType,nOperation;
			pTAMsgQ->PopData(&nStockIndex, &nChangedType,&nOperation);

			//�ʽ���������ʱ���ַǷ������ڡ�ʱ����Чtodo ��֮
			if (nStockIndex < 0
				|| pStockDatas[nStockIndex].m_nStockCode<1
				|| pStockDatas[nStockIndex].m_pCapitalFlow==NULL)
				continue;
			else
			{
				//���ڡ�ʱ����ܷǷ�
				int nDateTime = pStockDatas[nStockIndex].m_pCapitalFlow->m_nTime;

				if(nDateTime>150000  //����ʱ����Ч
					|| (nDateTime<93000 && nDateTime !=0))
					continue;

				nDateTime = pStockDatas[nStockIndex].m_pCapitalFlow->m_nDate;
				if (nDateTime>20300000  //����������Ч  ��ʱ������2010����2030�������
					|| (nDateTime<20100000))
					continue;
			}

			switch (nChangedType)
			{
			case STOCKDATACHANGE_CAPITALFLOW:
				if (NULL != pStockDatas[nStockIndex].m_pCapitalFlow)
				{
					sprintf_s(szBuf, "���--%06d--�ʽ��� ", (pStockDatas + nStockIndex)->m_nStockCode);
					pTrader->SendMsg2UI(szBuf);

					if ((pStockDatas + nStockIndex)->KLineDataValid() == false)
					{
						char szStartDateTime[32], szStopDateTime[32], szCode[16];
						int	 nWeekInMinutes, nCount;

						(pStockDatas + nStockIndex)->GetKLineMsg(szCode, szStartDateTime, szStopDateTime,
							&nWeekInMinutes, &nCount);

						pTrader->ReadKDataByCapital(pKLineBuffer, &nCount,
							szStartDateTime, szStopDateTime,
							szCode, nWeekInMinutes);

						(pStockDatas + nStockIndex)->CompareFlowKLine(pKLineBuffer, &nCount);

						(pStockDatas + nStockIndex)->AddKlineData(pKLineBuffer, nCount);
						{
							if (g_nAutoClickMode==ID_HOT_GET_CAPITAL_AND_KLINE)
							{
								if ((pStockDatas + nStockIndex)->SaveFlowAndKLine())
								{
									sprintf_s(szBuf, "SAVE %06d--%03d min flow and k line,Index=%d",
										(pStockDatas + nStockIndex)->m_nStockCode, nWeekInMinutes, g_nAllStocksCount);
									pTrader->SendMsg2UI(szBuf);
								}
								
							}
						}
						AddData2ReadDFCFThreadQueue(0, 0, 0);

						pTrader->CaclMainFlow((CINTEGER_QUEUE*)(pTrader->m_hTradeThread), &pStockDatas[nStockIndex]);
					}
					
				}
				break;

			case STOCKDATACHANGE_KLINE:
				sprintf_s(szBuf, "K�߼�������--%06d", (pStockDatas + nStockIndex)->m_nStockCode);
				pTrader->SendMsg2UI(szBuf);

				//K�߼�������
				switch (nChangedType)
				{
					case RISINGSUN_TA_BUY:
						if (pTrader->CaclKLineTrends(&pStockDatas[nStockIndex]))
						{
							pTrader->nBSQueue.PushData(nStockIndex, RISINGSUN_BUY);
							sprintf_s(szBuf, " (%02d)   %06d SELL��", nStockIndex,
								pStockDatas[nStockIndex].m_nStockCode);
							pTrader->SendMsg2UI(szBuf);
						}
						break;
					case RISINGSUN_TA_SELL:
						if (pTrader->CaclKLineTrends(&pStockDatas[nStockIndex], false))
						{
							pTrader->nBSQueue.PushData(nStockIndex, RISINGSUN_SELL);
							sprintf_s(szBuf, " (%02d)   %06d SELL��", nStockIndex, 
								pStockDatas[nStockIndex].m_nStockCode);
							pTrader->SendMsg2UI(szBuf);
						}
						break;
					case RISINGSUN_TA_BUYSELL:

						break;
				}
				break;

			case STOCKDATACHANGE_L2TICKS:
				//AddData2ReadDFCFThreadQueue(0,0,0);
				break;

			default:
				break;
			}
		}
		else
			Sleep(500);

	}
	return 0;
}
*/


//�����߳�
/*
����TAThread�̶߳��ʽ����ķ������ѹ�ע�Ĺ�Ʊ������뱾�̵߳���Ϣ���С�����
��Ϣ���еĹ�Ʊ�������K�ߵ��й����ݽ��������������
*/
/*
DWORD WINAPI TradeThread(LPVOID lpParam)
{
	THREADPARAMETERS    *pThreadParam = (THREADPARAMETERS  *)lpParam;
	CINTEGER_QUEUE		*pTradeMsgQ = (CINTEGER_QUEUE *)pThreadParam->pTradeMsgQ;
	CSTOCKDATAS			*pStockDatas = (CSTOCKDATAS*)pThreadParam->pStockDatas;
	CRISINGSUNTRADER	*pTrader = (CRISINGSUNTRADER  *)pThreadParam->pTrader;
	
	int	nStockCode, nChangedType, nLastWeeks;
	int nStockIndex;

	while (true)
	{
		if (pTradeMsgQ->HasData())  //�鿴�����Ƿ��й�Ʊ����Ϣ�����仯
		{
			try {
				pTradeMsgQ->PopData(&nStockCode, &nChangedType, &nLastWeeks);

				nStockIndex = FindStockInL2Ticks(pStockDatas, nStockCode);
				if (nStockIndex < 0
					|| pStockDatas[nStockIndex].m_nStockCode<1)
					continue;

				switch (nChangedType)
				{
				case FLOWDOWN:
					//�ʽ���ת��ʱ�����Ƿ�߱�����ʱ�������ʽ�������������ȡ��Ӧ���ڵ�K������
					//g_usrTAQueue.PushData(nStockIndex, STOCKDATACHANGE_KLINE, RISINGSUN_TA_SELL);
					break;
				case FLOWUP:
					//�ʽ���ת��ʱ�����Ƿ�߱�����ʱ�������ʽ�������������ȡ��Ӧ���ڵ�K������
					
					break;
				case FLOWNOCHANGED:
					
					break;
				case FLOWTOTALDOWN:

					break;

				case FLOWTOTALUP:
					break;

				case STOCKDATACHANGE_KLINE:
					break;
				case STOCKDATACHANGE_L2TICKS:

					break;

				default:
					break;
				}
			}
			catch (...)
			{

			}
			
		}
		else
			Sleep(500);

	}
	return 0;
}
*/


int WINAPI _tWinMain(HINSTANCE hInstExe, HINSTANCE, PTSTR pszCmdLine, int) {
	

	CAPIHook usrWorkIndDLL(TEXT("mainfree.exe"), TEXT("READDFCF.dll"));  //ʵ���Զ��嶯̬���Զ��ע��

	//g_usrTrader.m_hTAThread = CreateThread(NULL, 0, TAThread, &g_usrTradeThreadParam, 0, 0);
	//g_usrTrader.m_hTradeThread = CreateThread(NULL, 0, TradeThread, &g_usrTradeThreadParam, 0, 0);

	//����һ��ģ̬���壬��dfcf��ȫ��������Ϣ��ע�뵽DFCF��ַ�ؼ���DLLʵ�֡�
	InitUI(hInstExe);
	return(0);
}


//////////////////////////////// End of File //////////////////////////////////
