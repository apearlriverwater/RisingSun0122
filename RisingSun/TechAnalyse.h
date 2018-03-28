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
�ʽ������������С��80h��������̬�ƣ�����80h���������̬��
���ھ��߽����ж�
01  ����
02  ��������  FASTIN
03  ��������  SLOWIN
04  ��������  FASTOUT
05  ��������  SLOWOUT
06  ��ת��    IN2OUT
07  ��ת��    OUT2IN

*/
enum  CAPITAL_FLOW {
	
};

//SARָ��ʵ�ʾ������������
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
	���������ʽ�仯����������ʽ�����һ���ͺ���
	1�����������ʽ�����Ϊ��ͷ�����������������������ܴ��ڷ�ת��
	   �����ۼ��ʽ��ͷ�Ҵ�������0������ȷ�Ķ�ͷ���ƣ�
	*/
	CACL_FLOW_MAIN_DELTA,  //�����ʽ���������
	CACL_FLOW_MAIN_TOTAL,  //�����ʽ�仯����
	CACL_FLOW_SMALL_DELTA,
	CACL_FLOW_SMALL_TOTAL,

	FLOWREVERSE ,
	FASTIN ,
	SLOWIN ,
	FASTOUT,
	SLOWOUT ,
	IN2OUT ,  //���ȶ�״̬
	OUT2IN,  //���ȶ�״̬
	FLOWUP ,
	FLOWDOWN,
	FLOWTOTALUP,
	FLOWTOTALDOWN,
	FLOWNOCHANGED


};

//����TALIB ���м�������
typedef  bool(*TA_FUNC_TYPE)(void*,bool);
typedef struct tagTA_FUNCTION
{
	TA_FUNC_TYPE pfTA;	//��������������ڵ�ַ
	void *pParameters;	//�������������������ͻ��Զ�������
}TA_FUNCTION;

typedef struct tagTA_DATA
{
	void	*pData, *pData1;		//�����������ݼ�����  �ɵ������趨ʵ�ʵ��������ͣ�float��double
	int		nDataCount, nLastCount;//���������������������������
	
	/*
		nOption  ��ѡ��
		SAR����ƫ����  ָ�����ʱ����High��Lowƫ�Ƽ��㣬���ٶ��ڲ������ź���� 
		MainFlow ������������
				1--���������ʽ�仯���
				2--���������ʽ��ۼ����
				3--����ɢ���ʽ�仯���
				4--����ɢ���ʽ��ۼ����
		RSI:UP    �Ͻ���
		    DOWN  �½���
	*/
	int     nOption;           
	//���֧��5�����ڣ�С��1�����ں��ԣ����ݱ����С��������
	//����MACD���������ڵ�ָ�꣬0��1��2�ֱ��Ӧ�̡��С�������
	int     nWeek[WEEKS_COUNT];
	
	//��¼��������������
	int     nTACmdStatus;

	int     nTotalFlow;//��λ��Ԫ
	/*
	  ���������ۼ��ʽ���ʱ����¼���������ڵ������ʽ��������

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
		//��������һ��
		TA_Initialize();
	}

	~CTECHANALYSE()
	{
		TA_Shutdown();
	}

private:
	//�������������б��������������
	
	TA_FUNCTION m_usrLongTaList[TA_COUNT] = { NULL };
	TA_FUNCTION m_usrShortTaList[TA_COUNT] = {NULL};
		

public:
	
	//������ת��Ҳ��ͣ���ת�������������߷�ʽ����ʱ����ͣ���λ���Թ۲������㡣
	//����ͣ��㣨�ֳ�ת���SAR���Ի��εķ�ʽ�ƶ����ʳ�֮Ϊ������ת��ָ�� ��
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
			�ܺܿ��⵽�����߷�ת���������ֺܶ�����еĶ����㣬���ն����Ƹ��Ĵ���
			��dblOut����Ϣ����һ�����ȵ�ƫ�ƴ�������źŵ��ȶ��ԡ�
			����nLastCount�����ź���Ч�Լ��
			�����������ź�׼ȷ�Ⱥܲ�ź�����ʧ�棬���Ͼ��ߵ�ָ���жϡ�
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
				//dblOut[nOutCount - 1]��High Low���ڣ�ά����״����
				pParam->nTACmdStatus = nSARStatus;//�ͳ���ǰ״̬
				bRet = false;
			}
			else
			{
				if (   nSARStatus != SAR_D2U
					&& dblOut[nOutCount - 1] - ((float*)pParam->pData1)[nOutCount - 1]  <= EPS      //��ת��
					&& dblOut[nOutCount - 2] - ((float*)pParam->pData)[nOutCount - 2]  >= EPS
					)
				{
					nSARStatus = SAR_D2U;
					pParam->nTACmdStatus = nSARStatus;
					bRet = true;
				}
				else if (nSARStatus != SAR_U2D
					&& dblOut[nOutCount - 1] - ((float*)pParam->pData1)[nOutCount - 1]  >= EPS    //��ת��  
					&& dblOut[nOutCount - 2] - ((float*)pParam->pData)[nOutCount - 2]  <= EPS
					)
				{
					nSARStatus = SAR_U2D;
					pParam->nTACmdStatus = nSARStatus;
					bRet = true;
				}
				else
				{
					pParam->nTACmdStatus = nSARStatus;//�ͳ���ǰ״̬
					bRet = false;
				}
			}
			
				
		}
		catch (...)  //ץ������������͵��쳣����Ļ�
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

	//��ȡָ���ļ���С#include <sys/types.h>  <sys/stat.h> 
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

	//�����ʽ������������
	//�ʽ����Ʊ仯true������Ϊfasle��pParam->nTACmdStatus�����ʽ���״̬
	static bool  MainCapitalFlowChanged(void *pParameters, bool bCaclLastWeeks = false)
	{
		bool bRet = false;
		static int nStatus = FLOWREVERSE;
		int i;
		double dblOut[WEEKS_COUNT][MAX_CACL_COUNT] = { 0 };
		
		//�����ʽ�����Ϣ
		double dblMainFlow[MAX_CACL_COUNT] = { 0 };

		TA_DATA *pParam = (TA_DATA*)pParameters;

		int  nMaxAnalyseWeek = pParam->GetMaxWeek() + pParam->nLastCount + 1;

		if (   pParam->nDataCount - nMaxAnalyseWeek < 0 
			|| nMaxAnalyseWeek>MAX_CACL_COUNT)
			return bRet;

		try
		{
			CAPITALFLOWSTRUCK *pCapFlow = (CAPITALFLOWSTRUCK *)pParam->pData;

			//�����ۼ��ʽ�����Ϣ
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
			

			/*MainFlow ������������
				1--���������ʽ�仯���
				2--���������ʽ��ۼ����
				3--����ɢ���ʽ�仯���
				4--����ɢ���ʽ��ۼ����*/
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
			
			pParam->nTotalFlow= dblMainFlow [pParam->nDataCount-1]/ 10000;//�����ۼ�ֵ

			TA_DATA      usrFlow;

			usrFlow.nDataCount = min(pParam->nDataCount, MAX_CACL_COUNT);
			memcpy_s(usrFlow.nWeek, sizeof(int)*WEEKS_COUNT, pParam->nWeek, sizeof(int)*WEEKS_COUNT);
			usrFlow.nLastCount = pParam->nLastCount; //�����ʽ��Ƿ��ڶ�ͷ״̬��������
			usrFlow.pData = dblMainFlow;

			//�ʽ���������Ҫ�Ż����
			bRet=MAUP((void*)&usrFlow,true);//�ж������ʽ��Ƿ��ڶ�ͷ״̬
			if (bRet /*&& nStatus != FLOWUP*/)
			{
				pParam->nTACmdStatus = FLOWUP;
				pParam->nOption = usrFlow.nOption;
				nStatus = FLOWUP;
			}
			else
			{
				bRet = MADOWN((void*)&usrFlow,true);
				if (/*nStatus != FLOWDOWN && */bRet) //�ж������ʽ��Ƿ��ڿ�ͷ״̬
				{
					pParam->nTACmdStatus = FLOWDOWN;
					pParam->nOption = usrFlow.nOption;
					nStatus = FLOWDOWN;
					bRet = true;
				}
				else
				{
					//�ʽ�������ת���У��㷨��ϸ��  todo  20180118
					pParam->nTACmdStatus = nStatus;
					bRet = false;
				}
			}
		
		}
		catch (...)  //ץ������������͵��쳣����Ļ�
		{
			bRet = false;
		}

		return bRet;
	}

	//���߶�ͷ����
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
			//��������ھ�ֵ  ������nMaxAnalyseWeek����
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
					bRet = false;//���ݲ������������ж�
				}
			} while (--k >= 0 && bRet);

			//�Ƚ��Ƿ���������  ��ͷ�ж�
			do
			{
				//�Ƚ��Ƿ����������������Ϸ�ɢ
				
				k = i - 1;
				
				do
				{
					int index = nOutCount[k] - nLastWeeks - 1;
					int index1 = nOutCount[k - 1] - nLastWeeks - 1;
					bRet = (dblOut[k - 1][index1] - dblOut[k][index]>EPS);
					k--;
				} while (k > 0 && bRet);

				if(bRet)
					nLastWeeks++;  //�����ۼ��������Ϸ�ɢ��������

			} while (bRet && bCaclLastWeeks
				&& nOutCount[i - 1] - nLastWeeks >= 0);
		}
		catch (...)  //ץ������������͵��쳣����Ļ�
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
			//��������ھ�ֵ  ������nMaxAnalyseWeek����
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
					bRet = false;//���ݲ������������ж�
				}
			} while (--k >= 0 && bRet);

			
			do
			{
				//�Ƚ��Ƿ����������������Ϸ�ɢ
				
					k = i - 1;
					
					do
					{
						int index = nOutCount[k] - nLastWeeks - 1;
						int index1 = nOutCount[k - 1] - nLastWeeks - 1;
						bRet = (dblOut[k - 1][index1] - dblOut[k][index]>EPS);
						k--;
					} while (k > 0 && bRet);

                if(bRet)
					nLastWeeks++;  //�����ۼ��������Ϸ�ɢ��������

			} while (bRet && bCaclLastWeeks 
				&& nOutCount[i - 1]  - nLastWeeks>=0);
		}
		catch (...)  //ץ������������͵��쳣����Ļ�
		{
			bRet = false;
		}
		pParam->nOption = nLastWeeks;
		return nLastWeeks>=pParam->nLastCount;
	}
	//���߿�ͷ����
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
			//��������ھ�ֵ  ������nMaxAnalyseWeek����
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
					bRet = false;//���ݲ������������ж�
				}
			} while (--k >= 0 && bRet);


			do
			{
				//�Ƚ��Ƿ����������������·�ɢ
				
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
					nLastWeeks++;  //�����ۼ��������·�ɢ��������
				}

			} while (bRet && bCaclLastWeeks
				&& nOutCount[i - 1]  - nLastWeeks >= 0);

			

		}
		catch (...)  //ץ������������͵��쳣����Ļ�
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
			//��������ھ�ֵ  ������nMaxAnalyseWeek����
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
					bRet = false;//���ݲ������������ж�
				}
			} while (--k >= 0 && bRet);

			
			do
			{
				//�Ƚ��Ƿ����������������·�ɢ
				
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
					nLastWeeks++;  //�����ۼ��������·�ɢ��������
				}

			} while (bRet && nOutCount[i - 1]  - nLastWeeks >= 0);

			

		}
		catch (...)  //ץ������������͵��쳣����Ļ�
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
	//RSI���߶�ͷ����
	/*
	RSI - Relative Strength Index ���ǿ��ָ��
	��������RSI ���ƣ����ǿ��ָ��
	��飺��ͨ���Ƚ�һ��ʱ���ڵ�ƽ������������ƽ�����̵����������г�����̵������ʵ����
	�Ӷ�����δ���г������ơ�
	������Ӧ�ã��ٶȰٿ� ά���ٿ� ͬ��˳ѧԺ
	NOTE: The RSI function has an unstable period.
	real = RSI(close, timeperiod=14)
	*/
	static bool  RSIUP(void *pParameters, bool bCaclLastWeeks = true)
	{
		bool bRet = false;
		int  nLastWeeks = 0;
		int i, nOutBegin[3], nOutCount[3];
		
		//��������Ϊ���ֲ�ͬ���ڵ�����ͬʱ���������ƻ���clsoe ��maup
		double dblOut[3][MAX_CACL_COUNT] = { NULL };

		TA_DATA *pParam = (TA_DATA*)pParameters;
		double  dblGate =(double)pParam->nLastCount ;//�����ż�
		int  nMaxAnalyseWeek = pParam->GetMaxWeek() + 4 + 1;//��ת������Ҫ4��������

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

			//�Ƚ��Ƿ���������  ����buy����
			//RSI���������Ҵ���dblGate  
			//����̫�ϸ�����3���ڴ���dblGate����Ϊ���ڿ�buy״̬
			if (bRet)
				nLastWeeks = 0;

			while (bRet && bCaclLastWeeks
				&& nOutCount[i - 1]  - nLastWeeks >= 0)
			{
				//�Ƚ��Ƿ����������������Ϸ�ɢ
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
					nLastWeeks++;  //�����ۼ��������Ϸ�ɢ��������
			} 

				
		}
		catch (...)  //ץ������������͵��쳣����Ļ�
		{
			bRet = false;
		}

		pParam->nOption = nLastWeeks;
		return nLastWeeks>=3;
	}

	//RSI���߿�ͷ����
	static bool  RSIDOWN(void *pParameters, bool bCaclLastWeeks = false)
	{
		bool bRet = false;
		int  nLastWeeks=0;
		int i, nOutBegin[3], nOutCount[3];

		//��������Ϊ���ֲ�ͬ���ڵ�����ͬʱ���������ƻ���clsoe ��maup
		double dblOut[3][MAX_CACL_COUNT] = { NULL };

		TA_DATA *pParam = (TA_DATA*)pParameters;
		double  dblGate = (double)pParam->nLastCount;//�����ż�
		int  nMaxAnalyseWeek = pParam->GetMaxWeek() + 4 + 1;//��ת������Ҫ4��������

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

				//�Ƚ��Ƿ���������  ����sell����
				//RSI��������dblGate ��Ϊ������ʱ��  
				bRet = (   dblOut[i][nOutCount[i] - 3] - dblGate >= EPS
						&& dblOut[i][nOutCount[i] - 2] - dblGate >= EPS
						&& dblOut[i][nOutCount[i] - 1] - dblGate >= EPS  //���ݵݼ�
					);
			}

			if(bRet)
				nLastWeeks = 3;

			while (bRet && bCaclLastWeeks
				&& nOutCount[i - 1] - nLastWeeks >= 0)
			{
				//�Ƚ��Ƿ����������������Ϸ�ɢ
				int k = i - 1;
				
				do
				{
					int index = nOutCount[k] - nLastWeeks - 1;
					bRet = (dblOut[k][index]-dblGate>=EPS);
					k--;
				} while (k > 0 && bRet);

				if (bRet)
					nLastWeeks++;  //�����ۼ��������Ϸ�ɢ��������
				
			}


		}
		catch (...)  //ץ������������͵��쳣����Ļ�
		{
			bRet = false;
		}

		pParam->nOption = nLastWeeks;
		return nLastWeeks>=3;
	}

	// MACD���
	/*
	MACD - Moving Average Convergence/Divergence
	��������MACD
	���ƣ�ƽ����ͬ�ƶ�ƽ����
	��飺�������̼۵Ķ��ڣ�����Ϊ12�գ�ָ���ƶ�ƽ�����볤�ڣ�����Ϊ26�գ�
	ָ���ƶ�ƽ����֮��ľۺ������״���������������ʱ���������еļ���ָ�ꡣ
	macd��DIF��, macdsignal��DEA��, macdhist = MACD(close, fastperiod=12, slowperiod=26, signalperiod=9)
		
	����ԭ��Ϊ��
	macdhist=DIF-DEA��Ϊ��(���)�������źŲο���
	macdhist=DIF-DEA��Ϊ�������棩�������źŲο���
	�ź������ȵͣ����ַ�ת��signalperiod-1���ں���ܼ�⵽
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

			
			//�Ƚ��Ƿ���������  ���Ͻ������
			//macdhist�������Ϸ�ɢ������ע���ݷ��ŷ�ת
			
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
		catch (...)  //ץ������������͵��쳣����Ļ�
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

			//�Ƚ��Ƿ���������  ���Ͻ������
			//macdhist�����ݼ�������ע���ݷ��ŷ�ת
			
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
		catch (...)  //ץ������������͵��쳣����Ļ�
		{
			bRet = false;
		}

		return nLastWeeks>1;
	}
	
};


