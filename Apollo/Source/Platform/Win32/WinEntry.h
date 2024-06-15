#include "Apollo.h"
#include "IApplication.h"
#include "Common/CmdLineArgs.h"

extern Win32::IApplication* EntryApplication();

int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	auto EntryApp = EntryApplication();

	GameSettings gameSettings;
	EntryApp->SetupGameSettings();

	CmdLineArgs::ReadArguments();
	Debug logger;

	EntryApp->PreInitialize();
	EntryApp->Initialize();

	MSG msg{ 0 };
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))  // if there are window messages, process them
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else 
		{
			EntryApp->Update();
		}
	}

	return 0;
}