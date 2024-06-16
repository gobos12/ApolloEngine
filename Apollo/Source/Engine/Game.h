#pragma once

namespace Apollo
{
	/* Pre-built Game class that all Apollo projects should inherit from. */
	class APOLLO_API Game : public Win32::IApplication, public Win32::Window
	{
	public:
		Game();
		~Game() { }

		virtual VOID PreInitialize() override;
		virtual LRESULT MessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) override;
	};
}