#pragma once
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include <sys/types.h>  
#include <sys/stat.h>   
#include "..\RisingSun\Data.h"
#include  "..\ta-lib-msvc\c\include\ta_libc.h"

#define  TA_COUNT	8
#define  WEEKS_COUNT 5
#define  MAX_CACL_COUNT 512
#define  EPS			1e-4
/*
资金流总体情况：小于80h总体流入态势，大于80h总体呈流出态势
基于均线进行判断
01  备用
02  加速流入  FASTIN
03  减速流入  SLOWIN
04  加速流出  FASTOUT
05  减速流出  SLOWOUT
06  入转出    IN2OUT
07  出转入    OUT2IN

*/
enum  CAPITAL_FLOW {
	
};

//SAR指标实际就是起这个作用
enum  TA_TRENDS {
	MA_TRENDS_DO_ANALYSE=1,  //DO ANALYSE
	MA_TRENDS_D2U = 2,       // DOWN STATUS TO UP
	MA_TRENDS_U2D = 3,      //UP STATUS TO DOWN
	MA_TRENDS_GOLDX= 4,     // GOLD CROSS
	MA_TRENDS_DEADX = 5,    //DEAD CROSS
	MA_TRENDS_DOWN = 6,     //LAST DOWN
	MA_TRENDS_UP = 7,      //LAST UP
	SAR_D2U,
	SAR_U2D,
	/*
	主力增量资金变化情况与主力资金流有一定滞后性
	1）主力增量资金趋势为多头，表明外流减弱，表明可能存在反转，
	   主力累计资金多头且存量大于0才是明确的多头趋势；
	*/
	CACL_FLOW_MAIN_DELTA,  //主力资金增量趋势
	CACL_FLOW_MAIN_TOTAL,  //主力资金变化趋势
	CACL_FLOW_SMALL_DELTA,
	CACL_FLOW_SMALL_TOTAL,

	FLOWREVERSE ,
	FASTIN ,
	SLOWIN ,
	FASTOUT,
	SLOWOUT ,
	IN2OUT ,  //不稳定状态
	OUT2IN,  //不稳定状态
	FLOWUP ,
	FLOWDOWN,
	FLOWTOTALUP,
	FLOWTOTALDOWN,
	FLOWNOCHANGED


};

//基于TALIB 进行技术分析
typedef  bool(*TA_FUNC_TYPE)(void*,bool);
typedef struct tagTA_FUNCTION
{
	TA_FUNC_TYPE pfTA;	//技术分析函数入口地址
	void *pParameters;	//技术分析参数，简单类型或自定义类型
}TA_FUNCTION;

typedef struct tagTA_DATA
{
	void	*pData, *pData1;		//待分析的数据及长度  由调用者设定实际的数据类型：float、double
	int		nDataCount, nLastCount;//总数据项，连续满足条件的周期数
	
	/*
		nOption  可选项
		SAR数据偏移量  指标计算时用于High、Low偏移计算，减少短期波动的信号误差 
		MainFlow 区分数据类型
				1--计算主力资金变化情况
				2--计算主力资金累计情况
				3--计算散户资金变化情况
				4--计算散户资金累计情况
		RSI:UP    上界限
		    DOWN  下界限
	*/
	int     nOption;           
	//最多支持5种周期，小于1的周期忽略，数据必须从小到达排列
	//对于MACD等三种周期的指标，0、1、2分别对应短、中、长周期
	int     nWeek[WEEKS_COUNT];
	
	//记录技术分析结果情况
	int     nTACmdStatus;

	int     nTotalFlow;//单位万元
	/*
	  计算主力累计资金流时：记录分析周期内的主力资金总量情况

	*/


	int     GetMaxWeek()
	{
		int nRet = 0;
		for (int i = 0; i < WEEKS_COUNT && nWeek[i]>0; i++)
		{
			nRet = nWeek[i] > nRet ? nWeek[i] : nRet;
		}
		return nRet;
	}
}TA_DATA;

class CTECHANALYSE
{
public:
	CTECHANALYSE()
	{
		//仅能运行一次
		TA_Initialize();
	}

	~CTECHANALYSE()
	{
		TA_Shutdown();
	}

private:
	//技术分析参数列表，分析结果与运算
	
	TA_FUNCTION m_usrLongTaList[TA_COUNT] = { NULL };
	TA_FUNCTION m_usrShortTaList[TA_COUNT] = {NULL};
		

public:
	
	//抛物线转向也称停损点转向，是利用抛物线方式，随时调整停损点位置以观察买卖点。
	//由于停损点（又称转向点SAR）以弧形的方式移动，故称之为抛物线转向指标 。
	/*
	* TA_SAR - Parabolic SAR
	*
	* Input  = High, Low
	* Output = double
	*
	* Optional Parameters
	* -------------------
	* optInAcceleration:(From 0 to TA_REAL_MAX)
	*    Acceleration Factor used up to the Maximum value
	*
	* optInMaximum:(From 0 to TA_REAL_MAX)
	*    Acceleration Factor Maximum value
	*
	*
	*/
	static bool  SAR(void *pParameters,bool bCaclLastWeeks=false)
	{
		bool bRet = false;
		int nOutBegin, nOutCount;
		static int nSARStatus=0;
		double dblOut[MAX_CACL_COUNT] = { NULL };

		TA_DATA *pParam = (TA_DATA*)pParameters;

		try
		{
			TA_S_SAR(max(0, pParam->nDataCount-30 ), pParam->nDataCount ,
				(float*)pParam->pData, (float*)pParam->pData1,  //High Low
				pParam->nWeek[0], pParam->nWeek[1],
				&nOutBegin, &nOutCount, dblOut);
			/*
			能很快检测到抛物线反转，甚至出现很多过程中的抖动点，参照东方财富的处理，
			对dblOut的信息进行一定幅度的偏移处理，提高信号的稳定性。
			利用nLastCount进行信号有效性检测
			盘整条件下信号准确度很差，信号明显失真，需结合均线等指标判断。
			*/
			char szBuf[2048] = {0};
			double  dblVar = pParam->nOption/100.0;
			for (int i = nOutCount - 5; i < nOutCount; i++)
			{
				sprintf_s(szBuf, "%s%02d--%.2f,%.2f,%.2f\n", szBuf,
					i, ((float*)pParam->pData)[i], 
					((float*)pParam->pData1)[i] , 
					dblOut[i]);
			}

			if (dblOut[nOutCount - 1] - ((float*)pParam->pData1)[nOutCount - 1] * (1 - dblVar) >= EPS      
				&& dblOut[nOutCount - 1] - ((float*)pParam->pData)[nOutCount - 1] * (1 + dblVar) <= EPS)
			{
				//dblOut[nOutCount - 1]在High Low体内，维持现状不变
				pParam->nTACmdStatus = nSARStatus;//送出当前状态
				bRet = false;
			}
			else
			{
				if (   nSARStatus != SAR_D2U
					&& dblOut[nOutCount - 1] - ((float*)pParam->pData1)[nOutCount - 1]  <= EPS      //跌转升
					&& dblOut[nOutCount - 2] - ((float*)pParam->pData)[nOutCount - 2]  >= EPS
					)
				{
					nSARStatus = SAR_D2U;
					pParam->nTACmdStatus = nSARStatus;
					bRet = true;
				}
				else if (nSARStatus != SAR_U2D
					&& dblOut[nOutCount - 1] - ((float*)pParam->pData1)[nOutCount - 1]  >= EPS    //升转跌  
					&& dblOut[nOutCount - 2] - ((float*)pParam->pData)[nOutCount - 2]  <= EPS
					)
				{
					nSARStatus = SAR_U2D;
					pParam->nTACmdStatus = nSARStatus;
					bRet = true;
				}
				else
				{
					pParam->nTACmdStatus = nSARStatus;//送出当前状态
					bRet = false;
				}
			}
			
				
		}
		catch (...)  //抓获多种数据类型的异常对象的话
		{
			bRet = false;
		}

		return bRet;
	}

		
	void SetParameters(TA_FUNC_TYPE pTA, void *pParam)
	{
		int i;
		for (i = 0; i < TA_COUNT; i++)
			if (m_usrShortTaList[i].pfTA == NULL)
				break;
		if (i < TA_COUNT)
		{
			m_usrShortTaList[i].pfTA = pTA;
			m_usrShortTaList[i].pParameters = pParam;
		}
	}

	//获取指定文件大小#include <sys/types.h>  <sys/stat.h> 
	long GetFileSize(char* strFile)
	{
		struct stat my_stat;
		stat(strFile, &my_stat);
		return my_stat.st_size;
	}

	void ClearParameters()
	{
		memset(m_usrLongTaList, 0, TA_COUNT * sizeof(TA_FUNCTION));
		memset(m_usrShortTaList, 0, TA_COUNT * sizeof(TA_FUNCTION));
	}

	bool  Analyse(TA_FUNCTION *ptr=NULL)
	{
		bool bRet = true;
		
		for (int i = 0; i < TA_COUNT && m_usrShortTaList[i].pfTA; i++)
			if (false== m_usrShortTaList[i].pfTA(m_usrShortTaList[i].pParameters,false))
			{
				bRet = false;
				break;
			}
			
		return bRet;
	}

	//主力资金流入情况分析
	//资金趋势变化true，否则为fasle，pParam->nTACmdStatus返回资金流状态
	static bool  MainCapitalFlowChanged(void *pParameters, bool bCaclLastWeeks = false)
	{
		bool bRet = false;
		static int nStatus = FLOWREVERSE;
		int i;
		double dblOut[WEEKS_COUNT][MAX_CACL_COUNT] = { 0 };
		
		//主力资金流信息
		double dblMainFlow[MAX_CACL_COUNT] = { 0 };

		TA_DATA *pParam = (TA_DATA*)pParameters;

		int  nMaxAnalyseWeek = pParam->GetMaxWeek() + pParam->nLastCount + 1;

		if (   pParam->nDataCount - nMaxAnalyseWeek < 0 
			|| nMaxAnalyseWeek>MAX_CACL_COUNT)
			return bRet;

		try
		{
			CAPITALFLOWSTRUCK *pCapFlow = (CAPITALFLOWSTRUCK *)pParam->pData;

			//计算累计资金流信息
			int nStartIndex = max(0, pParam->nDataCount - MAX_CACL_COUNT);

			switch (pParam->nOption)
			{
			case CACL_FLOW_MAIN_DELTA:
			case CACL_FLOW_MAIN_TOTAL:
				dblMainFlow[0] = pCapFlow[nStartIndex].GetBigNavFlow();
				break;
			
			case CACL_FLOW_SMALL_DELTA:
			case CACL_FLOW_SMALL_TOTAL:
				dblMainFlow[0] = pCapFlow[nStartIndex].GetSmallNavFlow();
				break;
			}
			

			/*MainFlow 区分数据类型
				1--计算主力资金变化情况
				2--计算主力资金累计情况
				3--计算散户资金变化情况
				4--计算散户资金累计情况*/
			for (i = nStartIndex+1; i < pParam->nDataCount ; i++)
			{
				switch (pParam->nOption)
				{
					case CACL_FLOW_MAIN_DELTA:
						dblMainFlow[i - nStartIndex] = pCapFlow[i].GetBigNavFlow();
						break;
					case CACL_FLOW_MAIN_TOTAL:
						dblMainFlow[i - nStartIndex] = dblMainFlow[i - nStartIndex - 1]
							+ pCapFlow[i].GetBigNavFlow();
						break;
					case CACL_FLOW_SMALL_DELTA:
						dblMainFlow[i - nStartIndex] = pCapFlow[i].GetSmallNavFlow();
						break;
					case CACL_FLOW_SMALL_TOTAL:
						dblMainFlow[i - nStartIndex] = dblMainFlow[i - nStartIndex - 1]
							+ pCapFlow[i].GetSmallNavFlow();
						break;
				}
			}
			
			pParam->nTotalFlow= dblMainFlow [pParam->nDataCount-1]/ 10000;//返回累计值

			TA_DATA      usrFlow;

			usrFlow.nDataCount = min(pParam->nDataCount, MAX_CACL_COUNT);
			memcpy_s(usrFlow.nWeek, sizeof(int)*WEEKS_COUNT, pParam->nWeek, sizeof(int)*WEEKS_COUNT);
			usrFlow.nLastCount = pParam->nLastCount; //主力资金是否处于多头状态的周期数
			usrFlow.pData = dblMainFlow;

			//资金流均线需要优化设计
			bRet=MAUP((void*)&usrFlow,true);//判断主力资金是否处于多头状态
			if (bRet /*&& nStatus != FLOWUP*/)
			{
				pParam->nTACmdStatus = FLOWUP;
				pParam->nOption = usrFlow.nOption;
				nStatus = FLOWUP;
			}
			else
			{
				bRet = MADOWN((void*)&usrFlow,true);
				if (/*nStatus != FLOWDOWN && */bRet) //判断主力资金是否处于空头状态
				{
					pParam->nTACmdStatus = FLOWDOWN;
					pParam->nOption = usrFlow.nOption;
					nStatus = FLOWDOWN;
					bRet = true;
				}
				else
				{
					//资金流趋势转换中，算法需细化  todo  20180118
					pParam->nTACmdStatus = nStatus;
					bRet = false;
				}
			}
		
		}
		catch (...)  //抓获多种数据类型的异常对象的话
		{
			bRet = false;
		}

		return bRet;
	}

	//均线多头排列
	static bool  MAUP(void *pParameters, bool bCaclLastWeeks = true)
	{
		bool bRet = false;
		int  nLastWeeks=0;
		int i, nOutBegin[WEEKS_COUNT], nOutCount[WEEKS_COUNT];
		double dblOut[WEEKS_COUNT][MAX_CACL_COUNT] = {NULL};

		TA_DATA *pParam =(TA_DATA*) pParameters;
		int  nMaxAnalyseWeek = pParam->GetMaxWeek()+pParam->nLastCount+1;

		if (pParam->nDataCount - nMaxAnalyseWeek < 0 || nMaxAnalyseWeek>MAX_CACL_COUNT)
			return bRet;

		try
		{
			//计算各周期均值  仅计算nMaxAnalyseWeek周期
			for ( i = 0; i < WEEKS_COUNT && pParam->nWeek[i]>0; i++)
			{  //pParam->nDataCount - nMaxAnalyseWeek
				TA_MA(pParam->nDataCount - nMaxAnalyseWeek,
					pParam->nDataCount - 1,(double*)pParam->pData,
					pParam->nWeek[i], TA_MAType_SMA,
					&nOutBegin[i], &nOutCount[i], dblOut[i]);
			}

			bRet = true;
			int k = i - 1;
			do
			{
				if (nOutCount[k] - pParam->nLastCount<0)
				{
					bRet = false;//数据不完整，不做判断
				}
			} while (--k >= 0 && bRet);

			//比较是否满足条件  多头判断
			do
			{
				//比较是否满足条件均线向上发散
				
				k = i - 1;
				
				do
				{
					int index = nOutCount[k] - nLastWeeks - 1;
					int index1 = nOutCount[k - 1] - nLastWeeks - 1;
					bRet = (dblOut[k - 1][index1] - dblOut[k][index]>EPS);
					k--;
				} while (k > 0 && bRet);

				if(bRet)
					nLastWeeks++;  //计算累计满足向上发散的周期数

			} while (bRet && bCaclLastWeeks
				&& nOutCount[i - 1] - nLastWeeks >= 0);
		}
		catch (...)  //抓获多种数据类型的异常对象的话
		{
			bRet= false;
		}
		pParam->nOption = nLastWeeks;
		return nLastWeeks>= pParam->nLastCount ;
	}

	static bool  MAUP_S(void *pParameters,bool bCaclLastWeeks= true)
	{
		bool bRet = false;
		int nLastWeeks = 0;
		int i, nOutBegin[WEEKS_COUNT], nOutCount[WEEKS_COUNT];
		double dblOut[WEEKS_COUNT][MAX_CACL_COUNT] = { NULL };

		TA_DATA *pParam = (TA_DATA*)pParameters;
		int  nMaxAnalyseWeek = pParam->GetMaxWeek() + pParam->nLastCount + 1;

		if (pParam->nDataCount - nMaxAnalyseWeek < 0 || nMaxAnalyseWeek>MAX_CACL_COUNT)
			return bRet;

		try
		{
			//计算各周期均值  仅计算nMaxAnalyseWeek周期
			for (i = 0; i < WEEKS_COUNT && pParam->nWeek[i]>0; i++)
			{  //pParam->nDataCount - nMaxAnalyseWeek
				TA_S_MA(pParam->nDataCount - nMaxAnalyseWeek,
					pParam->nDataCount - 1, (float*)pParam->pData,
					pParam->nWeek[i], TA_MAType_SMA,
					&nOutBegin[i], &nOutCount[i], dblOut[i]);
			}

			bRet = true;
			int k = i - 1;
			do
			{
				if (nOutCount[k] - pParam->nLastCount<0)
				{
					bRet = false;//数据不完整，不做判断
				}
			} while (--k >= 0 && bRet);

			
			do
			{
				//比较是否满足条件均线向上发散
				
					k = i - 1;
					
					do
					{
						int index = nOutCount[k] - nLastWeeks - 1;
						int index1 = nOutCount[k - 1] - nLastWeeks - 1;
						bRet = (dblOut[k - 1][index1] - dblOut[k][index]>EPS);
						k--;
					} while (k > 0 && bRet);

                if(bRet)
					nLastWeeks++;  //计算累计满足向上发散的周期数

			} while (bRet && bCaclLastWeeks 
				&& nOutCount[i - 1]  - nLastWeeks>=0);
		}
		catch (...)  //抓获多种数据类型的异常对象的话
		{
			bRet = false;
		}
		pParam->nOption = nLastWeeks;
		return nLastWeeks>=pParam->nLastCount;
	}
	//均线空头排列
	static bool  MADOWN(void *pParameters, bool bCaclLastWeeks = true)
	{
		bool bRet = false;
		int nLastWeeks = 0;
		int i, nOutBegin[WEEKS_COUNT], nOutCount[WEEKS_COUNT];
		double dblOut[WEEKS_COUNT][MAX_CACL_COUNT] = { NULL };

		TA_DATA *pParam = (TA_DATA*)pParameters;
		int  nMaxAnalyseWeek = pParam->GetMaxWeek() + pParam->nLastCount + 1;

		if (pParam->nDataCount - nMaxAnalyseWeek < 0 || nMaxAnalyseWeek>MAX_CACL_COUNT)
			return bRet;

		try
		{
			//计算各周期均值  仅计算nMaxAnalyseWeek周期
			for (i = 0; i < WEEKS_COUNT && pParam->nWeek[i]>0; i++)
			{
				TA_MA(pParam->nDataCount - nMaxAnalyseWeek,
					pParam->nDataCount - 1, (double*)pParam->pData,
					pParam->nWeek[i], TA_MAType_SMA,
					&nOutBegin[i], &nOutCount[i], dblOut[i]);
			}

			bRet = true;
			int k = i - 1;
			do
			{
				if (nOutCount[k] - pParam->nLastCount<0)
				{
					bRet = false;//数据不完整，不做判断
				}
			} while (--k >= 0 && bRet);


			do
			{
				//比较是否满足条件均线向下发散
				
				k = i - 1;
				
				do
				{
					int index = nOutCount[k] - nLastWeeks - 1;
					int index1 = nOutCount[k - 1] - nLastWeeks - 1;
					bRet = (dblOut[k][index] - dblOut[k - 1][index1]>EPS);
					k--;
				} while (k > 0 && bRet);
				

				if (bRet)
				{
					nLastWeeks++;  //计算累计满足向下发散的周期数
				}

			} while (bRet && bCaclLastWeeks
				&& nOutCount[i - 1]  - nLastWeeks >= 0);

			

		}
		catch (...)  //抓获多种数据类型的异常对象的话
		{
			bRet = false;
		}
		pParam->nOption = nLastWeeks;
		return nLastWeeks>= pParam->nLastCount;
	}

	static bool  MADOWN_S(void *pParameters,bool bCaclLastWeeks=true)
	{
		bool bRet = false;
		int nLastWeeks = 0;
		int i, nOutBegin[WEEKS_COUNT], nOutCount[WEEKS_COUNT];
		double dblOut[WEEKS_COUNT][MAX_CACL_COUNT] = { NULL };

		TA_DATA *pParam = (TA_DATA*)pParameters;
		int  nMaxAnalyseWeek = pParam->GetMaxWeek() + pParam->nLastCount +1;

		if (pParam->nDataCount - nMaxAnalyseWeek < 0 || nMaxAnalyseWeek>MAX_CACL_COUNT)
			return bRet;

		try
		{
			//计算各周期均值  仅计算nMaxAnalyseWeek周期
			for (i = 0; i < WEEKS_COUNT && pParam->nWeek[i]>0; i++)
			{
				TA_S_MA(pParam->nDataCount - nMaxAnalyseWeek,
					pParam->nDataCount - 1, (float*)pParam->pData,
					pParam->nWeek[i], TA_MAType_SMA,
					&nOutBegin[i], &nOutCount[i], dblOut[i]);
			}

			bRet = true;
			int k = i - 1;
			do
			{
				if (nOutCount[k] - pParam->nLastCount<0)
				{
					bRet = false;//数据不完整，不做判断
				}
			} while (--k >= 0 && bRet);

			
			do
			{
				//比较是否满足条件均线向下发散
				
				k = i - 1;
				
				do
				{
					int index = nOutCount[k] - nLastWeeks - 1;
					int index1 = nOutCount[k - 1] - nLastWeeks - 1;
					bRet = (dblOut[k][index] - dblOut[k - 1][index1]>EPS);
					k--;
				} while (k > 0 && bRet);

				if (bRet)
				{
					nLastWeeks++;  //计算累计满足向下发散的周期数
				}

			} while (bRet && nOutCount[i - 1]  - nLastWeeks >= 0);

			

		}
		catch (...)  //抓获多种数据类型的异常对象的话
		{
			bRet = false;
		}

		pParam->nOption = nLastWeeks;
		return nLastWeeks>= pParam->nLastCount;
	}

	// when  dblIn>=dblLow and dblIn<=dblUp  return true
	static bool DoubleInRange(double dblIn,double dblLow,double dblUp)
	{
		if (dblIn - dblLow >= EPS &&  dblIn - dblUp <= EPS)
			return true;
		else
			return false;

	}
	//RSI均线多头排列
	/*
	RSI - Relative Strength Index 相对强弱指数
	函数名：RSI 名称：相对强弱指数
	简介：是通过比较一段时期内的平均收盘涨数和平均收盘跌数来分析市场买沽盘的意向和实力，
	从而作出未来市场的走势。
	分析和应用：百度百科 维基百科 同花顺学院
	NOTE: The RSI function has an unstable period.
	real = RSI(close, timeperiod=14)
	*/
	static bool  RSIUP(void *pParameters, bool bCaclLastWeeks = true)
	{
		bool bRet = false;
		int  nLastWeeks = 0;
		int i, nOutBegin[3], nOutCount[3];
		
		//考虑扩充为三种不同周期的数据同时分析，类似基于clsoe 的maup
		double dblOut[3][MAX_CACL_COUNT] = { NULL };

		TA_DATA *pParam = (TA_DATA*)pParameters;
		double  dblGate =(double)pParam->nLastCount ;//用作门槛
		int  nMaxAnalyseWeek = pParam->GetMaxWeek() + 4 + 1;//反转分析需要4周期数据

		if (pParam->nDataCount - nMaxAnalyseWeek < 0 || nMaxAnalyseWeek>MAX_CACL_COUNT)
			return bRet;
		
		try
		{
			bRet = true;
			for (i = 0; i < 3 && bRet && pParam->nWeek[i]>0; i++)
			{
				TA_S_RSI(pParam->nDataCount - nMaxAnalyseWeek,
					pParam->nDataCount - 1, (float*)pParam->pData,
					pParam->nWeek[i], &nOutBegin[i], &nOutCount[i], dblOut[i]);
				
				bRet = (DoubleInRange(dblOut[i][nOutCount[i] - 3], dblGate, pParam->nOption)
					&& DoubleInRange(dblOut[i][nOutCount[i] - 2], dblGate, pParam->nOption)
					&& DoubleInRange(dblOut[i][nOutCount[i] - 1], dblGate, pParam->nOption)
					);
			}

			//比较是否满足条件  符合buy条件
			//RSI持续递增且大于dblGate  
			//不能太严格，连续3周期大于dblGate即认为处于可buy状态
			if (bRet)
				nLastWeeks = 0;

			while (bRet && bCaclLastWeeks
				&& nOutCount[i - 1]  - nLastWeeks >= 0)
			{
				//比较是否满足条件均线向上发散
				int k = i - 1;

				do
				{
					int index = nOutCount[k] - nLastWeeks - 1;
					int index1 = nOutCount[k - 1] - nLastWeeks - 1;
					bRet = (dblOut[k - 1][index1] - dblOut[k][index]>EPS) 
						&& DoubleInRange(dblOut[k][index], dblGate, pParam->nOption);
					k--;
				} while (k > 0 && bRet);

				if (bRet)
					nLastWeeks++;  //计算累计满足向上发散的周期数
			} 

				
		}
		catch (...)  //抓获多种数据类型的异常对象的话
		{
			bRet = false;
		}

		pParam->nOption = nLastWeeks;
		return nLastWeeks>=3;
	}

	//RSI均线空头排列
	static bool  RSIDOWN(void *pParameters, bool bCaclLastWeeks = false)
	{
		bool bRet = false;
		int  nLastWeeks=0;
		int i, nOutBegin[3], nOutCount[3];

		//考虑扩充为三种不同周期的数据同时分析，类似基于clsoe 的maup
		double dblOut[3][MAX_CACL_COUNT] = { NULL };

		TA_DATA *pParam = (TA_DATA*)pParameters;
		double  dblGate = (double)pParam->nLastCount;//用作门槛
		int  nMaxAnalyseWeek = pParam->GetMaxWeek() + 4 + 1;//反转分析需要4周期数据

		if (pParam->nDataCount - nMaxAnalyseWeek < 0 || nMaxAnalyseWeek>MAX_CACL_COUNT)
			return bRet;

		try
		{
			bRet = true;
			for (i = 0; i < 3 && bRet && pParam->nWeek[i]>0; i++)
			{
				TA_S_RSI(pParam->nDataCount - nMaxAnalyseWeek,
					pParam->nDataCount - 1, (float*)pParam->pData,
					pParam->nWeek[i], &nOutBegin[i], &nOutCount[i], dblOut[i]);

				//比较是否满足条件  符合sell条件
				//RSI持续大于dblGate 认为是卖出时机  
				bRet = (   dblOut[i][nOutCount[i] - 3] - dblGate >= EPS
						&& dblOut[i][nOutCount[i] - 2] - dblGate >= EPS
						&& dblOut[i][nOutCount[i] - 1] - dblGate >= EPS  //数据递减
					);
			}

			if(bRet)
				nLastWeeks = 3;

			while (bRet && bCaclLastWeeks
				&& nOutCount[i - 1] - nLastWeeks >= 0)
			{
				//比较是否满足条件均线向上发散
				int k = i - 1;
				
				do
				{
					int index = nOutCount[k] - nLastWeeks - 1;
					bRet = (dblOut[k][index]-dblGate>=EPS);
					k--;
				} while (k > 0 && bRet);

				if (bRet)
					nLastWeeks++;  //计算累计满足向上发散的周期数
				
			}


		}
		catch (...)  //抓获多种数据类型的异常对象的话
		{
			bRet = false;
		}

		pParam->nOption = nLastWeeks;
		return nLastWeeks>=3;
	}

	// MACD金叉
	/*
	MACD - Moving Average Convergence/Divergence
	函数名：MACD
	名称：平滑异同移动平均线
	简介：利用收盘价的短期（常用为12日）指数移动平均线与长期（常用为26日）
	指数移动平均线之间的聚合与分离状况，对买进、卖出时机作出研判的技术指标。
	macd（DIF）, macdsignal（DEA）, macdhist = MACD(close, fastperiod=12, slowperiod=26, signalperiod=9)
		
	买卖原则为：
	macdhist=DIF-DEA均为正(金叉)，买入信号参考。
	macdhist=DIF-DEA均为负（死叉），卖出信号参考。
	信号灵敏度低，出现翻转后signalperiod-1周期后才能检测到
	*/
	static bool   MACDGold(void *pParameters,bool bCaclLastWeeks=false)
	{
		bool bRet = false;
		int nLastWeeks = 0;
		int nOutBegin, nOutCount;
		double dblOut[3][MAX_CACL_COUNT] = { NULL };

		TA_DATA *pParam = (TA_DATA*)pParameters;
		int  nMaxAnalyseWeek = pParam->GetMaxWeek() + pParam->nLastCount+1 ;

		if (pParam->nDataCount - nMaxAnalyseWeek < 0 || nMaxAnalyseWeek>MAX_CACL_COUNT)
			return bRet;

		try
		{
			//pParam->nDataCount - nMaxAnalyseWeek
			TA_S_MACD(0,
				pParam->nDataCount - 1, (float*)pParam->pData,
				pParam->nWeek[1], pParam->nWeek[2], pParam->nWeek[0],
				&nOutBegin, &nOutCount, dblOut[0], dblOut[1], dblOut[2]);

			
			//比较是否满足条件  符合金叉条件
			//macdhist持续向上发散、不关注数据符号反转
			
			do
			{
				bRet = (   dblOut[2][nOutCount - 4-nLastWeeks]>= EPS
					&& dblOut[2][nOutCount - 3 - nLastWeeks] >= EPS
					&& dblOut[2][nOutCount - 2 - nLastWeeks] >= EPS
					&& dblOut[2][nOutCount - 3 - nLastWeeks]- dblOut[2][nOutCount - 4 - nLastWeeks]>EPS
					&& dblOut[2][nOutCount - 2 - nLastWeeks] - dblOut[2][nOutCount - 3 - nLastWeeks]>EPS
					&& dblOut[2][nOutCount - 1 - nLastWeeks]- dblOut[2][nOutCount - 2 - nLastWeeks]>EPS);
			
				nLastWeeks++;
			} while (bRet && nOutCount - 4 - nLastWeeks >= 0);

			pParam->nOption = nLastWeeks;
		}
		catch (...)  //抓获多种数据类型的异常对象的话
		{
			bRet = false;
		}

		return nLastWeeks>1;
	}

	static bool   MACDDead(void *pParameters, bool bCaclLastWeeks = false)
	{
		bool bRet = false;
		int nLastWeeks = 0;
		int nOutBegin, nOutCount;
		double dblOut[3][MAX_CACL_COUNT] = { NULL };

		TA_DATA *pParam = (TA_DATA*)pParameters;
		int  nMaxAnalyseWeek = pParam->GetMaxWeek() + pParam->nLastCount + 1;

		if (pParam->nDataCount - nMaxAnalyseWeek < 0 || nMaxAnalyseWeek>MAX_CACL_COUNT)
			return bRet;

		try
		{
			TA_S_MACD(pParam->nDataCount - nMaxAnalyseWeek,
				pParam->nDataCount - 1, (float*)pParam->pData,
				pParam->nWeek[1], pParam->nWeek[2], pParam->nWeek[0],
				&nOutBegin, &nOutCount, dblOut[0], dblOut[1], dblOut[2]);

			//比较是否满足条件  符合金叉条件
			//macdhist持续递减、不关注数据符号反转
			
			do
			{
				bRet = (dblOut[2][nOutCount - 3- nLastWeeks]>0.0
					&& dblOut[2][nOutCount - 2- nLastWeeks]>0.0
					&& dblOut[2][nOutCount - 1- nLastWeeks]>0.0
					&& dblOut[2][nOutCount - 3- nLastWeeks] - dblOut[2][nOutCount - 4- nLastWeeks]>EPS
					&& dblOut[2][nOutCount - 2- nLastWeeks] - dblOut[2][nOutCount - 3- nLastWeeks]>EPS
					&& dblOut[2][nOutCount - 1- nLastWeeks] - dblOut[2][nOutCount - 2- nLastWeeks]>EPS);
				
				nLastWeeks++;

			} while (bRet && nOutCount - 4 - nLastWeeks>=0);

			pParam->nOption = nLastWeeks;

		}
		catch (...)  //抓获多种数据类型的异常对象的话
		{
			bRet = false;
		}

		return nLastWeeks>1;
	}
	
};


