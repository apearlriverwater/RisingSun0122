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


//������ȡ������
typedef struct tagHOOKSTRUCT {
	#define FLATJMPCODE_LENGTH 5            //x86 ƽ̹�ڴ�ģʽ�£�������תָ���
	#define FLATJMPCMD_LENGTH  1            //jmpָ����0xe9����
	#define FLATJMPCMD         0xe8          //MODULE LONG JMP  0xe9,MODULE CALL  0xe8
	#define FLATNOPCMD         0x90          //NOP


	char	*szModuleName, *szFuncName;//����ȡ��ģ��ͺ�����
	int		nOffset;		//�����غ�����ʵ��������ָ��������ַ��ƫ����
	PVOID	*pfOrigFun = NULL, *pfOrigFunCaller = NULL, *pfNewFun = NULL;//ԭ����ָ����º���ָ��
	BYTE    bytOrigEntryCode[FLATJMPCODE_LENGTH+1] = {0};//ԭ������ڴ���ָ����
	//nOffset  �����غ�����ʵ��������ָ��������ַ��ƫ����


	bool HookApi(bool bLocal=true)
	{
		bool    IsSuccess = FALSE;
		DWORD   TempProtectVar;              //��ʱ�������Ա���
		MEMORY_BASIC_INFORMATION MemInfo = { 0 };    //�ڴ��ҳ������Ϣ
		int nRetry = 0, nRetryCount = 5;

		if (!pfOrigFunCaller)
			return IsSuccess;

		while (nRetry<nRetryCount
			&& VirtualQuery(pfOrigFunCaller, &MemInfo, sizeof(MEMORY_BASIC_INFORMATION)) != sizeof(MEMORY_BASIC_INFORMATION))
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

				if (nRetry<nRetryCount)                            //�޸�ҳ��Ϊ��д
				{
					for (int i = 0; i<FLATJMPCODE_LENGTH+1; i++)
						bytOrigEntryCode[i] =*((BYTE*)pfOrigFunCaller + i);

					*(BYTE*)pfOrigFunCaller = FLATJMPCMD;  

					if(bLocal ) //ģ���ڵ���
						*(DWORD*)((BYTE*)pfOrigFunCaller + FLATJMPCMD_LENGTH)
							= (DWORD)pfNewFun - (DWORD)pfOrigFunCaller - FLATJMPCODE_LENGTH ;
					else //��ģ�����
					{
						*(DWORD*)((BYTE*)pfOrigFunCaller + FLATJMPCMD_LENGTH)
							= (DWORD)pfNewFun - (DWORD)pfOrigFunCaller - FLATJMPCODE_LENGTH;
						*((BYTE*)pfOrigFunCaller + FLATJMPCMD_LENGTH+4)= FLATNOPCMD;//��ָ��
					}

						

					nRetry = 0;
					while (nRetry<nRetryCount
						&& !VirtualProtect(MemInfo.BaseAddress,
							MemInfo.RegionSize, MemInfo.Protect, &TempProtectVar))   //�Ļ�ԭ����
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
		DWORD   TempProtectVar;              //��ʱ�������Ա���
		MEMORY_BASIC_INFORMATION MemInfo = { 0 };    //�ڴ��ҳ������Ϣ
		int nRetry = 0, nRetryCount = 5;

		if (!pfOrigFunCaller)
			return IsSuccess;

		//��ֹ�ڴ治�ܷ��ʵ���ʧ��
		while (nRetry<nRetryCount
			&& VirtualQuery(pfOrigFunCaller, &MemInfo, sizeof(MEMORY_BASIC_INFORMATION)) != sizeof(MEMORY_BASIC_INFORMATION))
		{
			Sleep(20);
			nRetry++;
		}

		if (nRetry<nRetryCount)
		{
			__try
			{
				nRetry = 0;
				//��ֹ�ڴ治�ܷ��ʵ���ʧ��
				while (nRetry<nRetryCount
					&& !VirtualProtect(MemInfo.BaseAddress, MemInfo.RegionSize, PAGE_READWRITE, &MemInfo.Protect))
				{
					Sleep(20);
					nRetry++;
				}

				if (nRetry<nRetryCount)                            //�޸�ҳ��Ϊ��д
				{
					for (int i = 0; i<FLATJMPCODE_LENGTH; i++)
						*((BYTE*)pfOrigFunCaller + i) = bytOrigEntryCode[i];

					IsSuccess = TRUE;
				}
			}
			__finally
			{
				nRetry = 0;
				while (nRetry<nRetryCount
					&& !VirtualProtect(MemInfo.BaseAddress,
						MemInfo.RegionSize, MemInfo.Protect, &TempProtectVar))   //�Ļ�ԭ����
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
		pfOrigFunCaller = NULL;
		pfNewFun = pfNew;
		szModuleName = szMod, szFuncName = szFunc;
		nOffset = nOffsetIn;

		HMODULE  hModule = GetModuleHandleA(szModuleName);
		pfOrigFun = (PVOID*)GetProcAddress(hModule, szFunc);
		pfOrigFunCaller = (PVOID*)((BYTE*)pfOrigFun + nOffset);

		return (!pfOrigFunCaller);
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
		/*
		102C7390 AddData  v591 = QDataEngine::WriteCapitalFlowKLineData
		      102D0107   call    ?WriteCapitalFlowKLineData@QDataEngine@@SAJEW4DCYCLE@@ABV?$basic_string@_WU?$char_traits@_W@std@@V?$allocator@_W@2@@std@@PAUCAPITALFLOW_DAY_ITEM_DATA@@HAAH@Z ; QDataEngine::WriteCapitalFlowKLineData(uchar,DCYCLE,std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>> const &,CAPITALFLOW_DAY_ITEM_DATA *,int,int &)
		int __thiscall sub_102F9AD0(WPARAM *this, int a2)(��Ч����,ʵʱ�Ե�K���ʽ������ݣ���;����)
		     102F9FD2   call    ?WriteCapitalFlowKLineData@QDataEngine@@SAJEW4DCYCLE@@ABV?$basic_string@_WU?$char_traits@_W@std@@V?$allocator@_W@2@@std@@PAUCAPITALFLOW_DAY_ITEM_DATA@@HAAH@Z ; QDataEngine::WriteCapitalFlowKLineData(uchar,DCYCLE,std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>> const &,CAPITALFLOW_DAY_ITEM_DATA *,int,int &)
		

		*/
		g_nCurStockCode = 0;
		int Add_L2DetailData_entrence = 0x7566ef0;
		int call_address_of_Add_L2DetailData = 0x0749A018;
		usrHookDFCF[0].InitHook("datacenter.dll",
			"?Add_L2DetailData@QDataEngine@@SAJPADEKKPAUL2_TRANSACTION_PKG@@H@Z", //����ȡ��ģ�����ֺͺ�������
			(PVOID*)HookAddL2Detail, //����ָ�� 
			call_address_of_Add_L2DetailData - Add_L2DetailData_entrence  //��Ա����غ�����ƫ������ͨ��IDA�ɻ���йز�������ȱʡֵΪ
			);
		usrHookDFCF[0].HookApi();

		int WriteCapitalFlowKLineData_entrence = 0x10364CB0;
		int call_address_of_WriteCapitalFlowKLineData = 0x102F9FD2;
		int AddDataAddress = 0x102C7390;
		/*
		usrHookDFCF[1].InitHook("datacenter.dll",
			"?AddData@CDataMgr@@QAEXPAPAD@Z", //����ȡ��ģ�����ֺͺ�������
			(PVOID*)HookWriteCapitalFlowKLineData, //����ָ��  WriteCapitalFlowKLineData(char, int, int, void *, int, int)
			call_address_of_WriteCapitalFlowKLineData- AddDataAddress //��Ա����غ�����ƫ������ͨ��IDA�ɻ���йز�������ȱʡֵΪ0
			);
		usrHookDFCF[1].HookApi();
		*/

		// call link  QDataEngine::WriteCapitalFlowKLineData--->sub_100352F0-->sub_100395C0-->sub_100399B0  0x10039A91--->memcpy_s
		int call_address_of_memcpy_s = 0x10039A91;
		usrHookDFCF[2].InitHook("datacenter.dll",
			"?WriteCapitalFlowKLineData@QDataEngine@@SAJEW4DCYCLE@@ABV?$basic_string@_WU?$char_traits@_W@std@@V?$allocator@_W@2@@std@@PAUCAPITALFLOW_DAY_ITEM_DATA@@HAAH@Z", //����ȡ��ģ�����ֺͺ�������
			(PVOID*)Hookmemcpy_s, //����ָ��  WriteCapitalFlowKLineData(char, int, int, void *, int, int)
			call_address_of_memcpy_s - WriteCapitalFlowKLineData_entrence //��Ա����غ�����ƫ������ͨ��IDA�ɻ���йز�������ȱʡֵΪ0
		);
		usrHookDFCF[2].HookApi(false);
		// */

		//CDataMgr::GetOneStkInfo(CDataMgr *this, char a2, char a3)
		//usrHookDFCF[2].InitHook("datacenter.dll",
		//		"?GetOneStkInfo@CDataMgr@@QAEPAUSTK_PER@@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@D@Z", //����ȡ��ģ�����ֺͺ�������
		//		(PVOID*)GetCurStockCode, //����ָ�� 
		//		0x050A6A84 - 0X050A69D0  //��Ա����غ�����ƫ������ͨ��IDA�ɻ���йز�������ȱʡֵΪ0
		//	);
		//usrHookDFCF[2].HookApi(false);//���ڿ�ε���  �Ǳ��ص���

		return;
		
	}
	//����__thiscall���thisָ�����Ч��������
	//int __cdecl QDataEngine::WriteCapitalFlowKLineData (char, int, int, void *, int, int)
	static int __cdecl  HookWriteCapitalFlowKLineData(char a0, int a1, int a2, void *pCap , int nCount, int a4)
	{
		typedef int(__cdecl *fp)(char, int, int, void *, int, int);

		PCWSTR  pszCaption = L"RingSun Aplication";

		// Send the string to the main dialog box
		COPYDATASTRUCT cdsCaptical = { 0x101, (nCount + 1) , pCap };

		FORWARD_WM_COPYDATA(FindWindow(NULL, pszCaption),
			NULL, &cdsCaptical, SendMessage);

		return 1;
	}
	

	//���ض�memcpy_s���ã������ͳ�
	static int __cdecl Hookmemcpy_s(void *Dst, rsize_t DstSize, const void *Src, rsize_t MaxCount)
	{
		PCWSTR  pszCaption = L"RingSun Aplication";

		// Send the string to the main dialog box
		COPYDATASTRUCT cdsCaptical = { 0x101, (MaxCount + 1) , (PVOID)Src };

		FORWARD_WM_COPYDATA(FindWindow(NULL, pszCaption),
			NULL, &cdsCaptical, SendMessage);

		memcpy_s(Dst, DstSize, Src, MaxCount);//ִ�б������ᵼ��dfcfֱ���˳����Ƿ��Ӧ�õı������ƣ���
		return 1;
	}

	//���ض�char *__cdecl strncpy(char *, const char *, size_t)���ã���ȡ��ǰstockcode
	//int __thiscall CDataMgr::GetOneStkInfo(CDataMgr *this, char a2, char a3)
	//�ɻ��dfcfĿǰ���ڴ���Ĺ�Ʊ��ָ���Ĵ��룬���÷ǳ�Ƶ��
	static char * __cdecl GetCurStockCode(char *szDest, const char *szSrc, size_t nCount)
	{
		PCWSTR  pszCaption = L"RingSun Aplication";
		
		g_nCurStockCode = atoi(szSrc);

		// Send the stock code  to the main dialog box  ������ǰ���ֽڵ�����
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

			// Send the stock code  to the main dialog box  ������ǰ���ֽڵ�����
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

//������ת���������

//�����������봦����  ���ñ���ȡ�����е�ѭ��ʵ������������������
//class CFUNCTION_OUT_IN {
//public:
//	 DWORD	pOutFrom , pInTo ;//���������������ַ
//	 char	*szModuleName, *szFuncName;//ģ��ͺ�����
//	 BYTE    *pbytOrigEntryCode ;//ԭ������ڴ���ָ����
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
//			//�ָ��������Զ����е�һϵ�ж�ջ��������
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
//			push 0x12345678;//0x12345678Ҫ��ʵ�ʵķ��ص�ַ�滻
//			ret
//		}
//	}
//
//	BOOL HookApi()
//	{
//		BOOL    IsSuccess = FALSE;
//		DWORD   TempProtectVar;              //��ʱ�������Ա���
//		MEMORY_BASIC_INFORMATION MemInfo = { 0 };    //�ڴ��ҳ������Ϣ
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
//				if (nRetry<nRetryCount)       //�޸�ҳ��Ϊ��д
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
//							MemInfo.RegionSize, MemInfo.Protect, &TempProtectVar))   //�Ļ�ԭ����
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
//		DWORD   TempProtectVar;              //��ʱ�������Ա���
//		MEMORY_BASIC_INFORMATION MemInfo = { 0 };    //�ڴ��ҳ������Ϣ
//		int nRetry = 0, nRetryCount = 5;
//
//		if (!pOutFrom)
//			return IsSuccess;
//
//		//��ֹ�ڴ治�ܷ��ʵ���ʧ��
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
//				//��ֹ�ڴ治�ܷ��ʵ���ʧ��
//				while (nRetry<nRetryCount
//					&& !VirtualProtect(MemInfo.BaseAddress, MemInfo.RegionSize, PAGE_READWRITE, &MemInfo.Protect))
//				{
//					Sleep(20);
//					nRetry++;
//				}
//
//				if (nRetry<nRetryCount)                            //�޸�ҳ��Ϊ��д
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
//						MemInfo.RegionSize, MemInfo.Protect, &TempProtectVar))   //�Ļ�ԭ����
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
