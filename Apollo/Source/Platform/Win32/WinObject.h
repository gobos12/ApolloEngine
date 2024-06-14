#pragma once

namespace Win32
{
	class APOLLO_API WinObject
	{

	public:
		/* WinObject Constructor */
		WinObject(std::wstring className, HICON icon);

		/* WinObject Deconstructor */
		~WinObject();

		/* Registers a new Window Class */
		virtual VOID RegisterNewClass();

		/* Initalize WinObject */
		virtual VOID Initialize() = 0;

	protected:
		/* Initialize message handler */
		static LRESULT InitMessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

		/* Assign message handler to a WinObject */
		static LRESULT AssignMessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

		/* Message handler function for child objects */
		virtual LRESULT MessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	protected:
		std::wstring		m_Class;
		HICON				m_hIcon;
		HWND				m_Handle;

	public:  /* GETTERS */
		HWND Handle() { return m_Handle; }

	protected:  /* SETTERS */
		VOID Handle(HWND hWnd) { m_Handle = hWnd; }

	};
}