#pragma once

#include <Windows.h>
#include <string>
#include "../resource.h"
#include "Core/Core.h"
#include "Engine/Game.h"
#include "Platform/Win32/WinEntry.h"

class Sample : public Apollo::Game
{
public:
	Sample();

	~Sample();

	VOID SetupGameSettings();

	/* Called to initialize BlankProject */
	VOID Initialize();

	/* Game Loop - called on a loop while BlankProject is running */
	VOID Update();
};