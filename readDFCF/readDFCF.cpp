/******************************************************************************
Module:  readDFCF.cpp
Notices: Copyright (c) 2008 Jeffrey Richter & Christophe Nasarre
******************************************************************************/


#include "..\CommonFiles\CmnHdr.h"     /* See Appendix A. */
#include <WindowsX.h>
#include <tchar.h>
#include <stdio.h>
#include <StrSafe.h>
#include "APIHook.h"
#include "resource.h"
#include "readDFCF.h"

HINSTANCE g_hInstDll = NULL;


HOOKDATACENTER	g_HookDataCenter;



///////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////



// This function sends the MessageBox info to our main dialog box
void SendreadDFCF(BOOL bUnicode,
	PVOID pvCaption, PVOID pvText, int nResult) {

	// Get the pathname of the process displaying the message box
	wchar_t szProcessPathname[MAX_PATH];
	GetModuleFileNameW(NULL, szProcessPathname, MAX_PATH);

	// Convert the return value into a human-readable string
	PCWSTR pszResult = L"(Unknown)";
	

	// Construct the string to send to the main dialog box
	wchar_t sz[2048];
	StringCchPrintfW(sz, _countof(sz), bUnicode
		? L"1212Unicode  Process: (%d) %s\r\nCaption: %s\r\nMessage: %s\r\nResult: %s"
		: L"1234Common   Process: (%d) %s\r\nCaption: %S\r\nMessage: %S\r\nResult: %s",
		GetCurrentProcessId(), szProcessPathname,
		pvCaption, pvText, pszResult);

	// Send the string to the main dialog box
	COPYDATASTRUCT cds = { 0, ((DWORD)wcslen(sz) + 1) * sizeof(wchar_t), sz };
	FORWARD_WM_COPYDATA(FindWindow(NULL, TEXT("RingSun Aplication")),
		NULL, &cds, SendMessage);
}



///////////////////////////////////////////////////////////////////////////////


/*
todo:�����洰�����̫���ӣ��Ժ��о�20171213
����ΪԶ��ע����ʹ�ã�����Ŀ��Ӧ�õ����ģ��ĵ�ַ�����ƣ�����Ҫ�ԣ���
*/
BOOL WINAPI DllMain(HINSTANCE hInstDll, DWORD fdwReason, PVOID fImpLoad) {
	

	if (fdwReason == DLL_PROCESS_ATTACH) {
		//����ʱ���ɹ����̣߳�������ע��ģ�鵼�������Ĺҹ�  ??
		g_hInstDll = hInstDll;

	}
	else if (fdwReason == DLL_PROCESS_DETACH)
	{
		//����ʱ�˳��������ֳ�
	}

	return(TRUE);
}

//BOOL WINAPI GetModuleList(MODULEINFO *pModuleInfo) {
//
//	char szBuf[MAX_PATH * 100] = { 0 };
//
//	PBYTE pb = NULL;
//	MEMORY_BASIC_INFORMATION mbi;
//	int nLen;
//	char szModName[MAX_PATH];
//	int nCount = 0;
//
//	//��ѯ�����ڴ����
//	while (VirtualQuery(pb, &mbi, sizeof(mbi)) == sizeof(mbi)) {
//		if (mbi.State == MEM_FREE)
//			mbi.AllocationBase = mbi.BaseAddress;
//
//		if ((mbi.AllocationBase == g_hInstDll) ||
//			(mbi.AllocationBase != mbi.BaseAddress) ||
//			(mbi.AllocationBase == NULL)) {
//			// Do not add the module name to the list
//			// if any of the following is true:
//			// 1. If this region contains this DLL
//			// 2. If this block is NOT the beginning of a region
//			// 3. If the address is NULL
//			nLen = 0;
//		}
//		else {
//			nLen = GetModuleFileNameA((HINSTANCE)mbi.AllocationBase,
//				szModName, _countof(szModName));
//
//			if (nLen > 0) {
//				char *szFilename = strrchr(szModName, '\\') + 1;
//				//��ѯָ����ģ������
//				pModuleInfo[nCount].AllocationBase = mbi.AllocationBase;
//				wsprintfA(pModuleInfo[nCount++].szModName, "%s",szFilename);
//			}
//		}
//
//		pb += mbi.RegionSize;
//	}
//
//	return  true;
//
//}


// Handle unexpected exceptions if the module is unloaded
LONG WINAPI InvalidReadExceptionFilter(PEXCEPTION_POINTERS pep) {

	// handle all unexpected exceptions because we simply don't patch
	// any module in that case
	LONG lDisposition = EXCEPTION_EXECUTE_HANDLER;

	// Note: pep->ExceptionRecord->ExceptionCode has 0xc0000005 as a value

	return(lDisposition);
}


//////////////////////////////// End of File //////////////////////////////////
