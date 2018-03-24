// 缠分析.cpp : 定义控制台应用程序的入口点。
/*
20170606 考虑增加一些蚂蚁量化的评价方法：资金热点，个股强弱指标，真实平均波动指标
一、量化市场因子
量化者首先该问自己，对于中国股市，你量化的方向是什么？ 价值投资还是市场投机？大数据说话，上市10年以上的中国A股股票，都经历过至少两次以上的跌幅大于50%的下跌，近一半的股票经历过6次及以上超过50%的下跌。每次下跌超过50%的过程中，有几个人有实力和胆量能继续持股？有几个持股人能坚信自己拿着的股票将来就是贵州茅台？ 连贵州茅台都有两次超过50%的跌幅！
中国股市波动幅度之巨大和频繁，价值投资者还幸存了几个？ 但给了投机者巨大的机会，因为每次下跌超过50%的后面，都会有巨大的涨幅。
中国A股市场更适合投机，那么量化的对象因子是价值相关还是市场相关？ 答案已经不言而喻！  再看看量化投资巨匠詹姆斯·西蒙斯（James Simons）， 他管理的文艺复兴基金，开始时量化因子包括很多基本面参数，业绩平平，后来抛弃了这些，专注市场因子，结果收益提高了一个数量级。所以，我更确信，对于中国股市，量化的方向是量化市场投机因素。
二、技术分析手段
量化就是技术分析吗？ 误耶！技术分析只是测量工具，市场分析才是王道，技术分析是给市场分析打工的，脱离市场分析的技术分析是又苦又累、朝不保夕、还倒贴钱的矿工活儿。
我所认为的市场因素包括那些，对应的常用技术测量工具（指标）是哪些：
1）整体市场方向---技术工具：均线、成交量
2）资金热点去向---技术工具：成交金额，区间金额堆积和变化
3）个股偏强偏弱---技术工具：相对强弱指标ＲＳＩ
4）个股波动幅度---技术工具：真实波动幅度均值（ATR）
三、核心资金流
市场最重要因素：资金流动
判断资金的热点去向，几乎占策略比重的一半。再多的兵力，如果投到一个错误的战场开战，真正的主战场却没有你的主力，这个战役你能赢吗？所以，再次强调，跟踪资金热点去向，到主战场上去。
四、控制资金回撤
覆巢之下，岂有完卵！　能穿越牛熊的股票太少了，连贵州茅台都有两次超过50%的跌幅，你能撑得住吗？　我的策略就是，保本最重要，大盘不好，跑出来看看，个股不好，撤退一些看看，大盘个股都不好，赶紧跑！

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
#include "缠分析.h"

//检测指定文件是否存在
bool IsFileExist(char* strFile)
{
	struct stat my_stat;
	return (stat(strFile, &my_stat) == 0);
}
//获取指定文件大小
long GetFileSize(char* strFile)
{
	struct stat my_stat;
	stat(strFile, &my_stat);
	return my_stat.st_size;
}


//读取通达信导出的权息文件,获取以10股为单位的送转股/分红/配股和配股价/流通盘变动信息,每段之间用0x09做间隔
//数据段之间通过0x09分隔,连续出现0x09表明部分字段缺失,数据记录之间的分隔符0x0d,0x0a
//通达信导出两个权息文件:当年权息.txt最近一年权息变化,当日权息.txt当日权息变化 本周权息.txt本周将发生的权息变化
//nDataLen 指向待分析数据,包含时间信息
//300381	溢多利	     20161018	20.00	1.000
//002456	欧菲光	     20161202                    - 5.0	102797.9
//300547	川环科技	 20161202		10.000
//仅处理分析周期内的全息变动信息
// todo 0103 代码待完善,取分红扩股是异常 
int	ReadQX(int nDataLen)
{
	FILE	*fp;
	string  sBuf, tmp;
	char buf[300];
	//大于g_usrHis5KFileInfo.nStopYmd才需要关注
	int		nValidQuanXiDate =g_usrHis5KFileInfo.nStopYmd; //nValidQuanXiDate  已有权息截止日期
	int i = 0, j, nQuanXiCount = 256, nQuanXiIndex = 1;
	bool  bQuanxiValid = false;
	long lFp;

	sprintf_s(buf, "%s*权息.txt", g_sQuanxiPath);
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
				//最后一行信息会读两次,原因不明,在代码中进行判断,不保留完全相同的权息记录
				fgets(buf, 256, fp);
				sBuf = buf;

				j = sBuf.find(9, 0);
				tmp = sBuf.substr(0, j);
				sBuf = sBuf.substr(j + 1, sBuf.length() - j - 1);

				// 读取股票代码
				g_pStockQuanXi[i].nCode = atoi(tmp.c_str());

				//跳过股票名称
				j = sBuf.find(9, 0);
				sBuf = sBuf.substr(j + 1, sBuf.length() - j - 1);


				//读取日期信息
				j = sBuf.find(9, 0);
				tmp = sBuf.substr(0, j);
				sBuf = sBuf.substr(j + 1, sBuf.length() - j - 1);
				int  nTmp = atoi(tmp.c_str());
				//权息变化的日期必须在分析的周期内
				g_pStockQuanXi[i].nDate = nTmp % 10000 + (nTmp / 10000 - 2004) * 2048;

				if (g_pStockQuanXi[i].nDate <= g_usrHis5KFileInfo.nStopYmd)
					break;

				//读取送转股信息
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


				//读取分红股信息
				j = sBuf.find(9, 0);
				if (j > 0)
				{
					bQuanxiValid = true;
					tmp = sBuf.substr(0, j);
					g_pStockQuanXi[i].fGain = atof(tmp.c_str()) / 10;
				}

				sBuf = sBuf.substr(j + 1, sBuf.length() - j - 1);

				//读取配股信息
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

						//读取配股股价信息
						g_pStockQuanXi[i].fBuyPrice = atof(sBuf.c_str());
						bQuanxiValid = true;
					}
				}

				//流通盘变化不处理

				if (bQuanxiValid == false)
					memset(&g_pStockQuanXi[i], 0, sizeof(StockQuanXi));
				else
				{
					//剔除重复的权息项目
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

//前复权后的价格
void	CaclQuanXiPrice(float fGiven, float fGain, float fBuyCount, float fBuyPrice, float *fPrice)
{
	*fPrice = (*fPrice - fGain + fBuyCount*fBuyPrice) / (1 + fGiven + fBuyCount);
}

//检查指定股票nCode在分析周期nStopDate内是否有权息变动,如有变动返回true
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

//检查指定股票nCode否有权息变动,如有变动返回true
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

//把需要调试的股票代码转成特殊的板块进行计算
//上海股票加上1000000
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


//对指定的股票代码序列进行潜在买点（123）买分析
//int blkList板块股票代码序列
void DetectBlockBuySignal(CStockBlockInfo *ptrBlockInfo, int nStopDate, int nStopTime)
	{
		int i = 0;

		//使用空闲的float数组进行计算
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
		sprintf_s(sbuf,"股票代码,周期,日期,时间,BS模式,BS类型,离当前周期数据,MACD,DIF");
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

			/*sprintf_s(sbuf, "日期,时间,代码,跌幅,连续收缩天数");
			LogFile(g_sOneBuy, sbuf);*/
			//todo 做记录	 代码,日期,时间,买量,成交额,手续费,当前现金,买入价,止损价,止盈价
			sprintf_s(g_sBSLog, "%s%s-%s-%d-%d-BS-%d min.txt", g_sTradePath, 
				g_usrAutoTrade.strBlock, g_usrAnalysePattern[g_nAnalysePat].sName,
				nDate, (nTime) / 100, nStep * 5);
		}

		if (IsFileExist(g_sHolding) == false)
		{
			sprintf_s(sbuf, "日期,时间,代码,买量,均价,收盘,市值,收益率,现金");
			int i = 0;
			while (g_sRefName[i].length()>0)
			{
				sprintf_s(sbuf, "%s,%s", sbuf, g_sRefName[i++].c_str());
			}
			LogFile(g_sHolding, sbuf);
		}

		if (IsFileExist(g_sBSLog) == false)
		{
			sprintf_s(sbuf, "代码,日期,时间,分析周期,BS处涨跌比,买量,成交额,手续费,类型,模式,最大持仓周期,成交价,止损价/均价,止盈价/盈亏比");
			LogFile(g_sBSLog, sbuf);
		}

	}

	//选股择时算法训练，通过历史数据形成模型
	//本函数设计成可扩充，通过增加不同的算法函数指针即可运行对应的学习模式 todo 20170210
	void Training(int nStopDate, int nStopTime, int nStep)
	{
		string sTmp;
		int  nLastDate = -1, j = 0;
		int  nCurDate, nCurTime;
		char	filepath[250] = { 0 };
		string	tmp, sBuf;
		int nDate, nTime;

		//验证算法或者实盘监控模式
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

			printf("\n 分析-%s-%s》日期：%d,时间：%d\n",
				g_usrAnalysePattern[g_nAnalysePat].sName,g_usrAutoTrade.strBlock,nDate,nTime);

			if (nLastDate != nCurDate)
			{
				//以天未单位计算1买机会
				nLastDate = nCurDate;

				memset(&g_usrDayTrends, 0, sizeof(CDayTrends));
				g_usrDayTrends.usrBuy1List[0].bDown = true;
				DetectBlockBuySignal(&g_usrBlock5MinKData, nCurDate, nCurTime);
			}
			

			//策略优化分析
			if (Buy1Cacl(nCurDate, nCurTime) == true)
				g_usrAutoTrade.DoBuy();

			if (Buy2SellxCacl(nCurDate, nCurTime) == true)
			{
				g_usrAutoTrade.Do2xBuy();
				g_usrAutoTrade.DoSell();
			}
				
			//仅输出买卖信息,不保存g_usrAutoTrade结构
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
	sprintf_s(sbuf1, "开始分析  日期:%d 时间：%06d",  nDate, nTime);
	LogFile("trade\\readlog.txt", sbuf1);

	//训练模式：从头开始读取历史数据，前g_nStockDownDays的数据无效，必须跳过
	if (   g_nWorkMode != WORKMODE_REAL)
	{
		//训练模式下,g_nAnalyseStopDate表示终止分析的日期
		Training(g_nAnalyseStopDate, 900, nStep);
	}
	else
		RealMonitor(nStep);

	GetCurrentDateTime(&nDate, &nTime);
	sprintf_s(sbuf1, "结束分析  日期:%d 时间：%d", nDate, nTime);
	LogFile("trade\\readlog.txt", sbuf1);

	if (NULL!= g_usrStockDateList)
		delete g_usrStockDateList;
}

	//实时监控
	int RealMonitor(int	nStep)
	{
		char sbuf[250] = { 0 };
		string sbuf1;
		int	nStopDate, nStopTime;
		int nLastDate = -1;

		ReadDateList4Real(g_nAnalyseStopDate);

		//验证算法或者实盘监控模式
		WriteLogHead(nStep);

		//从开始交易的时间起算
		int  j = 0;

		ReadTradeInfo();
		g_usrAutoTrade.bChanged = false;

		//指向已计算过的时间	

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
			g_sMailTitle = "BS提醒";

			nStopDate = g_usrStockDateList[j].nYmd;
			nStopTime = g_usrStockDateList[j].nMin;
			g_usrAutoTrade.nCurDate = g_usrStockDateList[j].nYmd;
			g_usrAutoTrade.nCurTime = g_usrStockDateList[j].nMin;
			
			printf("\n 实时-%s-%s》日期：%d,时间：%d\n",
				g_usrAnalysePattern[g_nAnalysePat].sName,g_usrAutoTrade.strBlock,
				(nStopDate / 2048 + 104) * 10000 + nStopDate % 2048,
				(nStopTime / 60) * 100 + nStopTime % 60);

			//20170318改为每个分析周期均判断，防止错失买入时机
			if (nLastDate != nStopDate)
			{
				nLastDate = nStopDate;
				memset(g_usrDayTrends.usrBuy1List, 0, BUY1STOCKNUMBERS * sizeof(DayTrends));
				g_usrDayTrends.usrBuy1List[0].bDown = true;
				g_usrDayTrends.nBuy1Count = 0;
				DetectBlockBuySignal(&g_usrBlock5MinKData, nStopDate, nStopTime);
				
			}

			//实时分析:实时监控模式
			if (Buy1CaclReal(j, nStopDate) == true)
				g_usrAutoTrade.DoBuy();

			if (Buy2SellxCaclReal(nStopDate, nStopTime) == true)
			{
				g_usrAutoTrade.Do2xBuy();
				g_usrAutoTrade.DoSell();
			}

			//仅输出买卖信息,不保存g_usrAutoTrade结构
			SaveTradeInfo(j);
		}

		//仅在当前分析周期发送交易提醒信息
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
//初始化应用程序参数
void	InitApp()
{
	memset(&g_usrDayTrends.usrBuy1List,0,sizeof(DayTrends)*BUY1STOCKNUMBERS);
	memset(&g_usrAutoTrade, 0, sizeof(CAutoTrade));

	//获取5分钟K线数据文件信息
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

//对板块内的股票进行分析，找出具有买入价值的标的，保留最大的前BUY1STOCKNUMBERS项
//不区分是否持仓，统一进行排序分析
bool FindUppingStock(CStockBlockInfo *ptrBlockInfo,int nStockIndex, int nStopDate, int nStopTime)
{
	char	filepath[250] = { 0 };
	string	tmp, sBuf;
	int	nMaxLen;
	
	int kk = 0, nDataLen = 0;
	//持仓标的不作判断
	if (g_usrAutoTrade.StockInList(ptrBlockInfo->usr5MinKDataInfo[nStockIndex].nCode,NULL))
		return  false;

	Stock5MinKData *ptr5MinKData=&ptrBlockInfo->usr5MinKDataInfo[nStockIndex];

	//判断当前标的是否有分析价值
	StockInfo *p5MinKData=ptr5MinKData->usrKData, 
		*pNowKData= g_pusrNowKData;

	//没有K线数据直接返回false
	if (NULL== p5MinKData || p5MinKData->nYmd == 0) return false;

	int nCode = ptr5MinKData->nCode;
	int nMarket=0;
	CNowTrends  usrNowTrends;

	nMaxLen = ptr5MinKData->lCount;

	//从数组中取有效的5分钟K线数据
	nDataLen = GotoStopDateTime(nMaxLen, nStopDate, nStopTime, p5MinKData)+1;

	usrNowTrends.p5MinKData = p5MinKData;
	usrNowTrends.pNowKData = g_pusrNowKData;
	usrNowTrends.n5MinKDataLen = nDataLen;
	usrNowTrends.nCode = nCode;

	if (nDataLen >= g_nStockDownDays * 48 
		&& p5MinKData[nDataLen - 1].nNumber > 0 //剔除当日停牌标的
		&& usrNowTrends.CheckRuler(m_pRulerFunction)==true)    //其他新加规则处理
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

			//初始化CJD和中枢盘整缓冲
			memset(g_pusrCJD, 0, g_nCJDBufSize * sizeof(CJDInfo));
			memset(g_pusrCZSPZ, 0, g_nCZSPZBufSize * sizeof(CZSPZInfo));
			usrNowTrends.usrCJD = g_pusrCJD;
			usrNowTrends.usrCZSPZ = g_pusrCZSPZ;

			usrNowTrends.SetLastDateDayClose(nDataLen, usrNowTrends.p5MinKData);
			//当前分析时涨停或跌停不做处理
			if (usrNowTrends.UpStop(nDataLen, usrNowTrends.p5MinKData)
				|| usrNowTrends.DownStop(nDataLen, usrNowTrends.p5MinKData))
				return false;

			usrNowTrends.fMALong = ptrBlockInfo->fMALong;
			usrNowTrends.fMAMid = ptrBlockInfo->fMAMid;
			usrNowTrends.fMAShort = ptrBlockInfo->fMAShort;

			//获取5分钟级别的最大最小值
			usrNowTrends.pNowKData = p5MinKData;
			usrNowTrends.SetMaxHighMinLow(nDataLen);
			usrNowTrends.pNowKData = pNowKData;
			usrNowTrends.fCurClose = p5MinKData[nDataLen-1].fClose;

			//初始化CJD和中枢盘整缓冲
			memset(g_pusrCJD,0,g_nCJDBufSize*sizeof(CJDInfo));
			memset(g_pusrCZSPZ, 0, g_nCZSPZBufSize * sizeof(CZSPZInfo));
			usrNowTrends.usrCJD = g_pusrCJD;
			usrNowTrends.usrCZSPZ = g_pusrCZSPZ;
			return usrNowTrends.IsUp4Buy(nDataLen, p5MinKData);
		}
	}

	return false;
}

//沪深股票的全部代码并保存在g_nBlockList供快速分析使用
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

	//找出当前沪深全部交易的股票代码
	for (int nMarket = 0; nMarket < 2; nMarket++)
	{
		string sTmp = g_sTDXPath;
		sTmp.append(g_sMinute5[nMarket]);
		lFp = _findfirst(sTmp.c_str(), &file);
		
		if (lFp != -1l)
		{
			//判断当前标的是否有分析价值
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


//读取5分钟K线数据,包括历史数据(从威盛投资下载的除权后历史5分钟数据,截止2016年12月底)
//path 历史数据文件名 ,nCode股票代码（备用）, 数据指针*pStockMinuteInfo，nMaxSize表示pStockMinuteInfo大小
//nStart5MinPlace历史数据开始记录，表示从第nStart5MinPlace个5分钟数据记录开始读取数据，0时表示从文件头开始读取数据
//历史数据截止日期时间nStopDate/nStopTime，如果超过nMaxSize,分批次读取与处理todo 20170210
//返回实际读取的5分钟数据项数,结果存在pStockMinuteInfo
int  ReadHis5MinKData4Real(string path, int nCode, StockInfo *pStockMinuteInfo, int nMaxSize,
	long nStart5MinPlace, int nStopDate, int nStopTime)
{
	int		nDataLen = 0;//当前有效数据记录数
	FILE	*fp;

	if (   NULL == pStockMinuteInfo 
		|| nStopDate>=g_usrHis5KFileInfo.nStopYmd
		|| IsSTStock(nCode)==true)  //ST板块的代码不做处理
		return -1;
	
	fopen_s(&fp, path.c_str(), "rb");

	if (fp != NULL)
	{
		fseek(fp, 0, SEEK_END);
		//从指定的记录项开始读取数据
		fseek(fp, nStart5MinPlace*32, SEEK_SET);
		nDataLen = fread(pStockMinuteInfo, 32, nMaxSize, fp);
		fclose(fp);
	}
	
	return nDataLen;
}

//读取5分钟K线数据,包括历史数据(从威盛投资下载的除权后历史5分钟数据,截止2016年12月底)/通达信软件当前下载的数据,
//根据分析的时段进行权息处理后合并到全局数组便于后续处理
//先读取通达信软件目录的5分钟数据,然后补读历史数据
//string HisPath,string TdxPath,string FileName文件名, StockInfo *pStockMinuteInfo nMaxSize表示pStockMinuteInfo大小
//nReadDays 拟读取nStopDate/nStopTime 前最新交易日的5分钟K线数据
//返回实际读取的5分钟数据项数,结果存在pStockMinuteInfo
int  Read5MinKData4Training(string path, string HisPath, 
	int nCode, StockInfo *pStockMinuteInfo, int nMaxSize,
	int nReadDays, int nStopDate, int nStopTime)
{
	char	filepath[250] = { 0 };
	int		nDataLen = 0;//当前有效数据记录数
	int		j, i;
	string	tmp, sBuf;
	long	lFp = -1;
	char	sbuf[250];
	FILE	*fp;
	bool	bMoveData = true;
	int		nRealCount = 0;//实时数据项
	int		nReadCount = 0;

	/* 根据nStopDate/nStopTime在历史数据/通达信数据/实时数据的关系读取5分钟K线数据
	数据从缓冲区末端开始装入,最后统一移到pStockMinuteInfo开始处
	大于通达信数据时:先读取实时数据
	大于历史数据时:线先读取通达信数据
	小于通达信数据时:仅读取历史数据
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

	//读取历史5分钟K线数据
	if (   g_nAnalyseStartDate >=g_usrHis5KFileInfo.nStartYmd
		&& g_nAnalyseStartDate <=g_usrHis5KFileInfo.nStopYmd)
	{
		// 典型通达信5分钟文件路径 E:\02soft\new_tdx\vipdoc\sh\fzline\sh000001.lc5
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
			//单独读取历史数据
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
						nDataLen = j +1;  //数据不足,保留全部最新数据
					}
				}
			}
			else
			{
				//判断数据有效性:如果nStopDate大于pStockMinuteInfo[nDataLen - 1].nYmd,表明没有该时段的数据,取其最新的数据替代
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
					//截止时间小于终止时间表明没有可用数据
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


//仅读取通达信软件目录的5分钟数据和实时5分钟K线数据
//path 指向K线文件的目录,nCode 代码, StockInfo *pStockMinuteInfo nMaxSize表示pStockMinuteInfo大小
//nReadDays 拟读取nStopDate/nStopTime 前最新交易日的5分钟K线数据
//返回实际读取的5分钟数据项数,结果存在pStockMinuteInfo
int  Read5MinKData4Real(string path, int nCode, 
	               StockInfo *pStockMinuteInfo, int nMaxSize,
	               int nReadDays,int nStopDate,int nStopTime)
{
	_finddata_t file;
	char	filepath[250] = { 0 };
	int		nDataLen = 0;//当前有效数据记录数
	int		j,i;
	string	tmp, sBuf;
	long	lFp = -1;
	char	sbuf[250];
	FILE	*fp;
	bool	bMoveData = true;
	int		nRealCount = 0;//实时数据项
	int		nReadCount = 0;

	/* 根据nStopDate/nStopTime在通达信数据/实时数据的关系读取5分钟K线数据
	   数据从缓冲区末端开始装入,最后统一移到pStockMinuteInfo开始处
		先读取通达信数据读，然后取实时数据
	*/

	if (NULL == pStockMinuteInfo) return -1;
	
	j = path.find("*.lc5", 0);
	if (j > 0)
	{
		path = path.substr(0, j);
		sprintf_s(sbuf, "*%06d.lc5", nCode);
		path.append(sbuf);
	}

	//读取实时和通达信5分钟K线数据
	{
		lFp = _findfirst(path.c_str(), &file);
		if (lFp != -1l)
		{
			// 读取最新的  nReadDays天的5分钟数据,min( nReadDays ,MAX5KS)防止指针溢出
			int nReadLen = min(nReadDays * 48, nMaxSize) * 32;
			
			sBuf = path.substr(0, path.find_last_of("\\") + 1);
			sBuf.append(file.name);
			fopen_s(&fp, sBuf.c_str(), "rb");

			if (NULL != fp)
			{
				//防止数据溢出
				i = file.size / 32;

				//历史文件数据项目多于需要数据项,读取最新的nReadLen即可
				{
					fseek(fp, -nReadLen, SEEK_END);
					if (nMaxSize - nDataLen - nReadLen/32 < 0)
						//缓冲区太小,无法读数据
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

		//读取当日5分钟实时K线数据
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

	//数据有效性判断
	{
		//data valid,数据结束位置
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
				//数据不足,保留全部最新数据 
				//停牌后复牌导致数据不连续  考虑重新读取数据TODO 20170320
				nDataLen = j + 1;  
			}
		}
		else
		{
			//判断数据有效性:如果nStopDate大于pStockMinuteInfo[nDataLen - 1].nYmd,表明没有该时段的数据,取其最新的数据替代
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
				//截止时间小于终止时间表明没有可用数据
			{
				return -1;
			}
		}
	}

	_fcloseall();
	return nDataLen;
}

//读取5分钟实时K线数据
// path 当前读取的5分钟历史数据文件路径,usrTmp实时数据存储开始位置
int  ReadReal5MinKData(WORKMODE nReal,string path, StockInfo *usrTmp,int nReadCount)
{
	//读取当日的5分钟数据,直接附加在历史数据后面
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
//基于深证综指5分钟离线数据读取交易日序列
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

	//g_sRefIndex[i] 格式 "sz\\fzline\\sz399006.lc5"
	g_nMaxStockDateListCount = nOldDataCount+ Read5MinKData4Real(path,
		atoi((g_sRefIndex[i]).substr(12, 6).c_str()), p5MinKData+ nOldDataCount, 
		lSize+48,  nDays+1, nNowDate, 900);

	usrTmp = p5MinKData;
	j=0;
	g_usrStockDateList[0].nIndex[0] = 1.0;//防止出现被零除异常

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
		g_usrStockDateList[0].nIndex[i] = 1.0;//防止出现被零除异常

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

		//g_sRefIndex[i] 格式 "sz\\fzline\\sz399006.lc5"
		g_nMaxStockDateListCount = nOldDataCount+ Read5MinKData4Real(path,
			atoi((g_sRefIndex[i]).substr(12, 6).c_str()), p5MinKData+ nOldDataCount,
			lSize, nDays, nNowDate, 900);

		j=0;
		usrTmp = p5MinKData;
		//将来完善不同指数间数据对准问题   todo 1107
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

//基于深证综指5分钟离线数据读取交易日序列  用于算法优化完善
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
	//g_sRefIndex[i] 格式 "sz\\fzline\\sz399006.lc5"
	g_nMaxStockDateListCount = Read5MinKData4Training(path, g_sTDXHisDataPath,
		atoi((g_sRefIndex[i]).substr(12, 6).c_str()), p5MinKData, 
		lSize, lSize / 48, nStopDate, nStopTime);

	usrTmp = p5MinKData;

	for (j = 0; j < 7; j++)
	{
		g_usrStockDateList[0].nIndex[j] = 1;//防止出现被零除异常
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
		g_usrStockDateList[0].nIndex[i] = 1.0;//防止出现被零除异常
		path = g_sTDXPath;
		path.append((g_sRefIndex[i]).substr(0, 10));
		path.append("*.lc5");

		//g_sRefIndex[i] 格式 "sz\\fzline\\sz399006.lc5"
		j = Read5MinKData4Training(path, g_sTDXHisDataPath,
			atoi((g_sRefIndex[i]).substr(12, 6).c_str()), p5MinKData,
			lSize, lSize / 48, nStopDate, nStopTime);

		j = 0;
		usrTmp = p5MinKData;
		//将来完善不同指数间数据对准问题   todo 1107
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

//生成通达信压缩格式的日期格式,入口参数为1170101,7位数的日期格式,前三位压缩的年代码
int CreateStockDate(int nDate)
{
   return  (nDate/10000-104)*2048 + nDate%10000;
}
//生成通达信压缩格式的日期格式,入口参数为20170101,8位数的日期格式,前4位年代码
int CreateStockDateByGeneralDate(int nDate)
{
	return  (nDate / 10000 - 2004) * 2048 + nDate % 10000;
}

int CreateStockTime(int nTime)
{
	return  (nTime/100)*60+nTime%100;
}

//保存二进制格式的买卖点数据
//买卖点数据格式：代码,日期,时间,分析周期，买量,成交额,手续费,类型,模式,最大持仓周期,买入价,止损价,止盈价
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


//将当前持仓情况保存到文件
//nDateIndex  当前分析的时间序号,用于取出对比时间
//nDateIndex==-1  表明计算结束，缓存存入文件
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

	//当前日期
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
			if((ptrBuySell+j)->nAmount >0 )	 //处理目前持仓的标的
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

			//取当前交易时间
			pTrends->GetCurDateTime (&nDate,&nTime);

			//记录当前日期、时间、持股代码、数量、均价、当前收盘价、市值、涨跌比率和现金
			sprintf_s(sbuf,"%07d,%4d,%07d,%04d,%04.2f,%04.2f,%04.2f,%03d,%04.2f\n",
				(nDate/2048+104)*10000+nDate%2048 ,
				(nTime/60)*100+nTime%60,
				pTrends->GetCode(),nAmount, pTrends->fAveragePrice,  pTrends->GetCurClose(),
				fAmount/100,(int)(100*fAmount/fCost)-100,g_usrAutoTrade.fNowFund /10000)  ;

			strFileBuf.append(sbuf);
			
			//puts(sbuf);

			//累计目前持仓市值
			fFund=fFund+nAmount *pTrends->GetCurClose()/100;
		}
		else 
		//未持仓，清除该结构体的内容
		{
			if(pTrends->GetCode ()>0)
			{
				memset(pTrends,0,sizeof(CNowTrends));
			}
		}
	}

	//记录当前日期、时间总资产及盈亏情况
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

//将当前持仓代码情况保存到文件
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

//将当前持仓标的保存到BSLog文件，便于在execl进行盈亏分析
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
		

		//代码,日期,时间,分析周期，BS处涨跌比,买量,成交额,手续费,类型,模式,最大持仓周期,买入价,止损价,止盈价
		sprintf_s(sbuf, "%07d,%07d,%04d,%04d,%04d,%04d,%06.2f,%04.2f,%02d,%02d,%04d,%04.2f,%04.2f,%04.2f",
			pTrends->GetCode(), (nDate / 2048 + 104) * 10000 + nDate % 2048,
			(nTime / 60) * 100 + nTime % 60, 5, 0, -nAmount, fAmount,
			0.0,  -BSTYPE_MAXHOLDWEEKS, BSMODE_MAXHOLDWEEKS,
			0, pTrends->GetCurClose(), 0.0,0.0);

		LogBSFile(g_sBSLog, sbuf);
	}
}

//将当前1买代码情况保存到文件  保存到cfg目录  "实时监控.txt"
void	Save1BuyStock()
{
	FILE	*fp;
	int		nStock[BUY1STOCKNUMBERS+2], i, j,nCode;
	char    sbuf[64];
	DeleteFile((LPCWSTR)g_s1BuyStock);
	DeleteFile((LPCWSTR)g_sRealMonitor);

	memset(nStock, 0, sizeof(int)*(BUY1STOCKNUMBERS+2));
	//前两个字节为最新分析日期时间
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
			//写入1买文件
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

//将当前1买标的读回
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

//读取自选持仓/平安的各种投顾服务
int	ReadZXCC(char *strPath)
{
	FILE	*fp;
	string  sBuf, tmp;
	char buf[256];
	int i = 0, j, nHoldingIndex = -1, nCodeIndex = 0;
	bool  bHoldingFound = false;
	long lFp;

	memset(&g_usrZXHolding, 0, ZXHOLDINGCOUNT * sizeof(ZXHolding));

	//仅在实时模式下分析自选持仓
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

//读取读取板块股票代码,返回代码总数及对应5分钟K线数据
int	ReadBLOCK(char *strPath,CStockBlockInfo *ptrStockBlock)
{
	FILE	*fp;
	char *buf;
	int i = 0, nSize = 0,j=0;

	fopen_s(&fp, strPath, "rb");
	if (fp != NULL)
	{
		//最多分析1200股票，防止内存不足导致异常，问题待查 20170402
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

		//每项记录9字节，7字节代码，2字节：0d0a
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

//读取读取板块股票代码,返回代码总数
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


		//每项记录9字节，7字节代码，2字节：0d0a
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

//读取读取ST板块股票代码,返回ST代码总数
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
		//每项记录9字节，7字节代码，2字节：0d0a
		for (i = 0; i<nSize-64; i += 9)
		{
			*(buf + i + 7) = 0;
			g_nSTlist[j++] = atoi(buf + i);
		}

		free(buf);
	}
	return j;
}
//判断指定代码是否为ST板块成员，是则返回true
bool  IsSTStock(int nCode)
{
	int i = 0, j = STNUMBERS-1,k=0;
	bool bRet = false;
	
	//跳过无效的代码
	while (g_nSTlist[j--] == 0);

	//二分法快速确定指定股票是否属于ST板块
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

//读取当前持仓情况和自定义持仓数据,并把重点关注的指数列为已持仓标的,计算其买卖点
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

	//加入重点关注的指数  用途不大，将来再使用20170311
	//i = 0;
	//while (g_usrStockIndexCodeName[i].unCode>0)
	//{
	//	if (k < MAXTRADENUMBER)
	//	{
	//		g_usrAutoTrade.usrStockTrade[k].nCode = g_usrStockIndexCodeName[i].unCode;
	//		//对自定义标的,人为设定一定的持仓量,方便后续处理
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

	//ReadZXCC("cfg\\自选持仓.txt");

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
	//				//对自定义标的,人为设定一定的持仓量,方便后续处理
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

//将当前持仓情况存入文件供后续分析直接使用
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

//分析当前股票是否在持仓列表，在即返回TRUE
bool	StockInTrade(CNowTrends *ptrTrends,int nCode)
{
	return g_usrAutoTrade.StockInList(nCode, ptrTrends);
}


void CheckAutoSell(int nDataLen,StockInfo *ptrStockInfo,int nWeek)
{
	//g_usrAutoTrade.AutoSell(nDataLen,ptrStockInfo,nCode,nWeek);
}

//粗略计算两个日期的差,不考虑大月、小月和二月等因素
//d1、d2为通达信压缩后的日期数据
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

//计算交易时间差
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
//粗略计算日期加指定天数
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

//分析标的判断，进队股票进行分析nMode=1，必要时在扩充其他标的
bool IsAnalyse(int nCode,int nMode)
{
	bool	ret=false;
	switch(nMode)
	{
	case 0:
		//深圳
		if( (nCode<9999) ||(nCode>=300000 && nCode<301000 ))
			ret=true;

		break;
	case 1:
		//上海
		if( nCode>=600000 && nCode<605000 )
			ret=true;

		break;
	case 99:
		//特殊板块分析，比如分级基金等，不做判断，直接返回true
		ret = true;

		break;
	}

	return ret;
}

//对当前股票的前期跌幅、长短均线走势进行拍讯，仅保留最大的前BUY1STOCKNUMBERS
//若当前加入的标的在前BUY1STOCKNUMBERS项内返回true
//上涨标的排序依据：*nWeekList上涨周期列表 权重计算15-1,30-2,45-3,60-4,90-5
//nDownWeeks  未使用
bool	SortDownStock(int nCode, int nBSType, int nDownRate1, short *nWeekList)
{
	int nValue = 0;
	int i = 0;
	bool	ret = false;

	//不同周期权重不一样
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


//如果没有指定的日期,应该选择最接近的日期  todo1127
int GotoStopDateTime(int nDataLen,int nStopDate,int nStopTime,StockInfo *p5MinKData)
{
	//剔除分钟数无效的数据	todo 二分法快速定位有效数据
	nDataLen--;
	int	nDiff,nSrcLen=nDataLen;
	int nLen=nDataLen/2,nLastLen=0;
	//p5MinKData[nLen].nYmd/2048>20 表明是2004年以前的数据,不必处理
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

	//数据终止于指定日期、时间
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
	//剔除分钟数无效的数据	todo 二分法快速定位有效数据
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

	//数据终止于指定日期、时间
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
	//剔除分钟数无效的数据	todo 二分法快速定位有效数据
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

	//数据终止于指定日期、时间
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

//从历史数据文件读取5分钟K线数据文件主要信息
// 典型5分钟文件路径 E:\02soft\new_tdx\vipdoc\sh\fzline\sh000001.lc5
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
		usrFileInfo->lCount = ftell(fp);       //文件长度
		fclose(fp);
	}
	else
	{
		memset(usrFileInfo,0,sizeof(C5MinKFileInfo));
	}
}


//指定操作的板块，沪深300操作空间最大，分级基金、etf和lof基金价值不大
void SetBlockParameters(_TCHAR* argv)
{
	switch (*argv)
	{
	case '0':
		//实时监控对象
		ReadBLOCK(g_sRealMonitor, &g_usrBlock5MinKData);
		sprintf_s(g_usrAutoTrade.strBlock, "%s", "实时监控");
		break;
	case  '1':
		//沪深300 板块
		ReadBLOCK(g_sHS300, &g_usrBlock5MinKData);
		sprintf_s(g_usrAutoTrade.strBlock,"%s", "沪深300");
		break;
	case '2':
		//央视50 板块
		ReadBLOCK(g_sYS50, &g_usrBlock5MinKData);
		sprintf_s(g_usrAutoTrade.strBlock, "%s", "央视50");
		break;
	case '3':
		//中小板
		ReadBLOCK(g_sZXB, &g_usrBlock5MinKData);
		sprintf_s(g_usrAutoTrade.strBlock, "%s", "中小板");
		break;
	case '4':
		//创业板
		ReadBLOCK(g_sCYB, &g_usrBlock5MinKData);
		sprintf_s(g_usrAutoTrade.strBlock, "%s", "创业板");
		break;
	case '5':
		//中小创
		ReadBLOCK(g_sZXC, &g_usrBlock5MinKData);
		sprintf_s(g_usrAutoTrade.strBlock, "%s", "中小创");
		break;

	case '6':
		//行业龙头
		 ReadBLOCK(g_sHYLT, &g_usrBlock5MinKData);
		sprintf_s(g_usrAutoTrade.strBlock, "%s", "行业龙头");
		break;
	case '7':
		//央企100
		ReadBLOCK(g_sYQ100, &g_usrBlock5MinKData);
		sprintf_s(g_usrAutoTrade.strBlock, "%s", "央企100");
		break;
	case '8':
		//上证180  没有操作价值，2012-2016没有一次买入信号
		 ReadBLOCK(g_sSZ180, &g_usrBlock5MinKData);
		sprintf_s(g_usrAutoTrade.strBlock, "%s", "上证180");
		break;
	case '9':
		//大盘蓝筹
		 ReadBLOCK(g_sDPLC, &g_usrBlock5MinKData);
		sprintf_s(g_usrAutoTrade.strBlock, "%s", "大盘蓝筹");
		break;
	case 'a':
	case 'A':
		//创业300
		 ReadBLOCK(g_sCY300, &g_usrBlock5MinKData);
		sprintf_s(g_usrAutoTrade.strBlock, "%s", "创业300");
		break;
	case 'b':
	case 'B':
		//ETF基金
		ReadBLOCK(g_sETF, &g_usrBlock5MinKData);
		sprintf_s(g_usrAutoTrade.strBlock, "%s", "ETF基金");
		break;
	case 'c':
	case 'C':
		//中小300
		 ReadBLOCK(g_sZX300, &g_usrBlock5MinKData);
		sprintf_s(g_usrAutoTrade.strBlock, "%s", "中小300");
		break;
	case 'd':
	case 'D':
		//中正100
		ReadBLOCK(g_sZZ100, &g_usrBlock5MinKData);
		sprintf_s(g_usrAutoTrade.strBlock, "%s", "中正100");
		break;
	case 'e':
	case 'E':
		//深证300
		ReadBLOCK(g_sSZ300, &g_usrBlock5MinKData);
		sprintf_s(g_usrAutoTrade.strBlock, "%s", "深证300");
		break;
	case 'f':
	case 'F':
		//中证100
		ReadBLOCK(g_sZZ100, &g_usrBlock5MinKData);
		sprintf_s(g_usrAutoTrade.strBlock, "%s", "中证100");
		break;
	case 'g':
	case 'G':
		//中证300
		ReadBLOCK(g_sZZ300, &g_usrBlock5MinKData);
		sprintf_s(g_usrAutoTrade.strBlock, "%s", "中证300");
		break;
	case 'z':
	case 'Z':
	default:
		CopyStock2Block();
		sprintf_s(g_usrAutoTrade.strBlock, "%s", "沪深全部");
		break;
	};
}

int SetupParameters(int argc, _TCHAR* argv[],bool *Debug)
{	
	int nRet=3;//缺省计算步长未15分钟，3个45分钟周期
	*Debug=false;
	g_nWorkMode =  WORKMODE_DEFAULT;
	string sbuf;

	ReadSTBLOCK((char*)g_sSTBlock);

	switch (argc)
	{
		case 7:
		case 8:
		{
			//4个参数，开始分析时间、结束时间和步长的买卖点以及是否SetDebugStockList
			g_nAnalyseStartDate = _wtoi(argv[1]);
			g_nAnalyseStartTime = _wtoi(argv[2]); //开始时间
			if ((g_nAnalyseStartTime >= 930 && g_nAnalyseStartTime <= 1130)
				|| (g_nAnalyseStartTime >= 1300 && g_nAnalyseStartTime <= 1500))
				g_nAnalyseStartTime = (g_nAnalyseStartTime / 100) * 60 + g_nAnalyseStartTime % 100;
			else
				g_nAnalyseStartTime = 900;

			g_nAnalyseStopDate = _wtoi(argv[3]);//结束日期

			g_nAnalyseStopTime = _wtoi(argv[4]); //结束时间
			g_nAnalyseStopTime = (g_nAnalyseStopTime / 100) * 60 + g_nAnalyseStopTime % 60;
			if ((g_nAnalyseStopTime >= 930 && g_nAnalyseStopTime <= 1130)
				|| (g_nAnalyseStopTime >= 1300 && g_nAnalyseStopTime <= 1500))
				g_nAnalyseStopTime = (g_nAnalyseStopTime / 100) * 60 + g_nAnalyseStopTime % 100;
			else
				g_nAnalyseStopTime = 900;

			g_nAnalyseStartDate = (g_nAnalyseStartDate / 10000 - 2004) * 2048 + (g_nAnalyseStartDate % 10000);
			g_nAnalyseStopDate = (g_nAnalyseStopDate / 10000 - 2004) * 2048 + (g_nAnalyseStopDate % 10000);

			//获取分析模式
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
				//训练模式：不必读取时间序列
				g_nWorkMode = WORKMODE_TRAINING;
				break;
			case 'r':
			case 'R':
				//实时分析模式
				g_nWorkMode = WORKMODE_REAL;
				//指向通达信历史主目录，在实时模式下仅分析通达信历史主目录信息
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

	//指定操作的板块
	if(*Debug != true)
		SetBlockParameters(argv[7]);
	else
		sprintf_s(g_usrAutoTrade.strBlock, "%s", "调试模式");

	return  nRet;
}

//兼容通达信结果返回模式的处理结果回送
//在分析模式下，每次调用后pfOUT指向下2个数据单位
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



//根据日线初选的项标的进行底背驰分析，找出潜在的BUY1STOCKNUMBERS标的并执行持仓
bool Buy1Cacl(int nStopDate, int nStopTime)
{
	char	filepath[250] = { 0 };
	string	tmp, sBuf, path;
	int	nCode, nDataLen,i;
	bool bRet = false;

	//满仓后不判新1买
	if (g_usrAutoTrade.HoldingFull() == true)
		return bRet;

	g_usrDayTrends.SortByDownRate();

	for (i = 0; i<g_usrDayTrends.nBuy1Count; i++)
	{
		StockInfo		*p5MinKData;
		long			nMaxLen;

		nCode = g_usrDayTrends.usrBuy1List[i].nCode;
		p5MinKData = g_usrBlock5MinKData.Get5MinKData(nCode,&nMaxLen);

		//5分钟K线数据无效，继续分析下一股票
		if (NULL == p5MinKData)  continue;
		
		CNowTrends		usrNowTrends;
		StockInfo		*pNowKData=g_pusrNowKData;

		//从数组中取有效的5分钟K线数据
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

					//初始化CJD和中枢盘整缓冲
					memset(g_pusrCJD, 0, g_nCJDBufSize * sizeof(CJDInfo));
					memset(g_pusrCZSPZ, 0, g_nCZSPZBufSize * sizeof(CZSPZInfo));
					usrNowTrends.usrCJD = g_pusrCJD;
					usrNowTrends.usrCZSPZ = g_pusrCZSPZ;

					//一买
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

//基于当日实时数据进行进行底背驰分析，找出潜在的BUY1STOCKNUMBERS标的并执行持仓
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

	//满仓后不判新1买
	if (g_usrAutoTrade.HoldingFull() == true)
		return false;

	g_usrDayTrends.SortByDownRate();

	for (i = 0; i<g_usrDayTrends.nBuy1Count; i++)
	{
		long			nMaxLen;

		nCode = g_usrDayTrends.usrBuy1List[i].nCode;
		if (0 == nCode) continue;

		p5MinKData = g_usrBlock5MinKData.Get5MinKData(nCode, &nMaxLen);

		//5分钟K线数据无效，继续分析下一股票
		if (NULL == p5MinKData)  continue;

		//从数组中取有效的5分钟K线数据
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
				//初始化CJD和中枢盘整缓冲
				memset(g_pusrCJD, 0, g_nCJDBufSize * sizeof(CJDInfo));
				memset(g_pusrCZSPZ, 0, g_nCZSPZBufSize * sizeof(CZSPZInfo));
				usrNowTrends.usrCJD = g_pusrCJD;
				usrNowTrends.usrCZSPZ = g_pusrCZSPZ;

				memcpy(usrNowTrends.nWeekList,
					g_usrDayTrends.usrBuy1List[i].nWeekList, ANALYSEWEEKS * sizeof(short));

				//一买
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


//对持仓标的进行2买、3买或卖出分析
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

		//5分钟K线数据无效，继续分析下一股票
		if (NULL == p5MinKData)  continue;

		//从数组中取有效的5分钟K线数据
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
				//初始化CJD和中枢盘整缓冲
				memset(g_pusrCJD, 0, g_nCJDBufSize * sizeof(CJDInfo));
				memset(g_pusrCZSPZ, 0, g_nCZSPZBufSize * sizeof(CZSPZInfo));
				usrNowTrends.usrCJD = g_pusrCJD;
				usrNowTrends.usrCZSPZ = g_pusrCZSPZ;

				//卖出分析
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

//对持仓标的进行2买、3买或卖出分析  实时分析
//对未持仓标的同样存在2买3买分析需要
//无论何种2买、3买，甚至类3买，其判断原则一致：
//分析周期内底背驰的底分型后出现一波反弹，其后回调产生次级别的底背驰而构成的买点
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

		//从数组中取有效的5分钟K线数据
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

				//初始化CJD和中枢盘整缓冲
				memset(g_pusrCJD, 0, g_nCJDBufSize * sizeof(CJDInfo));
				memset(g_pusrCZSPZ, 0, g_nCZSPZBufSize * sizeof(CZSPZInfo));
				usrNowTrends.usrCJD = g_pusrCJD;
				usrNowTrends.usrCZSPZ = g_pusrCZSPZ;


				//二买
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


//是否资金关注焦点
bool IsFocusing(StockInfo * pDayKData,int nDataLen,CNowTrends *ptrCNow)
{
	bool bRet = true;
	int nShort = 5, nMid = 10, nLong =120,nContinueUp=3;
	int  nLen = nLong + nContinueUp*5;
	
	/*  资金关注判断规则
	    1）nDataLen不能小于nMid的3倍
		2）最近连续nContinueUp交易日短中长成交量处于多头排列，且是首次出现
		3）短中长成交量处于连续递增状态
	*/
	if (nDataLen > nLen)
	{
		int i;
		float fRate = 1.5; //中线均线大于长线的比例
		
		long *lShort = new long[nLen], *lMid = new long[nLen], *lLong = new long[nLen];
		ptrCNow->MAVOL(nLen, pDayKData+nDataLen-nLen, nShort, nMid, nLong, lShort, lMid, lLong);

		for (i = nLen - 1; bRet==true && i >= nLen - 1 - nContinueUp; i--)
		{
			bRet = (lShort[i] > lLong[i] * fRate);
		}

		//nContinueUp+1天前不是多头排列
		if(bRet==true)
			bRet  =!(lShort[i] > lLong[i] * fRate);
	}
	else
		bRet = false;

	return bRet;
}

//RSI是否提示可买
bool IsRSIBuy(StockInfo * pDayKData, int nDataLen, CNowTrends *ptrCNow)
{
	bool bRet = true;


	return bRet;
}

//RSI是否提示应卖
bool IsRSISell(StockInfo * pDayKData, int nDataLen, CNowTrends *ptrCNow)
{
	bool bRet = true;


	return bRet;
}

//ATR是否提示可买
bool IsATRBuy(StockInfo * pDayKData, int nDataLen, CNowTrends *ptrCNow)
{
	bool bRet = true;


	return bRet;
}

//ATR是否提示应卖
bool IsATRSell(StockInfo * pDayKData, int nDataLen, CNowTrends *ptrCNow)
{
	bool bRet = true;


	return bRet;
}


