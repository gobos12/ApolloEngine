#pragma once

namespace CmdLineArgs
{
	/* Loops through cmd line args in project (under Preferences/Config Properties/Debugging) */
	VOID APOLLO_API ReadArguments();

	/* Compares arg str with all possible configurations for Engine */
	VOID APOLLO_API ReadArg(CONST WCHAR* argument);
}