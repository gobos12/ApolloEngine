#include "Sample.h"
#include "Platform/Win32/WinEntry.h"

class Sample : public Win32::IApplication
{
public:
	VOID SetupGameSettings() { }

	VOID PreInitialize() { }

	/* Called to initialize BlankProject */
	VOID Initialize() { }

	/* Game Loop - called on a loop while BlankProject is running */
	VOID Update() { }
};

ENTRYAPP(Sample)