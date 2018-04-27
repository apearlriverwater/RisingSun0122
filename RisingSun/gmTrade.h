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
extern CINTEGER_QUEUE g_usrTradeQueue;  //目前只能采用全局变量方式进行访问，通过指针传递的信息错误

typedef  struct tagTHREADPARAMETERS
{
	CINTEGER_QUEUE    *pTAMsgQ;    //技术分析队列
	CINTEGER_QUEUE    *pTradeMsgQ; //交易队列
	CSTOCKDATAS       *pStockDatas;
	CRISINGSUNTRADER  *pTrader;
}THREADPARAMETERS;

//掘金量化框架，目前用于读取K线数据
//由独立线程执行潜在的买卖点检测
class CRISINGSUNTRADER
{
public:
	HANDLE			m_hTAThread,m_hTradeThread;//技术分析线程、交易线程
	CINTEGER_QUEUE	nBSQueue;   //需执行买卖操作的标的及其参数队列，on_bar回调函数使用

	CRISINGSUNTRADER()
	{
		int ret;
		//初始化策略,根据配置文件
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

	//处理分时行情事件
	static void on_bar(Bar *bar)
	{
		char szBuf[260];
		sprintf_s(szBuf, "%s %s cloase=%03.2f\n", bar->strendtime, bar->sec_id, bar->close);
		printf_s(szBuf);
	}

	//处理委托回报事件
	void on_execrpt(ExecRpt *res) {}

	void on_order_status(Order *res) {}

	//委托回报函数类型(回调接口: 订单接受)
	void on_order_new(Order *res) {}

	//委托回报函数类型(回调接口：订单完全成交)
	void on_order_filled(Order *res) {}

	//委托回报函数类型(回调接口：订单部分成交)
	void on_order_partiall_filled(Order *res) {}

	//委托回报函数类型(回调接口：订单停止)
	void on_order_stop_executed(Order *res) {}

	//委托回报函数类型(回调接口：订单撤销成功)
	void on_order_canceled(Order *res) {}

	//委托回报函数类型(回调接口：撤单失败)
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



		//方式一：策略回测参数设置  20170818--20180112
		/*ret = strategy_backtest_config("2017-08-18 09:30:00", "2018-01-12 15:15:00",
				1000000, 1, 0.0003, 0.246, 1);
		ret = gm_md_subscribe("SZSE.000710.bar.30");*/

		
		// 设置事件回调函数
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


		//printf("策略起动成功! %s\n", gm_strerror(ret));

		// 执行并等待策略运行结束
		ret = gm_run();

		//不判断执行结果，实现免维护，错误信息统一输出到log，在掘金终端查看即可
		if (ret)
		{
			cout << "error:" << ret << " msg:" << gm_strerror(ret) << endl;
		}

		return 0;
	}

	//读取K线数据  考虑实时状态下新数据的叠加问题
	int ReadKDataByCapital(KLINEDATA *pBar, int *nRecords,
	    char *szStartDateTime,char *szStopDateTime,
		char *szCode,int nWeeksInMinutes)
	{
		/**
		* @brief 分时Bar数据结构
		用于解决数据对齐不一致的问题：ticks要求必须字节对齐，而gm可能是8字节对齐
		*
		*/
		typedef struct myBar
		{
			char                    exchange[LEN_EXCHANGE];       ///<交易所代码
			char                    sec_id[LEN_SECID];            ///<证券ID
			int                     bar_type;                     ///<分时周期类型(enum BarType)
			int		                nNoUsed;  //++++++
			double                  utc_time;                     ///bar的开始时间
			char                    strtime[LEN_ISO_DATATIME+4];    ///bar的开始时间  对齐8字节
			double                  utc_endtime;                  ///bar的结束时间
			char                    strendtime[LEN_ISO_DATATIME]; ///bar的结束时间

			float                   open;                         ///<开盘价
			float                   close;                        ///<收盘价
			float                   high;                         ///<最高价
			float                   low;                          ///<最低价
			int		                nNoUsed1;  //++++++ 对齐8字节
			double                  volume;                       ///<成交量
			double                  amount;                       ///<成交金额
			float                   pre_close;                    ///前收盘价
			int		                nNoUsed2;  //++++++对齐8字节
			long long                position;                    ///<持仓量
			float                   adj_factor;                   //复权因子
			int                     flag;                         //除权出息，停牌等标记
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
			//注意：没有交易时不返回K线数据，导致与资金流不对应  有时没有响应
			gm_md_get_bars(szCode, 60 * nWeeksInMinutes,
				szStart, szStopDateTime,
				(Bar**)&bars, &count);

			if (count == 0)
				break;


			//K数据格式转存
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
		
		//K数据格式转存
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

	//K线趋势计算分析:MA  RSI SAR MACD
	bool CaclKLineTrends(CSTOCKDATAS *pStockData,bool bCheckBuy=true)
	{
		bool bRet = false;
		char szBuf[260] = { 0 };

		//防止同一周期多次计算
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

		//防止同一周期多次计算
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
		int nTrendsBegin = 0;//趋势开始的位置
		m_usrParam.nDataCount = nCaclCount;

		//逆序分析最近四次资金流变化情况
		do
		{
			CAPITALFLOWSTRUCK *pStart = pStockData->m_pCapitalFlow + nStart;
			
			m_usrParam.pData = pStart;

			m_usrParam.nOption = CACL_FLOW_MAIN_DELTA;//主力增量变化趋势
			if (m_usrTA.MainCapitalFlowChanged(&m_usrParam,true))
			{
				if (m_usrParam.nTACmdStatus == FLOWUP  )
				{
					if (nMainFlowDeltaStatus != FLOWUP)
					{
						nMainFlowDeltaStatus = FLOWUP;
						//记录变化时的分析结果
						g_usrTradeQueue.PushData(pStockData->m_nStockCode,
							nMainFlowDeltaStatus, nMainFlowDeltaCount);
						
						nTrendsBegin =nCaclCount - m_usrParam.nOption;

						sprintf_s(szBuf, "From %04d:%04d to %04d:%04d 资金加速流入,持续周期:%d,累计:%d万元",
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
						//记录变化时的分析结果
						g_usrTradeQueue.PushData(pStockData->m_nStockCode,
							nMainFlowDeltaStatus, nMainFlowDeltaCount);

						
						nTrendsBegin = nCaclCount - m_usrParam.nOption ;
						
						sprintf_s(szBuf, "From %04d:%04d to %04d:%04d 资金加速流出,持续周期：%d,累计:%d万元",
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
			
			m_usrParam.nOption = CACL_FLOW_MAIN_TOTAL;//主力总量变化趋势
			
			if (m_usrTA.MainCapitalFlowChanged(&m_usrParam,true))
			{
				if (m_usrParam.nTACmdStatus == FLOWTOTALUP )
				{
					if (nMainFlowStatus != FLOWTOTALUP)
					{
						nMainFlowStatus = FLOWTOTALUP;
						//记录变化时的分析结果
						g_usrTradeQueue.PushData(pStockData->m_nStockCode,
							nMainFlowStatus, nMainFlowCount);
						
						nTrendsBegin =nCaclCount - m_usrParam.nOption ;
						sprintf_s(szBuf, "From %04d:%04d to %04d:%04d 资金累计流入,持续周期:%d,累计:%d万元",
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
						//记录变化时的分析结果
						g_usrTradeQueue.PushData(pStockData->m_nStockCode,
							nMainFlowStatus, nMainFlowCount);

						
						nTrendsBegin =nCaclCount - m_usrParam.nOption ;
						sprintf_s(szBuf, "From %04d:%04d to %04d:%04d 资金累计流出,持续周期:%d,累计:%d万元",
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
		
		sprintf_s(szBuf, "%06d 资金流计算完毕！", pStockData->m_nStockCode);
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
	int				m_nMa[WEEKS_COUNT] = { 5,10,20,0,0 },  //均线周期
					m_nRSIWeek[WEEKS_COUNT] = { 6,12,24,0,0 },  //RSI周期
					m_nMACDWeek[WEEKS_COUNT] = { 9,12,26,0,0 },//MACD周期
					m_nCapitalWeek[WEEKS_COUNT] = { 5,10,20,0,0 };//资金流均线周期

	
};


