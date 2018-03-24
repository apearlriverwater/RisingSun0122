/******************************************************************************
Module:  readDFCF.h
Notices: Copyright (c) 2008 Jeffrey Richter & Christophe Nasarre
******************************************************************************/

#include "APIHook.h"

#ifdef _X86_

#else

#error WINVER ERRORSLECT  ONLY USES ON X86!!!

#endif

typedef struct tagMODULEINFO {
	PVOID AllocationBase;
	char szModName[64] ;
}MODULEINFO;


//函数截取处理类
typedef struct tagHOOKSTRUCT {
	#define FLATJMPCODE_LENGTH 5            //x86 平坦内存模式下，绝对跳转指令长度
	#define FLATJMPCMD_LENGTH  1            //jmp指令码0xe9长度
	#define FLATJMPCMD         0xe8          //MODULE LONG JMP  0xe9,MODULE CALL  0xe8
	#define FLATNOPCMD         0x90          //NOP


	char	*szModuleName, *szFuncName;//被截取的模块和函数名
	int		nOffset;		//被拦截函数的实际入口相对指定函数地址的偏移量
	PVOID	*pfOrigFun = NULL, *pfNewFun = NULL;//原函数指针和新函数指针
	BYTE    bytOrigEntryCode[FLATJMPCODE_LENGTH+1] = {0};//原函数入口处的指令码
	//nOffset  被拦截函数的实际入口相对指定函数地址的偏移量


	bool HookApi(bool bLocal=true)
	{
		bool    IsSuccess = FALSE;
		DWORD   TempProtectVar;              //临时保护属性变量
		MEMORY_BASIC_INFORMATION MemInfo = { 0 };    //内存分页属性信息
		int nRetry = 0, nRetryCount = 5;

		if (!pfOrigFun)
			return IsSuccess;

		while (nRetry<nRetryCount
			&& VirtualQuery(pfOrigFun, &MemInfo, sizeof(MEMORY_BASIC_INFORMATION)) != sizeof(MEMORY_BASIC_INFORMATION))
		{
			Sleep(20);
			nRetry++;
		}

		if (nRetry<nRetryCount)
		{
			__try
			{
				nRetry = 0;
				while (nRetry<nRetryCount
					&& !VirtualProtect(MemInfo.BaseAddress, MemInfo.RegionSize, PAGE_READWRITE, &MemInfo.Protect))
				{
					Sleep(20);
					nRetry++;
				}

				if (nRetry<nRetryCount)                            //修改页面为可写
				{
					for (int i = 0; i<FLATJMPCODE_LENGTH+1; i++)
						bytOrigEntryCode[i] =*((BYTE*)pfOrigFun + i);

					*(BYTE*)pfOrigFun = FLATJMPCMD;  

					if(bLocal ) //模块内调用
						*(DWORD*)((BYTE*)pfOrigFun + FLATJMPCMD_LENGTH)
							= (DWORD)pfNewFun - (DWORD)pfOrigFun - FLATJMPCODE_LENGTH ;
					else //跨模块调用
					{
						*(DWORD*)((BYTE*)pfOrigFun + FLATJMPCMD_LENGTH)
							= (DWORD)pfNewFun - (DWORD)pfOrigFun - FLATJMPCODE_LENGTH;
						*((BYTE*)pfOrigFun + FLATJMPCMD_LENGTH+4)= FLATNOPCMD;//空指令
					}

						

					nRetry = 0;
					while (nRetry<nRetryCount
						&& !VirtualProtect(MemInfo.BaseAddress,
							MemInfo.RegionSize, MemInfo.Protect, &TempProtectVar))   //改回原属性
					{
						Sleep(20);
						nRetry++;
					}

					IsSuccess = TRUE;
				}
			}
			__finally
			{

			}
		}

		return IsSuccess;

	}

	BOOL unHookApi()
	{
		BOOL    IsSuccess = FALSE;
		DWORD   TempProtectVar;              //临时保护属性变量
		MEMORY_BASIC_INFORMATION MemInfo = { 0 };    //内存分页属性信息
		int nRetry = 0, nRetryCount = 5;

		if (!pfOrigFun)
			return IsSuccess;

		//防止内存不能访问导致失败
		while (nRetry<nRetryCount
			&& VirtualQuery(pfOrigFun, &MemInfo, sizeof(MEMORY_BASIC_INFORMATION)) != sizeof(MEMORY_BASIC_INFORMATION))
		{
			Sleep(20);
			nRetry++;
		}

		if (nRetry<nRetryCount)
		{
			__try
			{
				nRetry = 0;
				//防止内存不能访问导致失败
				while (nRetry<nRetryCount
					&& !VirtualProtect(MemInfo.BaseAddress, MemInfo.RegionSize, PAGE_READWRITE, &MemInfo.Protect))
				{
					Sleep(20);
					nRetry++;
				}

				if (nRetry<nRetryCount)                            //修改页面为可写
				{
					for (int i = 0; i<FLATJMPCODE_LENGTH; i++)
						*((BYTE*)pfOrigFun + i) = bytOrigEntryCode[i];

					IsSuccess = TRUE;
				}
			}
			__finally
			{
				nRetry = 0;
				while (nRetry<nRetryCount
					&& !VirtualProtect(MemInfo.BaseAddress,
						MemInfo.RegionSize, MemInfo.Protect, &TempProtectVar))   //改回原属性
				{
					Sleep(20);
					nRetry++;
				}
			}
		}

		return IsSuccess;


	}

	BOOL InitHook(char *szMod, char *szFunc, PVOID *pfNew, int nOffsetIn = 0)
	{
		pfOrigFun = NULL;
		pfNewFun = pfNew;
		szModuleName = szMod, szFuncName = szFunc;
		nOffset = nOffsetIn;

		HMODULE  hModule = GetModuleHandleA(szModuleName);
		pfOrigFun = (PVOID*)((BYTE*)GetProcAddress(hModule, szFunc) + nOffset);

		return (!pfOrigFun);
	}
	
}HOOKSTRUCT;

HOOKSTRUCT  usrHookDFCF[3];
int	 g_nCurStockCode, g_nTradeDate;

class HOOKDATACENTER
{
private:
	

public:
	

	HOOKDATACENTER()
	{
		Init();
	}

	~HOOKDATACENTER()
	{

	}


	static void Init()
	{
		g_nCurStockCode = 0;
		usrHookDFCF[0].InitHook("datacenter.dll",
			"?Add_L2DetailData@QDataEngine@@SAJPADEKKPAUL2_TRANSACTION_PKG@@H@Z", //被截取的模块名字和函数名字
			(PVOID*)HookAddL2Detail, //函数指针 
			0x0503A018 - 0X5106860 //相对被拦截函数的偏移量（通过IDA可获得有关参数），缺省值为
			);
		usrHookDFCF[0].HookApi();

		usrHookDFCF[1].InitHook("datacenter.dll",
			"?Add_L2DetailData@QDataEngine@@SAJPADEKKPAUL2_TRANSACTION_PKG@@H@Z", //被截取的模块名字和函数名字
			(PVOID*)Hook4DCA010memcpy_s, //函数指针 
			0x4DCA0F1-0X50F6860 //相对被拦截函数的偏移量（通过IDA可获得有关参数），缺省值为0
			);
		usrHookDFCF[1].HookApi(false);
		
		//CDataMgr::GetOneStkInfo(CDataMgr *this, char a2, char a3)
		//usrHookDFCF[2].InitHook("datacenter.dll",
		//		"?GetOneStkInfo@CDataMgr@@QAEPAUSTK_PER@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@D@Z", //被截取的模块名字和函数名字
		//		(PVOID*)GetCurStockCode, //函数指针 
		//		0x050A6A84 - 0X050A69D0  //相对被拦截函数的偏移量（通过IDA可获得有关参数），缺省值为0
		//	);
		//usrHookDFCF[2].HookApi(false);//属于跨段调用  非本地调用

		return;
		
	}
	//利用__thiscall解决this指针的有效传递问题
	static char __thiscall  Hook4DCA010(DWORD *pObj,int a2, int a3, int a4, int a5)
	{
		__asm {
						
			mov al,1

			
		}
	}

	//拦截对memcpy_s调用，数据送出
	static int __cdecl Hook4DCA010memcpy_s(void *Dst, rsize_t DstSize, const void *Src, rsize_t MaxCount)
	{
		PCWSTR  pszCaption = L"RingSun Aplication";

		// Send the string to the main dialog box
		COPYDATASTRUCT cdsCaptical = { 0x101, (MaxCount + 1) , (PVOID)Src };

		FORWARD_WM_COPYDATA(FindWindow(NULL, pszCaption),
			NULL, &cdsCaptical, SendMessage);

		memcpy_s(Dst, DstSize, Src, MaxCount);//执行本函数会导致dfcf直接退出，是否该应用的保护机制？？
		return 1;
	}

	//拦截对char *__cdecl strncpy(char *, const char *, size_t)调用，获取当前stockcode
	//int __thiscall CDataMgr::GetOneStkInfo(CDataMgr *this, char a2, char a3)
	//可获得dfcf目前正在处理的股票或指数的代码，调用非常频繁
	static char * __cdecl GetCurStockCode(char *szDest, const char *szSrc, size_t nCount)
	{
		PCWSTR  pszCaption = L"RingSun Aplication";
		
		g_nCurStockCode = atoi(szSrc);

		// Send the stock code  to the main dialog box  仅发送前八字节的内容
		COPYDATASTRUCT cdsCodeDate = { 0x99, nCount+2 ,(PVOID) szSrc };

		FORWARD_WM_COPYDATA(FindWindow(NULL, pszCaption),
			NULL, &cdsCodeDate, SendMessage);

		return strncpy(szDest, szSrc,  nCount);
	}

	static int __cdecl  HookAddL2Detail(char * szStockCode, char nA2, unsigned int nA3,
		unsigned int nSize, char * vpPtr, int nTradeDate)
	{
		static unsigned int nBuf[] = { 0,0,0 };

		if (nSize <= 0)
			return true;

		if (nBuf[0] != (unsigned int)atoi(szStockCode)
			|| nBuf[1] != nTradeDate
			|| nBuf[2] != nSize
			)
		{
			nBuf[0] = atoi(szStockCode);
			nBuf[1] = nTradeDate;
			nBuf[2] = nSize;
			g_nCurStockCode = nBuf[0];
			g_nTradeDate = nTradeDate;
			PCWSTR  pszCaption = L"RingSun Aplication";

			// Send the stock code  to the main dialog box  仅发送前八字节的内容
			COPYDATASTRUCT cdsCodeDate = { 0x99, 8 ,nBuf };

			FORWARD_WM_COPYDATA(FindWindow(NULL, pszCaption),
				NULL, &cdsCodeDate, SendMessage);

			// Send the string to the main dialog box
			COPYDATASTRUCT cdsL2 = { 0x100, (nSize * 17 + 1) , vpPtr };

			FORWARD_WM_COPYDATA(FindWindow(NULL, pszCaption),
				NULL, &cdsL2, SendMessage);
		}


		int nResult = true;

		// Return the result back to the caller
		return(nResult);

	}
};

//函数跳转出口与入口

//函数跳出跳入处理类  利用被截取函数中的循环实现入口跳出、跳入控制
//class CFUNCTION_OUT_IN {
//public:
//	 DWORD	pOutFrom , pInTo ;//函数跳出、跳入地址
//	 char	*szModuleName, *szFuncName;//模块和函数名
//	 BYTE    *pbytOrigEntryCode ;//原函数入口处的指令码
//	 int		m_nOrigEntryCodeSize;
//	CFUNCTION_OUT_IN(PVOID *pfNew, char *szMod, char *szFunc,
//		DWORD dwOutOffset,DWORD dwInOffset,int nOrigEntryCodeSize = 5 )
//	{
//		if (nOrigEntryCodeSize > 0)  
//		{
//			m_nOrigEntryCodeSize = nOrigEntryCodeSize;
//			
//			szModuleName = szMod, szFuncName = szFunc;
//			pbytOrigEntryCode = new BYTE[m_nOrigEntryCodeSize];
//			HMODULE  hModule = GetModuleHandleA(szModuleName);
//			pOutFrom = (DWORD)((BYTE*)GetProcAddress(hModule, szFuncName) + dwOutOffset);
//			pInTo = (DWORD)((BYTE*)GetProcAddress(hModule, szFuncName) + dwInOffset);
//		}
//	}
//	~CFUNCTION_OUT_IN()
//	{
//		if (pbytOrigEntryCode != NULL)
//		{
//			delete  pbytOrigEntryCode;
//			pbytOrigEntryCode = NULL;
//		}
//	}
//
//public:
//
//	static int __cdecl  OutInAddL2Detail()
//	{
//		__asm
//		{
//			//恢复编译器自动进行的一系列堆栈保护操作
//			lea ebx,backto
//			add ebx,1
//			mov DWORD PTR[ebx], pInTo
//			pop	 edi
//			pop	 esi
//			pop	 ebx
//			add	 esp, 192; 000000c0H
//			mov	 esp, ebp
//			pop	 ebp
//	backto:
//			push 0x12345678;//0x12345678要被实际的返回地址替换
//			ret
//		}
//	}
//
//	BOOL HookApi()
//	{
//		BOOL    IsSuccess = FALSE;
//		DWORD   TempProtectVar;              //临时保护属性变量
//		MEMORY_BASIC_INFORMATION MemInfo = { 0 };    //内存分页属性信息
//		int nRetry = 0, nRetryCount = 5;
//
//		if (!pOutFrom)
//			return IsSuccess;
//
//		while (nRetry<nRetryCount
//			&& VirtualQuery((PVOID*)pOutFrom, &MemInfo, sizeof(MEMORY_BASIC_INFORMATION)) != sizeof(MEMORY_BASIC_INFORMATION))
//		{
//			Sleep(20);
//			nRetry++;
//		}
//
//		if (nRetry<nRetryCount)
//		{
//			__try
//			{
//				nRetry = 0;
//				while (nRetry<nRetryCount
//					&& !VirtualProtect(MemInfo.BaseAddress, MemInfo.RegionSize, PAGE_READWRITE, &MemInfo.Protect))
//				{
//					Sleep(20);
//					nRetry++;
//				}
//
//				if (nRetry<nRetryCount)       //修改页面为可写
//				{
//					for (int i = 0; i<m_nOrigEntryCodeSize; i++)
//						pbytOrigEntryCode[i] = *((BYTE*)pOutFrom + i);
//
//					*(BYTE*)pOutFrom = FLATJMPCMD;
//					*(DWORD*)((BYTE*)pOutFrom + FLATJMPCMD_LENGTH) = (DWORD)OutInAddL2Detail -
//						(DWORD)pOutFrom - FLATJMPCODE_LENGTH;
//
//					nRetry = 0;
//					while (nRetry<nRetryCount
//						&& !VirtualProtect(MemInfo.BaseAddress,
//							MemInfo.RegionSize, MemInfo.Protect, &TempProtectVar))   //改回原属性
//					{
//						Sleep(20);
//						nRetry++;
//					}
//
//					IsSuccess = TRUE;
//				}
//			}
//			__finally
//			{
//
//			}
//		}
//
//		return IsSuccess;
//
//	}
//
//	BOOL unHookApi()
//	{
//		BOOL    IsSuccess = FALSE;
//		DWORD   TempProtectVar;              //临时保护属性变量
//		MEMORY_BASIC_INFORMATION MemInfo = { 0 };    //内存分页属性信息
//		int nRetry = 0, nRetryCount = 5;
//
//		if (!pOutFrom)
//			return IsSuccess;
//
//		//防止内存不能访问导致失败
//		while (nRetry<nRetryCount
//			&& VirtualQuery((PVOID*)pOutFrom, &MemInfo, sizeof(MEMORY_BASIC_INFORMATION)) != sizeof(MEMORY_BASIC_INFORMATION))
//		{
//			Sleep(20);
//			nRetry++;
//		}
//
//		if (nRetry<nRetryCount)
//		{
//			__try
//			{
//				nRetry = 0;
//				//防止内存不能访问导致失败
//				while (nRetry<nRetryCount
//					&& !VirtualProtect(MemInfo.BaseAddress, MemInfo.RegionSize, PAGE_READWRITE, &MemInfo.Protect))
//				{
//					Sleep(20);
//					nRetry++;
//				}
//
//				if (nRetry<nRetryCount)                            //修改页面为可写
//				{
//					for (int i = 0; i<FLATJMPCODE_LENGTH; i++)
//						*((BYTE*)pOutFrom + i) = pbytOrigEntryCode[i];
//
//					IsSuccess = TRUE;
//				}
//
//
//
//			}
//			__finally
//			{
//				nRetry = 0;
//				while (nRetry<nRetryCount
//					&& !VirtualProtect(MemInfo.BaseAddress,
//						MemInfo.RegionSize, MemInfo.Protect, &TempProtectVar))   //改回原属性
//				{
//					Sleep(20);
//					nRetry++;
//				}
//			}
//		}
//
//		return IsSuccess;
//
//
//	}
//
//
//};


//////////////////////////////// End of File //////////////////////////////////
