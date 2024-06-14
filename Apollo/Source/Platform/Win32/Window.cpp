#include "Apollo.h"
#include "Window.h"

namespace Win32
{
	Win32::Window::Window(std::wstring className, HICON icon, WindowType type)
		: WinObject(className, icon)
	{
		
	}

	Win32::Window::~Window()
	{
	}

	VOID Win32::Window::Initialize()
	{
		return VOID();
	}

	LRESULT Win32::Window::MessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		return LRESULT();
	}
}
