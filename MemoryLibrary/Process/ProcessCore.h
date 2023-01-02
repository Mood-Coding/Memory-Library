#pragma once
#include <Windows.h>

#ifndef PROCESSCORE_H

namespace Memory::Process
{
	/// <summary>
	/// 
	/// </summary>
	/// <param name="process_name">Process executable name, ie explorer.exe</param>
	/// <returns>Process ID</returns>
	DWORD GetProcessID( const wchar_t* process_name );
}

#endif // !PROCESSCORE_H

