#include <iostream>
#define NOMINMAX
#include "MemeLibrary.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Thirdparty/doctest.h"

TEST_CASE( "Meme::Process ProcessCore" )
{
	CHECK( Meme::Process::GetProcessID( L"TestMemeLibrary.exe" ) == GetCurrentProcessId() );
}

TEST_CASE( "Meme::Process ProcessModules" )
{
	CHECK( Meme::Process::GetModuleBaseAddress( GetCurrentProcessId(), L"ntdll.dll" ) != 0 );
}

TEST_CASE( "Meme::Process ProcessMemory" )
{
	HANDLE hProcess = OpenProcess( PROCESS_ALL_ACCESS, false, GetCurrentProcessId() );

	int originalData = 10;
	int newData = 0;
	CHECK( Meme::Process::ReadMemory( hProcess, (uintptr_t)&originalData, &newData ) != 0 );
	CHECK( newData == originalData );

	int writeData = 69;
	CHECK( Meme::Process::WriteMemory( hProcess, (uintptr_t)&originalData, &writeData ) != 0 );
	CHECK( originalData == writeData );
}