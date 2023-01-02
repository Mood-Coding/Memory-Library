#pragma once
#include <Windows.h>

#ifndef PROCESSMODULES_H

namespace Memory::Process
{
	/// <summary>
	/// Retrieves the base address of a module in a process
	/// with a given process ID and module name.
	/// </summary>
	/// <param name="pid">Target process ID</param>
	/// <param name="module_name">Module will be retrieved base address</param>
	/// <returns>Base address of module</returns>
	uintptr_t GetModuleBaseAddress( DWORD pid, const wchar_t* module_name );
}

#endif // !PROCESSMODULES_H