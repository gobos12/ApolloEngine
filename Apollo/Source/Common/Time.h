#pragma once
#include <string>

namespace Time
{
	/* Get current time in string format */
	std::wstring APOLLO_API GetTime(BOOL stripped = FALSE);

	/* Get current date in string format */
	std::wstring APOLLO_API GetDate(BOOL stripped = FALSE);

	/* Get current date and time in string format */
	std::wstring APOLLO_API GetDateTimeStr(BOOL stripped = FALSE);
}