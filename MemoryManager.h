#pragma once

#include <Windows.h>

#ifndef _MEMORYMANAGER_H_
#define _MEMORYMANAGER_H_

namespace MM
{
	template<typename T>
	static bool read(HANDLE hProcess, uintptr_t source, T* destination)
	{
		if (!hProcess)
			return 0;

		return ReadProcessMemory(hProcess, (LPCVOID)source, (LPVOID)destination, sizeof(T), NULL);
	}

	template<typename T>
	static bool write(HANDLE hProcess, uintptr_t address, T* value)
	{
		if (!hProcess)
			return 0;

		return WriteProcessMemory(hProcess, (LPVOID)address, (LPCVOID)value, sizeof(T), NULL);
	}
};

#endif //_MEMORYMANAGER_H_