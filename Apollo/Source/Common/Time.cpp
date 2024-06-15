#include "Apollo.h"
#include <ctime>
#include <sstream>
#include <iomanip>

// Unstripped = 00:00:00
// Stripped = 000000
std::wstring Time::GetTime(BOOL stripped)
{
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);
	std::wstringstream wss;
	wss << std::put_time(&ltm, L"%T");
	std::wstring timeStr = wss.str();

	if (stripped)
	{
		std::wstring chars = L":";
		for (WCHAR c : chars)
		{
			timeStr.erase(std::remove(timeStr.begin(), timeStr.end(), c), timeStr.end());
		}
	}

	return timeStr;
}

std::wstring Time::GetDate(BOOL stripped)
{
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);
	std::wstringstream wss;
	wss << std::put_time(&ltm, L"%d/%m/%y");
	std::wstring timeStr = wss.str();

	if (stripped)
	{
		std::wstring chars = L"/";
		for (WCHAR c : chars)
		{
			timeStr.erase(std::remove(timeStr.begin(), timeStr.end(), c), timeStr.end());
		}
	}

	return timeStr;
}

std::wstring Time::GetDateTimeStr(BOOL stripped)
{
	std::wstring timeStr = GetDate(stripped) + L" " + GetTime(stripped);

	if (stripped)
	{
		std::wstring chars = L" ";
		for (WCHAR c : chars)
		{
			timeStr.erase(std::remove(timeStr.begin(), timeStr.end(), c), timeStr.end());
		}
	}

	return timeStr;
}
