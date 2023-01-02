#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include "ProcessModules.h"

uintptr_t Memory::Process::GetModuleBaseAddress( DWORD pid, const wchar_t* module_name )
{
	HANDLE hSnap = CreateToolhelp32Snapshot( TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, pid );
	if (hSnap == INVALID_HANDLE_VALUE)
	{
#if _DEBUG
		std::cout << "[!] [Memory::Process::GetModuleBaseAddress] CreateToolhelp32Snapshot " << GetLastError() << '\n';
#endif // _DEBUG
		return 0;
	}

	uintptr_t moduleBaseAddress = 0;
	MODULEENTRY32 modEntry{};
	modEntry.dwSize = sizeof( modEntry );

	if (Module32First( hSnap, &modEntry ))
	{
		do
		{
			// 0 mean string1 identical to string2
			if (_wcsicmp( modEntry.szModule, module_name ) == 0)
			{
				moduleBaseAddress = (uintptr_t)modEntry.modBaseAddr;
				break;
			}
		}
		while (Module32Next( hSnap, &modEntry ));
	}
	{
#if _DEBUG
		std::cout << "[!] [Memory::Process::GetProcessID] Module32First " << GetLastError() << '\n';
#endif // _DEBUG
	}

	CloseHandle( hSnap );
	return moduleBaseAddress;
}