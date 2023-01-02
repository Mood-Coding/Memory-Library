#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include "ProcessModules.h"

uintptr_t Meme::Process::GetModuleBaseAddress( DWORD pid, const wchar_t* module_name )
{
	HANDLE hSnap = CreateToolhelp32Snapshot( TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, pid );
	if (hSnap == INVALID_HANDLE_VALUE)
	{
		std::cerr << "[!] [Meme::Process::GetModuleBaseAddress] CreateToolhelp32Snapshot " << GetLastError() << '\n';
		return 0;
	}

	uintptr_t moduleBaseAddress = 0;
	MODULEENTRY32 modEntry{};
	modEntry.dwSize = sizeof( modEntry );

	if (Module32First( hSnap, &modEntry ))
	{
		do
		{
			// Find module with the name specified by module_name argument
			// 0 means 2 strings are identical
			if (_wcsicmp( modEntry.szModule, module_name ) == 0) 
			{
				moduleBaseAddress = (uintptr_t)modEntry.modBaseAddr;
				break;
			}
		}
		while (Module32Next( hSnap, &modEntry ));
	}
	else
	{
		std::cerr << "[!] [Meme::Process::GetModuleBaseAddress] Module32First " << GetLastError() << '\n';
	}

	CloseHandle( hSnap );
	return moduleBaseAddress;
}