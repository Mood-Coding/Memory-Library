#include <iostream>
#define NOMINMAX
#include "MemoryLibrary.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Thirdparty/doctest.h"

TEST_CASE( "Memory::Process ProcessCore" )
{
    CHECK( Memory::Process::GetProcessID( L"TestMemoryLibrary.exe" ) == GetCurrentProcessId() );
}

TEST_CASE( "Memory::Process ProcessModules" )
{
    CHECK( Memory::Process::GetModuleBaseAddress( GetCurrentProcessId(), L"ntdll.dll" ) != 0 );
}