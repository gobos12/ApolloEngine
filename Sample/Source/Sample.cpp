#include "Sample.h"

ENTRYAPP(Sample)

Sample::Sample()
{

}

Sample::~Sample()
{

}

VOID Sample::SetupGameSettings()
{
	GameSettings::SetGameName(IDS_GAMENAME);
	GameSettings::SetShortName(IDS_SHORTNAME);
}

VOID Sample::Initialize()
{

}

VOID Sample::Update()
{

}
