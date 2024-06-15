#include "Apollo.h"
#include "Game.h"

namespace Apollo
{
	Game::Game() : Win32::Window(L"Game", NULL) { }

	VOID Game::PreInitialize()
	{
		Debug::LogSeparator();
		Debug::Log(L"Application starting...\n");
		Debug::Log(L"Game Name: %s\n", GameSettings::GetGameName());
		Debug::Log(L"Boot Time: %s\n", Time::GetDateTimeStr().c_str());
		Debug::Log(L"Engine Mode: %s\n", Engine::EngineModeToString().c_str());
		Debug::LogSeparator();

		Win32::Window::RegisterNewClass();
		Win32::Window::Initialize();
	}

	LRESULT Game::MessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		return Window::MessageHandler(hWnd, msg, wParam, lParam);
	}
}