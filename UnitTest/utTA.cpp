#include "stdafx.h"
#include "CppUnitTest.h"
#include "stdio.h"
#include "..\RisingSun\TechAnalyse.h"
#include "..\RisingSun\gmTrade.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTestTA)
	{
#define		DEBUG_COUNT		400
	private:
		CTECHANALYSE	usrTA;
		CRISINGSUNTRADER        usrGMTrade;
		TA_DATA			usrParam;
		KLINEDATA           usrBars[DEBUG_COUNT];
		float			fData[DEBUG_COUNT];
		
		int				nMa[WEEKS_COUNT] = { 9,12,26,0,0 };

		//生成代随机数的系列
		double  CreateLineRandData(double nBase = 2e6,
			double dlbLiner =5e5,
			double    nRand=4e4)
		{
			int j;
			double  dblRet;
			j = rand();
				
			dblRet = nBase + dlbLiner +nRand*j;// 周期变换的数据
			
			
			return dblRet;
		}

		void  CreateSinLinerData(int nBase=10,double dlbLiner=0.3,
			int nSinLiner=13,double dblSinWeek=0.29)
		{
			for (int i = 0; i < DEBUG_COUNT; i++)
				fData[i] = nBase + dlbLiner*i+ nSinLiner * sin(dblSinWeek*i);// 周期变换的数据
		}


	public:
		TEST_METHOD(TestSAR)
		{
			// TODO: 在此输入测试代码  000710-030-20170818--20180112.dat
			int i = 0;
			unsigned int nBufferSize = 4096;
			char szBuf[4096] = { 0 }, szTestDataFile[260] = "..\\UnitTest\\000710-030-20170818--20180112bars.dat";
			KLINEDATA  usrBars[DEBUG_COUNT] = { 0 };
			float	fHigh[DEBUG_COUNT], fLow[DEBUG_COUNT];

			FILE  *fp;

			fp = fopen(szTestDataFile, "rb");

			if (!fp)
				return;

			int nSize = sizeof(KLINEDATA);
			int nCount = min(usrTA.GetFileSize(szTestDataFile) / nSize, DEBUG_COUNT - 1);
			//usrGMTrade.ReadKData(usrBars, &nCount);

			fread_s(usrBars, DEBUG_COUNT *nSize, nSize, nCount, fp);
			fclose(fp);

			nMa[0] = 2, nMa[1] = 20, nMa[2] = 0;

			memcpy_s(usrParam.nWeek, sizeof(int)*WEEKS_COUNT, nMa, sizeof(int)*WEEKS_COUNT);
			usrParam.nLastCount = 0;
			
			for (i = 0; i < nCount; i++)
			{
				fHigh[i] = usrBars[i].high;
				fLow[i] = usrBars[i].low;
			}

			usrParam.pData = fHigh;
			usrParam.pData1 = fLow;

			for (i = 10; i <DEBUG_COUNT - 1; i++)
			{
				usrTA.ClearParameters();
				usrParam.nDataCount = i+1;
				usrParam.nOption = 1;
				usrTA.SetParameters(&usrTA.SAR, &usrParam);

				if (strlen(szBuf) < nBufferSize - 128) //防止缓冲区溢出
				{
					struct  tm timeStruc;
					int64_t   nTmp;
					nTmp = int64_t(usrBars[i ].utcStop);
					localtime_s(&timeStruc, &nTmp);
					int nDate = timeStruc.tm_year * 10000 + (timeStruc.tm_mon+1) * 100 + timeStruc.tm_mday;
					int nTime = timeStruc.tm_hour * 100 + timeStruc.tm_min;
					if (usrTA.Analyse()) //防止缓冲区溢出
					{
						if (usrParam.nTACmdStatus == SAR_D2U)
							sprintf_s(szBuf, "%sSAR UP Date:%d,Time:%d,Close;%.2f\n", szBuf,
								nDate, nTime, usrBars[i ].close);
						else
							sprintf_s(szBuf, "%sSAR DOWN Date:%d,Time:%d,Close;%.2f\n", szBuf,
								nDate, nTime, usrBars[i ].close);
					}
					
				}


			}

			i = 0;
		}

		//组合分析  资金流的作用似乎不大
		TEST_METHOD(MainFlowSARMA)
		{
			// TODO: 在此输入测试代码  000710-030-20170818--20180112.dat
			int i = 0;
			int nBufferSize = 4096*16;
			bool bNoChanged;
			char szBuf[4096*16] = { 0 }, szTestDataFile[260] = "..\\UnitTest\\000710-030-20170818--20180112.dat";
			CAPITALFLOWMINISTRUCK  usrFlow[DEBUG_COUNT] = { 0 };
			int  nMAWeek[] = { 5,10,20,0,0 },
				nFLOWWeek[] = { 3,5,13,0,0 },
				nRSIWeek[] = { 5,11,17,0,0 },
				nMACDWeek[] = { 9,12,26,0,0 },
				nSARWeek[] = {2,20,0,0,0};

			//High Low :for sar, Close:for ma and macd
			float	fHigh[DEBUG_COUNT],
				    fLow[DEBUG_COUNT], 
				    fClose[DEBUG_COUNT];

			FILE  *fp;

			//======================setup   flow data  =====================================
			fp = fopen(szTestDataFile, "rb");

			if (!fp)
				return;

			int nSize = sizeof(CAPITALFLOWMINISTRUCK);
			int nFlowCount = min(usrTA.GetFileSize(szTestDataFile) / nSize, DEBUG_COUNT - 1);

			fread_s(usrFlow, DEBUG_COUNT *nSize, nSize, nFlowCount, fp);
			fclose(fp);

			nMa[0] = 5, nMa[1] = 13, nMa[2] = 26;

			//read saved bars data
			char *ptr = strrchr(szTestDataFile, '.');
			memcpy_s(ptr, 8, "bars.dat", 8);
			fp = fopen(szTestDataFile, "rb");

			if (fp)
			{
				fread_s(usrBars, DEBUG_COUNT*nSize, nSize, nFlowCount, fp);
				fclose(fp);
			}

			//setup price data
			for (i = 0; i < nFlowCount; i++)
			{
				fHigh[i] = usrBars[i].high;
				fLow[i] = usrBars[i].low;
				fClose[i] = usrBars[i].close;
			}
			
			usrParam.nDataCount = usrParam.GetMaxWeek()*2;

			//for (i = usrParam.GetMaxWeek() + usrParam.nLastCount + 1; i <DEBUG_COUNT - 1; i++)
			for (i = max(100, nFlowCount - usrParam.nDataCount-100); i <nFlowCount - usrParam.nDataCount; i++)
			{
				bNoChanged = false;
				if (strlen(szBuf) < nBufferSize - 128) //防止缓冲区溢出
				{
					memcpy_s(usrParam.nWeek, sizeof(int)*WEEKS_COUNT,nFLOWWeek, sizeof(int)*WEEKS_COUNT);
					usrParam.nLastCount = 3;
					usrParam.nOption = CACL_FLOW_MAIN_DELTA;
					usrParam.pData = usrFlow+i- usrParam.GetMaxWeek();
					usrParam.nDataCount = usrParam.GetMaxWeek() * 2;
					if (usrTA.MainCapitalFlowChanged(&usrParam)) //资金流变化分析
					{
						if (usrParam.nTACmdStatus == FLOWUP)
							sprintf_s(szBuf, "%sFLOWIN", szBuf);
						else if (usrParam.nTACmdStatus == FLOWDOWN)
							sprintf_s(szBuf, "%sFLOWOUT", szBuf);
						else
						{
							sprintf_s(szBuf, "%sFLOW---", szBuf);
							bNoChanged = true;
						}
					}
					else
					{
						sprintf_s(szBuf, "%sFLOW---", szBuf);
						bNoChanged = true;
					}

					memcpy_s(usrParam.nWeek, sizeof(int)*WEEKS_COUNT,nMAWeek, sizeof(int)*WEEKS_COUNT);
					usrParam.nLastCount = 3;
					usrParam.pData =fClose + i - usrParam.GetMaxWeek();

					if (usrTA.MAUP_S(&usrParam) ) //MAUP
						sprintf_s(szBuf, "%s,MAUP", szBuf);
					else if (usrTA.MADOWN_S(&usrParam)) //MADOWN
						sprintf_s(szBuf, "%s,MADOWN", szBuf);
					else
					{
						sprintf_s(szBuf, "%s,MA----", szBuf);
						bNoChanged = true;
					}
						

					memcpy_s(usrParam.nWeek, sizeof(int)*WEEKS_COUNT,nSARWeek, sizeof(int)*WEEKS_COUNT);
					usrParam.nLastCount = 0;
								
					usrParam.pData = fHigh + i - usrParam.GetMaxWeek();
					usrParam.pData1 = fLow + i - usrParam.GetMaxWeek();
					if (usrTA.SAR(&usrParam))
						if(usrParam.nTACmdStatus == SAR_D2U)  //SAR UP
							sprintf_s(szBuf, "%s,SAR_D2U", szBuf);
						else if (usrParam.nTACmdStatus == SAR_U2D)  //SAR UP
							sprintf_s(szBuf, "%s,SAR_U2D", szBuf);
						else
						{
							sprintf_s(szBuf, "%s,SAR----", szBuf);
							bNoChanged = true;
						}
					else
					{
						sprintf_s(szBuf, "%s,SAR----", szBuf);
						bNoChanged = true;
					}
						
					sprintf_s(szBuf, "%s,%d,%d,%.2f\n", szBuf,
						usrFlow[i].m_nDate,usrFlow[i].m_nTime, usrBars[i].close);
				}
			}

			i = 0;
		}

		TEST_METHOD(TestMainFlow)
		{
			// TODO: 在此输入测试代码  000710-030-20170818--20180112.dat
			int i = 0;
			int nBufferSize = 4096;
			char szBuf[4096] = { 0 },szTestDataFile[260]="..\\UnitTest\\000710-030-20170818--20180112.dat";
			CAPITALFLOWMINISTRUCK  dblFlow[DEBUG_COUNT] = {0};
			FILE  *fp;
			fp=fopen(szTestDataFile, "rb");

			if (!fp)
				return;

			int nSize = sizeof(CAPITALFLOWMINISTRUCK);
			int nCount = min( usrTA.GetFileSize(szTestDataFile) / nSize, DEBUG_COUNT-1);

			fread_s(dblFlow, DEBUG_COUNT *nSize, nSize, nCount,fp ) ;
			fclose(fp);

			nMa[0] = 5, nMa[1] = 13, nMa[2] = 26;
			usrGMTrade.ReadKData(usrBars, &nCount);

			//read saved bars data
			char *ptr=strrchr(szTestDataFile, '.');
			memcpy_s(ptr, 8, "bars.dat", 8);
			fp = fopen(szTestDataFile, "rb");

			if (fp)
			{
				fread_s(usrBars, DEBUG_COUNT*nSize, nSize, nCount, fp);
				fclose(fp);
			}

			//save bars for test only
			/*fp = fopen(szTestDataFile, "wb");

			if (!fp)
				return;
			else
			{
				fwrite(usrBars,nSize , nCount, fp);
				fclose(fp);
			}*/

			memcpy_s(usrParam.nWeek, sizeof(int)*WEEKS_COUNT, nMa, sizeof(int)*WEEKS_COUNT);
			usrParam.nLastCount = 3;
			usrParam.pData = dblFlow;
			//for (i = usrParam.GetMaxWeek() + usrParam.nLastCount + 1; i <DEBUG_COUNT - 1; i++)
			for (i = 350; i <DEBUG_COUNT-1; i++)
			{
				usrTA.ClearParameters();
				usrParam.nDataCount = i+1;
				usrTA.SetParameters(&usrTA.MainCapitalFlowChanged, &usrParam);

				if (strlen(szBuf) < nBufferSize - 128) //防止缓冲区溢出
				{
					/*struct  tm timeStruc;
					int64_t   nTmp;
					nTmp = int64_t(usrBars[i - 1].utcStop);
					localtime_s(&timeStruc, &nTmp);*/

					if (usrTA.Analyse()) //防止缓冲区溢出
					{
						if (usrParam.nTACmdStatus == FLOWDOWN)
							sprintf_s(szBuf, "%sout Date:%d,Time:%d,Close;%.2f\n\n", szBuf,
								dblFlow[i].m_nDate, dblFlow[i].m_nTime, usrBars[i].close);
						else
							sprintf_s(szBuf, "%sIn Date:%d,Time:%d,Close;%.2f\n", szBuf,
								dblFlow[i].m_nDate, dblFlow[i].m_nTime, usrBars[i].close);
					}
				}
					

			}

			i = 0;
		}

		TEST_METHOD(TestRSI)
		{
			// TODO: 在此输入测试代码
			int i = 0;
			char szBuf[2600] = { 0 };

			CreateSinLinerData(10,0.3,13,0.29);
			nMa[0] = 5, nMa[1] = 11, nMa[2] = 17;

			memcpy_s(usrParam.nWeek, sizeof(int)*WEEKS_COUNT, nMa, sizeof(int)*WEEKS_COUNT);
			usrParam.pData = fData;
			sprintf_s(szBuf, "RSI");
			
			usrParam.nDataCount = usrParam.GetMaxWeek() * 2;
			for (i = max(0, DEBUG_COUNT-50- usrParam.nDataCount); i <DEBUG_COUNT- usrParam.nDataCount; i++)
			{
				usrParam.pData = fData+i;
				usrParam.nLastCount = 35;
				
				usrParam.nOption = 75;
				if (usrTA.RSIUP( &usrParam,true))
					sprintf_s(szBuf, "%s,UP:%d,Last Weeks:%d", szBuf, i, usrParam.nOption);

				usrParam.nDataCount = usrParam.GetMaxWeek()*2;
				usrParam.nLastCount = 70;
				if (usrTA.RSIDOWN(&usrParam, true))
					sprintf_s(szBuf, "%s,DOWN:%d,Last Weeks:%d", szBuf, i, usrParam.nOption);
			}

		}

		TEST_METHOD(TestMACDGold)
		{
			// TODO: 在此输入测试代码
			int i = 0;
			char szBuf[260] = {0};
			
			CreateSinLinerData();

			memcpy_s(usrParam.nWeek, sizeof(int)*WEEKS_COUNT, nMa, sizeof(int)*WEEKS_COUNT);
			usrParam.nLastCount = 0;
			
			usrParam.nDataCount = usrParam.GetMaxWeek()*2;
			sprintf_s(szBuf, "MACD");

			for (i = max(0, DEBUG_COUNT-500); i <DEBUG_COUNT; i++)
			{
				usrParam.pData = &fData[i];
				if(usrTA.MACDGold( &usrParam,true))
					sprintf_s(szBuf,"%s,Gold:%02d",szBuf,i);

				if (usrTA.MACDDead(&usrParam, true))
					sprintf_s(szBuf, "%s,Dead:%02d", szBuf, i);
			}

		}
		
		TEST_METHOD(TestMaUpDown)
		{
			// TODO: 在此输入测试代码
			int i = 0;
			for (i = 0; i < DEBUG_COUNT; i++)
				fData[i] = i;// 单调增加数据

			usrParam.nDataCount = 30;
			memcpy_s(usrParam.nWeek, sizeof(int)*WEEKS_COUNT, nMa, sizeof(int)*WEEKS_COUNT);
			usrParam.nLastCount = 3;
			usrParam.pData = fData;

			usrTA.MAUP_S(&usrParam, true);

			for (i = 0; i < DEBUG_COUNT; i++)
				fData[i] = DEBUG_COUNT-i;// 单调减少数据;

			nMa[3] = 30;
			nMa[4] = 60;
			usrParam.nDataCount = 64;
			memcpy_s(usrParam.nWeek, sizeof(int)*WEEKS_COUNT, nMa, sizeof(int)*WEEKS_COUNT);
			usrParam.nLastCount = 3;
			usrTA.MADOWN_S(&usrParam, true);
		}

	};
}