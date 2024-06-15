#pragma once
#include <string>

class APOLLO_API Debug
{
private:
	static Debug* instance;

public:
	static Debug* Singleton() { return instance; }

	Debug();
	~Debug() { }

	static VOID Log(const WCHAR* fmt, ...);

	/* Returns directory location where log files are dumped */
	static std::wstring LogDirectory();

	/* returns name of log file */
	static std::wstring LogFile();

	/* Prints a line of '-' chars with no time string */
	static VOID LogSeparator();

	/* Checks to see if MTAIL is running. MTAIL isa a debug program that prints log statements during runtime. */
	static BOOL IsMTailRunning();

	/* Starts MTAIL application */
	static VOID StartMTail();
};