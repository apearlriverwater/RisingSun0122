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
#define  TRADE_CACL_COUNT 340  //trade���ݷ�����������
#define  MAX_KLINE_COUNT  4000

/*
�Դ��ǻ۳������Ϊ���������ֱ�׼���£�
1��С�� (<2 ��� �� 4 ��Ԫ )��                   С��4��
2���е� (2-10 ��� �� 4-20 ��Ԫ )��     100000   4-20��
3���� (10-50 ��� �� 20-100 ��Ԫ )��  200000   20-100��
4���ش� (>50 ��� �� 100 ��Ԫ ) ��    500000   ����100��
*/
#define  SMALLPENVOLS		20000
#define  SMALLPENMONWEY		40000

#define  MIDPENVOLS			100000
#define  MIDPENMONWEY		200000

#define  LARGEPENVOLS		200000
#define  LARGEPENMONWEY		1000000

#define  SUPERPENVOLS		500000
#define  SUPERPENMONWEY		1000000

//���������������ͣ�K�ߡ��ֱʡ��ʽ��������֣�DDE����������
#define STOCKDATACHANGE_KLINE			1  //K LINE DATA CHANGED
#define STOCKDATACHANGE_L2TICKS			2  //L2TICKS DATA CHANGED
#define STOCKDATACHANGE_CAPITALFLOW		3  //CAPITALFLOW	 DATA CHANGED

//���������������ͣ����롢�����������ۺ�
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
	DWORD dwStocks;//�ɽ�������3000��ʾ30�֣�231��ʾ231��
	BYTE  bBS;//1-������2-����

}L2DETAIL;

typedef struct tagMONEYFLOW {
	float	fInMoney, fOutMoney;   //�������
	int     nInVol, nOutVol;      //������
}MONEYFLOW;
//����̶�Ϊ17�ֽ����ݣ����ýṹ�嵥�ֽڶ��뷽ʽ
typedef struct tagL2TICKS {
	int m_nTime, m_nIndex;       //ʱ�䡢�ɽ������
	int m_nPriceMul1000, m_nVols;//�۸�*1000���ɽ�����
	char m_nBS;                  //�ɽ�����2��  1�� 0 ���ۣ�
}L2TICKS;

//dw  ����   ������													4bytes + 0
//dw  ʱ��   ��λ����												4bytes + 4
//double С���룬�е��룬���룬������   32bytes + 8��10H��18H��20H
//double С�������е������󵥳������󵥳�   32bytes + 32H��30H��38H��40H
//
//���Ƴɽ���
//qword С���룬�е��룬���룬������   32bytes + 48H��50H��58H��60H
//qword С�������е������󵥳������󵥳�   32bytes + 68H��70H��78H��80H
//����32�ֽ����ݲ��� + 88H typedef struct tagCAPITALFLOWSTRUCK
typedef struct tagCAPITALFLOWSTRUCK {
public:
	int32_t	m_nDate,m_nTime;       //date /ʱ��
	double	m_dblSmallBuy, m_dblMidBuy, m_dblBigBuy, m_dblHugeBuy;
	double	m_dblSmallSell, m_dblMidSell, m_dblBigSell, m_dblHugeSell;
	//�ɽ���������λ����
	int64_t	m_lSmallBuy, m_lMidBuy, m_lBigBuy, m_lHugeBuy;
	int64_t	m_lSmallSell, m_lMidSell, m_lBigSell, m_lHugeSell;
	//������
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


//�ʽ�����K������
typedef struct tagFLOWANDKLINE {
	int32_t	m_nDate, m_nTime;       //date ʱ��
	double	m_dblSmallBuy, m_dblMidBuy, m_dblBigBuy, m_dblHugeBuy;
	double	m_dblSmallSell, m_dblMidSell, m_dblBigSell, m_dblHugeSell;
	float                   open;                         ///<���̼�
	float                   close;                        ///<���̼�
	float                   high;                         ///<��߼�
	float                   low;                          ///<��ͼ�
	double                  volume;                       ///<�ɽ���
	double                  amount;                       ///<�ɽ����
}FLOWANDKLINE;

using namespace std;

typedef struct tagKLINEDATA
{
	/*int						date;                     ///bar��stopʱ��
	int						time;*/
	double					utcStop;
	float                   open;                         ///<���̼�
	float                   close;                        ///<���̼�
	float                   high;                         ///<��߼�
	float                   low;                          ///<��ͼ�
	double                  volume;                       ///<�ɽ���
	double                  amount;                       ///<�ɽ����

	//UTCֵ����׼ʱ������ת��
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

	////�仯�Ĺ�Ʊ��š��仯����
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

	//�仯�Ĺ�Ʊ��š��仯���ݡ���������
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
	CRITICAL_SECTION csMainFlowLock;  //�����ʽ�������
	CRITICAL_SECTION csKLineDataLock;  //K��������
	CRITICAL_SECTION csTicksDataLock;  //Ticks������

public:
	int m_nStockCode, m_nTradeDate;//��Ʊ���롢���½�����
	
	//��������������� nIndex:Data index, nResult:TA result
	//CINTEGER_QUEUE    m_nTaResult;  
	int m_nTickCount;   //���յ�ǰ�ܳɽ�����
	L2TICKS *m_pL2Ticks;		//��̬����ıʳɽ�����  ��6000����3000Ϊ����������¼��

	int m_nCapitalFlowRecords;   //captical�ܼ�¼��
	CAPITALFLOWSTRUCK m_pCapitalFlow[MAX_KLINE_COUNT];  //������m_pKLineData����ͬ�����ڡ�ͳһʱ�䷶Χ

	int   m_nKCount, m_nKWeek;   //K�߼�¼������K������
	KLINEDATA  m_pKLineData[MAX_KLINE_COUNT];//m_pCapitalFlowȷ��K�����ݣ�ʱ�䷶Χ������������һ��

public:
	bool CompareFlowKLine(KLINEDATA *pKLineData,int *nKCount)
	{
		bool bRet = true;
		int nDate, nTime,nCopySize;

		
		for (int i = 0; i < m_nCapitalFlowRecords; i++)
		{
			(pKLineData + i)->UTC2DateTime(&nDate, &nTime);

			//����ȱ���ݵ�ԭ���Ǹ������ڳɽ�Ϊ0������һ�����ݲ��벹0
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
			&& nKDate==m_pCapitalFlow->m_nDate    //K���ʽ�����ʼ����ʱ�����
			&& nKTime==m_pCapitalFlow->m_nTime)
		{
			(m_pKLineData+m_nKCount-1)->UTC2DateTime(&nKDate, &nKTime);
			
			if (nKDate == (m_pCapitalFlow + m_nCapitalFlowRecords-1)->m_nDate    //K���ʽ�����������ʱ�����
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
	�Դ��ǻ۳������Ϊ���������ֱ�׼���£�
		1��С�� (<2 ��� �� 4 ��Ԫ )��                   С��4��
		2���е� (2-10 ��� �� 4-20 ��Ԫ )��     100000   С��10��   
		3���� (10-50 ��� �� 20-100 ��Ԫ )��  200000   С��100��
		4���ش� (>50 ��� �� 100 ��Ԫ ) ��    500000   ����100��

		���󵥣����ڵ���50��ɻ���100��Ԫ�ĳɽ�����
		�󵥣����ڵ���10��ɻ���20��Ԫ��С��50��ɺ�100��Ԫ�ĳɽ�����
		�е������ڵ���2��ɻ���4��Ԫ��С��10��ɺ�20��Ԫ�ĳɽ�����
		С����С��2��ɺ�4��Ԫ�ĳɽ�����
		���룺����ɽ��
		�����������ɽ��
		�������룺���󵥼Ӵ�����ɽ���֮�ͣ�
		�������������󵥼Ӵ������ɽ���֮�ͣ�
		���������룺��������-����������
		�������-������
		��ռ�ȣ�������-������/�ܳɽ���
	
	*/
	
	//�����ʽ�����Ϣ���ɻ�����K�����ݣ���ʱ��֧�����߼������µ�K������
	//1/5/15/30/60/120
	void GetKLineMsg(char *szCode,
		char *szStartDT,char *szStopDT,
		int *nWeekInMinutes,int *nCount)
	{
		if (NULL == m_pCapitalFlow)  //todo���飺Ϊ�λ���� NULL == m_pCapitalFlow
			return;

		*nCount =m_nCapitalFlowRecords ;
		*nWeekInMinutes = (m_pCapitalFlow[0].m_nTime % 10000 - 3000) / 100;//���Ӳ�
		int	 nHour= (m_pCapitalFlow[0].m_nTime - 90000) / 10000;//Сʱ��

		*nWeekInMinutes = *nWeekInMinutes + nHour * 60;//תΪ�ܷ��Ӳ�
		if (*nWeekInMinutes > 120)
		{  // ����ʱ��
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

	//�����ʽ�����K�����ݣ����ں�������
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
				//�ļ�����  �������¼ӵĲ��֣����ļ����ļ�¼��ʼ�������
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
					nCopySize = sizeof(KLINEDATA) - sizeof(double);//����utcstop
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
				//�ļ�����  �������¼ӵĲ��֣����ļ����ļ�¼��ʼ�������
				//���������⣬��ʱ���ֲ���������������  todo20180427
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
			//�ļ�����  �������¼ӵĲ��֣����ļ����ļ�¼��ʼ�������
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
		else if(pTicks[0].m_nTime<=92505)  //�ӽ������ױʽ��׿�ʼ��¼  ��������ͣ�ƿ��ܼ�¼������
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
				nVols = m_pL2Ticks[i].m_nVols;               //��λ����
				if (nVols > 0)   //�������гɽ������
				{
					/*
					�Դ��ǻ۳������Ϊ���������ֱ�׼���£�
					1��С�� (<2 ��� �� 4 ��Ԫ )��           2���   С��4��
					2���е� (2-10 ��� �� 4-20 ��Ԫ )��     10���   4-20��
					3���� (10-50 ��� �� 20-100 ��Ԫ )��  20���   20-100��
					4���ش� (>50 ��� �� 100 ��Ԫ ) ��    50���   ����100��
					Ҫ����Դ�����ͣ�͵�ͣ����������ͣ�����������룬��ͣ������������
					*/
					fAmount = (float)(m_pL2Ticks[i].m_nPriceMul1000*nVols) / 1000;//��λ��Ԫ

					if (fAmount - 40000.0 < 0 || (nVols < 20000 && fAmount - 40000.0 < 0))
					{   //  С�� (<2 ��� �� <4 ��Ԫ )
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
					{   //  �е� (<10 ��� �� <20 ��Ԫ )
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
					{   //  �� (<20 ��� �� <100 ��Ԫ )
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
			wsprintfA(szData, "%06d,���%d��Ԫ,��%d��Ԫ,���%d��Ԫ", m_nStockCode, (int)(fAmount)-nOut, (int)fAmount, nOut);

			wsprintfA(strrchr(szData, 0), ",С�룺%d���,%d��Ԫ,С����%d���,%d��Ԫ",
				usrSmall.nInVol / 10000, (int)usrSmall.fInMoney / 10000, usrSmall.nOutVol / 10000, (int)usrSmall.fOutMoney / 10000);
			wsprintfA(strrchr(szData, 0), ",���룺%d���,%d��Ԫ,�г���%d���,%d��Ԫ",
				usrMid.nInVol / 10000, (int)usrMid.fInMoney / 10000, usrMid.nOutVol / 10000, (int)usrMid.fOutMoney / 10000);
			wsprintfA(strrchr(szData, 0), ",���룺%d���,%d��Ԫ,�����%d���,%d��Ԫ",
				usrLarge.nInVol / 10000, (int)usrLarge.fInMoney / 10000, usrLarge.nOutVol / 10000, (int)usrLarge.fOutMoney / 10000);
			wsprintfA(strrchr(szData, 0), ",�����룺%d���,%d��Ԫ,�������%d���,%d��Ԫ",
				usrSuper.nInVol / 10000, (int)usrSuper.fInMoney / 10000, usrSuper.nOutVol / 10000, (int)usrSuper.fOutMoney / 10000);

			fprintf(fp, "%s\n", szData);

			fclose(fp);
		}

	}

	//���ڸ������ڵ��ʽ�����Ϣ�ƻ�������ʽ�����??���ÿ�Դƽ̨���м��㣿��
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
				nVols = m_pL2Ticks[i].m_nVols;               //��λ����
				if (nVols > 0)   //�������гɽ������
				{
					/*
					�Դ��ǻ۳������Ϊ���������ֱ�׼���£�
					1��С�� (<2 ��� �� 4 ��Ԫ )��           2���   С��4��
					2���е� (2-10 ��� �� 4-20 ��Ԫ )��     10���   4-20��
					3���� (10-50 ��� �� 20-100 ��Ԫ )��  20���   20-100��
					4���ش� (>50 ��� �� 100 ��Ԫ ) ��    50���   ����100��
					Ҫ����Դ�����ͣ�͵�ͣ����������ͣ�����������룬��ͣ������������
					*/
					fAmount = (float)(m_pL2Ticks[i].m_nPriceMul1000*nVols) / 1000;//��λ��Ԫ

					if (fAmount - 40000.0 < 0 || (nVols < 20000 && fAmount - 40000.0 < 0))
					{   //  С�� (<2 ��� �� <4 ��Ԫ )
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
					{   //  �е� (<10 ��� �� <20 ��Ԫ )
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
					{   //  �� (<20 ��� �� <100 ��Ԫ )
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
			wsprintfA(szData, "%06d,���%d��Ԫ,��%d��Ԫ,���%d��Ԫ", m_nStockCode, (int)(fAmount)-nOut, (int)fAmount, nOut);

			wsprintfA(strrchr(szData, 0), ",С�룺%d���,%d��Ԫ,С����%d���,%d��Ԫ",
				usrSmall.nInVol / 10000, (int)usrSmall.fInMoney / 10000, usrSmall.nOutVol / 10000, (int)usrSmall.fOutMoney / 10000);
			wsprintfA(strrchr(szData, 0), ",���룺%d���,%d��Ԫ,�г���%d���,%d��Ԫ",
				usrMid.nInVol / 10000, (int)usrMid.fInMoney / 10000, usrMid.nOutVol / 10000, (int)usrMid.fOutMoney / 10000);
			wsprintfA(strrchr(szData, 0), ",���룺%d���,%d��Ԫ,�����%d���,%d��Ԫ",
				usrLarge.nInVol / 10000, (int)usrLarge.fInMoney / 10000, usrLarge.nOutVol / 10000, (int)usrLarge.fOutMoney / 10000);
			wsprintfA(strrchr(szData, 0), ",�����룺%d���,%d��Ԫ,�������%d���,%d��Ԫ",
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
		//�������ƺ�������������20180128
		//Ҫ����С״̬��ȡ���ݲž�ȷ������������  ����ʵʱ״̬�µ����ݵ������⣬���ô���
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
				//������ͬʱ����false�������޹ش���
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

	//��̬�����ڴ��׳����ڴ���ʳ�ͻ  todo20180117
	bool AddL2Ticks(PCOPYDATASTRUCT pcds)
	{
		int nNewCount = (pcds->cbData - 1) / sizeof(L2TICKS);
		L2TICKS *pLastestTick = (L2TICKS *)(pcds->lpData)+nNewCount-1;//���µ�ticks
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

	//���ַ�ȷ�����µ�L2Ticks���ݼ�¼������nIndex��һ����Ч���ױ�
	//nIndexĿǰ���еļ�¼�����ṹ���е���������
	int FindLastestL2TickRecord(PCOPYDATASTRUCT pcds, int nIndex)
	{
		L2TICKS usrL2Tick;
		int		nStop = (pcds->cbData - 1) / sizeof(L2TICKS),nStart=0;//��ʼ������
		int		nReturn = 0;

		EnterCriticalSection(&csTicksDataLock);

		do
		{
			nReturn = (nStop + nStart) / 2;
			if (GetL2TickRecord(pcds, nReturn, &usrL2Tick))
			{
				if (usrL2Tick.m_nTime > m_pL2Ticks[nIndex].m_nTime)
				{
					//�����ڵͶ�
					nStop = nReturn;
				}
				else if (usrL2Tick.m_nTime == m_pL2Ticks[nIndex].m_nTime)
				{
					if (usrL2Tick.m_nIndex > m_pL2Ticks[nIndex].m_nIndex)
						//�����ڵͶ�
						nStop = nReturn;
					else if (usrL2Tick.m_nIndex < m_pL2Ticks[nIndex].m_nIndex)
						//�����ڸ߶�
						nStart = nReturn;
					else
						break;

				}
				else
				{
					//�����ڸ߶�
					nStart = nReturn;
				}
			}
			else
			{
				return -1;//û�к��ʵ�����
				break;
			}

		} while (nStop-nStart>1);

		if (usrL2Tick.m_nIndex == m_pL2Ticks[nIndex].m_nIndex)
			nReturn = nReturn + 1;//point to next record
		else
		{
			if (nStop - nStart == 1)  //�ж����µ�������  ���ݿ��ܲ��������м���ܶ�ʧ����
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

	//��ȡָ����L2Ticks���ݼ�¼
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


