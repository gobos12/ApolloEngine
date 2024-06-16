#include "Apollo.h"
#include <fstream>
#include <SHlobj.h>
#include <cstdio>
#include <TlHelp32.h>

Debug* Debug::instance;

Debug::Debug()
{
	instance = this;
}

VOID Debug::Log(LogType type, const WCHAR* fmt, ...)
{
	WCHAR buffer[MAX_LOG_LEN];
	va_list args;

	va_start(args, fmt);
	vswprintf_s(buffer, fmt, args);
	va_end(args);

	std::wfstream outfile;
	outfile.open(std::wstring(LogDirectory() + L"/" + LogFile()), std::ios_base::app);

	if (outfile.is_open())
	{
		std::wstring s = buffer;

		switch (type)
		{
		case LogType::L_DEBUG:
			outfile << L"[" << Time::GetDateTimeStr() << L"]" << s;
			break;
		case LogType::L_WARNING:
			outfile << L"[" << Time::GetDateTimeStr() << L"]" << L"WARNING: " << s;
			break;
		case LogType::L_ERROR:
			outfile << L"[" << Time::GetDateTimeStr() << L"]" << L"ERROR: " << s;
			break;
		}

		outfile.close();
		OutputDebugString(s.c_str());
	}
	else 
	{
		MessageBox(NULL, L"Unable to open log file in Debug::Log().", L"Log Error", MB_OK);
	}
}

std::wstring Debug::LogDirectory()
{
	WCHAR Path[MAX_FILE_LEN];
	WCHAR* AppDataLocal;
	SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, nullptr, &AppDataLocal);
	wcscpy_s(Path, AppDataLocal);
	wcscat_s(Path, L"\\");
	wcscat_s(Path, GameSettings::GetGameName());
	CreateDirectory(Path, NULL);
	wcscat_s(Path, L"\\Log");
	CreateDirectory(Path, NULL);
	return Path;
}

std::wstring Debug::LogFile()
{
	WCHAR File[MAX_FILE_LEN];
	wcscpy_s(File, GameSettings::GetGameName());
	wcscat_s(File, GameSettings::GetBootTime());
	wcscat_s(File, L".log");
	return File;
}

VOID Debug::LogSeparator()
{
	std::wstring s = L"\n--------------------------------------------------------------------------------------\n\n";

#ifdef _DEBUG
	std::wfstream outfile;
	outfile.open(std::wstring(LogDirectory() + L"/" + LogFile()), std::ios_base::app);

	if (outfile.is_open())
	{
		outfile << s;
		outfile.close();
	}
	else
	{
		MessageBox(NULL, L"Unable to open log file in Debug::LogSeparator().", L"Log Error", MB_OK);
	}

#endif
}

/* Private class to check to see if MTail is already running, so we don't open multiple copies during debug session */
BOOL Debug::IsMTailRunning()
{
	bool exists = false;
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);

	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (Process32First(snapshot, &entry))
	{
		while (Process32Next(snapshot, &entry))
		{
			if (!_wcsicmp(entry.szExeFile, L"mTAIL.exe"))
			{
				exists = true;
			}
		}
	}

	CloseHandle(snapshot);
	return exists;
}

/* Start MTail from Project or Build Directory -- depends on where its ran from */
VOID Debug::StartMTail()
{
	if (IsMTailRunning())
	{
		Debug::Log(LogType::L_ERROR, L"--MTail failed to start -- Already Running\n");
		return;
	}

	Debug::Log(LogType::L_DEBUG, L"--Starting MTail\n");
	WCHAR path[MAX_PATH] = { 0 };
	GetCurrentDirectoryW(MAX_PATH, path);
	std::wstring url = path + std::wstring(L"/mTAIL.exe");
	std::wstring params = L" \"" + LogDirectory() + L"/" + LogFile() + L"\" /start";
	ShellExecute(0, NULL, url.c_str(), params.c_str(), NULL, SW_SHOWDEFAULT);
}
