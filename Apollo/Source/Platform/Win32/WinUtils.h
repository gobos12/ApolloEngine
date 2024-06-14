#pragma once

#define DEFAULT_WIDTH 800
#define DEFAULT_HEIGHT 600

namespace Win32
{
	enum WindowType : DWORD
	{
		STATIC = WS_OVERLAPPED,
		RESIZEABLE = WS_SIZEBOX,
		POPUP = WS_POPUP
	};

	namespace Utils
	{

	}
}