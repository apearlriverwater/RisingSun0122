#pragma once
#include <stdio.h>
#include <Windows.h>
#include<time.h>
#include <string>
#include <string.h>
#include <iostream>
#include <process.h>
#include "..\gmsdk_c_2.9.9_windows\inc\strategy.h"
#include "Data.h"

#include "TechAnalyse.h"


class CRISINGSUNTRADER;
extern CINTEGER_QUEUE g_usrTradeQueue;  //Ŀǰֻ�ܲ���ȫ�ֱ�����ʽ���з��ʣ�ͨ��ָ�봫�ݵ���Ϣ����

typedef  struct tagTHREADPARAMETERS
{
	CINTEGER_QUEUE    *pTAMsgQ;    //������������
	CINTEGER_QUEUE    *pTradeMsgQ; //���׶���
	CSTOCKDATAS       *pStockDatas;
	CRISINGSUNTRADER  *pTrader;
}THREADPARAMETERS;

//���������ܣ�Ŀǰ���ڶ�ȡK������
//�ɶ����߳�ִ��Ǳ�ڵ���������
class CRISINGSUNTRADER
{
public:
	HANDLE			m_hTAThread,m_hTradeThread;//���������̡߳������߳�
	CINTEGER_QUEUE	nBSQueue;   //��ִ�����������ı�ļ���������У�on_bar�ص�����ʹ��

	CRISINGSUNTRADER()
	{
		int ret;
		//��ʼ������,���������ļ�
		ret = strategy_init("haigezyj@qq.com",
			"zyj2590@1109",
			"a3b22a0e-f7fa-11e7-827b-dc5360304926",
			"",
			MD_MODE_PLAYBACK,//MD_MODE_SIMULATED  MD_MODE_LIVE MD_MODE_PLAYBACK
			"localhost:8001");
		//ret = strategy_init_with_config("RisingSun.ini");

		/*if (ret)
		{
			_Debug_message(L"gmTrade", L"Trader init error!", ret);
		}*/
	}

	~CRISINGSUNTRADER()
	{
		if (m_hTAThread)
		{
			TerminateThread(m_hTAThread, 0);
			m_hTAThread = NULL;
		}
			
	}
	void on_login()
	{
	}

	void on_error(int ec, const char *lp)
	{
	}

	//�����ʱ�����¼�
	static void on_bar(Bar *bar)
	{
		char szBuf[260];
		sprintf_s(szBuf, "%s %s cloase=%03.2f\n", bar->strendtime, bar->sec_id, bar->close);
		printf_s(szBuf);
	}

	//����ί�лر��¼�
	void on_execrpt(ExecRpt *res) {}

	void on_order_status(Order *res) {}

	//ί�лر���������(�ص��ӿ�: ��������)
	void on_order_new(Order *res) {}

	//ί�лر���������(�ص��ӿڣ�������ȫ�ɽ�)
	void on_order_filled(Order *res) {}

	//ί�лر���������(�ص��ӿڣ��������ֳɽ�)
	void on_order_partiall_filled(Order *res) {}

	//ί�лر���������(�ص��ӿڣ�����ֹͣ)
	void on_order_stop_executed(Order *res) {}

	//ί�лر���������(�ص��ӿڣ����������ɹ�)
	void on_order_canceled(Order *res) {}

	//ί�лر���������(�ص��ӿڣ�����ʧ��)
	void on_order_cancel_rejected(ExecRpt *res) {}
	int mainTrade()
	{
		Bar *bars = nullptr;
		int count = 0;
		char szBuf[260];

		int ret = gm_md_get_bars("SZSE.000710", 60 * 30,
			"2017-08-18 09:30:00", "2018-01-12 15:15:00",
			&bars, &count);

		for (int i = 0; i < count; i++)
		{
			sprintf_s(szBuf, "%s,%s,%f,%f", bars[i].sec_id,
				bars[i].strtime, bars[i].close, bars[i].high);
		}



		//��ʽһ�����Իز��������  20170818--20180112
		/*ret = strategy_backtest_config("2017-08-18 09:30:00", "2018-01-12 15:15:00",
				1000000, 1, 0.0003, 0.246, 1);
		ret = gm_md_subscribe("SZSE.000710.bar.30");*/

		
		// �����¼��ص�����
		/*gm_td_set_login_callback(on_login);
		gm_td_set_error_callback(on_error);*/
		gm_md_set_bar_callback(on_bar);
		/*gm_td_set_execrpt_callback(on_execrpt);
		gm_td_set_order_status_callback(on_order_status);
		gm_td_set_order_new_callback(on_order_new);
		gm_td_set_order_filled_callback(on_order_filled);
		gm_td_set_order_partially_filled_callback(on_order_partiall_filled);
		gm_td_set_order_stop_executed_callback(on_order_stop_executed);
		gm_td_set_order_cancelled_callback(on_order_canceled);
		gm_td_set_order_cancel_rejected_callback(on_order_cancel_rejected);*/


		//printf("�����𶯳ɹ�! %s\n", gm_strerror(ret));

		// ִ�в��ȴ��������н���
		ret = gm_run();

		//���ж�ִ�н����ʵ����ά����������Ϣͳһ�����log���ھ���ն˲鿴����
		if (ret)
		{
			cout << "error:" << ret << " msg:" << gm_strerror(ret) << endl;
		}

		return 0;
	}

	//��ȡK������  ����ʵʱ״̬�������ݵĵ�������
	int ReadKDataByCapital(KLINEDATA *pBar, int *nRecords,
	    char *szStartDateTime,char *szStopDateTime,
		char *szCode,int nWeeksInMinutes)
	{
		/**
		* @brief ��ʱBar���ݽṹ
		���ڽ�����ݶ��벻һ�µ����⣺ticksҪ������ֽڶ��룬��gm������8�ֽڶ���
		*
		*/
		typedef struct myBar
		{
			char                    exchange[LEN_EXCHANGE];       ///<����������
			char                    sec_id[LEN_SECID];            ///<֤ȯID
			int                     bar_type;                     ///<��ʱ��������(enum BarType)
			int		                nNoUsed;  //++++++
			double                  utc_time;                     ///bar�Ŀ�ʼʱ��
			char                    strtime[LEN_ISO_DATATIME+4];    ///bar�Ŀ�ʼʱ��  ����8�ֽ�
			double                  utc_endtime;                  ///bar�Ľ���ʱ��
			char                    strendtime[LEN_ISO_DATATIME]; ///bar�Ľ���ʱ��

			float                   open;                         ///<���̼�
			float                   close;                        ///<���̼�
			float                   high;                         ///<��߼�
			float                   low;                          ///<��ͼ�
			int		                nNoUsed1;  //++++++ ����8�ֽ�
			double                  volume;                       ///<�ɽ���
			double                  amount;                       ///<�ɽ����
			float                   pre_close;                    ///ǰ���̼�
			int		                nNoUsed2;  //++++++����8�ֽ�
			long long                position;                    ///<�ֲ���
			float                   adj_factor;                   //��Ȩ����
			int                     flag;                         //��Ȩ��Ϣ��ͣ�Ƶȱ��
		}myBar;

		myBar *bars = nullptr;
		int count = 0,nReadCount=0,i;
		char  szStart[128] = { 0 };
		/*gm_md_get_bars("SZSE.000710", 60 * 30,
			"2017-08-18 09:30:00", "2018-01-12 15:15:00",
			&bars, &count);*/
		sprintf_s(szStart, "%s", szStartDateTime);

		do 
		{
			//ע�⣺û�н���ʱ������K�����ݣ��������ʽ�������Ӧ  ��ʱû����Ӧ
			gm_md_get_bars(szCode, 60 * nWeeksInMinutes,
				szStart, szStopDateTime,
				(Bar**)&bars, &count);

			if (count == 0)
				break;


			//K���ݸ�ʽת��
			for ( i = 0; i <min(count,MAX_KLINE_COUNT); i++)
			{
				int  j = i+ nReadCount;
				pBar[j].utcStop = bars[i].utc_endtime;
				memcpy_s(&pBar[j].open, 32, &bars[i].open, 32);
				pBar[j].volume = bars[i].volume;
				pBar[j].amount = bars[i].amount;
			}

			nReadCount += count;
			int nDate, nTime;
			pBar[count - 1].UTC2DateTime(&nDate, &nTime);
			sprintf_s(szStart, 32, "%4d-%02d-%02d %02d:%02d:00",
				nDate / 10000,
				(nDate % 10000) / 100,
				nDate % 100,
				nTime / 10000,
				(nTime % 10000) / 100 );
			

		} while (nReadCount<*nRecords && strstr(szStart,szStopDateTime)==NULL);

		*nRecords = nReadCount;
		
		return nReadCount;
	}

	int ReadKData(KLINEDATA *pBar,int *nRecords)
	{
		Bar *bars = nullptr;
		int count = 0;

		gm_md_get_bars("SZSE.000710", 60 * 30,
			"2017-08-18 09:30:00", "2018-01-12 15:15:00",
			&bars, &count);
		
		//K���ݸ�ʽת��
		for (int i = 0; i <min (count, *nRecords); i++)
		{
			pBar[i].utcStop = bars[i].utc_endtime;
			memcpy_s(&pBar[i].open, 16,&bars[i].open, 16);
			pBar[i].volume = bars[i].volume;
			pBar[i].amount = bars[i].amount;
		}

		*nRecords = count;
		return count;
	}

	//K�����Ƽ������:MA  RSI SAR MACD
	bool CaclKLineTrends(CSTOCKDATAS *pStockData,bool bCheckBuy=true)
	{
		bool bRet = false;
		char szBuf[260] = { 0 };

		//��ֹͬһ���ڶ�μ���
		static int nLastCaclCode = 0;
		static double  dblLastUTC = 0;
		if (nLastCaclCode == pStockData->m_nStockCode
			&& dblLastUTC == pStockData->m_pKLineData[pStockData->m_nKCount - 1].utcStop)
			return false;
		else
		{
			nLastCaclCode = pStockData->m_nStockCode;
			dblLastUTC = pStockData->m_pKLineData[pStockData->m_nKCount - 1].utcStop;
		}

		int nCaclCount = (m_usrParam.GetMaxWeek() + m_usrParam.nLastCount) * 2;

		int nStart = max(0, pStockData->m_nKCount - nCaclCount);//
		
		m_usrParam.nDataCount = nCaclCount;

		float fClose[MAX_CACL_COUNT] = { 0 };

		KLINEDATA *pBar = pStockData->m_pKLineData;
		for (int i = nStart; i < pStockData->m_nKCount; i++)
			fClose[i- nStart] = pBar[i].close;

		m_usrParam.pData = fClose;
		if (bCheckBuy)
		{
			m_usrParam.nLastCount = 3;
			memcpy_s(m_usrParam.nWeek, sizeof(int)*WEEKS_COUNT, m_nMa, sizeof(int)*WEEKS_COUNT);
			//bRet = m_usrTA.MAUP_S(&m_usrParam) && m_usrTA.RSIUP(&m_usrParam);
			if (m_usrTA.MAUP_S(&m_usrParam,true))
			{
				sprintf_s(szBuf, "%06d  MAUP %d:%d close=%.2f", pStockData->m_nStockCode,
					pStockData->m_pCapitalFlow[pStockData->m_nKCount - 1].m_nDate,
					pStockData->m_pCapitalFlow[pStockData->m_nKCount - 1].m_nTime,
					pBar[pStockData->m_nKCount - 1].close);

				SendMsg2UI(szBuf);
			}

			m_usrParam.nLastCount = 35;
			m_usrParam.nOption = 80;
			memcpy_s(m_usrParam.nWeek, sizeof(int)*WEEKS_COUNT, m_nRSIWeek, sizeof(int)*WEEKS_COUNT);
			if (m_usrTA.RSIUP(&m_usrParam))
			{
				sprintf_s(szBuf, "%06d  RSIUP %d:%d close=%.2f", pStockData->m_nStockCode,
					pStockData->m_pCapitalFlow[pStockData->m_nKCount - 1].m_nDate,
					pStockData->m_pCapitalFlow[pStockData->m_nKCount - 1].m_nTime,
					pBar[pStockData->m_nKCount - 1].close);

				SendMsg2UI(szBuf);
			}

		}
		else
		{
			//bRet = m_usrTA.MADOWN_S(&m_usrParam) && m_usrTA.RSIDOWN(&m_usrParam);
			memcpy_s(m_usrParam.nWeek, sizeof(int)*WEEKS_COUNT, m_nMa, sizeof(int)*WEEKS_COUNT);
			m_usrParam.nLastCount = 3;
			if (m_usrTA.MADOWN_S(&m_usrParam,true))
			{
				sprintf_s(szBuf, "%06d  MADOWN %d:%d close=%.2f", pStockData->m_nStockCode,
					pStockData->m_pCapitalFlow[pStockData->m_nKCount - 1].m_nDate,
					pStockData->m_pCapitalFlow[pStockData->m_nKCount - 1].m_nTime,
					pBar[pStockData->m_nKCount - 1].close);

				SendMsg2UI(szBuf);
			}
			m_usrParam.nLastCount = 90;
			m_usrParam.nOption = 80;
			memcpy_s(m_usrParam.nWeek, sizeof(int)*WEEKS_COUNT, m_nRSIWeek, sizeof(int)*WEEKS_COUNT);
			if (m_usrTA.RSIDOWN(&m_usrParam))
			{
				sprintf_s(szBuf, "%06d  RSIDOWN %d:%d close=%.2f", pStockData->m_nStockCode,
					pStockData->m_pCapitalFlow[pStockData->m_nKCount - 1].m_nDate,
					pStockData->m_pCapitalFlow[pStockData->m_nKCount - 1].m_nTime,
					pBar[pStockData->m_nKCount - 1].close);

				SendMsg2UI(szBuf);
			}
		}
			

		return bRet;
	}

	bool CaclMainFlow(CINTEGER_QUEUE *pTradeQueue, CSTOCKDATAS *pStockData)
	{
		char szBuf[260] = { 0 };
		static int nLastCaclCode=0, nLastCaclDate=0, nLastCacTime=0;

		//��ֹͬһ���ڶ�μ���
		if (nLastCaclCode == pStockData->m_nStockCode
			&& nLastCaclDate == pStockData->m_pCapitalFlow[pStockData->m_nCapitalFlowRecords - 1].m_nDate
			&& nLastCacTime == pStockData->m_pCapitalFlow[pStockData->m_nCapitalFlowRecords - 1].m_nTime)
			return false;
		else
		{
			nLastCaclCode = pStockData->m_nStockCode;
			nLastCaclDate = pStockData->m_pCapitalFlow[pStockData->m_nCapitalFlowRecords - 1].m_nDate;
			nLastCacTime = pStockData->m_pCapitalFlow[pStockData->m_nCapitalFlowRecords - 1].m_nTime;
		}

		memcpy_s(m_usrParam.nWeek, sizeof(int)*WEEKS_COUNT, m_nCapitalWeek, sizeof(int)*WEEKS_COUNT);
		m_usrParam.nLastCount = 3;
		
		m_usrParam.nDataCount = pStockData->m_nCapitalFlowRecords;
		int nCaclCount = (m_usrParam.GetMaxWeek() + m_usrParam.nLastCount) * 2;
		int nStart = max(0, m_usrParam.nDataCount - nCaclCount-1);
		int nMainFlowDeltaStatus=-1, 
			nMainFlowDeltaCount=0, 
			nMainFlowStatus=-1, 
			nMainFlowCount=0,
			nMainFlowChanged=0;
		int nTrendsBegin = 0;//���ƿ�ʼ��λ��
		m_usrParam.nDataCount = nCaclCount;

		//�����������Ĵ��ʽ����仯���
		do
		{
			CAPITALFLOWSTRUCK *pStart = pStockData->m_pCapitalFlow + nStart;
			
			m_usrParam.pData = pStart;

			m_usrParam.nOption = CACL_FLOW_MAIN_DELTA;//���������仯����
			if (m_usrTA.MainCapitalFlowChanged(&m_usrParam,true))
			{
				if (m_usrParam.nTACmdStatus == FLOWUP  )
				{
					if (nMainFlowDeltaStatus != FLOWUP)
					{
						nMainFlowDeltaStatus = FLOWUP;
						//��¼�仯ʱ�ķ������
						g_usrTradeQueue.PushData(pStockData->m_nStockCode,
							nMainFlowDeltaStatus, nMainFlowDeltaCount);
						
						nTrendsBegin =nCaclCount - m_usrParam.nOption;

						sprintf_s(szBuf, "From %04d:%04d to %04d:%04d �ʽ��������,��������:%d,�ۼ�:%d��Ԫ",
							(pStart+nTrendsBegin)->m_nDate%10000, (pStart + nTrendsBegin)->m_nTime/100,
							(pStart + nCaclCount)->m_nDate%10000, (pStart + nCaclCount)->m_nTime/100,
							m_usrParam.nOption, m_usrParam.nTotalFlow);

						nStart = nStart - m_usrParam.nOption ;
						SendMsg2UI(szBuf);
						nMainFlowDeltaCount = 1;
						nMainFlowChanged++;
					}
					else
						nMainFlowDeltaCount++;
				}
				else  if (m_usrParam.nTACmdStatus == FLOWDOWN )
				{
					if (nMainFlowDeltaStatus != FLOWDOWN)
					{
						nMainFlowDeltaStatus = FLOWDOWN;
						//��¼�仯ʱ�ķ������
						g_usrTradeQueue.PushData(pStockData->m_nStockCode,
							nMainFlowDeltaStatus, nMainFlowDeltaCount);

						
						nTrendsBegin = nCaclCount - m_usrParam.nOption ;
						
						sprintf_s(szBuf, "From %04d:%04d to %04d:%04d �ʽ��������,�������ڣ�%d,�ۼ�:%d��Ԫ",
							(pStart + nTrendsBegin)->m_nDate%10000, (pStart + nTrendsBegin)->m_nTime/100,
							(pStart + nCaclCount)->m_nDate%10000, (pStart + nCaclCount)->m_nTime/100,
							m_usrParam.nOption, m_usrParam.nTotalFlow);

						nStart = nStart - m_usrParam.nOption ;
						SendMsg2UI(szBuf);
						nMainFlowDeltaCount = 1;
						nMainFlowChanged++;
						
					}
					else
						nMainFlowDeltaCount++;
				}
			}
			else
				g_usrTradeQueue.PushData(pStockData->m_nStockCode,
					FLOWNOCHANGED, nMainFlowDeltaCount);
			
			m_usrParam.nOption = CACL_FLOW_MAIN_TOTAL;//���������仯����
			
			if (m_usrTA.MainCapitalFlowChanged(&m_usrParam,true))
			{
				if (m_usrParam.nTACmdStatus == FLOWTOTALUP )
				{
					if (nMainFlowStatus != FLOWTOTALUP)
					{
						nMainFlowStatus = FLOWTOTALUP;
						//��¼�仯ʱ�ķ������
						g_usrTradeQueue.PushData(pStockData->m_nStockCode,
							nMainFlowStatus, nMainFlowCount);
						
						nTrendsBegin =nCaclCount - m_usrParam.nOption ;
						sprintf_s(szBuf, "From %04d:%04d to %04d:%04d �ʽ��ۼ�����,��������:%d,�ۼ�:%d��Ԫ",
							(pStart + nTrendsBegin)->m_nDate%10000, (pStart + nTrendsBegin)->m_nTime/100,
							(pStart + nCaclCount)->m_nDate%10000, (pStart + nCaclCount)->m_nTime/100,
							m_usrParam.nOption, m_usrParam.nTotalFlow);

						nStart = nStart - m_usrParam.nOption ;

						SendMsg2UI(szBuf);
						nMainFlowCount = 1;
						nMainFlowChanged++;

					}
					else
						nMainFlowCount++;
				}
				else  if (m_usrParam.nTACmdStatus == FLOWTOTALDOWN )
				{
					if (nMainFlowStatus != FLOWTOTALDOWN)
					{
						nMainFlowStatus = FLOWTOTALDOWN;
						//��¼�仯ʱ�ķ������
						g_usrTradeQueue.PushData(pStockData->m_nStockCode,
							nMainFlowStatus, nMainFlowCount);

						
						nTrendsBegin =nCaclCount - m_usrParam.nOption ;
						sprintf_s(szBuf, "From %04d:%04d to %04d:%04d �ʽ��ۼ�����,��������:%d,�ۼ�:%d��Ԫ",
							(pStart + nTrendsBegin)->m_nDate%10000, (pStart + nTrendsBegin)->m_nTime/100,
							(pStart + nCaclCount)->m_nDate % 10000, (pStart + nCaclCount)->m_nTime/100,
							m_usrParam.nOption, m_usrParam.nTotalFlow);
						
						SendMsg2UI(szBuf);

						nStart = nStart - m_usrParam.nOption ;

						nMainFlowCount = 1;
						nMainFlowChanged++;

					}
					else
						nMainFlowCount++;
				}
			}
			
			nStart--;
		} while (nStart>0 && (nMainFlowChanged<2));
		
		sprintf_s(szBuf, "%06d �ʽ���������ϣ�", pStockData->m_nStockCode);
		SendMsg2UI(szBuf);

		return true;
	}


	void   SendMsg2UI(char *szMSG)
	{
		// Send the string to the main dialog box
		COPYDATASTRUCT cdsCaptical = { 0x201, (strlen(szMSG) + 1) , (PVOID)szMSG };

		FORWARD_WM_COPYDATA(FindWindow(NULL, MY_CAPTION),
			NULL, &cdsCaptical, SendMessage);
	}

private:
	CTECHANALYSE	m_usrTA;
	
	TA_DATA			m_usrParam;
	KLINEDATA       m_usrBars[TRADE_CACL_COUNT];
	int				m_nMa[WEEKS_COUNT] = { 5,10,20,0,0 },  //��������
					m_nRSIWeek[WEEKS_COUNT] = { 6,12,24,0,0 },  //RSI����
					m_nMACDWeek[WEEKS_COUNT] = { 9,12,26,0,0 },//MACD����
					m_nCapitalWeek[WEEKS_COUNT] = { 5,10,20,0,0 };//�ʽ�����������

	
};


