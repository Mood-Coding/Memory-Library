#pragma once

#include <cstdint>
#include <iostream>
#include <Windows.h>

class Memory
{
	HANDLE hProcess;

public:
	Memory(DWORD ProcessID)
	{
		hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, ProcessID);
		if (hProcess)
		{
			std::cout << "<OpenProcess> Open a handle to " << ProcessID << " success!\n";
		}
		else
		{
			std::cout << "<OpenProcess> Error " << GetLastError() << '\n';
		}
	}

	~Memory()
	{
		if (CloseHandle(hProcess))
		{
			std::cout << "<CloseHandle> Success!\n";
		}
	}

	bool Read(uintptr_t ReadAddress, LPVOID ReadBuffer, SIZE_T ReadSize)
	{
		if (!ReadProcessMemory(hProcess, (LPCVOID)ReadAddress, ReadBuffer, ReadSize, NULL))
		{
			std::cout << "<ReadProcessMemory> Error " << GetLastError() << '\n';
			return false;
		}

		return true;
	}

	bool Write(uintptr_t WriteAddress, LPCVOID WriteBuffer, SIZE_T WriteSize)
	{
		if (WriteProcessMemory(hProcess, (LPVOID)WriteAddress, WriteBuffer, WriteSize, NULL))
		{
			std::cout << "<WriteProcessMemory> Error " << GetLastError() << '\n';
			return false;
		}

		return true;
	}

};

