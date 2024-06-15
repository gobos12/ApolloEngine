#pragma once

#include "WinObject.h"

#include <Uxtheme.h>
	#pragma comment(lib, "uxtheme.lib")

namespace Win32
{
	class APOLLO_API Window : public Win32::WinObject
	{
	public:
		/* Window Constructor */
		Window(std::wstring className, HICON icon, WindowType type = RESIZEABLE);

		/* Window Deconstructor */
		~Window() { }

		virtual VOID Initialize() override;

		virtual LRESULT MessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) override;

		VOID RedrawWindow();

		VOID OnNonClientCreate();

		VOID OnNonClientActivate(BOOL active);

		VOID OnNonClientPaint(HRGN region);

	protected:
		SIZE			m_Size;
		WindowType		m_Type;
		BOOL			m_IsActive;

	public: /* GETTERS */
		SIZE GetSize() { return m_Size; }

	protected: /* SETTERS */
		VOID SetSize(SIZE size) { m_Size = size; }
		VOID SetSize(INT cx, INT cy) { m_Size.cx = cx; m_Size.cy = cy; }
	};
}