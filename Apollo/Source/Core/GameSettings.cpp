#include "Apollo.h"

GameSettings* GameSettings::instance;

GameSettings::GameSettings()
{
	instance = this;

	/* Default Game Settings */
	wcscpy_s(instance->m_GameName, L"UNDEFINED");
	wcscpy_s(instance->m_ShortName, L"UNDEFINED");
}

GameSettings::~GameSettings() { }
