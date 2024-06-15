#include "Apollo.h"
#include "Window.h"

namespace Win32
{
	Win32::Window::Window(std::wstring className, HICON icon, WindowType type)
		: WinObject(className, icon), m_Type(type)
	{
		SetSize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
	}


	VOID Win32::Window::Initialize()
	{
		RECT desktop;
		const HWND hDesktop = GetDesktopWindow();
		GetWindowRect(hDesktop, &desktop);

		RECT R = { 0, 0, m_Size.cx, m_Size.cy };
		AdjustWindowRect(&R, m_Type, false);

		m_Handle = CreateWindow(m_Class.c_str(), 
								m_Class.c_str(), 
								m_Type,
								((desktop.right / 2) - (m_Size.cx / 2)),
								((desktop.bottom / 2) - (m_Size.cy / 2)),
								m_Size.cx, 
								m_Size.cy, 
								0,  // parent window
								0,  // menu window
								HInstance(), 
								(void*)this);

		ShowWindow(m_Handle, SW_SHOW);
		UpdateWindow(m_Handle);
	}

	LRESULT Win32::Window::MessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		return WinObject::MessageHandler(hWnd, msg, wParam, lParam);
	}
}
