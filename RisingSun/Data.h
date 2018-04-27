#pragma once
#include <windowsx.h>
#include <WinUser.h>
#include <tchar.h>
#include <strsafe.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include<io.h>
#include <iostream>
#include <queue>  
#include "Resource.h"


#define  MY_CAPTION        L"RingSun Aplication"
#define  TRADE_CACL_COUNT 340  //trade数据分析的周期数
#define  MAX_KLINE_COUNT  4000

/*
以大智慧炒股软件为例，其区分标准如下：
1、小单 (<2 万股 或 4 万元 )，                   小于4万
2、中单 (2-10 万股 或 4-20 万元 )，     100000   4-20万
3、大单 (10-50 万股 或 20-100 万元 )，  200000   20-100万
4、特大单 (>50 万股 或 100 万元 ) 。    500000   大于100万
*/
#define  SMALLPENVOLS		20000
#define  SMALLPENMONWEY		40000

#define  MIDPENVOLS			100000
#define  MIDPENMONWEY		200000

#define  LARGEPENVOLS		200000
#define  LARGEPENMONWEY		1000000

#define  SUPERPENVOLS		500000
#define  SUPERPENMONWEY		1000000

//技术分析数据类型：K线、分笔、资金流，增仓？DDE？主力动向？
#define STOCKDATACHANGE_KLINE			1  //K LINE DATA CHANGED
#define STOCKDATACHANGE_L2TICKS			2  //L2TICKS DATA CHANGED
#define STOCKDATACHANGE_CAPITALFLOW		3  //CAPITALFLOW	 DATA CHANGED

//技术分析买卖类型：买入、卖出、买卖综合
#define RISINGSUN_TA_BUY			1  //BUY 
#define RISINGSUN_TA_SELL			2  //SELL
#define RISINGSUN_TA_BUYSELL		3  //BUYSELL
#define RISINGSUN_TA_SAVE_FLOW_AND_KLINE		4  //SAVE_FLOW_AND_KLINE


#define RISINGSUN_BUY			1  //BUY 
#define RISINGSUN_SELL			2  //SELL

#define  MAXSTOCKS  100
typedef struct  tagL2DETAIL
{
	DWORD dwTime;
	DWORD dwIndex;//from 0
	DWORD dwPrice;//true price*1000
	DWORD dwStocks;//成交股数，3000表示30手，231表示231股
	BYTE  bBS;//1-主卖，2-主买

}L2DETAIL;

typedef struct tagMONEYFLOW {
	float	fInMoney, fOutMoney;   //进出金额
	int     nInVol, nOutVol;      //进出量
}MONEYFLOW;
//必须固定为17字节数据，采用结构体单字节对齐方式
typedef struct tagL2TICKS {
	int m_nTime, m_nIndex;       //时间、成交笔序号
	int m_nPriceMul1000, m_nVols;//价格*1000，成交股数
	char m_nBS;                  //成交方向：2买  1卖 0 竞价？
}L2TICKS;

//dw  日期   交易日													4bytes + 0
//dw  时间   单位分钟												4bytes + 4
//double 小单入，中单入，大单入，超大单入   32bytes + 8，10H，18H，20H
//double 小单出，中单出，大单出，超大单出   32bytes + 32H，30H，38H，40H
//
//疑似成交量
//qword 小单入，中单入，大单入，超大单入   32bytes + 48H，50H，58H，60H
//qword 小单出，中单出，大单出，超大单出   32bytes + 68H，70H，78H，80H
//其余32字节内容不详 + 88H typedef struct tagCAPITALFLOWSTRUCK
typedef struct tagCAPITALFLOWSTRUCK {
public:
	int32_t	m_nDate,m_nTime;       //date /时间
	double	m_dblSmallBuy, m_dblMidBuy, m_dblBigBuy, m_dblHugeBuy;
	double	m_dblSmallSell, m_dblMidSell, m_dblBigSell, m_dblHugeSell;
	//成交数量，单位：股
	int64_t	m_lSmallBuy, m_lMidBuy, m_lBigBuy, m_lHugeBuy;
	int64_t	m_lSmallSell, m_lMidSell, m_lBigSell, m_lHugeSell;
	//？？？
	int32_t	m_nUnkown[8];

	double GetBigNavFlow()
	{
		return m_dblBigBuy + m_dblHugeBuy - m_dblBigSell - m_dblHugeSell;
	}
	double GetSmallNavFlow()
	{
		return m_dblSmallBuy + m_dblMidBuy - m_dblSmallSell - m_dblMidSell;
	}

	double GetTotalFlow()
	{
		return m_dblBigBuy + m_dblHugeBuy + m_dblSmallBuy + m_dblMidBuy;
	}
	
	int64_t GetTotalVol()
	{
		return m_lBigBuy + m_lHugeBuy + m_lSmallBuy+ m_lMidBuy;
	}
	

}CAPITALFLOWSTRUCK;


//资金流与K线数据
typedef struct tagFLOWANDKLINE {
	int32_t	m_nDate, m_nTime;       //date 时间
	double	m_dblSmallBuy, m_dblMidBuy, m_dblBigBuy, m_dblHugeBuy;
	double	m_dblSmallSell, m_dblMidSell, m_dblBigSell, m_dblHugeSell;
	float                   open;                         ///<开盘价
	float                   close;                        ///<收盘价
	float                   high;                         ///<最高价
	float                   low;                          ///<最低价
	double                  volume;                       ///<成交量
	double                  amount;                       ///<成交金额
}FLOWANDKLINE;

using namespace std;

typedef struct tagKLINEDATA
{
	/*int						date;                     ///bar的stop时间
	int						time;*/
	double					utcStop;
	float                   open;                         ///<开盘价
	float                   close;                        ///<收盘价
	float                   high;                         ///<最高价
	float                   low;                          ///<最低价
	double                  volume;                       ///<成交量
	double                  amount;                       ///<成交金额

	//UTC值到标准时间日期转换
	int UTC2DateTime(int *nDate,int *nTime)
	{
		struct  tm timeStruc;
		int64_t   nTmp;
		nTmp = int64_t(utcStop);
		localtime_s(&timeStruc, &nTmp);

		*nDate =19000000+ timeStruc.tm_year * 10000 + (timeStruc.tm_mon + 1) * 100 + timeStruc.tm_mday;
		*nTime = timeStruc.tm_hour * 10000 + timeStruc.tm_min*100+ timeStruc.tm_sec;

		return  *nDate;
	}

}KLINEDATA;

/*
class CINTEGER_QUEUE
{
private:
	queue<int>  intQueue;

	CRITICAL_SECTION cs;

public:
	bool HasData()
	{
		return (!intQueue.empty());
	}
	CINTEGER_QUEUE()
	{
		InitializeCriticalSection(&cs);
	}

	~CINTEGER_QUEUE()
	{

	}

	////变化的股票序号、变化内容
	//void PushData(int nIndex, int nData)
	//{
	//	EnterCriticalSection(&cs);

	//	intQueue.push(nIndex);
	//	intQueue.push(nData);

	//	LeaveCriticalSection(&cs);
	//}

	//void PopData(int *nIndex, int *nData)
	//{
	//	EnterCriticalSection(&cs);

	//	*nIndex = intQueue.front();
	//	intQueue.pop();
	//	*nData = intQueue.front();
	//	intQueue.pop();

	//	LeaveCriticalSection(&cs);
	//}

	//变化的股票序号、变化内容、持续周期
	void PushData(int nStockCode, int nData,int nLastWeeks=0)
	{
		EnterCriticalSection(&cs);

		intQueue.push(nStockCode);
		intQueue.push(nData);
		intQueue.push(nLastWeeks);

		LeaveCriticalSection(&cs);
	}

	void PopData(int *nStockCode, int *nData,  int *nLastWeeks=NULL)
	{
		EnterCriticalSection(&cs);

		*nStockCode = intQueue.front();
		intQueue.pop();
		*nData = intQueue.front();
		intQueue.pop();

		if(nLastWeeks != NULL)
			*nLastWeeks = intQueue.front();
		intQueue.pop();

		LeaveCriticalSection(&cs);
	}
};
*/
class CSTOCKDATAS
{
private:
	CRITICAL_SECTION csMainFlowLock;  //主力资金数据锁
	CRITICAL_SECTION csKLineDataLock;  //K线数据锁
	CRITICAL_SECTION csTicksDataLock;  //Ticks数据锁

public:
	int m_nStockCode, m_nTradeDate;//股票代码、最新交易日
	
	//技术分析结果队列 nIndex:Data index, nResult:TA result
	//CINTEGER_QUEUE    m_nTaResult;  
	int m_nTickCount;   //当日当前总成交笔数
	L2TICKS *m_pL2Ticks;		//动态分配的笔成交数据  起步6000，以3000为基础递增记录数

	int m_nCapitalFlowRecords;   //captical总记录数
	CAPITALFLOWSTRUCK m_pCapitalFlow[MAX_KLINE_COUNT];  //必须与m_pKLineData保持同种周期、统一时间范围

	int   m_nKCount, m_nKWeek;   //K线记录总数、K线周期
	KLINEDATA  m_pKLineData[MAX_KLINE_COUNT];//m_pCapitalFlow确定K线数据，时间范围与周期数必须一致

public:
	bool CompareFlowKLine(KLINEDATA *pKLineData,int *nKCount)
	{
		bool bRet = true;
		int nDate, nTime,nCopySize;

		
		for (int i = 0; i < m_nCapitalFlowRecords; i++)
		{
			(pKLineData + i)->UTC2DateTime(&nDate, &nTime);

			//出现缺数据的原因是该周期内成交为0，插入一项数据并须补0
			if ((m_pCapitalFlow + i)->m_nTime != nTime || (m_pCapitalFlow + i)->m_nDate != nDate)
			{
				nCopySize = (m_nCapitalFlowRecords - i - 1) * sizeof(KLINEDATA);
				memcpy_s(pKLineData + i + 1, nCopySize,
					pKLineData + i, nCopySize);
				(pKLineData + i+1)->amount = 0;
				(pKLineData + i+1)->volume = 0;
				(*nKCount)++;
			}
		}
		
		

		return bRet;
	}
	//check K line data valid  or not
	bool KLineDataValid()
	{
		bool bRet = false;
		int nKDate,nKTime;

		if (m_pKLineData == NULL)
			return bRet;

		m_pKLineData->UTC2DateTime(&nKDate, &nKTime);

		if (   m_nCapitalFlowRecords == m_nKCount
			&& nKDate==m_pCapitalFlow->m_nDate    //K和资金流开始日期时间相等
			&& nKTime==m_pCapitalFlow->m_nTime)
		{
			(m_pKLineData+m_nKCount-1)->UTC2DateTime(&nKDate, &nKTime);
			
			if (nKDate == (m_pCapitalFlow + m_nCapitalFlowRecords-1)->m_nDate    //K和资金流结束日期时间相等
				&& nKTime == (m_pCapitalFlow + m_nCapitalFlowRecords-1)->m_nTime)
				bRet = true;
		}

		return bRet;
	}

	CSTOCKDATAS(int nStockCode=0,int nTradeDate=0)
	{
		m_nStockCode = nStockCode;
		m_nTradeDate = nTradeDate;
		m_pL2Ticks = NULL;
		//m_pCapitalFlow = NULL;
		m_nTickCount = 0;
		InitializeCriticalSection(&csMainFlowLock);
		InitializeCriticalSection(&csKLineDataLock);
		InitializeCriticalSection(&csTicksDataLock);
	}

	~CSTOCKDATAS()
	{
		if (NULL != m_pL2Ticks)
		{
			delete m_pL2Ticks;
			m_pL2Ticks = NULL;
		}

		/*if (NULL != m_pCapitalFlow)
		{
			delete m_pCapitalFlow;
			m_pCapitalFlow = NULL;
		}*/

		/*if (NULL != m_pKLineData)
		{
			delete m_pKLineData;
			m_pKLineData = NULL;
		}*/
	}
	/*
	以大智慧炒股软件为例，其区分标准如下：
		1、小单 (<2 万股 或 4 万元 )，                   小于4万
		2、中单 (2-10 万股 或 4-20 万元 )，     100000   小于10万   
		3、大单 (10-50 万股 或 20-100 万元 )，  200000   小于100万
		4、特大单 (>50 万股 或 100 万元 ) 。    500000   大于100万

		超大单：大于等于50万股或者100万元的成交单；
		大单：大于等于10万股或者20万元且小于50万股和100万元的成交单；
		中单：大于等于2万股或者4万元且小于10万股和20万元的成交单；
		小单：小于2万股和4万元的成交单；
		流入：买入成交额；
		流出：卖出成交额；
		主力流入：超大单加大单买入成交额之和；
		主力流出：超大单加大单卖出成交额之和；
		主力净流入：主力流入-主力流出；
		净额：流入-流出；
		净占比：（流入-流出）/总成交额
	
	*/
	
	//根据资金流信息生成基本的K线数据，暂时仅支持日线及其以下的K线类型
	//1/5/15/30/60/120
	void GetKLineMsg(char *szCode,
		char *szStartDT,char *szStopDT,
		int *nWeekInMinutes,int *nCount)
	{
		if (NULL == m_pCapitalFlow)  //todo待查：为何会出现 NULL == m_pCapitalFlow
			return;

		*nCount =m_nCapitalFlowRecords ;
		*nWeekInMinutes = (m_pCapitalFlow[0].m_nTime % 10000 - 3000) / 100;//分钟差
		int	 nHour= (m_pCapitalFlow[0].m_nTime - 90000) / 10000;//小时差

		*nWeekInMinutes = *nWeekInMinutes + nHour * 60;//转为总分钟差
		if (*nWeekInMinutes > 120)
		{  // 下午时段
			*nWeekInMinutes = *nWeekInMinutes - 90;
		}

		if (m_nStockCode >= 600000)
			sprintf_s(szCode, 16, "SHSE.%06d", m_nStockCode);
		else
			sprintf_s(szCode, 16, "SZSE.%06d", m_nStockCode);
	
		sprintf_s(szStartDT, 32, "%4d-%02d-%02d 09:30:00",
			m_pCapitalFlow[0].m_nDate / 10000,
			(m_pCapitalFlow[0].m_nDate % 10000) / 100,
			m_pCapitalFlow[0].m_nDate % 100);

		sprintf_s(szStopDT, 32, "%4d-%02d-%02d %02d:%02d:00",
			m_pCapitalFlow[m_nCapitalFlowRecords-1].m_nDate / 10000,
			(m_pCapitalFlow[m_nCapitalFlowRecords - 1].m_nDate % 10000) / 100,
			m_pCapitalFlow[m_nCapitalFlowRecords - 1].m_nDate % 100,
			m_pCapitalFlow[m_nCapitalFlowRecords - 1].m_nTime / 10000,
			(m_pCapitalFlow[m_nCapitalFlowRecords - 1].m_nTime % 10000) / 100);
	}

	//存贮资金流和K线数据，用于后续分析
	bool SaveFlowAndKLine()
	{
		bool bFileChange = false;
		char szBuf[260] = { 0 };

		int nDataCount = m_nCapitalFlowRecords;
		CAPITALFLOWSTRUCK *pCapitalFlow = m_pCapitalFlow;
		FLOWANDKLINE *pFlowKLine = new FLOWANDKLINE[nDataCount];
		KLINEDATA    *pKLine = m_pKLineData;

		char szFilePath[260];
		FILE	*fp;
		int nCopySize;
		int nStartRecord = 0;

		if (NULL != pFlowKLine && NULL != pKLine)
		{
			int  nMin = (pCapitalFlow[0].m_nTime) / 100, nHour;

			if (nMin > 0)
			{
				nHour = nMin - 900;
				nMin = (nMin % 100 - 30);
				if (nMin < 0)
				{
					nHour--;
					nMin = nMin + 60;
				}
				nMin = (nHour / 100) * 60 + nMin;
			}
			else
				nMin = 0;

			sprintf_s(szFilePath, "\\data\\FLOWKLINE-%03d-%06d.dat",
				nMin,m_nStockCode);

			struct stat my_stat;
			if (stat(szFilePath, &my_stat) == 0)//==-1
			{
				//文件存在  仅保存新加的部分，从文件最后的记录开始添加数据
				fopen_s(&fp, szFilePath, "rb+");
				nCopySize =sizeof(FLOWANDKLINE);
				fseek(fp, -nCopySize, SEEK_END);
				pFlowKLine->m_nDate = -1;
				fread_s(pFlowKLine, nCopySize, nCopySize, 1, fp);

				if(pFlowKLine->m_nDate > -1)
					for (nStartRecord = nDataCount-1; nStartRecord >=0; nStartRecord--)
					{
						if (pCapitalFlow[nStartRecord].m_nDate == pFlowKLine->m_nDate)
							if (pCapitalFlow[nStartRecord].m_nTime == pFlowKLine->m_nTime)
								if( m_pKLineData[nStartRecord].volume == pFlowKLine->volume)
									{
										nStartRecord++;
										fseek(fp, 0, SEEK_END);//append
										break;
									}
								else
								{
									fseek(fp, -nCopySize, SEEK_END);//overwrite the last record
									break;
								}
									
							else if (pCapitalFlow[nStartRecord].m_nTime > pFlowKLine->m_nTime)
							{
								fseek(fp, 0, SEEK_END);//append
								break;
							}

						else if (pCapitalFlow[nStartRecord].m_nDate > pFlowKLine->m_nDate)
						{
							fseek(fp, 0, SEEK_END);//append
							break;
						}
					}
			}
			else
				fopen_s(&fp, szFilePath, "wb");

			if (fp != NULL)
			{
				if (nStartRecord<0)
				{
					nStartRecord = 0;
				}
				for (int i = nStartRecord; i < nDataCount; i++)
				{
					nCopySize = sizeof(CAPITALFLOWSTRUCK);
					memcpy_s(&pFlowKLine[i], nCopySize, &pCapitalFlow[i], nCopySize);
					nCopySize = sizeof(KLINEDATA) - sizeof(double);//不含utcstop
					memcpy_s(&pFlowKLine[i].open, nCopySize, &pKLine[i].open, nCopySize);
				}

				if (nStartRecord < nDataCount)
				{
					nCopySize=fwrite(&pFlowKLine[nStartRecord], sizeof(FLOWANDKLINE), nDataCount- nStartRecord, fp);
					bFileChange = true;
				}
				
				fclose(fp);
			}

			delete pFlowKLine;
			
		}

		return bFileChange;
	}

	bool SaveCapitalData()
	{
		bool bFileChange = false;
		char szBuf[260] = { 0 };

		int nDataCount = m_nCapitalFlowRecords;
		CAPITALFLOWSTRUCK *pCapitalFlow = m_pCapitalFlow,usrCapBuffer;

		char szFilePath[260];
		FILE	*fp;
		int nCopySize;
		int nStartRecord = 0;

		{
			int  nMin = (pCapitalFlow[0].m_nTime) / 100, nHour;

			if (nMin > 0)
			{
				nHour = nMin - 900;
				nMin = (nMin % 100 - 30);
				if (nMin < 0)
				{
					nHour--;
					nMin = nMin + 60;
				}
				nMin = (nHour / 100) * 60 + nMin;
			}
			else
				nMin = 0;

			sprintf_s(szFilePath, "\\data\\CAP-%06d-%03d.dat",
				m_nStockCode,nMin );

			struct stat my_stat;
			if (stat(szFilePath, &my_stat) == 0)//==-1
			{
				//文件存在  仅保存新加的部分，从文件最后的记录开始添加数据
				//处理有问题，有时出现不断往后加数据情况  todo20180427
				fopen_s(&fp, szFilePath, "rb+");
				nCopySize = sizeof(CAPITALFLOWSTRUCK);
				fseek(fp, -nCopySize, SEEK_END);
				usrCapBuffer.m_nDate=-1;
				fread_s(&usrCapBuffer, nCopySize, nCopySize, 1, fp);

				if (usrCapBuffer.m_nDate > -1)
					for (nStartRecord = nDataCount - 1; nStartRecord >= 0; nStartRecord--)
					{
						if (pCapitalFlow[nStartRecord].m_nDate == usrCapBuffer.m_nDate)
							if (pCapitalFlow[nStartRecord].m_nTime == usrCapBuffer.m_nTime)
								if (pCapitalFlow[nStartRecord].m_dblSmallBuy == usrCapBuffer.m_dblSmallBuy)
								{
									nStartRecord++;
									fseek(fp, 0, SEEK_END);//append
									break;
								}
								else
								{
									fseek(fp, -nCopySize, SEEK_END);//overwrite the last record
									break;
								}

							else if (pCapitalFlow[nStartRecord].m_nTime > usrCapBuffer.m_nTime)
							{
								fseek(fp, 0, SEEK_END);//append
								break;
							}

							else if (pCapitalFlow[nStartRecord].m_nDate > usrCapBuffer.m_nDate)
							{
								fseek(fp, 0, SEEK_END);//append
								break;
							}
					}
			}
			else
				fopen_s(&fp, szFilePath, "wb");

			if (fp != NULL)
			{
				if (nStartRecord < 0)
				{
					nStartRecord = 0;
				}

				if (nStartRecord < nDataCount)
				{
					nCopySize = fwrite(&pCapitalFlow[nStartRecord], sizeof(CAPITALFLOWSTRUCK), nDataCount - nStartRecord, fp);
					bFileChange = true;
				}

				fclose(fp);
			}

		}

		return bFileChange;
	}


	bool SaveTicksData()
	{
		bool bFileChange = false;
		char szBuf[260] = { 0 };

		int nDataCount = m_nTickCount;
		L2TICKS *pTicks= m_pL2Ticks, usrTickBuffer;

		char szFilePath[260];
		FILE	*fp=NULL;
		int nCopySize;
		int nStartRecord = 0;


		if (!m_nStockCode || !m_pL2Ticks || m_nTickCount<=0)
			return bFileChange;
		
		sprintf_s(szFilePath, "\\data\\ticks-%06d-%08d.dat", m_nStockCode, m_nTradeDate);
		struct stat my_stat;
		if (stat(szFilePath, &my_stat) == 0)//==-1
		{
			//文件存在  仅保存新加的部分，从文件最后的记录开始添加数据
			fopen_s(&fp, szFilePath, "rb+");
			nCopySize = sizeof(L2TICKS);
			fseek(fp, -nCopySize, SEEK_END);
			usrTickBuffer.m_nTime = -1;
			fread_s(&usrTickBuffer, nCopySize, nCopySize, 1, fp);

			if (usrTickBuffer.m_nTime > -1)
				for (nStartRecord = nDataCount - 1; nStartRecord >= 0; nStartRecord--)
				{
					if (pTicks[nStartRecord].m_nTime > usrTickBuffer.m_nTime)
					{
						fseek(fp, 0, SEEK_END);//append
						break;
					}
					else if (pTicks[nStartRecord].m_nTime == usrTickBuffer.m_nTime)
						if (pTicks[nStartRecord].m_nIndex >= usrTickBuffer.m_nIndex)
						{
							nStartRecord++;
							fseek(fp, 0, SEEK_END);//append
							break;
						}
				}

		}
		else if(pTicks[0].m_nTime<=92505)  //从交易日首笔交易开始记录  假如上午停牌可能记录不下来
			fopen_s(&fp, szFilePath, "wb");

		if (fp != NULL)
		{
			if (nStartRecord < 0)
			{
				nStartRecord = 0;
			}

			if (nStartRecord < nDataCount)
			{
				nCopySize = fwrite(&pTicks[nStartRecord], sizeof(L2TICKS), nDataCount - nStartRecord, fp);
				bFileChange = true;
			}

			fclose(fp);
		}


		return bFileChange;

	}

	void CaclTicksBuySell()
	{
		char szFilePath[260], szData[1024];
		FILE	*fp;
		int i = 0;
		MONEYFLOW	usrSmall = { 0 }, usrMid = { 0 }, usrLarge = { 0 }, usrSuper = { 0 };
		int nVols;
		float  fAmount;

		if (!m_nStockCode)
			return;

		if (fp != NULL)
		{
			while (m_pL2Ticks[i].m_nTime > 0)
			{
				nVols = m_pL2Ticks[i].m_nVols;               //单位：股
				if (nVols > 0)   //仅处理有成交的情况
				{
					/*
					以大智慧炒股软件为例，其区分标准如下：
					1、小单 (<2 万股 或 4 万元 )，           2万股   小于4万
					2、中单 (2-10 万股 或 4-20 万元 )，     10万股   4-20万
					3、大单 (10-50 万股 或 20-100 万元 )，  20万股   20-100万
					4、特大单 (>50 万股 或 100 万元 ) 。    50万股   大于100万
					要区别对待：涨停和跌停的买卖，涨停：主动性买入，跌停：主动性卖出
					*/
					fAmount = (float)(m_pL2Ticks[i].m_nPriceMul1000*nVols) / 1000;//单位：元

					if (fAmount - 40000.0 < 0 || (nVols < 20000 && fAmount - 40000.0 < 0))
					{   //  小单 (<2 万股 或 <4 万元 )
						switch (m_pL2Ticks[i].m_nBS)
						{
						case 1:
							usrSmall.nOutVol += nVols;
							usrSmall.fOutMoney += fAmount;
							break;
						case 2:
							usrSmall.nInVol += nVols;
							usrSmall.fInMoney += fAmount;
							break;
						}
					}
					else if (fAmount - 200000.0 < 0 || (nVols < 100000 && fAmount - 200000.0 < 0))
					{   //  中单 (<10 万股 或 <20 万元 )
						switch (m_pL2Ticks[i].m_nBS)
						{
						case 1:
							usrMid.nOutVol += nVols;
							usrMid.fOutMoney += fAmount;
							break;
						case 2:
							usrMid.nInVol += nVols;
							usrMid.fInMoney += fAmount;
							break;
						}
					}
					else if (fAmount - 1000000.0 < 0 || (nVols < 200000) && fAmount - 1000000.0 < 0)
					{   //  大单 (<20 万股 或 <100 万元 )
						switch (m_pL2Ticks[i].m_nBS)
						{
						case 1:
							usrLarge.nOutVol += nVols;
							usrLarge.fOutMoney += fAmount;
							break;
						case 2:
							usrLarge.nInVol += nVols;
							usrLarge.fInMoney += fAmount;
							break;
						}
					}
					else
					{
						switch (m_pL2Ticks[i].m_nBS)
						{
						case 1:
							usrSuper.nOutVol += nVols;
							usrSuper.fOutMoney += fAmount;
							break;
						case 2:
							usrSuper.nInVol += nVols;
							usrSuper.fInMoney += fAmount;
							break;
						}
					}
				}

				i++;
			}
			fclose(fp);
		}

		sprintf_s(szFilePath, "\\data\\total---%08d.txt", m_nTradeDate);
		fopen_s(&fp, szFilePath, "a+");

		if (fp != NULL)
		{
			memset(szData, 0, 1024);
			fAmount = (usrSmall.fInMoney + usrLarge.fInMoney + usrMid.fInMoney + usrSuper.fInMoney) / 10000;
			int  nOut = (usrSmall.fOutMoney + usrLarge.fOutMoney + usrMid.fOutMoney + usrSuper.fOutMoney) / 10000;
			wsprintfA(szData, "%06d,净额：%d万元,入额：%d万元,出额：%d万元", m_nStockCode, (int)(fAmount)-nOut, (int)fAmount, nOut);

			wsprintfA(strrchr(szData, 0), ",小入：%d万股,%d万元,小出：%d万股,%d万元",
				usrSmall.nInVol / 10000, (int)usrSmall.fInMoney / 10000, usrSmall.nOutVol / 10000, (int)usrSmall.fOutMoney / 10000);
			wsprintfA(strrchr(szData, 0), ",中入：%d万股,%d万元,中出：%d万股,%d万元",
				usrMid.nInVol / 10000, (int)usrMid.fInMoney / 10000, usrMid.nOutVol / 10000, (int)usrMid.fOutMoney / 10000);
			wsprintfA(strrchr(szData, 0), ",大入：%d万股,%d万元,大出：%d万股,%d万元",
				usrLarge.nInVol / 10000, (int)usrLarge.fInMoney / 10000, usrLarge.nOutVol / 10000, (int)usrLarge.fOutMoney / 10000);
			wsprintfA(strrchr(szData, 0), ",超大入：%d万股,%d万元,超大出：%d万股,%d万元",
				usrSuper.nInVol / 10000, (int)usrSuper.fInMoney / 10000, usrSuper.nOutVol / 10000, (int)usrSuper.fOutMoney / 10000);

			fprintf(fp, "%s\n", szData);

			fclose(fp);
		}

	}

	//基于各种周期的资金流信息计划最近的资金趋势??利用开源平台进行计算？？
	void CaclBuySellTrends()
	{
		char szFilePath[260], szData[1024];
		FILE	*fp;
		int i = 0;
		MONEYFLOW	usrSmall = { 0 }, usrMid = { 0 }, usrLarge = { 0 }, usrSuper = { 0 };
		int nVols;
		float  fAmount;

		if (!m_nStockCode)
			return;

		if (fp != NULL)
		{
			while (m_pL2Ticks[i].m_nTime > 0)
			{
				nVols = m_pL2Ticks[i].m_nVols;               //单位：股
				if (nVols > 0)   //仅处理有成交的情况
				{
					/*
					以大智慧炒股软件为例，其区分标准如下：
					1、小单 (<2 万股 或 4 万元 )，           2万股   小于4万
					2、中单 (2-10 万股 或 4-20 万元 )，     10万股   4-20万
					3、大单 (10-50 万股 或 20-100 万元 )，  20万股   20-100万
					4、特大单 (>50 万股 或 100 万元 ) 。    50万股   大于100万
					要区别对待：涨停和跌停的买卖，涨停：主动性买入，跌停：主动性卖出
					*/
					fAmount = (float)(m_pL2Ticks[i].m_nPriceMul1000*nVols) / 1000;//单位：元

					if (fAmount - 40000.0 < 0 || (nVols < 20000 && fAmount - 40000.0 < 0))
					{   //  小单 (<2 万股 或 <4 万元 )
						switch (m_pL2Ticks[i].m_nBS)
						{
						case 1:
							usrSmall.nOutVol += nVols;
							usrSmall.fOutMoney += fAmount;
							break;
						case 2:
							usrSmall.nInVol += nVols;
							usrSmall.fInMoney += fAmount;
							break;
						}
					}
					else if (fAmount - 200000.0 < 0 || (nVols < 100000 && fAmount - 200000.0 < 0))
					{   //  中单 (<10 万股 或 <20 万元 )
						switch (m_pL2Ticks[i].m_nBS)
						{
						case 1:
							usrMid.nOutVol += nVols;
							usrMid.fOutMoney += fAmount;
							break;
						case 2:
							usrMid.nInVol += nVols;
							usrMid.fInMoney += fAmount;
							break;
						}
					}
					else if (fAmount - 1000000.0 < 0 || (nVols < 200000) && fAmount - 1000000.0 < 0)
					{   //  大单 (<20 万股 或 <100 万元 )
						switch (m_pL2Ticks[i].m_nBS)
						{
						case 1:
							usrLarge.nOutVol += nVols;
							usrLarge.fOutMoney += fAmount;
							break;
						case 2:
							usrLarge.nInVol += nVols;
							usrLarge.fInMoney += fAmount;
							break;
						}
					}
					else
					{
						switch (m_pL2Ticks[i].m_nBS)
						{
						case 1:
							usrSuper.nOutVol += nVols;
							usrSuper.fOutMoney += fAmount;
							break;
						case 2:
							usrSuper.nInVol += nVols;
							usrSuper.fInMoney += fAmount;
							break;
						}
					}
				}

				i++;
			}
			fclose(fp);
		}

		sprintf_s(szFilePath, "\\data\\total---%08d.txt", m_nTradeDate);
		fopen_s(&fp, szFilePath, "a+");

		if (fp != NULL)
		{
			memset(szData, 0, 1024);
			fAmount = (usrSmall.fInMoney + usrLarge.fInMoney + usrMid.fInMoney + usrSuper.fInMoney) / 10000;
			int  nOut = (usrSmall.fOutMoney + usrLarge.fOutMoney + usrMid.fOutMoney + usrSuper.fOutMoney) / 10000;
			wsprintfA(szData, "%06d,净额：%d万元,入额：%d万元,出额：%d万元", m_nStockCode, (int)(fAmount)-nOut, (int)fAmount, nOut);

			wsprintfA(strrchr(szData, 0), ",小入：%d万股,%d万元,小出：%d万股,%d万元",
				usrSmall.nInVol / 10000, (int)usrSmall.fInMoney / 10000, usrSmall.nOutVol / 10000, (int)usrSmall.fOutMoney / 10000);
			wsprintfA(strrchr(szData, 0), ",中入：%d万股,%d万元,中出：%d万股,%d万元",
				usrMid.nInVol / 10000, (int)usrMid.fInMoney / 10000, usrMid.nOutVol / 10000, (int)usrMid.fOutMoney / 10000);
			wsprintfA(strrchr(szData, 0), ",大入：%d万股,%d万元,大出：%d万股,%d万元",
				usrLarge.nInVol / 10000, (int)usrLarge.fInMoney / 10000, usrLarge.nOutVol / 10000, (int)usrLarge.fOutMoney / 10000);
			wsprintfA(strrchr(szData, 0), ",超大入：%d万股,%d万元,超大出：%d万股,%d万元",
				usrSuper.nInVol / 10000, (int)usrSuper.fInMoney / 10000, usrSuper.nOutVol / 10000, (int)usrSuper.fOutMoney / 10000);

			fprintf(fp, "%s\n", szData);

			fclose(fp);
		}
	}

	bool AddKlineData(KLINEDATA *pKLinde,int nRecordCount)
	{
		bool bFileChanged = false;
		EnterCriticalSection(&csKLineDataLock);

		if (m_pKLineData == NULL || m_nKCount != nRecordCount)
		{
			m_nKCount = nRecordCount;
		}
		int nBytes = nRecordCount*sizeof(KLINEDATA);
		memcpy_s(m_pKLineData, nBytes, pKLinde, nBytes);
		
		/*bFileChanged=SaveFlowAndKLine();*/

		LeaveCriticalSection(&csKLineDataLock);

		return bFileChanged;
	}


	bool AddCapitalFlow(PCOPYDATASTRUCT pcds)
	{
		int i = 0;
		//数据项似乎不完整，待查20180128
		//要在缩小状态下取数据才精确，否则少数据  考虑实时状态下的数据叠加问题，不好处理
		int nNewCount = (pcds->cbData - 1) / sizeof(CAPITALFLOWSTRUCK);
		int nNewIndex=0;
		CAPITALFLOWSTRUCK *ptr;

		if (m_nCapitalFlowRecords != nNewCount)
		{
			m_nCapitalFlowRecords = nNewCount;
		}
		else
		{
			i = nNewCount - 1;
			ptr = (CAPITALFLOWSTRUCK*)((BYTE*)pcds->lpData +i * sizeof(CAPITALFLOWSTRUCK));
			if (ptr->m_nDate== m_pCapitalFlow[i].m_nDate
				&& ptr->m_nTime== m_pCapitalFlow[i].m_nTime
				&&ptr->m_dblSmallBuy== m_pCapitalFlow[i].m_dblSmallBuy
				&&ptr->m_dblSmallSell== m_pCapitalFlow[i].m_dblSmallSell)
			{
				//数据相同时返回false，减少无关处理
				return false;
			}
			


		}

		EnterCriticalSection(&csMainFlowLock);

		for (i = nNewIndex; i < min(nNewCount,MAX_KLINE_COUNT); i++)
		{
			ptr = (CAPITALFLOWSTRUCK*)((BYTE*)pcds->lpData + i * sizeof(CAPITALFLOWSTRUCK));
			memcpy_s(&m_pCapitalFlow[i], sizeof(CAPITALFLOWSTRUCK),
				ptr, sizeof(CAPITALFLOWSTRUCK));
		}

		//long lVol = ptr->GetTotalVol();
		//double dblAmt = ptr->GetTotalFlow(), dblBig = ptr->GetBigNavFlow(),dblSmall=ptr->GetSmallNavFlow();
		LeaveCriticalSection(&csMainFlowLock);

		return true;
	}

	//动态分配内存易出现内存访问冲突  todo20180117
	bool AddL2Ticks(PCOPYDATASTRUCT pcds)
	{
		int nNewCount = (pcds->cbData - 1) / sizeof(L2TICKS);
		L2TICKS *pLastestTick = (L2TICKS *)(pcds->lpData)+nNewCount-1;//最新的ticks
		bool bRet = true;

		EnterCriticalSection(&csTicksDataLock);

		if (m_nTickCount != nNewCount || !m_pL2Ticks)
		{
			if (m_pL2Ticks)
			{
				delete m_pL2Ticks;
				m_pL2Ticks = NULL;
			}

			m_nTickCount = nNewCount;
			m_pL2Ticks = new L2TICKS[nNewCount];
			memcpy_s(m_pL2Ticks, pcds->cbData - 1, pcds->lpData, pcds->cbData - 1);
		}
		else if(pLastestTick->m_nIndex==m_pL2Ticks[nNewCount-1].m_nIndex)
		{
			bRet = false;
		}
		else
			memcpy_s(m_pL2Ticks, pcds->cbData - 1, pcds->lpData, pcds->cbData - 1);

		LeaveCriticalSection(&csTicksDataLock);

		return bRet;
	}

	//二分法确定最新的L2Ticks数据记录，返回nIndex下一项有效交易笔
	//nIndex目前已有的记录数：结构体中的最新数据
	int FindLastestL2TickRecord(PCOPYDATASTRUCT pcds, int nIndex)
	{
		L2TICKS usrL2Tick;
		int		nStop = (pcds->cbData - 1) / sizeof(L2TICKS),nStart=0;//起始数据项
		int		nReturn = 0;

		EnterCriticalSection(&csTicksDataLock);

		do
		{
			nReturn = (nStop + nStart) / 2;
			if (GetL2TickRecord(pcds, nReturn, &usrL2Tick))
			{
				if (usrL2Tick.m_nTime > m_pL2Ticks[nIndex].m_nTime)
				{
					//数据在低端
					nStop = nReturn;
				}
				else if (usrL2Tick.m_nTime == m_pL2Ticks[nIndex].m_nTime)
				{
					if (usrL2Tick.m_nIndex > m_pL2Ticks[nIndex].m_nIndex)
						//数据在低端
						nStop = nReturn;
					else if (usrL2Tick.m_nIndex < m_pL2Ticks[nIndex].m_nIndex)
						//数据在高端
						nStart = nReturn;
					else
						break;

				}
				else
				{
					//数据在高端
					nStart = nReturn;
				}
			}
			else
			{
				return -1;//没有合适的数据
				break;
			}

		} while (nStop-nStart>1);

		if (usrL2Tick.m_nIndex == m_pL2Ticks[nIndex].m_nIndex)
			nReturn = nReturn + 1;//point to next record
		else
		{
			if (nStop - nStart == 1)  //判定最新的数据项  数据可能不连续，中间可能丢失数据
			{
				GetL2TickRecord(pcds, nStart, &usrL2Tick);
				if(   (usrL2Tick.m_nTime > m_pL2Ticks[nIndex].m_nTime)
					||(usrL2Tick.m_nTime == m_pL2Ticks[nIndex].m_nTime
						&& usrL2Tick.m_nIndex>m_pL2Ticks[nIndex].m_nIndex) )
				{
					nReturn = nStart;
				}
				else
				{
					GetL2TickRecord(pcds, nStop, &usrL2Tick);
					if ((usrL2Tick.m_nTime > m_pL2Ticks[nIndex].m_nTime)
						|| (usrL2Tick.m_nTime == m_pL2Ticks[nIndex].m_nTime
							&& usrL2Tick.m_nIndex > m_pL2Ticks[nIndex].m_nIndex))
					{
						nReturn = nStop;
					}
					else
						nReturn = -1;

				}
			}
				
		}
		
		LeaveCriticalSection(&csTicksDataLock);

		return nReturn;
	}

	//读取指定的L2Ticks数据记录
	bool GetL2TickRecord(PCOPYDATASTRUCT pcds,int nIndex, L2TICKS *pL2Tick)
	{
		if ((pcds->cbData -1)/ sizeof(L2TICKS) >= nIndex)
		{
			int i = nIndex* sizeof(L2TICKS);
			pL2Tick->m_nTime = *(DWORD*)((BYTE*)pcds->lpData + i);
			pL2Tick->m_nIndex = *(DWORD*)((BYTE*)pcds->lpData + i + 4);
			pL2Tick->m_nPriceMul1000 = (*(DWORD*)((BYTE*)pcds->lpData + i + 8));
			pL2Tick->m_nVols=*(DWORD*)((BYTE*)pcds->lpData + i + 12) ;
			pL2Tick->m_nBS = *(BYTE*)((BYTE*)pcds->lpData + i + 16);
			return true;
		}
		else
			return false;
	}

};


