#include "Apollo.h"
#include "CmdLineArgs.h"
#include <algorithm>

VOID CmdLineArgs::ReadArguments()
{
	int argc = 0; // number of arguements
	LPWSTR* argv = CommandLineToArgvW(GetCommandLineW(), &argc);

	for (int i = 1; i < argc; ++i) // first cmd line argument is the url of the exe, so we start loop @ 1
	{
		std::wstring key = argv[i]; // very first string of argv
		if (key[0] == '-') // checks first char
		{
			key.erase(0, 1); //-mTail -> mTail
			std::transform(key.begin(), key.end(), key.begin(), ::tolower);
			ReadArg(key.c_str());
		}
	}
}

VOID CmdLineArgs::ReadArg(const WCHAR* argument)
{
	if (wcscmp(argument, L"mtail") == 0) Debug::StartMTail();
	if (wcscmp(argument, L"debug") == 0) Engine::SetMode(Engine::EngineMode::DEBUG);
	if (wcscmp(argument, L"editor") == 0) Engine::SetMode(Engine::EngineMode::EDITOR);
	if (wcscmp(argument, L"server") == 0) Engine::SetMode(Engine::EngineMode::SERVER);
}
