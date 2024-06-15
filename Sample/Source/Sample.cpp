#include "Sample.h"
#include "Engine/Game.h"
#include "Platform/Win32/WinEntry.h"

class Sample : public Apollo::Game
{
public:
	Sample() { }

	~Sample() { }

	VOID SetupGameSettings();

	/* Called to initialize BlankProject */
	VOID Initialize() { }

	/* Game Loop - called on a loop while BlankProject is running */
	VOID Update() { }
};

ENTRYAPP(Sample)

VOID Sample::SetupGameSettings()
{
	GameSettings::SetGameName(IDS_GAMENAME);
	GameSettings::SetShortName(IDS_SHORTNAME);
}
