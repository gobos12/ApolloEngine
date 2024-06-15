#include "Apollo.h"
#include "Game.h"

namespace Apollo
{
	Game::Game() : Win32::Window(L"Game", NULL)
	{

	}

	VOID Game::PreInitialize()
	{
		Win32::Window::RegisterNewClass();
		Win32::Window::Initialize();
	}

	LRESULT Game::MessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		return Window::MessageHandler(hWnd, msg, wParam, lParam);
	}
}