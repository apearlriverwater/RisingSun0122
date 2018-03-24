/******************************************************************************
Module:  APIHook.h
Notices: Copyright (c) 2008 Jeffrey Richter & Christophe Nasarre
******************************************************************************/
#pragma once
#include <windowsx.h>
#include <malloc.h>

typedef struct tagDFCFDLLFUNCADDRESS {
	wchar_t pszModName[124];
	HMODULE hModule;
	wchar_t pszFuncName[128];
	PROC dwAddress;
}DFCFDLLFUNCADDRESS;




class CAPIHook {
public:
   // Hook a function in all modules
   CAPIHook(LPCSTR pszCalleeModName, PCSTR pszFuncName, PROC pfnHook);

   // Unhook a function from all modules
   ~CAPIHook();

   // Returns the original address of the hooked function
   operator PROC() { return(m_pfnOrig); }

   // Hook module w/CAPIHook implementation?
   // I have to make it static because I need to use it 
   // in ReplaceIATEntryInAllMods
   static BOOL ExcludeAPIHookMod; 


public:
   // Calls the real GetProcAddress 
   static FARPROC WINAPI GetProcAddressRaw(HMODULE hmod, PCSTR pszProcName);

private:
   static PVOID sm_pvMaxAppAddr; // Maximum private memory address
   static CAPIHook* sm_pHead;    // Address of first object
   CAPIHook* m_pNext;            // Address of next  object

   LPCSTR m_pszCalleeModName;     // Module containing the function (ANSI)  应该保存实体而非指针？？？
   PCSTR m_pszFuncName;          // Function name in callee (ANSI)
   PROC  m_pfnOrig;              // Original function address in callee
   PROC  m_pfnHook;              // Hook function address
   
private:
   // Replaces a symbol's address in a module's import section
   static void WINAPI ReplaceIATEntryInAllMods(LPCSTR pszCalleeModName, 
      PROC pfnOrig, PROC pfnHook);

   // Replaces a symbol's address in all modules' import sections
   static void WINAPI ReplaceIATEntryInOneMod(LPCSTR pszCalleeModName, 
      PROC pfnOrig, PROC pfnHook, HMODULE hmodCaller);

   
   // Replaces a symbol's address in a module's export sections
   static void ReplaceEATEntryInOneMod(HMODULE hmod, PCSTR pszFunctionName, PROC pfnNew);

   BOOL WINAPI InjectLibW(DWORD dwProcessId,
	   PCWSTR pszLibFile,
	   LPCSTR pszProcName)
   {

	   BOOL bOk = FALSE; // Assume that the function fails
	   HANDLE hProcess = NULL, hThread = NULL;
	   PWSTR pszLibFileRemote = NULL;

	   __try {
		   // Get a handle for the target process.
		   hProcess = OpenProcess(
			   PROCESS_QUERY_INFORMATION |   // Required by Alpha
			   PROCESS_CREATE_THREAD |   // For CreateRemoteThread
			   PROCESS_VM_OPERATION |   // For VirtualAllocEx/VirtualFreeEx
			   PROCESS_VM_WRITE,             // For WriteProcessMemory
			   FALSE, dwProcessId);
		   if (hProcess == NULL) __leave;

		   // Calculate the number of bytes needed for the DLL's pathname
		   int cch = 1 + lstrlenW(pszLibFile);
		   int cb = cch * sizeof(wchar_t);

		   // Allocate space in the remote process for the pathname
		   pszLibFileRemote = (PWSTR)
			   VirtualAllocEx(hProcess, NULL, cb, MEM_COMMIT, PAGE_READWRITE);
		   if (pszLibFileRemote == NULL) __leave;

		   // Copy the DLL's pathname to the remote process' address space
		   if (!WriteProcessMemory(hProcess, pszLibFileRemote,
			   (PVOID)pszLibFile, cb, NULL)) __leave;

		   // Get the real address of LoadLibraryW in Kernel32.dll
		   /*PTHREAD_START_ROUTINE pfnThreadRtn = (PTHREAD_START_ROUTINE)
		   GetProcAddress(GetModuleHandle(TEXT("Kernel32")), "LoadLibraryW");*/

		   PTHREAD_START_ROUTINE pfnThreadRtn = (PTHREAD_START_ROUTINE)
			   GetProcAddress(GetModuleHandle(pszLibFile), pszProcName);
		   if (pfnThreadRtn == NULL) __leave;

		   // Create a remote thread that calls LoadLibraryW(DLLPathname)  
		   //远程注入readDFCF,进入DFCF地址空间，安装关注的API钩子截取数据
		   //调用带参数的readDFCF导出函数接收关心的数据
		   hThread = CreateRemoteThread(hProcess, NULL, 0,
			   pfnThreadRtn, pszLibFileRemote, 0, NULL);
		   if (hThread == NULL) __leave;

		   // Wait for the remote thread to terminate
		   WaitForSingleObject(hThread, INFINITE);

		   bOk = TRUE; // Everything executed successfully
	   }
	   __finally { // Now, we can clean everything up

				   // Free the remote memory that contained the DLL's pathname
		   if (pszLibFileRemote != NULL)
			   VirtualFreeEx(hProcess, pszLibFileRemote, 0, MEM_RELEASE);

		   if (hThread != NULL)
			   CloseHandle(hThread);

		   if (hProcess != NULL)
			   CloseHandle(hProcess);
	   }

	   return(bOk);
   }

   BOOL WINAPI InjectLibA(DWORD dwProcessId, PCSTR pszLibFile, LPCSTR pszProcName) {

	   // Allocate a (stack) buffer for the Unicode version of the pathname
	   SIZE_T cchSize = lstrlenA(pszLibFile) + 1;
	   PWSTR pszLibFileW = (PWSTR)
		   _alloca(cchSize * sizeof(wchar_t));

	   // Convert the ANSI pathname to its Unicode equivalent
	   StringCchPrintfW(pszLibFileW, cchSize, L"%S", pszLibFile);

	   // Call the Unicode version of the function to actually do the work.
	   return(InjectLibW(dwProcessId, pszLibFileW, pszProcName));
   }

private:
   // Used when a DLL is newly loaded after hooking a function
   static void    WINAPI FixupNewlyLoadedModule(HMODULE hmod, DWORD dwFlags);
   
   // Used to trap when DLLs are newly loaded
   static HMODULE WINAPI LoadLibraryA(PCSTR pszModulePath);
   static HMODULE WINAPI LoadLibraryW(PCWSTR pszModulePath);
   static HMODULE WINAPI LoadLibraryExA(PCSTR pszModulePath, 
      HANDLE hFile, DWORD dwFlags);
   static HMODULE WINAPI LoadLibraryExW(PCWSTR pszModulePath, 
      HANDLE hFile, DWORD dwFlags);

   // Returns address of replacement function if hooked function is requested
   static FARPROC WINAPI GetProcAddress(HMODULE hmod, PCSTR pszProcName);
   static void  DisplayDebugMsgW(LPWSTR szMsg);
   // 宽字符转窄字符
   static char *WideCharToAnsi(wchar_t *pWideChar)
   {
	   if (pWideChar == NULL)
	   {
		   return NULL;
	   }

	   char *pszBuf = NULL;
	   int needBytes = WideCharToMultiByte(CP_ACP, 0, pWideChar, -1, NULL, 0, NULL, NULL);
	   if (needBytes > 0)
	   {
		   pszBuf = new char[needBytes + 1];
		   ZeroMemory(pszBuf, (needBytes + 1) * sizeof(char));
		   WideCharToMultiByte(CP_ACP, 0, pWideChar, -1, pszBuf, needBytes, NULL, NULL);
	   }

	   return pszBuf;
   }
   
   // 窄字节转宽字节
   static wchar_t *AnsiCharToWide(char *pChar)
   {
	   if (pChar == NULL)
	   {
		   return NULL;
	   }

	   wchar_t *pszBuf = NULL;
	   int needWChar = MultiByteToWideChar(CP_ACP, 0, pChar, -1, NULL, 0);
	   if (needWChar > 0)
	   {
		   pszBuf = new wchar_t[needWChar + 1];
		   ZeroMemory(pszBuf, (needWChar + 1) * sizeof(wchar_t));
		   MultiByteToWideChar(CP_ACP, 0, pChar, -1, pszBuf, needWChar);
	   }

	   return pszBuf;
   }
private:
   // Instantiates hooks on these functions
   static CAPIHook sm_LoadLibraryA;
   static CAPIHook sm_LoadLibraryW;
   static CAPIHook sm_LoadLibraryExA;
   static CAPIHook sm_LoadLibraryExW;
   static CAPIHook sm_GetProcAddress;
};


//////////////////////////////// End of File //////////////////////////////////
