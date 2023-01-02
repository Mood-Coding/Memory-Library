#pragma once

#include <Windows.h>

#ifndef PROCESSMEMORY_H

namespace Meme::Process
{
	/// <summary>
	/// Read data from process's memory and stores it in specified location
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="hProcess">A handle to the process</param>
	/// <param name="source">The address of the memory location to read from</param>
	/// <param name="destination">A pointer to the destination where the data will be stored</param>
	/// <returns>If the function succeeds, the return value is nonzero.<para/>
	///	If the function fails, the return value is 0 (zero).<para/>
	/// To get extended error information, call GetLastError.
	/// </returns>
	template<typename T>
	int ReadMemory( HANDLE hProcess, uintptr_t source, T* destination )
	{
		if (hProcess == nullptr)
			return false;

		return ReadProcessMemory( hProcess, (LPCVOID)source, (LPVOID)destination, sizeof( T ), nullptr );
	}

	/// <summary>
	/// Write data to the memory of a process from specified location
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="hProcess">A handle to the process</param>
	/// <param name="address">The address of memory location to write to</param>
	/// <param name="value">A pointer to the data source will be used to write</param>
	/// <returns>If the function succeeds, the return value is nonzero.<para/>
	///	If the function fails, the return value is 0 (zero).<para/>
	/// To get extended error information, call GetLastError.
	/// </returns>
	template<typename T>
	int WriteMemory( HANDLE hProcess, uintptr_t address, T* value )
	{
		if (hProcess == nullptr)
			return false;

		return WriteProcessMemory( hProcess, (LPVOID)address, (LPCVOID)value, sizeof( T ), nullptr );
	}
}

#endif // !PROCESSMEMORY_H