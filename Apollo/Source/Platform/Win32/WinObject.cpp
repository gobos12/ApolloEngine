#include "Apollo.h"
#include "WinObject.h"

namespace Win32
{
	WinObject::WinObject(std::wstring className, HICON icon) : m_Class(className), m_hIcon(icon) { }

	WinObject::~WinObject() { }

	VOID WinObject::RegisterNewClass()
	{
		WNDCLASSEX wcex;

		wcex.cbSize = sizeof(WNDCLASSEX);
		wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;

		wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
		wcex.hbrBackground = (HBRUSH)(CreateSolidBrush(RGB(120, 163, 255))); // CORNFLOWER BLUE !!
		wcex.hIcon = m_hIcon;
		wcex.hIconSm = m_hIcon;

		wcex.lpszClassName = m_Class.c_str();
		wcex.lpszMenuName = nullptr;

		wcex.hInstance = HInstance();
		wcex.lpfnWndProc = InitMessageHandler;

		RegisterClassEx(&wcex);
	}

	LRESULT WinObject::InitMessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		if (msg == WM_NCCREATE)  // when non-client create message is sent, make a new pointer to the winobj we need
		{
			const CREATESTRUCTW* const pCreate = reinterpret_cast<CREATESTRUCTW*>(lParam);
			Win32::WinObject* const pWnd = static_cast<Win32::WinObject*>(pCreate->lpCreateParams);
			SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pWnd));
			SetWindowLongPtr(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&Win32::WinObject::AssignMessageHandler));
			pWnd->Handle(hWnd);
			return pWnd->MessageHandler(hWnd, msg, wParam, lParam); // pulls message handler from inherited winobjs
		}

		return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	LRESULT WinObject::AssignMessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		Win32::WinObject* const pWnd = reinterpret_cast<WinObject*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
		return pWnd->MessageHandler(hWnd, msg, wParam, lParam);
	}

	LRESULT WinObject::MessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}

}