#pragma once
class   CStockBlockInfo;

int     g_nAnalysePat = 0;//����ģʽ����
int		g_nStockDownDays = 0; //��ѡ1���ĵ��µ�����
int     g_nStockBufSize=0;       //���ڵ�һ��ķ����Ļ�������С
int     g_nCJDBufSize=0, g_nCZSPZBufSize=0;//�����㡢�������������С

#define  ANALYSEWEEKS  4  
short		*g_nWeekList;

#define     MASHORT 5
#define     MAMID  20
#define     MALONG  30
#define     MAXSTEPDOWN 15  //�׶�������
#define		MAXTRADENUMBER  30  //�������ĵ���������������Զ���ĳֱֲ��

#define	    BUY1STOCKNUMBERS	50  //���1��������
int			g_nMaxHolding  =   10; //����������������ѡ���ĳֱֲ��
/*              g_nStockDownDays    g_nWeekList
    ������  ��       30            10,20,30
    �������ã�       60            15,30,45    
	�������ã�      120            60,90,120 
	�������ã�      240            120,180,240

*/
typedef struct tagAnalysePattern
{
	char sName[8];
	short nStockDownDays;
	short nMaxHolding;//���ֲ���
	short nDownGate;//��������ﵽ���ż�
	short nStep;
	short nWeekList[ANALYSEWEEKS];
}AnalysePattern;

AnalysePattern g_usrAnalysePattern[]=
{
	{"����", 30,10, 3, 1,{  5, 10, 15,0 } },
	{"����", 60,15, 6, 3,{ 15, 30, 45,0 } },
	{"����",120,20, 9, 6,{ 60, 90,120,0 } },
	{"����",240,25,15,12,{120,180,240,0 } }
};


//�µ�����ĩ�˵ı��۷������µ����ȴ���20%�ŷ�����������Ϊ�������ڵĿɶ�������0929   todo
#define		CSTOCKMAXDOWNGATE  20
#define     UPSELLGATE 10    //��ʼ�������������ż�
#define     AUTODOWNSELLGATE 10  //ֹ���ż�
#define		CJDWAITING  5  //�ȴ����������ƻ����5�վ���������
#define     MAX5KS	  200*48	//������200��������5����K��
#define		BSCOUNT		6       //�������������ٹ�6��
//���ڸߵ͵㣬������5��  0-����ߵ͵㣬1��2���ߵ͵㣬�Դ�����
#define     LASTESTHIGHLOWCOUNT 1
#define		TBWEEKS		17
#define     TBPOINTCOUNT  8
#define     ZXHOLDINGCOUNT 20 //��ѡ�ֲֵı��,����ѡ/ƽ�����ɵ�
#define		CZSVARRATE 3      //���ನ���ʣ������˷�Χ����Ϊ�����������������

//������������  ͨ����������K����Ϊ8000��
const int		g_nMaxDataLen = 4096;
const int		g_nMaxStock = 15;
int				g_nUPPERCENT = 15, g_nDOWNPERCENT = 15;
const			short conMAXSTOCK = 30;
short			MAXHOLDDAYS = 45;
int				g_nAnalyseStartDate=-1,g_nAnalyseStopDate = 100;//g_nAnalyseStartDate=-1 ��ʼʱ���������ļ�ȷ��
int				g_nAnalyseStartTime = -1, 
				g_nAnalyseStopTime = -1;//��һ��Ʊ����ʱ�Ŀ�ʼʱ�䣬��g_nAnalyseStartDate��Ӧ
float           *g_fbuf1 = NULL,
				*g_fbuf2 = NULL,
				*g_fbuf3 = NULL;
float           *g_fMA1 = NULL,
				*g_fMA2 = NULL,
				*g_fMA3 = NULL;
long	*g_l1 = NULL, *g_l2 = NULL, *g_l3 = NULL;

typedef struct tagStockCodeName
{
	char		*strName;
	unsigned int unCode;
}StockCodeName;

	/*
	��֤��ָ,999999
	��֤50,000016
	����300,000300
	��֤180,1000010
	��֤380,1000009
	��֤100,1000903
	��֤500,1000905

	��֤��ָ,399001
	��ҵ��,399006
	��С��,399005
	��֤100R,0399004
	��֤300,0399007
	��С300,0399008
	��֤��ָ,0399106

	ͨ������ҵ
	�������  //880493
	����880471��֤ȯ880472���ز�880482����ɫ880324��ú̿880301,����880318
	*/

	StockCodeName g_usrStockIndexCodeName[] =
	{
		{ "��֤��ָ", 1000001 },
		{ "��֤180", 1000010 },
		{ "����300", 1000300 },
		{ "��֤��ָ", 399106 },
		{ "��ҵ��", 399006 },
		{ "��С��", 399005 },
		{ "��С300", 399008 },
		{ "��֤300", 399007 },
		{ "��֤50", 1000016 },
		{ "��֤380", 1000009 },
		{ "��֤100", 1000903 },
		{ "��֤500", 1000905 },
		{ "��֤��ָ", 399001 },
		{ "��֤100R", 399004 },

		{ "", 0 }
	};



void	LogBSFile(char *FilePath, char *msg);
long	GetFileSize(char* strFile);
int		CopyStock2Block();
bool	CheckCodeQX(int nCode);
void	ResultOut(float **pfOUT, int nDataIndex, float fData);
bool	IsSTStock(int nCode);
int		ReadSTBLOCK(char *strPath);
int		TimeDiff(int d1, int d2);
int		ReadZXCC(char *strPath);
void	Load1Buy();
bool	IsFileExist(char *strFile);
bool	Buy1CaclReal(int nStopDate, int nStopTime);
void	Save1BuyStock();
int		ReadQX(int);
void	SaveHoldingStock();
bool	CheckQX(float *fGiven, float *fGain, float *fBuyCount, float *fBuyPrice,
	int *nDateLarge, int *nDateSmall, int nStopDate, int nStartDate, int nCode);
void	CaclQuanXiPrice(float fGiven, float fGain, float fBuyCount, float fBuyPrice, float *fPrice);
void	MakeStockDateTime(int nDataLen,int *nDate,int *nTime);
void	LogFile(char *FilePath,char *msg);
int		DateAdd(int nYMD,int g_nAnalyseStopDate)	;
bool	IsAnalyse(int nCode,int nMode);
void	InitApp();
bool	SortDownStock(int nCode, int nDownWeeks, int nDownRate, short *nWeekList);

void	WriteLogHead(int nStep);

typedef struct tagStockInfo
{
	unsigned short	nYmd, nMin;
	float		fOpen, fHigh, fLow, fClose;
	float	fAmount;
	int		nNumber;
	int		ForUsed;

	int Date()
	{
		return nYmd % 2048 + (nYmd / 2048 + 104) * 100;
	}

	int Time()
	{
		return (nMin / 60) * 100 + nMin % 60;
	}
}StockInfo;
StockInfo *g_pusrNowKData = NULL;

//�����K���ļ���Ϣ,��Ҫ���ڶ���ʷ����/ͨ��������/ʵʱ���ݵ���ʼʱ��/����������(��48��ת��Ϊ����������)
typedef struct tagC5MinKFileInfo
{
	int nStartYmd,nStartMin, nStopYmd,nStopMin; //ʵ�����ݵ���ֹ����ʱ��
	long  lCount;  //����������(��48��ת��Ϊ����������)
}C5MinKFileInfo;



typedef struct tagBSInfo
{
	unsigned short	nYmd,nMin,nWeek,nK;
	//nMode:����ָ�꣬��MACD/DIFF DEA ���ߣ��ֲ����ڵ���ֹ��ֹӯ��,nType �������ݣ��� �������á����౳�ۡ����߱���
	short	nMode,nType,nUpPercent,nDownPercent;
	float	fBuySellPrice,fClose;
	float	fCJDMaxDownPercent,fDownPrice;//����Ч�������λ���س��������س�ֹ���λ�����ڼ�����
	unsigned short	nMustSellYMD,nAmount;// nMustSellYMD������ֵ����ڣ��������м䲻���׵�����	nAmount��������
}BSInfo;

//top��botton�������Ʊ������������Ӧ�ļ�ֵ����ֵ���������̼ۡ���߼ۡ�MACD��
typedef struct tagDayTrends
{
	BSInfo	usrBSPoint[BSCOUNT];
	short	nWeekList[ANALYSEWEEKS];//��¼���ж̾��߾����ǵ���Ч����
	unsigned short		nBSIndex;//��Ч��������
	int		nValue;//���ݵ�����������խ����������Ȩ�أ���Ϊ�������������
	int		nDownRate;//��ߵ�����ĵ���
	int		nCode,nLastetBuyYmd;//���һ����������
	bool	bDown,bBSChanged; 
}DayTrends;

//��ѡ�ֲ�
typedef struct tagZXHolding
{
	char strName[60];//��ѡ�������
	int  nCode[20]; //��ϱ��
}ZXHolding;
ZXHolding		g_usrZXHolding[ZXHOLDINGCOUNT];  //���֧��10����ѡ�ֲ����
#define    STNUMBERS  80
int		g_nSTlist[STNUMBERS] = {1};//ST�������б�
  

//��ȡͨ���ŵ�����ȨϢ�ļ�,��ȡ��10��Ϊ��λ����ת��/�ֺ�/��ɺ���ɼ���Ϣ,
//���ݶ�֮��ͨ��0x09�ָ�,��������0x09���������ֶ�ȱʧ,���ݼ�¼֮��ķָ���0x0d,0x0a
//300381	�����	     20161018	20.00	1.000
//002456	ŷ�ƹ�	     20161202                    - 5.0	102797.9
//300547	�����Ƽ�	 20161202		10.000
typedef struct tagStockQuanXi
{
	INT32	nCode, nDate;
	float	fGiven, fGain, fBuyCount, fBuyPrice;
}StockQuanXi;

StockQuanXi  *g_pStockQuanXi=NULL;

//1�����ݽṹ  ��㽵���������ԽС�����ֵԽ��
class CDayTrends
{
public:
	DayTrends usrBuy1List[BUY1STOCKNUMBERS];
	int nBuy1Count;
	//DayTrends usrBuy1ListUp[BUY1STOCKNUMBERS];
	//int nBuy1UpCount;
	int	nCurBuyIndex;
	
public:

	CDayTrends(void )
	{
		
		for (int i = 0; i < BUY1STOCKNUMBERS; i++)
		{
			memset(usrBuy1List[i].nWeekList, 0, ANALYSEWEEKS * sizeof(short));
		}
			
	}

	//�����Ծ�������δ��׼����Ļ����ϣ�
	//��ͬһ���������µı�İ���������ĵ������н�������
	void	SortByDownRate()
	{
		int  nValue = 0,j=0;
		for (int i = 0; i < nBuy1Count; i++)
		{
			nValue = usrBuy1List[i].nValue;
			j = i+1;
			//������������ǰ��
			while (nValue == usrBuy1List[j].nValue && j<nBuy1Count)
			{
				if (usrBuy1List[i].nDownRate < usrBuy1List[j].nDownRate)
				{
					Swap(i, j);
				}
				j++;
			}
		}
	}
//��DayTrends g_usrDayTrends.usrBuy1List����ı��BUY1STOCKNUMBERS���������������ŵ�ǰ��
//todo 2017-02-19���Ż�����ֵ������,���ֶ������������ʱ�����������ѡ
	void	Swap(int i,int j)
	{
		DayTrends tmp;
		if (i!=j && i>=0 && j>=0)
		{
			memcpy(&tmp, &usrBuy1List[i], sizeof(DayTrends));
			memcpy(&usrBuy1List[i], &usrBuy1List[j], sizeof(DayTrends));
			memcpy(&usrBuy1List[j], &tmp, sizeof(DayTrends));
		}
	}
	void	Buy1StockSort()
	{
		int j=0;
		for(int i=0;i<BUY1STOCKNUMBERS-1;i++)
		{
			if(usrBuy1List[i].bBSChanged ==true)
			{
				if (i != j)
				{
					Swap(i,j);
				}
				j++;
			}
		}
		nCurBuyIndex=0;
	}

	BSInfo* Buy1Get()
	{
		if(usrBuy1List[nCurBuyIndex].bBSChanged ==true)
			return &usrBuy1List[nCurBuyIndex++].usrBSPoint[0];
		else
			return NULL;

	}
};
CDayTrends  g_usrDayTrends;

typedef struct tagCJDInfo
{
	int     nDateTime;//����ʱ��
	int		nPlace, nP1, nP3;   //λ��  nP1,nPlace,nP3
	char    nStatus;   //-1 �͵㣬���  1 ��㣬����
	char    nNewHighLow;//-1 �¸ߣ�  1 �µͣ�0��ͨ
	bool    bIsUp;	   //�����߶�true������Ϊ�µ�  
	float   fLineLen;  //�߶γ��ȣ���ʱ�ü۸���ʾ
	int	    nLineBi;   //�߶γ��ȱ�
}CJDInfo;
CJDInfo			*g_pusrCJD = NULL;

//����Ϣͬʱ�����г��¶ȳ�������
typedef struct tagRefStockInfo
{
	unsigned short	nYmd,nMin;
	int				nIndex[7]; 
	float			fAmount[7];
}RefStockInfo;

//top��botton�������Ʊ������������Ӧ�ļ�ֵ����ֵ���������̼ۡ���߼ۡ�MACD��
typedef struct tagTBPoint
{
	int		nIndex; //����������������������
	float	fValue; //�����������������Ӧ��ߵ����͵�
	float	fEnergy; //�������Ӧ����
	int     nDate; //���ڣ����ݷ������ʹ��
}TBPoint;

 typedef struct tagStockDayInfo
{
	int		nYmd;
	int		fOpen,fHigh,fLow,fClose; 
	int		fAmount;
	int		nNumber;
	int		ForUsed;
}StockDayInfo;

//nMode:����ָ�꣬��MACD/DIFF DEA ���ߣ��ֲ����ڵ���ֹ��ֹӯ��,nType �������ݣ��� �������á����౳�ۡ����߱���
enum BUYSELLMODE{
	BSMODE_MACD=101,BSMODE_DIFF=102,BSMODE_DEA=103,
	BSMODE_STOPUP=104,BSMODE_STOPDOWN=105,BSMODE_MAXHOLDWEEKS=106,BSMODE_SECOND=107,BSMODE_THIRD=108
};
enum BUYSELLTYPE{
	BSTYPE_STOPUP=1,BSTYPE_STOPDOWN=2,BSTYPE_MAXHOLDWEEKS=4,BSTYPE_PZBC=8,
	BSTYPE_ZSBC=16,BSTYPE_JXBC=32,BSTYPE_2BUY=64,BSTYPE_3BUY=128,
	BSTYPE_JXDOWN = 256,  //���ж̾����µ�
	BSTYPE_STEPUP=512     //ƽ̨ͻ��
};

enum WORKMODE{
	WORKMODE_DEFAULT = 0, WORKMODE_REAL = 1, WORKMODE_TRAINING = 2,
	WORKMODE_DEBUG=3, WORKMODE_BLOCK=4
};


//todo  ���Ż�20170212
string	g_sRefIndex[] =
{ "sz\\fzline\\sz399001.lc5",  /*  ����ָ */
"sz\\fzline\\sz399006.lc5", /*  �ҵ�� */
"sz\\fzline\\sz399300.lc5", /*  ��֤300 */
"sh\\fzline\\sh000010.lc5", /*  ��֤180 */
"sh\\fzline\\sh000300.lc5", /*  ��֤300 */
"sz\\fzline\\sz399005.lc5",  /*  ����С�� */
"sh\\fzline\\sh000001.lc5", /*  ��֤��ָ */
""
};

string	g_sRefName[] =
{"����ָ ",
"�ҵ��",
"��֤300",
"��֤180",
"��֤300",
"����С��",
"��֤��ָ",
""
};

const int g_nMinCount = 240;//���ڷ��Ӽ�¼��ĵĲ�������240��

//��ǰ���ڴ����ָ�������ÿ��ʹ��ǰtdxӦ�ȵ���StoreMarketCTA
int   g_nCurrentMarketIndex = -1;

//����ģʽ��ʵʱ��أ�ѵ��ѧϰ��������
WORKMODE g_nWorkMode = WORKMODE_DEFAULT;


//������ʵʱ����
//bool g_bRealMode = false;
//true  ������ģʽֱ����Ӧ�ó�����ã� false ��ͨ���ŵ���
bool	g_bAnalyseMode=false;
//��������������ʵʱ����ʱ���ط���̫������  ������Ϊͨ���ŵ�DLLʹ��ʱ������
int    g_nCaclDataStartPoint=0;
//��������
int    g_nWeek=0;
int		g_nCurrentStockDate=0,g_nCurrentStockTime=0;//��ǰ����Ĺ�Ʊʱ��   tdx����������������ʵʱ���ݵĶ�Ӧʱ��

//��ǰ�������롢����������
unsigned int    g_nCurrentStockCode=0;
float			g_fCurrentStockLB=1.0;

float *g_fMAShort, *g_fMALong;

void	SelectStock2Sell();
void	Get5MinKFileInfo(string path, C5MinKFileInfo *usrFileInfo);

int			 g_nMACDLong=26,g_nMACDMid=12,g_nMACDShort=9;

//g_sTDXPathͨ��������Ŀ¼,g_sTDXHisDataPathͨ����5������ʷ����Ŀ¼,���߽�ϲ������������ʵʱ���
string g_sTDXPath= "E:\\02soft\\new_tdx\\vipdoc\\";  //ͨ��������Ŀ¼
string g_sTDXHisDataPath ="E:\\01finance\\new_tdx2012-2016\\vipdoc\\"; 

string g_sHisDataPathList[] = { "E:\\01finance\\new_tdx2012-2016\\vipdoc\\",//0 ���Է�������ʷ����
                                "E:\\02soft\\new_tdx\\vipdoc2014-2016\\" };//  1 ʵʱ��ص���ʷ����Ŀ¼
//"E:\\02soft\\99zd_gfzq\\vipdoc2014-2016\\"
// "E:\\02soft\\new_tdx\\vipdoc2014-2016\\";// "E:\\01finance\\vipdoc2012-201609\\";  // "E:\\02soft\\new_tdx\\vipdoc2014-2016\\";//"E:\\01finance\\vipdoc2012-201609\\";  //ͨ����5������ʷ����Ŀ¼,���߽�ϲ������������ʵʱ���
//"E:\\monitor\\""E:\\02soft\\new_tdx\\";E:\monitor  E:\\02soft\\99zd_gfzq\\"

//5����K���ļ�����:ͨ����,��ʷ����,ʵʱ���� ��ֹ����ʱ��,��������,�ڳ�ʼ��ʱ��ȡ������
C5MinKFileInfo g_usrTDX5KFileInfo, g_usrHis5KFileInfo, g_usrReal5KFileInfo;//

string	g_sMinute5[2]={"sz\\fzline\\*.lc5","sh\\fzline\\*.lc5"};
string	g_sDayFile[2]={"sz\\lday\\*.day","sh\\lday\\*.day"};
string  g_sMailContent="",g_sMailTitle="";  //��¼�������䷢�͵�BS��Ϣ

char	g_sLogFile[250]={0},g_sHolding[250]={0},g_sBSLog[250]={0},g_sOneBuy[250]={0};
char	g_sLogPath[] = { "log\\" }, 
		g_sQuanxiPath[] = { "quanxi\\" },
		g_sSTBlock[] = { "cfg\\ST���.EBK" },
		g_sRealMonitor[] = { "cfg\\ʵʱ���.EBK" },  //���µ�1����
		g_sHS300[] = { "cfg\\hs300.EBK" },
		g_sYS50[] = { "cfg\\����50.EBK" },
	    g_sCYB[] = { "cfg\\��ҵ��.EBK" }, 
	    g_sZXB[] = { "cfg\\��С��.EBK" }, 
		g_sZXC[] = { "cfg\\��С��.EBK" },
		g_sHYLT[] = { "cfg\\��ҵ��ͷ.EBK" },
		g_sSZ180[] = { "cfg\\��֤180.EBK" },
		g_sYQ100[] = { "cfg\\����100.EBK" },
		g_sCY300[] = { "cfg\\��ҵ300.EBK" },
		g_sZX300[] = { "cfg\\��С300.EBK" },
		g_sETF[] = { "cfg\\etf.txt" },
		g_sDPLC[] = { "cfg\\��������.EBK" },
		g_sZZ100[] = { "cfg\\��֤100.EBK" },
		g_sZZ300[] = { "cfg\\��֤300.EBK" },
		g_sSZ300[] = { "cfg\\��֤300.EBK" };

char	g_sTradePath[]={"trade\\"},
		g_sTradeFile[]={"trade\\trade.dat"},
        g_sHoldingStock[] = { "trade\\holding.dat" },
		g_s1BuyStock[] = { "trade\\1Buy.dat" },
		g_sDayTrends[] = { "trade\\DayTrends.dat" },
		g_sRealPath[]={"real\\"},
		g_sRealCfg[] = { "cfg\\" },
		g_sRealMail[] = { "trade\\realmail.txt" };

typedef struct tagCZSPZInfo
{
	int     nVarRate;//����������Ĳ�����
	int		nStart, nStop;//��ʼ���ڽ�������  ������
	bool    bIsZS; //0���� 1����
	int		p1, p2;//λ��  ��ʼ������λ��
	bool	bIsUp; //true��ʾ����false��ʾ��
	float   fMaxLow, fMinHigh, fLow, fHigh;  //������ߡ���ͼ۵ļ�ֵ,��������ߡ����ֵ

    //����������״̬������������ʱ�ж��Ƿ��¸߻��µͣ������������ʱ�ж��Ƿ���ֱ���
    //0  û�в�����ֵ����ͨ��
    //1 ���µͣ�2���µ���MACD���ۣ�3 ���µ���DIF����,4���µ���DEA����
    //-1 ���¸ߣ�-2���¸���MACD���ۣ�-3 ���¸���DIF����, -4���¸���DEA����
	int     nStatus;

	//��������������										 
	float   Mid()
	{
		return (fLow + fHigh) / 2;
	}

	//�������ನ���ʣ�����������ߵİٷֱȣ�������=��fLow+ fHigh��/2
	int  VarRate(StockInfo *pNowKData,CJDInfo *usrCJD)
	{
		nVarRate = pNowKData[usrCJD[p1].nPlace].nYmd;
		nStart = (nVarRate / 2048 + 104) * 10000 + nVarRate % 2048;
		nVarRate = pNowKData[usrCJD[p2].nPlace].nYmd;
		nStop = (nVarRate / 2048 + 104) * 10000 + nVarRate % 2048;

		nVarRate = VarRate(fHigh, fLow);
		return nVarRate;
	}

	//����ָ�����¸ߡ��µͼ������ನ���ʣ�����������ߵİٷֱȣ�������=��fLow+ fHigh��/2
	//���������Ƿ���Ч�жϣ����������
	int  VarRate(float fNewHigh, float fNewLow)
	{
		int tmp;
		if (Mid() != 0)
			tmp = (int)(100 * (fNewHigh - fNewLow) / Mid());
		else
			tmp = 0;

		return tmp;
	}

}CZSPZInfo;
CZSPZInfo		*g_pusrCZSPZ = NULL;

//���߶�����  todo 0818
typedef struct tagCLineInfo
{
	bool	bIsUp, bPeak, bBotton; ////true��ʾ����false��ʾ��
	int		p1, p2;//λ��  ��ʼ����λ��
	float   fLow, fHigh;  //�߶���ߡ���ͼ�
}CLineInfo;


class CNowTrends;


int	g_nMaxStockDateListCount = 0;
RefStockInfo	*g_usrStockDateList = NULL;


const short		conCaclCJD=10,conSendCFX2TDX=20,conSendXD2TDX=30,conCaclCZSPZBC=40,conCaclCZSPZ=50;	
int		CreateStockDateByGeneralDate(int nDate);
int		CreateStockDate(int nDate);

void	Log(char *msg);
void	LogFile(char *FilePath,char *msg) ;

void	Training(int nStopDate, int nStopTime,int nStep);
void	MakeStockDateTime(int nDataLen,int *nDate,int *nTime);

//����ǰ�ֲ�������浽�ļ�
void	SaveTradeInfo(int)	;
void	SaveHolding2BSLog();

//��ȡ��ǰ�ֲ����
void	ReadTradeInfo()	 ;
void    WriteTradeInfo();
bool	StockInTrade(CNowTrends *ptrTrends,int nCode);
void	CheckAutoSell(int nDataLen,StockInfo *ptrStockInfo,int nWeek);
void	ReadDateList4Real(int nDays);
void	ReadDateList4Training(int nStopDate, int nStopTime);
int		GotoStopDateTime(int nDataLen, int nStopDate, int nStopTime, StockInfo *p5MinKData);
int		GotoStopDateTime(int nDataLen,int nStopDate,int nStopTime,StockInfo *pStockInfo,int nWeek);
int		GotoStopDateTime(int nDataLen, int nStopDate, int nStopTime, tagRefStockInfo *pStockInfo, int nWeek);
int		SetupParameters(int argc, _TCHAR* argv[],bool *Debug);
void	SetBlockParameters(_TCHAR* argv);
void	Init();

void	MakeStockDateTime(int nDataLen,int *nDate,int *nTime);
int		DateDiff(int d1,int d2);
void	GetCurrentDateTime(int *Date,  int *Time);
bool	Buy1Cacl(int nStopDate,int nStopTime);
bool	Buy2SellxCacl(int nStopDate,int nStopTime);
bool	Buy2SellxCaclReal(int nStopDate, int nStopTime);
int		ReadReal5MinKData(WORKMODE nReal, string path, StockInfo *usrTmp,int);
int		Read5MinKData4Real(string path, int nCode, StockInfo *pStockMinuteInfo,
	        int nMaxSize,int nReadDays, int nStopDate, int nStopTime);
int  Read5MinKData4Training(string path, string HisPath, int nCode, StockInfo *pStockMinuteInfo, int nMaxSize,
	int nReadDays, int nStopDate, int nStopTime);
int		ReadHis5MinKData4Real(string path, int nCode, StockInfo *pStockMinuteInfo, int nMaxSize,
			long nStart5MinPlace, int nStopDate, int nStopTime);
int RealMonitor(int	nStep);

bool IsFocusing(StockInfo *p,int len,CNowTrends *);
bool IsRSIBuy(StockInfo *p,int len,CNowTrends *);
bool IsATRBuy(StockInfo *p,int len,CNowTrends *);
bool IsATRSell(StockInfo *p,int len,CNowTrends *);



	typedef BOOL(*pRulerFUNC)(StockInfo *,int,CNowTrends *); //����cNowTrends�õĹ�������ָ������
	pRulerFUNC m_pRulerFunction[]= { 
		/*(pRulerFUNC)&IsFocusing ,*/
		(pRulerFUNC)&IsRSIBuy,
		(pRulerFUNC)&IsATRBuy,
		NULL
	};

class	CNowTrends
{
public:
#define		CONTINUEDOWNWEEKS  10 //5�վ�����10�վ�����������������������������ǰ�������

	int		nHoldingAmount;
	bool	bDayUp, bBSChanged;//��¼�ֱֲ�����߼����Ƿ�����̬�ƣ�����С���ڷ���   ������仯
	//����ʵ�ʶ�̬�����������Ϣ���� mTop�ɴ�С  mBotton��С����(��������߼���ͼ�)
	TBPoint	mTop[TBPOINTCOUNT], mBotton[TBPOINTCOUNT];
	//δ�ֱֲ�ı�������������������ֵ��Сֵ��������MACD DEA DIFF ���������۸�仯���ۼ�ֵ
	//�ֱֲ�ı����״�������������ֵ��Сֵ��������MACD DEA DIFF ���������۸�仯���ۼ�ֵ
	//��¼�������������Ӧ����  �����������ܷ�ֵû��һһ��Ӧ��ϵ
	TBPoint   mMaxEnergy[TBPOINTCOUNT], mMinEnergy[TBPOINTCOUNT];

	BSInfo	usrBuy[BSCOUNT];	   //��һ����˳���������Ϣ
	BSInfo	usrSell[BSCOUNT];

	//����ʱ�����ֹ��fAutoDownSellPrice��ֹӯ�۸�fAutoUpSellPrice�������ż�f2BuyGate��f3BuyGate������
	float	fAutoUpSellPrice, fAutoDownSellPrice, f2BuyGate, f3BuyGate;
	//����ʱ�趨BS������ĸߵ͵㣬�����ж��Ƿ���ƻ����ƽ��ڸߵ͵�
	TBPoint   m_usrLastestHigh[LASTESTHIGHLOWCOUNT], m_usrLastestLow[LASTESTHIGHLOWCOUNT];

	//nStatus >0 �ս��ڵ׷��ͣ�<0�ս��ڶ�����  = �޷���; nNewHighLow>0 	���¸�,<0���µ�  =0���¸��µ�
	short				nStatus, nNewHighLow;
	unsigned short		nLatesBuyYmd, nFirstSellCJD;

	short				nBuyIndex, nSellIndex;
	int					nCode;
	unsigned short		nCurYmd, nCurMin;  //��ǰ�������ڶ�Ӧ�Ľ������ڡ�ʱ�䣬ͣ�ƻ�������ʱͣ�������Ľ������ڡ�ʱ��
	StockInfo           *p5MinKData;//ԭʼ��5����K������
	int                 n5MinKDataLen;
	StockInfo           *pNowKData;//����������ת�����K������
	int                 nNowKDataLen;
	
	int					nCJDCount = 0;
	CZSPZInfo			*pCZSPZ;//�����������ݽṹ
	CZSPZInfo			*usrCZSPZ;
	CJDInfo				*usrCJD;
	int					nCZSPZCount = 0;
	float				*fDIF, *fDEA, *fMACD;
	float				*fMAShort, *fMAMid, *fMALong; //�������ھ���ָ��
	long				*nVolMaLong, *nVolMid, *nVolShort; //�ɽ������ж��վ�ֵ
	short				    nWeekList[ANALYSEWEEKS];//��¼���ж̾��߾����ǵ���Ч����
public:
	//��ǰ�����������̼ۡ��ֲ־��ۺ�ǰ�����̼ۣ�����ͳ����ֵ;�ֹɾ���
	//ǰ�վ��������ж��Ƿ��������ͣ���ͣ
	float				fCurClose, fAveragePrice, fLastDateClose;
	//���������ʹ��
	unsigned short		nMaxHighYmd, nMaxHighMin;  //��ǰ�������ڶ�Ӧ�����HIGH��Ӧ�Ľ������ڡ�ʱ��
	float				fMaxHigh;
	unsigned short		nMinLowYmd, nMinLowMin;  //��ǰ�������ڶ�Ӧ����СLOW��Ӧ�Ľ������ڡ�ʱ��
	float				fMinLow;
	unsigned short		nMaxHigh, nMinLow;//���HIGH/LOW��Ӧ�ĵ�ǰ����K����ţ����ڿ���ȷ����ֵ�ڵ�ǰ�������ڵ�λ��

public:
	//�����飬ȫ�����������ʱ����true,���򷵻�false��5����K�����ݱ����ڵ���ǰ���ú�
	//���������ò����ķ�ʽ���ڣ����ӹ���ʱ�������ò�����ʵ�ֺ����������ܲ��ص���
	bool CheckRuler(pRulerFUNC *ptr)
	{
		bool bRet = true;
		 
		int nLen = n5MinKDataLen;
		
		CreateStockData(&nLen, p5MinKData, pNowKData, 5, 240);

		//ȫ��������ķ�ʽִ�У���һ����Ч���˳�����ִ��
		while (*ptr != NULL && bRet==true)
		{
			bRet=(*ptr)(pNowKData, nLen,this);
			ptr++;
		}

		return bRet;
	}

	//��λ�������������ֵ�ò����㣬����ֵ�ǲ��������
	//���������ӽ����ֵ�Ĳ�����
	int LocateMaxHighCJD()
	{
		int i = nCJDCount - 1;

		if (usrCJD[i].nStatus > 0) i--;

		while (i > 0 && usrCJD[i].nPlace > nMaxHigh)  i -= 2;
		
		return i + 1;
	}
	//��λ�������������ֵ�ò����㣬����ֵ�ǲ��������
	//���������ӽ����ֵ�Ĳ�����
	int LocateMinLowCJD()
	{
		int i = nCJDCount - 1;

		if (usrCJD[i].nStatus < 0) i--;

		while (i > 0 && usrCJD[i].nPlace > nMinLow)  i -= 2;

		return i + 1;
	}

	//����MACD  EMA 
	/*
	��EMA1�Ĳ���Ϊ12�գ�EMA2�Ĳ���Ϊ26�գ�DIF�Ĳ���Ϊ9��Ϊ��������MACD�ļ������
	1�������ƶ�ƽ��ֵ��EMA��
	12��EMA����ʽΪ   EMA��12��=ǰһ��EMA��12����11/13���������̼ۡ�2/13
	26��EMA����ʽΪ   EMA��26��=ǰһ��EMA��26����25/27���������̼ۡ�2/27
	2���������ֵ��DIF��   DIF=����EMA��12��������EMA��26��
	3������DIF��9��EMA   �������ֵ������9�յ�EMA�������ƽ��ֵ���������MACDֵ��
	Ϊ�˲���ָ��ԭ�����������ֵ����DEA��DEM��
	*/

	float EMA(float fClose, int nWeek, float fLastEMA)
	{
		return (fLastEMA*(nWeek - 1) + fClose * 2) / (nWeek + 1);
	}

	void MACD(int nDataLen, float *pfDIF, float *pfDEA, float *pfMACD,
		StockInfo *pStockSrc, int nShort, int nLong, int nMid)
	{
		float fLastEMALong = 0, fLastEMAShort = 0;
		int i;

		i = g_nCaclDataStartPoint;
		fLastEMAShort = pStockSrc[i].fClose;
		fLastEMALong = pStockSrc[i].fClose;
		pfDIF[i] = 0;
		pfDEA[i] = 0;
		pfMACD[i++] = 0;

		for (; i<nDataLen; i++)
		{
			fLastEMAShort = EMA(pStockSrc[i].fClose, nShort, fLastEMAShort);
			fLastEMALong = EMA(pStockSrc[i].fClose, nLong, fLastEMALong);
			pfDIF[i] = fLastEMAShort - fLastEMALong;
			pfDEA[i] = EMA(pfDIF[i], nMid, pfDEA[i - 1]);
			pfMACD[i] = 2 * (pfDIF[i] - pfDEA[i]);
		}
	}

	//�����ɼ�ʱ��ϵ�е�������
	void AnalyseStockData(int nSrcDataLen, bool bStockInTrade)
	{
		if (nSrcDataLen > 3)
		{
			//��ǰ����ʱ��ͣ�Ʊ�Ĳ�������
			//�����жϣ���ֹ����5����K�����ݴ���������ͣ��
			if (this->p5MinKData[nSrcDataLen - 1].nNumber == 0
				&& this->p5MinKData[nSrcDataLen - 2].nNumber == 0)
				return;

			this->SetLastDateDayClose(nSrcDataLen, this->p5MinKData);
			//��ǰ����ʱ��ͣ���ͣ��������
			if (this->UpStop(nSrcDataLen, this->p5MinKData)
				|| this->DownStop(nSrcDataLen, this->p5MinKData))
				return;
		}
		else
			return;

		short nSourceMin = 5, i = 0;
		int	nDataLen = nSrcDataLen;

		fDEA = g_fbuf1;
		fDIF = g_fbuf2;
		fMACD = g_fbuf3;

		if (bStockInTrade == true)
		{
			//��������ʱ���뵱ǰ���������ٲ�1��Ž��ж������
			if ((this->p5MinKData + nSrcDataLen - 1)->nYmd <= this->GetEldBuyYmd())
				return;

			int n = this->GetMustSellYmd();
			if ((this->p5MinKData + nSrcDataLen - 1)->nYmd >= n && n>0)
			{
				//�̶���30�������������жϵ�ǰ��Ʊ�Ƿ����µ�״̬  todo 20170222���Ż�
				CreateStockData(&nDataLen, this->p5MinKData, this->pNowKData,
					nSourceMin, 30);

				SetMaxHighMinLow(nDataLen);
				this->bDayUp = !StockIsDownOld4AutoSell(nDataLen, this->pNowKData);
			}
		}

		this->fMAShort = g_fMA1;
		this->fMAMid = g_fMA2;
		this->fMALong = g_fMA3;

		i = 0;
		while (this->nWeekList[i] != 0)
		{
			nDataLen = nSrcDataLen;
			memset(this->pNowKData, 0, sizeof(StockInfo)*nDataLen / this->nWeekList[i] * 5);

			//5��������ת��15/30/60����,nDataLen����ת����ķ�����������
			CreateStockData(&nDataLen, this->p5MinKData, this->pNowKData, nSourceMin,
				this->nWeekList[i]);
			SetMaxHighMinLow(nDataLen);

			SetAnalyseMode(nDataLen, 960, this->nWeekList[i], nCode);

			float	fCmd = 0, fMode;
			//���̼۾�ֵ
			MA(nDataLen, this->pNowKData, MASHORT, MAMID, MALONG,
				this->fMAShort, this->fMAMid, this->fMALong);


			//���³ֱֲ�ĵ�ǰ���ڵ����̼�
			SetCurClose(this->p5MinKData[nSrcDataLen - 1].fClose);

			CaclCJD(nDataLen, NULL, NULL, NULL, NULL);

			//������������
			CaclCZSPZ(nDataLen, NULL, NULL, NULL, NULL);

			if (bStockInTrade == true)
				AutoSell(nDataLen);

			//�������	 
			if (bStockInTrade == true && nCJDCount>10)
			{
				MACD(nDataLen, fDIF, fDEA, fMACD, this->pNowKData,
					g_nMACDMid, g_nMACDLong, g_nMACDShort);

				//�������
				fCmd = -1;
				fMode = BSMODE_DIFF;
				CaclBSPoint(nDataLen, NULL, &fMode, &fCmd, fDIF);

				//����ǰ�����ж�Ŀǰ��λ�Ƿ����ֹ���λ������ֹ���λʱ�����ж������
				if (fCurClose-fAutoDownSellPrice>0) //20170503 ����
				{
					fCmd = 2;
					fMode = BSMODE_DIFF;
					CaclBSPoint(nDataLen, NULL, &fMode, &fCmd, fDIF);
				}
			}
			else if(bStockInTrade==false)
			{
				MACD(nDataLen, fDIF, fDEA, fMACD, this->pNowKData, g_nMACDMid, g_nMACDLong, g_nMACDShort);

				fCmd = 1;

				//��������һ�����  ����DIF�б���
				fMode = BSMODE_DIFF;
				CaclBSPoint(nDataLen, NULL, &fMode, &fCmd, fDIF);
			}

			i++;
		};
}

	//�����ɼ�ʱ��ϵ���Ƿ���ڵױ��ۣ����򷵻�true
	bool DetectBtnBC(int nSrcDataLen,int nWeek)
	{

		if (nSrcDataLen > 3)
		{
			//��ǰ����ʱ��ͣ�Ʊ�Ĳ�������
			//�����жϣ���ֹ����5����K�����ݴ���������ͣ��
			if (this->p5MinKData[nSrcDataLen - 1].nNumber == 0
				&& this->p5MinKData[nSrcDataLen - 2].nNumber == 0)
				return false;
		}

		short nSourceMin = 5, i = 0;
		int	nDataLen = nSrcDataLen;

		memset(this->pNowKData, 0, sizeof(StockInfo)*nDataLen / nWeek * 5);

		//5��������ת��15/30/60����,nDataLen����ת����ķ�����������
		CreateStockData(&nDataLen, this->p5MinKData, this->pNowKData, nSourceMin,nWeek);
		SetMaxHighMinLow(nDataLen);

		SetAnalyseMode(nDataLen, 960, nWeek, nCode);
		CaclCJD(nDataLen, NULL, NULL, NULL, NULL);

		//�ױ��۷���	 
		if (nCJDCount-1-LocateMinLowCJD()<2  && nCJDCount>10)
		{
			float	fCmd = 0, fMode;

			fDEA = g_fbuf1;
			fDIF = g_fbuf2;
			fMACD = g_fbuf3;
			MACD(nDataLen, fDIF, fDEA, fMACD, this->pNowKData,
				g_nMACDMid, g_nMACDLong, g_nMACDShort);

			//����������������ֵ֮���CJD���
			CaclCJDTBPoint(fDIF, nDataLen);
			// ����������������ܷ��
			CaclEnergyTopBtn(fDIF, nDataLen);

			int nBC = BtnBC(nCJDCount - 1);
			return nBC > 0;
		}
	}

	//����������ʷ�����ļ��ķ�������ģʽ
	// pfCount  ������������    
	//pfWeek  �������ڣ���ͨ���ŵ���������Ӧ
	//��Ʊ��ָ������
	void SetAnalyseMode(int DataLen, int pfCount, int pfWeek, int nCode)
	{
		//g_nMaxAnalyseDateLen=DataLen;
		g_bAnalyseMode = true;
		g_nCaclDataStartPoint = 0;
		if (DataLen>g_nMaxDataLen) //��ֹ���ݹ��ർ��g_usrStock�±�Խ��
			g_nCaclDataStartPoint = DataLen - g_nMaxDataLen - 10;

		//Դͷ���ƣ���ֹ��������Խ��
		g_nCaclDataStartPoint = max(max(DataLen - max(0, pfCount), 0), g_nCaclDataStartPoint);

		g_nWeek = pfWeek;
		g_nCurrentStockCode = nCode;
		nCJDCount = 0;

		memset(usrCJD, 0, sizeof(CJDInfo));
	}

	//���߶μ��㣬�����ж���������
	void	CaclCLine()
	{
		int		i = 1;
		float	h = 0, l = 0;
		bool    bNewLine = false;//���������������߶δ�����ֹҪ��Ƴɵݹ鴦��
		bool	bIsUp = false;

		//������߶�״̬���������µ�
		//�߶εĶ��壺������3�ʹ��ɣ���ǰ���ʱ������ص����֣��������������������,�� �߶εĳ����սᶨ�壺1+1ģʽ��
		if (nCJDCount>3)
		{
			while (i<nCJDCount)
			{
				if (bNewLine == false)
				{
					if (usrCJD[i].nStatus >0 /*&& i+3<nCJDCount*/)
						//�ײ�����
					{
						h = min(pNowKData[usrCJD[i + 1].nPlace].fHigh,
							pNowKData[usrCJD[i + 3].nPlace].fHigh);
						l = max(pNowKData[usrCJD[i].nPlace].fLow,
							pNowKData[usrCJD[i + 2].nPlace].fLow);

						if (pNowKData[usrCJD[i].nPlace].fLow
							- pNowKData[usrCJD[i + 3].nPlace].fHigh >0.0)
							bIsUp = false; //�߶��µ�
						else
							bIsUp = true; //�߶�����
					}
					else if (usrCJD[i].nStatus <0 /*&& i+3<nCJDCount*/)
						//��������
					{
						h = min(pNowKData[usrCJD[i].nPlace].fHigh,
							pNowKData[usrCJD[i + 2].nPlace].fHigh);
						l = max(pNowKData[usrCJD[i + 1].nPlace].fLow,
							pNowKData[usrCJD[i + 3].nPlace].fLow);


						if (pNowKData[usrCJD[i].nPlace].fHigh
							- pNowKData[usrCJD[i + 3].nPlace].fLow >0.0)
							bIsUp = false; //�߶��µ�
						else
							bIsUp = true; //�߶�����
					}
					//else
					//	bIsUp=usrCJD[i].bIsUp;//�����2��δ��Ϊ�߶Σ�����ǰ������ƣ������ж�����

				}
				if (h - l >= 0.0 || bNewLine == true) //�������߶Σ�������3�ʹ��ɣ���ǰ���ʱ������ص����֣��������������������
				{
					if (bNewLine == false && usrCJD[i].bIsUp == bIsUp) //�߶����� todo ���ܳ����µ͡��¸ߵĴ���0820
					{
						if ((bIsUp == true && (pNowKData[usrCJD[i + 1].nPlace].fHigh
							- pNowKData[usrCJD[i + 3].nPlace].fHigh >0.0))  //�����߶��ڲ����¸�
							|| (bIsUp == false && pNowKData[usrCJD[i + 1].nPlace].fLow
								- pNowKData[usrCJD[i + 3].nPlace].fLow <0.0))//�µ��߶��ڲ����µ�
						{
							if (i<nCJDCount - 2)
							{
								usrCJD[i].bIsUp = bIsUp;
								usrCJD[i + 1].bIsUp = bIsUp;
								i = i + 1;
							}
							else
								break;
						}
						else
						{
							/*if( i<nCJDCount-4)
							{*/
							usrCJD[i].bIsUp = bIsUp;
							usrCJD[i + 1].bIsUp = bIsUp;
							usrCJD[i + 2].bIsUp = bIsUp;
							usrCJD[i + 3].bIsUp = bIsUp;
							i = i + 3;
							/*}
							else
							break;*/
						}
					}
					else if (bNewLine == false && usrCJD[i].bIsUp != bIsUp)//�߶�����
					{
						if (usrCJD[i].nStatus >0) //
						{
							if (pNowKData[usrCJD[i].nPlace].fLow
								- pNowKData[usrCJD[i + 4].nPlace].fLow >0.0)
							{//�����߶����ɺ����ϳ��ִ��µͣ��ñ���Ч
								if (pNowKData[usrCJD[i + 2].nPlace].fLow
									- pNowKData[usrCJD[i + 4].nPlace].fLow >0.0)
								{
									/*if( i<nCJDCount-5)
									{*/
									usrCJD[i + 1].bIsUp = usrCJD[i].bIsUp;
									usrCJD[i + 2].bIsUp = usrCJD[i].bIsUp;
									usrCJD[i + 3].bIsUp = usrCJD[i].bIsUp;
									usrCJD[i + 4].bIsUp = usrCJD[i].bIsUp;
									bIsUp = usrCJD[i].bIsUp;
									i = i + 4;
									/*}
									else
									break;*/

								}
								else//�ڲ��µ�
								{
									/*if( i<nCJDCount-3)
									{*/
									usrCJD[i + 1].bIsUp = usrCJD[i].bIsUp;
									usrCJD[i + 2].bIsUp = usrCJD[i].bIsUp;
									bIsUp = usrCJD[i].bIsUp;
									i = i + 2;
									/*}
									else
									break;*/


								}
							}
							else
							{//todo ���µʹ���
								if (pNowKData[usrCJD[i].nPlace].fLow
									- pNowKData[usrCJD[i + 2].nPlace].fLow >0.0)
								{
									/*if( i<nCJDCount-3)
									{*/
									usrCJD[i + 1].bIsUp = usrCJD[i].bIsUp;
									usrCJD[i + 2].bIsUp = usrCJD[i].bIsUp;
									bIsUp = usrCJD[i].bIsUp;
									i = i + 2;
									/*}
									else
									break;*/
								}
								else
								{
									/*if( i<nCJDCount-4)
									{*/
									usrCJD[i].bIsUp = bIsUp;
									usrCJD[i + 1].bIsUp = bIsUp;
									usrCJD[i + 2].bIsUp = bIsUp;
									usrCJD[i + 3].bIsUp = bIsUp;
									i = i + 3;
									bNewLine = true;
									/*}
									else
									break;*/
								}
							}
						}
						else
						{
							if (pNowKData[usrCJD[i].nPlace].fHigh
								- pNowKData[usrCJD[i + 2].nPlace].fHigh <0.0)
							{//�µ��߶��ڴ��¸ߣ��ñ���Ч
							 /*if( i<nCJDCount-3)
							 {*/
								usrCJD[i + 1].bIsUp = usrCJD[i].bIsUp;
								usrCJD[i + 2].bIsUp = usrCJD[i].bIsUp;
								bIsUp = usrCJD[i].bIsUp;
								i = i + 2;
								/*}
								else
								break;*/

							}
							else if (pNowKData[usrCJD[i].nPlace].fHigh
								- pNowKData[usrCJD[i + 4].nPlace].fHigh <0.0)
							{//�µ��߶����ɺ����ϳ��ִ��¸ߣ��ñ���Ч
							 /*if( i<nCJDCount-5)
							 {*/
								usrCJD[i + 1].bIsUp = usrCJD[i].bIsUp;
								usrCJD[i + 2].bIsUp = usrCJD[i].bIsUp;
								usrCJD[i + 3].bIsUp = usrCJD[i].bIsUp;
								usrCJD[i + 4].bIsUp = usrCJD[i].bIsUp;
								bIsUp = usrCJD[i].bIsUp;
								i = i + 4;
								/*}
								else break;*/

							}
							else
							{
								/*if( i<nCJDCount-4)
								{*/
								usrCJD[i].bIsUp = bIsUp;
								usrCJD[i + 1].bIsUp = bIsUp;
								usrCJD[i + 2].bIsUp = bIsUp;
								usrCJD[i + 3].bIsUp = bIsUp;
								bNewLine = true;
								i = i + 3;
								/*}
								else break;*/

							}
						}
					}
					else
						bNewLine = false;

					if (bIsUp == true)  //����
					{
						if (usrCJD[i].nStatus >0)  //��
						{
							//i+1��i+2�ʴ��¸ߣ�������
							while (pNowKData[usrCJD[i + 2].nPlace].fHigh
								- pNowKData[usrCJD[i].nPlace].fHigh>0.0)
							{
								usrCJD[i].bIsUp = true;
								usrCJD[i + 1].bIsUp = true;
								usrCJD[i + 2].bIsUp = true;
								bIsUp = usrCJD[i].bIsUp;
								i = i + 2;
							}

							//i+1��i+2�����¸ߣ���i+1����i-1  ת�� ���߶�
							if (pNowKData[usrCJD[i + 2].nPlace].fHigh
								- pNowKData[usrCJD[i].nPlace].fHigh<0.0
								&& pNowKData[usrCJD[i + 1].nPlace].fLow
								- pNowKData[usrCJD[i - 1].nPlace].fLow<0.0)
							{

								if (pNowKData[usrCJD[i + 4].nPlace].fHigh
									- pNowKData[usrCJD[i].nPlace].fHigh<0.0)
								{  //�µ��߶����ɺ����ϳ��ִ��¸ߣ��ñ���Ч
								   /*if(i+5<nCJDCount)
								   {*/
									usrCJD[i].bIsUp = true;
									usrCJD[i + 1].bIsUp = true;
									usrCJD[i + 2].bIsUp = true;
									usrCJD[i + 3].bIsUp = true;
									usrCJD[i + 4].bIsUp = true;
									i = i + 4;
									bNewLine = false;
									bIsUp = true;
									/*}
									else break;*/


								}
								else
								{
									if (pNowKData[usrCJD[i + 2].nPlace].fHigh
										- pNowKData[usrCJD[i].nPlace].fHigh >0.0)
									{
										/*if(i+3<nCJDCount)
										{*/
										usrCJD[i + 1].bIsUp = usrCJD[i].bIsUp;
										usrCJD[i + 2].bIsUp = usrCJD[i].bIsUp;
										bIsUp = usrCJD[i].bIsUp;
										i = i + 2;
										/*}
										else break;*/
									}
									else
									{
										/*if(i+4<nCJDCount)
										{*/
										usrCJD[i].bIsUp = false;
										usrCJD[i + 1].bIsUp = false;
										usrCJD[i + 2].bIsUp = false;
										usrCJD[i + 3].bIsUp = false;
										i = i + 3;
										bNewLine = true;
										bIsUp = false;

										/*}
										else break;*/
									}
								}
							}
						}
						else   //��
						{

							while (pNowKData[usrCJD[i + 2].nPlace].fHigh
								- pNowKData[usrCJD[i].nPlace].fHigh>0.0)
							{
								usrCJD[i + 1].bIsUp = true;
								usrCJD[i + 2].bIsUp = true;
								i = i + 2;
								bNewLine = false;
								bIsUp = true;
								//if((pNowKData[usrCJD[i-1].nPlace].fLow
								//		-pNowKData[usrCJD[i+1].nPlace].fLow>0.0) 
								//   &&(pNowKData[usrCJD[i+1].nPlace].fLow
								//		-pNowKData[usrCJD[i+3].nPlace].fLow>0.0) )
								//{ //���ϴ��µ�
								//	usrCJD[i].bIsUp =false;
								//	usrCJD[i+1].bIsUp =false;	
								//	usrCJD[i+2].bIsUp =false;
								//	usrCJD[i+3].bIsUp =false;
								//	i=i+3;
								//	bNewLine=true;
								//	bIsUp=false;
								//	
								//}
								//else
								//{  //i+2���¸ߣ�������
								//	break;
								//	/*usrCJD[i].bIsUp =true;
								//	usrCJD[i+1].bIsUp =true;	
								//	usrCJD[i+2].bIsUp =true;
								//	i=i+2;*/
								//}
							}

							//i+2�����¸ߣ���i+1����i-1  ת�� ���߶�
							if (pNowKData[usrCJD[i + 2].nPlace].fHigh
								- pNowKData[usrCJD[i].nPlace].fHigh<0.0
								/*&& pNowKData[usrCJD[i+1].nPlace].fLow
								-pNowKData[usrCJD[i-1].nPlace].fLow<0.0*/)
							{
								if (pNowKData[usrCJD[i + 4].nPlace].fHigh
									- pNowKData[usrCJD[i].nPlace].fHigh>0.0)
								{  //�������µͣ���ͬ�µ�
									if ((pNowKData[usrCJD[i - 1].nPlace].fLow
										- pNowKData[usrCJD[i + 1].nPlace].fLow>0.0)
										&& (pNowKData[usrCJD[i + 1].nPlace].fLow
											- pNowKData[usrCJD[i + 3].nPlace].fLow>0.0))
									{
										usrCJD[i].bIsUp = false;
										usrCJD[i + 1].bIsUp = false;
										usrCJD[i + 2].bIsUp = false;
										usrCJD[i + 3].bIsUp = false;
										i = i + 3;
										bNewLine = false;
										bIsUp = false;

									}
									else
									{	//�µ��߶����ɺ����ϳ��ִ��¸ߣ��ñ���Ч
										usrCJD[i].bIsUp = true;
										usrCJD[i + 1].bIsUp = true;
										usrCJD[i + 2].bIsUp = true;
										usrCJD[i + 3].bIsUp = true;
										usrCJD[i + 4].bIsUp = true;
										i = i + 4;
										bNewLine = false;
										bIsUp = true;
									}
								}
								else
								{
									/*if(i+4<nCJDCount)
									{*/
									usrCJD[i].bIsUp = false;
									usrCJD[i + 1].bIsUp = false;
									usrCJD[i + 2].bIsUp = false;
									usrCJD[i + 3].bIsUp = false;
									i = i + 3;
									bNewLine = true;
									bIsUp = false;
									/*}
									else break;*/
								}
							}
						}
					}
					else /*if( i<nCJDCount-2)*/ //����
					{
						if (usrCJD[i].nStatus >0)  //��
						{
							//i+2���µͣ�������
							if (pNowKData[usrCJD[i + 2].nPlace].fLow
								- pNowKData[usrCJD[i].nPlace].fLow<0.0)
							{
								/*if(i+3<nCJDCount)
								{*/
								usrCJD[i].bIsUp = false;
								usrCJD[i + 1].bIsUp = false;
								usrCJD[i + 2].bIsUp = false;
								i = i + 2;
								/*}
								else break;*/
							}

							//i+2�����µͣ���i+1����i-1  ת��  ���߶�
							if (pNowKData[usrCJD[i + 2].nPlace].fLow
								- pNowKData[usrCJD[i].nPlace].fLow>0.0
								/*&& pNowKData[usrCJD[i+1].nPlace].fHigh
								-pNowKData[usrCJD[i-1].nPlace].fHigh>0.0*/)
							{
								if (pNowKData[usrCJD[i + 4].nPlace].fLow
									- pNowKData[usrCJD[i].nPlace].fLow<0.0)
								{
									/*if(i+5<nCJDCount)
									{*/
									usrCJD[i].bIsUp = false;
									usrCJD[i + 1].bIsUp = false;
									usrCJD[i + 2].bIsUp = false;
									usrCJD[i + 3].bIsUp = false;
									usrCJD[i + 4].bIsUp = false;
									i = i + 4;
									bNewLine = false;
									bIsUp = false;
									/*}
									else break;*/
								}
								else
								{
									/*if(i+4<nCJDCount)
									{*/
									usrCJD[i].bIsUp = true;
									usrCJD[i + 1].bIsUp = true;
									usrCJD[i + 2].bIsUp = true;
									usrCJD[i + 3].bIsUp = true;
									i = i + 3;
									bNewLine = true;
									bIsUp = true;
									/*}
									else break;*/
								}
							}

						}
						else  //��
						{
							//i+2���µͣ�������  ???
							while (pNowKData[usrCJD[i + 2].nPlace].fLow
								- pNowKData[usrCJD[i].nPlace].fLow<0.0)
							{
								/*if(i+3<nCJDCount)
								{*/
								usrCJD[i + 1].bIsUp = false;
								usrCJD[i + 2].bIsUp = false;
								i = i + 2;
								/*}
								else
								break;*/
							}

							//i+2�����µͣ���i+1����i-1  ת��  ���߶�
							if (pNowKData[usrCJD[i + 2].nPlace].fLow
								- pNowKData[usrCJD[i].nPlace].fLow>0.0
								&& pNowKData[usrCJD[i + 1].nPlace].fHigh
								- pNowKData[usrCJD[i - 1].nPlace].fHigh>0.0)
							{
								if (pNowKData[usrCJD[i + 4].nPlace].fLow
									- pNowKData[usrCJD[i].nPlace].fLow>0.0)
								{
									/*if(i+5<nCJDCount)
									{*/
									usrCJD[i].bIsUp = false;
									usrCJD[i + 1].bIsUp = false;
									usrCJD[i + 2].bIsUp = false;
									usrCJD[i + 3].bIsUp = false;
									usrCJD[i + 4].bIsUp = false;
									i = i + 4;
									bNewLine = false;
									bIsUp = false;
									//}
								}
								else
								{
									/*if(i+4<nCJDCount)
									{*/
									usrCJD[i].bIsUp = true;
									usrCJD[i + 1].bIsUp = true;
									usrCJD[i + 2].bIsUp = true;
									usrCJD[i + 3].bIsUp = true;
									i = i + 3;
									bNewLine = true;
									bIsUp = true;
									/*}
									else break;*/
								}
							}
						}  //false
					}
				}
				else
				{//����û�й������֣��������������߶ι��򣬿�������������ԭ��������0815
					usrCJD[i].bIsUp = bIsUp;
					usrCJD[i + 1].bIsUp = bIsUp;
					usrCJD[i + 2].bIsUp = bIsUp;
					i += 2;
				}
			}

			//���һ�����ƴ���	 
			i = nCJDCount - 1;
			while (0 == usrCJD[i].nStatus) i--;
			if (usrCJD[i].nStatus >0 && ((usrCJD[i].bIsUp ^usrCJD[i - 1].bIsUp) == false))
			{
				if (usrCJD[i].bIsUp == true)
				{
					usrCJD[i - 1].bIsUp = false;
					usrCJD[i].bIsUp = false;
				}
				else
				{
					usrCJD[i].bIsUp = true;
				}

			}

			if (usrCJD[i].nStatus <0 && ((usrCJD[i].bIsUp ^usrCJD[i - 1].bIsUp) == false))
			{
				if (usrCJD[i].bIsUp == true)
					usrCJD[i].bIsUp = false;
				else
					usrCJD[i - 1].bIsUp = true;

			}

		}

	}

	void	CreateStockData(int	*nDataLen, StockInfo *pBase, StockInfo *pDest,
		int nFromMinute, int nToMinute)
	{
		int	i = 0, j = 0, k;
		int	nRate = nToMinute / nFromMinute;

		//�ҵ����ݵ�ĳ�տ�ʼ�����ת��
		if (575!= pBase[i].nMin)
		{
			k = TimeDiff(15 * 60, pBase[i].nMin);
			i = i + k / 5 + 1;
		}
		

		for (; i<*nDataLen; i += nRate, j++)
		{
			pDest[j].fOpen = pBase[i].fOpen;

			pDest[j].fLow = pBase[i].fLow;
			pDest[j].fHigh = pBase[i].fHigh;
			pDest[j].fAmount = pBase[i].fAmount;
			pDest[j].nNumber = pBase[i].nNumber;
			pDest[j].nYmd = pBase[i].nYmd;
			pDest[j].nMin = pBase[i ].nMin;
			for (k = 1; k<nRate && i + k<*nDataLen;)
			{
				pDest[j].fLow = min(pDest[j].fLow, pBase[i + k].fLow);
				pDest[j].fHigh = max(pDest[j].fHigh, pBase[i + k].fHigh);
				pDest[j].fAmount += pBase[i + k].fAmount;
				pDest[j].nNumber += pBase[i + k].nNumber;

				k++;
				if ((pBase[i + k].nMin<780 && pBase[i].nMin<780) || (pBase[i + k].nMin >= 780 && pBase[i].nMin >= 780))
					if ((pBase[i + k].nMin - pBase[i].nMin>nToMinute - nFromMinute)
						|| (pBase[i + k].nYmd != pBase[i].nYmd))
						break;

				if ((pBase[i + k].nMin >= 780 && pBase[i].nMin<780))
					if ((pBase[i + k].nMin - pBase[i].nMin - 90>nToMinute - nFromMinute)
						|| (pBase[i + k].nYmd != pBase[i].nYmd))
						break;
			}
			
			pDest[j].fClose = pBase[i + k - 1].fClose;	 //��ֹ���̼����

		}

		*nDataLen = j;

		//ͳһ����ȨϢ����  1205
		//�˴���Ӧ����CNowTrends��ͳһ���㣬��ֹ��μ���Ӱ��Ч�� TODO20170318
		if (false == CheckCodeQX(nCode))
			return;

		float fGiven = 0, fGain = 0, fBuyCount = 0, fBuyPrice = 0;
		float fGiven1 = 0, fGain1 = 0, fBuyCount1 = 0, fBuyPrice1 = 0;
		bool	bQuanXi = false;
		int		nDateLarge = 0, nDateSmall = 0;

		for (i = j - 1; i > 0; i--)
		{
			//�ݲ����Ƿ�����������һ�����ϵĳ�Ȩ��Ϣ��Ϣ����  1205  

			if (bQuanXi == true)
			{
				CaclQuanXiPrice(fGiven, fGain, fBuyCount, fBuyPrice, &pDest[i].fClose);
				CaclQuanXiPrice(fGiven, fGain, fBuyCount, fBuyPrice, &pDest[i].fOpen);
				CaclQuanXiPrice(fGiven, fGain, fBuyCount, fBuyPrice, &pDest[i].fHigh);
				CaclQuanXiPrice(fGiven, fGain, fBuyCount, fBuyPrice, &pDest[i].fLow);
			}
			else if (true == CheckQX(&fGiven1, &fGain1, &fBuyCount1, &fBuyPrice1, &nDateLarge,
				&nDateSmall, pDest[i].nYmd, pDest[0].nYmd, nCode))
			{
				bQuanXi = true;
				fGiven = fGiven1, fGain = fGain1, fBuyCount = fBuyCount1, fBuyPrice = fBuyPrice1;
				CaclQuanXiPrice(fGiven, fGain, fBuyCount, fBuyPrice, &pDest[i].fClose);
				CaclQuanXiPrice(fGiven, fGain, fBuyCount, fBuyPrice, &pDest[i].fOpen);
				CaclQuanXiPrice(fGiven, fGain, fBuyCount, fBuyPrice, &pDest[i].fHigh);
				CaclQuanXiPrice(fGiven, fGain, fBuyCount, fBuyPrice, &pDest[i].fLow);
			}

			//ȨϢ�仯ʱ�䲻��Ŀǰ����ʱ������
			if (nDateLarge > 0 || nDateSmall<0)
				break;
		}
	}

	//��������  ��������
	//�������ࡢ���������жϣ����仯����С��VARRATE=3%����Ϊ���������죬�����������������������20170223
	void CaclCZSPZ(int DataLen, float* pfOUT, float* pfPlace, float* pfDATE, float* pfVOL)
	{
		int		iLineCount = 0;
		int		i = 1;
		bool	bNewZS, bNewPZ;
		int		NewHighLow1 = 0, NewHighLow2 = 0;
		float	fPZ, fZS;
		CZSPZInfo usrLowVarChannel;  //΢С��������

									 //�����������
		CaclCPen(DataLen, pfOUT, pfPlace, pfDATE, pfVOL);

		memset(usrCZSPZ, 0, (nCZSPZCount + 1) * sizeof(CZSPZInfo));
		memset(&usrLowVarChannel, 0, sizeof(CZSPZInfo));

		nCZSPZCount = 1;

		i = 2;
		while (i<nCJDCount)
		{
			//�����������ʼ�������Ǳʱȴ���1.2
			while (i < nCJDCount - 1 && usrCJD[i].nLineBi < 12)
			{
				//��ǰ�������������
				//usrCZSPZ[nCZSPZCount-1].p2 = i;

				//��¼�Ͳ���������
				if (usrLowVarChannel.p1 == 0)
					usrLowVarChannel.p1 = i;
				else
					usrLowVarChannel.p2 = i;

				i++;

			}

			NewHighLow1 = 0;
			NewHighLow2 = 0;
			bNewPZ = CaclCPZ(i, &NewHighLow1, &fPZ);
			bNewZS = CaclCZS(i, &NewHighLow2, &fZS);

			if (bNewZS == true && bNewPZ == true)
			{
				if (NewHighLow1 == -1 && NewHighLow2 == -1 && fPZ - fZS<0.0)
				{
					CaclCPZ(i, &NewHighLow1, &fPZ);
					if (usrCZSPZ[nCZSPZCount - 1].VarRate(pNowKData,usrCJD)>CZSVARRATE)
					{
						i = usrCZSPZ[nCZSPZCount].p2 - 1;
						//��ǰ��������������̼���ǰһ������������̼۱Ƚ�
						usrCZSPZ[nCZSPZCount].bIsUp = (bool)(pNowKData[usrCJD[usrCZSPZ[nCZSPZCount].p2].nPlace].fClose
							- pNowKData[usrCJD[usrCZSPZ[nCZSPZCount - 1].p2].nPlace].fClose>0.0);

						nCZSPZCount++;
						memset(&usrLowVarChannel, 0, sizeof(CZSPZInfo));
					}
					else if (nCZSPZCount>0)
					{
						//��¼�Ͳ���������
						usrLowVarChannel.p1 = usrCZSPZ[nCZSPZCount - 1].p2;
						usrLowVarChannel.p2 = i;

						//ָ������
						usrCZSPZ[nCZSPZCount - 1].p2 = usrCZSPZ[nCZSPZCount].p2;
						i = usrCZSPZ[nCZSPZCount].p2 - 1;
					}

				}
				else if (NewHighLow1 == -1 && NewHighLow2 == -1 && fPZ - fZS >= 0.0)
				{
					if (usrCZSPZ[nCZSPZCount].VarRate(pNowKData,usrCJD) > CZSVARRATE)
					{
						i = usrCZSPZ[nCZSPZCount].p2 - 1;
						//��ǰ��������������̼���ǰһ������������̼۱Ƚ�
						usrCZSPZ[nCZSPZCount].bIsUp = (bool)(pNowKData[usrCJD[usrCZSPZ[nCZSPZCount].p2].nPlace].fClose
							- pNowKData[usrCJD[usrCZSPZ[nCZSPZCount - 1].p2].nPlace].fClose>0.0);

						nCZSPZCount++;
						memset(&usrLowVarChannel, 0, sizeof(CZSPZInfo));
					}
					else if (nCZSPZCount>0)
					{
						//��¼�Ͳ���������
						usrLowVarChannel.p1 = usrCZSPZ[nCZSPZCount - 1].p2;
						usrLowVarChannel.p2 = i;

						//ָ������
						usrCZSPZ[nCZSPZCount - 1].p2 = usrCZSPZ[nCZSPZCount].p2;
						i = usrCZSPZ[nCZSPZCount].p2 - 1;
					}
				}
				else if (NewHighLow1 == -1 && NewHighLow2>-1)
				{
					CaclCPZ(i, &NewHighLow1, &fPZ);

					if (usrCZSPZ[nCZSPZCount].VarRate(pNowKData,usrCJD) > CZSVARRATE)
					{
						i = usrCZSPZ[nCZSPZCount].p2 - 1;
						//��ǰ��������������̼���ǰһ������������̼۱Ƚ�
						usrCZSPZ[nCZSPZCount].bIsUp = (pNowKData[usrCJD[usrCZSPZ[nCZSPZCount].p2].nPlace].fClose
							- pNowKData[usrCJD[usrCZSPZ[nCZSPZCount - 1].p2].nPlace].fClose > 0.0);

						nCZSPZCount++;
						memset(&usrLowVarChannel, 0, sizeof(CZSPZInfo));
					}
					else if (nCZSPZCount>0)
					{
						//��¼�Ͳ���������
						usrLowVarChannel.p1 = usrCZSPZ[nCZSPZCount - 1].p2;
						usrLowVarChannel.p2 = i;

						//ָ������
						usrCZSPZ[nCZSPZCount - 1].p2 = usrCZSPZ[nCZSPZCount].p2;
						i = usrCZSPZ[nCZSPZCount].p2 - 1;
					}

				}
				else if (NewHighLow1 == 1 && NewHighLow2 == 1 && fPZ - fZS>0.0)
				{
					CaclCPZ(i, &NewHighLow1, &fPZ);
					if (usrCZSPZ[nCZSPZCount].VarRate(pNowKData,usrCJD) > CZSVARRATE)
					{
						i = usrCZSPZ[nCZSPZCount].p2 - 1;
						//��ǰ��������������̼���ǰһ������������̼۱Ƚ�
						usrCZSPZ[nCZSPZCount].bIsUp = (pNowKData[usrCJD[usrCZSPZ[nCZSPZCount].p2].nPlace].fClose
							- pNowKData[usrCJD[usrCZSPZ[nCZSPZCount - 1].p2].nPlace].fClose > 0.0);

						nCZSPZCount++;
						memset(&usrLowVarChannel, 0, sizeof(CZSPZInfo));
					}
					else if (nCZSPZCount>0)
					{
						//��¼�Ͳ���������
						usrLowVarChannel.p1 = usrCZSPZ[nCZSPZCount - 1].p2;
						usrLowVarChannel.p2 = i;

						//ָ������
						usrCZSPZ[nCZSPZCount - 1].p2 = usrCZSPZ[nCZSPZCount].p2;
						i = usrCZSPZ[nCZSPZCount].p2 - 1;
					}

				}
				else if (NewHighLow1 == 1 && NewHighLow2<1)
				{
					CaclCPZ(i, &NewHighLow1, &fPZ);
					if (usrCZSPZ[nCZSPZCount].VarRate(pNowKData,usrCJD) > CZSVARRATE)
					{
						i = usrCZSPZ[nCZSPZCount].p2 - 1;
						//��ǰ��������������̼���ǰһ������������̼۱Ƚ�
						usrCZSPZ[nCZSPZCount].bIsUp = (pNowKData[usrCJD[usrCZSPZ[nCZSPZCount].p2].nPlace].fClose
							- pNowKData[usrCJD[usrCZSPZ[nCZSPZCount - 1].p2].nPlace].fClose > 0.0);

						nCZSPZCount++;
						memset(&usrLowVarChannel, 0, sizeof(CZSPZInfo));
					}
					else if (nCZSPZCount>0)
					{
						//��¼�Ͳ���������
						usrLowVarChannel.p1 = usrCZSPZ[nCZSPZCount - 1].p2;
						usrLowVarChannel.p2 = i;

						//ָ������
						usrCZSPZ[nCZSPZCount - 1].p2 = usrCZSPZ[nCZSPZCount].p2;
						i = usrCZSPZ[nCZSPZCount].p2 - 1;
					}

				}
				else
				{
					if (usrCZSPZ[nCZSPZCount].VarRate(pNowKData,usrCJD) > CZSVARRATE)
					{
						i = usrCZSPZ[nCZSPZCount].p2 - 1;
						//��ǰ��������������̼���ǰһ������������̼۱Ƚ�
						usrCZSPZ[nCZSPZCount].bIsUp = (pNowKData[usrCJD[usrCZSPZ[nCZSPZCount].p2].nPlace].fClose
							- pNowKData[usrCJD[usrCZSPZ[nCZSPZCount - 1].p2].nPlace].fClose > 0.0);

						nCZSPZCount++;
						memset(&usrLowVarChannel, 0, sizeof(CZSPZInfo));
					}
					else if (nCZSPZCount>0)
					{
						//��¼�Ͳ���������
						usrLowVarChannel.p1 = usrCZSPZ[nCZSPZCount - 1].p2;
						usrLowVarChannel.p2 = i;

						//ָ������
						usrCZSPZ[nCZSPZCount - 1].p2 = usrCZSPZ[nCZSPZCount].p2;
						i = usrCZSPZ[nCZSPZCount].p2 - 1;
					}

				}
			}
			else if (bNewZS == false && bNewPZ == true)
			{
				CaclCPZ(i, &NewHighLow1, &fPZ);
				if (usrCZSPZ[nCZSPZCount].VarRate(pNowKData,usrCJD) > CZSVARRATE)
				{
					//��ǰ��������������̼���ǰһ������������̼۱Ƚ�
					usrCZSPZ[nCZSPZCount].bIsUp = (pNowKData[usrCJD[usrCZSPZ[nCZSPZCount].p2].nPlace].fClose
						- pNowKData[usrCJD[usrCZSPZ[nCZSPZCount - 1].p2].nPlace].fClose > 0.0);

					i = usrCZSPZ[nCZSPZCount].p2 - 1;
					nCZSPZCount++;
					memset(&usrLowVarChannel, 0, sizeof(CZSPZInfo));
				}
				else if (nCZSPZCount>0)
				{

					//��¼�Ͳ���������
					usrLowVarChannel.p1 = usrCZSPZ[nCZSPZCount - 1].p2;
					usrLowVarChannel.p2 = i;
					//ָ������
					usrCZSPZ[nCZSPZCount - 1].p2 = usrCZSPZ[nCZSPZCount].p2;
					i = usrCZSPZ[nCZSPZCount].p2 - 1;
				}

				usrCZSPZ[nCZSPZCount].p1 = 0;
			}
			else if (bNewZS == true && bNewPZ == false)
			{
				if (usrCZSPZ[nCZSPZCount].VarRate(pNowKData,usrCJD) >CZSVARRATE)
				{
					i = usrCZSPZ[nCZSPZCount].p2 - 1;
					//��ǰ��������������̼���ǰһ������������̼۱Ƚ�
					usrCZSPZ[nCZSPZCount].bIsUp = (pNowKData[usrCJD[usrCZSPZ[nCZSPZCount].p2].nPlace].fClose
						- pNowKData[usrCJD[usrCZSPZ[nCZSPZCount - 1].p2].nPlace].fClose > 0.0);

					nCZSPZCount++;
					if (usrLowVarChannel.p1>0)
						memset(&usrLowVarChannel, 0, sizeof(CZSPZInfo));
				}
				else if (nCZSPZCount>0)
				{
					//��¼�Ͳ���������
					usrLowVarChannel.p1 = usrCZSPZ[nCZSPZCount - 1].p2;
					usrLowVarChannel.p2 = i;

					//ָ������
					usrCZSPZ[nCZSPZCount - 1].p2 = usrCZSPZ[nCZSPZCount].p2;
					i = usrCZSPZ[nCZSPZCount].p2 - 1;
				}

				//usrCZSPZ[nCZSPZCount].p1 = 0;
			}
			else if (i < nCJDCount)
			{   //��ǰ�������������  �������죬���������µ��������������20170319
				//usrCZSPZ[nCZSPZCount-1].p2 = i;

				//��¼�Ͳ���������
				if (usrLowVarChannel.p1 == 0)
					usrLowVarChannel.p1 = i;
				else
					usrLowVarChannel.p2 = i;

				i++;
			}
		}
	}


	//�������,ͬʱ���Ǽ��������߶κ��µ��߶Σ����1+1�ս����
	void CaclCPen(int DataLen, float* pfOUT, float* pfPlace, float* pfDATE, float* pfVOL)
	{
		int	i = 1, p1, p2;

		//���������������
		i = 0;
		p1 = usrCJD[i].nPlace;
		p2 = usrCJD[i + 1].nPlace;
		if (usrCJD[i].nStatus >0)
			usrCJD[i].fLineLen = pNowKData[p2].fHigh - pNowKData[p1].fLow;
		else
			usrCJD[i].fLineLen = -pNowKData[p2].fLow + pNowKData[p1].fHigh;

		//�����������  
		i = 1;
		while (i<nCJDCount - 1)
		{
			p1 = usrCJD[i].nPlace;
			p2 = usrCJD[i + 1].nPlace;

			if (usrCJD[i].nStatus >0)
				usrCJD[i].fLineLen = pNowKData[p2].fHigh - pNowKData[p1].fLow;
			else
				usrCJD[i].fLineLen = -pNowKData[p2].fLow + pNowKData[p1].fHigh;

			if (usrCJD[i].fLineLen<0.0001)
				usrCJD[i].nLineBi = 0;
			else
				usrCJD[i].nLineBi = int(10 * usrCJD[i - 1].fLineLen / usrCJD[i].fLineLen);

			i++;
		}
	}

	/*
	����nCJDIndex-1��nCJDIndex��ɵı�������nCZSIndex��ϵ��
	���ڣ�����1
	�н���������0
	���ڣ�����-1
	*/
	int PenInCZS(int nCJDIndex, int nCZSIndex)
	{
		int	out = 0;
		float	gg, dd, fHigh, fLow;

		if (nCJDIndex>0 && nCJDIndex<nCJDCount)
		{
			if (usrCJD[nCJDIndex].nStatus >0)
			{
				fHigh = pNowKData[usrCJD[nCJDIndex - 1].nPlace].fHigh;
				fLow = pNowKData[usrCJD[nCJDIndex].nPlace].fLow;
			}
			else
			{
				fHigh = pNowKData[usrCJD[nCJDIndex].nPlace].fHigh;
				fLow = pNowKData[usrCJD[nCJDIndex - 1].nPlace].fLow;
			}

			//��������ı�׼����
			/*gg=usrCZSPZ[nCZSIndex].fMinHigh ;
			dd=usrCZSPZ[nCZSIndex].fMaxLow ;*/
			//���͵������������  0928
			gg = usrCZSPZ[nCZSIndex].fHigh;
			dd = usrCZSPZ[nCZSIndex].fLow;

			if (fHigh - gg >= 0.0 && fLow - dd <= 0.0) //�ʴ�͸����
				out = 0;
			else if (fHigh - gg <0.0 && fLow - dd >0.0) //����������
				out = 0;
			else if ((fLow - dd >= 0.0 && fLow - gg <= 0.0) //�ʿ�����������
				|| (fHigh - dd >= 0.0 && fLow - gg <= 0.0)) //�ʿ�����������
				out = 0;
			else if (fLow - gg >0.0 && fLow - fHigh <0.0) //����������
				out = 1;
			else if (fHigh - dd <0.0 && fLow - fHigh <0.0) //������������
				out = -1;
		}
		return out;
	}


	//-========================================�Ľ���Ĳ����㡢���ࡢ��������
	//����K��ͼ�еĲ��ʻ�����  ���׷����жϣ����ն������
	/*
	�������ǲ���������ϵ������K�ߣ��м�һ���ߵ����  ���͵�Ҳ��ߡ�
	�����������ǹ����н�����ת�۵��źš�һֻ�����Ĺ�Ʊ������������Ͷ�û�г��֣��Ͳ�Ӧ�ü���������
	һ�����5���ھ��߾Ϳ�ȷ�������͵�ȷ����

	�׷����ǲ���������ϵ������K�ߣ��м�һ���͵���� ���ߵ�Ҳ��͡�
	�׷������µ����̽�����ת�۵��źš�һֻ�µ������еĹ�Ʊ��������׷��Ͷ�û�г��֣��Ͳ�Ӧ���������롣
	*/

	void CaclCJD(int DataLen, float* pfOUT, float* pfPlace, float* pfDATE, float* pfVOL)
	{
		int p1 = 0, p2 = 0, p3 = 0;//��¼λ��
		float h1, h2, h3, l1, l2, l3;//�����ҵ����������ߵ�λ

		int i = g_nCaclDataStartPoint, iChangeed = 0;
		//DataLen = g_nMaxAnalyseDateLen;

		nCJDCount = 0;
		usrCJD[0].nStatus = 0; usrCJD[0].bIsUp = false;
		p1 = i, l1 = pNowKData[i].fLow;
		p2 = i + 1, l2 = pNowKData[i + 1].fLow;
		p3 = i + 2, l3 = pNowKData[i + 2].fLow;
		h1 = pNowKData[i].fHigh;
		h2 = pNowKData[i + 1].fHigh;
		h3 = pNowKData[i + 2].fHigh;
		i += 3;

		for (; i<DataLen && nCJDCount<g_nMaxDataLen / 6 + 5;)
		{
			iChangeed = 2;//2 ������Ч��0������Ч��1 �����������ϵ

						  //ǰ�������ϵ����
						  //�����������У�����K �ߵ���ߵ㵱�ߵ㣬����K�ߵ͵��еĽϸ��ߵ��ɵ͵㣬�����Ͱ���K�ߺϲ���һ�µ�K�� �����GG)��
						  //���½������У�����K �ߵ���͵㵱�͵㣬����K�ߵ��еĽϵ��ߵ��ɸߵ㣬�����Ͱ���K�ߺϲ���һ�µ�K�ߣ����DD)��

			while (h1 >= h2 && l1 <= l2)  //1-2ǰ����,��l2
			{
				l2 = l3, h2 = h3;
				p2 = p3, p3 = i++;
				l3 = pNowKData[p3].fLow;
				h3 = pNowKData[p3].fHigh;
				iChangeed = 1;
				if (i>DataLen - 1) break;
			}

			while (h1 <= h2 && l1 >= l2 && p1>2) //1-2���ǰ,��l1 p3p2���� p1ǰ��
			{
				p1--;
				l1 = pNowKData[p1].fLow, h1 = pNowKData[p1].fHigh;
			}

			while (h2 >= h3 && l2 <= l3)  //2-3ǰ����,��l3
			{
				p3 = i++;
				l3 = pNowKData[p3].fLow;
				h3 = pNowKData[p3].fHigh;
				iChangeed = 1;
				if (i>DataLen - 1) break;
			}

			//p1������յͿ������K����̬��������ǰ������K�ߵĺ��ǰ����  ���͵����������������̬  3��2����
			while (h2 <= h3 && l2 >= l3 && p1>2) //2-3���ǰ,��l2  3��2,3���� p2p1��ǰ��
			{
				h2 = h1, l2 = l1;
				p2 = p1--;
				l1 = pNowKData[p1].fLow;
				h1 = pNowKData[p1].fHigh;
			}

			//������-1ʱ�����ͣ���С��1�ǵ׷���
			int nFX = CaclCFX(p1, p2, p3);

			//�������ж�  if(h2>h1 && h2>h3 && l2>l1 && l2>l3) ���յ���5���ھ���
			if (nFX <= -1 && p3 + 1 <= DataLen)
			{   //�ݲ����ǵ���5�վ���|| pNowKData[p3].fClose <pNowKData[p3].fMA5 
				//	|| pNowKData[p3+1].fClose <pNowKData[p3].fMA5
				if (1)
				{
					if (nCJDCount<2) //ǰ�������ͣ�0��1�����ж���Ч��
					{
						usrCJD[nCJDCount].nPlace = p2;
						usrCJD[nCJDCount].nDateTime = (pNowKData[p2].nYmd %2048)*100 
							+ (pNowKData[p2].nMin /60);
						usrCJD[nCJDCount].nP1 = p1;
						usrCJD[nCJDCount].nP3 = p2;
						usrCJD[nCJDCount++].nStatus = nFX;
						iChangeed = 0;
					}
					else
					{
						//���������Ͳ��ؼ�¼����ǰһ�׷��ͼ������4�����ڲ���Ϊ�����ͳ���
						if (usrCJD[nCJDCount - 1].nStatus >= 1)
						{
							//if(h2-pNowKData[usrCJD[nCJDCount-1].nPlace].fHigh >0)   //���������ǰ��
							{    //TODO  ���p3�� 20170301
								if (p2 - usrCJD[nCJDCount - 1].nPlace>3
									&& p1 - usrCJD[nCJDCount - 1].nP3>1)
								{
									usrCJD[nCJDCount].nPlace = p2;
									usrCJD[nCJDCount].nDateTime = (pNowKData[p2].nYmd % 2048) * 100 
										+ (pNowKData[p2].nMin / 60);
									usrCJD[nCJDCount].nP1 = p1;
									usrCJD[nCJDCount].nP3 = p3;
									usrCJD[nCJDCount++].nStatus = nFX;
									iChangeed = 0;
								}
								else if (h2 - pNowKData[usrCJD[nCJDCount - 2].nPlace].fHigh>0.0)
									//�׿����úܽ�����  ���¶�����ǰ�����������һ�ף�ǰ������Ϊ����
									//��Ҫ�жϣ��������ĵͷ����Ƿ��ǰһ�ͷ��͸��ͣ�
									//���ǣ���ǰһ�׷����Ƶ��ⱻ�����ĵ׷���20160929
								{
									if (nCJDCount >= 3)
									{
										if (pNowKData[usrCJD[nCJDCount - 3].nPlace].fLow
											- pNowKData[usrCJD[nCJDCount - 1].nPlace].fLow>0.0)
										{
											memcpy(&usrCJD[nCJDCount - 3], &usrCJD[nCJDCount - 1], sizeof(CJDInfo));
											nCJDCount -= 2;
											iChangeed = 0;
										}
										else
										{
											//�¶����ǰһ��
											nCJDCount -= 2;
											usrCJD[nCJDCount].nPlace = p2;
											usrCJD[nCJDCount].nDateTime = (pNowKData[p2].nYmd % 2048) * 100 
												+ (pNowKData[p2].nMin / 60);
											usrCJD[nCJDCount].nP1 = p1;
											usrCJD[nCJDCount].nP3 = p3;
											usrCJD[nCJDCount++].nStatus = nFX;
											iChangeed = 0;
										}

									}
									else
									{
										nCJDCount -= 2;
										usrCJD[nCJDCount].nPlace = p2;
										usrCJD[nCJDCount].nDateTime = (pNowKData[p2].nYmd % 2048) * 100 
											+ (pNowKData[p2].nMin / 60);
										usrCJD[nCJDCount].nP1 = p1;
										usrCJD[nCJDCount].nP3 = p3;
										usrCJD[nCJDCount++].nStatus = nFX;
										iChangeed = 0;
									}
								}
							}
						}
						else if (usrCJD[nCJDCount - 1].nStatus <= -1 && p2 - usrCJD[nCJDCount - 1].nPlace>0
							&& pNowKData[usrCJD[nCJDCount - 1].nPlace].fHigh - h2<0)  //�¶����͸���)
						{
							//�������ֶ����ͣ�����λ�� 
							usrCJD[nCJDCount - 1].nPlace = p2;
							usrCJD[nCJDCount].nDateTime = (pNowKData[p2].nYmd % 2048) * 100 
								+ (pNowKData[p2].nMin / 60);
							usrCJD[nCJDCount - 1].nP1 = p1;
							usrCJD[nCJDCount - 1].nP3 = p3;
							usrCJD[nCJDCount - 1].nStatus = nFX;
							iChangeed = 0;
						}
					}
				}
			}
			//---------------------�׷����ж�  if(h2<h1 && h2<h3 && l2<l1 && l2<l3) 
			else if (nFX >= 1 && p3 + 1 <= DataLen)
			{
				if (nCJDCount<2) //0��1���Ͳ��ж���Ч��
				{
					usrCJD[nCJDCount].nPlace = p2;
					usrCJD[nCJDCount].nDateTime = (pNowKData[p2].nYmd % 2048) * 100 
						+ (pNowKData[p2].nMin / 60);
					usrCJD[nCJDCount].nP1 = p1;
					usrCJD[nCJDCount].nP3 = p3;
					usrCJD[nCJDCount++].nStatus = -1;
					iChangeed = 0;
				}
				else
				{
					//�����׷��Ͳ��ؼ�¼����ǰһ�����ͼ������4�����ڲ���Ϊ�����ͳ���
					if (usrCJD[nCJDCount - 1].nStatus <= -1)
					{
						if (p2 - usrCJD[nCJDCount - 1].nPlace>3
							&& p1 - usrCJD[nCJDCount - 1].nP3>1)
						{
							usrCJD[nCJDCount].nPlace = p2;
							usrCJD[nCJDCount].nDateTime = (pNowKData[p2].nYmd % 2048) * 100 
								+ (pNowKData[p2].nMin / 60);
							usrCJD[nCJDCount].nP1 = p1;
							usrCJD[nCJDCount].nP3 = p3;
							usrCJD[nCJDCount++].nStatus = nFX;
							iChangeed = 0;
						}
						else if (l2 - pNowKData[usrCJD[nCJDCount - 2].nPlace].fLow<0.0)
							//���׿��׵úܽ�����  ���¶�����ǰ�����������һ�ף�ǰ������Ϊ����  todo 20160801
						{
							nCJDCount -= 2;
							usrCJD[nCJDCount].nPlace = p2;
							usrCJD[nCJDCount].nDateTime = (pNowKData[p2].nYmd % 2048) * 100 
								+ (pNowKData[p2].nMin / 60);
							usrCJD[nCJDCount].nP1 = p1;
							usrCJD[nCJDCount].nP3 = p3;
							usrCJD[nCJDCount++].nStatus = nFX;
							iChangeed = 0;
						}

					}
					else if (usrCJD[nCJDCount - 1].nStatus >= 1 && p2 - usrCJD[nCJDCount - 1].nPlace>0
						&& pNowKData[usrCJD[nCJDCount - 1].nPlace].fLow - l2>0)  //�µ׷��͸���
					{
						//�������ֵ׷��ͣ�����λ��
						usrCJD[nCJDCount - 1].nPlace = p2;
						usrCJD[nCJDCount].nDateTime = (pNowKData[p2].nYmd % 2048) * 100 
							+ (pNowKData[p2].nMin / 60);
						usrCJD[nCJDCount - 1].nP1 = p1;
						usrCJD[nCJDCount - 1].nP3 = p3;
						usrCJD[nCJDCount - 1].nStatus = nFX;
						iChangeed = 0;
					}
				}
			}

			if (iChangeed == 2)  //���������Ч���ͣ�ֱ����������һ������
			{
				l1 = l2, l2 = l3, h1 = h2, h2 = h3;
				p1 = p2, p2 = p3, p3 = i;
				l3 = pNowKData[p3].fLow;
				h3 = pNowKData[p3].fHigh;
			}
			else if (iChangeed == 0)
				//��Ч���ͺ�Ĵ��� ȷ��������������֮��û�й�����K��
			{
				p1 = p3;
				l1 = l3;
				h1 = h3;
				p2 = p1 + 1;
				l2 = pNowKData[p2].fLow;
				h2 = pNowKData[p2].fHigh;
				p3 = p2 + 1;
				l3 = pNowKData[p3].fLow;
				h3 = pNowKData[p3].fHigh;
				i = p3 + 1;
				while (h1 >= h2 && l1 <= l2)  //1-2ǰ����,��l2
				{
					l2 = l3, h2 = h3;
					p2 = p3, p3 = i++;
					l3 = pNowKData[p3].fLow;
					h3 = pNowKData[p3].fHigh;
					iChangeed = 1;
					if (i>DataLen - 1) break;
				}
			}
		}

		int nMinLow = this->nMinLow;
		int nMaxHigh = this->nMaxHigh;
		for (i = 1; i<nCJDCount; i++)
		{
			ResultOut(&pfOUT, usrCJD[i].nPlace, (float)usrCJD[i].nStatus);
			usrCJD[i].bIsUp = false;//��ʼ���߶�Ϊȱʡ�µ�״̬
		}
		//��ǰ���㴴�¸��µ��ж�
		if (usrCJD[nCJDCount - 1].nP3 == DataLen - 1)
		{
			this->nStatus = usrCJD[nCJDCount - 1].nStatus;

			this->nNewHighLow = 0;

			if ((nMaxHigh > usrCJD[nCJDCount - 1].nP1 && nMaxHigh < usrCJD[nCJDCount - 1].nP3)
				|| (nMinLow > usrCJD[nCJDCount - 1].nP1 && nMinLow < usrCJD[nCJDCount - 1].nP3))
			{
				this->nNewHighLow = usrCJD[nCJDCount - 1].nStatus;
				usrCJD[nCJDCount - 1].nNewHighLow = usrCJD[nCJDCount - 1].nStatus;
			}


		}
		else
			this->nStatus = 0;

	}

	int CaclCFX(int p1, int p2, int p3)
	{
		int out = 0;

		float h1 = pNowKData[p1].fHigh,
			h2 = pNowKData[p2].fHigh,
			h3 = pNowKData[p3].fHigh;

		float l1 = pNowKData[p1].fLow,
			l2 = pNowKData[p2].fLow,
			l3 = pNowKData[p3].fLow;

		float o1 = pNowKData[p1].fOpen,
			o2 = pNowKData[p2].fOpen,
			o3 = pNowKData[p3].fOpen;

		float c1 = pNowKData[p1].fClose,
			c2 = pNowKData[p2].fClose,
			c3 = pNowKData[p3].fClose;

		if (h2>h1 && h2>h3 && l2>l1 && l2>l3)  //������  h2��l2��� 
		{
			out = -3;
			/*������K��������Ƶ�һ��K�ߵĵײ��������̲����յ���
			һ��K������һ��֮�ϣ�������ǿ�Ķ����ͣ����н�ǿ��ɱ����*/
			if (l3<l1 && c3<l1 + (h1 - l1) / 2)
				out = -1;

			/*����ڶ���K���ǳ���Ӱ��������ֱ�ӵĳ�������������K�߲�������
			�����ڵڶ���K������һ��֮�ϣ���ô�÷��͵����ȾͱȽϴ�
			����ͨ��ʵ�岿��ָ����7%������Ӱָ��Ӱ�߷��ȴ���5%��*/
			if (c2<o2 && (((o2 - c2) / c1)>0.07 || ((h2 - o2) / c1)>0.05))
				out = -2;
		}
		else if (l2<l1 && l2<l3 && h2<h1 && h2<h3) //�׷���  h2��l2���
		{
			out = 3;
			/*������K��������Ƶ�һ��K�ߵĶ������������յ���
			һ��K������һ��֮�ϣ�������ǿ�ĵ׷��ͣ����н�ǿ��������*/
			if (h3>h1 && c3>l1 + (h1 - l1) / 2)
				out = 1;

			/*����ڶ���K���ǳ���Ӱ��������ֱ�ӵĳ�������������K������
			�����ڵڶ���K������һ��֮�ϣ���ô�÷��͵����ȾͱȽϴ�
			����ͨ��ʵ�岿��ָ����7%������Ӱָ��Ӱ�߷��ȴ���5%��*/
			if (c2>o2 && (((c2 - o2) / c1)>0.07 || ((o2 - l2) / c1)>0.05))
				out = 2;
		}

		return out;

	}

	//����������µ�ʱ�Ƿ�������࣬������򷵻�true
	bool CheckZSInPZ(int i)
	{
		CZSPZInfo usrZSPZ;
		int n;
		float f;
		bool bRet = false;
		//�ݴ浱ǰ������Ϣ
		memcpy(&usrZSPZ, &usrCZSPZ[nCZSPZCount], sizeof(CZSPZInfo));

		bRet = CaclCZS(i, &n, &f);
		//�ָ���ǰ������Ϣ
		memcpy(&usrCZSPZ[nCZSPZCount], &usrZSPZ, sizeof(CZSPZInfo));

		return  bRet;
	}

	//��������  NewHighLow=1 nCJDIndex+2�����¸�
	//					 =-1 nCJDIndex+2�����µ�
	//          fData    ���¸߻��µ�ʱ������      
	bool	CaclCPZ(int	nCJDIndex, int *NewHighLow, float *fData)
	{
		int		i = nCJDIndex;
		bool	bNewPZ = false;
		*NewHighLow = 0;
		*fData = 0;
		float	h1, l1;

		//2 �ж������������������ʱȽ����ж�
		if (nCJDCount - i>2)
		{
			//if (usrCJD[i + 1].nLineBi<11)
			{
				usrCZSPZ[nCZSPZCount].bIsZS = false;
				usrCZSPZ[nCZSPZCount].bIsUp = (usrCJD[i - 1].nStatus >0);

				usrCZSPZ[nCZSPZCount].p2 = i + 2;

				if (usrCJD[i - 1].nStatus >0)
				{
					h1 = max(pNowKData[usrCJD[i].nPlace].fHigh, pNowKData[usrCJD[i + 2].nPlace].fHigh);
					l1 = min(pNowKData[usrCJD[i - 1].nPlace].fLow, pNowKData[usrCJD[i + 1].nPlace].fLow);

					//�������¸�����
					usrCZSPZ[nCZSPZCount].p1 = i - 1;
					while (nCJDCount - i >= 2)
					{
						//����������µ�ʱ�Ƿ�������࣬��������˳�ѭ��������������
						if (CheckZSInPZ(i) == true) break;

						if (pNowKData[usrCJD[i + 2].nPlace].fHigh
							- pNowKData[usrCJD[i].nPlace].fHigh>0.0)
						{
							*NewHighLow = 1;
							h1 = pNowKData[usrCJD[i + 2].nPlace].fHigh;
							*fData = h1;
							bNewPZ = true;
							i += 2;
							usrCZSPZ[nCZSPZCount].p2 = i;
						}
						else
							break;

						usrCZSPZ[nCZSPZCount].fHigh = h1;
						usrCZSPZ[nCZSPZCount].fLow = l1;
					}
				}
				else
				{
					h1 = max(pNowKData[usrCJD[i - 1].nPlace].fHigh, pNowKData[usrCJD[i + 1].nPlace].fHigh);
					l1 = min(pNowKData[usrCJD[i].nPlace].fLow, pNowKData[usrCJD[i + 2].nPlace].fLow);
					//�������µ�����
					usrCZSPZ[nCZSPZCount].p1 = i - 1;
					while (nCJDCount - i >= 2)
					{
						//����������µ�ʱ�Ƿ�������࣬��������˳�ѭ��������������
						if (CheckZSInPZ(i) == true) break;

						if (pNowKData[usrCJD[i + 2].nPlace].fLow
							- pNowKData[usrCJD[i].nPlace].fLow<0.0)
						{
							*NewHighLow = -1;
							l1 = pNowKData[usrCJD[i + 2].nPlace].fLow;
							*fData = l1;
							bNewPZ = true;
							i += 2;
							usrCZSPZ[nCZSPZCount].p2 = i;
						}
						else
							break;

						usrCZSPZ[nCZSPZCount].fHigh = h1;
						usrCZSPZ[nCZSPZCount].fLow = l1;
					}
				}
			}
		}
		usrCZSPZ[nCZSPZCount].fMaxLow = 0;
		usrCZSPZ[nCZSPZCount].fMinHigh = 0;
		return	bNewPZ;
	}

	//��������  NewHighLow=1 nCJDIndex+2�����¸�
	//					 =-1 nCJDIndex+2�����µ�
	//          fData  �¸߻��µ�����
	//todo  20160730 �����ڴ��¸ߡ��µʹ�����  �����ഴ�¸�  �����࣬��֮������
	//�����ڼȲ����¸�Ҳ�����µ����������������෽��
	bool	CaclCZS(int	nCJDIndex, int *NewHighLow, float *fData)
	{
		//���ನ����Χ
#define  ZSVARRATE 10 
		int	iLineCount = 0;
		int	i = nCJDIndex;
		float h1, l1, fFirstPenHigh, hMax = 0.0, lMin = 99999.0;
		bool bNewZS = false;

		*NewHighLow = 0;

		//1 �����жϣ���4�������ıʱȽ����ж�
		if (nCJDCount - i>3)
		{
			//����2�ʳ��Ƚӽ����������
			/*if (usrCJD[i + 1].nLineBi >= 3 && usrCJD[i + 1].nLineBi <= 44
			&& usrCJD[i + 2].nLineBi >= 3 && usrCJD[i + 2].nLineBi <= 44 )*/
			{
				int nZSPercent;
				if (usrCJD[i].nStatus <0)// ������ ��������
				{

					//���๫���۸񲿷�
					h1 = min(pNowKData[usrCJD[i].nPlace].fHigh,
						pNowKData[usrCJD[i + 2].nPlace].fHigh);
					l1 = max(pNowKData[usrCJD[i + 1].nPlace].fLow,
						pNowKData[usrCJD[i + 3].nPlace].fLow);

					//����ߵͼ�λ
					hMax = max(max(hMax, pNowKData[usrCJD[i].nPlace].fHigh),
						pNowKData[usrCJD[i + 2].nPlace].fHigh);
					lMin = min(min(lMin, pNowKData[usrCJD[i + 1].nPlace].fLow),
						pNowKData[usrCJD[i + 3].nPlace].fLow);

					*NewHighLow = 1;
					*fData = hMax;

					fFirstPenHigh = pNowKData[usrCJD[i].nPlace].fHigh
						- pNowKData[usrCJD[i + 1].nPlace].fLow;
				}
				else //�׷���  �µ�����
				{
					h1 = min(pNowKData[usrCJD[i + 1].nPlace].fHigh,
						pNowKData[usrCJD[i + 3].nPlace].fHigh);
					l1 = max(pNowKData[usrCJD[i].nPlace].fLow,
						pNowKData[usrCJD[i + 2].nPlace].fLow);

					hMax = max(max(hMax, pNowKData[usrCJD[i + 1].nPlace].fHigh),
						pNowKData[usrCJD[i + 3].nPlace].fHigh);
					lMin = min(min(lMin, pNowKData[usrCJD[i].nPlace].fLow),
						pNowKData[usrCJD[i + 2].nPlace].fLow);

					*NewHighLow = -1;
					*fData = lMin;

					fFirstPenHigh = pNowKData[usrCJD[i + 1].nPlace].fHigh
						- pNowKData[usrCJD[i].nPlace].fLow;
				}

				nZSPercent = (int)(100 * (h1 - l1) / fFirstPenHigh);

				//h1 - l1>0.0������Ч,���ನ���ܴ�ʱ��Ϊ��������
				if (h1 - l1>0.0 /*&& nZSPercent<ZSVARRATE*/)
				{
					usrCZSPZ[nCZSPZCount].bIsZS = true;
					usrCZSPZ[nCZSPZCount].p1 = i;
					usrCZSPZ[nCZSPZCount].p2 = i + 3;

					usrCZSPZ[nCZSPZCount].fMaxLow = l1;
					usrCZSPZ[nCZSPZCount].fMinHigh = h1;
					usrCZSPZ[nCZSPZCount].fHigh = hMax;
					usrCZSPZ[nCZSPZCount].fLow = lMin;
					i += 4;
					bNewZS = true;

					//�������촦��:����������������ǰһ�ʺ͵�ǰ��
					while ((PenInCZS(i, nCZSPZCount) == 0 && PenInCZS(i + 1, nCZSPZCount) == 0)
						&& nCJDCount - i >= 1)
					{
						bool  bNewLow = false, bNewHigh = false;

						if (usrCJD[i].nStatus >0)
						{
							//�׷��ʹ������Ƿ�����µ�
							hMax = max(hMax, pNowKData[usrCJD[i - 1].nPlace].fHigh);
							lMin = min(lMin, pNowKData[usrCJD[i].nPlace].fLow);

							bNewLow = (lMin - pNowKData[usrCJD[i].nPlace].fLow == 0.0) //��ǰ���㴴�µ�
								&& (lMin - usrCZSPZ[nCZSPZCount - 1].fLow<0.0)  //��ǰ���ǰһ�����������µ�
								&& (pNowKData[usrCJD[i + 2].nPlace].fLow - lMin>0.0);  //��һ�ͷ���δ���µ�

							if (bNewLow == true)
							{
								*NewHighLow = -1;
								*fData = lMin;
							}
						}
						else
						{
							//�����ʹ������Ƿ�����¸�
							hMax = max(hMax, pNowKData[usrCJD[i].nPlace].fHigh);
							lMin = min(lMin, pNowKData[usrCJD[i - 1].nPlace].fLow);

							bNewHigh = (hMax - pNowKData[usrCJD[i].nPlace].fHigh == 0) //��ǰ���㴴�¸�
								&& (usrCZSPZ[nCZSPZCount - 1].fHigh - hMax<0.0)   //��ǰ���ǰһ�����������¸�
								&& (pNowKData[usrCJD[i + 2].nPlace].fHigh - hMax<0.0); //��һ������δ���¸�

							if (bNewHigh == true)
							{
								*NewHighLow = 1;
								*fData = hMax;
							}
						}
						usrCZSPZ[nCZSPZCount].fHigh = hMax;
						usrCZSPZ[nCZSPZCount].fLow = lMin;

						//�����ڳ����¸߻��µ�ʱ�˳����㣬������ǰ��Ч����
						if (bNewHigh == true || bNewLow == true)
						{
							usrCZSPZ[nCZSPZCount].p2 = i;
							break;
						}
						else
							i++;

					}

					if (i - 1 - usrCZSPZ[nCZSPZCount].p2>0)
					{
						if (nCJDCount == i)
							i--;

						usrCZSPZ[nCZSPZCount].p2 = i;
					}
				}
			}

		}
		return bNewZS;
	}

	//�����������������㱳��  ͨ������  pfType 1 һ�����,2 ���������  -1һ������ -2 �������� 
	//       pfMode	   1=MACD 2=DIF 3=DEA
	void CaclBSPoint(int DataLen, float* pfOUT, float* pfMode, float* pfType, float* pfMACD)
	{
		int	nType = (int)pfType[0];

		/*
		��ǰ��������Ч���ж�
		��Ч�ĵ׷���
		1�����µ͵ĵ׷��Ͳ�����5����������5���ھ��߲��ò�����ֵ
		2�����µ͵ĵ׷��Ͳ��������������µĵ׷��͵�δ���µ͡��м�û�ж����ͣ�
		�׷��������5����������5���ھ��߲��ò�����ֵ
		3�����µ͵ĵ׷��Ͳ������γ�һ�������ʺ�С�����࣬��������һ���׷���
		5����������5���ھ���

		��Ч�Ķ�����
		1�����¸ߵĶ����Ͳ�����5�����ڵ���5���ھ��߲��ò�����ֵ
		2�����¸ߵĶ����Ͳ��������������µĶ����͵�δ���¸ߡ��м�û�е׷��ͣ�
		�����������5�����ڵ���5���ھ��߲��ò�����ֵ
		3�����¸ߵĶ����Ͳ������γ�һ�������ʺ�С�����࣬��������һ��������
		5�����ڵ���5���ھ���
		*/

		//�������
		if (usrCJD[nCJDCount - 1].nStatus < 0 //�����ͺ��µ�
			&& pNowKData[usrCJD[nCJDCount - 1].nPlace].fHigh>pNowKData[DataLen - 1].fHigh)
		{
			//20170319�����жϣ���ǰK����߼۵��ڶ����͸�ֵ�������µ�����
			//���¸ߵĶ���������ʱ����ֹ���λ���¸߶�������߼���ͬ������ۣ������ﵽһ���̶�ʱ��ֹ��
			if (usrCJD[nCJDCount - 1].nP3 == DataLen - 1 && usrCJD[nCJDCount - 1].nNewHighLow < 0)
				this->fAutoDownSellPrice = pNowKData[usrCJD[nCJDCount - 1].nPlace].fHigh
				*(1.0 - (float)AUTODOWNSELLGATE / 100);

			//�����ͺ���ƶ����ھ���ʱ������������ʱ���д���
			if (pNowKData[DataLen - 1].fClose - this->fMAShort[DataLen - 1] < 0.0
				&& nType < 0) //�����ͽ����������������������������  ���������Ƿ񶥱���
			{
				CheckSellSignal(DataLen, pfMode, pfType, pfMACD);
			}
		}

		//������
		if (    nType > 0
			&&  usrCJD[nCJDCount - 1].nStatus > 0  //�׷���
			|| (usrCJD[nCJDCount - 1].nStatus < 0  //�����ͺ������
				&& pNowKData[usrCJD[nCJDCount - 1].nPlace].fHigh<pNowKData[DataLen - 1].fHigh))
			//20170319�����жϣ���ǰK����߼۸��ڶ����͸�ֵ��������������
		{
			//�׷��ͱ������ƶ����ھ���:���ϣ������о��߶�Ҫ����
			CheckBuySignal(DataLen, pfMode, pfType, pfMACD);
		}
	}


	//�����������������������ź�  ͨ������  pfType 1 һ�����,2 ���������  -1һ������ -2 �������� 
	//       pfMode	   1=MACD 2=DIF 3=DEA
	//       ���Ż�����㷨��Ҫ�жϱ������������ǰ�ڸߵ������  20170403
	void CheckBuySignal(int DataLen, float* pfMode, float* pfType, float* pfMACD)
	{
		int	nLastestZSPZ;
		int	nMode = (int)pfMode[0], nType = (int)pfType[0];
		int	nDelta = 3, nStart;
		int	nDown;

		/*
		�ױ��۷���	 ������
		1)	�ӷ��������ڵ���ߵ㶥���Ϳ�ʼ�����µ������������ࣻ
		2)	�������ϴ��µ͵��������������ڼ����һ�����������ߵ���������Ϊ�����ϵ����ƣ�
		�ӵڶ��δ��µͿ�ʼ�ж��Ƿ���ֱ��ۣ������ּ����֮��
		3)  Ŀǰ���²�������ֹ�ڵ�ǰ��������K�ߴ����ұ����ǵ׷���
		*/
		if (nType >= 1 && nCZSPZCount >= 4  //������������Ҫ��3���Ž��з���
			/*&& this->VolMAUp( DataLen,MALONG,3)==true*/)  //�ɽ��������Ŵ�
		{
			nLastestZSPZ = nCZSPZCount - 1;
			
			//���ڲ����µ��׶������
			//���µ�����Ѱ��Ǳ�������

			//����������������ֵ�����ĵ���
			nDown = 100 - 100 * pNowKData[usrCJD[usrCZSPZ[nLastestZSPZ].p2].nPlace].fClose
				/ this->fMaxHigh;

			//����������������ֵ֮���CJD���
			this->CaclCJDTBPoint(pfMACD, DataLen);
			// ����������������ܷ��
			this->CaclEnergyTopBtn(pfMACD, DataLen);
				
			int nBC= this->BtnBC(usrCZSPZ[nLastestZSPZ].p2);
			//int nBC = this->BtnBC(nCJDCount-1);
			if( ( nBC> 1 && nType==1 )   //һ�򣺳���2�δ��µ͵ױ���    
										 //2������1�εױ���
				|| (nBC>1 && nType>1) )
			{
				this->bBSChanged = true;

				//��¼���������YMD
				nLatesBuyYmd = pNowKData[DataLen - 1].nYmd;
				if(nType>1)
					AddBuy(DataLen - 1, DataLen - 1, BSTYPE_2BUY, nMode, nDown);
				else
					AddBuy(DataLen - 1, DataLen - 1,BSTYPE_ZSBC, nMode, nDown);
			}
			else 
			{
				//�жϴ��׶��¸ߵ�ʱ��  �������׺ܴ�
				if (CheckStepUp(DataLen) == true)
					this->AddBuy(DataLen - 1, DataLen - 1,
						BSTYPE_STEPUP, nMode, nDown);
			}
			return;
		}//if (nType >= 1 && nCZSPZCount >= 4
	}

	//���ͻ�ƽ׶��¸��Ƿ����
	/*ͻ�ƽ׶��¸���������
		1�����ж̾��߾�������
		2��������������ߵ��ĵ͵��ҳ��ֳ���15%(MAXSTEPDOWN)�ĵ�����
		3��δ���ֶ����ۣ�
		4��������������ߵ������µĲ��������6�����ϼ��㣻
		5����ǰK���������Ҹ��ڶ̾��ߣ�
		6�����ܻ��ж��ͻ�ƽ׶��¸ߡ�*/
	bool CheckStepUp(int nDataLen)
	{
		bool  bRet = false;

		if (    fCurClose>fMAShort[nDataLen-1]   //��ǰK���������Ҹ��ڶ̾���
			 && MAUp(nDataLen - 1, fMALong, 3) 
			 && MAUp(nDataLen - 1, fMAMid, 3) 
			 && MAUp(nDataLen - 1, fMAShort, 3)
			 && nMaxHigh>nMinLow                 //�����������������ͺ�
			 && this->TopBC(nCJDCount - 1) <= 0) //û�г��ֶ�����
		{
			//ָ�������������ߵ�,ͬʱ������͵��Ķ������Ƿ�����
			int nMaxCJD = nCJDCount - 1;
			int nLastGate= max(nMinLow, nMaxHigh); //�뵱ǰK���������͵� / ��ߵ�λ��
			float fLastHigh = 0;
			if ( usrCJD[nMaxCJD].nStatus>0)   nMaxCJD--;
			for (; nMaxCJD>0 && usrCJD[nMaxCJD].nPlace > nMaxHigh; nMaxCJD -= 2)
			{
				//������͵�/��ߵ��Ķ������Ƿ�����
				if (usrCJD[nMaxCJD].nPlace >nLastGate)
				{
					if (fLastHigh > pNowKData[usrCJD[nMaxCJD].nPlace].fHigh) continue;

					fLastHigh = pNowKData[usrCJD[nMaxCJD].nPlace].fHigh;

					if (fCurClose > fLastHigh && pNowKData[nDataLen - 1].fOpen<fLastHigh)
					{
						//�������ƶ�����
						bRet = true;
						return bRet;
					}
				}
			}

			if (nMaxCJD > 0 && nCJDCount- nMaxCJD>6)
				nMaxCJD += 2;
			else
				return bRet;

			//��ǰ�ڸߵ�������׶��ԵĲ�����׵㣬���������Ƿ�ﵽ15%
			int nMinCJD= nMaxCJD + 1;
			int fMinLow=999999;
			if (nMinCJD > 0 && usrCJD[nMinCJD].nStatus<0)   nMinCJD++;
			for (; nMinCJD < nCJDCount; nMinCJD += 2)
			{
				if (fMinLow > pNowKData[usrCJD[nMinCJD].nPlace].fLow)
					fMinLow = pNowKData[usrCJD[nMinCJD].nPlace].fLow;
			}

			if (100-100*fMinLow/fMaxHigh>MAXSTEPDOWN)
			{
				fLastHigh = 0;
				//������ߵ���͵��Ķ������Ƿ񱻵�ǰK������
				//�������ƶ����Ͳ���Ϊ����Ч����
				for (int k= nMinCJD - 1; usrCJD[k].nPlace>nMaxHigh; k-=2)
				{
					if (fLastHigh > pNowKData[usrCJD[k].nPlace].fHigh) continue;

					fLastHigh = pNowKData[usrCJD[k].nPlace].fHigh;

					if (fCurClose <= fLastHigh)
						break;
					else if(fCurClose > fLastHigh && pNowKData[nDataLen-1].fOpen<fLastHigh)
					{
						//�������ƶ�����
						bRet = true;
						break;
					}
				}
			}
		}
		
		return bRet;

	}
	//����������������������  ͨ������  pfType 1 һ�����,2 ���������  -1һ������ -2 �������� 
	//       pfMode	   1=MACD 2=DIF 3=DEA
	void CheckSellSignal(int DataLen, float* pfMode, float* pfType, float* pfMACD)
	{
		int	nMode = (int)pfMode[0], nType = (int)pfType[0];
		int	nDown;

		/*	�������
		�����۷���
		1)	������������������ʼ������
		2)	�������ϴ��¸ߵ��������������ڼ����һ�����������ߵ㽵������Ϊ�����������ƣ��ӵڶ��δ��¸߿�ʼ�ж��Ƿ���ֱ��ۣ������ּ����֮��
		*/

		//���¸ߺ����5%���ϵĵ�����������   �����������ڣ��������¸ߺ�վ����  TODO 20170223
		if ((nType <= -1))
		{
			//������ƽ���Ƿ�
			if (this->fAveragePrice == 0.0)
				//��ѡ�ֲֻ�ָ��
				nDown = 100;
			else
				nDown = -100 + 100 * pNowKData[usrCJD[nCJDCount - 1].nPlace].fClose
				/ this->fAveragePrice;

			//����������Ѱ��Ǳ�������㣬�����������յ�
			//�������һ�γ��ֵ��������������
			this->CaclCJDTBPoint(pfMACD, DataLen);
			this->CaclEnergyTopBtn(pfMACD, DataLen);
			//�����������϶�����ʱ�����ֲ���
			if (this->TopBC(nCJDCount - 1)>=2)
			{
				//�����׶β�Ӧ����  20170314
				this->bBSChanged = true;
				this->AddSell(DataLen - 1, DataLen - 1,
					-BSTYPE_ZSBC, nMode, nDown);
			}

			if (this->MADown(DataLen) == true)
			{
				//���ж̾��߾��µ������µ����ƺ����ԣ������������
				this->bBSChanged = true;
				this->AddSell(DataLen - 1, DataLen - 1,
					-BSTYPE_JXDOWN, nMode, nDown);
			}
		}
	}

	//���Ŀǰ�Ƿ��������
	//���ж̾���ȫ���������������������ﵽֹ�����
	bool DetectSellSignal(int DataLen)
	{
		bool bRet = false;

		if (100 - 100 * fCurClose / fMaxHigh>AUTODOWNSELLGATE)
		{
			bRet = MADown(DataLen);
		}

		return bRet;

	}

	//���÷�����������ת�����ݵĵ�nCount+1������ͼ۸����5��
	/*
	 �ڲ��������У�ͻ��ǰ�ڸߵ͵�������ζ�Ų����µ��µ����������ơ�ͼ�к��ߴ�����ڸߵ㣬���ߴ�����ڵ͵㡣
		1���������ƣ�ͻ��ǰ�ڸߵ��ҳ��ж̾��߾���
		2���µ����ƣ�ͻ��ǰ�ڵ͵��ҳ��ж̾��߾���
		3���������ƣ������жϵ����ܼ��������̵��ж������ܼ�����  
		4) ���Ʒ�ת���޷��ж����Ʒ�ת�����㷨��ʱ���ã��û��ڲ�����ķ�Ƚ��н��ڸߵ͵��ж�
	*/
	void	SetLastestMaxHighMinLow(int nDataLen)
	{
		int	 i,k,nCount;

		for (i = 0; i < LASTESTHIGHLOWCOUNT; i++)
		{
			m_usrLastestHigh[i].fValue = -999999;
			m_usrLastestHigh[i].fEnergy = -999999;
			m_usrLastestHigh[i].nIndex = -1;
			m_usrLastestLow[i].fValue = 999999;
			m_usrLastestLow[i].fEnergy = 999999;
			m_usrLastestLow[i].nIndex = -1;
		}

		i = 0;
		k = LASTESTHIGHLOWCOUNT - 1;
		m_usrLastestHigh[k].fValue = pNowKData[i].fHigh;
		m_usrLastestHigh[k].nIndex = i;
		m_usrLastestLow[k].fValue = pNowKData[i].fLow;
		m_usrLastestLow[k].nIndex = i;

		//���µ�����ʱû�����ֵ������������û�����ֵ����
		for ( i = 1; i<nDataLen; i++)
		{
			//���ֵ  
			//��High���ݽ���High��Indexͬʱ������������
			if (m_usrLastestHigh[k].fValue < pNowKData[i].fHigh )
			{
				nCount = k* sizeof(TBPoint);
				_memccpy(m_usrLastestHigh , m_usrLastestHigh +1 ,nCount,nCount );
				m_usrLastestHigh[k].fValue = pNowKData[i].fHigh;
				m_usrLastestHigh[k].nIndex = i;
						
			}
				
			//���ֵ
			//��Low���ݽ��н�������
			if (m_usrLastestLow[k].fValue - pNowKData[i].fLow > 0)
			{
				nCount = (k) * sizeof(TBPoint);
				_memccpy(m_usrLastestLow , m_usrLastestLow +1 , nCount, nCount);
				m_usrLastestLow[k].fValue = pNowKData[i].fLow;
				m_usrLastestLow[k].nIndex = i;
			}
			
		}
	}
	
	//���÷�����������ת�����ݵ������ͼ۸�
	void	SetMaxHighMinLow(int	nDataLen)
	{
		int	i = 0, k;
		int	nMaxHigh = 0, nMinLow = 0;
		float fMaxHigh = -1, fMinLow = 999999;

		for (; i<nDataLen; i++)
		{
			//�������һ���������������ֵ  �����ж��Զ�������ʱ��
			if (fMaxHigh - pNowKData[i].fHigh <0)
			{
				if (pNowKData[i].nYmd >nLatesBuyYmd)
				{
					fMaxHigh = pNowKData[i].fHigh;
					nMaxHigh = i;
				}
			}

			//������������ڵ���Сֵ  ���ڷ���1��ʱ��
			if (fMinLow - pNowKData[i].fLow >0)
			{
				if (pNowKData[i].nYmd >nLatesBuyYmd)
				{
					fMinLow = pNowKData[i].fLow;
					nMinLow = i;
				}
			}
		}

		this->nMaxHigh = nMaxHigh;
		this->fMaxHigh = fMaxHigh;
		this->nMaxHighYmd = pNowKData[nMaxHigh].nYmd;
		this->nMaxHighMin = pNowKData[nMaxHigh].nMin;

		this->nMinLow = nMinLow;
		this->fMinLow = fMinLow;
		this->nMinLowYmd = pNowKData[nMinLow].nYmd;
		this->nMinLowMin = pNowKData[nMinLow].nMin;

	}

	//��ͣ�ж�  TODO ����ST���Ʊ���ж�20170311
	bool   UpStop(int nDataLen, StockInfo *ptr5MinKInfo)
	{
		if (fLastDateClose > 0)
			return  (ptr5MinKInfo + nDataLen - 1)->fClose / fLastDateClose  > 1.09;
		else
			return false;
	}

	//��ͣ  TODO ����ST���Ʊ���ж�20170311
	bool   DownStop(int nDataLen, StockInfo *ptr5MinKInfo)
	{
		if (fLastDateClose > 0)
			return  (ptr5MinKInfo + nDataLen - 1)->fClose / fLastDateClose < 0.91;
		else
			return false;
	}

	//����ǰһ���������̼ۣ������ж���ͣ���ͣ
	void   SetLastDateDayClose(int nDataLen, StockInfo *ptr5MinKInfo)
	{
		int nTimeDiff = TimeDiff((ptr5MinKInfo + nDataLen - 1)->nMin, 570) / 5;
		int nTmp = nDataLen - nTimeDiff - 1;
		if (nTmp >= 0)
		{
			fLastDateClose = (ptr5MinKInfo + nTmp)->fClose;
		}
		else
			fLastDateClose = -1.0;
	}


	//�ж��Ƿ�����nCount���ڳ���ǰ�ڸߵ��������̼۳�������
	bool	StepUp(int nDataLen, StockInfo *pStockInfo, float fMaxHigh, int nCount)
	{
		bool bRet = true;

		if (nCount <= 0 || fMaxHigh<=0)
			return false;

		int j = max(nDataLen - nCount, 0);

		do
		{
			bRet = ((pStockInfo + j)->fClose >fMaxHigh)
				&& ((pStockInfo + j)->fClose >= (pStockInfo + j - 1)->fClose);
		} while (j++ < nDataLen  && bRet == true);

		return bRet;
	}

	//�ж�ָ�����������5����K�������Ƿ����������ɽ����Ƿ���������

	bool	VOLUp5Min(int nDataLen, int nCount)
	{
		bool bRet = true;

		if (nCount <= 0)
			return false;

		//����������ĳɽ���
		int j = max(g_nStockDownDays*48 - nCount - 2, 0);

		do
		{
			bRet = (p5MinKData[j + 1].nNumber >= p5MinKData[j].nNumber);
		} while (j++ < nDataLen - 2 && bRet == true);

		return bRet;
	}

	//��ǰ���������ڳɽ����Ƿ���������
	bool	VOLUp(int nDataLen, int nCount)
	{
		bool bRet = true;

		if (nCount <= 0)
			return false;

		//����������ĳɽ���
		int j = max(nDataLen - nCount - 2, 0);

		do
		{
			bRet = (pNowKData[ j + 1].nNumber >= pNowKData [j].nNumber );
		} while (j++ < nDataLen - 2 && bRet == true);

		return bRet;
	}

	//�ж�ָ�������Ƿ�������nCount��������
	bool	MAUp(int nDataLen, float *pMa, int nCount)
	{
		bool bRet = true;

		if (nCount <= 0)
			return false;

		//����������ľ�ֵ��̫Զ�ľ�ֵ���������������
		int j = max(nDataLen - nCount , 0);

		do
		{
			bRet = (*(pMa + j + 1) >= *(pMa + j));
		} while (j++ < nDataLen-1  && bRet == true);

		return bRet;
	}

	//�ж�ָ�������Ƿ�������nCount���ڵ�
	bool	MADown(int nDataLen, float *pMa, int nCount)
	{
		bool bRet = true;

		if (nCount <= 0)
			return false;

		//����������ľ�ֵ��̫Զ�ľ�ֵ���������������
		int j = max(nDataLen - nCount - 2, 0);

		do
		{
			bRet = (*(pMa + j + 1) < *(pMa + j));
		} while (j++ < nDataLen - 2 && bRet == true);

		return bRet;
	}

	//�ɽ�����ֵ�Ƿ���� �����nCount�����ڳɽ������ж̾�ֵ�Ƿ������ 
	bool	VolMAUp(int nDataLen, int nLong, int nCount)
	{
		bool bRet = true;

		if (nDataLen < nLong || nLong <= 0 || nCount <= 0)
			return false;

		//����������ľ�ֵ��̫Զ�ľ�ֵ���������������
		int j = max(nDataLen - nLong * 2 - nCount - 1, 0);

		do
		{
			bRet = (*(nVolMaLong + j + 1) > *(nVolMaLong + j))
				&& (*(nVolMid + j + 1) > *(nVolMid + j))
				&& (*(nVolShort + j + 1) > *(nVolShort + j));
		} while (j++ < nDataLen - nLong && bRet == true);

		return bRet;
	}


	//�ɽ�����ֵ�Ƿ�ݼ� �����nCount�����ڳɽ������ж̾�ֵ�Ƿ���ݼ� 
	bool	VolMADown(int nDataLen, int nLong, int nCount)
	{
		bool bRet = true;

		if (nDataLen < nLong || nLong <= 0 || nCount <= 0)
			return false;

		//����������ľ�ֵ��̫Զ�ľ�ֵ���������������
		int j = max(nDataLen - nLong - nCount - 1, 0);

		do
		{
			bRet = (*(nVolMaLong + j + 1) < *(nVolMaLong + j))
				&& (*(nVolMid + j + 1) < *(nVolMid + j))
				&& (*(nVolShort + j + 1) < *(nVolShort + j));
		} while (j++ < nDataLen - nLong && bRet == true);

		return bRet;
	}


	//������������ڵ����ܷ�ֵ��ֵ
	//��ֵ�Ӵ�С����ֵ��С����
	//���ڲ�������м���
	void	CaclEnergyTopBtn(float *pfMACD, int  nDataLen)
	{
		int k;

		for (k = 0; k < TBPOINTCOUNT; k++)
		{
			mMaxEnergy[k].fEnergy = -99999, mMaxEnergy[k].fValue = -99999, mMaxEnergy[k].nIndex = -1;
			mMinEnergy[k].fEnergy = 99999, mMinEnergy[k].fValue = 99999, mMinEnergy[k].nIndex = -1;
		}

		int		i = nCJDCount - 1;

		//����������������������ܸߵ͵����Ҫ
		if (   nLatesBuyYmd <= nCurYmd && nLatesBuyYmd>0 ) //�����
		{
			//ָ������������ں�ĵ�һ�������㣬��¼�ϳ���µ��������
			//�ϳ�׶Σ����δ���ֶ����ۣ��߱������������µ��׶Σ����ֵױ��۾߱���������
			while (pNowKData[usrCJD[i].nP1].nYmd > nLatesBuyYmd && i>0)
				i--; // �����������������

			i++;
			CaclUpEnergy(i, pfMACD);
			CaclDownEnergy(i, pfMACD);
		}
		else if (nLatesBuyYmd == 0 && nMinLow < nMaxHigh) //�µͺ��¸�
		{
			//ָ���µͺ�ĵ�һ�������㣬��¼�ϳ����ܱ仯��ͬʱ�����µ�ǰ���µ�����
			//�ϳ�׶Σ����δ���ֶ����ۣ��߱������������µ��׶Σ����ֵױ��۾߱���������
			while (usrCJD[i].nP1>nMaxHigh	&& i>0)	i--; // ��������

			i++;
			CaclDownEnergy(i, pfMACD);
			CaclUpEnergy(i, pfMACD);
		}
		//һ�����������Ҫ���ܵ͵�
		else if (nLatesBuyYmd == 0 && nMinLow > nMaxHigh)
		{
			int nStart = 0;//�������
			float fHigh = -999999.0;

			//�͵��ڸߵ�󣬴��µ����
			//�ϳ�׶Σ����δ���ֶ����ۣ��߱������������µ��׶Σ����ֵױ��۾߱���������
			//ָ�������������ߵ����ں��׸������㣬������¼���µ����ܱ仯
			while (usrCJD[i].nP1> nMaxHigh && i > 0) i--;

			i++;
			CaclDownEnergy(i, pfMACD);

			//ָ�������������͵����ں��׸������㣬������¼���������ܱ仯
			i = nCJDCount - 1;
			while (usrCJD[i].nP1> nMinLow && i > 0) i--;
			i++;
			CaclUpEnergy(i, pfMACD);
		}

	}

	//����������µ����ܲ�����mMinEnergy��������������
	void  CaclDownEnergy(int nStartCJD, float *pfMACD )
	{
		//Ǳ�ڶ��������������������
		int i= nStartCJD;
		TBPoint  usrMin;

		//����������������ֵ����Low��С��5���׷���:һ�����  
		//����Ӷ����Ϳ�ʼ
		while (usrCJD[i].nStatus > 0 && i<nCJDCount - 1) i++;

		for (; i<nCJDCount - 1; i+=2)
		{
			usrMin.fEnergy = 999999;
			//ȡ������������Сֵ  �Ӷ����ͽ�������ʼ���׷��ͽ���
			for (int j = usrCJD[i].nP3 + 1; j<usrCJD[i + 1].nP3; j++)
				if (usrMin.fEnergy - pfMACD[j] > 0.0)
				{
					usrMin.fValue = pNowKData[j].fLow;
					usrMin.nIndex = i;
					usrMin.nDate= (pNowKData[usrCJD[i].nPlace].nYmd % 2048)*100
						+(pNowKData[usrCJD[i].nPlace].nMin / 60);
					usrMin.fEnergy = pfMACD[j];
				}

			//��С������������
			for (int k = 0; k < TBPOINTCOUNT; k++)
				if (    usrMin.fEnergy < mMinEnergy[k].fEnergy )
				{
					// ��������Сֵ����ֵ�����
					if (k<TBPOINTCOUNT - 1)
						memcpy(&mMinEnergy[k + 1], &mMinEnergy[k], (TBPOINTCOUNT - k - 1) * sizeof(TBPoint));

					memcpy(&mMinEnergy[k], &usrMin, sizeof(TBPoint));

					break;
				}
		}
	}

	//����������ϳ����ܲ�����mMaxEnergy�����ݽ�������
	void  CaclUpEnergy(int nStartCJD, float *pfMACD )
	{
		//Ǳ�ڶ��������������������
		int i = nStartCJD;
		TBPoint  usrMax;

		//����High����5��������
		
		// �����������������ʱ��Ҫ�õ�������  ��¼Highֵ
		//����ӵ׷��Ϳ�ʼ
		while (usrCJD[i].nStatus < 0 && i<nCJDCount - 1) i++;

		for (; i<nCJDCount - 1; i+=2)
		{
			usrMax.fEnergy = -999999;
			//ȡ�������������ֵ
			for (int j = usrCJD[i].nP3 + 1; j<usrCJD[i + 1].nP3 + 1; j++)
				if (usrMax.fEnergy - pfMACD[j] < 0.0)
				{
					usrMax.fValue = pNowKData[j].fHigh;
					usrMax.nIndex = i;
					usrMax.nDate = (pNowKData[j].nYmd%2048)*100
						+ (pNowKData[j].nMin / 60);
					usrMax.fEnergy = pfMACD[j];
				}

			//�Ӵ�С������������
			for (int k = 0; k < TBPOINTCOUNT; k++)
				if (   usrMax.fEnergy > mMaxEnergy[k].fEnergy )
				{
					if (k<TBPOINTCOUNT - 1)
						memcpy(&mMaxEnergy[k + 1], &mMaxEnergy[k], (TBPOINTCOUNT - k - 1) * sizeof(TBPoint));

					memcpy(&mMaxEnergy[k], &usrMax, sizeof(TBPoint));
					break;
				}
		}
	}

	//��������㴴�¸��µ�ʱ�����ܷ�ֵ  
	//�������ͼۼ۸���� ����С��TBPOINTCOUNT�����ֱ����mTop��mBotton
	//mTop�Ӵ�С��mBotton��С����
	//pfMACD ������DIFF DEA MACD
	//TODO 20170303�������������������Ǽ۸�仯���ۼ�ֵ��DIFF DEA MACD�����������������ۼ�ֵ
	void	CaclCJDTBPoint(float *pfMACD, int  nDataLen)
	{
		int k;

		for (k = 0; k < TBPOINTCOUNT; k++)
		{
			mTop[k].fEnergy = -99999, mTop[k].fValue = -99999, mTop[k].nIndex = -1;
			mBotton[k].fEnergy = 99999, mBotton[k].fValue = 99999, mBotton[k].nIndex = -1;
		}

		int i = nCJDCount - 1;
	
		/*
		��ǰ��Ĳ��ڳֲַ�Χ�ڣ�����Ǳ�ڵ�123��
		*/

		int nStart = 0;//123��������
		float fHigh = -999999.0;
		int  nLowestCJD=i;//�µʹ�������
		int  nHighestCJD = i;//�¸ߴ�������

		//ָ��������λ�õĲ�����
		while (usrCJD[nLowestCJD].nPlace > nMinLow && nLowestCJD > 0) nLowestCJD--;
		//if (nLowestCJD == 0)  return; //��͵㲻�ǲ����㣬��������

		//ָ�������ߵ�Ĳ�����
		while (usrCJD[nHighestCJD].nPlace > nMaxHigh && nHighestCJD > 0) nHighestCJD--;
		//if (nHighestCJD == 0)  return; //��ߵ㲻�ǲ����㣬��������
		

		if (nMinLow > nMaxHigh && nLowestCJD+1<=nCJDCount)
		{
			//1B
			i = nHighestCJD;
			CaclCJDBtn(pfMACD, i);
		}
		else if (nMinLow > nMaxHigh )
		{
			//δ����ǰ�ڸߵ㣬Ǳ��2��3�����������������
			i = nLowestCJD;
			CaclCJDTop(pfMACD, i);  //��������

			//ָ���µͺ���¸�
			int nLastestHigh;
			float fLastestHigh=-99999;
			if (usrCJD[i].nStatus < 0)
				k = i;
			else
				k = i + 1;

			for (; k <= nCJDCount; k += 2)
			{
				if (fLastestHigh < pNowKData[usrCJD[k].nPlace].fHigh)
				{
					fLastestHigh = pNowKData[usrCJD[k].nPlace].fHigh;
					nLastestHigh = k;
				}
			}

			CaclCJDBtn(pfMACD, nLastestHigh);  //2B3B����

		}
		else
		{
			//���Ʒ��������ڸߵ㣺ƽ̨ͻ��  BT����  TODO 20170405
			//�����������������   �������ϡ�ͻ��ǰ��ƽ̨�ߵ�
			//���г����߾������ҵ�ǰ���̼۸��ڶ��г����߲��ܹ��������
			//���һ�������ж�  TODO  20170306
			i = nLowestCJD;
			CaclCJDTop(pfMACD, i);  //�ж��Ƿ��ѳ��ֶ�����

			i = nCJDCount - 1;
			if (usrCJD[i].nStatus > 0) i--;

			//if (this->TopBC(i) == -1 /*&& pfMACD[nDataLen-1]>pfMACD[usrCJD[i].nPlace]*/)
			//{
			//	this->bBSChanged = true;
			//	this->AddBuy(nDataLen - 1, nDataLen - 1,
			//		BSTYPE_STEPUP, 0, 0);
			//}

		}


	}  //void	CaclCJDTBPoint( float *pfMACD, int  nDataLen)

	   //�������ܼ��������
	void  CaclCJDTop(float *pfMACD, int  nStartCJD)
	{
		//�����ֵ����Сֵǰ��������,mTop[TBPOINTCOUNT]���ִ�ķ������С��λ��
		TBPoint  usrMax;
		//����High����5��������
		usrMax.fValue = -999999;
		int i = nStartCJD;
		if (usrCJD[i].nStatus> 0) i++;

	

		for (; i <= nCJDCount; i += 2)
		{   // �������������ʱ��Ҫ�õ�������
			//������������
			if (usrMax.fValue < pNowKData[usrCJD[i].nPlace].fHigh)
			{
				usrMax.fValue = pNowKData[usrCJD[i].nPlace].fHigh;
				usrMax.nIndex = i;
				usrMax.nDate = (pNowKData[usrCJD[i].nPlace].nYmd % 2048)*100
					+ (pNowKData[usrCJD[i].nPlace].nMin / 60);
				usrMax.fEnergy = pfMACD[usrCJD[i].nPlace];
				//�Ӵ�С������������
				for (int k = 0; k < TBPOINTCOUNT; k++)
					if (usrMax.fValue > mTop[k].fValue)
					{
						if (k<TBPOINTCOUNT - 1)
							memcpy(&mTop[k + 1], &mTop[k],
							(TBPOINTCOUNT - k - 1) * sizeof(TBPoint));

						memcpy(&mTop[k], &usrMax, sizeof(TBPoint));
						break;
					}
			}
		}
	}



	void  CaclCJDBtn(float *pfMACD, int  nStartCJD)
	{
		//�����ֵ����Сֵǰ��������,mTop[TBPOINTCOUNT]���ִ�ķ������С��λ��
		//mBotton[TBPOINTCOUNT]����С�ķ������С��λ��
		TBPoint  usrMin;
		//����High����5��������
		usrMin.fValue = 999999;
		int i = nStartCJD;

		if (usrCJD[i].nStatus < 0) i++;

		for (; i<=nCJDCount; i+=2)
		{   // �������������ʱ��Ҫ�õ�������
			//����Low��С��5���׷���
			if (usrMin.fValue > pNowKData[usrCJD[i].nPlace].fLow)
			{
				usrMin.fValue = pNowKData[usrCJD[i].nPlace].fLow;
				usrMin.nIndex = i;
				usrMin.nDate = (pNowKData[usrCJD[i].nPlace].nYmd % 2048) * 100
					+ (pNowKData[usrCJD[i].nPlace].nMin / 60);
				usrMin.fEnergy = pfMACD[usrCJD[i].nPlace];
				//mBotton��С��������
				for (int k = 0; k < TBPOINTCOUNT; k++)
					if (usrMin.fValue < mBotton[k].fValue)
					{
						// ��������Сֵ����ֵ�����
						if (k<TBPOINTCOUNT - 1)
							memcpy(&mBotton[k + 1], &mBotton[k],
							(TBPOINTCOUNT - k - 1) * sizeof(TBPoint));

						memcpy(&mBotton[k], &usrMin, sizeof(TBPoint));

						break;
					}
			}
		}
	}


	   //�ж��Ƿ�����˳��ж̾���ͬʱ�µ������
	   //��Ҫ�оݣ����ж̾��߳�����3���������µ�
	   //          ���ж̿��ڣ���>��>�̣����о��߾���3������������
	bool MADown(int DataLen)
	{
		bool bRet = true;

		for (int i = DataLen - 1; i >DataLen - 4; i--)
		{
			bRet = (fMAShort[i] - fMAMid[i] < fMAShort[i - 1] - fMAMid[i - 1])
				&& (fMAShort[i] - fMAMid[i] <0)
				&& (fMAMid[i] - fMALong[i]<0);
			if (bRet == false)
				return false;
		}

		return 	 fMALong[DataLen - 1]>fMAMid[DataLen - 1]
			&& fMAMid[DataLen - 1]>fMAShort[DataLen - 1]
			&& MADown(DataLen, fMAShort, 3)  //�̾����µ�
			&& MADown(DataLen, fMAMid, 3)    //�о����µ�
			&& MADown(DataLen, fMALong, 3);  //�������µ�
	}

	//�ۺϲ����㶥���ͺ������ж��Ƿ�����˶����ۣ����س��ֶ����۵Ĵ�����û���򷵻�-1
	int		TopBC(int nCJDIndex)
	{
		int nRet = -1;
		int i = 0;
		
		//�Զ����ͽ��ж����۷���
		if (nCJDIndex > 1 && usrCJD[nCJDIndex].nStatus >= 0)  nCJDIndex--;

		do
		{
			if (mTop[i].nIndex == nCJDIndex)
			{
				int j;
				//����Ŀǰ�Ƿ���������
				for (j = 0; j<TBPOINTCOUNT; j++)
					if (mMaxEnergy[j].fEnergy - mTop[i].fEnergy <= 0.0)
					{
						//û�з������ۣ��˳�ѭ��
						break;
					}

				nRet = j;

				break;
			}
			i++;
		} while (i <TBPOINTCOUNT && i>1 && mTop[i].nIndex>0);

		return nRet;
	}

	//�ۺϲ�����׷��ͺ������ж��Ƿ�����˵ױ��ۣ����س��ֵױ��۵Ĵ�����û���򷵻�0
	int		BtnBC(int nCJDIndex)
	{
		int nRet = 0;
		int i = 0;

		//�Ե׷��ͽ��еױ��۷���
		if (nCJDIndex > 1 && usrCJD[nCJDIndex].nStatus <= 0)  nCJDIndex--;

		do
		{
			if (mBotton[i].nIndex == nCJDIndex)
			{
				int j;
				for (j = 0; j<TBPOINTCOUNT; j++)
					if (mBotton[i].fEnergy - mMinEnergy[j].fEnergy <= 0)
					{
						//û�б��ۣ��˳�
						break;
					}

				nRet = j;
				break;
			}
			i++;
		} while (i <TBPOINTCOUNT  && mBotton[i].nIndex>0 && i>1);

		return nRet;
	}

	void	AddBuy(int nDataLen, int	nK, int type, int nMode, int nDownPercent)
	{
		//nK   nDataLen�ǵ�ǰ����������
		if (pNowKData[nK].nYmd <= pNowKData[nDataLen].nYmd)
		{
			int i = 0;
			while (usrBuy[i].nAmount >0 && i<BSCOUNT) i++;

			//�������ڿ��������¼��ǰ��������Ч
			if (usrBuy[i].nAmount == 0 && i<BSCOUNT)
			{
				nLatesBuyYmd = pNowKData[nDataLen].nYmd;
				bDayUp = true;
				bBSChanged = true;
				usrBuy[i].nAmount = 0;
				usrBuy[i].nK = nK;
				usrBuy[i].nMode = nMode;
				usrBuy[i].nType = type;
				usrBuy[i].nDownPercent = nDownPercent;
				usrBuy[i].nWeek = g_nWeek;
				usrBuy[i].fBuySellPrice = pNowKData[nK].fOpen;
				usrBuy[i].fClose = pNowKData[nK].fClose;
				usrBuy[i].nYmd = nCurYmd;
				usrBuy[i].nMin = nCurMin;
				nBuyIndex++;
			}
		}
	}
	void	AddSell(int nDataLen, int nK, int type, int nMode, int nDownPercent)
	{
		//nK   nDataLen��ͬһ�첻ͬ��K��λ��ʱ���������
		if (nBuyIndex>0
			&& pNowKData[nK].nYmd == pNowKData[nDataLen].nYmd
			&& pNowKData[nK].nMin == pNowKData[nDataLen].nMin)
		{
			int nLastBuyYmd = usrBuy[nBuyIndex - 1].nYmd;
			
			if (nSellIndex<BSCOUNT - 1
				&& pNowKData[nK].nYmd>nLastBuyYmd)
			{

				while (usrSell[nSellIndex].nAmount >0) nSellIndex++;

				int i = nSellIndex;
				bBSChanged = true;

				//����ǰ�ֲ�����50%��������
				usrSell[i].nAmount = 50;
				usrSell[i].nK = nK;
				usrSell[i].nMode = nMode;
				usrSell[i].nType = type;
				usrSell[i].nWeek = g_nWeek;
				usrSell[i].nMustSellYMD = 0;
				usrSell[i].nDownPercent = usrBuy[0].nDownPercent;//һ�򴦵ĵ���
				usrSell[i].nMustSellYMD = 1;
				usrSell[i].fBuySellPrice = pNowKData[nK].fOpen;
				usrSell[i].nYmd = nCurYmd;
				usrSell[i].nMin = nCurMin;
				nSellIndex++;
			}
		}
		else
		{	//���մ�������Զ���ֱֲ�Ĵ���  �����������մ���20170116
			int i = 0;
		}
	}
	void SetCurClose(float fClose)
	{
		fCurClose = fClose;
	}
	void SetfAveragePrice(float fClose)
	{
		fAveragePrice = fClose;
	}
	float GetfAveragePrice()
	{
		return fAveragePrice;
	}
	float GetCurClose()
	{
		return fCurClose;
	}
	void SetCurDateTime(unsigned short nYmd, unsigned short nMin)
	{
		nCurYmd = nYmd;
		nCurMin = nMin;

	}
	void GetCurDateTime(unsigned short *nYmd, unsigned short *nMin)
	{
		*nYmd = nCurYmd;
		*nMin = nCurMin;
	}
	int DecBuyIndex()
	{
		if (nBuyIndex>0)
			return --nBuyIndex;
		else
			return -1;
	}
	int DecSellIndex()
	{
		if (nSellIndex>0)
			return --nSellIndex;
		else
			return -1;
	}

	BSInfo *GetusrBuy()
	{
		return 	&usrBuy[0];
	}
	BSInfo *GetusrSell()
	{
		return 	&usrSell[0];
	}
	unsigned int	GetCode()
	{
		return 	  nCode;
	}

	void	SetCode(int Code)
	{
		nCode = Code;
	}

	//�Զ����ִ���
	void	AutoSell(int nDataLen)
	{
		int nCount = GetBuyIndex();
		if (nCount == 0) return;

		//����Ƿ���ֹ��ֹӯ�۸�
		//�ֲ�����һ�������
		//�����3����������ֳ��ж̾��߾����ҵ�������ֹ�����һ�룬�Զ�����
		//nLatesBuyYmd  Ϊ��Ϊ0��   TODO 20170428
		if (nHoldingAmount>0 && nLatesBuyYmd<pNowKData[nDataLen - 1].nYmd)	 //�ֲ�����һ��
		{
			if (fAutoDownSellPrice > pNowKData[nDataLen - 1].fClose)
				AddSell(nDataLen-1, nDataLen - 1, -BSTYPE_STOPDOWN, BSMODE_STOPDOWN, 0);
			else if (DetectSellSignal(nDataLen) == true)
			{
				AddSell(nDataLen-1, nDataLen - 1, -BSTYPE_JXDOWN, BSMODE_STOPDOWN, 0);
			}
			else
			{
				//�����3����������ֳ��ж̾��߾����ҵ�������ֹ�����һ�룬�Զ�����)
				if (100 - 100 * fCurClose / fMaxHigh>AUTODOWNSELLGATE/2 
					&& MADown(nDataLen)==true
					&& nLatesBuyYmd+3>=pNowKData[nDataLen - 1].nYmd)
				{
					AddSell(nDataLen-1, nDataLen - 1, -BSTYPE_JXDOWN, BSMODE_STOPDOWN, 0);
				}
			}
		}
	}

	//�����жϵ�ǰ��ĵ����ƣ�����Ѱ�������ԣ�Ҫ�����60�գ�48��5��������*30�����������ƣ�
	//�����µ����ҵ�������15%��Ĳ��й�ע��ֵ
	//����5�ա�10�վ��߻�MACD�е�ǰ��������
	bool	StockIsDown(int	nDataLen, StockInfo *pBase)
	{
		int			DOWNGATE = 25;
		bool		ret = false;
		float		fNowClose = 0, 
					*fMa5=new float[g_nStockDownDays + 2], 
					*fMa10= new float[g_nStockDownDays + 2];

		int			i, j;
		int			nWeek = g_nStockDownDays;
		//return true;  g_sOneBuy

		if (nDataLen<g_nStockDownDays)
			return ret;
		else
			i = nDataLen - nWeek;

		memset(fMa5, 0, g_nStockDownDays * sizeof(float));
		memset(fMa10, 0, g_nStockDownDays * sizeof(float));

		for (j = 0; j<5; j++)
		{
			fMa10[9] = fMa10[9] + (pBase + j)->fClose;
			fMa5[4] = fMa5[4] + (pBase + j)->fClose;
		}
		fMa5[4] = fMa5[4] * 0.2;

		for (j = 5; j<10; j++)
		{
			fMa10[9] = fMa10[9] + (pBase + j + i)->fClose;
			fMa5[j] = fMa5[j - 1] + ((pBase + j + i)->fClose - (pBase + j + i - 5)->fClose)*0.2;
		}

		fMa10[9] = fMa10[9] * 0.1;
		j = 10;

		do
		{
			fMa5[j] = fMa5[j - 1] + ((pBase + i + j)->fClose - (pBase + i + j - 5)->fClose)*0.2;
			fMa10[j] = fMa10[j - 1] + ((pBase + i + j)->fClose - (pBase + i + j - 10)->fClose)*0.1;
		} while (j++<g_nStockDownDays - 1);

		//�ж����3��5��10�վ��߾����Ƿ񲻶ϼ���,��5���ߵ���10���ߡ����������㷨todo1008
		bool bIsDown = true;

		//��ѡ���Ժܹؼ���Ӧ���н�һ���������ж��㷨todo 1105
		j = g_nStockDownDays - 1;
		while (bIsDown == true && j>1)
			bIsDown =/*fMa5[j]-fMa10[j]<0.0 &&*/ fMa5[j] - fMa10[j] - fMa5[j - 1] + fMa10[j-- - 1]>0.0;

		int nDown = (int)(100 - (pBase + nDataLen - 1)->fClose / this->fMaxHigh * 100);
		ret = (g_nStockDownDays - 1 - j>2) && (nDown - DOWNGATE>0);

		if (ret == true)
		{
			//ret=SortDownStock(nCode,g_nStockDownDays-1-j,nDown,	NULL);
		}

		return ret;
	}

	//�Զ������ù�Ʊ���Ʒ���
	/*
	�����:��ǰ��λ������������ֵ5%
	���̼�����3�յ���5�վ���
	5�վ�������3�յ���10�վ���
	*/
	bool	StockIsDownOld4AutoSell(int	nDataLen, StockInfo *pBase)
	{
#define		WEEKS		60
#define     DOWNGATE	0.05

		bool		ret = false;
		float		fNowClose = 0, fMa5[WEEKS + 2], fMa10[WEEKS + 2];
		int			i, j;
		int			nWeek = MAMID*1.1;
		//return true;  g_sOneBuy

		if (nDataLen<nWeek)
			return ret;
		else
			i = nDataLen - nWeek;

		memset(fMa5, 0, nWeek * sizeof(float));
		memset(fMa10, 0, nWeek * sizeof(float));
		//this->fMaxHigh = -1;

		for (j = 0; j<MASHORT; j++)
		{
			fMa10[9] = fMa10[MAMID - 1] + (pBase + j)->fClose;
			fMa5[4] = fMa5[MASHORT - 1] + (pBase + j)->fClose;
		}
		fMa5[4] = fMa5[MASHORT - 1] / MASHORT;

		for (j = MASHORT; j<MAMID - 1; j++)
		{
			fMa10[9] = fMa10[MAMID - 1] + (pBase + j + i)->fClose;
			fMa5[j] = fMa5[j - 1] + ((pBase + j + i)->fClose - (pBase + j + i - MASHORT)->fClose) / MASHORT;
		}

		fMa10[MAMID - 1] = fMa10[MAMID - 1] / MAMID;
		j = MAMID;

		do
		{
			fMa5[j] = fMa5[j - 1] + ((pBase + i + j)->fClose - (pBase + i + j - 5)->fClose) / MASHORT;
			fMa10[j] = fMa10[j - 1] + ((pBase + i + j)->fClose - (pBase + i + j - 10)->fClose) / MAMID;
		} while (j++<nWeek - 1);

		//�ж����3��5��10�վ��߾����Ƿ񲻶ϼ���,��(��??)5���ߵ���10���ߡ����������㷨  todo20170203
		bool bIsDown = true;

		for (j = nWeek - 4; j<nWeek - 1; j++)
			if (fMa5[j] - fMa10[j]>0.0)
			{
				bIsDown = false;
				break;
			}

		ret = bIsDown || (1 - (pBase + nDataLen - 1)->fClose / this->fMaxHigh - DOWNGATE>0);

		return ret;
	}

	//�����ֵ
	void	MA(int	nDataLen, StockInfo *pBase,  //Դ��������������ָ��
		int nShort, int nLong,           //��ֵ����
		float *fShort, float *fLong)     //��ֵ����
	{
		int		nStart, j;

		if (nDataLen < nLong || nLong <= 0 || nShort <= 0)
			return;

		//����������ľ�ֵ��̫Զ�ľ�ֵ���������������
		nStart = max(nDataLen - nLong*1.3, 0);

		memset(fShort, 0, nDataLen * sizeof(float));
		memset(fLong, 0, nDataLen * sizeof(float));

		for (j = nStart; j < nStart + nShort; j++)
		{
			fShort[nStart + nShort - 1] = fShort[nStart + nShort - 1] + (pBase + j)->fClose;
		}
		fLong[nStart + nLong - 1] = fShort[nStart + nShort - 1];
		fShort[nStart + nShort - 1] = fShort[nStart + nShort - 1] / nShort;

		for (; j <nStart + nLong; j++)
		{
			fLong[nStart + nLong - 1] = fLong[nStart + nLong - 1] + (pBase + j)->fClose;
			fShort[j] = fShort[j - 1] + ((pBase + j)->fClose - (pBase + j - nShort)->fClose) / nShort;
		}

		fLong[nStart + nLong - 1] = fLong[nStart + nLong - 1] / nLong;

		do
		{
			fShort[j] = fShort[j - 1] + ((pBase + j)->fClose - (pBase + j - nShort)->fClose) / nShort;
			fLong[j] = fLong[j - 1] + ((pBase + j)->fClose - (pBase + j - nLong)->fClose) / nLong;
		} while (j++ < nDataLen);

	}
	//�����ֵ
	void	MA(int	nDataLen, StockInfo *pBase,  //Դ��������������ָ��
		int nShort, int nMid, int nLong,           //��ֵ����
		float *fShort, float *fMid, float *fLong)     //��ֵ����
	{
		int		nStart, j;

		if (nDataLen < nLong || nLong <= 0 || nMid <= 0 || nShort <= 0)
			return;

		//����������ľ�ֵ��̫Զ�ľ�ֵ���������������
		nStart = 0;// max(nDataLen - nLong*1.3, 0);

		memset(fShort, 0, nDataLen * sizeof(float));
		memset(fMid, 0, nDataLen * sizeof(float));
		memset(fLong, 0, nDataLen * sizeof(float));

		j = nStart;
		fMid[j] = (pBase + j)->fClose / nMid;
		fShort[j] = (pBase + j)->fClose / nShort;
		fLong[j] = (pBase + j)->fClose / nLong;

		for (j = nStart + 1; j < nStart + nShort; j++)
		{
			fLong[j] = fLong[j - 1] + (pBase + j)->fClose / nLong;
			fMid[j] = fMid[j - 1] + (pBase + j)->fClose / nMid;
			fShort[j] = fShort[j - 1] + (pBase + j)->fClose / nShort;
		}

		for (; j <nStart + nMid; j++)
		{
			fLong[j] = fLong[j - 1] + (pBase + j)->fClose / nLong;
			fMid[j] = fMid[j - 1] + (pBase + j)->fClose / nMid;
			fShort[j] = fShort[j - 1] + ((pBase + j)->fClose - (pBase + j - nShort)->fClose) / nShort;
		}

		for (; j <nStart + nLong; j++)
		{
			fLong[j] = fLong[j - 1] + (pBase + j)->fClose / nLong;
			fMid[j] = fMid[j - 1] + ((pBase + j)->fClose - (pBase + j - nMid)->fClose) / nMid;
			fShort[j] = fShort[j - 1] + ((pBase + j)->fClose - (pBase + j - nShort)->fClose) / nShort;
		}

		do
		{
			fShort[j] = fShort[j - 1] + ((pBase + j)->fClose - (pBase + j - nShort)->fClose) / nShort;
			fMid[j] = fMid[j - 1] + ((pBase + j)->fClose - (pBase + j - nMid)->fClose) / nMid;
			fLong[j] = fLong[j - 1] + ((pBase + j)->fClose - (pBase + j - nLong)->fClose) / nLong;
		} while (j++ < nDataLen);

	}
	//����ɽ�����ֵ
	void	MAVOL(int	nDataLen, StockInfo *pBase,  //Դ��������������ָ��
		int nShort, int nMid, int nLong,           //��ֵ����
		long *lShort, long *lMid, long *lLong)     //��ֵ����
	{
		int	   j=0;
		long   l1, l2;
		if (nDataLen < nLong || nLong <= 0 || nMid <= 0 || nShort <= 0)
			return;

		//����������ľ�ֵ��̫Զ�ľ�ֵ���������������
		//nStart = max(nDataLen - nLong , 0);

		lMid[j] = (pBase + j)->nNumber /nMid;
		lLong[j] = (pBase + j)->nNumber /nLong;
		lShort[j] = (pBase + j)->nNumber / nShort;

		for (j = 1; j < nShort; j++)
		{
			l1 = (pBase + j)->nNumber;
			lShort[j] = lShort[j- 1] + l1/nShort;
			lMid[j] = lMid[j-1]+ l1 / nMid;
			lLong[j] = lLong[j-1]+ l1 / nLong;
		}

		for (; j < nMid; j++)
		{
			l1 = (pBase + j)->nNumber;
			l2 = (pBase + j - nShort)->nNumber;
			lMid[j ] = lMid[j - 1] + l1 / nMid;
			lShort[j] = lShort[j - 1] + (l1 - l2) / nShort;
			lLong[j ] = lLong[j - 1]+l1/ nLong;
		}

		for (; j <nLong; j++)
		{
			l1 = (pBase + j)->nNumber;
			lLong[j] = lLong[j - 1] + l1 / nLong;

			l2 = (pBase + j - nMid)->nNumber;
			lMid[j] = lMid[j - 1] + (l1 - l2) / nMid;

			l2 = (pBase + j - nShort)->nNumber;
			lShort[j] = lShort[j - 1] + (l1 - l2) / nShort;
		}

		do
		{
			l1 = (pBase + j)->nNumber;
			l2 = (pBase + j - nShort)->nNumber;
			lShort[j] = lShort[j - 1] + (l1 - l2) / nShort;

			l2 = (pBase + j - nMid)->nNumber;
			lMid[j] = lMid[j - 1] + (l1 - l2) / nMid;

			l2 = (pBase + j - nLong)->nNumber;
			lLong[j] = lLong[j - 1] + (l1 - l2) / nLong;
		} while (j++ <nDataLen-1);

	}

	//��ѡ1����ʹ��,�����жϵ�ǰ��ĵ����ƣ�����Ѱ�������ԣ�Ҫ�����60�գ�48��5��������*30�����������ƣ�
	//����2��3�򣺲�����ֱ�Ӹ��������true  ����false ������
	//��ȥ�����ٲ���Ҫ����Ҫ����Ŀǰ�µ������Ƿ��Ѽ������Ƿ�������������ƣ�
	//���̸��ڶ̾����ҳ��ж̾��߾���������״̬
	//���Ǳ���������ݣ�Ȩ�ؼ���15-1,30-2,45-3,60-4,90-5
	bool	IsUp4Buy(int	nDataLen, StockInfo *pBase,bool Is1Buy=true)
	{
		
		bool		ret = false;
		float		fNowClose = 0;
		int			nWeek = g_nStockDownDays - 5,nDownRate=100-100*fCurClose/fMaxHigh;

		if (nDataLen<nWeek)
			return ret;

		bool bIsDown = true;

		int n1 = nDataLen, i = 0, nValidWeeks = 0;//��Ч��������

		while (g_usrAnalysePattern[g_nAnalysePat].nWeekList[i]> 0)
		{
			int  nCount =min( nDataLen,MALONG * 2 
				* g_usrAnalysePattern[g_nAnalysePat].nWeekList[i]/ 5);

			n1 = nCount;//�����Ż������ٷ�����������
			if (nDataLen < nCount)
			{
				i++;
				continue;
			}

			CreateStockData(&n1, p5MinKData + nDataLen - nCount, 
				pNowKData, 5, g_usrAnalysePattern[g_nAnalysePat].nWeekList[i]);

			SetMaxHighMinLow(n1);

			//���̼۾�ֵ
			MA(n1, pNowKData, MASHORT, MAMID, MALONG,
				this->fMAShort, this->fMAMid, this->fMALong);

			//���ж̾��߾������ż�������
			//��ǰ���̸��ڶ̾���
			//�ɽ�����������
			//����������׷��ͳ��ֵױ��ۣ�����
			ret =  MAUp(n1, fMALong, 3) && MAUp(n1, fMAMid, 3) && MAUp(n1, fMAShort, 3)
				&& (*(fMAShort+n1-1)-*(fMAMid+n1-1)>0)
				&& (*(fMAMid+n1-1)-*(fMALong+n1-1)>0)
				&& this->VOLUp5Min(n1,  3)
				&& pNowKData[n1-1].fClose>this->fMAShort[n1-1]
				//20170503��ʱȡ�����ۼ��
				/*&& DetectBtnBC(nDataLen, g_usrAnalysePattern[g_nAnalysePat].nWeekList[i]) == true*/;

			if (ret == true )
			{
				this->nWeekList[nValidWeeks++] = g_usrAnalysePattern[g_nAnalysePat].nWeekList[i];
			}
			i++;
		}

		if (nValidWeeks>0 && Is1Buy==true 
			&& nDownRate>g_usrAnalysePattern[g_nAnalysePat].nDownGate)
			ret = SortDownStock(nCode, 0, nDownRate, &this->nWeekList[0]);

		return ret;
	}


	void	AddAutoSell(int nIndex, int nK, int nNumber, int nWeek)
	{
		if (nIndex >= 0 && nSellIndex<BSCOUNT) //��̬��������λ��	TODO 0925
		{
			int i = 0;
			//ָ��һ�����е�����,��������Ϊ���������Զ��Ҷ���������
			while (usrSell[i].nK>0) i = (i + 1) % BSCOUNT;

			usrSell[i].nK = nK;
			usrSell[i].nMustSellYMD = 0;
			usrSell[i].nAmount = nNumber;

			//�����۴��Ӧ�ô��뵱ǰ�� 20170313 ���ֲ�����
			usrSell[i].fBuySellPrice = fCurClose;//  ptrStockInfo[nK].fClose;

			usrSell[i].nYmd = nCurYmd;
			usrSell[i].nMin = nCurMin;
			usrSell[i].nWeek = nWeek;
			nSellIndex++;
		}
		else
			//���մ���  ��������
			;

	}

	int	GetBuy(int	n)
	{
		return usrBuy[n].nK;
	}
	int	GetBuyType(int	n)
	{
		return usrBuy[n].nType;
	}
	int	GetBuyMode(int	n)
	{
		return usrBuy[n].nMode;
	}
	int	GetBuyIndex()
	{
		return nBuyIndex;
	}
	int	GetSell(int n)
	{
		return	usrSell[n].nK;
	}
	int	GetSellType(int n)
	{
		return	usrSell[n].nType;
	}
	int	GetSellMode(int n)
	{
		return	usrSell[n].nMode;
	}
	int	GetSellIndex()
	{
		return	nSellIndex;
	}
	//��ȡ�����������
	int GetEldBuyYmd()
	{
		int nRet = 999999;

		for (int i = 0; i < BSCOUNT; i++)
		{
			if (usrBuy[i].nYmd<nRet && usrBuy[i].nYmd>0)
				nRet = usrBuy[i].nYmd;
		}
		if (nRet == 999999)
			nRet = -1;

		return nRet;

	}

	//��ȡ��ǰ�ֲֵ����ֲ�����
	int GetMustSellYmd()
	{
		int nRet = -1;

		for (int i = 0; i < BSCOUNT; i++)
		{
			if (usrBuy[i].nMustSellYMD>nRet)
				nRet = usrBuy[i].nMustSellYMD;
		}
		return nRet;

	}

	CNowTrends(void)
	{
		fAutoUpSellPrice = -1;
		nVolMaLong = 0, nVolMid = 0, nVolShort = 0;
		memset(&nWeekList, 0, ANALYSEWEEKS - 1);
	}

	~CNowTrends(void)
	{

	}
};


class CAutoTrade
{
public:
	int		nCheckSell, nWeek;//ÿ���������ڽ��й���������������
							  //short	nTradeIndex;  //�ֲ�����
	bool	bChanged, bBuySellChanged;     //�ṹ���ݷ����仯ʱΪtrue	 ���������ź�ʱbBuySellChangedΪtrue
	int		nCurDate, nCurTime;
	int		nCurStockIndex;//�����ڷ����׶εĵ�ǰ�ֲֹ�Ʊ������usrStockTrade��������ЧΪ-1
	int	    nHoldingCount = 0;//Ŀǰ�ֲּ���ѡ�ֲ�������ÿ��ִ����DoBuy���Զ�����
	CNowTrends	usrStockTrade[MAXTRADENUMBER];
	float   fCurHolding;//��ǰ�ֲ���ֵ
	float	fStartFund, fNowFund, fNowGain, fAutoSellPoint;//��ʼ���  ��ǰ�ʽ��� ��ǰӯ�����������Զ��볡�����������ֲ���������0���Զ��볡������0�ֲ�����
	int		nNextRecord;//�´ζ�ȡ���ļ���¼λ��,����ָ֤��Ϊ�ο���
	int     nCurDataLen;//��ǰ���ݳ���,,����ָ֤��Ϊ�ο���
	char    strBlock[32];//�������
private:
	int     nForSellCode[2] = {0,0};//Ǳ����ֱ�ģ����ڳ��ֺܺõ����ʱ���
	int		nMustSellYMD;//nMustSellYMD���ֲ�����
	float	fBuyFeeRate, fSellFeeRate, fMaxUpPercent, fMaxDownPercent;//��������  ֹ��ֹӯ����
	int		nBuyCount, nSellCount, nSellNumber;//fBuyCount/nSellCount С��100��ʾÿ�ι����ʣ���ʽ�ٷֱȣ�����100��ʾÿ�ι���Ĺ��� nSellNumber�������������Ĵ����
	int		nBuyNumber;//��ǰ�������  ��������ʱ���K���������ж����ֲ������ã�
	float	fCJDMaxDownPercent, fDownPrice, fBuySellFee;//����Ч�������λ���س��������س�ֹ���λ�����ڼ�����

public:


	void	Init(int	MaxDataLen)
	{

	}

	//�����ֱֲ���Ƿ��ڿ���/��������״̬������
	//��������������Ŀ����ǻᱻ�Ż��ı��  todo 20170501 ���Ż�  �������ǻ����е���
	void DetectHoldingBuySignal(CStockBlockInfo *ptrBlockInfo, int nStopDate, int nStopTime)
	{
		int i = 0;

		//ʹ�ÿ��е�float������м���
		//ptrBlockInfo->fMAShort = g_fbuf1;
		//ptrBlockInfo->fMAMid = g_fbuf2;
		//ptrBlockInfo->fMALong = g_fbuf3;

		//memset(g_usrDayTrends.usrBuy1List, 0, BUY1STOCKNUMBERS * sizeof(DayTrends));
		//g_usrDayTrends.usrBuy1List[0].bDown = true;
		//g_usrDayTrends.nBuy1Count = 0;

		//nForSellCode[0] = 0, nForSellCode[1] = 0;

		//for (i = 0; i < g_nMaxHolding; i++)
		//{
		//	j = ptrBlockInfo->FindStockInBlock(usrStockTrade[i].nCode);
		//	if(j>0)
		//		FindUppingStock(ptrBlockInfo, j, nStopDate, nStopTime);
		//}
		//	
		////ȡ������ֱ�ı���
		//if (g_usrDayTrends.nBuy1Count >= 2)
		//{
		//	for (i = 0; i <2; i++)
		//	{
		//		nForSellCode[i] = g_usrDayTrends.usrBuy1List[g_usrDayTrends.nBuy1Count - 1 - i].nCode;
		//	}
		//}
		

	}

	//�������������������������أ�������ȶȡ�����ȶȵ���Ϣ������ǰ�����������㷨����������
	//���뵥λΪ�֣���100��
	int	CaclBuyAmount(BSInfo *usrBuyPtr)
	{
		int nRet = (int)((fNowFund / 10000)*nBuyCount / usrBuyPtr->fBuySellPrice);
		/*if(nRet<1)
		nRet=1;*/

		return nRet;
	}

	//�������������������������أ�������ȶȡ�����ȶȵ���Ϣ������ǰ�����������㷨����������
	//ÿ�ε�������ָ�������ĳֲ���	nNumber<=0 ʱ��ÿ�������ֲ�25%��nNumber>0ʱ����ָ������
	//������λΪ�֣���100��
	int	CaclSellAmount(int i, int nNumber)
	{
		int nCount = usrStockTrade[i].GetBuyIndex();
		int	nSellNumber = 0;
		int	nRet, j, k;

		if (nCount == 0)
			return 0;

		if (nNumber <= 0)
			nSellNumber = nSellCount;
		else if (nNumber >= 100)
			nSellNumber = 100;
		else
			nSellNumber = nNumber;

		BSInfo *usrBuyPtr = usrStockTrade[i].GetusrBuy();

		//�����źŴﵽBSCOUNT�Σ���ոù�Ʊ
		if (usrStockTrade[i].GetSellIndex() == BSCOUNT)
		{
			nRet = usrStockTrade[i].nHoldingAmount;

			//��ǰ�������ִ���
			while (usrStockTrade[i].DecSellIndex()>0);
			while (usrStockTrade[i].DecBuyIndex()>0);
			for (j = 0; j<BSCOUNT; j++)
			{
				(usrBuyPtr + j)->nAmount = 0;
				(usrBuyPtr + j)->nK = 0;
			}
			usrStockTrade[i].nHoldingAmount = 0;
			return nRet;
		}
		else
			nRet = usrStockTrade[i].nHoldingAmount*nSellNumber / 100;

		if (nRet == 0)
			nRet = usrStockTrade[i].nHoldingAmount;

		k = nRet;
		for (j = 0; j<BSCOUNT && k>0; j++)
		{	  //��ճֲ�����
			if (k >= (usrBuyPtr + j)->nAmount && (usrBuyPtr + j)->nAmount>0)
			{
				k -= (usrBuyPtr + j)->nAmount;
				(usrBuyPtr + j)->nAmount = 0;
				usrStockTrade[i].DecBuyIndex();
			}
			else if ((usrBuyPtr + j)->nAmount>0)
			{
				(usrBuyPtr + j)->nAmount -= k;
				break;
			}
		}
		if (nRet	 <0)
			nRet = 0;

		usrStockTrade[i].nHoldingAmount -= nRet;

		if (usrStockTrade[i].nHoldingAmount == 0)
		{
			//��ǰ�������ִ���
			while (usrStockTrade[i].DecSellIndex()>0);
			while (usrStockTrade[i].DecBuyIndex()>0);
		}

		return nRet;
	}

	void DoBuy()
	{
		char sbuf[250];
		int nDate, nTime, nAmount = 0;
		float	fVol = 0;
		BSInfo *usrBuyPtr = NULL;
		float	fFee;
		int nCount;

		g_usrDayTrends.Buy1StockSort();

		for (int i = 0; i<g_nMaxHolding; i++)
		{
			nCount = usrStockTrade[i].GetBuyIndex();

			//���гֲ�,�������¹�Ʊ
			if (nCount > 0)
				continue;

			usrBuyPtr = g_usrDayTrends.Buy1Get();
			if (usrBuyPtr == NULL) break;//û�������Ϣ��ֱ���˳���û�������Ϣ����
			nCount = g_usrDayTrends.usrBuy1List[g_usrDayTrends.nCurBuyIndex - 1].nBSIndex;

			bool bBSValid = false;

			for (int j = 0; j<nCount; j++)
			{
				if (00 == (usrBuyPtr + j)->nAmount && (usrBuyPtr + j)->nK >0
					&& nCurDate == (usrBuyPtr + j)->nYmd && nCurTime == (usrBuyPtr + j)->nMin
					&& g_usrDayTrends.usrBuy1List[g_usrDayTrends.nCurBuyIndex - 1].bBSChanged == true)
				{
					(usrBuyPtr + j)->nMustSellYMD = DateAdd((usrBuyPtr + j)->nYmd, nMustSellYMD);
					(usrBuyPtr + j)->nAmount = CaclBuyAmount((usrBuyPtr + j));
					usrStockTrade[i].nCode = g_usrDayTrends.usrBuy1List[g_usrDayTrends.nCurBuyIndex - 1].nCode;
					usrStockTrade[i].nCurMin = nCurTime;
					usrStockTrade[i].nCurYmd = nCurDate;
					usrStockTrade[i].fCurClose = (usrBuyPtr + j)->fClose;

					if (usrStockTrade[i].fAutoDownSellPrice == 0)
					{
						usrStockTrade[i].fAutoDownSellPrice = (usrBuyPtr + j)->fBuySellPrice*(1 - fMaxDownPercent/2);
						usrStockTrade[i].f2BuyGate = (usrBuyPtr + j)->fBuySellPrice*(1 + fMaxDownPercent/2 );
						usrStockTrade[i].fAutoUpSellPrice = (usrBuyPtr + j)->fBuySellPrice*(1 + fMaxUpPercent);//һ��ʱ�����ֹ��fAutoDownSellPrice��ֹӯ�۸�fAutoUpSellPrice 
					}

					if ((usrBuyPtr + j)->nAmount > 0)
					{
						bBSValid = true;
						bChanged = true;

						if (i < g_nMaxHolding)  //�Զ��ֱֲ��
						{
							fFee = 100 * (usrBuyPtr + j)->nAmount*(usrBuyPtr + j)->fBuySellPrice;
							fNowFund = fNowFund - fFee - fFee*fBuyFeeRate;

							usrStockTrade[i].fAveragePrice = (usrBuyPtr + j)->fBuySellPrice;
							usrStockTrade[i].nHoldingAmount = usrStockTrade[i].nHoldingAmount + (usrBuyPtr + j)->nAmount;

							//todo ����¼	 ����,����,ʱ��,�������ڣ�����,�ɽ���,������,����,ģʽ,���ֲ�����,�����,ֹ���,ֹӯ��
							nDate = ((usrBuyPtr + j)->nYmd / 2048 + 104) * 10000 + (usrBuyPtr + j)->nYmd % 2048;
							nTime = ((usrBuyPtr + j)->nMin / 60) * 100 + (usrBuyPtr + j)->nMin % 60;
							int nCode = usrStockTrade[i].GetCode();
							sprintf_s(sbuf, "%07d,%07d,%04d,%04d,%04d,%03d,%06.2f,%04.2f,%02d,%02d,%04d,%04.2f,%04.2f,%04.2f",
								nCode, nDate, nTime, (usrBuyPtr + j)->nWeek, (usrBuyPtr + j)->nDownPercent, (usrBuyPtr + j)->nAmount, -fFee,
								-fFee*fBuyFeeRate, (usrBuyPtr + j)->nType, (usrBuyPtr + j)->nMode,
								(usrBuyPtr + j)->nMustSellYMD, (usrBuyPtr + j)->fBuySellPrice, usrStockTrade[i].fAutoDownSellPrice, usrStockTrade[i].fAutoUpSellPrice);
							LogBSFile(g_sBSLog, sbuf);

						}
						else
						{
							fFee = -1234;
						}

						if (j == 0 && g_nWorkMode == WORKMODE_REAL)  //ֻ������յ�һ�����
						{
							g_sMailContent.append("\n");
							g_sMailContent.append(sbuf);
							sprintf_s(sbuf, ",B%07d", usrStockTrade[i].GetCode());
							g_sMailTitle.append(sbuf);
						}
					}
					else
					{
						//�ʽ������㣬��¼�������ֵ����  todo ����̫�࣬��������20170307
						fFee = -1234;
					}
				}

				if (bBSValid == true)
				{
					memcpy(&usrStockTrade[i].usrBuy[j], usrBuyPtr + j, sizeof(BSInfo));
					usrStockTrade[i].nBuyIndex = nCount;
					memset(usrBuyPtr + j, 0, sizeof(BSInfo));

					g_usrDayTrends.usrBuy1List[g_usrDayTrends.nCurBuyIndex - 1].nBSIndex -= 1;
					if (0 == g_usrDayTrends.usrBuy1List[g_usrDayTrends.nCurBuyIndex - 1].nBSIndex)
						g_usrDayTrends.usrBuy1List[g_usrDayTrends.nCurBuyIndex - 1].bBSChanged = false;

					bBSValid = false;
				}
			}//for (int j = 0; j<nCount; j++)
		}//for (int i = 0; i<g_nMaxHolding; i++)

	}

	void Do2xBuy()
	{
		char sbuf[250];
		int nDate, nTime, nAmount = 0;
		float	fVol = 0;
		float	fFee = -1;

		for (int i = 0; i<MAXTRADENUMBER; i++)
		{
			int nCount = usrStockTrade[i].GetBuyIndex();
			bool	b2Buy = false;
			BSInfo *usrBuyPtr = NULL;

			if (nCount > 0)
			{
				//���������ж�
				for (int k = 0; k < BSCOUNT; k++)
				{
					if (this->nCurDate == usrStockTrade[i].usrBuy[k].nYmd
						&& this->nCurTime == usrStockTrade[i].usrBuy[k].nMin
						&&  usrStockTrade[i].usrBuy[k].nAmount == 0)
					{
						b2Buy = true;
						usrBuyPtr = &usrStockTrade[i].usrBuy[k];
						nCount = nCount - k;
						break;
					}
				}
				if (b2Buy == false)
					continue;
			}
			else
				continue;

			bool bBSValid = false;

			for (int j = 0; j<BSCOUNT; j++)
			{
				if (00 == (usrBuyPtr + j)->nAmount && (usrBuyPtr + j)->nK >0
					&& nCurDate == (usrBuyPtr + j)->nYmd && nCurTime == (usrBuyPtr + j)->nMin)
				{
					(usrBuyPtr + j)->nMustSellYMD = DateAdd((usrBuyPtr + j)->nYmd, nMustSellYMD);
					(usrBuyPtr + j)->nAmount = CaclBuyAmount((usrBuyPtr + j));

					if (i < g_nMaxHolding)
					{
						//�����ֲִ���
						if (usrStockTrade[i].fAutoDownSellPrice == 0)
						{
							usrStockTrade[i].fAutoDownSellPrice = (usrBuyPtr + j)->fBuySellPrice*(1 - fMaxDownPercent);
							usrStockTrade[i].f2BuyGate = (usrBuyPtr + j)->fBuySellPrice*(1 + fMaxDownPercent / 2);
							usrStockTrade[i].fAutoUpSellPrice = (usrBuyPtr + j)->fBuySellPrice*(1 + fMaxUpPercent);//һ��ʱ�����ֹ��fAutoDownSellPrice��ֹӯ�۸�fAutoUpSellPrice 
						}
						fFee = 100 * (usrBuyPtr + j)->nAmount*(usrBuyPtr + j)->fBuySellPrice;

						usrStockTrade[i].fAveragePrice = (fFee / 100 + usrStockTrade[i].nHoldingAmount *usrStockTrade[i].fAveragePrice);
						usrStockTrade[i].nHoldingAmount += (usrBuyPtr + j)->nAmount;
						//���㵱ǰ�ֲֳɱ���
						usrStockTrade[i].fAveragePrice = usrStockTrade[i].fAveragePrice / usrStockTrade[i].nHoldingAmount;

						fNowFund = fNowFund - fFee - fFee*fBuyFeeRate;

						usrStockTrade[i].nCurMin = nCurTime;
						usrStockTrade[i].nCurYmd = nCurDate;
						usrStockTrade[i].fCurClose = (usrBuyPtr + j)->fClose;
						bBSValid = true;

						//todo ����¼	 ����,����,ʱ��,�������ڣ�����,�ɽ���,������,����,ģʽ,���ֲ�����,�����,ֹ���,ֹӯ��
						nDate = ((usrBuyPtr + j)->nYmd / 2048 + 104) * 10000 + (usrBuyPtr + j)->nYmd % 2048;
						nTime = ((usrBuyPtr + j)->nMin / 60) * 100 + (usrBuyPtr + j)->nMin % 60;
						sprintf_s(sbuf, "%07d,%07d,%04d,%04d,%04d,%03d,%06.2f,%04.2f,%02d,%02d,%04d,%04.2f,%04.2f,%04.2f",
							usrStockTrade[i].GetCode(), nDate, nTime, (usrBuyPtr + j)->nWeek, (usrBuyPtr + j)->nDownPercent, (usrBuyPtr + j)->nAmount, -fFee,
							-fFee*fBuyFeeRate, (usrBuyPtr + j)->nType, (usrBuyPtr + j)->nMode,
							(usrBuyPtr + j)->nMustSellYMD, (usrBuyPtr + j)->fBuySellPrice, usrStockTrade[i].fAutoDownSellPrice, usrStockTrade[i].fAutoUpSellPrice);
						LogBSFile(g_sBSLog, sbuf);

					}
					else
						//�ص��עָ�����Զ���ֲִ���
						fFee = -1234;

					if (j == 0 && g_nWorkMode == WORKMODE_REAL)
					{
						g_sMailContent.append("\n");
						g_sMailContent.append(sbuf);
						sprintf_s(sbuf, ",B%07d", usrStockTrade[i].GetCode());
						g_sMailTitle.append(sbuf);
					}

					bChanged = true;
				}
			}

		}
	}
	
	void DoSell()
	{
		char sbuf[250];
		int nDate, nTime;

		for (int i = 0; i<MAXTRADENUMBER; i++)
		{
			int nCount = usrStockTrade[i].GetSellIndex();
			int nCode = usrStockTrade[i].nCode;
			float	fFee = -1;
			if (nCount>0)
			{
				BSInfo *usrSellPtr = usrStockTrade[i].GetusrSell();
				for (int j = 0; j<BSCOUNT && nCount-->0; j++)
				{
					if (usrSellPtr->nK>0)
					{
						if (usrSellPtr->nAmount == 0) //��������,����������
						{
							usrSellPtr->nAmount = CaclSellAmount(i, 0);
							if (usrSellPtr->nAmount == 0)
								continue;
						}
						else
						{
							usrSellPtr->nAmount = CaclSellAmount(i, usrSellPtr->nAmount);
							if (usrSellPtr->nAmount == 0)
								continue;
						}

						//������Ϣ��¼����������
						if (i < g_nMaxHolding)
						{
							fFee = 100 * usrSellPtr->nAmount*usrSellPtr->fBuySellPrice;
							fNowFund = fNowFund + fFee - fFee*fSellFeeRate;
						}
						else
							fFee = -1234;

						bChanged = true;

						//todo ����¼	 ����,����,ʱ��,����,�ɽ���,������,����,ģʽ,���ֲ�����,�ɽ���,����,ӯ����
						nDate = (usrSellPtr->nYmd / 2048 + 104) * 10000 + usrSellPtr->nYmd % 2048;
						nTime = (usrSellPtr->nMin / 60) * 100 + usrSellPtr->nMin % 60;
						sprintf_s(sbuf, "%07d,%07d,%04d,%03d,%03d,%04d,%06.2f,%04.2f,%02d,%02d,%04d,%04.2f,%04.2f,%03.0f",
							usrStockTrade[i].GetCode(), nDate, nTime, usrSellPtr->nWeek, usrSellPtr->nDownPercent,
							-usrSellPtr->nAmount, fFee, -fFee*fSellFeeRate, usrSellPtr->nType, usrSellPtr->nMode,
							usrSellPtr->nMustSellYMD, usrSellPtr->fBuySellPrice, usrStockTrade[i].fAveragePrice,
							100 * usrSellPtr->fBuySellPrice / usrStockTrade[i].fAveragePrice - 100);

						LogBSFile(g_sBSLog, sbuf);

						if (j == 0 && g_nWorkMode==WORKMODE_REAL)
						{
							g_sMailContent.append("\n");
							g_sMailContent.append(sbuf);
							sprintf_s(sbuf, ",S%07d", usrStockTrade[i].GetCode());
							g_sMailTitle.append(sbuf);
						}

						usrStockTrade[i].DecSellIndex();
						memset(usrSellPtr, 0, sizeof(BSInfo));
					}
					else
						usrStockTrade[i].DecSellIndex();

					usrSellPtr++;
				}
			}
		}
	}

	void	AddStock(CNowTrends *ptr, bool nBuy)
	{
		if (nBuy == true && bBuySellChanged == true)
		{
			if (this->nCurStockIndex >-1)
			{
				//ͬһ��Ʊ������봦��  ��������
				memcpy(&usrStockTrade[nCurStockIndex], ptr, sizeof(CNowTrends));
				bChanged = true;
				bBuySellChanged = false;
			}
			else
			{
				for (int i = 0; i<MAXTRADENUMBER; i++)
				{
					if (usrStockTrade[i].GetCode() == 0)
					{
						memcpy(&usrStockTrade[i], ptr, sizeof(CNowTrends));
						bChanged = true;
						bBuySellChanged = false;
						this->nCurStockIndex = i;
						break;
					}
				}
				//nTradeIndex++;
			}

		}
		else if (nBuy == false)
		{
			//���ڳֲ��б������������ս�������
			if (this->nCurStockIndex >-1)
			{
				//ͬһ��Ʊ������봦��  ��������
				memcpy(&usrStockTrade[nCurStockIndex], ptr, sizeof(CNowTrends));
				bChanged = true;
			}
		}
	}
	void	InitFund(float	fFund, int nHoldWeeks)
	{
		fStartFund = fFund;
		fBuyFeeRate = 0.00025;
		fSellFeeRate = 0.00025;

		fNowFund = fStartFund;
		nBuyCount = 100 / g_nMaxHolding;
		nSellCount = 25;
		fCJDMaxDownPercent = 0.15;
		fMaxUpPercent = 0.25;
		fMaxDownPercent = (float)AUTODOWNSELLGATE / 100;
		nMustSellYMD = nHoldWeeks;
		nBuyNumber = 0;
		fAutoSellPoint = 0.05;
		nSellNumber = 0;

	}
	//���ָ����Ʊ�Ƿ��ڳֲ��б�������ǰ��Ʊ��������g_usrNowTrends
	//�����Զ��ֱֲ����Ч
	bool	StockInList(unsigned int nStockCode,CNowTrends *ptrTrends)
	{
		bool ret = false;
		if (nStockCode <= 0)  return false;

		this->nCurStockIndex = -1;
		for (int i = 0; i<g_nMaxHolding; i++)
			if (usrStockTrade[i].nHoldingAmount >0
				&& nStockCode == usrStockTrade[i].GetCode())
			{
				if (NULL != ptrTrends)
					memcpy(ptrTrends, &usrStockTrade[i], sizeof(CNowTrends));

				this->nCurStockIndex = i;
				return true;
			}
		if(NULL!= ptrTrends)
			memset(ptrTrends, 0, sizeof(CNowTrends));
		return ret;
	}

	//�ж�Ŀǰ�Ƿ��ѵ������ֲ֣����򷵻�true
	//���ֺ󲻱��жϺ������ֵ�1��
	bool	HoldingFull()
	{
		bool ret = true;

		for (int i = 0; i<g_nMaxHolding; i++)
			if (0 == usrStockTrade[i].GetCode())
			{
				ret = false;
				break;
			}

		return ret;
	}

	//���ָ����Ʊ�Ƿ����Զ���ֲ��б�������ǰ��Ʊ��������g_usrNowTrends
	bool	StockZXCCList(unsigned int nStockCode)
	{
		this->nCurStockIndex = -1;
		if (nStockCode <= 0)  return false;

		for (int i = g_nMaxHolding; i<MAXTRADENUMBER; i++)
			if (nStockCode == usrStockTrade[i].GetCode())
			{
				this->nCurStockIndex = i;
				return true;
			}

		return false;
	}


	CAutoTrade(void)
	{
		nNextRecord = 0;
		nCurDataLen = 0;
		memset(usrStockTrade, 0, MAXTRADENUMBER * sizeof(CNowTrends));
	}

	~CAutoTrade(void)
	{

	}
};

CAutoTrade g_usrAutoTrade;


//���ڲ��Է��������ݽṹ
typedef struct tagStock5MinKData
{
	int nCode;//��Ʊ��ָ������
	//int nFileStartYmd, nFileStartMin, nFileStopYmd, nFileStopMin; //�ļ����ݵ���ֹ����ʱ��
	//int nStartYmd, nStartMin, nStopYmd, nStopMin; //�ṹ�����ݵ���ֹ����ʱ��
	//int nStopTradeStartYmd, nStopTradeStopYmd; //��ǰ����������ͣ��ʱ��
	long  lCount=0;  //����������(��48��ת��Ϊ����������)
				   //���浥�����ɷ�����5����K�����ݣ�����ڴ治�㣬�������ʵ���СMAX5KS
	StockInfo	*usrKData;
	//���ù�Ʊ�����ͬʱ��ȡ��Ӧ��5����K������
	void SetCode(int Code)
	{
		nCode = Code;
	}

	//���ù�Ʊ�����ͬʱ��ȡ��Ӧ��5����K������
	void Read5MinData(int nStartDate, int nStopDate)
	{
		string sTmp;
		int nMarket;
		char sbuf[250];
		int j,nTmp;
		int nDataLen=0;
		FILE *fp;

		usrKData = NULL;
		lCount = 0;
		if (nCode >= 1000000)
		{
			nMarket = 1;
			nTmp= nCode- 1000000;
			sTmp.append(g_sMinute5[nMarket]);
			j = sTmp.find("*.lc5", 0);
			sTmp = sTmp.substr(0, j);
			sprintf_s(sbuf, "sh\\fzline\\sh%06d.lc5", nTmp);
		}
		else
		{
			nMarket = 0;
			nTmp = nCode ;
			sTmp.append(g_sMinute5[nMarket]);
			j = sTmp.find("*.lc5", 0);
			sTmp = sTmp.substr(0, j);
			sprintf_s(sbuf, "sz\\fzline\\sz%06d.lc5", nTmp);
		}

		if (g_nWorkMode == WORKMODE_REAL)
		{
			sTmp = g_sTDXPath;
			sTmp.append(sbuf);
			//��ȡ5����K���ļ���������
			lCount = GetFileSize((char*)sTmp.c_str()) / 32 ;
			if (lCount <= 0 || lCount > 10000000) return;
			int		nOldDataCount=0;
			usrKData = new StockInfo[lCount+ g_nStockDownDays * 48+48 ];
			//�ȶ�������ʷ����
			sTmp = g_sTDXHisDataPath;
			sTmp.append(sbuf);
			fopen_s(&fp, sTmp.c_str(), "rb");

			if (NULL != fp)
			{
				fseek(fp, -g_nStockDownDays * 48 * 32, SEEK_END);
				nOldDataCount = fread(usrKData, 32, g_nStockDownDays * 48, fp);
				fclose(fp);
			}

			sTmp = g_sTDXPath;
			sTmp.append(sbuf);
			Read5MinKData4Real(sTmp, nCode, usrKData+ nOldDataCount,
				lCount+48, lCount/48+1, nStopDate,900);

			lCount = lCount + nOldDataCount+1;
		}
		else
		{
			sTmp = g_sTDXHisDataPath;
			sTmp.append(sbuf);
			//��ȡ5����K���ļ���������
			lCount = GetFileSize((char*)sTmp.c_str()) / 32 ;

			if (lCount <= 0 || lCount > 10000000) return;

			usrKData = new StockInfo[lCount];
			fopen_s(&fp, sTmp.c_str(), "rb");
			if (fp != NULL)
			{
				lCount = nDataLen + fread(usrKData + nDataLen, 32, lCount, fp);
				fclose(fp);
				if (lCount == 0)
				{
					lCount = 0;
					delete usrKData;

					nDataLen = -1;
				}
			}
			else
			{
				lCount = 0;
				delete usrKData;
				nDataLen = -1;
			}
		}
		
	}
}Stock5MinKData;

//������Ĺ�Ʊ�����Ϣ
//�����Ʊ����5����K�����ݵĹؼ���Ϣ��������ǰͣ�����ڵȣ����ٶ��ļ��Ķ�д
class   CStockBlockInfo
{
public:
	int		nBlockCount = 0;//����Ʊ����
	//���ݿ�ʼ���ڡ��������ڣ���ʼʱ��̶�Ϊ0935������ʱ��̶�Ϊ1500
	int		nStartYmd;
	int		nStopYmd;
	float	*fMAShort = NULL, *fMAMid = NULL, *fMALong = NULL;
	Stock5MinKData	*usr5MinKDataInfo = NULL;//����Ʊ5����K���ļ���Ϣ
public:
	CStockBlockInfo()
	{
		nStartYmd=0, nStopYmd=0;
	}

	//�ж�ָ����Ʊ�����Ƿ��ڰ����,����������
	int	FindStockInBlock(int Code)
	{
		int i;
		int nRet = -1;
		for (i = 0; i < nBlockCount; i++)
			if (usr5MinKDataInfo[i].nCode == Code)
			{
				nRet= i;
				break;
			}

		return nRet;
	}

	//��ȡָ����Ʊ�����5����K������
	StockInfo	* Get5MinKData(int Code,long *lDataLen)
	{
		int i;
		StockInfo	*ptr = NULL;

		for (i = 0; i < nBlockCount; i++)
			if (usr5MinKDataInfo[i].nCode == Code)
			{
				ptr = usr5MinKDataInfo[i].usrKData;
				*lDataLen = usr5MinKDataInfo[i].lCount;
				break;
			}

		return ptr;
	}
	//��������5����K������
	//���nDate��nStartYmd ��nStopYmd��Χ�ڣ����仯����false����Ҫ�仯����true
	bool	Read5MinKData()
	{
		if (   NULL == usr5MinKDataInfo
			|| nStartYmd <= 0
			|| nStopYmd <= 0)  
				return false;

		int i,nStart= nStartYmd,nStop= nStopYmd;
		int  nDate, nTime;
		char sbuf[250];
		GetCurrentDateTime(&nDate,&nTime);
		sprintf_s(sbuf, "UpdateDate %s.%s->��Ʊ����%d ��ʼ�� %d  %d", 
			g_usrAutoTrade.strBlock, g_usrAnalysePattern[g_nAnalysePat].sName,
			nBlockCount,  nDate, nTime);

		LogFile("trade\\readlog.txt", sbuf);

		for (i = 0; i < nBlockCount; i++)
			usr5MinKDataInfo[i].Read5MinData(nStart, nStop);

		GetCurrentDateTime(&nDate, &nTime);

		sprintf_s(sbuf, "UpdateDate %s.%s->��Ʊ����%d ������ %d  %d",
			g_usrAutoTrade.strBlock, g_usrAnalysePattern[g_nAnalysePat].sName,
			nBlockCount, nDate, nTime);

		;
		LogFile("trade\\readlog.txt", sbuf);

		return true;
	}

	//ɾ��5����K�������ڴ�
	void	Delete5MinKData()
	{
		/*StockInfo *ptr = NULL;
		for (int i = 0; i < nBlockCount; i++)
		{
			ptr=usr5MinKDataInfo[i].usrKData;
			if (NULL != ptr)
				delete ptr;
		}*/
	}

	//���nDate��nStartYmd ��nStopYmd��Χ�ڷ���true,����false
	bool	DateValid(int nDate)
	{
		if (nDate >= nStartYmd && nDate <= nStopYmd)
			return true;
		else
			return false;
	}

};
CStockBlockInfo g_usrBlock5MinKData;
void	SetDebugStockList(CStockBlockInfo *ptrStockBlock);
bool	FindUppingStock(CStockBlockInfo *ptrBlockInfo, int nStockIndex, int nStopDate, int nStopTime);