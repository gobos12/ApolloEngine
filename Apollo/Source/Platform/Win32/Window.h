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
		~Window();

		virtual VOID Initialize() override;
		virtual LRESULT MessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) override;

	protected:
		SIZE			m_Size;
		WindowType		m_Type;
		BOOL			m_IsActive;

	public: /* GETTERS */
		SIZE Size() { return m_Size; }

	protected: /* SETTERS */
		VOID Size(SIZE size) { m_Size = size; }
		VOID Size(INT cx, INT cy) { m_Size.cx = cx; m_Size.cy = cy; }
	};
}