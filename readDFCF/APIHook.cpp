/******************************************************************************
Module:  APIHook.cpp
Notices: Copyright (c) 2008 Jeffrey Richter & Christophe Nasarre
******************************************************************************/


#include "..\CommonFiles\CmnHdr.h"
#include <ImageHlp.h>
#include <tlhelp32.h>

#pragma comment(lib, "ImageHlp")
#include <malloc.h>        // For alloca
#include "APIHook.h"
#include "..\CommonFiles\Toolhelp.h"
#include <StrSafe.h>


/////////////////////////////////////////////////////////////////////////////////


// The head of the linked-list of CAPIHook objects
CAPIHook* CAPIHook::sm_pHead = NULL;

// By default, the module containing the CAPIHook() is not hooked
BOOL CAPIHook::ExcludeAPIHookMod = TRUE; 


// Handle unexpected exceptions if the module is unloaded
LONG WINAPI InvalidReadExceptionFilter(PEXCEPTION_POINTERS pep) {

	// handle all unexpected exceptions because we simply don't patch
	// any module in that case
	LONG lDisposition = EXCEPTION_EXECUTE_HANDLER;

	// Note: pep->ExceptionRecord->ExceptionCode has 0xc0000005 as a value

	return(lDisposition);
}


///////////////////////////////////////////////////////////////////////////////
//不能使用？？？
void  CAPIHook::DisplayDebugMsgW(LPWSTR szMsg)
{
	wchar_t szBuf[2600];
	GetModuleFileNameW(NULL, szBuf, _countof(szBuf));
	wchar_t sz[3000];
	StringCchPrintfW(sz, _countof(sz),
		TEXT("[%4u - %s] debug information %s\r\n"),
		GetCurrentProcessId(), szBuf, szMsg);
	OutputDebugString(sz);
}



CAPIHook::CAPIHook(LPCSTR pszCalleeModName, PCSTR pszFuncName, PROC pfnHook) {
   m_pNext  = sm_pHead;    // The next node was at the head
   sm_pHead = this;        // This node is now at the head
   
   // Save information about this hooked function
   m_pszCalleeModName	= pszCalleeModName;
   m_pszFuncName		= pszFuncName;
   m_pfnHook            = pfnHook;
   HMODULE	hModule		= GetModuleHandleA(pszCalleeModName);
   m_pfnOrig            = GetProcAddressRaw(hModule, m_pszFuncName);

   HookApi((fnHookAddL2Detail*)m_pfnOrig, (fnHookAddL2Detail*)pfnHook);

   // If function does not exit,... bye bye
   // This happens when the module is not already loaded
   //if (m_pfnOrig != NULL)
   //{
	  // //ReplaceEATEntryInOneMod(hModule, pszFuncName, m_pfnHook);
	  // // Hook this function in all currently loaded modules  
	  // ReplaceIATEntryInAllMods(pszCalleeModName, m_pfnOrig, m_pfnHook);
   //}

   
}


///////////////////////////////////////////////////////////////////////////////


CAPIHook::~CAPIHook() {

   // Unhook this function from all modules
   ReplaceIATEntryInAllMods(m_pszCalleeModName, m_pfnHook, m_pfnOrig);

   // Remove this object from the linked list
   CAPIHook* p = sm_pHead; 
   if (p == this) {     // Removing the head node
      sm_pHead = p->m_pNext; 
   } else {

      BOOL bFound = FALSE;

      // Walk list from head and fix pointers
      for (; !bFound && (p->m_pNext != NULL); p = p->m_pNext) {
         if (p->m_pNext == this) { 
            // Make the node that points to us point to our next node
            p->m_pNext = p->m_pNext->m_pNext; 
            bFound = TRUE;
         }
      }
   }
}


///////////////////////////////////////////////////////////////////////////////


// NOTE: This function must NOT be inlined
FARPROC CAPIHook::GetProcAddressRaw(HMODULE hmod, PCSTR pszProcName) {

   return(::GetProcAddress(hmod, pszProcName));
}


///////////////////////////////////////////////////////////////////////////////


// Returns the HMODULE that contains the specified memory address
static HMODULE ModuleFromAddress(PVOID pv) {

   MEMORY_BASIC_INFORMATION mbi;
   return((VirtualQuery(pv, &mbi, sizeof(mbi)) != 0) 
      ? (HMODULE) mbi.AllocationBase : NULL);
}


///////////////////////////////////////////////////////////////////////////////
/*
	对于导出函数，直接替换其入口函数
*/
void CAPIHook::ReplaceEATEntryInOneMod(HMODULE hmod, PCSTR pszFunctionName,PROC pfnNew) 
{
	// Get the address of the module's export section
	ULONG ulSize;

	PIMAGE_EXPORT_DIRECTORY pExportDir = NULL;
	__try {
		pExportDir = (PIMAGE_EXPORT_DIRECTORY)ImageDirectoryEntryToData(
			hmod, TRUE, IMAGE_DIRECTORY_ENTRY_EXPORT, &ulSize);
	}
	__except (InvalidReadExceptionFilter(GetExceptionInformation())) {
		// Nothing to do in here, thread continues to run normally
		// with NULL for pExportDir 
	}

	if (pExportDir == NULL)
		return;  // This module has no export section or is unloaded

	PDWORD pdwNamesRvas = (PDWORD)((PBYTE)hmod + pExportDir->AddressOfNames);//导出函数名字开始地址

	PWORD pdwNameOrdinals = (PWORD)
		((PBYTE)hmod + pExportDir->AddressOfNameOrdinals);//导出函数序号开始地址

	PDWORD pdwFunctionAddresses = (PDWORD)
		((PBYTE)hmod + pExportDir->AddressOfFunctions);//导出函数开始地址，序加dwBase才是真实地址
	

	// Walk the array of this module's function names 
	for (DWORD n = 0; n < pExportDir->NumberOfNames; n++) {
		// Get the function name
		PSTR pszFuncName = (PSTR)((PBYTE)hmod + pdwNamesRvas[n]);

		// If not the specified function, try the next function
		if (lstrcmpiA(pszFuncName, pszFunctionName) != 0) continue;

		// Get the address of this function's address
		PROC* ppfn = (PROC*)&pdwFunctionAddresses[n];  //old function RVA address pointer  加入基址???hmod
		PROC  pOriginalFunc = *ppfn;//原来函数地址RVA
		// Turn the new address into an RVA
		pfnNew = (PROC)((PBYTE)pfnNew - (PBYTE)hmod); //不同基准，能转换？？？ 减 dwBase  IAT 不减

		// Replace current function address with new function address
		/*if (!WriteProcessMemory(GetCurrentProcess(), ppfn, &pfnNew,
			sizeof(pfnNew), NULL) && (ERROR_NOACCESS == GetLastError())) */
		{
			//如果写入进程地址失败，开启有关权限后在写
			DWORD dwOldProtect;
			//修改内存属性成功时函数返回非0，修改失败时返回0
			if (VirtualProtect(ppfn, sizeof(pfnNew), PAGE_WRITECOPY,&dwOldProtect)) 
			{
				//非零值代表成功  地址没有更改，实际效果出不来todo 20171217
				if (WriteProcessMemory(GetCurrentProcess(), ppfn, &pfnNew, sizeof(pfnNew), NULL))
				{
					char  sBuf[512] = { 0 };
				
					sprintf_s(sBuf, "[%d]函数【%s】新旧地址替换成功[%x,%x，%x]",
						n,pszFuncName, pfnNew, pOriginalFunc,*ppfn);
					chMB(sBuf);
				}

				VirtualProtect(ppfn, sizeof(pfnNew), dwOldProtect, &dwOldProtect);
				
			}
		}
		break;  // We did it, get out
	}

}

//pszCalleeModName被调用的模块
void CAPIHook::ReplaceIATEntryInAllMods(LPCSTR pszCalleeModName, 
   PROC pfnCurrent, PROC pfnNew) 
{
   HMODULE hmodThisMod =( ExcludeAPIHookMod 
      ? ModuleFromAddress(ReplaceIATEntryInAllMods) : NULL);

   // Get the list of modules in this process   CToolhelp objToolHelp(TH32CS_SNAPMODULE, GetCurrentProcessId());
   wchar_t szModName[2048] = {0}, szMyModName[2048] = { 0 };

   HANDLE hToolHelp;
   hToolHelp = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, 0);
   MODULEENTRY32 me32;
   me32.dwSize = sizeof(MODULEENTRY32);

   //遍历全部模块，ReplaceIATEntryInOneMod函数判断当前模块是否调用指定的模块pszCalleeModName
   //在此不区分当前模块，如有需要（测试时）当前模块也hook
   for (BOOL bOk = Module32First(hToolHelp, &me32); bOk; bOk = Module32Next(hToolHelp, &me32))
   {
	   //if (lstrcmpiW(me32.szModule, pszCalleeModName) != 0)
	   {
		   ReplaceIATEntryInOneMod(pszCalleeModName, pfnCurrent, pfnNew, me32.hModule);
	   //{
		  // //导出函数不能拦截
		  // //MessageBoxW(GetActiveWindow(), me32.szModule, L"dfcf finds datacenter module", MB_OK);
		  // /*char szBuf[128] = { 0 };
		  // sprintf_s(szBuf,"original address :%x,hModule:%x", pfnCurrent, me32.hModule);
		  // chMB(szBuf);
		  // ReplaceEATEntryInOneMod(me32.hModule,"?Add_L2DetailData@QDataEngine@@SAJPADEKKPAUL2_TRANSACTION_PKG@@H@Z", pfnNew);*/
	   }
   }

   CloseHandle(hToolHelp);
   
}


///////////////////////////////////////////////////////////////////////////////



//对pszCalleeModName模块内部特定函数安装挂钩
void CAPIHook::ReplaceIATEntryInOneMod(LPCSTR pszCalleeModName, 
   PROC pfnCurrent, PROC pfnNew, HMODULE hmodCaller) {

   // Get the address of the module's import section
   ULONG ulSize;

   // An exception was triggered by Explorer (when browsing the content of 
   // a folder) into imagehlp.dll. It looks like one module was unloaded...
   // Maybe some threading problem: the list of modules from Toolhelp might 
   // not be accurate if FreeLibrary is called during the enumeration.
   PIMAGE_IMPORT_DESCRIPTOR pImportDesc = NULL;
   __try {
      pImportDesc = (PIMAGE_IMPORT_DESCRIPTOR) ImageDirectoryEntryToData(
         hmodCaller, TRUE, IMAGE_DIRECTORY_ENTRY_IMPORT, &ulSize);
   } 
   __except (InvalidReadExceptionFilter(GetExceptionInformation())) {
      // Nothing to do in here, thread continues to run normally
      // with NULL for pImportDesc 
   }
   
   if (pImportDesc == NULL)
      return;  // This module has no import section or is no longer loaded

   char  szBuf[8192] = { 0 };
   bool  bIsImported = false;
   
   

   // Find the import descriptor containing references to callee's functions
   for (; pImportDesc->Name; pImportDesc++) {

      PSTR pszCalledModule = (PSTR) ((PBYTE) hmodCaller + pImportDesc->Name);//指向被导入的模块名字
	  //chMB(pszCalledModule);
	  //导入指定模块的特定函数挂钩子  
      if (lstrcmpiA(pszCalledModule, pszCalleeModName) == 0) {
		  bIsImported = true;
		  char szTmp[260] = { 0 };
		  HMODULE	hModule = GetModuleHandleA(pszCalleeModName);
		  GetModuleFileNameA(hmodCaller, szTmp, 260);

		  wsprintfA(szBuf, "导入者【%s】\n", strrchr(szTmp, '\\') + 1);
		  
		  wsprintfA(strrchr(szBuf,0),"[%s]基址[%08x]被钩函数[%08x]\n ", 
			  pszCalleeModName, hModule,pfnCurrent);

         // Get caller's import address table (IAT) for the callee's functions
         PIMAGE_THUNK_DATA pThunk = (PIMAGE_THUNK_DATA) 
            ((PBYTE) hmodCaller + pImportDesc->FirstThunk);

         // Replace current function address with new function address
         for (; pThunk->u1.Function; pThunk++) {
			 
            // Get the address of the function address
            PROC* ppfn = (PROC*) &pThunk->u1.Function;
			wsprintfA(strrchr(szBuf, 0), "[%08x] ", ppfn);
            // Is this the function we're looking for?  远程注入时函数地址不一致的问题
            BOOL bFound = (*ppfn == pfnCurrent);
            if (bFound) {
				chMB("对指定模块的特定函数挂钩子");
				if (!WriteProcessMemory(GetCurrentProcess(), ppfn, &pfnNew, 
                    sizeof(pfnNew), NULL) && (ERROR_NOACCESS == GetLastError())) {
                  
				  DWORD dwOldProtect;
                  if (VirtualProtect(ppfn, sizeof(pfnNew), PAGE_WRITECOPY, 
                     &dwOldProtect)) {

                     WriteProcessMemory(GetCurrentProcess(), ppfn, &pfnNew, 
                        sizeof(pfnNew), NULL);
                     VirtualProtect(ppfn, sizeof(pfnNew), dwOldProtect, 
                        &dwOldProtect);
                  }
               }
				return;  // We did it, get out
            }
         }
      }  // Each import section is parsed until the right entry is found and patched
   }
   if(bIsImported)
		chMB(szBuf);
}



void CAPIHook::FixupNewlyLoadedModule(HMODULE hmod, DWORD dwFlags) {

   // If a new module is loaded, hook the hooked functions
   if ((hmod != NULL) &&   // Do not hook our own module
       (hmod != ModuleFromAddress(FixupNewlyLoadedModule)) && 
       ((dwFlags & LOAD_LIBRARY_AS_DATAFILE) == 0) &&
       ((dwFlags & LOAD_LIBRARY_AS_DATAFILE_EXCLUSIVE) == 0) &&
       ((dwFlags & LOAD_LIBRARY_AS_IMAGE_RESOURCE) == 0)
       ) {

      for (CAPIHook* p = sm_pHead; p != NULL; p = p->m_pNext) {
         if (p->m_pfnOrig != NULL) {
            ReplaceIATEntryInAllMods(p->m_pszCalleeModName, 
               p->m_pfnOrig, p->m_pfnHook);  
         } else {
#ifdef _DEBUG
            // We should never end up here 
            wchar_t szPathname[MAX_PATH];
            GetModuleFileNameW(NULL, szPathname, _countof(szPathname));
            wchar_t sz[1024];
            StringCchPrintfW(sz, _countof(sz), 
               TEXT("[%4u - %s] impossible to find %S\r\n"), 
               GetCurrentProcessId(), szPathname, p->m_pszCalleeModName);
            OutputDebugString(sz);
#endif
         }
      }
   }
}


///////////////////////////////////////////////////////////////////////////////


HMODULE WINAPI CAPIHook::LoadLibraryA(PCSTR pszModulePath) {

   HMODULE hmod = ::LoadLibraryA(pszModulePath);
   FixupNewlyLoadedModule(hmod, 0);
   return(hmod);
}


///////////////////////////////////////////////////////////////////////////////


HMODULE WINAPI CAPIHook::LoadLibraryW(PCWSTR pszModulePath) {

   HMODULE hmod = ::LoadLibraryW(pszModulePath);
   FixupNewlyLoadedModule(hmod, 0);
   return(hmod);
}


///////////////////////////////////////////////////////////////////////////////


HMODULE WINAPI CAPIHook::LoadLibraryExA(PCSTR pszModulePath, 
   HANDLE hFile, DWORD dwFlags) {

   HMODULE hmod = ::LoadLibraryExA(pszModulePath, hFile, dwFlags);
   FixupNewlyLoadedModule(hmod, dwFlags);
   return(hmod);
}


///////////////////////////////////////////////////////////////////////////////


HMODULE WINAPI CAPIHook::LoadLibraryExW(PCWSTR pszModulePath, 
   HANDLE hFile, DWORD dwFlags) {

   HMODULE hmod = ::LoadLibraryExW(pszModulePath, hFile, dwFlags);
   FixupNewlyLoadedModule(hmod, dwFlags);
   return(hmod);
}


///////////////////////////////////////////////////////////////////////////////


FARPROC WINAPI CAPIHook::GetProcAddress(HMODULE hmod, PCSTR pszProcName) {

   // Get the true address of the function
   FARPROC pfn = GetProcAddressRaw(hmod, pszProcName);

   // Is it one of the functions that we want hooked?
   CAPIHook* p = sm_pHead;
   for (; (pfn != NULL) && (p != NULL); p = p->m_pNext) {

      if (pfn == p->m_pfnOrig) {

         // The address to return matches an address we want to hook
         // Return the hook function address instead
         pfn = p->m_pfnHook;
         break;
      }
   }

   return(pfn);
}


//////////////////////////////// End of File //////////////////////////////////
