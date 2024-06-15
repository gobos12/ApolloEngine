#pragma once

class APOLLO_API GameSettings
{
private:
	static GameSettings* instance;

	static GameSettings* Singleton() { return instance;  }

public:
	/* Constructor & Deconstructor */
	GameSettings();
	~GameSettings();

private:
	WCHAR m_GameName[MAX_STRING_LEN];
	WCHAR m_ShortName[MAX_STRING_LEN];
	HICON m_MainIcon;
	WCHAR m_BootTime[MAX_STRING_LEN];
	WCHAR m_SplashURL[MAX_STRING_LEN];

public: /* GETTERS & SETTERS*/
	static WCHAR* GetGameName() { return instance->m_GameName; }
	static VOID SetGameName(UINT id) { LoadString(HInstance(), id, instance->m_GameName, MAX_STRING_LEN); }

	static WCHAR* GetShortName() { return instance->m_ShortName; }
	static VOID SetShortName(UINT id) { LoadString(HInstance(), id, instance->m_ShortName, MAX_STRING_LEN); }

	static HICON GetMainIcon() { return instance->m_MainIcon; }
	static VOID SetMainIcon(UINT id) { LoadIcon(HInstance(), MAKEINTRESOURCE(id)); }

	static WCHAR* GetBootTime() { return instance->m_BootTime; }

	static WCHAR* GetSplashURL() { return instance->m_SplashURL; }
	static VOID SetSplashURL(UINT id) { LoadString(HInstance(), id, instance->m_SplashURL, MAX_STRING_LEN); }
};