#pragma once
#include <time.h>
//#include "gmTrade.h"
//extern CRISINGSUNTRADER  g_usrTrader;
//extern CINTEGER_QUEUE g_usrTAQueue;
extern CSTOCKDATAS g_usrStockData[MAXSTOCKS];

int FindStockInL2Ticks(CSTOCKDATAS *pStockData, int nStockCode);
void dealWithHotKey(HWND hwnd, WPARAM wParam);
void regVirtualMouseHotKey(HWND hwnd);
int  InitUI(HINSTANCE hInstExe);
void   AddData2ReadDFCFThreadQueue(int , int , int );

class CDISPLAY
{
#define DISPLAYBUFSIZE   8192*4
private:
	char szBuffer[DISPLAYBUFSIZE] = { 0 };
	
	CRITICAL_SECTION cs;

public:
	//多线程使用时可能出现混乱  todo
	void AddMsg(HWND hWnd, char *szMsg)
	{
		char szBuf[512] = { 0 };

		time_t now;
		struct tm * timeinfo;
		time(&now);
		timeinfo = localtime(&now);
		sprintf_s(szBuf, "[%02d:%02d:%02d] %s", 
			timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec,  szMsg);

		int nMsgLen = strlen(szBuf);

		int nCount = min(DISPLAYBUFSIZE / 10, nMsgLen + 10);  //10%缓冲  截除超过90%处的内容

		EnterCriticalSection(&cs);

		if (strlen(szBuffer) + nCount > DISPLAYBUFSIZE)
			szBuffer[DISPLAYBUFSIZE*2/3] = 0;

		//把最新的数据放在最前显示
		if (strlen(szBuffer)>0)
			memcpy_s(szBuffer + strlen(szBuf) + 2, DISPLAYBUFSIZE - nCount, szBuffer, strlen(szBuffer));

		memcpy_s(szBuffer, nMsgLen, szBuf, nMsgLen);
		memcpy_s(szBuffer + nMsgLen, 2, "\r\n", 2);

		SetDlgItemTextA(hWnd, IDC_INFO, szBuffer);

		LeaveCriticalSection(&cs);
	}

	CDISPLAY()
	{
		InitializeCriticalSection(&cs);
	}

	~CDISPLAY()
	{

	}
};
