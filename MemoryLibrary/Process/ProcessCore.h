#pragma once
#include <Windows.h>

#ifndef PROCESSCORE_H

namespace Meme::Process
{
	/// <summary>
	/// Retrieve PID of a process with a given executable name
	/// </summary>
	/// <param name="process_name">Process executable name, ie. explorer.exe</param>
	/// <returns>PID</returns>
	DWORD GetProcessID( const wchar_t* process_name );
}

#endif // !PROCESSCORE_H

