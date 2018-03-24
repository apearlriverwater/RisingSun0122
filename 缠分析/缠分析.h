#pragma once
class   CStockBlockInfo;

int     g_nAnalysePat = 0;//分析模式索引
int		g_nStockDownDays = 0; //初选1买标的的下跌周期
int     g_nStockBufSize=0;       //用于单一标的分析的缓冲区大小
int     g_nCJDBufSize=0, g_nCZSPZBufSize=0;//缠极点、中枢盘整缓冲大小

#define  ANALYSEWEEKS  4  
short		*g_nWeekList;

#define     MASHORT 5
#define     MAMID  20
#define     MALONG  30
#define     MAXSTEPDOWN 15  //阶段最大跌幅
#define		MAXTRADENUMBER  30  //拟买入标的的最大数量，包括自定义的持仓标的

#define	    BUY1STOCKNUMBERS	50  //最大1买标的数量
int			g_nMaxHolding  =   10; //基于量化分析策略选定的持仓标的
/*              g_nStockDownDays    g_nWeekList
    超短线  ：       30            10,20,30
    短线配置：       60            15,30,45    
	中线配置：      120            60,90,120 
	长线配置：      240            120,180,240

*/
typedef struct tagAnalysePattern
{
	char sName[8];
	short nStockDownDays;
	short nMaxHolding;//最大持仓数
	short nDownGate;//跌幅必须达到的门槛
	short nStep;
	short nWeekList[ANALYSEWEEKS];
}AnalysePattern;

AnalysePattern g_usrAnalysePattern[]=
{
	{"超短", 30,10, 3, 1,{  5, 10, 15,0 } },
	{"短线", 60,15, 6, 3,{ 15, 30, 45,0 } },
	{"中线",120,20, 9, 6,{ 60, 90,120,0 } },
	{"长线",240,25,15,12,{120,180,240,0 } }
};


//下跌周期末端的背驰分析：下跌幅度大于20%才分析，将来改为基于周期的可定义数据0929   todo
#define		CSTOCKMAXDOWNGATE  20
#define     UPSELLGATE 10    //开始进行卖出分析门槛
#define     AUTODOWNSELLGATE 10  //止损门槛
#define		CJDWAITING  5  //等待缠极点升破或跌破5日均线周期数
#define     MAX5KS	  200*48	//最多分析200个交易日5分钟K线
#define		BSCOUNT		6       //买卖点总数不操过6个
//近期高低点，最多计算5对  0-最近高低点，1第2个高低点，以此类推
#define     LASTESTHIGHLOWCOUNT 1
#define		TBWEEKS		17
#define     TBPOINTCOUNT  8
#define     ZXHOLDINGCOUNT 20 //自选持仓的标的,含自选/平安荐股等
#define		CZSVARRATE 3      //中枢波动率，超出此范围才认为是新中枢或盘整产生

//最大分析数据项  通达信最大处理的K线数为8000个
const int		g_nMaxDataLen = 4096;
const int		g_nMaxStock = 15;
int				g_nUPPERCENT = 15, g_nDOWNPERCENT = 15;
const			short conMAXSTOCK = 30;
short			MAXHOLDDAYS = 45;
int				g_nAnalyseStartDate=-1,g_nAnalyseStopDate = 100;//g_nAnalyseStartDate=-1 开始时间由数据文件确定
int				g_nAnalyseStartTime = -1, 
				g_nAnalyseStopTime = -1;//单一股票调试时的开始时间，与g_nAnalyseStartDate对应
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
	上证综指,999999
	上证50,000016
	沪深300,000300
	上证180,1000010
	上证380,1000009
	中证100,1000903
	中证500,1000905

	深证成指,399001
	创业板,399006
	中小板,399005
	深证100R,0399004
	深证300,0399007
	中小300,0399008
	深证综指,0399106

	通达信行业
	软件服务  //880493
	银行880471，证券880472，地产880482，有色880324，煤炭880301,钢铁880318
	*/

	StockCodeName g_usrStockIndexCodeName[] =
	{
		{ "上证综指", 1000001 },
		{ "上证180", 1000010 },
		{ "沪深300", 1000300 },
		{ "深证综指", 399106 },
		{ "创业板", 399006 },
		{ "中小板", 399005 },
		{ "中小300", 399008 },
		{ "深证300", 399007 },
		{ "上证50", 1000016 },
		{ "上证380", 1000009 },
		{ "中证100", 1000903 },
		{ "中证500", 1000905 },
		{ "深证成指", 399001 },
		{ "深证100R", 399004 },

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

//五分钟K线文件信息,主要用于对历史数据/通达信数据/实时数据的起始时间/数据总项数(除48可转化为交易日数据)
typedef struct tagC5MinKFileInfo
{
	int nStartYmd,nStartMin, nStopYmd,nStopMin; //实际数据的起止日期时间
	long  lCount;  //数据总项数(除48可转化为交易日数据)
}C5MinKFileInfo;



typedef struct tagBSInfo
{
	unsigned short	nYmd,nMin,nWeek,nK;
	//nMode:分析指标，如MACD/DIFF DEA 均线，持仓周期到、止损、止盈等,nType 买卖依据，如 盘整配置、中枢背驰、均线背驰
	short	nMode,nType,nUpPercent,nDownPercent;
	float	fBuySellPrice,fClose;
	float	fCJDMaxDownPercent,fDownPrice;//在有效缠极点高位最大回撤比例及回撤止损价位，低于即出局
	unsigned short	nMustSellYMD,nAmount;// nMustSellYMD必须清仓的日期，不考虑中间不交易的日子	nAmount交易手数
}BSInfo;

//top、botton数据项，股票数据索引及对应的极值，极值可能是收盘价、最高价、MACD等
typedef struct tagDayTrends
{
	BSInfo	usrBSPoint[BSCOUNT];
	short	nWeekList[ANALYSEWEEKS];//记录长中短均线均上涨的有效周期
	unsigned short		nBSIndex;//有效买卖点数
	int		nValue;//根据跌幅、连续收窄的天数计算权重，作为买入排序的依据
	int		nDownRate;//最高点至今的跌幅
	int		nCode,nLastetBuyYmd;//最近一次买入日期
	bool	bDown,bBSChanged; 
}DayTrends;

//自选持仓
typedef struct tagZXHolding
{
	char strName[60];//自选组合名称
	int  nCode[20]; //组合标的
}ZXHolding;
ZXHolding		g_usrZXHolding[ZXHOLDINGCOUNT];  //最多支持10组自选持仓组合
#define    STNUMBERS  80
int		g_nSTlist[STNUMBERS] = {1};//ST板块代码列表
  

//读取通达信导出的权息文件,获取以10股为单位的送转股/分红/配股和配股价信息,
//数据段之间通过0x09分隔,连续出现0x09表明部分字段缺失,数据记录之间的分隔符0x0d,0x0a
//300381	溢多利	     20161018	20.00	1.000
//002456	欧菲光	     20161202                    - 5.0	102797.9
//300547	川环科技	 20161202		10.000
typedef struct tagStockQuanXi
{
	INT32	nCode, nDate;
	float	fGiven, fGain, fBuyCount, fBuyPrice;
}StockQuanXi;

StockQuanXi  *g_pStockQuanXi=NULL;

//1买数据结构  买点降序排序，序号越小买入价值越大
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

	//保持以均线向上未基准排序的基础上，
	//对同一均线趋势下的标的按最高以来的跌幅进行降序排序
	void	SortByDownRate()
	{
		int  nValue = 0,j=0;
		for (int i = 0; i < nBuy1Count; i++)
		{
			nValue = usrBuy1List[i].nValue;
			j = i+1;
			//把最大的排在最前面
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
//对DayTrends g_usrDayTrends.usrBuy1List保存的标的BUY1STOCKNUMBERS个标的中有买点标的排到前面
//todo 2017-02-19待优化买点价值的排序,出现多个标的又买入点时如何排序与优选
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
	int     nDateTime;//月日时间
	int		nPlace, nP1, nP3;   //位置  nP1,nPlace,nP3
	char    nStatus;   //-1 低点，买点  1 峰点，卖点
	char    nNewHighLow;//-1 新高，  1 新低，0普通
	bool    bIsUp;	   //上升线段true，否则为下跌  
	float   fLineLen;  //线段长度，暂时用价格差表示
	int	    nLineBi;   //线段长度比
}CJDInfo;
CJDInfo			*g_pusrCJD = NULL;

//该信息同时用于市场温度初步计算
typedef struct tagRefStockInfo
{
	unsigned short	nYmd,nMin;
	int				nIndex[7]; 
	float			fAmount[7];
}RefStockInfo;

//top、botton数据项，股票数据索引及对应的极值，极值可能是收盘价、最高价、MACD等
typedef struct tagTBPoint
{
	int		nIndex; //缠极点索引或者数据索引
	float	fValue; //缠极点或数据索引对应最高点或最低点
	float	fEnergy; //缠极点对应量能
	int     nDate; //日期，数据分析检查使用
}TBPoint;

 typedef struct tagStockDayInfo
{
	int		nYmd;
	int		fOpen,fHigh,fLow,fClose; 
	int		fAmount;
	int		nNumber;
	int		ForUsed;
}StockDayInfo;

//nMode:分析指标，如MACD/DIFF DEA 均线，持仓周期到、止损、止盈等,nType 买卖依据，如 盘整配置、中枢背驰、均线背驰
enum BUYSELLMODE{
	BSMODE_MACD=101,BSMODE_DIFF=102,BSMODE_DEA=103,
	BSMODE_STOPUP=104,BSMODE_STOPDOWN=105,BSMODE_MAXHOLDWEEKS=106,BSMODE_SECOND=107,BSMODE_THIRD=108
};
enum BUYSELLTYPE{
	BSTYPE_STOPUP=1,BSTYPE_STOPDOWN=2,BSTYPE_MAXHOLDWEEKS=4,BSTYPE_PZBC=8,
	BSTYPE_ZSBC=16,BSTYPE_JXBC=32,BSTYPE_2BUY=64,BSTYPE_3BUY=128,
	BSTYPE_JXDOWN = 256,  //长中短均线下跌
	BSTYPE_STEPUP=512     //平台突破
};

enum WORKMODE{
	WORKMODE_DEFAULT = 0, WORKMODE_REAL = 1, WORKMODE_TRAINING = 2,
	WORKMODE_DEBUG=3, WORKMODE_BLOCK=4
};


//todo  待优化20170212
string	g_sRefIndex[] =
{ "sz\\fzline\\sz399001.lc5",  /*  深综指 */
"sz\\fzline\\sz399006.lc5", /*  深创业板 */
"sz\\fzline\\sz399300.lc5", /*  深证300 */
"sh\\fzline\\sh000010.lc5", /*  上证180 */
"sh\\fzline\\sh000300.lc5", /*  上证300 */
"sz\\fzline\\sz399005.lc5",  /*  深中小板 */
"sh\\fzline\\sh000001.lc5", /*  上证综指 */
""
};

string	g_sRefName[] =
{"深综指 ",
"深创业板",
"深证300",
"上证180",
"上证300",
"深中小板",
"上证综指",
""
};

const int g_nMinCount = 240;//基于分钟记录标的的参数，共240项

//当前正在处理的指数数据项，每次使用前tdx应先调用StoreMarketCTA
int   g_nCurrentMarketIndex = -1;

//工作模式：实时监控，训练学习，评估等
WORKMODE g_nWorkMode = WORKMODE_DEFAULT;


//交易日实时分析
//bool g_bRealMode = false;
//true  缠分析模式直接有应用程序调用； false 由通达信调用
bool	g_bAnalyseMode=false;
//计算周期数，在实时分析时不必分析太多数据  尽在作为通达信的DLL使用时有作用
int    g_nCaclDataStartPoint=0;
//分析周期
int    g_nWeek=0;
int		g_nCurrentStockDate=0,g_nCurrentStockTime=0;//当前处理的股票时间   tdx服务器给出的最新实时数据的对应时间

//当前分析代码、索引、量比
unsigned int    g_nCurrentStockCode=0;
float			g_fCurrentStockLB=1.0;

float *g_fMAShort, *g_fMALong;

void	SelectStock2Sell();
void	Get5MinKFileInfo(string path, C5MinKFileInfo *usrFileInfo);

int			 g_nMACDLong=26,g_nMACDMid=12,g_nMACDShort=9;

//g_sTDXPath通达信数据目录,g_sTDXHisDataPath通达信5分钟历史数据目录,两者结合才能完成买卖点实时监控
string g_sTDXPath= "E:\\02soft\\new_tdx\\vipdoc\\";  //通达信数据目录
string g_sTDXHisDataPath ="E:\\01finance\\new_tdx2012-2016\\vipdoc\\"; 

string g_sHisDataPathList[] = { "E:\\01finance\\new_tdx2012-2016\\vipdoc\\",//0 策略分析用历史数据
                                "E:\\02soft\\new_tdx\\vipdoc2014-2016\\" };//  1 实时监控的历史数据目录
//"E:\\02soft\\99zd_gfzq\\vipdoc2014-2016\\"
// "E:\\02soft\\new_tdx\\vipdoc2014-2016\\";// "E:\\01finance\\vipdoc2012-201609\\";  // "E:\\02soft\\new_tdx\\vipdoc2014-2016\\";//"E:\\01finance\\vipdoc2012-201609\\";  //通达信5分钟历史数据目录,两者结合才能完成买卖点实时监控
//"E:\\monitor\\""E:\\02soft\\new_tdx\\";E:\monitor  E:\\02soft\\99zd_gfzq\\"

//5分钟K线文件数据:通达信,历史数据,实时数据 起止日期时间,数据项数,在初始化时读取次数据
C5MinKFileInfo g_usrTDX5KFileInfo, g_usrHis5KFileInfo, g_usrReal5KFileInfo;//

string	g_sMinute5[2]={"sz\\fzline\\*.lc5","sh\\fzline\\*.lc5"};
string	g_sDayFile[2]={"sz\\lday\\*.day","sh\\lday\\*.day"};
string  g_sMailContent="",g_sMailTitle="";  //记录你向邮箱发送的BS信息

char	g_sLogFile[250]={0},g_sHolding[250]={0},g_sBSLog[250]={0},g_sOneBuy[250]={0};
char	g_sLogPath[] = { "log\\" }, 
		g_sQuanxiPath[] = { "quanxi\\" },
		g_sSTBlock[] = { "cfg\\ST板块.EBK" },
		g_sRealMonitor[] = { "cfg\\实时监控.EBK" },  //最新的1买标的
		g_sHS300[] = { "cfg\\hs300.EBK" },
		g_sYS50[] = { "cfg\\央视50.EBK" },
	    g_sCYB[] = { "cfg\\创业板.EBK" }, 
	    g_sZXB[] = { "cfg\\中小板.EBK" }, 
		g_sZXC[] = { "cfg\\中小创.EBK" },
		g_sHYLT[] = { "cfg\\行业龙头.EBK" },
		g_sSZ180[] = { "cfg\\上证180.EBK" },
		g_sYQ100[] = { "cfg\\央企100.EBK" },
		g_sCY300[] = { "cfg\\创业300.EBK" },
		g_sZX300[] = { "cfg\\中小300.EBK" },
		g_sETF[] = { "cfg\\etf.txt" },
		g_sDPLC[] = { "cfg\\大盘蓝筹.EBK" },
		g_sZZ100[] = { "cfg\\中证100.EBK" },
		g_sZZ300[] = { "cfg\\中证300.EBK" },
		g_sSZ300[] = { "cfg\\深证300.EBK" };

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
	int     nVarRate;//中枢或盘整的波动率
	int		nStart, nStop;//开始日期结束日期  调试用
	bool    bIsZS; //0盘整 1中枢
	int		p1, p2;//位置  起始缠极点位置
	bool	bIsUp; //true表示升，false表示跌
	float   fMaxLow, fMinHigh, fLow, fHigh;  //中枢最高、最低价的极值,中枢内最高、最低值

    //盘整或中枢状态，在中枢生成时判断是否创新高或创新低，在买卖点分析时判断是否出现背驰
    //0  没有操作价值，普通；
    //1 创新低，2创新低且MACD背驰，3 创新低且DIF背驰,4创新低且DEA背驰
    //-1 创新高，-2创新高且MACD背驰，-3 创新高且DIF背驰, -4创新高且DEA背驰
	int     nStatus;

	//返回中心线数据										 
	float   Mid()
	{
		return (fLow + fHigh) / 2;
	}

	//返回中枢波动率：相对于中心线的百分比，中心线=（fLow+ fHigh）/2
	int  VarRate(StockInfo *pNowKData,CJDInfo *usrCJD)
	{
		nVarRate = pNowKData[usrCJD[p1].nPlace].nYmd;
		nStart = (nVarRate / 2048 + 104) * 10000 + nVarRate % 2048;
		nVarRate = pNowKData[usrCJD[p2].nPlace].nYmd;
		nStop = (nVarRate / 2048 + 104) * 10000 + nVarRate % 2048;

		nVarRate = VarRate(fHigh, fLow);
		return nVarRate;
	}

	//根据指定的新高、新低计算中枢波动率：相对于中心线的百分比，中心线=（fLow+ fHigh）/2
	//用于中枢是否有效判断，结果不保存
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

//缠线段趋势  todo 0818
typedef struct tagCLineInfo
{
	bool	bIsUp, bPeak, bBotton; ////true表示升，false表示跌
	int		p1, p2;//位置  起始极点位置
	float   fLow, fHigh;  //线段最高、最低价
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

//将当前持仓情况保存到文件
void	SaveTradeInfo(int)	;
void	SaveHolding2BSLog();

//读取当前持仓情况
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



	typedef BOOL(*pRulerFUNC)(StockInfo *,int,CNowTrends *); //定义cNowTrends用的规则处理函数指针类型
	pRulerFUNC m_pRulerFunction[]= { 
		/*(pRulerFUNC)&IsFocusing ,*/
		(pRulerFUNC)&IsRSIBuy,
		(pRulerFUNC)&IsATRBuy,
		NULL
	};

class	CNowTrends
{
public:
#define		CONTINUEDOWNWEEKS  10 //5日均线在10日均线下连续运行周期数、跌幅低于前期买入价

	int		nHoldingAmount;
	bool	bDayUp, bBSChanged;//记录持仓标的日线级别是否上涨态势，方便小周期分析   买卖点变化
	//根据实际动态调整保存的信息内容 mTop由大到小  mBotton由小到大(缠极点最高价最低价)
	TBPoint	mTop[TBPOINTCOUNT], mBotton[TBPOINTCOUNT];
	//未持仓标的保存分析周期内量能最大值最小值，可能是MACD DEA DIFF 中枢盘整价格变化量累计值
	//持仓标的保存首次买入后量能最大值最小值，可能是MACD DEA DIFF 中枢盘整价格变化量累计值
	//记录数据索引及其对应数据  缠极点与量能峰值没有一一对应关系
	TBPoint   mMaxEnergy[TBPOINTCOUNT], mMinEnergy[TBPOINTCOUNT];

	BSInfo	usrBuy[BSCOUNT];	   //不一定是顺序存放买点信息
	BSInfo	usrSell[BSCOUNT];

	//购买时计算好止损fAutoDownSellPrice、止盈价格fAutoUpSellPrice、二买门槛f2BuyGate，f3BuyGate？？？
	float	fAutoUpSellPrice, fAutoDownSellPrice, f2BuyGate, f3BuyGate;
	//买卖时设定BS点最近的高低点，用于判断是否跌破或升破近期高低点
	TBPoint   m_usrLastestHigh[LASTESTHIGHLOWCOUNT], m_usrLastestLow[LASTESTHIGHLOWCOUNT];

	//nStatus >0 终结于底分型，<0终结于顶分型  = 无分型; nNewHighLow>0 	创新高,<0创新低  =0非新高新低
	short				nStatus, nNewHighLow;
	unsigned short		nLatesBuyYmd, nFirstSellCJD;

	short				nBuyIndex, nSellIndex;
	int					nCode;
	unsigned short		nCurYmd, nCurMin;  //当前分析周期对应的交易日期、时间，停牌或无数据时停留在最后的交易日期、时间
	StockInfo           *p5MinKData;//原始的5分钟K线数据
	int                 n5MinKDataLen;
	StockInfo           *pNowKData;//按分析周期转换后的K线数据
	int                 nNowKDataLen;
	
	int					nCJDCount = 0;
	CZSPZInfo			*pCZSPZ;//中枢盘整数据结构
	CZSPZInfo			*usrCZSPZ;
	CJDInfo				*usrCJD;
	int					nCZSPZCount = 0;
	float				*fDIF, *fDEA, *fMACD;
	float				*fMAShort, *fMAMid, *fMALong; //长短周期均线指针
	long				*nVolMaLong, *nVolMid, *nVolShort; //成交量长中短日均值
	short				    nWeekList[ANALYSEWEEKS];//记录长中短均线均上涨的有效周期
public:
	//当前分析周期收盘价、持仓均价和前日收盘价，用于统计市值;持股均价
	//前日均价用于判断是否出现了涨停或跌停
	float				fCurClose, fAveragePrice, fLastDateClose;
	//买卖点分析使用
	unsigned short		nMaxHighYmd, nMaxHighMin;  //当前分析周期对应的最大HIGH对应的交易日期、时间
	float				fMaxHigh;
	unsigned short		nMinLowYmd, nMinLowMin;  //当前分析周期对应的最小LOW对应的交易日期、时间
	float				fMinLow;
	unsigned short		nMaxHigh, nMinLow;//最大HIGH/LOW对应的当前周期K线序号，用于快速确定极值在当前分析周期的位置

public:
	//规则检查，全部规则均满足时返回true,否则返回false，5分钟K线数据必须在调用前设置好
	//规则以配置参数的方式存在，增加规则时调整配置参数和实现函数，程序框架不必调整
	bool CheckRuler(pRulerFUNC *ptr)
	{
		bool bRet = true;
		 
		int nLen = n5MinKDataLen;
		
		CreateStockData(&nLen, p5MinKData, pNowKData, 5, 240);

		//全部规则按与的方式执行，有一项无效即退出规则执行
		while (*ptr != NULL && bRet==true)
		{
			bRet=(*ptr)(pNowKData, nLen,this);
			ptr++;
		}

		return bRet;
	}

	//定位分析中期内最低值得缠极点，返回值是缠极点序号
	//该序号是最接近最低值的缠极点
	int LocateMaxHighCJD()
	{
		int i = nCJDCount - 1;

		if (usrCJD[i].nStatus > 0) i--;

		while (i > 0 && usrCJD[i].nPlace > nMaxHigh)  i -= 2;
		
		return i + 1;
	}
	//定位分析中期内最高值得缠极点，返回值是缠极点序号
	//该序号是最接近最低值的缠极点
	int LocateMinLowCJD()
	{
		int i = nCJDCount - 1;

		if (usrCJD[i].nStatus < 0) i--;

		while (i > 0 && usrCJD[i].nPlace > nMinLow)  i -= 2;

		return i + 1;
	}

	//计算MACD  EMA 
	/*
	以EMA1的参数为12日，EMA2的参数为26日，DIF的参数为9日为例来看看MACD的计算过程
	1、计算移动平均值（EMA）
	12日EMA的算式为   EMA（12）=前一日EMA（12）×11/13＋今日收盘价×2/13
	26日EMA的算式为   EMA（26）=前一日EMA（26）×25/27＋今日收盘价×2/27
	2、计算离差值（DIF）   DIF=今日EMA（12）－今日EMA（26）
	3、计算DIF的9日EMA   根据离差值计算其9日的EMA，即离差平均值，是所求的MACD值。
	为了不与指标原名相混淆，此值又名DEA或DEM。
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

	//分析股价时间系列的买卖点
	void AnalyseStockData(int nSrcDataLen, bool bStockInTrade)
	{
		if (nSrcDataLen > 3)
		{
			//当前分析时点停牌标的不做处理
			//加严判断，防止个别5分钟K线数据错误导致误判停牌
			if (this->p5MinKData[nSrcDataLen - 1].nNumber == 0
				&& this->p5MinKData[nSrcDataLen - 2].nNumber == 0)
				return;

			this->SetLastDateDayClose(nSrcDataLen, this->p5MinKData);
			//当前分析时涨停或跌停不做处理
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
			//最早买入时间离当前交易日最少差1天才进行二买分析
			if ((this->p5MinKData + nSrcDataLen - 1)->nYmd <= this->GetEldBuyYmd())
				return;

			int n = this->GetMustSellYmd();
			if ((this->p5MinKData + nSrcDataLen - 1)->nYmd >= n && n>0)
			{
				//固定用30分钟周期数据判断当前股票是否处于下跌状态  todo 20170222待优化
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

			//5分钟数据转到15/30/60分钟,nDataLen返回转换后的分钟数据总数
			CreateStockData(&nDataLen, this->p5MinKData, this->pNowKData, nSourceMin,
				this->nWeekList[i]);
			SetMaxHighMinLow(nDataLen);

			SetAnalyseMode(nDataLen, 960, this->nWeekList[i], nCode);

			float	fCmd = 0, fMode;
			//收盘价均值
			MA(nDataLen, this->pNowKData, MASHORT, MAMID, MALONG,
				this->fMAShort, this->fMAMid, this->fMALong);


			//更新持仓标的当前周期的收盘价
			SetCurClose(this->p5MinKData[nSrcDataLen - 1].fClose);

			CaclCJD(nDataLen, NULL, NULL, NULL, NULL);

			//中枢盘整计算
			CaclCZSPZ(nDataLen, NULL, NULL, NULL, NULL);

			if (bStockInTrade == true)
				AutoSell(nDataLen);

			//卖点分析	 
			if (bStockInTrade == true && nCJDCount>10)
			{
				MACD(nDataLen, fDIF, fDEA, fMACD, this->pNowKData,
					g_nMACDMid, g_nMACDLong, g_nMACDShort);

				//卖点分析
				fCmd = -1;
				fMode = BSMODE_DIFF;
				CaclBSPoint(nDataLen, NULL, &fMode, &fCmd, fDIF);

				//二买前首先判断目前价位是否跌破止损价位，跌破止损价位时不进行二买分析
				if (fCurClose-fAutoDownSellPrice>0) //20170503 加入
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

				//买点分析：一买分析  基于DIF判背驰
				fMode = BSMODE_DIFF;
				CaclBSPoint(nDataLen, NULL, &fMode, &fCmd, fDIF);
			}

			i++;
		};
}

	//分析股价时间系列是否存在底背驰，是则返回true
	bool DetectBtnBC(int nSrcDataLen,int nWeek)
	{

		if (nSrcDataLen > 3)
		{
			//当前分析时点停牌标的不做处理
			//加严判断，防止个别5分钟K线数据错误导致误判停牌
			if (this->p5MinKData[nSrcDataLen - 1].nNumber == 0
				&& this->p5MinKData[nSrcDataLen - 2].nNumber == 0)
				return false;
		}

		short nSourceMin = 5, i = 0;
		int	nDataLen = nSrcDataLen;

		memset(this->pNowKData, 0, sizeof(StockInfo)*nDataLen / nWeek * 5);

		//5分钟数据转到15/30/60分钟,nDataLen返回转换后的分钟数据总数
		CreateStockData(&nDataLen, this->p5MinKData, this->pNowKData, nSourceMin,nWeek);
		SetMaxHighMinLow(nDataLen);

		SetAnalyseMode(nDataLen, 960, nWeek, nCode);
		CaclCJD(nDataLen, NULL, NULL, NULL, NULL);

		//底背驰分析	 
		if (nCJDCount-1-LocateMinLowCJD()<2  && nCJDCount>10)
		{
			float	fCmd = 0, fMode;

			fDEA = g_fbuf1;
			fDIF = g_fbuf2;
			fMACD = g_fbuf3;
			MACD(nDataLen, fDIF, fDEA, fMACD, this->pNowKData,
				g_nMACDMid, g_nMACDLong, g_nMACDShort);

			//计算分析周期内最大值之后的CJD峰谷
			CaclCJDTBPoint(fDIF, nDataLen);
			// 计算分析周期内量能峰谷
			CaclEnergyTopBtn(fDIF, nDataLen);

			int nBC = BtnBC(nCJDCount - 1);
			return nBC > 0;
		}
	}

	//设置利用历史数据文件的分析计算模式
	// pfCount  分析的周期数    
	//pfWeek  分析周期，与通达信的周期数对应
	//股票或指数代码
	void SetAnalyseMode(int DataLen, int pfCount, int pfWeek, int nCode)
	{
		//g_nMaxAnalyseDateLen=DataLen;
		g_bAnalyseMode = true;
		g_nCaclDataStartPoint = 0;
		if (DataLen>g_nMaxDataLen) //防止数据过多导致g_usrStock下表越界
			g_nCaclDataStartPoint = DataLen - g_nMaxDataLen - 10;

		//源头控制，防止出现数据越界
		g_nCaclDataStartPoint = max(max(DataLen - max(0, pfCount), 0), g_nCaclDataStartPoint);

		g_nWeek = pfWeek;
		g_nCurrentStockCode = nCode;
		nCJDCount = 0;

		memset(usrCJD, 0, sizeof(CJDInfo));
	}

	//缠线段计算，用于判断整体走势
	void	CaclCLine()
	{
		int		i = 1;
		float	h = 0, l = 0;
		bool    bNewLine = false;//在延伸中生成新线段处理，防止要设计成递归处理
		bool	bIsUp = false;

		//计算缠线段状态：上升或下跌
		//线段的定义：至少由3笔构成，且前三笔必须有重叠部分（可能是中枢或者盘整）,； 线段的初级终结定义：1+1模式。
		if (nCJDCount>3)
		{
			while (i<nCJDCount)
			{
				if (bNewLine == false)
				{
					if (usrCJD[i].nStatus >0 /*&& i+3<nCJDCount*/)
						//底部极点
					{
						h = min(pNowKData[usrCJD[i + 1].nPlace].fHigh,
							pNowKData[usrCJD[i + 3].nPlace].fHigh);
						l = max(pNowKData[usrCJD[i].nPlace].fLow,
							pNowKData[usrCJD[i + 2].nPlace].fLow);

						if (pNowKData[usrCJD[i].nPlace].fLow
							- pNowKData[usrCJD[i + 3].nPlace].fHigh >0.0)
							bIsUp = false; //线段下跌
						else
							bIsUp = true; //线段上涨
					}
					else if (usrCJD[i].nStatus <0 /*&& i+3<nCJDCount*/)
						//顶部极点
					{
						h = min(pNowKData[usrCJD[i].nPlace].fHigh,
							pNowKData[usrCJD[i + 2].nPlace].fHigh);
						l = max(pNowKData[usrCJD[i + 1].nPlace].fLow,
							pNowKData[usrCJD[i + 3].nPlace].fLow);


						if (pNowKData[usrCJD[i].nPlace].fHigh
							- pNowKData[usrCJD[i + 3].nPlace].fLow >0.0)
							bIsUp = false; //线段下跌
						else
							bIsUp = true; //线段上涨
					}
					//else
					//	bIsUp=usrCJD[i].bIsUp;//若最后2笔未成为线段，延续前面的走势，难以判断走势

				}
				if (h - l >= 0.0 || bNewLine == true) //生成新线段：至少由3笔构成，且前三笔必须有重叠部分（可能是中枢或者盘整）
				{
					if (bNewLine == false && usrCJD[i].bIsUp == bIsUp) //线段延伸 todo 可能出现新低、新高的处理0820
					{
						if ((bIsUp == true && (pNowKData[usrCJD[i + 1].nPlace].fHigh
							- pNowKData[usrCJD[i + 3].nPlace].fHigh >0.0))  //上升线段内部创新高
							|| (bIsUp == false && pNowKData[usrCJD[i + 1].nPlace].fLow
								- pNowKData[usrCJD[i + 3].nPlace].fLow <0.0))//下跌线段内部创新低
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
					else if (bNewLine == false && usrCJD[i].bIsUp != bIsUp)//线段新生
					{
						if (usrCJD[i].nStatus >0) //
						{
							if (pNowKData[usrCJD[i].nPlace].fLow
								- pNowKData[usrCJD[i + 4].nPlace].fLow >0.0)
							{//上升线段生成后马上出现创新低，该笔无效
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
								else//内部新低
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
							{//todo 创新低处理
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
							{//下跌线段内创新高，该笔无效
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
							{//下跌线段生成后马上出现创新高，该笔无效
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

					if (bIsUp == true)  //升势
					{
						if (usrCJD[i].nStatus >0)  //底
						{
							//i+1、i+2笔创新高，继续升
							while (pNowKData[usrCJD[i + 2].nPlace].fHigh
								- pNowKData[usrCJD[i].nPlace].fHigh>0.0)
							{
								usrCJD[i].bIsUp = true;
								usrCJD[i + 1].bIsUp = true;
								usrCJD[i + 2].bIsUp = true;
								bIsUp = usrCJD[i].bIsUp;
								i = i + 2;
							}

							//i+1、i+2不创新高，且i+1低于i-1  转跌 新线段
							if (pNowKData[usrCJD[i + 2].nPlace].fHigh
								- pNowKData[usrCJD[i].nPlace].fHigh<0.0
								&& pNowKData[usrCJD[i + 1].nPlace].fLow
								- pNowKData[usrCJD[i - 1].nPlace].fLow<0.0)
							{

								if (pNowKData[usrCJD[i + 4].nPlace].fHigh
									- pNowKData[usrCJD[i].nPlace].fHigh<0.0)
								{  //下跌线段生成后马上出现创新高，该笔无效
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
						else   //顶
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
								//{ //不断创新低
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
								//{  //i+2创新高，继续升
								//	break;
								//	/*usrCJD[i].bIsUp =true;
								//	usrCJD[i+1].bIsUp =true;	
								//	usrCJD[i+2].bIsUp =true;
								//	i=i+2;*/
								//}
							}

							//i+2不创新高，且i+1低于i-1  转跌 新线段
							if (pNowKData[usrCJD[i + 2].nPlace].fHigh
								- pNowKData[usrCJD[i].nPlace].fHigh<0.0
								/*&& pNowKData[usrCJD[i+1].nPlace].fLow
								-pNowKData[usrCJD[i-1].nPlace].fLow<0.0*/)
							{
								if (pNowKData[usrCJD[i + 4].nPlace].fHigh
									- pNowKData[usrCJD[i].nPlace].fHigh>0.0)
								{  //连续创新低，视同下跌
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
									{	//下跌线段生成后马上出现创新高，该笔无效
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
					else /*if( i<nCJDCount-2)*/ //跌势
					{
						if (usrCJD[i].nStatus >0)  //底
						{
							//i+2创新低，继续跌
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

							//i+2不创新低，且i+1高于i-1  转升  新线段
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
						else  //顶
						{
							//i+2创新低，继续跌  ???
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

							//i+2不创新低，且i+1高于i-1  转升  新线段
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
				{//三笔没有公共部分，不符合生成新线段规则，快升、快跌情况，原趋势延续0815
					usrCJD[i].bIsUp = bIsUp;
					usrCJD[i + 1].bIsUp = bIsUp;
					usrCJD[i + 2].bIsUp = bIsUp;
					i += 2;
				}
			}

			//最后一笔走势处理	 
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

		//找到数据的某日开始点进行转换
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
			
			pDest[j].fClose = pBase[i + k - 1].fClose;	 //防止收盘价算错

		}

		*nDataLen = j;

		//统一增加权息处理  1205
		//此代码应放在CNowTrends类统一计算，防止多次计算影响效率 TODO20170318
		if (false == CheckCodeQX(nCode))
			return;

		float fGiven = 0, fGain = 0, fBuyCount = 0, fBuyPrice = 0;
		float fGiven1 = 0, fGain1 = 0, fBuyCount1 = 0, fBuyPrice1 = 0;
		bool	bQuanXi = false;
		int		nDateLarge = 0, nDateSmall = 0;

		for (i = j - 1; i > 0; i--)
		{
			//暂不考虑分析交易期内一次以上的除权除息信息处理  1205  

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

			//权息变化时间不在目前分析时间区间
			if (nDateLarge > 0 || nDateSmall<0)
				break;
		}
	}

	//计算中枢  计算盘整
	//增加中枢、盘整延伸判断：若变化幅度小于VARRATE=3%，认为是中枢延伸，不判新新中枢或盘整产生；20170223
	void CaclCZSPZ(int DataLen, float* pfOUT, float* pfPlace, float* pfDATE, float* pfVOL)
	{
		int		iLineCount = 0;
		int		i = 1;
		bool	bNewZS, bNewPZ;
		int		NewHighLow1 = 0, NewHighLow2 = 0;
		float	fPZ, fZS;
		CZSPZInfo usrLowVarChannel;  //微小波动区间

									 //计算缠笔数据
		CaclCPen(DataLen, pfOUT, pfPlace, pfDATE, pfVOL);

		memset(usrCZSPZ, 0, (nCZSPZCount + 1) * sizeof(CZSPZInfo));
		memset(&usrLowVarChannel, 0, sizeof(CZSPZInfo));

		nCZSPZCount = 1;

		i = 2;
		while (i<nCJDCount)
		{
			//中枢或盘整开始的条件是笔比大于1.2
			while (i < nCJDCount - 1 && usrCJD[i].nLineBi < 12)
			{
				//当前中枢或盘整延伸
				//usrCZSPZ[nCZSPZCount-1].p2 = i;

				//记录低波动率区间
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
						//当前中枢或盘整的收盘价与前一中枢或盘整收盘价比较
						usrCZSPZ[nCZSPZCount].bIsUp = (bool)(pNowKData[usrCJD[usrCZSPZ[nCZSPZCount].p2].nPlace].fClose
							- pNowKData[usrCJD[usrCZSPZ[nCZSPZCount - 1].p2].nPlace].fClose>0.0);

						nCZSPZCount++;
						memset(&usrLowVarChannel, 0, sizeof(CZSPZInfo));
					}
					else if (nCZSPZCount>0)
					{
						//记录低波动率区间
						usrLowVarChannel.p1 = usrCZSPZ[nCZSPZCount - 1].p2;
						usrLowVarChannel.p2 = i;

						//指数延伸
						usrCZSPZ[nCZSPZCount - 1].p2 = usrCZSPZ[nCZSPZCount].p2;
						i = usrCZSPZ[nCZSPZCount].p2 - 1;
					}

				}
				else if (NewHighLow1 == -1 && NewHighLow2 == -1 && fPZ - fZS >= 0.0)
				{
					if (usrCZSPZ[nCZSPZCount].VarRate(pNowKData,usrCJD) > CZSVARRATE)
					{
						i = usrCZSPZ[nCZSPZCount].p2 - 1;
						//当前中枢或盘整的收盘价与前一中枢或盘整收盘价比较
						usrCZSPZ[nCZSPZCount].bIsUp = (bool)(pNowKData[usrCJD[usrCZSPZ[nCZSPZCount].p2].nPlace].fClose
							- pNowKData[usrCJD[usrCZSPZ[nCZSPZCount - 1].p2].nPlace].fClose>0.0);

						nCZSPZCount++;
						memset(&usrLowVarChannel, 0, sizeof(CZSPZInfo));
					}
					else if (nCZSPZCount>0)
					{
						//记录低波动率区间
						usrLowVarChannel.p1 = usrCZSPZ[nCZSPZCount - 1].p2;
						usrLowVarChannel.p2 = i;

						//指数延伸
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
						//当前中枢或盘整的收盘价与前一中枢或盘整收盘价比较
						usrCZSPZ[nCZSPZCount].bIsUp = (pNowKData[usrCJD[usrCZSPZ[nCZSPZCount].p2].nPlace].fClose
							- pNowKData[usrCJD[usrCZSPZ[nCZSPZCount - 1].p2].nPlace].fClose > 0.0);

						nCZSPZCount++;
						memset(&usrLowVarChannel, 0, sizeof(CZSPZInfo));
					}
					else if (nCZSPZCount>0)
					{
						//记录低波动率区间
						usrLowVarChannel.p1 = usrCZSPZ[nCZSPZCount - 1].p2;
						usrLowVarChannel.p2 = i;

						//指数延伸
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
						//当前中枢或盘整的收盘价与前一中枢或盘整收盘价比较
						usrCZSPZ[nCZSPZCount].bIsUp = (pNowKData[usrCJD[usrCZSPZ[nCZSPZCount].p2].nPlace].fClose
							- pNowKData[usrCJD[usrCZSPZ[nCZSPZCount - 1].p2].nPlace].fClose > 0.0);

						nCZSPZCount++;
						memset(&usrLowVarChannel, 0, sizeof(CZSPZInfo));
					}
					else if (nCZSPZCount>0)
					{
						//记录低波动率区间
						usrLowVarChannel.p1 = usrCZSPZ[nCZSPZCount - 1].p2;
						usrLowVarChannel.p2 = i;

						//指数延伸
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
						//当前中枢或盘整的收盘价与前一中枢或盘整收盘价比较
						usrCZSPZ[nCZSPZCount].bIsUp = (pNowKData[usrCJD[usrCZSPZ[nCZSPZCount].p2].nPlace].fClose
							- pNowKData[usrCJD[usrCZSPZ[nCZSPZCount - 1].p2].nPlace].fClose > 0.0);

						nCZSPZCount++;
						memset(&usrLowVarChannel, 0, sizeof(CZSPZInfo));
					}
					else if (nCZSPZCount>0)
					{
						//记录低波动率区间
						usrLowVarChannel.p1 = usrCZSPZ[nCZSPZCount - 1].p2;
						usrLowVarChannel.p2 = i;

						//指数延伸
						usrCZSPZ[nCZSPZCount - 1].p2 = usrCZSPZ[nCZSPZCount].p2;
						i = usrCZSPZ[nCZSPZCount].p2 - 1;
					}

				}
				else
				{
					if (usrCZSPZ[nCZSPZCount].VarRate(pNowKData,usrCJD) > CZSVARRATE)
					{
						i = usrCZSPZ[nCZSPZCount].p2 - 1;
						//当前中枢或盘整的收盘价与前一中枢或盘整收盘价比较
						usrCZSPZ[nCZSPZCount].bIsUp = (pNowKData[usrCJD[usrCZSPZ[nCZSPZCount].p2].nPlace].fClose
							- pNowKData[usrCJD[usrCZSPZ[nCZSPZCount - 1].p2].nPlace].fClose > 0.0);

						nCZSPZCount++;
						memset(&usrLowVarChannel, 0, sizeof(CZSPZInfo));
					}
					else if (nCZSPZCount>0)
					{
						//记录低波动率区间
						usrLowVarChannel.p1 = usrCZSPZ[nCZSPZCount - 1].p2;
						usrLowVarChannel.p2 = i;

						//指数延伸
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
					//当前中枢或盘整的收盘价与前一中枢或盘整收盘价比较
					usrCZSPZ[nCZSPZCount].bIsUp = (pNowKData[usrCJD[usrCZSPZ[nCZSPZCount].p2].nPlace].fClose
						- pNowKData[usrCJD[usrCZSPZ[nCZSPZCount - 1].p2].nPlace].fClose > 0.0);

					i = usrCZSPZ[nCZSPZCount].p2 - 1;
					nCZSPZCount++;
					memset(&usrLowVarChannel, 0, sizeof(CZSPZInfo));
				}
				else if (nCZSPZCount>0)
				{

					//记录低波动率区间
					usrLowVarChannel.p1 = usrCZSPZ[nCZSPZCount - 1].p2;
					usrLowVarChannel.p2 = i;
					//指数延伸
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
					//当前中枢或盘整的收盘价与前一中枢或盘整收盘价比较
					usrCZSPZ[nCZSPZCount].bIsUp = (pNowKData[usrCJD[usrCZSPZ[nCZSPZCount].p2].nPlace].fClose
						- pNowKData[usrCJD[usrCZSPZ[nCZSPZCount - 1].p2].nPlace].fClose > 0.0);

					nCZSPZCount++;
					if (usrLowVarChannel.p1>0)
						memset(&usrLowVarChannel, 0, sizeof(CZSPZInfo));
				}
				else if (nCZSPZCount>0)
				{
					//记录低波动率区间
					usrLowVarChannel.p1 = usrCZSPZ[nCZSPZCount - 1].p2;
					usrLowVarChannel.p2 = i;

					//指数延伸
					usrCZSPZ[nCZSPZCount - 1].p2 = usrCZSPZ[nCZSPZCount].p2;
					i = usrCZSPZ[nCZSPZCount].p2 - 1;
				}

				//usrCZSPZ[nCZSPZCount].p1 = 0;
			}
			else if (i < nCJDCount)
			{   //当前中枢或盘整延伸  不能延伸，否则导致最新的中枢或盘整错误20170319
				//usrCZSPZ[nCZSPZCount-1].p2 = i;

				//记录低波动率区间
				if (usrLowVarChannel.p1 == 0)
					usrLowVarChannel.p1 = i;
				else
					usrLowVarChannel.p2 = i;

				i++;
			}
		}
	}


	//计算缠笔,同时上涨计算上涨线段和下跌线段，完成1+1终结计算
	void CaclCPen(int DataLen, float* pfOUT, float* pfPlace, float* pfDATE, float* pfVOL)
	{
		int	i = 1, p1, p2;

		//计算缠笔数据首项
		i = 0;
		p1 = usrCJD[i].nPlace;
		p2 = usrCJD[i + 1].nPlace;
		if (usrCJD[i].nStatus >0)
			usrCJD[i].fLineLen = pNowKData[p2].fHigh - pNowKData[p1].fLow;
		else
			usrCJD[i].fLineLen = -pNowKData[p2].fLow + pNowKData[p1].fHigh;

		//计算缠笔数据  
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
	极点nCJDIndex-1和nCJDIndex组成的笔与中枢nCZSIndex关系：
	高于：返回1
	有交集：返回0
	低于：返回-1
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

			//缠对中枢的标准定义
			/*gg=usrCZSPZ[nCZSIndex].fMinHigh ;
			dd=usrCZSPZ[nCZSIndex].fMaxLow ;*/
			//简化型的走势中枢分析  0928
			gg = usrCZSPZ[nCZSIndex].fHigh;
			dd = usrCZSPZ[nCZSIndex].fLow;

			if (fHigh - gg >= 0.0 && fLow - dd <= 0.0) //笔穿透中枢
				out = 0;
			else if (fHigh - gg <0.0 && fLow - dd >0.0) //笔在中枢内
				out = 0;
			else if ((fLow - dd >= 0.0 && fLow - gg <= 0.0) //笔跨在中枢下沿
				|| (fHigh - dd >= 0.0 && fLow - gg <= 0.0)) //笔跨在中枢上沿
				out = 0;
			else if (fLow - gg >0.0 && fLow - fHigh <0.0) //笔在中枢上
				out = 1;
			else if (fHigh - dd <0.0 && fLow - fHigh <0.0) //笔在中枢下沿
				out = -1;
		}
		return out;
	}


	//-========================================改进后的缠极点、中枢、盘整分析
	//计算K线图中的缠笔画极点  顶底分型判断，参照定义进行
	/*
	顶分型是不含包含关系的三根K线，中间一根高点最高  ，低点也最高。
	顶分型是上涨过程中将出现转折的信号。一只上升的股票，如果连顶分型都没有出现，就不应该急于卖出。
	一般跌破5周期均线就可确立顶分型的确立。

	底分型是不含包含关系的三根K线，中间一根低点最低 ，高点也最低。
	底分型是下跌过程将出现转折的信号。一只下跌过程中的股票，如果连底分型都没有出现，就不应当急于买入。
	*/

	void CaclCJD(int DataLen, float* pfOUT, float* pfPlace, float* pfDATE, float* pfVOL)
	{
		int p1 = 0, p2 = 0, p3 = 0;//记录位置
		float h1, h2, h3, l1, l2, l3;//从左到右的三个连续高低位

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
			iChangeed = 2;//2 分型无效，0分型有效，1 处理过包含关系

						  //前后包含关系处理
						  //在上升趋势中，把两K 线的最高点当高点，而两K线低点中的较高者当成低点，这样就把两K线合并成一新的K线 （简称GG)。
						  //在下降趋势中，把两K 线的最低点当低点，而两K高点中的较低者当成高点，这样就把两K线合并成一新的K线（简称DD)。

			while (h1 >= h2 && l1 <= l2)  //1-2前包后,丢l2
			{
				l2 = l3, h2 = h3;
				p2 = p3, p3 = i++;
				l3 = pNowKData[p3].fLow;
				h3 = pNowKData[p3].fHigh;
				iChangeed = 1;
				if (i>DataLen - 1) break;
			}

			while (h1 <= h2 && l1 >= l2 && p1>2) //1-2后包前,丢l1 p3p2不动 p1前移
			{
				p1--;
				l1 = pNowKData[p1].fLow, h1 = pNowKData[p1].fHigh;
			}

			while (h2 >= h3 && l2 <= l3)  //2-3前包后,丢l3
			{
				p3 = i++;
				l3 = pNowKData[p3].fLow;
				h3 = pNowKData[p3].fHigh;
				iChangeed = 1;
				if (i>DataLen - 1) break;
			}

			//p1是跳后空低开后高走K线形态，包含了前面若干K线的后包前处理  典型的盘整后快速拉升形态  3包2特例
			while (h2 <= h3 && l2 >= l3 && p1>2) //2-3后包前,丢l2  3包2,3不动 p2p1向前移
			{
				h2 = h1, l2 = l1;
				p2 = p1--;
				l1 = pNowKData[p1].fLow;
				h1 = pNowKData[p1].fHigh;
			}

			//不大于-1时顶分型；不小于1是底分型
			int nFX = CaclCFX(p1, p2, p3);

			//顶分型判断  if(h2>h1 && h2>h3 && l2>l1 && l2>l3) 且收低于5周期均线
			if (nFX <= -1 && p3 + 1 <= DataLen)
			{   //暂不考虑跌破5日均线|| pNowKData[p3].fClose <pNowKData[p3].fMA5 
				//	|| pNowKData[p3+1].fClose <pNowKData[p3].fMA5
				if (1)
				{
					if (nCJDCount<2) //前两个分型（0、1）不判断有效性
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
						//连续顶分型不必记录，与前一底分型间隔最少4个周期才认为顶分型成立
						if (usrCJD[nCJDCount - 1].nStatus >= 1)
						{
							//if(h2-pNowKData[usrCJD[nCJDCount-1].nPlace].fHigh >0)   //顶必须高于前底
							{    //TODO  相对p3？ 20170301
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
									//底靠顶得很近处理  若新顶高于前顶，放弃最近一底，前顶更新为本顶
									//还要判断，被放弃的低分型是否比前一低分型更低，
									//若是，将前一底分型移到拟被放弃的底分型20160929
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
											//新顶替代前一顶
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
							&& pNowKData[usrCJD[nCJDCount - 1].nPlace].fHigh - h2<0)  //新顶分型更高)
						{
							//连续出现顶分型，更新位置 
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
			//---------------------底分型判断  if(h2<h1 && h2<h3 && l2<l1 && l2<l3) 
			else if (nFX >= 1 && p3 + 1 <= DataLen)
			{
				if (nCJDCount<2) //0和1分型不判断有效性
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
					//连续底分型不必记录，与前一顶分型间隔最少4个周期才认为顶分型成立
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
							//顶底靠底得很近处理  若新顶高于前顶，放弃最近一底，前顶更新为本顶  todo 20160801
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
						&& pNowKData[usrCJD[nCJDCount - 1].nPlace].fLow - l2>0)  //新底分型更低
					{
						//连续出现底分型，更新位置
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

			if (iChangeed == 2)  //如果不是有效分型，直接往移至下一个周期
			{
				l1 = l2, l2 = l3, h1 = h2, h2 = h3;
				p1 = p2, p2 = p3, p3 = i;
				l3 = pNowKData[p3].fLow;
				h3 = pNowKData[p3].fHigh;
			}
			else if (iChangeed == 0)
				//有效分型后的处理 确保连续两个分型之间没有公共的K线
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
				while (h1 >= h2 && l1 <= l2)  //1-2前包后,丢l2
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
			usrCJD[i].bIsUp = false;//初始化线段为缺省下跌状态
		}
		//当前极点创新高新低判断
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

		if (h2>h1 && h2>h3 && l2>l1 && l2>l3)  //顶分型  h2、l2最高 
		{
			out = -3;
			/*第三根K线如果跌破第一根K线的底部，且收盘不能收到第
			一根K线区间一半之上，属于最强的顶分型，具有较强的杀伤力*/
			if (l3<l1 && c3<l1 + (h1 - l1) / 2)
				out = -1;

			/*如果第二根K线是长上影甚至就是直接的长阴，而第三根K线不能以阳
			线收在第二根K线区间一半之上，那么该分型的力度就比较大
			长阴通常实体部分指大于7%，长上影指上影线幅度大于5%。*/
			if (c2<o2 && (((o2 - c2) / c1)>0.07 || ((h2 - o2) / c1)>0.05))
				out = -2;
		}
		else if (l2<l1 && l2<l3 && h2<h1 && h2<h3) //底分型  h2、l2最低
		{
			out = 3;
			/*第三根K线如果升破第一根K线的顶部，且收盘收到第
			一根K线区间一半之上，属于最强的底分型，具有较强的上升力*/
			if (h3>h1 && c3>l1 + (h1 - l1) / 2)
				out = 1;

			/*如果第二根K线是长下影甚至就是直接的长阳，而第三根K线以阳
			线收在第二根K线区间一半之上，那么该分型的力度就比较大
			长阳通常实体部分指大于7%，长下影指下影线幅度大于5%。*/
			if (c2>o2 && (((c2 - o2) / c1)>0.07 || ((o2 - l2) / c1)>0.05))
				out = 2;
		}

		return out;

	}

	//检测连续创新低时是否包含中枢，如果有则返回true
	bool CheckZSInPZ(int i)
	{
		CZSPZInfo usrZSPZ;
		int n;
		float f;
		bool bRet = false;
		//暂存当前盘整信息
		memcpy(&usrZSPZ, &usrCZSPZ[nCZSPZCount], sizeof(CZSPZInfo));

		bRet = CaclCZS(i, &n, &f);
		//恢复当前盘整信息
		memcpy(&usrCZSPZ[nCZSPZCount], &usrZSPZ, sizeof(CZSPZInfo));

		return  bRet;
	}

	//计算盘整  NewHighLow=1 nCJDIndex+2缠创新高
	//					 =-1 nCJDIndex+2缠创新低
	//          fData    创新高或新低时的数据      
	bool	CaclCPZ(int	nCJDIndex, int *NewHighLow, float *fData)
	{
		int		i = nCJDIndex;
		bool	bNewPZ = false;
		*NewHighLow = 0;
		*fData = 0;
		float	h1, l1;

		//2 判断盘整，用连续两个笔比进行判断
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

					//连续创新高盘整
					usrCZSPZ[nCZSPZCount].p1 = i - 1;
					while (nCJDCount - i >= 2)
					{
						//检测连续创新低时是否包含中枢，如果有则退出循环，本盘整结束
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
					//连续创新低盘整
					usrCZSPZ[nCZSPZCount].p1 = i - 1;
					while (nCJDCount - i >= 2)
					{
						//检测连续创新低时是否包含中枢，如果有则退出循环，本盘整结束
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

	//计算中枢  NewHighLow=1 nCJDIndex+2缠创新高
	//					 =-1 nCJDIndex+2缠创新低
	//          fData  新高或新低数据
	//todo  20160730 中枢内创新高、新低处理？？  出中枢创新高  升中枢，反之跌中枢
	//中枢内既不创新高也不创新低则按整体走势判中枢方向
	bool	CaclCZS(int	nCJDIndex, int *NewHighLow, float *fData)
	{
		//中枢波动范围
#define  ZSVARRATE 10 
		int	iLineCount = 0;
		int	i = nCJDIndex;
		float h1, l1, fFirstPenHigh, hMax = 0.0, lMin = 99999.0;
		bool bNewZS = false;

		*NewHighLow = 0;

		//1 中枢判断，用4个连续的笔比进行判断
		if (nCJDCount - i>3)
		{
			//连续2笔长度接近，中枢成立
			/*if (usrCJD[i + 1].nLineBi >= 3 && usrCJD[i + 1].nLineBi <= 44
			&& usrCJD[i + 2].nLineBi >= 3 && usrCJD[i + 2].nLineBi <= 44 )*/
			{
				int nZSPercent;
				if (usrCJD[i].nStatus <0)// 顶分型 上涨中枢
				{

					//中枢公共价格部分
					h1 = min(pNowKData[usrCJD[i].nPlace].fHigh,
						pNowKData[usrCJD[i + 2].nPlace].fHigh);
					l1 = max(pNowKData[usrCJD[i + 1].nPlace].fLow,
						pNowKData[usrCJD[i + 3].nPlace].fLow);

					//中枢高低价位
					hMax = max(max(hMax, pNowKData[usrCJD[i].nPlace].fHigh),
						pNowKData[usrCJD[i + 2].nPlace].fHigh);
					lMin = min(min(lMin, pNowKData[usrCJD[i + 1].nPlace].fLow),
						pNowKData[usrCJD[i + 3].nPlace].fLow);

					*NewHighLow = 1;
					*fData = hMax;

					fFirstPenHigh = pNowKData[usrCJD[i].nPlace].fHigh
						- pNowKData[usrCJD[i + 1].nPlace].fLow;
				}
				else //底分型  下跌中枢
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

				//h1 - l1>0.0中枢有效,中枢波动很大时作为盘整处理
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

					//中枢延伸处理:连续两笔在中枢内前一笔和当前笔
					while ((PenInCZS(i, nCZSPZCount) == 0 && PenInCZS(i + 1, nCZSPZCount) == 0)
						&& nCJDCount - i >= 1)
					{
						bool  bNewLow = false, bNewHigh = false;

						if (usrCJD[i].nStatus >0)
						{
							//底分型处理，判是否出现新低
							hMax = max(hMax, pNowKData[usrCJD[i - 1].nPlace].fHigh);
							lMin = min(lMin, pNowKData[usrCJD[i].nPlace].fLow);

							bNewLow = (lMin - pNowKData[usrCJD[i].nPlace].fLow == 0.0) //当前极点创新低
								&& (lMin - usrCZSPZ[nCZSPZCount - 1].fLow<0.0)  //当前相对前一中枢盘整创新低
								&& (pNowKData[usrCJD[i + 2].nPlace].fLow - lMin>0.0);  //下一低分型未创新低

							if (bNewLow == true)
							{
								*NewHighLow = -1;
								*fData = lMin;
							}
						}
						else
						{
							//顶分型处理，判是否出现新高
							hMax = max(hMax, pNowKData[usrCJD[i].nPlace].fHigh);
							lMin = min(lMin, pNowKData[usrCJD[i - 1].nPlace].fLow);

							bNewHigh = (hMax - pNowKData[usrCJD[i].nPlace].fHigh == 0) //当前极点创新高
								&& (usrCZSPZ[nCZSPZCount - 1].fHigh - hMax<0.0)   //当前相对前一中枢盘整创新高
								&& (pNowKData[usrCJD[i + 2].nPlace].fHigh - hMax<0.0); //下一顶分型未创新高

							if (bNewHigh == true)
							{
								*NewHighLow = 1;
								*fData = hMax;
							}
						}
						usrCZSPZ[nCZSPZCount].fHigh = hMax;
						usrCZSPZ[nCZSPZCount].fLow = lMin;

						//中枢内出现新高或新低时退出计算，保留当前有效中枢
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

	//基于中枢与盘整计算背驰  通过调用  pfType 1 一买分析,2 二买分析；  -1一卖分析 -2 二卖分析 
	//       pfMode	   1=MACD 2=DIF 3=DEA
	void CaclBSPoint(int DataLen, float* pfOUT, float* pfMode, float* pfType, float* pfMACD)
	{
		int	nType = (int)pfType[0];

		/*
		当前缠极点有效性判断
		有效的底分型
		1、创新低的底分型产生后5周期内升破5周期均线才用操作价值
		2、创新低的底分型产生后，另外生成新的底分型但未创新低、中间没有顶分型，
		底分型延伸后5周期内升破5周期均线才用操作价值
		3、创新低的底分型产生后形成一个波动率很小的中枢，中枢的最后一个底分型
		5周期内升破5周期均线

		有效的顶分型
		1、创新高的顶分型产生后5周期内跌破5周期均线才用操作价值
		2、创新高的顶分型产生后，另外生成新的顶分型但未创新高、中间没有底分型，
		顶分型延伸后5周期内跌破5周期均线才用操作价值
		3、创新高的顶分型产生后形成一个波动率很小的中枢，中枢的最后一个顶分型
		5周期内跌破5周期均线
		*/

		//卖点分析
		if (usrCJD[nCJDCount - 1].nStatus < 0 //顶分型后下跌
			&& pNowKData[usrCJD[nCJDCount - 1].nPlace].fHigh>pNowKData[DataLen - 1].fHigh)
		{
			//20170319加严判断：当前K线最高价低于顶分型高值，处于下跌趋势
			//创新高的顶分型生成时更新止损价位，新高顶分型最高价视同新买入价，跌幅达到一定程度时做止损
			if (usrCJD[nCJDCount - 1].nP3 == DataLen - 1 && usrCJD[nCJDCount - 1].nNewHighLow < 0)
				this->fAutoDownSellPrice = pNowKData[usrCJD[nCJDCount - 1].nPlace].fHigh
				*(1.0 - (float)AUTODOWNSELLGATE / 100);

			//顶分型后跌破短周期均线时进行卖出分析时进行处理
			if (pNowKData[DataLen - 1].fClose - this->fMAShort[DataLen - 1] < 0.0
				&& nType < 0) //顶分型仅适用于卖点分析，不适用买点分析  后续分析是否顶背驰
			{
				CheckSellSignal(DataLen, pfMode, pfType, pfMACD);
			}
		}

		//买点分析
		if (    nType > 0
			&&  usrCJD[nCJDCount - 1].nStatus > 0  //底分型
			|| (usrCJD[nCJDCount - 1].nStatus < 0  //顶分型后的上涨
				&& pNowKData[usrCJD[nCJDCount - 1].nPlace].fHigh<pNowKData[DataLen - 1].fHigh))
			//20170319加严判断：当前K线最高价高于顶分型高值，处于上涨趋势
		{
			//底分型必须升破短周期均线:加严，长短中均线都要升破
			CheckBuySignal(DataLen, pfMode, pfType, pfMACD);
		}
	}


	//基于中枢与盘整计算买入信号  通过调用  pfType 1 一买分析,2 二买分析；  -1一卖分析 -2 二卖分析 
	//       pfMode	   1=MACD 2=DIF 3=DEA
	//       待优化买点算法，要判断背驰情况、冲破前期高点情况等  20170403
	void CheckBuySignal(int DataLen, float* pfMode, float* pfType, float* pfMACD)
	{
		int	nLastestZSPZ;
		int	nMode = (int)pfMode[0], nType = (int)pfType[0];
		int	nDelta = 3, nStart;
		int	nDown;

		/*
		底背驰分析	 买点分析
		1)	从分析周期内的最高点顶分型开始分析下跌的盘整与中枢；
		2)	遍历不断创新低的中枢与盘整，期间出现一中枢与盘整高点升高仍认为处于上跌趋势；
		从第二次创新低开始判断是否出现背驰，若出现即标记之；
		3)  目前最新缠极点终止于当前分析周期K线处，且必须是底分型
		*/
		if (nType >= 1 && nCZSPZCount >= 4  //中枢盘整至少要有3个才进行分析
			/*&& this->VolMAUp( DataLen,MALONG,3)==true*/)  //成交量持续放大
		{
			nLastestZSPZ = nCZSPZCount - 1;
			
			//基于缠论下跌阶段找买点
			//在下跌周期寻找潜在买入点

			//计算分析周期内最大值以来的跌幅
			nDown = 100 - 100 * pNowKData[usrCJD[usrCZSPZ[nLastestZSPZ].p2].nPlace].fClose
				/ this->fMaxHigh;

			//计算分析周期内最大值之后的CJD峰谷
			this->CaclCJDTBPoint(pfMACD, DataLen);
			// 计算分析周期内量能峰谷
			this->CaclEnergyTopBtn(pfMACD, DataLen);
				
			int nBC= this->BtnBC(usrCZSPZ[nLastestZSPZ].p2);
			//int nBC = this->BtnBC(nCJDCount-1);
			if( ( nBC> 1 && nType==1 )   //一买：超过2次创新低底背驰    
										 //2买：至少1次底背驰
				|| (nBC>1 && nType>1) )
			{
				this->bBSChanged = true;

				//记录最新买入的YMD
				nLatesBuyYmd = pNowKData[DataLen - 1].nYmd;
				if(nType>1)
					AddBuy(DataLen - 1, DataLen - 1, BSTYPE_2BUY, nMode, nDown);
				else
					AddBuy(DataLen - 1, DataLen - 1,BSTYPE_ZSBC, nMode, nDown);
			}
			else 
			{
				//判断创阶段新高的时机  对利润贡献很大
				if (CheckStepUp(DataLen) == true)
					this->AddBuy(DataLen - 1, DataLen - 1,
						BSTYPE_STEPUP, nMode, nDown);
			}
			return;
		}//if (nType >= 1 && nCZSPZCount >= 4
	}

	//检测突破阶段新高是否成立
	/*突破阶段新高买入条件
		1）长中短均线均上升；
		2）分析周期内最高点后的低点且出现超过15%(MAXSTEPDOWN)的跌幅；
		3）未出现顶背驰；
		4）分析周期内最高点与最新的缠极点间有6个以上极点；
		5）当前K线收阳线且高于短均线；
		6）可能会有多次突破阶段新高。*/
	bool CheckStepUp(int nDataLen)
	{
		bool  bRet = false;

		if (    fCurClose>fMAShort[nDataLen-1]   //当前K线收阳线且高于短均线
			 && MAUp(nDataLen - 1, fMALong, 3) 
			 && MAUp(nDataLen - 1, fMAMid, 3) 
			 && MAUp(nDataLen - 1, fMAShort, 3)
			 && nMaxHigh>nMinLow                 //分析周期内最高在最低后
			 && this->TopBC(nCJDCount - 1) <= 0) //没有出现顶背驰
		{
			//指向分析周期内最高点,同时分析最低点后的顶分型是否被升破
			int nMaxCJD = nCJDCount - 1;
			int nLastGate= max(nMinLow, nMaxHigh); //离当前K线最近的最低点 / 最高点位置
			float fLastHigh = 0;
			if ( usrCJD[nMaxCJD].nStatus>0)   nMaxCJD--;
			for (; nMaxCJD>0 && usrCJD[nMaxCJD].nPlace > nMaxHigh; nMaxCJD -= 2)
			{
				//分析最低点/最高点后的顶分型是否被升破
				if (usrCJD[nMaxCJD].nPlace >nLastGate)
				{
					if (fLastHigh > pNowKData[usrCJD[nMaxCJD].nPlace].fHigh) continue;

					fLastHigh = pNowKData[usrCJD[nMaxCJD].nPlace].fHigh;

					if (fCurClose > fLastHigh && pNowKData[nDataLen - 1].fOpen<fLastHigh)
					{
						//阳线升破顶分型
						bRet = true;
						return bRet;
					}
				}
			}

			if (nMaxCJD > 0 && nCJDCount- nMaxCJD>6)
				nMaxCJD += 2;
			else
				return bRet;

			//从前期高点起分析阶段性的缠极点底点，分析跌幅是否达到15%
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
				//分析最高点最低点间的顶分型是否被当前K线升破
				//阳线升破顶分型才认为是有效升破
				for (int k= nMinCJD - 1; usrCJD[k].nPlace>nMaxHigh; k-=2)
				{
					if (fLastHigh > pNowKData[usrCJD[k].nPlace].fHigh) continue;

					fLastHigh = pNowKData[usrCJD[k].nPlace].fHigh;

					if (fCurClose <= fLastHigh)
						break;
					else if(fCurClose > fLastHigh && pNowKData[nDataLen-1].fOpen<fLastHigh)
					{
						//阳线升破顶分型
						bRet = true;
						break;
					}
				}
			}
		}
		
		return bRet;

	}
	//基于中枢与盘整计算卖出  通过调用  pfType 1 一买分析,2 二买分析；  -1一卖分析 -2 二卖分析 
	//       pfMode	   1=MACD 2=DIF 3=DEA
	void CheckSellSignal(int DataLen, float* pfMode, float* pfType, float* pfMACD)
	{
		int	nMode = (int)pfMode[0], nType = (int)pfType[0];
		int	nDown;

		/*	卖点分析
		顶背驰分析
		1)	从上涨中枢与盘整开始分析。
		2)	遍历不断创新高的中枢与盘整，期间出现一中枢与盘整高点降低仍认为处于上涨趋势；从第二次创新高开始判断是否出现背驰，若出现即标记之。
		*/

		//创新高后出现5%以上的跌幅必须卖出   ：几个周期内？表明创新高后站不稳  TODO 20170223
		if ((nType <= -1))
		{
			//买入后的平均涨幅
			if (this->fAveragePrice == 0.0)
				//自选持仓或指数
				nDown = 100;
			else
				nDown = -100 + 100 * pNowKData[usrCJD[nCJDCount - 1].nPlace].fClose
				/ this->fAveragePrice;

			//在上涨周期寻找潜在卖出点，将来考虑做空点
			//不处理第一次出现的上涨中枢或盘整
			this->CaclCJDTBPoint(pfMACD, DataLen);
			this->CaclEnergyTopBtn(pfMACD, DataLen);
			//出现两次以上顶背驰时做减仓操作
			if (this->TopBC(nCJDCount - 1)>=2)
			{
				//上升阶段不应该卖  20170314
				this->bBSChanged = true;
				this->AddSell(DataLen - 1, DataLen - 1,
					-BSTYPE_ZSBC, nMode, nDown);
			}

			if (this->MADown(DataLen) == true)
			{
				//长中短均线均下跌表明下跌趋势很明显，必须立即清仓
				this->bBSChanged = true;
				this->AddSell(DataLen - 1, DataLen - 1,
					-BSTYPE_JXDOWN, nMode, nDown);
			}
		}
	}

	//检测目前是否存在卖点
	//长中短均线全跌且最近买入点后的最大跌幅达到止损比例
	bool DetectSellSignal(int DataLen)
	{
		bool bRet = false;

		if (100 - 100 * fCurClose / fMaxHigh>AUTODOWNSELLGATE)
		{
			bRet = MADown(DataLen);
		}

		return bRet;

	}

	//设置分析周期内已转换数据的第nCount+1个高最低价格，最多5组
	/*
	 在波段走势中，突破前期高低点往往意味着产生新的下跌或上涨趋势。图中红线代表近期高点，绿线代表近期低点。
		1）上涨趋势：突破前期高点且长中短均线均升
		2）下跌趋势：突破前期低点且长中短均线均跌
		3）观望趋势：短升中断跌可能继续跌，短跌中断升可能继续升  
		4) 趋势反转：无法判断趋势反转。此算法暂时不用，用基于缠极点的峰谷进行近期高低点判断
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

		//在下跌趋势时没有最高值排序，上涨趋势没有最低值排序
		for ( i = 1; i<nDataLen; i++)
		{
			//最高值  
			//对High数据进行High和Index同时进行升序排序
			if (m_usrLastestHigh[k].fValue < pNowKData[i].fHigh )
			{
				nCount = k* sizeof(TBPoint);
				_memccpy(m_usrLastestHigh , m_usrLastestHigh +1 ,nCount,nCount );
				m_usrLastestHigh[k].fValue = pNowKData[i].fHigh;
				m_usrLastestHigh[k].nIndex = i;
						
			}
				
			//最低值
			//对Low数据进行降序排序
			if (m_usrLastestLow[k].fValue - pNowKData[i].fLow > 0)
			{
				nCount = (k) * sizeof(TBPoint);
				_memccpy(m_usrLastestLow , m_usrLastestLow +1 , nCount, nCount);
				m_usrLastestLow[k].fValue = pNowKData[i].fLow;
				m_usrLastestLow[k].nIndex = i;
			}
			
		}
	}
	
	//设置分析周期内已转换数据的最高最低价格
	void	SetMaxHighMinLow(int	nDataLen)
	{
		int	i = 0, k;
		int	nMaxHigh = 0, nMinLow = 0;
		float fMaxHigh = -1, fMinLow = 999999;

		for (; i<nDataLen; i++)
		{
			//计算最近一次买入以来的最大值  用于判断自动卖出的时机
			if (fMaxHigh - pNowKData[i].fHigh <0)
			{
				if (pNowKData[i].nYmd >nLatesBuyYmd)
				{
					fMaxHigh = pNowKData[i].fHigh;
					nMaxHigh = i;
				}
			}

			//计算分析周期内的最小值  用于分析1买时机
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

	//涨停判断  TODO 加上ST类股票的判断20170311
	bool   UpStop(int nDataLen, StockInfo *ptr5MinKInfo)
	{
		if (fLastDateClose > 0)
			return  (ptr5MinKInfo + nDataLen - 1)->fClose / fLastDateClose  > 1.09;
		else
			return false;
	}

	//跌停  TODO 加上ST类股票的判断20170311
	bool   DownStop(int nDataLen, StockInfo *ptr5MinKInfo)
	{
		if (fLastDateClose > 0)
			return  (ptr5MinKInfo + nDataLen - 1)->fClose / fLastDateClose < 0.91;
		else
			return false;
	}

	//设置前一日日线收盘价，用于判断涨停或跌停
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


	//判断是否连续nCount周期冲破前期高点且其收盘价持续升高
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

	//判断指定周期内最近5分钟K线数据是否连续递增成交量是否连续增加

	bool	VOLUp5Min(int nDataLen, int nCount)
	{
		bool bRet = true;

		if (nCount <= 0)
			return false;

		//仅计算最近的成交量
		int j = max(g_nStockDownDays*48 - nCount - 2, 0);

		do
		{
			bRet = (p5MinKData[j + 1].nNumber >= p5MinKData[j].nNumber);
		} while (j++ < nDataLen - 2 && bRet == true);

		return bRet;
	}

	//当前分析周期内成交量是否连续增加
	bool	VOLUp(int nDataLen, int nCount)
	{
		bool bRet = true;

		if (nCount <= 0)
			return false;

		//仅计算最近的成交量
		int j = max(nDataLen - nCount - 2, 0);

		do
		{
			bRet = (pNowKData[ j + 1].nNumber >= pNowKData [j].nNumber );
		} while (j++ < nDataLen - 2 && bRet == true);

		return bRet;
	}

	//判断指定均线是否处于连续nCount周期上升
	bool	MAUp(int nDataLen, float *pMa, int nCount)
	{
		bool bRet = true;

		if (nCount <= 0)
			return false;

		//仅计算最近的均值，太远的均值无益于买卖点分析
		int j = max(nDataLen - nCount , 0);

		do
		{
			bRet = (*(pMa + j + 1) >= *(pMa + j));
		} while (j++ < nDataLen-1  && bRet == true);

		return bRet;
	}

	//判断指定均线是否处于连续nCount周期跌
	bool	MADown(int nDataLen, float *pMa, int nCount)
	{
		bool bRet = true;

		if (nCount <= 0)
			return false;

		//仅计算最近的均值，太远的均值无益于买卖点分析
		int j = max(nDataLen - nCount - 2, 0);

		do
		{
			bRet = (*(pMa + j + 1) < *(pMa + j));
		} while (j++ < nDataLen - 2 && bRet == true);

		return bRet;
	}

	//成交量均值是否递增 最近的nCount周期内成交量长中短均值是否均上升 
	bool	VolMAUp(int nDataLen, int nLong, int nCount)
	{
		bool bRet = true;

		if (nDataLen < nLong || nLong <= 0 || nCount <= 0)
			return false;

		//仅计算最近的均值，太远的均值无益于买卖点分析
		int j = max(nDataLen - nLong * 2 - nCount - 1, 0);

		do
		{
			bRet = (*(nVolMaLong + j + 1) > *(nVolMaLong + j))
				&& (*(nVolMid + j + 1) > *(nVolMid + j))
				&& (*(nVolShort + j + 1) > *(nVolShort + j));
		} while (j++ < nDataLen - nLong && bRet == true);

		return bRet;
	}


	//成交量均值是否递减 最近的nCount周期内成交量长中短均值是否均递减 
	bool	VolMADown(int nDataLen, int nLong, int nCount)
	{
		bool bRet = true;

		if (nDataLen < nLong || nLong <= 0 || nCount <= 0)
			return false;

		//仅计算最近的均值，太远的均值无益于买卖点分析
		int j = max(nDataLen - nLong - nCount - 1, 0);

		do
		{
			bRet = (*(nVolMaLong + j + 1) < *(nVolMaLong + j))
				&& (*(nVolMid + j + 1) < *(nVolMid + j))
				&& (*(nVolShort + j + 1) < *(nVolShort + j));
		} while (j++ < nDataLen - nLong && bRet == true);

		return bRet;
	}


	//计算分析周期内的量能峰值谷值
	//峰值从大到小，谷值从小到大
	//基于缠极点进行计算
	void	CaclEnergyTopBtn(float *pfMACD, int  nDataLen)
	{
		int k;

		for (k = 0; k < TBPOINTCOUNT; k++)
		{
			mMaxEnergy[k].fEnergy = -99999, mMaxEnergy[k].fValue = -99999, mMaxEnergy[k].nIndex = -1;
			mMinEnergy[k].fEnergy = 99999, mMinEnergy[k].fValue = 99999, mMinEnergy[k].nIndex = -1;
		}

		int		i = nCJDCount - 1;

		//二买三买或卖出分析：量能高低点均需要
		if (   nLatesBuyYmd <= nCurYmd && nLatesBuyYmd>0 ) //买入后
		{
			//指向最近买入日期后的第一个缠极点，记录上冲或下跌量能情况
			//上冲阶段，如果未出现顶背驰，具备买入条件；下跌阶段，出现底背驰具备买入条件
			while (pNowKData[usrCJD[i].nP1].nYmd > nLatesBuyYmd && i>0)
				i--; // 二买三买或卖出分析

			i++;
			CaclUpEnergy(i, pfMACD);
			CaclDownEnergy(i, pfMACD);
		}
		else if (nLatesBuyYmd == 0 && nMinLow < nMaxHigh) //新低后创新高
		{
			//指向新低后的第一个缠极点，记录上冲量能变化，同时分析新低前的下跌量能
			//上冲阶段，如果未出现顶背驰，具备买入条件；下跌阶段，出现底背驰具备买入条件
			while (usrCJD[i].nP1>nMaxHigh	&& i>0)	i--; // 二买三买

			i++;
			CaclDownEnergy(i, pfMACD);
			CaclUpEnergy(i, pfMACD);
		}
		//一买分析：仅需要量能低点
		else if (nLatesBuyYmd == 0 && nMinLow > nMaxHigh)
		{
			int nStart = 0;//分析起点
			float fHigh = -999999.0;

			//低点在高点后，创新低情况
			//上冲阶段，如果未出现顶背驰，具备买入条件；下跌阶段，出现底背驰具备买入条件
			//指向分析周期内最高点日期后首个缠极点，后续记录其下跌量能变化
			while (usrCJD[i].nP1> nMaxHigh && i > 0) i--;

			i++;
			CaclDownEnergy(i, pfMACD);

			//指向分析周期内最低点日期后首个缠极点，后续记录其上升量能变化
			i = nCJDCount - 1;
			while (usrCJD[i].nP1> nMinLow && i > 0) i--;
			i++;
			CaclUpEnergy(i, pfMACD);
		}

	}

	//计算缠极点下跌量能并存在mMinEnergy，数据升序排序
	void  CaclDownEnergy(int nStartCJD, float *pfMACD )
	{
		//潜在二买、三买分析，卖出分析
		int i= nStartCJD;
		TBPoint  usrMin;

		//保存分析周期内最大值以来Low最小的5个底分型:一买分析  
		//必须从顶分型开始
		while (usrCJD[i].nStatus > 0 && i<nCJDCount - 1) i++;

		for (; i<nCJDCount - 1; i+=2)
		{
			usrMin.fEnergy = 999999;
			//取两个极点间的最小值  从顶分型结束处开始到底分型结束
			for (int j = usrCJD[i].nP3 + 1; j<usrCJD[i + 1].nP3; j++)
				if (usrMin.fEnergy - pfMACD[j] > 0.0)
				{
					usrMin.fValue = pNowKData[j].fLow;
					usrMin.nIndex = i;
					usrMin.nDate= (pNowKData[usrCJD[i].nPlace].nYmd % 2048)*100
						+(pNowKData[usrCJD[i].nPlace].nMin / 60);
					usrMin.fEnergy = pfMACD[j];
				}

			//从小到大排序数据
			for (int k = 0; k < TBPOINTCOUNT; k++)
				if (    usrMin.fEnergy < mMinEnergy[k].fEnergy )
				{
					// 仅保留最小值后出现的数据
					if (k<TBPOINTCOUNT - 1)
						memcpy(&mMinEnergy[k + 1], &mMinEnergy[k], (TBPOINTCOUNT - k - 1) * sizeof(TBPoint));

					memcpy(&mMinEnergy[k], &usrMin, sizeof(TBPoint));

					break;
				}
		}
	}

	//计算缠极点上冲量能并存在mMaxEnergy，数据降序排序
	void  CaclUpEnergy(int nStartCJD, float *pfMACD )
	{
		//潜在二买、三买分析，卖出分析
		int i = nStartCJD;
		TBPoint  usrMax;

		//保存High最大的5个顶分型
		
		// 二买三买或卖出分析时需要用到顶分型  记录High值
		//必须从底分型开始
		while (usrCJD[i].nStatus < 0 && i<nCJDCount - 1) i++;

		for (; i<nCJDCount - 1; i+=2)
		{
			usrMax.fEnergy = -999999;
			//取两个极点间的最大值
			for (int j = usrCJD[i].nP3 + 1; j<usrCJD[i + 1].nP3 + 1; j++)
				if (usrMax.fEnergy - pfMACD[j] < 0.0)
				{
					usrMax.fValue = pNowKData[j].fHigh;
					usrMax.nIndex = i;
					usrMax.nDate = (pNowKData[j].nYmd%2048)*100
						+ (pNowKData[j].nMin / 60);
					usrMax.fEnergy = pfMACD[j];
				}

			//从大到小进行数据排序
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

	//计算缠极点创新高新低时的量能峰值  
	//按最高最低价价格最大 、最小的TBPOINTCOUNT个，分别存在mTop和mBotton
	//mTop从大到小，mBotton从小到大
	//pfMACD 可能是DIFF DEA MACD
	//TODO 20170303可扩充中枢盘整的上涨价格变化量累计值，DIFF DEA MACD在中枢盘整周期内累计值
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
		当前标的不在持仓范围内，分析潜在的123买。
		*/

		int nStart = 0;//123买分析起点
		float fHigh = -999999.0;
		int  nLowestCJD=i;//新低处缠极点
		int  nHighestCJD = i;//新高处缠极点

		//指向包含最低位置的缠极点
		while (usrCJD[nLowestCJD].nPlace > nMinLow && nLowestCJD > 0) nLowestCJD--;
		//if (nLowestCJD == 0)  return; //最低点不是缠极点，不作处理

		//指向包含最高点的缠极点
		while (usrCJD[nHighestCJD].nPlace > nMaxHigh && nHighestCJD > 0) nHighestCJD--;
		//if (nHighestCJD == 0)  return; //最高点不是缠极点，不作处理
		

		if (nMinLow > nMaxHigh && nLowestCJD+1<=nCJDCount)
		{
			//1B
			i = nHighestCJD;
			CaclCJDBtn(pfMACD, i);
		}
		else if (nMinLow > nMaxHigh )
		{
			//未冲破前期高点，潜在2买3买分析或者卖出分析
			i = nLowestCJD;
			CaclCJDTop(pfMACD, i);  //卖出分析

			//指向新低后的新高
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

			CaclCJDBtn(pfMACD, nLastestHigh);  //2B3B分析

		}
		else
		{
			//冲破分析周期内高点：平台突破  BT分析  TODO 20170405
			//上涨中枢或盘整处理   均线向上、突破前期平台高点
			//短中长均线均向上且当前收盘价高于短中长均线才能构成买入点
			//需进一步加严判断  TODO  20170306
			i = nLowestCJD;
			CaclCJDTop(pfMACD, i);  //判断是否已出现顶背驰

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

	   //基于量能计算缠极点
	void  CaclCJDTop(float *pfMACD, int  nStartCJD)
	{
		//对最大值、最小值前几个排序,mTop[TBPOINTCOUNT]数字大的放在序号小的位置
		TBPoint  usrMax;
		//保存High最大的5个顶分型
		usrMax.fValue = -999999;
		int i = nStartCJD;
		if (usrCJD[i].nStatus> 0) i++;

	

		for (; i <= nCJDCount; i += 2)
		{   // 二买或卖出分析时需要用到顶分型
			//仅分析顶分型
			if (usrMax.fValue < pNowKData[usrCJD[i].nPlace].fHigh)
			{
				usrMax.fValue = pNowKData[usrCJD[i].nPlace].fHigh;
				usrMax.nIndex = i;
				usrMax.nDate = (pNowKData[usrCJD[i].nPlace].nYmd % 2048)*100
					+ (pNowKData[usrCJD[i].nPlace].nMin / 60);
				usrMax.fEnergy = pfMACD[usrCJD[i].nPlace];
				//从大到小进行数据排序
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
		//对最大值、最小值前几个排序,mTop[TBPOINTCOUNT]数字大的放在序号小的位置
		//mBotton[TBPOINTCOUNT]数字小的放在序号小的位置
		TBPoint  usrMin;
		//保存High最大的5个顶分型
		usrMin.fValue = 999999;
		int i = nStartCJD;

		if (usrCJD[i].nStatus < 0) i++;

		for (; i<=nCJDCount; i+=2)
		{   // 二买或卖出分析时需要用到顶分型
			//保存Low最小的5个底分型
			if (usrMin.fValue > pNowKData[usrCJD[i].nPlace].fLow)
			{
				usrMin.fValue = pNowKData[usrCJD[i].nPlace].fLow;
				usrMin.nIndex = i;
				usrMin.nDate = (pNowKData[usrCJD[i].nPlace].nYmd % 2048) * 100
					+ (pNowKData[usrCJD[i].nPlace].nMin / 60);
				usrMin.fEnergy = pfMACD[usrCJD[i].nPlace];
				//mBotton从小到大排序
				for (int k = 0; k < TBPOINTCOUNT; k++)
					if (usrMin.fValue < mBotton[k].fValue)
					{
						// 仅保留最小值后出现的数据
						if (k<TBPOINTCOUNT - 1)
							memcpy(&mBotton[k + 1], &mBotton[k],
							(TBPOINTCOUNT - k - 1) * sizeof(TBPoint));

						memcpy(&mBotton[k], &usrMin, sizeof(TBPoint));

						break;
					}
			}
		}
	}


	   //判断是否出现了长中短均线同时下跌的情况
	   //主要判据：长中短均线出现了3周期连续下跌
	   //          长中短开口：长>中>短，短中均线距离3周期连续扩大
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
			&& MADown(DataLen, fMAShort, 3)  //短均线下跌
			&& MADown(DataLen, fMAMid, 3)    //中均线下跌
			&& MADown(DataLen, fMALong, 3);  //长均线下跌
	}

	//综合缠极点顶分型和量能判断是否出现了顶背驰，返回出现顶背驰的次数，没有则返回-1
	int		TopBC(int nCJDIndex)
	{
		int nRet = -1;
		int i = 0;
		
		//对顶分型进行顶背驰分析
		if (nCJDIndex > 1 && usrCJD[nCJDIndex].nStatus >= 0)  nCJDIndex--;

		do
		{
			if (mTop[i].nIndex == nCJDIndex)
			{
				int j;
				//分析目前是否发生顶背驰
				for (j = 0; j<TBPOINTCOUNT; j++)
					if (mMaxEnergy[j].fEnergy - mTop[i].fEnergy <= 0.0)
					{
						//没有发生背驰，退出循环
						break;
					}

				nRet = j;

				break;
			}
			i++;
		} while (i <TBPOINTCOUNT && i>1 && mTop[i].nIndex>0);

		return nRet;
	}

	//综合缠极点底分型和量能判断是否出现了底背驰，返回出现底背驰的次数，没有则返回0
	int		BtnBC(int nCJDIndex)
	{
		int nRet = 0;
		int i = 0;

		//对底分型进行底背驰分析
		if (nCJDIndex > 1 && usrCJD[nCJDIndex].nStatus <= 0)  nCJDIndex--;

		do
		{
			if (mBotton[i].nIndex == nCJDIndex)
			{
				int j;
				for (j = 0; j<TBPOINTCOUNT; j++)
					if (mBotton[i].fEnergy - mMinEnergy[j].fEnergy <= 0)
					{
						//没有背驰，退出
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
		//nK   nDataLen是当前日买入点成立
		if (pNowKData[nK].nYmd <= pNowKData[nDataLen].nYmd)
		{
			int i = 0;
			while (usrBuy[i].nAmount >0 && i<BSCOUNT) i++;

			//仅当存在空余的买点记录当前买点才能生效
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
		//nK   nDataLen是同一天不同的K线位置时卖出点成立
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

				//按当前持仓量的50%比例减仓
				usrSell[i].nAmount = 50;
				usrSell[i].nK = nK;
				usrSell[i].nMode = nMode;
				usrSell[i].nType = type;
				usrSell[i].nWeek = g_nWeek;
				usrSell[i].nMustSellYMD = 0;
				usrSell[i].nDownPercent = usrBuy[0].nDownPercent;//一买处的跌幅
				usrSell[i].nMustSellYMD = 1;
				usrSell[i].fBuySellPrice = pNowKData[nK].fOpen;
				usrSell[i].nYmd = nCurYmd;
				usrSell[i].nMin = nCurMin;
				nSellIndex++;
			}
		}
		else
		{	//做空处理或者自定义持仓标的处理  将来扩充做空处理20170116
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

	//自动减仓处理
	void	AutoSell(int nDataLen)
	{
		int nCount = GetBuyIndex();
		if (nCount == 0) return;

		//检查是否到了止损、止盈价格
		//持仓至少一天才能卖
		//买入后3天内如果出现长中短均线均跌且跌幅大于止损幅度一半，自动卖出
		//nLatesBuyYmd  为何为0？   TODO 20170428
		if (nHoldingAmount>0 && nLatesBuyYmd<pNowKData[nDataLen - 1].nYmd)	 //持仓至少一天
		{
			if (fAutoDownSellPrice > pNowKData[nDataLen - 1].fClose)
				AddSell(nDataLen-1, nDataLen - 1, -BSTYPE_STOPDOWN, BSMODE_STOPDOWN, 0);
			else if (DetectSellSignal(nDataLen) == true)
			{
				AddSell(nDataLen-1, nDataLen - 1, -BSTYPE_JXDOWN, BSMODE_STOPDOWN, 0);
			}
			else
			{
				//买入后3天内如果出现长中短均线均跌且跌幅大于止损幅度一半，自动卖出)
				if (100 - 100 * fCurClose / fMaxHigh>AUTODOWNSELLGATE/2 
					&& MADown(nDataLen)==true
					&& nLatesBuyYmd+3>=pNowKData[nDataLen - 1].nYmd)
				{
					AddSell(nDataLen-1, nDataLen - 1, -BSTYPE_JXDOWN, BSMODE_STOPDOWN, 0);
				}
			}
		}
	}

	//初步判断当前标的的走势，对于寻找买点而言，要看最近60日（48个5分钟周期*30）的整体走势，
	//处于下跌的且跌幅超过15%标的才有关注价值
	//利用5日、10日均线或MACD判当前整体走势
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

		//判断最近3日5、10日均线距离是否不断减少,且5日线低于10日线。将来完善算法todo1008
		bool bIsDown = true;

		//初选策略很关键，应该有进一步的量化判断算法todo 1105
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

	//自动减仓用股票走势分析
	/*
	买入后:当前价位低于买入后最大值5%
	收盘价连续3日低于5日均线
	5日均线连续3日低于10日均线
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

		//判断最近3日5、10日均线距离是否不断减少,或(且??)5日线低于10日线。将来完善算法  todo20170203
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

	//计算均值
	void	MA(int	nDataLen, StockInfo *pBase,  //源数据项数、数据指针
		int nShort, int nLong,           //均值周期
		float *fShort, float *fLong)     //均值周期
	{
		int		nStart, j;

		if (nDataLen < nLong || nLong <= 0 || nShort <= 0)
			return;

		//仅计算最近的均值，太远的均值无益于买卖点分析
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
	//计算均值
	void	MA(int	nDataLen, StockInfo *pBase,  //源数据项数、数据指针
		int nShort, int nMid, int nLong,           //均值周期
		float *fShort, float *fMid, float *fLong)     //均值周期
	{
		int		nStart, j;

		if (nDataLen < nLong || nLong <= 0 || nMid <= 0 || nShort <= 0)
			return;

		//仅计算最近的均值，太远的均值无益于买卖点分析
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
	//计算成交量均值
	void	MAVOL(int	nDataLen, StockInfo *pBase,  //源数据项数、数据指针
		int nShort, int nMid, int nLong,           //均值周期
		long *lShort, long *lMid, long *lLong)     //均值周期
	{
		int	   j=0;
		long   l1, l2;
		if (nDataLen < nLong || nLong <= 0 || nMid <= 0 || nShort <= 0)
			return;

		//仅计算最近的均值，太远的均值无益于买卖点分析
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

	//初选1买标的使用,初步判断当前标的的走势，对于寻找买点而言，要看最近60日（48个5分钟周期*30）的整体走势，
	//对于2买3买：不排序直接给出结果：true  可买，false 不可买
	//过去跌多少不重要，重要的是目前下跌趋势是否已减弱，是否出现了升的趋势？
	//收盘高于短均线且长中短均线均处于上升状态
	//上涨标的排序依据：权重计算15-1,30-2,45-3,60-4,90-5
	bool	IsUp4Buy(int	nDataLen, StockInfo *pBase,bool Is1Buy=true)
	{
		
		bool		ret = false;
		float		fNowClose = 0;
		int			nWeek = g_nStockDownDays - 5,nDownRate=100-100*fCurClose/fMaxHigh;

		if (nDataLen<nWeek)
			return ret;

		bool bIsDown = true;

		int n1 = nDataLen, i = 0, nValidWeeks = 0;//有效的周期数

		while (g_usrAnalysePattern[g_nAnalysePat].nWeekList[i]> 0)
		{
			int  nCount =min( nDataLen,MALONG * 2 
				* g_usrAnalysePattern[g_nAnalysePat].nWeekList[i]/ 5);

			n1 = nCount;//将来优化，减少分析的数据量
			if (nDataLen < nCount)
			{
				i++;
				continue;
			}

			CreateStockData(&n1, p5MinKData + nDataLen - nCount, 
				pNowKData, 5, g_usrAnalysePattern[g_nAnalysePat].nWeekList[i]);

			SetMaxHighMinLow(n1);

			//收盘价均值
			MA(n1, pNowKData, MASHORT, MAMID, MALONG,
				this->fMAShort, this->fMAMid, this->fMALong);

			//长中短均线均上升才继续分析
			//当前收盘高于短均线
			//成交量持续上升
			//最近的两个底分型出现底背驰？？？
			ret =  MAUp(n1, fMALong, 3) && MAUp(n1, fMAMid, 3) && MAUp(n1, fMAShort, 3)
				&& (*(fMAShort+n1-1)-*(fMAMid+n1-1)>0)
				&& (*(fMAMid+n1-1)-*(fMALong+n1-1)>0)
				&& this->VOLUp5Min(n1,  3)
				&& pNowKData[n1-1].fClose>this->fMAShort[n1-1]
				//20170503暂时取消背驰检测
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
		if (nIndex >= 0 && nSellIndex<BSCOUNT) //动态保存卖点位置	TODO 0925
		{
			int i = 0;
			//指向一个空闲的卖点,将来扩充为在卖出日自动找顶分型卖出
			while (usrSell[i].nK>0) i = (i + 1) % BSCOUNT;

			usrSell[i].nK = nK;
			usrSell[i].nMustSellYMD = 0;
			usrSell[i].nAmount = nNumber;

			//卖出价存错：应该存入当前价 20170313 发现并纠正
			usrSell[i].fBuySellPrice = fCurClose;//  ptrStockInfo[nK].fClose;

			usrSell[i].nYmd = nCurYmd;
			usrSell[i].nMin = nCurMin;
			usrSell[i].nWeek = nWeek;
			nSellIndex++;
		}
		else
			//做空处理  将来扩充
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
	//获取最旧买入日期
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

	//获取当前持仓的最大持仓日期
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
	int		nCheckSell, nWeek;//每个分析周期进行过卖点分析标的数量
							  //short	nTradeIndex;  //持仓总数
	bool	bChanged, bBuySellChanged;     //结构数据发生变化时为true	 发出买卖信号时bBuySellChanged为true
	int		nCurDate, nCurTime;
	int		nCurStockIndex;//正处于分析阶段的当前持仓股票索引即usrStockTrade索引，无效为-1
	int	    nHoldingCount = 0;//目前持仓及自选持仓总数，每次执行完DoBuy后自动更新
	CNowTrends	usrStockTrade[MAXTRADENUMBER];
	float   fCurHolding;//当前持仓市值
	float	fStartFund, fNowFund, fNowGain, fAutoSellPoint;//初始金额  当前资金额度 当前盈余比例购买后自动离场周期数即最大持仓周期数，0不自动离场，大于0持仓周期
	int		nNextRecord;//下次读取的文件记录位置,以上证指数为参考点
	int     nCurDataLen;//当前数据长度,,以上证指数为参考点
	char    strBlock[32];//板块名称
private:
	int     nForSellCode[2] = {0,0};//潜在清仓标的，拟在出现很好的买点时清仓
	int		nMustSellYMD;//nMustSellYMD最大持仓周期
	float	fBuyFeeRate, fSellFeeRate, fMaxUpPercent, fMaxDownPercent;//买卖费率  止损、止盈比率
	int		nBuyCount, nSellCount, nSellNumber;//fBuyCount/nSellCount 小于100表示每次购买的剩余资金百分比，大于100表示每次购买的股数 nSellNumber卖出次数，第四次清仓
	int		nBuyNumber;//当前买点索引  买入日期时间和K线索引（判断最大持仓周期用）
	float	fCJDMaxDownPercent, fDownPrice, fBuySellFee;//在有效缠极点高位最大回撤比例及回撤止损价位，低于即出局

public:


	void	Init(int	MaxDataLen)
	{

	}

	//分析持仓标的是否处于可买/继续持有状态并排序
	//处于最后的两个标的可能是会被优化的标的  todo 20170501 待优化  采用判涨还是判跌？
	void DetectHoldingBuySignal(CStockBlockInfo *ptrBlockInfo, int nStopDate, int nStopTime)
	{
		int i = 0;

		//使用空闲的float数组进行计算
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
		////取出拟清仓标的备用
		//if (g_usrDayTrends.nBuy1Count >= 2)
		//{
		//	for (i = 0; i <2; i++)
		//	{
		//		nForSellCode[i] = g_usrDayTrends.usrBuy1List[g_usrDayTrends.nBuy1Count - 1 - i].nCode;
		//	}
		//}
		

	}

	//根据买卖点情况，结合其他因素，如大盘热度、板块热度等信息决定当前购买数量，算法待扩充完善
	//买入单位为手，即100股
	int	CaclBuyAmount(BSInfo *usrBuyPtr)
	{
		int nRet = (int)((fNowFund / 10000)*nBuyCount / usrBuyPtr->fBuySellPrice);
		/*if(nRet<1)
		nRet=1;*/

		return nRet;
	}

	//根据买卖点情况，结合其他因素，如大盘热度、板块热度等信息决定当前卖出数量，算法待扩充完善
	//每次调用卖出指定比例的持仓量	nNumber<=0 时，每次卖出持仓25%，nNumber>0时卖出指定比例
	//卖出单位为手，即100股
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

		//卖出信号达到BSCOUNT次，清空该股票
		if (usrStockTrade[i].GetSellIndex() == BSCOUNT)
		{
			nRet = usrStockTrade[i].nHoldingAmount;

			//当前标的已清仓处理
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
		{	  //清空持仓数据
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
			//当前标的已清仓处理
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

			//已有持仓,不加入新股票
			if (nCount > 0)
				continue;

			usrBuyPtr = g_usrDayTrends.Buy1Get();
			if (usrBuyPtr == NULL) break;//没有买点信息，直接退出，没有买点信息可用
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
						usrStockTrade[i].fAutoUpSellPrice = (usrBuyPtr + j)->fBuySellPrice*(1 + fMaxUpPercent);//一买时计算好止损fAutoDownSellPrice、止盈价格fAutoUpSellPrice 
					}

					if ((usrBuyPtr + j)->nAmount > 0)
					{
						bBSValid = true;
						bChanged = true;

						if (i < g_nMaxHolding)  //自动持仓标的
						{
							fFee = 100 * (usrBuyPtr + j)->nAmount*(usrBuyPtr + j)->fBuySellPrice;
							fNowFund = fNowFund - fFee - fFee*fBuyFeeRate;

							usrStockTrade[i].fAveragePrice = (usrBuyPtr + j)->fBuySellPrice;
							usrStockTrade[i].nHoldingAmount = usrStockTrade[i].nHoldingAmount + (usrBuyPtr + j)->nAmount;

							//todo 做记录	 代码,日期,时间,分析周期，买量,成交额,手续费,类型,模式,最大持仓周期,买入价,止损价,止盈价
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

						if (j == 0 && g_nWorkMode == WORKMODE_REAL)  //只输出当日第一个买点
						{
							g_sMailContent.append("\n");
							g_sMailContent.append(sbuf);
							sprintf_s(sbuf, ",B%07d", usrStockTrade[i].GetCode());
							g_sMailTitle.append(sbuf);
						}
					}
					else
					{
						//资金不足的买点，记录曾经出现的买点  todo 数据太多，将来完善20170307
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
				//二买、三买判断
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
						//正常持仓处理
						if (usrStockTrade[i].fAutoDownSellPrice == 0)
						{
							usrStockTrade[i].fAutoDownSellPrice = (usrBuyPtr + j)->fBuySellPrice*(1 - fMaxDownPercent);
							usrStockTrade[i].f2BuyGate = (usrBuyPtr + j)->fBuySellPrice*(1 + fMaxDownPercent / 2);
							usrStockTrade[i].fAutoUpSellPrice = (usrBuyPtr + j)->fBuySellPrice*(1 + fMaxUpPercent);//一买时计算好止损fAutoDownSellPrice、止盈价格fAutoUpSellPrice 
						}
						fFee = 100 * (usrBuyPtr + j)->nAmount*(usrBuyPtr + j)->fBuySellPrice;

						usrStockTrade[i].fAveragePrice = (fFee / 100 + usrStockTrade[i].nHoldingAmount *usrStockTrade[i].fAveragePrice);
						usrStockTrade[i].nHoldingAmount += (usrBuyPtr + j)->nAmount;
						//计算当前持仓成本价
						usrStockTrade[i].fAveragePrice = usrStockTrade[i].fAveragePrice / usrStockTrade[i].nHoldingAmount;

						fNowFund = fNowFund - fFee - fFee*fBuyFeeRate;

						usrStockTrade[i].nCurMin = nCurTime;
						usrStockTrade[i].nCurYmd = nCurDate;
						usrStockTrade[i].fCurClose = (usrBuyPtr + j)->fClose;
						bBSValid = true;

						//todo 做记录	 代码,日期,时间,分析周期，买量,成交额,手续费,类型,模式,最大持仓周期,买入价,止损价,止盈价
						nDate = ((usrBuyPtr + j)->nYmd / 2048 + 104) * 10000 + (usrBuyPtr + j)->nYmd % 2048;
						nTime = ((usrBuyPtr + j)->nMin / 60) * 100 + (usrBuyPtr + j)->nMin % 60;
						sprintf_s(sbuf, "%07d,%07d,%04d,%04d,%04d,%03d,%06.2f,%04.2f,%02d,%02d,%04d,%04.2f,%04.2f,%04.2f",
							usrStockTrade[i].GetCode(), nDate, nTime, (usrBuyPtr + j)->nWeek, (usrBuyPtr + j)->nDownPercent, (usrBuyPtr + j)->nAmount, -fFee,
							-fFee*fBuyFeeRate, (usrBuyPtr + j)->nType, (usrBuyPtr + j)->nMode,
							(usrBuyPtr + j)->nMustSellYMD, (usrBuyPtr + j)->fBuySellPrice, usrStockTrade[i].fAutoDownSellPrice, usrStockTrade[i].fAutoUpSellPrice);
						LogBSFile(g_sBSLog, sbuf);

					}
					else
						//重点关注指数和自定义持仓处理
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
						if (usrSellPtr->nAmount == 0) //常规卖点,按比例卖出
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

						//卖点信息记录，将来补充
						if (i < g_nMaxHolding)
						{
							fFee = 100 * usrSellPtr->nAmount*usrSellPtr->fBuySellPrice;
							fNowFund = fNowFund + fFee - fFee*fSellFeeRate;
						}
						else
							fFee = -1234;

						bChanged = true;

						//todo 做记录	 代码,日期,时间,买量,成交额,手续费,类型,模式,最大持仓周期,成交价,均价,盈亏比
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
				//同一股票多次买入处理  将来扩充
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
			//已在持仓列表方可卖出，卖空将来扩充
			if (this->nCurStockIndex >-1)
			{
				//同一股票多次买入处理  将来扩充
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
	//检查指定股票是否在持仓列表，并将当前股票参数赋予g_usrNowTrends
	//仅对自动持仓标的有效
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

	//判断目前是否已到了最大持仓，是则返回true
	//满仓后不必判断后续出现的1买
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

	//检查指定股票是否在自定义持仓列表，并将当前股票参数赋予g_usrNowTrends
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


//用于策略分析的数据结构
typedef struct tagStock5MinKData
{
	int nCode;//股票或指数代码
	//int nFileStartYmd, nFileStartMin, nFileStopYmd, nFileStopMin; //文件数据的起止日期时间
	//int nStartYmd, nStartMin, nStopYmd, nStopMin; //结构体数据的起止日期时间
	//int nStopTradeStartYmd, nStopTradeStopYmd; //当前分析周期内停牌时段
	long  lCount=0;  //数据总项数(除48可转化为交易日数据)
				   //保存单次最大可分析的5分钟K线数据，如果内存不足，将来可适当减小MAX5KS
	StockInfo	*usrKData;
	//设置股票代码的同时读取对应的5分钟K线数据
	void SetCode(int Code)
	{
		nCode = Code;
	}

	//设置股票代码的同时读取对应的5分钟K线数据
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
			//读取5分钟K线文件基本数据
			lCount = GetFileSize((char*)sTmp.c_str()) / 32 ;
			if (lCount <= 0 || lCount > 10000000) return;
			int		nOldDataCount=0;
			usrKData = new StockInfo[lCount+ g_nStockDownDays * 48+48 ];
			//先读部分历史数据
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
			//读取5分钟K线文件基本数据
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

//拟分析的股票板块信息
//保存股票代码5分钟K线数据的关键信息，包括当前停牌周期等，减少对文件的读写
class   CStockBlockInfo
{
public:
	int		nBlockCount = 0;//板块股票总数
	//数据开始日期、结束日期，开始时间固定为0935，结束时间固定为1500
	int		nStartYmd;
	int		nStopYmd;
	float	*fMAShort = NULL, *fMAMid = NULL, *fMALong = NULL;
	Stock5MinKData	*usr5MinKDataInfo = NULL;//各股票5分钟K线文件信息
public:
	CStockBlockInfo()
	{
		nStartYmd=0, nStopYmd=0;
	}

	//判断指定股票代码是否在板块中,返回其索引
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

	//获取指定股票代码的5分钟K线数据
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
	//更新类内5分钟K线数据
	//如果nDate在nStartYmd 、nStopYmd范围内，不变化返回false，需要变化返回true
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
		sprintf_s(sbuf, "UpdateDate %s.%s->股票数：%d 开始： %d  %d", 
			g_usrAutoTrade.strBlock, g_usrAnalysePattern[g_nAnalysePat].sName,
			nBlockCount,  nDate, nTime);

		LogFile("trade\\readlog.txt", sbuf);

		for (i = 0; i < nBlockCount; i++)
			usr5MinKDataInfo[i].Read5MinData(nStart, nStop);

		GetCurrentDateTime(&nDate, &nTime);

		sprintf_s(sbuf, "UpdateDate %s.%s->股票数：%d 结束： %d  %d",
			g_usrAutoTrade.strBlock, g_usrAnalysePattern[g_nAnalysePat].sName,
			nBlockCount, nDate, nTime);

		;
		LogFile("trade\\readlog.txt", sbuf);

		return true;
	}

	//删除5分钟K线数据内存
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

	//如果nDate在nStartYmd 、nStopYmd范围内返回true,否则false
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