/******************************************************************************
Module:  APIHook.cpp
Notices: Copyright (c) 2008 Jeffrey Richter & Christophe Nasarre
******************************************************************************/

#include "..\CommonFiles\CmnHdr.h"
#include <ImageHlp.h>
#pragma comment(lib, "ImageHlp")
#include <malloc.h>        // For alloca
#include <tlhelp32.h> //toolhelp API 头文件
#include "..\CommonFiles\Toolhelp.h"
#include <StrSafe.h>


//读取DFCF专用dll函数地址结构体
typedef struct tagDFCFDLLFUNCADDRESS {
	wchar_t pszModName[124];
	wchar_t pszFuncName[128];
	PROC dwAddress;
}DFCFDLLFUNCADDRESS;

#ifdef UNICODE
#define InjectLib InjectLibW
#define EjectLib  EjectLibW
#else
#define InjectLib InjectLibA
#define EjectLib  EjectLibA
#endif   // !UNICODE


class CAPIHook {
public:
	// Hook a function in all modules  
	CAPIHook(STRSAFE_LPWSTR pszCalleeModName, STRSAFE_LPWSTR pszInjDllName) {

		m_pNext = sm_pHead;    // The next node was at the head
		sm_pHead = this;        // This node is now at the head


		m_dwThreadId = FindApp(pszCalleeModName);
		m_szInjLibName = pszInjDllName;
		if (m_dwThreadId == 0) {
			// A process ID of 0 causes everything to take place in the 
			// local process; this makes things easier for debugging.
			m_dwThreadId = GetCurrentProcessId();
			LoadLibraryA("readdfcf.dll");
		}
		RemoteInjectLoadLibrary(m_dwThreadId, pszInjDllName);
	}

	// Unhook a function from all modules
	~CAPIHook() {

		// Remove this object from the linked list
		CAPIHook* p = sm_pHead;
		if (p == this) {     // Removing the head node
			sm_pHead = p->m_pNext;
		}
		else
		{

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

		EjectLibW(m_dwThreadId, m_szInjLibName);

	}

	// Returns the original address of the hooked function
	operator PROC() { return(m_pfnOrig); }

	// Hook module w/CAPIHook implementation?
	// I have to make it static because I need to use it 
	// in ReplaceIATEntryInAllMods
	static BOOL ExcludeAPIHookMod;


public:
	BOOL WINAPI InjectDfcfW(DWORD dwProcessId,
		PCWSTR pszLibFile)
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
			PTHREAD_START_ROUTINE pfnThreadRtn = (PTHREAD_START_ROUTINE)
				GetProcAddress(GetModuleHandle(TEXT("Kernel32")), "LoadLibraryW");


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

	BOOL WINAPI EjectLibW(DWORD dwProcessId, PCWSTR pszLibFile) {

		BOOL bOk = FALSE; // Assume that the function fails
		HANDLE hthSnapshot = NULL;
		HANDLE hProcess = NULL, hThread = NULL;

		__try {
			// Grab a new snapshot of the process
			hthSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, dwProcessId);
			if (hthSnapshot == INVALID_HANDLE_VALUE) __leave;

			// Get the HMODULE of the desired library
			MODULEENTRY32W me = { sizeof(me) };
			BOOL bFound = FALSE;
			BOOL bMoreMods = Module32FirstW(hthSnapshot, &me);
			for (; bMoreMods; bMoreMods = Module32NextW(hthSnapshot, &me)) {
				bFound = (_wcsicmp(me.szModule, pszLibFile) == 0) ||
					(_wcsicmp(me.szExePath, pszLibFile) == 0);
				if (bFound) break;
			}
			if (!bFound) __leave;

			// Get a handle for the target process.
			hProcess = OpenProcess(
				PROCESS_QUERY_INFORMATION |
				PROCESS_CREATE_THREAD |
				PROCESS_VM_OPERATION,  // For CreateRemoteThread
				FALSE, dwProcessId);
			if (hProcess == NULL) __leave;

			// Get the real address of FreeLibrary in Kernel32.dll
			PTHREAD_START_ROUTINE pfnThreadRtn = (PTHREAD_START_ROUTINE)
				GetProcAddress(GetModuleHandle(TEXT("Kernel32")), "FreeLibrary");
			if (pfnThreadRtn == NULL) __leave;

			// Create a remote thread that calls FreeLibrary()
			hThread = CreateRemoteThread(hProcess, NULL, 0,
				pfnThreadRtn, me.modBaseAddr, 0, NULL);
			if (hThread == NULL) __leave;

			// Wait for the remote thread to terminate
			WaitForSingleObject(hThread, INFINITE);

			bOk = TRUE; // Everything executed successfully
		}
		__finally { // Now we can clean everything up

			if (hthSnapshot != NULL)
				CloseHandle(hthSnapshot);

			if (hThread != NULL)
				CloseHandle(hThread);

			if (hProcess != NULL)
				CloseHandle(hProcess);
		}

		return(bOk);
	}

	BOOL WINAPI EjectLibA(DWORD dwProcessId, PCSTR pszLibFile) {

		// Allocate a (stack) buffer for the Unicode version of the pathname
		SIZE_T cchSize = lstrlenA(pszLibFile) + 1;
		PWSTR pszLibFileW = (PWSTR)
			_alloca(cchSize * sizeof(wchar_t));

		// Convert the ANSI pathname to its Unicode equivalent
		StringCchPrintfW(pszLibFileW, cchSize, L"%S", pszLibFile);

		// Call the Unicode version of the function to actually do the work.
		return(EjectLibW(dwProcessId, pszLibFileW));
	}

	void RemoteInjectLoadLibrary(DWORD dwProcessId, TCHAR *pszModName)
	{
		if (dwProcessId == 0) {
			// A process ID of 0 causes everything to take place in the 
			// local process; this makes things easier for debugging.
			dwProcessId = GetCurrentProcessId();
		}

		TCHAR szLibFile[MAX_PATH];
		GetModuleFileName(NULL, szLibFile, _countof(szLibFile));
		PTSTR pFilename = _tcsrchr(szLibFile, TEXT('\\')) + 1;
		//_tcscpy_s(pFilename, _countof(szLibFile) - (pFilename - szLibFile),
		//	TEXT("readDFCF.dll"));  //确定进行远程注入的DLL文件路径

		_tcscpy_s(pFilename, _countof(szLibFile) - (pFilename - szLibFile),
			pszModName);  //确定进行远程注入的DLL文件路径

		if (InjectDfcfW(dwProcessId, szLibFile)) {
			//chMB("DLL Injection/Ejection successful.");
		}
		else {
			//chMB("DLL Injection/Ejection failed.");
		}
	}

	//远程运行dfcf工作DLL的接口函数获得目标函数的真实地址
	PTHREAD_START_ROUTINE WINAPI ReadDfcfDLLFuncAddress(DWORD dwProcessId,
		wchar_t* pszLibFile, wchar_t* pszFuncName)
	{
		BOOL bOk = FALSE; // Assume that the function fails
		HANDLE hProcess = NULL, hThread = NULL;
		PWSTR pszLibFileRemote = NULL;
		PTHREAD_START_ROUTINE pfnThreadRtn = NULL;

		__try {
			// Get a handle for the target process.
			hProcess = OpenProcess(
				PROCESS_QUERY_INFORMATION |   // Required by Alpha
				PROCESS_CREATE_THREAD |   // For CreateRemoteThread
				PROCESS_VM_OPERATION |   // For VirtualAllocEx/VirtualFreeEx
				PROCESS_VM_WRITE,             // For WriteProcessMemory
				FALSE, dwProcessId);
			if (hProcess == NULL) __leave;

			// Get the real address of ReadDfcfDLLFuncAddress in readDFCF.dll ReadDfcfDLLFuncAddress  _ReadDfcfDLLFuncAddress@8

			HMODULE  hReadDFCF = GetModuleHandle(TEXT("readDFCF.dll"));
			if (NULL == hReadDFCF)
				hReadDFCF = LoadLibrary(TEXT("readDFCF.dll"));

			pfnThreadRtn = (PTHREAD_START_ROUTINE)
				GetProcAddress(hReadDFCF, "_ReadDfcfDLLFuncAddress@4");


			if (pfnThreadRtn == NULL) __leave;

			DFCFDLLFUNCADDRESS  usrDFCFDllFuncAddress = { 0 }, *usrRemoteDFCFDllFuncAddress;

			usrDFCFDllFuncAddress.dwAddress = 0;
			wcscpy_s(&usrDFCFDllFuncAddress.pszModName[0], 124, pszLibFile);
			wcscpy_s(&usrDFCFDllFuncAddress.pszFuncName[0], 128, pszFuncName);


			// Allocate space in the remote process for the pathname
			usrRemoteDFCFDllFuncAddress = (DFCFDLLFUNCADDRESS *)
				VirtualAllocEx(hProcess, NULL, sizeof(DFCFDLLFUNCADDRESS), MEM_COMMIT, PAGE_READWRITE);
			if (usrRemoteDFCFDllFuncAddress == NULL) __leave;

			// Copy the DLL's pathname and function name  to the remote process' address space
			if (!WriteProcessMemory(hProcess, usrRemoteDFCFDllFuncAddress,
				(PVOID)&usrDFCFDllFuncAddress, sizeof(DFCFDLLFUNCADDRESS), NULL)) __leave;

			// Create a remote thread that calls LoadLibraryW(DLLPathname)  
			//远程注入readDFCF,进入DFCF地址空间，安装关注的API钩子截取数据
			//调用带参数的readDFCF导出函数接收关心的数据
			hThread = CreateRemoteThread(hProcess, NULL, 0,
				pfnThreadRtn, usrRemoteDFCFDllFuncAddress, 0, NULL);
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

		return(pfnThreadRtn);

	}

	///////////////////////////////////////////////////////////////////////////////
	//执行DFCF命令
	BOOL WINAPI DoDfcfCmd(PCWSTR pszLibFile, LPCSTR szFuncName)
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
				FALSE, FindApp(L"mainfree.exe"));
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

			// Get the real address of LoadLibraryW in pszLibFile
			PTHREAD_START_ROUTINE pfnThreadRtn = (PTHREAD_START_ROUTINE)
				GetProcAddress(GetModuleHandle(pszLibFile), szFuncName);
			pfnThreadRtn = (PTHREAD_START_ROUTINE)
				GetProcAddress(GetModuleHandle(L"Kernel32.dll"), "LoadLibraryW");


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
private:
	static PVOID sm_pvMaxAppAddr; // Maximum private memory address
	static CAPIHook* sm_pHead;    // Address of first object
	CAPIHook* m_pNext;            // Address of next  object

	PCSTR m_pszCalleeModName;     // Module containing the function (ANSI)
	PCSTR m_pszFuncName;          // Function name in callee (ANSI)
	PROC  m_pfnOrig;              // Original function address in callee
	PROC  m_pfnHook;              // Hook function address
	DWORD m_dwThreadId ;
	LPCWSTR m_szInjLibName ;
private:



	DWORD FindApp(LPCWSTR pszAppName)
	{
		// Get the list of modules in this process  
		DWORD  dwRet = NULL;

		HANDLE hToolHelp;
		hToolHelp = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		PROCESSENTRY32 process32;
		process32.dwSize = sizeof(process32);

		BOOL bReturn = Process32First(hToolHelp, &process32);
		while (bReturn)
		{
			if (lstrcmpiW(pszAppName, process32.szExeFile) == 0) 
			{
				dwRet = process32.th32ProcessID;
				break;
			}
			bReturn = Process32Next(hToolHelp, &process32);
		}

		CloseHandle(hToolHelp);
		return dwRet;
	}

private:
	// NOTE: This function must NOT be inlined
	static FARPROC GetProcAddressRaw(HMODULE hmod, PCSTR pszProcName) {

		return(::GetProcAddress(hmod, pszProcName));
	}
	// Returns address of replacement function if hooked function is requested
	FARPROC WINAPI GetProcAddress(HMODULE hmod, PCSTR pszProcName) {

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

};

