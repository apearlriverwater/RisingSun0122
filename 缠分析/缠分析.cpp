// ������.cpp : �������̨Ӧ�ó������ڵ㡣
/*
20170606 ��������һЩ�������������۷������ʽ��ȵ㣬����ǿ��ָ�꣬��ʵƽ������ָ��
һ�������г�����
���������ȸ����Լ��������й����У��������ķ�����ʲô�� ��ֵͶ�ʻ����г�Ͷ����������˵��������10�����ϵ��й�A�ɹ�Ʊ���������������������ϵĵ�������50%���µ�����һ��Ĺ�Ʊ������6�μ����ϳ���50%���µ���ÿ���µ�����50%�Ĺ����У��м�������ʵ���͵����ܼ����ֹɣ��м����ֹ����ܼ����Լ����ŵĹ�Ʊ�������ǹ���ę́�� ������ę́�������γ���50%�ĵ�����
�й����в�������֮�޴��Ƶ������ֵͶ���߻��Ҵ��˼����� ������Ͷ���߾޴�Ļ��ᣬ��Ϊÿ���µ�����50%�ĺ��棬�����о޴���Ƿ���
�й�A���г����ʺ�Ͷ������ô�����Ķ��������Ǽ�ֵ��ػ����г���أ� ���Ѿ����Զ�����  �ٿ�������Ͷ�ʾ޽�ղķ˹������˹��James Simons���� ����������ո��˻��𣬿�ʼʱ�������Ӱ����ܶ�����������ҵ��ƽƽ��������������Щ��רע�г����ӣ�������������һ�������������ԣ��Ҹ�ȷ�ţ������й����У������ķ����������г�Ͷ�����ء�
�������������ֶ�
�������Ǽ��������� ��Ү����������ֻ�ǲ������ߣ��г������������������������Ǹ��г������򹤵ģ������г������ļ����������ֿ����ۡ�������Ϧ��������Ǯ�Ŀ󹤻����
������Ϊ���г����ذ�����Щ����Ӧ�ĳ��ü����������ߣ�ָ�꣩����Щ��
1�������г�����---�������ߣ����ߡ��ɽ���
2���ʽ��ȵ�ȥ��---�������ߣ��ɽ���������ѻ��ͱ仯
3������ƫǿƫ��---�������ߣ����ǿ��ָ��ңӣ�
4�����ɲ�������---�������ߣ���ʵ�������Ⱦ�ֵ��ATR��
���������ʽ���
�г�����Ҫ���أ��ʽ�����
�ж��ʽ���ȵ�ȥ�򣬼���ռ���Ա��ص�һ�롣�ٶ�ı��������Ͷ��һ�������ս����ս����������ս��ȴû��������������ս������Ӯ�����ԣ��ٴ�ǿ���������ʽ��ȵ�ȥ�򣬵���ս����ȥ��
�ġ������ʽ�س�
����֮�£��������ѣ����ܴ�Խţ�ܵĹ�Ʊ̫���ˣ�������ę́�������γ���50%�ĵ��������ܳŵ�ס�𣿡��ҵĲ��Ծ��ǣ���������Ҫ�����̲��ã��ܳ������������ɲ��ã�����һЩ���������̸��ɶ����ã��Ͻ��ܣ�

*/
//
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <conio.h>
#include "stdafx.h"
#include<string.h>
#include<io.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <ctime>
#include<Windows.h>  
#include <WinSock.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <omp.h>
using namespace std;
#pragma  comment(lib, "wsock32.lib")

#include "stdafx.h"
#include "������.h"

//���ָ���ļ��Ƿ����
bool IsFileExist(char* strFile)
{
	struct stat my_stat;
	return (stat(strFile, &my_stat) == 0);
}
//��ȡָ���ļ���С
long GetFileSize(char* strFile)
{
	struct stat my_stat;
	stat(strFile, &my_stat);
	return my_stat.st_size;
}


//��ȡͨ���ŵ�����ȨϢ�ļ�,��ȡ��10��Ϊ��λ����ת��/�ֺ�/��ɺ���ɼ�/��ͨ�̱䶯��Ϣ,ÿ��֮����0x09�����
//���ݶ�֮��ͨ��0x09�ָ�,��������0x09���������ֶ�ȱʧ,���ݼ�¼֮��ķָ���0x0d,0x0a
//ͨ���ŵ�������ȨϢ�ļ�:����ȨϢ.txt���һ��ȨϢ�仯,����ȨϢ.txt����ȨϢ�仯 ����ȨϢ.txt���ܽ�������ȨϢ�仯
//nDataLen ָ�����������,����ʱ����Ϣ
//300381	�����	     20161018	20.00	1.000
//002456	ŷ�ƹ�	     20161202                    - 5.0	102797.9
//300547	�����Ƽ�	 20161202		10.000
//��������������ڵ�ȫϢ�䶯��Ϣ
// todo 0103 ���������,ȡ�ֺ��������쳣 
int	ReadQX(int nDataLen)
{
	FILE	*fp;
	string  sBuf, tmp;
	char buf[300];
	//����g_usrHis5KFileInfo.nStopYmd����Ҫ��ע
	int		nValidQuanXiDate =g_usrHis5KFileInfo.nStopYmd; //nValidQuanXiDate  ����ȨϢ��ֹ����
	int i = 0, j, nQuanXiCount = 256, nQuanXiIndex = 1;
	bool  bQuanxiValid = false;
	long lFp;

	sprintf_s(buf, "%s*ȨϢ.txt", g_sQuanxiPath);
	_finddata_t file;
	lFp = _findfirst(buf, &file);

	if (lFp == -1l)
		return false;

	g_pStockQuanXi = (StockQuanXi*)calloc(nQuanXiCount, sizeof(StockQuanXi));
	memset(g_pStockQuanXi, nQuanXiCount* sizeof(StockQuanXi), 0);

	do
	{
		sprintf_s(buf, "%s%s", g_sQuanxiPath, file.name);
		fopen_s(&fp, buf, "rb");
		if (fp != NULL)
		{
			memset(buf, 0, 256);
			do
			{
				//���һ����Ϣ�������,ԭ����,�ڴ����н����ж�,��������ȫ��ͬ��ȨϢ��¼
				fgets(buf, 256, fp);
				sBuf = buf;

				j = sBuf.find(9, 0);
				tmp = sBuf.substr(0, j);
				sBuf = sBuf.substr(j + 1, sBuf.length() - j - 1);

				// ��ȡ��Ʊ����
				g_pStockQuanXi[i].nCode = atoi(tmp.c_str());

				//������Ʊ����
				j = sBuf.find(9, 0);
				sBuf = sBuf.substr(j + 1, sBuf.length() - j - 1);


				//��ȡ������Ϣ
				j = sBuf.find(9, 0);
				tmp = sBuf.substr(0, j);
				sBuf = sBuf.substr(j + 1, sBuf.length() - j - 1);
				int  nTmp = atoi(tmp.c_str());
				//ȨϢ�仯�����ڱ����ڷ�����������
				g_pStockQuanXi[i].nDate = nTmp % 10000 + (nTmp / 10000 - 2004) * 2048;

				if (g_pStockQuanXi[i].nDate <= g_usrHis5KFileInfo.nStopYmd)
					break;

				//��ȡ��ת����Ϣ
				j = sBuf.find(9, 0);

				if (j > 0)
				{
					tmp = sBuf.substr(0, j);
					g_pStockQuanXi[i].fGiven = atof(tmp.c_str()) / 10;
					bQuanxiValid = true;
				}
				else
					bQuanxiValid = false;
				sBuf = sBuf.substr(j + 1, sBuf.length() - j - 1);


				//��ȡ�ֺ����Ϣ
				j = sBuf.find(9, 0);
				if (j > 0)
				{
					bQuanxiValid = true;
					tmp = sBuf.substr(0, j);
					g_pStockQuanXi[i].fGain = atof(tmp.c_str()) / 10;
				}

				sBuf = sBuf.substr(j + 1, sBuf.length() - j - 1);

				//��ȡ�����Ϣ
				j = sBuf.find(9, 0);
				if (j > 0)
				{
					sBuf = sBuf.substr(0, j);
					j = sBuf.find(' ', 0);
					if (j > -1)
					{
						tmp = sBuf.substr(0, j);
						sBuf = sBuf.substr(j + 1, sBuf.length() - j - 1);
						g_pStockQuanXi[i].fBuyCount = atof(tmp.c_str()) / 10;

						//��ȡ��ɹɼ���Ϣ
						g_pStockQuanXi[i].fBuyPrice = atof(sBuf.c_str());
						bQuanxiValid = true;
					}
				}

				//��ͨ�̱仯������

				if (bQuanxiValid == false)
					memset(&g_pStockQuanXi[i], 0, sizeof(StockQuanXi));
				else
				{
					//�޳��ظ���ȨϢ��Ŀ
					for (j = 0; j < i - 1; j++)
					{
						if (g_pStockQuanXi[i].nCode == g_pStockQuanXi[j].nCode  && g_pStockQuanXi[i].nDate == g_pStockQuanXi[j].nDate)
						{
							bQuanxiValid = !((g_pStockQuanXi[i].fBuyCount == g_pStockQuanXi[j].fBuyCount)
								&& (g_pStockQuanXi[i].fGain == g_pStockQuanXi[j].fGain)
								&& (g_pStockQuanXi[i].fGiven == g_pStockQuanXi[j].fGiven));

							if (bQuanxiValid == false) break;
						}
					}

					if (bQuanxiValid == true)
					{
						i++;

						if (i % nQuanXiCount == nQuanXiCount - 1)
						{
							nQuanXiIndex++;
							int n = nQuanXiIndex*nQuanXiCount;
							StockQuanXi *tmp = (StockQuanXi *)malloc(n*sizeof(StockQuanXi));
							memset(tmp, 0, n*sizeof(StockQuanXi));
							memcpy_s(tmp, n *sizeof(StockQuanXi), g_pStockQuanXi, (n - nQuanXiCount) *sizeof(StockQuanXi));
							free(g_pStockQuanXi);
							g_pStockQuanXi = tmp;
						}
					}

				}

			} while (!feof(fp));

			fclose(fp);
		}

	} while (_findnext(lFp, &file) == 0);

	_findclose(lFp);
	return 0;

}

//ǰ��Ȩ��ļ۸�
void	CaclQuanXiPrice(float fGiven, float fGain, float fBuyCount, float fBuyPrice, float *fPrice)
{
	*fPrice = (*fPrice - fGain + fBuyCount*fBuyPrice) / (1 + fGiven + fBuyCount);
}

//���ָ����ƱnCode�ڷ�������nStopDate���Ƿ���ȨϢ�䶯,���б䶯����true
bool	CheckQX(float *fGiven, float *fGain, float *fBuyCount, float *fBuyPrice,
	int *nDateLarge,int *nDateSmall,int nStopDate,int nStartDate, int nCode)
{
	bool ret = false;
	int	i = 0;
	while (g_pStockQuanXi[i].nCode != nCode && g_pStockQuanXi[i++].nCode>0);

	
	if (g_pStockQuanXi[i].nDate == nStopDate || g_pStockQuanXi[i].nDate == nStartDate)
	{
		*fGiven = g_pStockQuanXi[i].fGiven;
		*fGain = g_pStockQuanXi[i].fGain ;
		*fBuyCount = g_pStockQuanXi[i].fBuyCount;
		*fBuyPrice = g_pStockQuanXi[i].fBuyPrice;
		return true;
	}
	else if (g_pStockQuanXi[i].nDate> nStopDate)
		*nDateLarge = 1;
	else
		*nDateLarge = -1;

	if (g_pStockQuanXi[i].nDate< nStartDate)
		*nDateSmall = -1;
	else
		*nDateSmall = 1;

	return  ret;
}

//���ָ����ƱnCode����ȨϢ�䶯,���б䶯����true
bool	CheckCodeQX(int nCode)
{
	int	i = 0;
	if (g_pStockQuanXi != NULL)
	{
		while (g_pStockQuanXi[i].nCode != nCode && g_pStockQuanXi[i].nCode > 0) i++;
		return g_pStockQuanXi[i].nCode > 0;
	}
	else
		return false;
}

//����Ҫ���ԵĹ�Ʊ����ת������İ����м���
//�Ϻ���Ʊ����1000000
void SetDebugStockList(CStockBlockInfo *ptrStockBlock)
{
	const int nCount = 10;
	int i;
	int	nCode[nCount]={300264,300033,300356,-2395,-1,0};

	ptrStockBlock->usr5MinKDataInfo = new Stock5MinKData[nCount];
	memset(ptrStockBlock->usr5MinKDataInfo, 0, nCount * sizeof(Stock5MinKData));

	for (i = 0; i < nCount; i++)
	{
		if (nCode[i] > 0)
			ptrStockBlock->usr5MinKDataInfo[i].SetCode(nCode[i]);
		else
			break;
	}

	ptrStockBlock->nBlockCount = i;
}


//��ָ���Ĺ�Ʊ�������н���Ǳ����㣨123�������
//int blkList����Ʊ��������
void DetectBlockBuySignal(CStockBlockInfo *ptrBlockInfo, int nStopDate, int nStopTime)
	{
		int i = 0;

		//ʹ�ÿ��е�float������м���
		ptrBlockInfo->fMAShort = g_fbuf1;
		ptrBlockInfo->fMAMid = g_fbuf2;
		ptrBlockInfo->fMALong = g_fbuf3;
		
		for(i=0;i<ptrBlockInfo->nBlockCount;i++)
			FindUppingStock(ptrBlockInfo,i, nStopDate, nStopTime);

	}

void WriteLogHead(int nStep)
	{
		char sbuf[250]={0};
		int	 nDate,nTime;

		GetCurrentDateTime(&nDate,&nTime);

		/*sprintf_s(g_sLogFile,"%s%d-%d-trends.txt",g_sLogPath,nDate,(nTime)/100);
		sprintf_s(sbuf,"��Ʊ����,����,����,ʱ��,BSģʽ,BS����,�뵱ǰ��������,MACD,DIF");
		LogFile(g_sLogFile,sbuf);*/

		int		nNowYmd=(nDate/10000-104)*2048+nDate%10000;
		/*sprintf_s(g_sOneBuy, "%s%s-%s-%d-%d-OneBuy-%d min.txt", g_sTradePath,
			g_usrAutoTrade.strBlock, g_usrAnalysePattern[g_nAnalysePat].sName,
			nDate, (nTime) / 100, nStep * 5);*/

		if (g_nWorkMode == WORKMODE_REAL)
		{
			sprintf_s(g_sHolding, "%s%s-%s-Real-Holding.txt", g_sTradePath,
				g_usrAutoTrade.strBlock, g_usrAnalysePattern[g_nAnalysePat].sName);

			sprintf_s(g_sBSLog, "%s%s-%s-Real-BS.txt", g_sTradePath, 
				g_usrAutoTrade.strBlock, g_usrAnalysePattern[g_nAnalysePat].sName);
		}
		else
		{
			sprintf_s(g_sHolding, "%s%s-%s-%d-%d-Holding-%d min.txt", g_sTradePath,
				g_usrAutoTrade.strBlock, g_usrAnalysePattern[g_nAnalysePat].sName, 
				nDate, (nTime) / 100, nStep * 5);

			/*sprintf_s(sbuf, "����,ʱ��,����,����,������������");
			LogFile(g_sOneBuy, sbuf);*/
			//todo ����¼	 ����,����,ʱ��,����,�ɽ���,������,��ǰ�ֽ�,�����,ֹ���,ֹӯ��
			sprintf_s(g_sBSLog, "%s%s-%s-%d-%d-BS-%d min.txt", g_sTradePath, 
				g_usrAutoTrade.strBlock, g_usrAnalysePattern[g_nAnalysePat].sName,
				nDate, (nTime) / 100, nStep * 5);
		}

		if (IsFileExist(g_sHolding) == false)
		{
			sprintf_s(sbuf, "����,ʱ��,����,����,����,����,��ֵ,������,�ֽ�");
			int i = 0;
			while (g_sRefName[i].length()>0)
			{
				sprintf_s(sbuf, "%s,%s", sbuf, g_sRefName[i++].c_str());
			}
			LogFile(g_sHolding, sbuf);
		}

		if (IsFileExist(g_sBSLog) == false)
		{
			sprintf_s(sbuf, "����,����,ʱ��,��������,BS���ǵ���,����,�ɽ���,������,����,ģʽ,���ֲ�����,�ɽ���,ֹ���/����,ֹӯ��/ӯ����");
			LogFile(g_sBSLog, sbuf);
		}

	}

	//ѡ����ʱ�㷨ѵ����ͨ����ʷ�����γ�ģ��
	//��������Ƴɿ����䣬ͨ�����Ӳ�ͬ���㷨����ָ�뼴�����ж�Ӧ��ѧϰģʽ todo 20170210
	void Training(int nStopDate, int nStopTime, int nStep)
	{
		string sTmp;
		int  nLastDate = -1, j = 0;
		int  nCurDate, nCurTime;
		char	filepath[250] = { 0 };
		string	tmp, sBuf;
		int nDate, nTime;

		//��֤�㷨����ʵ�̼��ģʽ
		WriteLogHead(nStep);

		ReadTradeInfo();
		//Load1Buy();
		g_usrAutoTrade.bChanged = false;
		if (g_usrAutoTrade.nCurDate > 0)
			g_nAnalyseStartDate = g_usrAutoTrade.nCurDate;

		ReadDateList4Training(nStopDate,nStopTime);

		j = 0;
		if (g_usrAutoTrade.nCurDate>0)
			j = GotoStopDateTime(g_nMaxStockDateListCount, g_usrAutoTrade.nCurDate, 
				g_usrAutoTrade.nCurTime, g_usrStockDateList, 5);
		else
		{
			j = GotoStopDateTime(g_nMaxStockDateListCount, g_nAnalyseStartDate,
				g_nAnalyseStartTime, g_usrStockDateList, 5);
		}

		if (j<g_nStockDownDays * 48 && g_usrAutoTrade.nCurDate==0)
			j = g_nStockDownDays * 48+ nStep-1;

		g_usrBlock5MinKData.nStartYmd = g_usrStockDateList[j].nYmd;
		if(j+MAX5KS- g_nStockDownDays * 48>j)
			g_usrBlock5MinKData.nStopYmd = g_usrStockDateList[j + MAX5KS - g_nStockDownDays * 48].nYmd;
		else
			g_usrBlock5MinKData.nStopYmd = g_usrStockDateList[g_nMaxStockDateListCount-1].nYmd;

		g_usrBlock5MinKData.Read5MinKData();
		
		while (g_nMaxStockDateListCount > j)
		{
			nCurDate = g_usrStockDateList[j].nYmd;
			nCurTime = g_usrStockDateList[j].nMin;
			g_usrAutoTrade.nCurDate = nCurDate;
			g_usrAutoTrade.nCurTime = nCurTime;
			nDate = (nCurDate / 2048 + 104) * 10000 + nCurDate % 2048;
			nTime= (nCurTime / 60) * 100 + nCurTime % 60;

			printf("\n ����-%s-%s�����ڣ�%d,ʱ�䣺%d\n",
				g_usrAnalysePattern[g_nAnalysePat].sName,g_usrAutoTrade.strBlock,nDate,nTime);

			if (nLastDate != nCurDate)
			{
				//����δ��λ����1�����
				nLastDate = nCurDate;

				memset(&g_usrDayTrends, 0, sizeof(CDayTrends));
				g_usrDayTrends.usrBuy1List[0].bDown = true;
				DetectBlockBuySignal(&g_usrBlock5MinKData, nCurDate, nCurTime);
			}
			

			//�����Ż�����
			if (Buy1Cacl(nCurDate, nCurTime) == true)
				g_usrAutoTrade.DoBuy();

			if (Buy2SellxCacl(nCurDate, nCurTime) == true)
			{
				g_usrAutoTrade.Do2xBuy();
				g_usrAutoTrade.DoSell();
			}
				
			//�����������Ϣ,������g_usrAutoTrade�ṹ
			SaveTradeInfo(j);
			j += nStep;
			
		}//while (g_usrStockDateList[j].nYmd > 0)

		SaveTradeInfo(-1);
		SaveHolding2BSLog();
		LogBSFile(g_sBSLog,"");

		g_usrBlock5MinKData.Delete5MinKData();
		
}


int _tmain(int argc, _TCHAR* argv[])
	{
	string sbuf;

	InitApp();

	bool	bSetDebugStockList;
	int 	nStep;
	g_nAnalysePat = SetupParameters(argc, argv, &bSetDebugStockList);

	int  nDate, nTime;
	char sbuf1[250];

	if (g_nAnalysePat >= 0 && g_nAnalysePat < 4)
	{
		nStep = g_usrAnalysePattern[g_nAnalysePat].nStep;
		g_nMaxHolding = g_usrAnalysePattern[g_nAnalysePat].nMaxHolding;
		g_nStockDownDays = g_usrAnalysePattern[g_nAnalysePat].nStockDownDays;
		g_nWeekList = g_usrAnalysePattern[g_nAnalysePat].nWeekList;
		g_nStockBufSize = g_nStockDownDays * 48 + 100;
		g_nCJDBufSize = g_nStockDownDays * 48 / 15;
		g_nCZSPZBufSize = g_nStockDownDays * 48 / 30;
		g_fbuf1=new float[g_nStockBufSize],
		g_fbuf2= new float[g_nStockBufSize],
		g_fbuf3= new float[g_nStockBufSize];
		g_fMA1= new float[g_nStockBufSize],
		g_fMA2= new float[g_nStockBufSize],
		g_fMA3= new float[g_nStockBufSize];

		g_pusrNowKData = new  StockInfo[g_nStockBufSize];
		g_pusrCZSPZ =new  CZSPZInfo[g_nCZSPZBufSize];
		g_pusrCJD = new CJDInfo	[g_nCJDBufSize];
	}
	else
		return -1;

	GetCurrentDateTime(&nDate, &nTime);
	sprintf_s(sbuf1, "��ʼ����  ����:%d ʱ�䣺%06d",  nDate, nTime);
	LogFile("trade\\readlog.txt", sbuf1);

	//ѵ��ģʽ����ͷ��ʼ��ȡ��ʷ���ݣ�ǰg_nStockDownDays��������Ч����������
	if (   g_nWorkMode != WORKMODE_REAL)
	{
		//ѵ��ģʽ��,g_nAnalyseStopDate��ʾ��ֹ����������
		Training(g_nAnalyseStopDate, 900, nStep);
	}
	else
		RealMonitor(nStep);

	GetCurrentDateTime(&nDate, &nTime);
	sprintf_s(sbuf1, "��������  ����:%d ʱ�䣺%d", nDate, nTime);
	LogFile("trade\\readlog.txt", sbuf1);

	if (NULL!= g_usrStockDateList)
		delete g_usrStockDateList;
}

	//ʵʱ���
	int RealMonitor(int	nStep)
	{
		char sbuf[250] = { 0 };
		string sbuf1;
		int	nStopDate, nStopTime;
		int nLastDate = -1;

		ReadDateList4Real(g_nAnalyseStopDate);

		//��֤�㷨����ʵ�̼��ģʽ
		WriteLogHead(nStep);

		//�ӿ�ʼ���׵�ʱ������
		int  j = 0;

		ReadTradeInfo();
		g_usrAutoTrade.bChanged = false;

		//ָ���Ѽ������ʱ��	

		if (g_usrAutoTrade.nCurDate>0)
			j = GotoStopDateTime(g_nMaxStockDateListCount, g_usrAutoTrade.nCurDate,
				g_usrAutoTrade.nCurTime, g_usrStockDateList, 5);
		else
		{
			j = GotoStopDateTime(g_nMaxStockDateListCount, g_nAnalyseStartDate,
				g_nAnalyseStartTime, g_usrStockDateList, 5);
			j =max(j, g_nStockDownDays * 48-1);
		}

		g_usrBlock5MinKData.nStartYmd = g_usrStockDateList[j].nYmd;
		g_usrBlock5MinKData.nStopYmd = g_usrStockDateList[g_nMaxStockDateListCount - 1].nYmd;

		g_usrBlock5MinKData.Read5MinKData();

		for (; j<g_nMaxStockDateListCount; j += nStep)
		{
			g_sMailContent = "";
			g_sMailTitle = "BS����";

			nStopDate = g_usrStockDateList[j].nYmd;
			nStopTime = g_usrStockDateList[j].nMin;
			g_usrAutoTrade.nCurDate = g_usrStockDateList[j].nYmd;
			g_usrAutoTrade.nCurTime = g_usrStockDateList[j].nMin;
			
			printf("\n ʵʱ-%s-%s�����ڣ�%d,ʱ�䣺%d\n",
				g_usrAnalysePattern[g_nAnalysePat].sName,g_usrAutoTrade.strBlock,
				(nStopDate / 2048 + 104) * 10000 + nStopDate % 2048,
				(nStopTime / 60) * 100 + nStopTime % 60);

			//20170318��Ϊÿ���������ھ��жϣ���ֹ��ʧ����ʱ��
			if (nLastDate != nStopDate)
			{
				nLastDate = nStopDate;
				memset(g_usrDayTrends.usrBuy1List, 0, BUY1STOCKNUMBERS * sizeof(DayTrends));
				g_usrDayTrends.usrBuy1List[0].bDown = true;
				g_usrDayTrends.nBuy1Count = 0;
				DetectBlockBuySignal(&g_usrBlock5MinKData, nStopDate, nStopTime);
				
			}

			//ʵʱ����:ʵʱ���ģʽ
			if (Buy1CaclReal(j, nStopDate) == true)
				g_usrAutoTrade.DoBuy();

			if (Buy2SellxCaclReal(nStopDate, nStopTime) == true)
			{
				g_usrAutoTrade.Do2xBuy();
				g_usrAutoTrade.DoSell();
			}

			//�����������Ϣ,������g_usrAutoTrade�ṹ
			SaveTradeInfo(j);
		}

		//���ڵ�ǰ�������ڷ��ͽ���������Ϣ
		if (g_sMailContent.length() > 0 && g_nWorkMode == WORKMODE_REAL)
		{
			char sbuf[1024];
			sprintf_s(sbuf, "title:%s\ncontent:%s\n", g_sMailTitle.c_str(), g_sMailContent.c_str());
			LogFile((char*)&g_sRealMail[0], sbuf);
		}
		
		SaveTradeInfo(-1);
		SaveHoldingStock();
		//SaveHolding2BSLog();
		LogBSFile(g_sBSLog, "");
		WriteTradeInfo();
		return true;
	}
//��ʼ��Ӧ�ó������
void	InitApp()
{
	memset(&g_usrDayTrends.usrBuy1List,0,sizeof(DayTrends)*BUY1STOCKNUMBERS);
	memset(&g_usrAutoTrade, 0, sizeof(CAutoTrade));

	//��ȡ5����K�������ļ���Ϣ
	string sbuf1;
	sbuf1 = g_sTDXHisDataPath;
	sbuf1.append("sh\\fzline\\sh000001.lc5");
	Get5MinKFileInfo(sbuf1, &g_usrHis5KFileInfo);

	sbuf1 = g_sTDXPath;
	sbuf1.append("sh\\fzline\\sh000001.lc5");
	Get5MinKFileInfo(sbuf1, &g_usrTDX5KFileInfo);
	sbuf1 = g_sRealPath;
	sbuf1.append("1000001.lc5");
	Get5MinKFileInfo(sbuf1, &g_usrReal5KFileInfo);
}

//�԰���ڵĹ�Ʊ���з������ҳ����������ֵ�ı�ģ���������ǰBUY1STOCKNUMBERS��
//�������Ƿ�ֲ֣�ͳһ�����������
bool FindUppingStock(CStockBlockInfo *ptrBlockInfo,int nStockIndex, int nStopDate, int nStopTime)
{
	char	filepath[250] = { 0 };
	string	tmp, sBuf;
	int	nMaxLen;
	
	int kk = 0, nDataLen = 0;
	//�ֱֲ�Ĳ����ж�
	if (g_usrAutoTrade.StockInList(ptrBlockInfo->usr5MinKDataInfo[nStockIndex].nCode,NULL))
		return  false;

	Stock5MinKData *ptr5MinKData=&ptrBlockInfo->usr5MinKDataInfo[nStockIndex];

	//�жϵ�ǰ����Ƿ��з�����ֵ
	StockInfo *p5MinKData=ptr5MinKData->usrKData, 
		*pNowKData= g_pusrNowKData;

	//û��K������ֱ�ӷ���false
	if (NULL== p5MinKData || p5MinKData->nYmd == 0) return false;

	int nCode = ptr5MinKData->nCode;
	int nMarket=0;
	CNowTrends  usrNowTrends;

	nMaxLen = ptr5MinKData->lCount;

	//��������ȡ��Ч��5����K������
	nDataLen = GotoStopDateTime(nMaxLen, nStopDate, nStopTime, p5MinKData)+1;

	usrNowTrends.p5MinKData = p5MinKData;
	usrNowTrends.pNowKData = g_pusrNowKData;
	usrNowTrends.n5MinKDataLen = nDataLen;
	usrNowTrends.nCode = nCode;

	if (nDataLen >= g_nStockDownDays * 48 
		&& p5MinKData[nDataLen - 1].nNumber > 0 //�޳�����ͣ�Ʊ��
		&& usrNowTrends.CheckRuler(m_pRulerFunction)==true)    //�����¼ӹ�����
	{
		p5MinKData += nDataLen - g_nStockDownDays * 48;
		nDataLen = g_nStockDownDays * 48;
		if (p5MinKData[nDataLen - 1].nYmd == nStopDate
			&& p5MinKData[nDataLen - 1].nMin == nStopTime)
			
		{
			g_usrAutoTrade.nCurDate = nStopDate;
			g_usrAutoTrade.nCurTime = nStopTime;

			memset(&usrNowTrends, 0, sizeof(CNowTrends));
			usrNowTrends.nCode = nCode;
			usrNowTrends.p5MinKData = p5MinKData;

			//��ʼ��CJD��������������
			memset(g_pusrCJD, 0, g_nCJDBufSize * sizeof(CJDInfo));
			memset(g_pusrCZSPZ, 0, g_nCZSPZBufSize * sizeof(CZSPZInfo));
			usrNowTrends.usrCJD = g_pusrCJD;
			usrNowTrends.usrCZSPZ = g_pusrCZSPZ;

			usrNowTrends.SetLastDateDayClose(nDataLen, usrNowTrends.p5MinKData);
			//��ǰ����ʱ��ͣ���ͣ��������
			if (usrNowTrends.UpStop(nDataLen, usrNowTrends.p5MinKData)
				|| usrNowTrends.DownStop(nDataLen, usrNowTrends.p5MinKData))
				return false;

			usrNowTrends.fMALong = ptrBlockInfo->fMALong;
			usrNowTrends.fMAMid = ptrBlockInfo->fMAMid;
			usrNowTrends.fMAShort = ptrBlockInfo->fMAShort;

			//��ȡ5���Ӽ���������Сֵ
			usrNowTrends.pNowKData = p5MinKData;
			usrNowTrends.SetMaxHighMinLow(nDataLen);
			usrNowTrends.pNowKData = pNowKData;
			usrNowTrends.fCurClose = p5MinKData[nDataLen-1].fClose;

			//��ʼ��CJD��������������
			memset(g_pusrCJD,0,g_nCJDBufSize*sizeof(CJDInfo));
			memset(g_pusrCZSPZ, 0, g_nCZSPZBufSize * sizeof(CZSPZInfo));
			usrNowTrends.usrCJD = g_pusrCJD;
			usrNowTrends.usrCZSPZ = g_pusrCZSPZ;
			return usrNowTrends.IsUp4Buy(nDataLen, p5MinKData);
		}
	}

	return false;
}

//�����Ʊ��ȫ�����벢������g_nBlockList�����ٷ���ʹ��
int CopyStock2Block()
{
	_finddata_t file;
	char	filepath[250] = { 0 };
	string	tmp, sBuf;
	long	lFp;
	int		nBlockCount ,*nStockList;
	int  j = 0;

	if (g_nWorkMode == WORKMODE_REAL)
	{
		nBlockCount = 4000;
	}
	else
	{
		nBlockCount = 1250;
	}

	nStockList = new int[nBlockCount];

	//�ҳ���ǰ����ȫ�����׵Ĺ�Ʊ����
	for (int nMarket = 0; nMarket < 2; nMarket++)
	{
		string sTmp = g_sTDXPath;
		sTmp.append(g_sMinute5[nMarket]);
		lFp = _findfirst(sTmp.c_str(), &file);
		
		if (lFp != -1l)
		{
			//�жϵ�ǰ����Ƿ��з�����ֵ
			do
			{
				tmp = file.name;
				tmp = tmp.substr(2, 6);
				int nCode = atoi(tmp.c_str());
				if (IsAnalyse(nCode, nMarket) == true &&  IsSTStock(nCode) == false)
				{
					if (nMarket==1)
						nStockList[j++]= nCode + 1000000;
					else
						nStockList[j++] = nCode ;
				}
			} while (_findnext(lFp, &file) == 0  && j<nBlockCount);

			_findclose(lFp);
		}
	}
	
	if (nBlockCount > 0)
	{
		g_usrBlock5MinKData.usr5MinKDataInfo = (Stock5MinKData*)calloc(nBlockCount, sizeof(Stock5MinKData));
		memset(g_usrBlock5MinKData.usr5MinKDataInfo, 0, nBlockCount * sizeof(Stock5MinKData));

		int i;
		for (i = 0; i < nBlockCount; i++)
			g_usrBlock5MinKData.usr5MinKDataInfo[i].SetCode(nStockList[i]);

		g_usrBlock5MinKData.nBlockCount = nBlockCount;
	}
	

	delete nStockList;

	return  nBlockCount;
}


//��ȡ5����K������,������ʷ����(����ʢͶ�����صĳ�Ȩ����ʷ5��������,��ֹ2016��12�µ�)
//path ��ʷ�����ļ��� ,nCode��Ʊ���루���ã�, ����ָ��*pStockMinuteInfo��nMaxSize��ʾpStockMinuteInfo��С
//nStart5MinPlace��ʷ���ݿ�ʼ��¼����ʾ�ӵ�nStart5MinPlace��5�������ݼ�¼��ʼ��ȡ���ݣ�0ʱ��ʾ���ļ�ͷ��ʼ��ȡ����
//��ʷ���ݽ�ֹ����ʱ��nStopDate/nStopTime���������nMaxSize,�����ζ�ȡ�봦��todo 20170210
//����ʵ�ʶ�ȡ��5������������,�������pStockMinuteInfo
int  ReadHis5MinKData4Real(string path, int nCode, StockInfo *pStockMinuteInfo, int nMaxSize,
	long nStart5MinPlace, int nStopDate, int nStopTime)
{
	int		nDataLen = 0;//��ǰ��Ч���ݼ�¼��
	FILE	*fp;

	if (   NULL == pStockMinuteInfo 
		|| nStopDate>=g_usrHis5KFileInfo.nStopYmd
		|| IsSTStock(nCode)==true)  //ST���Ĵ��벻������
		return -1;
	
	fopen_s(&fp, path.c_str(), "rb");

	if (fp != NULL)
	{
		fseek(fp, 0, SEEK_END);
		//��ָ���ļ�¼�ʼ��ȡ����
		fseek(fp, nStart5MinPlace*32, SEEK_SET);
		nDataLen = fread(pStockMinuteInfo, 32, nMaxSize, fp);
		fclose(fp);
	}
	
	return nDataLen;
}

//��ȡ5����K������,������ʷ����(����ʢͶ�����صĳ�Ȩ����ʷ5��������,��ֹ2016��12�µ�)/ͨ���������ǰ���ص�����,
//���ݷ�����ʱ�ν���ȨϢ�����ϲ���ȫ��������ں�������
//�ȶ�ȡͨ�������Ŀ¼��5��������,Ȼ�󲹶���ʷ����
//string HisPath,string TdxPath,string FileName�ļ���, StockInfo *pStockMinuteInfo nMaxSize��ʾpStockMinuteInfo��С
//nReadDays ���ȡnStopDate/nStopTime ǰ���½����յ�5����K������
//����ʵ�ʶ�ȡ��5������������,�������pStockMinuteInfo
int  Read5MinKData4Training(string path, string HisPath, 
	int nCode, StockInfo *pStockMinuteInfo, int nMaxSize,
	int nReadDays, int nStopDate, int nStopTime)
{
	char	filepath[250] = { 0 };
	int		nDataLen = 0;//��ǰ��Ч���ݼ�¼��
	int		j, i;
	string	tmp, sBuf;
	long	lFp = -1;
	char	sbuf[250];
	FILE	*fp;
	bool	bMoveData = true;
	int		nRealCount = 0;//ʵʱ������
	int		nReadCount = 0;

	/* ����nStopDate/nStopTime����ʷ����/ͨ��������/ʵʱ���ݵĹ�ϵ��ȡ5����K������
	���ݴӻ�����ĩ�˿�ʼװ��,���ͳһ�Ƶ�pStockMinuteInfo��ʼ��
	����ͨ��������ʱ:�ȶ�ȡʵʱ����
	������ʷ����ʱ:���ȶ�ȡͨ��������
	С��ͨ��������ʱ:����ȡ��ʷ����
	*/

	if (NULL == pStockMinuteInfo)   
		return -1;

	j = path.find("*.lc5", 0);
	if (j > 0)
	{
		path = path.substr(0, j);
		sprintf_s(sbuf, "*%06d.lc5", nCode);
		path.append(sbuf);
	}

	//��ȡ��ʷ5����K������
	if (   g_nAnalyseStartDate >=g_usrHis5KFileInfo.nStartYmd
		&& g_nAnalyseStartDate <=g_usrHis5KFileInfo.nStopYmd)
	{
		// ����ͨ����5�����ļ�·�� E:\02soft\new_tdx\vipdoc\sh\fzline\sh000001.lc5
		string stmp;

		stmp = path.substr(g_sTDXPath.length(), 10);
		stmp.append(stmp.substr(0, 2));
		stmp.append(path.substr(path.length() - 10, 10));
		sBuf = HisPath;
		sBuf.append(stmp);
		long lSize = GetFileSize((char*)sBuf.c_str()) / 32;
		StockInfo *buf = new StockInfo[lSize];
		fopen_s(&fp, sBuf.c_str(), "rb");
		
		if (fp != NULL)
		{
			nDataLen = fread(buf, 32, lSize, fp);
			fclose(fp);
			//������ȡ��ʷ����
			j = GotoStopDateTime(nDataLen, nStopDate, nStopTime, buf, 5);
			i = nReadDays * 48;
			if (j>-1)
			{
				if (j - i>0)
				{
					memmove_s(pStockMinuteInfo, i * 32, &buf[j - i + 1], i * 32);
					nDataLen = i;
				}
				else if (j - i<0)
				{
					if (nDataLen == 0)
					{
						nDataLen = -1;
						memset(pStockMinuteInfo,0, i * 32);
					}
					else
					{
						memmove_s(pStockMinuteInfo, i * 32, buf, (j +1)* 32);
						nDataLen = j +1;  //���ݲ���,����ȫ����������
					}
				}
			}
			else
			{
				//�ж�������Ч��:���nStopDate����pStockMinuteInfo[nDataLen - 1].nYmd,����û�и�ʱ�ε�����,ȡ�����µ��������
				if (pStockMinuteInfo[nDataLen - 1].nYmd < nStopDate
					|| (pStockMinuteInfo[nDataLen - 1].nYmd == nStopDate  && pStockMinuteInfo[nDataLen - 1].nMin <= nStopTime))
				{
					j = nReadDays * 48;
					if (nDataLen>j)
					{
						memmove_s(pStockMinuteInfo, j * 32, &buf[nDataLen - j], j * 32);
						nDataLen = j;
					}
				}
				else
					//��ֹʱ��С����ֹʱ�����û�п�������
				{
					memset(pStockMinuteInfo, 0, i * 32);
					nDataLen= -1;
				}
			}
			delete buf;
		}
	}
		
	return nDataLen;
}


//����ȡͨ�������Ŀ¼��5�������ݺ�ʵʱ5����K������
//path ָ��K���ļ���Ŀ¼,nCode ����, StockInfo *pStockMinuteInfo nMaxSize��ʾpStockMinuteInfo��С
//nReadDays ���ȡnStopDate/nStopTime ǰ���½����յ�5����K������
//����ʵ�ʶ�ȡ��5������������,�������pStockMinuteInfo
int  Read5MinKData4Real(string path, int nCode, 
	               StockInfo *pStockMinuteInfo, int nMaxSize,
	               int nReadDays,int nStopDate,int nStopTime)
{
	_finddata_t file;
	char	filepath[250] = { 0 };
	int		nDataLen = 0;//��ǰ��Ч���ݼ�¼��
	int		j,i;
	string	tmp, sBuf;
	long	lFp = -1;
	char	sbuf[250];
	FILE	*fp;
	bool	bMoveData = true;
	int		nRealCount = 0;//ʵʱ������
	int		nReadCount = 0;

	/* ����nStopDate/nStopTime��ͨ��������/ʵʱ���ݵĹ�ϵ��ȡ5����K������
	   ���ݴӻ�����ĩ�˿�ʼװ��,���ͳһ�Ƶ�pStockMinuteInfo��ʼ��
		�ȶ�ȡͨ�������ݶ���Ȼ��ȡʵʱ����
	*/

	if (NULL == pStockMinuteInfo) return -1;
	
	j = path.find("*.lc5", 0);
	if (j > 0)
	{
		path = path.substr(0, j);
		sprintf_s(sbuf, "*%06d.lc5", nCode);
		path.append(sbuf);
	}

	//��ȡʵʱ��ͨ����5����K������
	{
		lFp = _findfirst(path.c_str(), &file);
		if (lFp != -1l)
		{
			// ��ȡ���µ�  nReadDays���5��������,min( nReadDays ,MAX5KS)��ָֹ�����
			int nReadLen = min(nReadDays * 48, nMaxSize) * 32;
			
			sBuf = path.substr(0, path.find_last_of("\\") + 1);
			sBuf.append(file.name);
			fopen_s(&fp, sBuf.c_str(), "rb");

			if (NULL != fp)
			{
				//��ֹ�������
				i = file.size / 32;

				//��ʷ�ļ�������Ŀ������Ҫ������,��ȡ���µ�nReadLen����
				{
					fseek(fp, -nReadLen, SEEK_END);
					if (nMaxSize - nDataLen - nReadLen/32 < 0)
						//������̫С,�޷�������
					{
						fclose(fp);
						return -1;
					}
					else
					{
						j = fread(pStockMinuteInfo, 32, nReadLen / 32, fp);
						nDataLen = j;
						fclose(fp);
					}
				}
			}
		}

		//��ȡ����5����ʵʱK������
		if (nStopDate >= g_usrTDX5KFileInfo.nStopYmd)
		{
			nRealCount = TimeDiff(nStopTime, 570) / 5;
			if (nRealCount >= 0 && nMaxSize - nRealCount >= 0 && nDataLen>0)
			{
				nRealCount = ReadReal5MinKData(g_nWorkMode, path, pStockMinuteInfo+nDataLen, nRealCount);
			}
			else
				nDataLen = ReadReal5MinKData(g_nWorkMode, path, pStockMinuteInfo, nRealCount);
		}
	}

	//������Ч���ж�
	{
		//data valid,���ݽ���λ��
		j = GotoStopDateTime(nDataLen, nStopDate, nStopTime, pStockMinuteInfo, 5);
		if (j>-1)
		{
			i = nReadDays * 48;
			if (i < j)
			{
				memmove_s(pStockMinuteInfo, i * 32, &pStockMinuteInfo[j - i+1], i * 32);
				nDataLen = i;
			}
			else if(j - i<0)
			{
				//���ݲ���,����ȫ���������� 
				//ͣ�ƺ��Ƶ������ݲ�����  �������¶�ȡ����TODO 20170320
				nDataLen = j + 1;  
			}
		}
		else
		{
			//�ж�������Ч��:���nStopDate����pStockMinuteInfo[nDataLen - 1].nYmd,����û�и�ʱ�ε�����,ȡ�����µ��������
			if (pStockMinuteInfo[nDataLen - 1].nYmd < nStopDate 
				|| (pStockMinuteInfo[nDataLen - 1].nYmd == nStopDate  && pStockMinuteInfo[nDataLen - 1].nMin<nStopTime) )
			{
				j = nReadDays * 48;
				if (nDataLen>j)
				{
					memmove_s(pStockMinuteInfo, j * 32, &pStockMinuteInfo[nDataLen - j], j * 32);
					nDataLen = j;
				}
			}
			else
				//��ֹʱ��С����ֹʱ�����û�п�������
			{
				return -1;
			}
		}
	}

	_fcloseall();
	return nDataLen;
}

//��ȡ5����ʵʱK������
// path ��ǰ��ȡ��5������ʷ�����ļ�·��,usrTmpʵʱ���ݴ洢��ʼλ��
int  ReadReal5MinKData(WORKMODE nReal,string path, StockInfo *usrTmp,int nReadCount)
{
	//��ȡ���յ�5��������,ֱ�Ӹ�������ʷ���ݺ���
	int n5KLen = 0;
	int nMarket, nCode;
	char sbuf[250];

	if (nReal !=WORKMODE_REAL)
		return n5KLen;

	nMarket = path.find("sh");
	if (nMarket>0)
		nMarket = 1;
	else
		nMarket = 0;

	nCode = atoi(path.substr(path.length() - 10, 6).c_str());
	path = g_sRealPath;
	sprintf_s(sbuf, "%07d.lc5", nCode + nMarket * 1000000);
	path.append(sbuf);

	FILE	*fpReal;

	fopen_s(&fpReal, path.c_str(), "rb");
	if (NULL != fpReal)
	{
		n5KLen = fread(usrTmp, 32, nReadCount, fpReal);
		fclose(fpReal);
	}
	return n5KLen;
}
//������֤��ָ5�����������ݶ�ȡ����������
void ReadDateList4Real(int nDays)
{
	int	nReadCount = min(nDays * 48, MAX5KS) * 32, i, j;
	StockInfo * usrTmp=NULL;
	string path;
	FILE *fp;

	int	 nLastLen=-1,nOldDataCount;
	int  nNowDate, nNowTime;
	GetCurrentDateTime(&nNowDate, &nNowTime);
	nNowDate = CreateStockDate(nNowDate);

	path=g_sTDXPath;
	i = 0;
	path.append (g_sRefIndex[i]);
		
	long lSize = GetFileSize((char*)path.c_str()) / 32;
	g_usrStockDateList = new RefStockInfo[lSize+g_nStockDownDays*48+48];
	StockInfo *p5MinKData = new StockInfo[lSize + g_nStockDownDays * 48+48];

	path = g_sTDXHisDataPath;
	path.append(g_sRefIndex[i]);
	fopen_s(&fp, path.c_str(), "rb");

	if (NULL != fp)
	{
		fseek(fp, -g_nStockDownDays * 48*32, SEEK_END);
		nOldDataCount = fread(p5MinKData,32, g_nStockDownDays * 48,fp);
		fclose(fp);
	}

	path = g_sTDXPath;
	path.append(g_sRefIndex[i]);
	fopen_s(&fp, path.c_str(), "rb");

	//g_sRefIndex[i] ��ʽ "sz\\fzline\\sz399006.lc5"
	g_nMaxStockDateListCount = nOldDataCount+ Read5MinKData4Real(path,
		atoi((g_sRefIndex[i]).substr(12, 6).c_str()), p5MinKData+ nOldDataCount, 
		lSize+48,  nDays+1, nNowDate, 900);

	usrTmp = p5MinKData;
	j=0;
	g_usrStockDateList[0].nIndex[0] = 1.0;//��ֹ���ֱ�����쳣

	while (j<g_nMaxStockDateListCount)
	{
		g_usrStockDateList[j].nYmd =usrTmp[j].nYmd ;
		g_usrStockDateList[j].nMin  =usrTmp[j].nMin  ;
		g_usrStockDateList[j].nIndex[i]=(int)usrTmp[j].fClose ;
		g_usrStockDateList[j].fAmount[i]=usrTmp[j++].fAmount; 
	}

	i=1;
	while(g_sRefIndex[i].length ()>0)
	{
		g_usrStockDateList[0].nIndex[i] = 1.0;//��ֹ���ֱ�����쳣

		path = g_sTDXHisDataPath;
		path.append(g_sRefIndex[i]);
		fopen_s(&fp, path.c_str(), "rb");

		if (NULL != fp)
		{
			fseek(fp, -g_nStockDownDays * 48 * 32, SEEK_END);
			nOldDataCount = fread(p5MinKData, 32, g_nStockDownDays * 48, fp);
			fclose(fp);
		}

		path = g_sTDXPath;
		path.append((g_sRefIndex[i]).substr(0, 10));
		path.append("*.lc5");

		//g_sRefIndex[i] ��ʽ "sz\\fzline\\sz399006.lc5"
		g_nMaxStockDateListCount = nOldDataCount+ Read5MinKData4Real(path,
			atoi((g_sRefIndex[i]).substr(12, 6).c_str()), p5MinKData+ nOldDataCount,
			lSize, nDays, nNowDate, 900);

		j=0;
		usrTmp = p5MinKData;
		//�������Ʋ�ָͬ�������ݶ�׼����   todo 1107
		while(usrTmp[j].nMin==g_usrStockDateList[j].nMin  && usrTmp[j].nYmd ==g_usrStockDateList[j].nYmd 
			&& j<g_nMaxStockDateListCount)
		{
			g_usrStockDateList[j].nIndex[i]=(int)usrTmp[j].fClose ;
			g_usrStockDateList[j].fAmount[i]=usrTmp[j++ ].fAmount; 
		}
		i++;
	}

	if (g_nMaxStockDateListCount>0)
		ReadQX(g_nMaxStockDateListCount);
}

//������֤��ָ5�����������ݶ�ȡ����������  �����㷨�Ż�����
void ReadDateList4Training(int nStopDate,int nStopTime)
{
	int	nReadCount =  MAX5KS * 32, i, j;
	StockInfo * usrTmp = NULL;
	string path;
	
	int	 nLastLen = -1;
	i = 0;

	path = g_sTDXHisDataPath;
	path.append((g_sRefIndex[i]));
	long lSize = GetFileSize((char*)path.c_str())/32;
	g_usrStockDateList = new RefStockInfo[lSize];
	StockInfo *p5MinKData=new StockInfo[lSize];

	path = g_sTDXPath;
	path.append((g_sRefIndex[i]).substr(0, 10));
	path.append("*.lc5");
	//g_sRefIndex[i] ��ʽ "sz\\fzline\\sz399006.lc5"
	g_nMaxStockDateListCount = Read5MinKData4Training(path, g_sTDXHisDataPath,
		atoi((g_sRefIndex[i]).substr(12, 6).c_str()), p5MinKData, 
		lSize, lSize / 48, nStopDate, nStopTime);

	usrTmp = p5MinKData;

	for (j = 0; j < 7; j++)
	{
		g_usrStockDateList[0].nIndex[j] = 1;//��ֹ���ֱ�����쳣
	}
		
	j = 0;
	while (j<g_nMaxStockDateListCount)
	{
		g_usrStockDateList[j].nYmd = usrTmp[j].nYmd;
		g_usrStockDateList[j].nMin = usrTmp[j].nMin;
		g_usrStockDateList[j].nIndex[i] = (int)usrTmp[j].fClose;
		g_usrStockDateList[j].fAmount[i] = usrTmp[j++].fAmount;
	}

	i = 1;
	while (g_sRefIndex[i].length()>0)
	{
		g_usrStockDateList[0].nIndex[i] = 1.0;//��ֹ���ֱ�����쳣
		path = g_sTDXPath;
		path.append((g_sRefIndex[i]).substr(0, 10));
		path.append("*.lc5");

		//g_sRefIndex[i] ��ʽ "sz\\fzline\\sz399006.lc5"
		j = Read5MinKData4Training(path, g_sTDXHisDataPath,
			atoi((g_sRefIndex[i]).substr(12, 6).c_str()), p5MinKData,
			lSize, lSize / 48, nStopDate, nStopTime);

		j = 0;
		usrTmp = p5MinKData;
		//�������Ʋ�ָͬ�������ݶ�׼����   todo 1107
		while (usrTmp[j].nMin == g_usrStockDateList[j].nMin  
			&& usrTmp[j].nYmd == g_usrStockDateList[j].nYmd
			&& j<g_nMaxStockDateListCount)
		{
			g_usrStockDateList[j].nIndex[i] = (int)usrTmp[j].fClose;
			g_usrStockDateList[j].fAmount[i] = usrTmp[j++].fAmount;
		}
		i++;
	}
	delete p5MinKData;
}


void MakeStockDateTime(int nDataLen,int *nDate,int *nTime,StockInfo *pNowKData)
{
   int	tmp=pNowKData[nDataLen].nYmd;

   *nDate=	(tmp/2048+104)*10000   +tmp%2048;
   tmp=pNowKData[nDataLen].nMin ;
   *nTime=(tmp/60)*100+tmp%60;
}

//����ͨ����ѹ����ʽ�����ڸ�ʽ,��ڲ���Ϊ1170101,7λ�������ڸ�ʽ,ǰ��λѹ���������
int CreateStockDate(int nDate)
{
   return  (nDate/10000-104)*2048 + nDate%10000;
}
//����ͨ����ѹ����ʽ�����ڸ�ʽ,��ڲ���Ϊ20170101,8λ�������ڸ�ʽ,ǰ4λ�����
int CreateStockDateByGeneralDate(int nDate)
{
	return  (nDate / 10000 - 2004) * 2048 + nDate % 10000;
}

int CreateStockTime(int nTime)
{
	return  (nTime/100)*60+nTime%100;
}

//��������Ƹ�ʽ������������
//���������ݸ�ʽ������,����,ʱ��,�������ڣ�����,�ɽ���,������,����,ģʽ,���ֲ�����,�����,ֹ���,ֹӯ��
void LogBSFileAsBin(char *FilePath, string *msg)
{

}

void LogBSFile(char *FilePath, char *msg)
{
	static string strFileBuf = "";

	if (strlen(msg) > 0)
	{
		strFileBuf.append(msg);
		strFileBuf.append("\n");
		if (strFileBuf.length() > 65536)
		{
			LogFile(FilePath, (char*)strFileBuf.c_str());
			strFileBuf = "";
		}
	}
	else
	{
		LogFile(FilePath, (char*)strFileBuf.c_str());
		strFileBuf = "";
	}
}

void LogFile(char *FilePath,char *msg)
{
	FILE	*fp;
	    
	fopen_s(&fp,FilePath,"a+");
	if (fp!=NULL) 
	{
		fprintf(fp,"%s\n",msg);  
		fclose(fp);
	}
}



void	GetCurrentDateTime(int *Date,  int *Time)
{
   // current date/time based on current system
   time_t now = time(0);

   tm ltm;
   localtime_s(&ltm,&now);
   
   // print various components of tm structure.
   *Date= 10000* ltm.tm_year +100*( 1 + ltm.tm_mon)+ ltm.tm_mday ;
   *Time=10000*(ltm.tm_hour )+100*( 1 + ltm.tm_min)+ 1 + ltm.tm_sec ;
}

void	Log(char *msg)
{
	FILE	*fp;
	  
	fopen_s(&fp,"log\\log.txt","a+");
	fprintf(fp,"%s\n",msg);  
	fclose(fp);
}


//����ǰ�ֲ�������浽�ļ�
//nDateIndex  ��ǰ������ʱ�����,����ȡ���Ա�ʱ��
//nDateIndex==-1  ���������������������ļ�
void	SaveTradeInfo(int nDateIndex)
{
	char	sbuf[250];
	BSInfo * ptrBuySell;
	CNowTrends	*pTrends;
	int		nBuyDate,i,nHolding=0,nAmount=0;
	float	fFund=0,fCost;
	bool bHolding,bHasHolding=false;
	static string strFileBuf="";

	if (nDateIndex == -1 )
	{
		if (strFileBuf.length() >  10)
		{
			LogFile(g_sHolding, (char*)strFileBuf.c_str());
			strFileBuf = "";
		}
		return;
	}

	//��ǰ����
	nBuyDate=(g_usrAutoTrade.nCurDate/2048+104)*10000 +g_usrAutoTrade.nCurDate %2048;

	for(i=0;i<g_nMaxHolding;i++)
	{
		pTrends=&g_usrAutoTrade.usrStockTrade[i]; 
		ptrBuySell=pTrends->GetusrBuy ();
		bHolding=false;
		nAmount=0;
		fCost=0;
		for(int j=0;j<BSCOUNT  && pTrends->nHoldingAmount >0;j++)
		{
			if((ptrBuySell+j)->nAmount >0 )	 //����Ŀǰ�ֲֵı��
			{
				nAmount=nAmount+ (ptrBuySell+j)->nAmount;
				fCost+=(ptrBuySell+j)->nAmount*(ptrBuySell+j)->fBuySellPrice ;
				bHolding=true;
				bHasHolding=true;
			}
		}
			
		if(bHolding==true)  
		{
			nHolding++;
			float fAmount=nAmount *pTrends->GetCurClose();
			unsigned short nDate,nTime;

			//ȡ��ǰ����ʱ��
			pTrends->GetCurDateTime (&nDate,&nTime);

			//��¼��ǰ���ڡ�ʱ�䡢�ֹɴ��롢���������ۡ���ǰ���̼ۡ���ֵ���ǵ����ʺ��ֽ�
			sprintf_s(sbuf,"%07d,%4d,%07d,%04d,%04.2f,%04.2f,%04.2f,%03d,%04.2f\n",
				(nDate/2048+104)*10000+nDate%2048 ,
				(nTime/60)*100+nTime%60,
				pTrends->GetCode(),nAmount, pTrends->fAveragePrice,  pTrends->GetCurClose(),
				fAmount/100,(int)(100*fAmount/fCost)-100,g_usrAutoTrade.fNowFund /10000)  ;

			strFileBuf.append(sbuf);
			
			//puts(sbuf);

			//�ۼ�Ŀǰ�ֲ���ֵ
			fFund=fFund+nAmount *pTrends->GetCurClose()/100;
		}
		else 
		//δ�ֲ֣�����ýṹ�������
		{
			if(pTrends->GetCode ()>0)
			{
				memset(pTrends,0,sizeof(CNowTrends));
			}
		}
	}

	//��¼��ǰ���ڡ�ʱ�����ʲ���ӯ�����
	if(bHasHolding==true)
	{
		g_usrAutoTrade.fCurHolding =fFund*10000;
		g_usrAutoTrade.fNowGain =(g_usrAutoTrade.fCurHolding+g_usrAutoTrade.fNowFund)/g_usrAutoTrade.fStartFund *100 -100;
		sprintf_s(sbuf,"%07d,%4d,%07d,%04d,%04.2f,%04.2f,%04.2f,%03d,%04.2f,%04d,%04d,%04d,%04d,%04d,%04d,%04d\n",
			(g_usrAutoTrade.nCurDate/2048+104)*10000+g_usrAutoTrade.nCurDate%2048 ,
			(g_usrAutoTrade.nCurTime/60)*100+g_usrAutoTrade.nCurTime%60,
			1234567,
			nHolding,8888.88,
			(g_usrAutoTrade.fNowFund+g_usrAutoTrade.fCurHolding)/10000,
			g_usrAutoTrade.fCurHolding/10000,
			(int)g_usrAutoTrade.fNowGain ,
			g_usrAutoTrade.fNowFund /10000,
			100 * g_usrStockDateList[nDateIndex].nIndex[0] / g_usrStockDateList[0].nIndex[0]- 100,
			100 * g_usrStockDateList[nDateIndex].nIndex[1] / g_usrStockDateList[0].nIndex[1]- 100,
			100 * g_usrStockDateList[nDateIndex].nIndex[2] / g_usrStockDateList[0].nIndex[2]- 100, 
			100 * g_usrStockDateList[nDateIndex].nIndex[3] / g_usrStockDateList[0].nIndex[3] - 100,
			100 * g_usrStockDateList[nDateIndex].nIndex[4] / g_usrStockDateList[0].nIndex[4] - 100,
			100 * g_usrStockDateList[nDateIndex].nIndex[5] / g_usrStockDateList[0].nIndex[5] - 100,
			100 * g_usrStockDateList[nDateIndex].nIndex[6] / g_usrStockDateList[0].nIndex[6] - 100);

		strFileBuf.append(sbuf);
		puts(sbuf);

		if (strFileBuf.length() > 65536 * 10)
		{
			LogFile(g_sHolding, (char*)strFileBuf.c_str());
			strFileBuf = "";
		}
	}
	
}

//����ǰ�ֲִ���������浽�ļ�
void	SaveHoldingStock()
{
	int		i, j, *nStock;
	nStock = new int[g_nMaxHolding];
	memset(nStock, 0, sizeof(int)*g_nMaxHolding);
	j = 0;
	for (i = 0; i<g_nMaxHolding; i++)
	{
		if (g_usrAutoTrade.usrStockTrade[i].nHoldingAmount >0)
			nStock[j++] = g_usrAutoTrade.usrStockTrade[i].nCode;
	}

	DeleteFile((LPCWSTR)g_sHoldingStock);
	FILE	*fp;
	fopen_s(&fp, g_sHoldingStock, "wb");
	if (fp != NULL)
	{
		fwrite(&nStock, sizeof(nStock), 1, fp);
		fclose(fp);
	}

}

//����ǰ�ֱֲ�ı��浽BSLog�ļ���������execl����ӯ������
void	SaveHolding2BSLog()
{
	int nAmount;
	unsigned short nDate= g_usrAutoTrade.nCurDate, 
				   nTime= g_usrAutoTrade.nCurTime;

	for (int i = 0; i<g_nMaxHolding; i++)
	{
		if ((nAmount=g_usrAutoTrade.usrStockTrade[i].nHoldingAmount) == 0)
			continue;

		CNowTrends  *pTrends = &g_usrAutoTrade.usrStockTrade[i];

		float fAmount = nAmount *pTrends->GetCurClose()*100;
		
		char sbuf[256];
		

		//����,����,ʱ��,�������ڣ�BS���ǵ���,����,�ɽ���,������,����,ģʽ,���ֲ�����,�����,ֹ���,ֹӯ��
		sprintf_s(sbuf, "%07d,%07d,%04d,%04d,%04d,%04d,%06.2f,%04.2f,%02d,%02d,%04d,%04.2f,%04.2f,%04.2f",
			pTrends->GetCode(), (nDate / 2048 + 104) * 10000 + nDate % 2048,
			(nTime / 60) * 100 + nTime % 60, 5, 0, -nAmount, fAmount,
			0.0,  -BSTYPE_MAXHOLDWEEKS, BSMODE_MAXHOLDWEEKS,
			0, pTrends->GetCurClose(), 0.0,0.0);

		LogBSFile(g_sBSLog, sbuf);
	}
}

//����ǰ1�����������浽�ļ�  ���浽cfgĿ¼  "ʵʱ���.txt"
void	Save1BuyStock()
{
	FILE	*fp;
	int		nStock[BUY1STOCKNUMBERS+2], i, j,nCode;
	char    sbuf[64];
	DeleteFile((LPCWSTR)g_s1BuyStock);
	DeleteFile((LPCWSTR)g_sRealMonitor);

	memset(nStock, 0, sizeof(int)*(BUY1STOCKNUMBERS+2));
	//ǰ�����ֽ�Ϊ���·�������ʱ��
	nStock[0] = g_usrAutoTrade.nCurDate;
	nStock[1] = g_usrAutoTrade.nCurTime;
	j = 2;
	
	fopen_s(&fp, g_sRealMonitor, "wt");
	for (i = 0; i<g_usrDayTrends.nBuy1Count; i++)
	{
		nCode = g_usrDayTrends.usrBuy1List[i].nCode;
		if (nCode > 0)
		{
			nStock[j++] =nCode;
			//д��1���ļ�
			sprintf_s(sbuf, "%07d\n", nCode);
			fputs(sbuf, fp);
		}
			
	}
	fclose(fp);

	if (j > 0)
	{
		fopen_s(&fp, g_s1BuyStock, "wb");
		fwrite(&nStock, sizeof(int), j, fp);
		fclose(fp);
	}

	
}

//����ǰ1���Ķ���
void	Load1Buy()
{
	FILE	*fp;

	fopen_s(&fp, g_sDayTrends, "rb");
	if (fp != NULL)
	{
		fread_s(&g_usrDayTrends, sizeof(CDayTrends), sizeof(CDayTrends), 1, fp);
		fclose(fp);
	}
}

//��ȡ��ѡ�ֲ�/ƽ���ĸ���Ͷ�˷���
int	ReadZXCC(char *strPath)
{
	FILE	*fp;
	string  sBuf, tmp;
	char buf[256];
	int i = 0, j, nHoldingIndex = -1, nCodeIndex = 0;
	bool  bHoldingFound = false;
	long lFp;

	memset(&g_usrZXHolding, 0, ZXHOLDINGCOUNT * sizeof(ZXHolding));

	//����ʵʱģʽ�·�����ѡ�ֲ�
	if (g_nWorkMode != WORKMODE_REAL)
		return false;

	_finddata_t file;
	lFp = _findfirst(strPath, &file);

	if (lFp == -1l)
		return false;

	do
	{
		sprintf_s(buf, "%s%s", g_sRealCfg, file.name);
		fopen_s(&fp, buf, "rb");
		if (fp != NULL)
		{
			bHoldingFound = false;
			do
			{
				memset(buf, 0, 256);
				fgets(buf, 256, fp);
				sBuf = buf;

				j = sBuf.find('[', 0);
				if (j >= 0)
				{
					i = sBuf.find(']', j + 1);
					if (i > 0)
					{
						if (nHoldingIndex<ZXHOLDINGCOUNT - 1)
							nHoldingIndex++;

						nCodeIndex = 0;
						bHoldingFound = true;
						sprintf_s(&g_usrZXHolding[nHoldingIndex].strName[0], 60, "%s", (char*)sBuf.substr(j + 1, i - j - 1).c_str());
					}
				}
				else if (bHoldingFound == true)
				{
					if (nCodeIndex<ZXHOLDINGCOUNT)
						g_usrZXHolding[nHoldingIndex].nCode[nCodeIndex++] = atoi(buf);
				}

			} while (!feof(fp));

			fclose(fp);
		}
	} while (_findnext(lFp, &file) == 0);
	_findclose(lFp);
	return 0;

}

//��ȡ��ȡ����Ʊ����,���ش�����������Ӧ5����K������
int	ReadBLOCK(char *strPath,CStockBlockInfo *ptrStockBlock)
{
	FILE	*fp;
	char *buf;
	int i = 0, nSize = 0,j=0;

	fopen_s(&fp, strPath, "rb");
	if (fp != NULL)
	{
		//������1200��Ʊ����ֹ�ڴ治�㵼���쳣��������� 20170402
		nSize =min( GetFileSize(strPath),1200*9);
		buf =(char*) malloc(nSize + 64);
		memset(buf, 0, nSize + 64);
		fread(buf, nSize, 1, fp);
		fclose(fp);

		if (nSize > 0)
		{
			ptrStockBlock->nBlockCount = nSize/9;
			ptrStockBlock->usr5MinKDataInfo = new Stock5MinKData[nSize/9+1];
			memset(ptrStockBlock->usr5MinKDataInfo, 0, (nSize / 9 +1) * sizeof(Stock5MinKData));
		}
		else
			return -1;

		//ÿ���¼9�ֽڣ�7�ֽڴ��룬2�ֽڣ�0d0a
		while (*(buf + i)==0x0d || *(buf + i) == 0x0a)  i++;
		for(;i<nSize;i+=9)
		{
			*(buf + i + 7) = 0;
			ptrStockBlock->usr5MinKDataInfo[j++].SetCode( atoi(buf + i));
		}
		free(buf);
	}
	ptrStockBlock->nBlockCount = j;
	return j;
}

//��ȡ��ȡ����Ʊ����,���ش�������
int	ReadBLOCK(char *strPath)
{
	FILE	*fp;
	char *buf;
	int i = 0, nSize = 0, j = 0;
	int *ptrList=NULL;

	fopen_s(&fp, strPath, "rb");
	if (fp != NULL)
	{
		nSize = GetFileSize(strPath);
		buf = (char*)malloc(nSize + 64);
		memset(buf, 0, nSize + 64);
		fread(buf, nSize, 1, fp);
		fclose(fp);

		if (nSize > 0)
		{
			ptrList = (int*)malloc((nSize / 9 + 2) * sizeof(int));
			memset(ptrList, 0, (nSize / 9 + 2) * sizeof(int));
		}
		else
			return -1;


		//ÿ���¼9�ֽڣ�7�ֽڴ��룬2�ֽڣ�0d0a
		for (i = 0; i<nSize; i += 9)
		{
			*(buf + i + 7) = 0;
			ptrList[j++] = atoi(buf + i);
		}
		free(buf);
	}

	if (j > 0)
	{
		g_usrBlock5MinKData.usr5MinKDataInfo = (Stock5MinKData*)calloc(j, sizeof(Stock5MinKData));
		memset(g_usrBlock5MinKData.usr5MinKDataInfo, 0, j * sizeof(Stock5MinKData));
		int i;
		for (i = 0; i < j; i++)
			g_usrBlock5MinKData.usr5MinKDataInfo[i].SetCode(ptrList[i]);

		g_usrBlock5MinKData.nBlockCount = j;
	}
	return j;
}

//��ȡ��ȡST����Ʊ����,����ST��������
int	ReadSTBLOCK(char *strPath)
{
	FILE	*fp;
	char *buf;
	int i = 0, nSize = 0, j = 0;

	memset(&g_nSTlist, 0, STNUMBERS * sizeof(int));
	fopen_s(&fp, strPath, "rb");
	if (fp != NULL)
	{
		nSize = GetFileSize(strPath) + 64;
		buf = (char*)malloc(nSize);
		memset(buf, 0, nSize);
		fread(buf, nSize, 1, fp);
		fclose(fp);
		//ÿ���¼9�ֽڣ�7�ֽڴ��룬2�ֽڣ�0d0a
		for (i = 0; i<nSize-64; i += 9)
		{
			*(buf + i + 7) = 0;
			g_nSTlist[j++] = atoi(buf + i);
		}

		free(buf);
	}
	return j;
}
//�ж�ָ�������Ƿ�ΪST����Ա�����򷵻�true
bool  IsSTStock(int nCode)
{
	int i = 0, j = STNUMBERS-1,k=0;
	bool bRet = false;
	
	//������Ч�Ĵ���
	while (g_nSTlist[j--] == 0);

	//���ַ�����ȷ��ָ����Ʊ�Ƿ�����ST���
	do
	{
		k = (i + j) / 2;
		if (nCode > g_nSTlist[k])
			i = k;
		else if (nCode < g_nSTlist[k])
			j = k;
		else
		{
			bRet = true;
			break;
		}
	} while (j - i > 1);

	return bRet;
}

//��ȡ��ǰ�ֲ�������Զ���ֲ�����,�����ص��ע��ָ����Ϊ�ѳֱֲ��,������������
void	ReadTradeInfo()
{
	FILE	*fp;
	fopen_s(&fp, g_sTradeFile, "rb");
	if (NULL != fp)
	{
		fread_s(&g_usrAutoTrade, sizeof(CAutoTrade), sizeof(CAutoTrade), 1, fp);
		fclose(fp);
	}

	if (g_usrAutoTrade.fNowFund == 0)
		g_usrAutoTrade.InitFund(1000000, MAXHOLDDAYS);


	int i = 0, k = g_nMaxHolding;
	memset(&g_usrAutoTrade.usrStockTrade[k], 0, (MAXTRADENUMBER - k) * sizeof(CNowTrends));

	//�����ص��ע��ָ��  ��;���󣬽�����ʹ��20170311
	//i = 0;
	//while (g_usrStockIndexCodeName[i].unCode>0)
	//{
	//	if (k < MAXTRADENUMBER)
	//	{
	//		g_usrAutoTrade.usrStockTrade[k].nCode = g_usrStockIndexCodeName[i].unCode;
	//		//���Զ�����,��Ϊ�趨һ���ĳֲ���,�����������
	//		g_usrAutoTrade.usrStockTrade[k].nHoldingAmount = 10;
	//		g_usrAutoTrade.usrStockTrade[k].usrBuy[0].nAmount = 10;
	//		g_usrAutoTrade.usrStockTrade[k].usrBuy[0].nYmd = 10;
	//		g_usrAutoTrade.usrStockTrade[k].nBuyIndex = 1;
	//		k++;
	//	}
	//	else
	//		return;

	//	i++;
	//}

	//ReadZXCC("cfg\\��ѡ�ֲ�.txt");

	//while (strlen(g_usrZXHolding[i].strName)>0)
	//{
	//	j = 0;
	//	while (g_usrZXHolding[i].nCode[j] > 0)
	//	{
	//		if (g_usrAutoTrade.StockZXCCList(g_usrZXHolding[i].nCode[j]) == false
	//		 && g_usrAutoTrade.StockInList(g_usrZXHolding[i].nCode[j]) == false)
	//			if (k < MAXTRADENUMBER )
	//			{
	//				g_usrAutoTrade.usrStockTrade[k].nCode = g_usrZXHolding[i].nCode[j];
	//				//���Զ�����,��Ϊ�趨һ���ĳֲ���,�����������
	//				g_usrAutoTrade.usrStockTrade[k].nHoldingAmount = 10;
	//				g_usrAutoTrade.usrStockTrade[k].usrBuy[0].nAmount = 10;
	//				g_usrAutoTrade.usrStockTrade[k].usrBuy[0].nYmd = 10;
	//				g_usrAutoTrade.usrStockTrade[k].nBuyIndex = 1;
	//				k++;
	//			}
	//				else
	//					return;

	//		j++;
	//	}
	//	i++;
	//}


}

//����ǰ�ֲ���������ļ�����������ֱ��ʹ��
void	WriteTradeInfo()
{
	FILE	*fp;
	fopen_s(&fp,g_sTradeFile,"wb");
	if(NULL!=fp)
	{
		fwrite(&g_usrAutoTrade, sizeof(CAutoTrade),  1, fp);
		fclose(fp);
	}
}

//������ǰ��Ʊ�Ƿ��ڳֲ��б��ڼ�����TRUE
bool	StockInTrade(CNowTrends *ptrTrends,int nCode)
{
	return g_usrAutoTrade.StockInList(nCode, ptrTrends);
}


void CheckAutoSell(int nDataLen,StockInfo *ptrStockInfo,int nWeek)
{
	//g_usrAutoTrade.AutoSell(nDataLen,ptrStockInfo,nCode,nWeek);
}

//���Լ����������ڵĲ�,�����Ǵ��¡�С�ºͶ��µ�����
//d1��d2Ϊͨ����ѹ�������������
int	DateDiff(int d1,int d2)
{
	int y1,y2,m1,m2;
	int	nStartY,nStopY,nStartM,nStopM,nStartD,nStopD;
	if(d1!=d2)
	{
	   	nStartY=d1/2048;
		nStopY=d2/2048;
		nStartM=d1%2048/100;
		nStopM=d2%2048/100;
		nStartD=d1%2048%100;
		nStopD=d2%2048%100;

		m1=(nStartM+9)%12;
		y1=nStartY-m1/10;
		d1=365*y1+y1/4-y1/100+y1/400+(m1*306+5)/10+(nStartD-1);

		m2=(nStopM+9)%12;
		y2=nStopY-m2/10;
		d2=365*y2+y2/4-y2/100+y2/400+(m2*306+5)/10+(nStopD-1);

	   return d1-d2;
	}
	else  
		return 0   ;

}

//���㽻��ʱ���
int	TimeDiff(int d1,int d2)
{
	int ret=d1-d2;
	
	int h1=d1/60;
	int h2=d2/60;
	if(h2>=13 && h1<13)
			ret=ret+90;	
	else  if(h1>=13 && h2<13)
			ret=ret-90;


	return ret;
}
//���Լ������ڼ�ָ������
int		DateAdd(int nYMD,int g_nAnalyseStopDate)	
{
	  int	nYear=nYMD/2048,nMonth=(nYMD%2048)/100,nDay=(nYMD%2048)%100+g_nAnalyseStopDate;
	  if((nMonth==2 && nDay>28)	)
	  {
			nMonth++;
			nDay-=28;
	  }
	  else if (nMonth!=2 && nDay>30)
	  {
			nMonth++;
			nDay-=30;
	  }

	  if(nMonth>12)
	  {
		  nYear++;
		  nMonth=1;
	  }
	  return nYear*2048+ nMonth*100+nDay;

}

//��������жϣ����ӹ�Ʊ���з���nMode=1����Ҫʱ�������������
bool IsAnalyse(int nCode,int nMode)
{
	bool	ret=false;
	switch(nMode)
	{
	case 0:
		//����
		if( (nCode<9999) ||(nCode>=300000 && nCode<301000 ))
			ret=true;

		break;
	case 1:
		//�Ϻ�
		if( nCode>=600000 && nCode<605000 )
			ret=true;

		break;
	case 99:
		//���������������ּ�����ȣ������жϣ�ֱ�ӷ���true
		ret = true;

		break;
	}

	return ret;
}

//�Ե�ǰ��Ʊ��ǰ�ڵ��������̾������ƽ�����Ѷ������������ǰBUY1STOCKNUMBERS
//����ǰ����ı����ǰBUY1STOCKNUMBERS���ڷ���true
//���Ǳ���������ݣ�*nWeekList���������б� Ȩ�ؼ���15-1,30-2,45-3,60-4,90-5
//nDownWeeks  δʹ��
bool	SortDownStock(int nCode, int nBSType, int nDownRate1, short *nWeekList)
{
	int nValue = 0;
	int i = 0;
	bool	ret = false;

	//��ͬ����Ȩ�ز�һ��
	while (nWeekList[i]>0)
	{
		nValue += nWeekList[i++] / 15;
	}

	i = 0;
	while (g_usrDayTrends.usrBuy1List[i].bDown == true)
	{
		int j = g_usrDayTrends.nBuy1Count;
		if (g_usrDayTrends.usrBuy1List[i].nValue <nValue && i <= j)
		{
			if (j == BUY1STOCKNUMBERS - 1)
			{
				if (i<BUY1STOCKNUMBERS - 1)
					memcpy(&g_usrDayTrends.usrBuy1List[i + 1],
						&g_usrDayTrends.usrBuy1List[i], (j - i) * sizeof(DayTrends));
			}
			else
			{
				memcpy(&g_usrDayTrends.usrBuy1List[i + 1],
					&g_usrDayTrends.usrBuy1List[i], (j - i + 1) * sizeof(DayTrends));
				g_usrDayTrends.nBuy1Count++;
			}

			g_usrDayTrends.usrBuy1List[i].nCode = nCode;
			g_usrDayTrends.usrBuy1List[i].nValue = nValue;
			g_usrDayTrends.usrBuy1List[i].nDownRate = nDownRate1;
			g_usrDayTrends.usrBuy1List[i].bDown = true;
			memcpy(&g_usrDayTrends.usrBuy1List[i].nWeekList[0], nWeekList, ANALYSEWEEKS * sizeof(short));
			ret = true;
			break;
		}
		i++;
	}
	return ret;
}


//���û��ָ��������,Ӧ��ѡ����ӽ�������  todo1127
int GotoStopDateTime(int nDataLen,int nStopDate,int nStopTime,StockInfo *p5MinKData)
{
	//�޳���������Ч������	todo ���ַ����ٶ�λ��Ч����
	nDataLen--;
	int	nDiff,nSrcLen=nDataLen;
	int nLen=nDataLen/2,nLastLen=0;
	//p5MinKData[nLen].nYmd/2048>20 ������2004����ǰ������,���ش���
	if (p5MinKData[nLen].nYmd/2048>20)
	{
		nDataLen = -1;
		return nDataLen;
	}

	nDiff=DateDiff( p5MinKData[nLen].nYmd,nStopDate);

	do
	{
		if(nDiff>0)
		{
			nDataLen=nLen;
			nLen=max((nLastLen+nDataLen)/2,nLastLen);
		}
		else if(nDiff<0)
		{
			nLastLen=nLen;
			nLen=(nLen+ nDataLen )/2;
		}
		nDiff = DateDiff(p5MinKData[nLen].nYmd, nStopDate);
	}while ( nDataLen-nLen>1 && nDiff!=0);

	//������ֹ��ָ�����ڡ�ʱ��
	if(nDiff==0)
	{
		nDiff=TimeDiff(p5MinKData[nLen].nMin ,nStopTime);
		nDataLen=nLen;
		nLen=nLen-nDiff/5;
		if(nLen>0)
		{
			if(p5MinKData[nLen].nMin ==nStopTime)
				nDataLen=nLen;
			/*else
				nDataLen=-1;*/
		}
		/*else
			nDataLen=-1;*/
	}
	/*else
		nDataLen=-1;*/

	return 	  nDataLen;
}

int GotoStopDateTime(int nDataLen,int nStopDate,int nStopTime,StockInfo *pStockInfo,int nWeek)
{
	//�޳���������Ч������	todo ���ַ����ٶ�λ��Ч����
	nDataLen--;
	int	nDiff,nSrcLen=nDataLen;
	int nLen=nDataLen/2,nLastLen=0;
	do
	{
		nDiff = DateDiff((pStockInfo + nLen)->nYmd, nStopDate);
		if(nDiff>0)
		{
			nDataLen=nLen;
			nLen=max((nLastLen+nDataLen)/2,nLastLen);
			//nLen=nLen- nDateDiff*48;
		}
		else if(nDiff<0)
		{
			nLastLen=nLen;
			nLen=(nLen+ nDataLen )/2;
		}
		else
			break;
	}while ( nDataLen-nLen>1);

	//������ֹ��ָ�����ڡ�ʱ��
	if (nDiff == 0)
	{
		nDiff = TimeDiff((pStockInfo + nLen)->nMin, nStopTime);
		nLen = nLen - nDiff / nWeek;
		if (nLen >= 0)
		{
			if ((pStockInfo + nLen)->nMin == nStopTime)
				nDataLen = nLen;
			else
				nDataLen = -1;
		}
		else
			nDataLen = -1;
	}
	/*else if ((pStockInfo + nDataLen)->nYmd < nStopDate)
		nDataLen = -1;*/

	return 	  nDataLen;
}

int GotoStopDateTime(int nDataLen, int nStopDate, int nStopTime, tagRefStockInfo *pStockInfo, int nWeek)
{
	//�޳���������Ч������	todo ���ַ����ٶ�λ��Ч����
	nDataLen--;
	int	nDiff, nSrcLen = nDataLen;
	int nLen = nDataLen / 2, nLastLen = 0;
	do
	{
		nDiff =DateDiff( (pStockInfo + nLen)->nYmd, nStopDate);
		if (nDiff>0)
		{
			nDataLen = nLen;
			nLen = max((nLastLen + nDataLen) / 2, nLastLen);
			//nLen=nLen- nDateDiff*48;
		}
		else if (nDiff<0)
		{
			nLastLen = nLen;
			nLen = (nLen + nDataLen) / 2;
		}
		else
			break;
	} while (nDataLen - nLen>1);

	//������ֹ��ָ�����ڡ�ʱ��
	if (nDiff == 0)
	{
		nDiff = TimeDiff((pStockInfo + nLen)->nMin, nStopTime);
		nLen = nLen - nDiff / nWeek;
		
		if (nLen>=0)
		{
			if ((pStockInfo + nLen)->nMin == nStopTime)
				nDataLen = nLen;
			else
				nDataLen = 0;
		}
		else
			nDataLen =0;
	}
	else if((pStockInfo )->nYmd == nStopDate)
		nDataLen = 0;
	else
	{
		nDiff = DateDiff((pStockInfo + nLen)->nYmd, nStopDate);
		if( (nDiff>=0) || ((pStockInfo + nSrcLen)->nYmd> nStopDate) )
			nDataLen = nLen;
		else
			nDataLen = -1;
	}
		

	return 	  nDataLen;
}

//����ʷ�����ļ���ȡ5����K�������ļ���Ҫ��Ϣ
// ����5�����ļ�·�� E:\02soft\new_tdx\vipdoc\sh\fzline\sh000001.lc5
void Get5MinKFileInfo(string path,C5MinKFileInfo *usrFileInfo)
{
	FILE *fp;
	StockInfo usrTmp;

	fopen_s(&fp, path.c_str(), "rb");
	if (NULL != fp)
	{
		fread(&usrTmp, 32, 1, fp);
		usrFileInfo->nStartYmd = usrTmp.nYmd;
		usrFileInfo->nStartMin = usrTmp.nMin;
		fseek(fp, -32, SEEK_END);

		fread(&usrTmp, 32, 1, fp);
		usrFileInfo->nStopYmd = usrTmp.nYmd;
		usrFileInfo->nStopMin = usrTmp.nMin;
		usrFileInfo->lCount = ftell(fp);       //�ļ�����
		fclose(fp);
	}
	else
	{
		memset(usrFileInfo,0,sizeof(C5MinKFileInfo));
	}
}


//ָ�������İ�飬����300�����ռ���󣬷ּ�����etf��lof�����ֵ����
void SetBlockParameters(_TCHAR* argv)
{
	switch (*argv)
	{
	case '0':
		//ʵʱ��ض���
		ReadBLOCK(g_sRealMonitor, &g_usrBlock5MinKData);
		sprintf_s(g_usrAutoTrade.strBlock, "%s", "ʵʱ���");
		break;
	case  '1':
		//����300 ���
		ReadBLOCK(g_sHS300, &g_usrBlock5MinKData);
		sprintf_s(g_usrAutoTrade.strBlock,"%s", "����300");
		break;
	case '2':
		//����50 ���
		ReadBLOCK(g_sYS50, &g_usrBlock5MinKData);
		sprintf_s(g_usrAutoTrade.strBlock, "%s", "����50");
		break;
	case '3':
		//��С��
		ReadBLOCK(g_sZXB, &g_usrBlock5MinKData);
		sprintf_s(g_usrAutoTrade.strBlock, "%s", "��С��");
		break;
	case '4':
		//��ҵ��
		ReadBLOCK(g_sCYB, &g_usrBlock5MinKData);
		sprintf_s(g_usrAutoTrade.strBlock, "%s", "��ҵ��");
		break;
	case '5':
		//��С��
		ReadBLOCK(g_sZXC, &g_usrBlock5MinKData);
		sprintf_s(g_usrAutoTrade.strBlock, "%s", "��С��");
		break;

	case '6':
		//��ҵ��ͷ
		 ReadBLOCK(g_sHYLT, &g_usrBlock5MinKData);
		sprintf_s(g_usrAutoTrade.strBlock, "%s", "��ҵ��ͷ");
		break;
	case '7':
		//����100
		ReadBLOCK(g_sYQ100, &g_usrBlock5MinKData);
		sprintf_s(g_usrAutoTrade.strBlock, "%s", "����100");
		break;
	case '8':
		//��֤180  û�в�����ֵ��2012-2016û��һ�������ź�
		 ReadBLOCK(g_sSZ180, &g_usrBlock5MinKData);
		sprintf_s(g_usrAutoTrade.strBlock, "%s", "��֤180");
		break;
	case '9':
		//��������
		 ReadBLOCK(g_sDPLC, &g_usrBlock5MinKData);
		sprintf_s(g_usrAutoTrade.strBlock, "%s", "��������");
		break;
	case 'a':
	case 'A':
		//��ҵ300
		 ReadBLOCK(g_sCY300, &g_usrBlock5MinKData);
		sprintf_s(g_usrAutoTrade.strBlock, "%s", "��ҵ300");
		break;
	case 'b':
	case 'B':
		//ETF����
		ReadBLOCK(g_sETF, &g_usrBlock5MinKData);
		sprintf_s(g_usrAutoTrade.strBlock, "%s", "ETF����");
		break;
	case 'c':
	case 'C':
		//��С300
		 ReadBLOCK(g_sZX300, &g_usrBlock5MinKData);
		sprintf_s(g_usrAutoTrade.strBlock, "%s", "��С300");
		break;
	case 'd':
	case 'D':
		//����100
		ReadBLOCK(g_sZZ100, &g_usrBlock5MinKData);
		sprintf_s(g_usrAutoTrade.strBlock, "%s", "����100");
		break;
	case 'e':
	case 'E':
		//��֤300
		ReadBLOCK(g_sSZ300, &g_usrBlock5MinKData);
		sprintf_s(g_usrAutoTrade.strBlock, "%s", "��֤300");
		break;
	case 'f':
	case 'F':
		//��֤100
		ReadBLOCK(g_sZZ100, &g_usrBlock5MinKData);
		sprintf_s(g_usrAutoTrade.strBlock, "%s", "��֤100");
		break;
	case 'g':
	case 'G':
		//��֤300
		ReadBLOCK(g_sZZ300, &g_usrBlock5MinKData);
		sprintf_s(g_usrAutoTrade.strBlock, "%s", "��֤300");
		break;
	case 'z':
	case 'Z':
	default:
		CopyStock2Block();
		sprintf_s(g_usrAutoTrade.strBlock, "%s", "����ȫ��");
		break;
	};
}

int SetupParameters(int argc, _TCHAR* argv[],bool *Debug)
{	
	int nRet=3;//ȱʡ���㲽��δ15���ӣ�3��45��������
	*Debug=false;
	g_nWorkMode =  WORKMODE_DEFAULT;
	string sbuf;

	ReadSTBLOCK((char*)g_sSTBlock);

	switch (argc)
	{
		case 7:
		case 8:
		{
			//4����������ʼ����ʱ�䡢����ʱ��Ͳ������������Լ��Ƿ�SetDebugStockList
			g_nAnalyseStartDate = _wtoi(argv[1]);
			g_nAnalyseStartTime = _wtoi(argv[2]); //��ʼʱ��
			if ((g_nAnalyseStartTime >= 930 && g_nAnalyseStartTime <= 1130)
				|| (g_nAnalyseStartTime >= 1300 && g_nAnalyseStartTime <= 1500))
				g_nAnalyseStartTime = (g_nAnalyseStartTime / 100) * 60 + g_nAnalyseStartTime % 100;
			else
				g_nAnalyseStartTime = 900;

			g_nAnalyseStopDate = _wtoi(argv[3]);//��������

			g_nAnalyseStopTime = _wtoi(argv[4]); //����ʱ��
			g_nAnalyseStopTime = (g_nAnalyseStopTime / 100) * 60 + g_nAnalyseStopTime % 60;
			if ((g_nAnalyseStopTime >= 930 && g_nAnalyseStopTime <= 1130)
				|| (g_nAnalyseStopTime >= 1300 && g_nAnalyseStopTime <= 1500))
				g_nAnalyseStopTime = (g_nAnalyseStopTime / 100) * 60 + g_nAnalyseStopTime % 100;
			else
				g_nAnalyseStopTime = 900;

			g_nAnalyseStartDate = (g_nAnalyseStartDate / 10000 - 2004) * 2048 + (g_nAnalyseStartDate % 10000);
			g_nAnalyseStopDate = (g_nAnalyseStopDate / 10000 - 2004) * 2048 + (g_nAnalyseStopDate % 10000);

			//��ȡ����ģʽ
			nRet = _wtoi(argv[5]);

			switch (*argv[6])
			{
			case  'd':
			case 'D':
				*Debug = true;
				g_nWorkMode = WORKMODE_DEBUG;
				SetDebugStockList(&g_usrBlock5MinKData);
				break;
			case 'a':
			case 'A':
				//ѵ��ģʽ�����ض�ȡʱ������
				g_nWorkMode = WORKMODE_TRAINING;
				break;
			case 'r':
			case 'R':
				//ʵʱ����ģʽ
				g_nWorkMode = WORKMODE_REAL;
				//ָ��ͨ������ʷ��Ŀ¼����ʵʱģʽ�½�����ͨ������ʷ��Ŀ¼��Ϣ
				g_sTDXHisDataPath = g_sHisDataPathList[1];
				break;
			default:
				break;
			}

			break;
		}

		default:

			break;
	}

	//ָ�������İ��
	if(*Debug != true)
		SetBlockParameters(argv[7]);
	else
		sprintf_s(g_usrAutoTrade.strBlock, "%s", "����ģʽ");

	return  nRet;
}

//����ͨ���Ž������ģʽ�Ĵ���������
//�ڷ���ģʽ�£�ÿ�ε��ú�pfOUTָ����2�����ݵ�λ
void ResultOut(float **pfOUT,int nDataIndex,float fData)
{
	if(NULL!=*pfOUT)
		if(g_bAnalyseMode==true)
		{
			*(*pfOUT)++=(float)nDataIndex;
			*(*pfOUT)++=fData;
		}
		else
			(*pfOUT)[nDataIndex]=fData;
}



//get string from in between start and stop
char *GetItemFromStr(char *in,char *start,char *stop)
{
	char 	*tmp=NULL;

	tmp=strstr(in,start);
	if(NULL!=tmp)
	{
		tmp+=strlen(start);
		//tmp = strtok(tmp, stop);
		strtok_s(tmp,stop,&tmp);
	}

	return tmp;

}



//�������߳�ѡ�����Ľ��еױ��۷������ҳ�Ǳ�ڵ�BUY1STOCKNUMBERS��Ĳ�ִ�гֲ�
bool Buy1Cacl(int nStopDate, int nStopTime)
{
	char	filepath[250] = { 0 };
	string	tmp, sBuf, path;
	int	nCode, nDataLen,i;
	bool bRet = false;

	//���ֺ�����1��
	if (g_usrAutoTrade.HoldingFull() == true)
		return bRet;

	g_usrDayTrends.SortByDownRate();

	for (i = 0; i<g_usrDayTrends.nBuy1Count; i++)
	{
		StockInfo		*p5MinKData;
		long			nMaxLen;

		nCode = g_usrDayTrends.usrBuy1List[i].nCode;
		p5MinKData = g_usrBlock5MinKData.Get5MinKData(nCode,&nMaxLen);

		//5����K��������Ч������������һ��Ʊ
		if (NULL == p5MinKData)  continue;
		
		CNowTrends		usrNowTrends;
		StockInfo		*pNowKData=g_pusrNowKData;

		//��������ȡ��Ч��5����K������
		nDataLen = GotoStopDateTime(nMaxLen, nStopDate, nStopTime, p5MinKData) + 1;

		if (nDataLen >= g_nStockDownDays * 48)
		{
			p5MinKData += nDataLen - g_nStockDownDays * 48;
			nDataLen = g_nStockDownDays * 48;

			if (p5MinKData[nDataLen - 1].nYmd == nStopDate
				&& p5MinKData[nDataLen - 1].nMin == nStopTime)
			{
				bool bIsHolding = StockInTrade(&usrNowTrends, nCode);

				if (bIsHolding == false)
				{
					memset(&usrNowTrends, 0, sizeof(CNowTrends));
					usrNowTrends.nCurYmd = nStopDate;
					usrNowTrends.nCurMin = nStopTime;
					usrNowTrends.p5MinKData = p5MinKData;
					usrNowTrends.pNowKData = pNowKData;

					//��ʼ��CJD��������������
					memset(g_pusrCJD, 0, g_nCJDBufSize * sizeof(CJDInfo));
					memset(g_pusrCZSPZ, 0, g_nCZSPZBufSize * sizeof(CZSPZInfo));
					usrNowTrends.usrCJD = g_pusrCJD;
					usrNowTrends.usrCZSPZ = g_pusrCZSPZ;

					//һ��
					usrNowTrends.nCode = nCode;
					usrNowTrends.fCurClose = p5MinKData[nDataLen - 1].fClose;
					memcpy(usrNowTrends.nWeekList, g_usrDayTrends.usrBuy1List[i].nWeekList,
						ANALYSEWEEKS * sizeof(short));

					usrNowTrends.AnalyseStockData(nDataLen, bIsHolding);

					if (usrNowTrends.bBSChanged == true && usrNowTrends.nBuyIndex > 0)
					{
						g_usrDayTrends.usrBuy1List[i].bBSChanged = true;
						g_usrDayTrends.usrBuy1List[i].nBSIndex = usrNowTrends.nBuyIndex;
						memcpy(&g_usrDayTrends.usrBuy1List[i].usrBSPoint[0], &
							usrNowTrends.usrBuy[0], usrNowTrends.nBuyIndex * sizeof(BSInfo));

						bRet = true;
					}
				}
			}
		}
	}
	return  bRet;
}

//���ڵ���ʵʱ���ݽ��н��еױ��۷������ҳ�Ǳ�ڵ�BUY1STOCKNUMBERS��Ĳ�ִ�гֲ�
bool Buy1CaclReal(int nDataIndex, int nStopDate)
{
	char	filepath[250] = { 0 };
	string	tmp, sBuf, path;
	int		nCode, nMarket = 0;
	int     nDataLen = 0;
	int		nRealCount = TimeDiff(g_usrStockDateList[nDataIndex].nMin, 570) / 5;
	int     i;
	CNowTrends		usrNowTrends;
	StockInfo		*pNowKData=new StockInfo[g_nStockDownDays * 48 + 100];
	StockInfo		*p5MinKData;

	//���ֺ�����1��
	if (g_usrAutoTrade.HoldingFull() == true)
		return false;

	g_usrDayTrends.SortByDownRate();

	for (i = 0; i<g_usrDayTrends.nBuy1Count; i++)
	{
		long			nMaxLen;

		nCode = g_usrDayTrends.usrBuy1List[i].nCode;
		if (0 == nCode) continue;

		p5MinKData = g_usrBlock5MinKData.Get5MinKData(nCode, &nMaxLen);

		//5����K��������Ч������������һ��Ʊ
		if (NULL == p5MinKData)  continue;

		//��������ȡ��Ч��5����K������
		nDataLen = GotoStopDateTime(nMaxLen, nStopDate, 
			g_usrStockDateList[nDataIndex].nMin, p5MinKData) + 1;

		if (nDataLen >= g_nStockDownDays * 48)
		{
			p5MinKData += nDataLen - g_nStockDownDays * 48;
			nDataLen = g_nStockDownDays * 48;

			if (p5MinKData[nDataLen - 1].nYmd == nStopDate
					&& p5MinKData[nDataLen - 1].nMin == g_usrStockDateList[nDataIndex].nMin)
			{
				memset(&usrNowTrends, 0, sizeof(CNowTrends));
				g_usrAutoTrade.nCurDate = nStopDate;
				g_usrAutoTrade.nCurTime = g_usrStockDateList[nDataIndex].nMin;
				usrNowTrends.p5MinKData = p5MinKData;
				usrNowTrends.pNowKData = pNowKData;
				usrNowTrends.nCurMin = g_usrStockDateList[nDataIndex].nMin;
				usrNowTrends.nCurYmd = nStopDate;
				//��ʼ��CJD��������������
				memset(g_pusrCJD, 0, g_nCJDBufSize * sizeof(CJDInfo));
				memset(g_pusrCZSPZ, 0, g_nCZSPZBufSize * sizeof(CZSPZInfo));
				usrNowTrends.usrCJD = g_pusrCJD;
				usrNowTrends.usrCZSPZ = g_pusrCZSPZ;

				memcpy(usrNowTrends.nWeekList,
					g_usrDayTrends.usrBuy1List[i].nWeekList, ANALYSEWEEKS * sizeof(short));

				//һ��
				usrNowTrends.nCode = nCode;
				usrNowTrends.fCurClose = p5MinKData[nDataLen - 1].fClose;

				usrNowTrends.AnalyseStockData(nDataLen, false);

				if (usrNowTrends.bBSChanged == true && usrNowTrends.nBuyIndex > 0)
				{
					g_usrDayTrends.usrBuy1List[i].bBSChanged = true;
					g_usrDayTrends.usrBuy1List[i].nBSIndex = usrNowTrends.nBuyIndex;
					g_usrDayTrends.usrBuy1List[i].nLastetBuyYmd = usrNowTrends.nLatesBuyYmd;
					memcpy(&g_usrDayTrends.usrBuy1List[i].usrBSPoint[0], &
						usrNowTrends.usrBuy[0], usrNowTrends.nBuyIndex * sizeof(BSInfo));
				}
			}
		}
	}
	return  true;
}


//�Գֱֲ�Ľ���2��3�����������
bool Buy2SellxCacl(int nStopDate, int nStopTime)
{
	char	filepath[250] = { 0 };
	string	tmp, sBuf, path;
	int	 nCode, nDataLen;
	bool bRet = false;
	StockInfo		*p5MinKData;
	long			nMaxLen;
	CNowTrends		usrNowTrends;
	StockInfo		*pNowKData= g_pusrNowKData;

	for (int i = 0; i<MAXTRADENUMBER; i++)
	{
		nCode = g_usrAutoTrade.usrStockTrade[i].nCode;
		if (0 == nCode) continue;

		p5MinKData = g_usrBlock5MinKData.Get5MinKData(nCode,&nMaxLen);

		//5����K��������Ч������������һ��Ʊ
		if (NULL == p5MinKData)  continue;

		//��������ȡ��Ч��5����K������
		nDataLen = GotoStopDateTime(nMaxLen, nStopDate, nStopTime, p5MinKData) + 1;

		if (nDataLen >= g_nStockDownDays * 48)
		{
			p5MinKData += nDataLen - g_nStockDownDays * 48;
			nDataLen = g_nStockDownDays * 48;

			if (p5MinKData[nDataLen - 1].nYmd == nStopDate
				&& p5MinKData[nDataLen - 1].nMin == nStopTime)
			{
				CNowTrends  usrNowTrends;
				g_usrAutoTrade.usrStockTrade[i].nCurMin = nStopTime;
				g_usrAutoTrade.usrStockTrade[i].nCurYmd = nStopDate;
				g_usrAutoTrade.usrStockTrade[i].fCurClose = p5MinKData[nDataLen - 1].fClose;
				memcpy(&usrNowTrends, &g_usrAutoTrade.usrStockTrade[i], sizeof(CNowTrends));
				memcpy(&usrNowTrends.nWeekList[0], 
					g_usrAnalysePattern[g_nAnalysePat].nWeekList, ANALYSEWEEKS * sizeof(short));
				
				g_usrAutoTrade.nCurDate = nStopDate;
				g_usrAutoTrade.nCurTime = nStopTime;
				g_usrAutoTrade.nCurStockIndex = i;
				usrNowTrends.bBSChanged = false;
				usrNowTrends.p5MinKData = p5MinKData;
				usrNowTrends.pNowKData = pNowKData;
				//��ʼ��CJD��������������
				memset(g_pusrCJD, 0, g_nCJDBufSize * sizeof(CJDInfo));
				memset(g_pusrCZSPZ, 0, g_nCZSPZBufSize * sizeof(CZSPZInfo));
				usrNowTrends.usrCJD = g_pusrCJD;
				usrNowTrends.usrCZSPZ = g_pusrCZSPZ;

				//��������
				usrNowTrends.nCode = nCode;
				memcpy(usrNowTrends.nWeekList, 
					g_usrAnalysePattern[g_nAnalysePat].nWeekList, ANALYSEWEEKS * sizeof(short));

				usrNowTrends.AnalyseStockData(nDataLen, true);
				if (usrNowTrends.bBSChanged == true)
				{
					memcpy(&g_usrAutoTrade.usrStockTrade[i], &usrNowTrends, sizeof(CNowTrends));
					bRet = true;
				}
			}
		}
	}
	return  bRet;
}

//�Գֱֲ�Ľ���2��3�����������  ʵʱ����
//��δ�ֱֲ��ͬ������2��3�������Ҫ
//���ۺ���2��3��������3�����ж�ԭ��һ�£�
//���������ڵױ��۵ĵ׷��ͺ����һ�����������ص������μ���ĵױ��۶����ɵ����
bool Buy2SellxCaclReal(int nStopDate, int nStopTime)
{
	char	filepath[250] = { 0 };
	string	tmp, sBuf, path;
	int	nCode;
	int    nRealCount = TimeDiff(nStopTime, 570) / 5;
	StockInfo  *p5MinKData, 
		*pNowKData=new StockInfo[g_nStockDownDays * 48 + 100];
	long			nMaxLen;
	CNowTrends  usrNowTrends;

	for (int i = 0; i<MAXTRADENUMBER; i++)
	{
		nCode = g_usrAutoTrade.usrStockTrade[i].nCode;
		if (nCode == 0)
			continue;

		
		if (StockInTrade(&usrNowTrends, nCode) == false)
			continue;

		p5MinKData = g_usrBlock5MinKData.Get5MinKData(nCode, &nMaxLen);

		if (NULL==p5MinKData)
			continue;

		int		nDataLen = 0;

		//��������ȡ��Ч��5����K������
		nDataLen = GotoStopDateTime(nMaxLen, nStopDate, nStopTime, p5MinKData) + 1;

		if (nDataLen >= g_nStockDownDays * 48)
		{
			p5MinKData += nDataLen - g_nStockDownDays * 48;
			nDataLen = g_nStockDownDays * 48;

			if (p5MinKData[nDataLen - 1].nYmd == nStopDate
				&& p5MinKData[nDataLen - 1].nMin == nStopTime)
			{
				g_usrAutoTrade.usrStockTrade[i].fCurClose = p5MinKData[nDataLen - 1].fClose;
				memcpy(&usrNowTrends, &g_usrAutoTrade.usrStockTrade[i], sizeof(CNowTrends));
				memcpy(&usrNowTrends.nWeekList[0], 
					&g_usrAnalysePattern[g_nAnalysePat].nWeekList, ANALYSEWEEKS * sizeof(short));

				g_usrAutoTrade.nCurStockIndex = i;
				usrNowTrends.bBSChanged = false;
				usrNowTrends.p5MinKData = p5MinKData;
				usrNowTrends.pNowKData = pNowKData;
				usrNowTrends.nCurMin = nStopTime;
				usrNowTrends.nCurYmd = nStopDate;
				usrNowTrends.nLatesBuyYmd= g_usrDayTrends.usrBuy1List[i].nLastetBuyYmd;

				//��ʼ��CJD��������������
				memset(g_pusrCJD, 0, g_nCJDBufSize * sizeof(CJDInfo));
				memset(g_pusrCZSPZ, 0, g_nCZSPZBufSize * sizeof(CZSPZInfo));
				usrNowTrends.usrCJD = g_pusrCJD;
				usrNowTrends.usrCZSPZ = g_pusrCZSPZ;


				//����
				usrNowTrends.nCode = nCode;
				usrNowTrends.AnalyseStockData(nDataLen, true);
				if (usrNowTrends.bBSChanged == true)
				{
					memcpy(&g_usrAutoTrade.usrStockTrade[i], &usrNowTrends, sizeof(CNowTrends));
				}
			}
		}
	}
	return  true;
}


//�Ƿ��ʽ��ע����
bool IsFocusing(StockInfo * pDayKData,int nDataLen,CNowTrends *ptrCNow)
{
	bool bRet = true;
	int nShort = 5, nMid = 10, nLong =120,nContinueUp=3;
	int  nLen = nLong + nContinueUp*5;
	
	/*  �ʽ��ע�жϹ���
	    1��nDataLen����С��nMid��3��
		2���������nContinueUp�����ն��г��ɽ������ڶ�ͷ���У������״γ���
		3�����г��ɽ���������������״̬
	*/
	if (nDataLen > nLen)
	{
		int i;
		float fRate = 1.5; //���߾��ߴ��ڳ��ߵı���
		
		long *lShort = new long[nLen], *lMid = new long[nLen], *lLong = new long[nLen];
		ptrCNow->MAVOL(nLen, pDayKData+nDataLen-nLen, nShort, nMid, nLong, lShort, lMid, lLong);

		for (i = nLen - 1; bRet==true && i >= nLen - 1 - nContinueUp; i--)
		{
			bRet = (lShort[i] > lLong[i] * fRate);
		}

		//nContinueUp+1��ǰ���Ƕ�ͷ����
		if(bRet==true)
			bRet  =!(lShort[i] > lLong[i] * fRate);
	}
	else
		bRet = false;

	return bRet;
}

//RSI�Ƿ���ʾ����
bool IsRSIBuy(StockInfo * pDayKData, int nDataLen, CNowTrends *ptrCNow)
{
	bool bRet = true;


	return bRet;
}

//RSI�Ƿ���ʾӦ��
bool IsRSISell(StockInfo * pDayKData, int nDataLen, CNowTrends *ptrCNow)
{
	bool bRet = true;


	return bRet;
}

//ATR�Ƿ���ʾ����
bool IsATRBuy(StockInfo * pDayKData, int nDataLen, CNowTrends *ptrCNow)
{
	bool bRet = true;


	return bRet;
}

//ATR�Ƿ���ʾӦ��
bool IsATRSell(StockInfo * pDayKData, int nDataLen, CNowTrends *ptrCNow)
{
	bool bRet = true;


	return bRet;
}


