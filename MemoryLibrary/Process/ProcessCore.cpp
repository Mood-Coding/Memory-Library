#include "ProcessCore.h"
#include <TlHelp32.h>
#include <iostream>
#include <Windows.h>

DWORD Memory::Process::GetProcessID( const wchar_t* process_name )
{
	HANDLE hSnap = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, NULL );
	if (hSnap == INVALID_HANDLE_VALUE)
	{
#if _DEBUG
		std::cout << "[!] [Memory::Process::GetProcessID] CreateToolhelp32Snapshot " << GetLastError() << '\n';
#endif // _DEBUG
		return 0;
	}

	DWORD pid = 0;
	PROCESSENTRY32 pe{};
	pe.dwSize = sizeof( PROCESSENTRY32 );

	if (Process32First( hSnap, &pe ))
	{
		do
		{
			// Find process with the name specified by process_name argument
			// 0 means 2 strings are identical
			if (_wcsicmp( pe.szExeFile, process_name ) == 0)
			{
				pid = pe.th32ProcessID;
				break;
			}
		}
		while (Process32Next( hSnap, &pe ));
	}
	else
	{
#if _DEBUG
		std::cout << "[!] [Memory::Process::GetProcessID] Process32First " << GetLastError() << '\n';
#endif // _DEBUG
	}

	CloseHandle( hSnap );
	return pid;
}