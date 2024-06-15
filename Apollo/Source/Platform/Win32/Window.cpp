#include "Apollo.h"
#include "Window.h"

#define DCX_USESTYLE 0x00010000

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
		/* Client messages -> general, high-level messages to change the INSIDE of a window */
		/* Non-Client messages -> chances the window itself */

		switch (msg)
		{
		case WM_NCCREATE: { OnNonClientCreate(); } return TRUE;
		case WM_NCACTIVATE: { OnNonClientActivate(LOWORD(wParam) != WA_INACTIVE); } return TRUE;
		case WM_NCPAINT: { OnNonClientPaint((HRGN)wParam); } return FALSE;
		case WM_TIMER: { RedrawWindow(); } break;
		}

		return WinObject::MessageHandler(hWnd, msg, wParam, lParam);
	}

	VOID Window::RedrawWindow()
	{
		// Reset window
		SetWindowPos(Handle(), 0, 0, 0, 0, 0, 
			SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE | SWP_DRAWFRAME | SWP_FRAMECHANGED);

		SendMessage(Handle(), WM_PAINT, 0, 0);
	}

	VOID Window::OnNonClientCreate()
	{
		SetTimer(Handle(), 1, 100, NULL);
		SetWindowTheme(Handle(), L"", L"");
	}

	VOID Window::OnNonClientActivate(BOOL active)
	{
		m_IsActive = active;
	}

	VOID Window::OnNonClientPaint(HRGN region)
	{
		HDC hdc = GetDCEx(m_Handle, region, DCX_WINDOW | DCX_INTERSECTRGN | DCX_USESTYLE);
		RECT rect;
		GetWindowRect(Handle(), &rect);

		SIZE size = SIZE{ rect.right - rect.left, rect.bottom - rect.top };
		
		HBITMAP hbmMem = CreateCompatibleBitmap(hdc, size.cx, size.cy);
		HANDLE hold = SelectObject(hdc, hbmMem);

		HBRUSH brush = CreateSolidBrush(RGB(10, 20, 30));
		FillRect(hdc, new RECT{ 0, 0, size.cx, size.cy }, brush);
		DeleteObject(brush); // deallocate mem

		ReleaseDC(Handle(), hdc);
	}
}
