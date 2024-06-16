#pragma once

/* Contains necessary #include statements for the Apollo Engine */

#include "Core/Definitions.h"
#include "Core/GameSettings.h"

#include "Engine/OEngine.h"

#include "Common/Time.h"
#include "Common/Debug.h"

#ifdef WIN32
	#include "Platform/Win32/WinUtils.h"
	#include "Platform/Win32/WinObject.h"
	#include "Platform/Win32/Window.h"
	#include "Platform/Win32/IApplication.h"
#endif