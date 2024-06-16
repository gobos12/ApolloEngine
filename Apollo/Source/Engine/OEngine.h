#pragma once

class APOLLO_API OEngine;

namespace Engine
{
	/* INT enum that represents the various engine types for Apollo */
	enum EngineMode : INT
	{
		NONE,
		DEBUG,
		RELEASE,
		EDITOR,
		SERVER
	};

	extern OEngine g_Engine;

	
	VOID APOLLO_API SetMode(EngineMode mode);
	EngineMode APOLLO_API GetMode();

	/* Converts engine type to a string for debugging */
	std::wstring APOLLO_API EngineModeToString();
}

using namespace Engine;
class APOLLO_API OEngine
{
public:
	OEngine();
	~OEngine() { }

	EngineMode GetEngineMode() { return m_EngineMode; }
	VOID SetEngineMode(EngineMode mode) { m_EngineMode = mode; }

private:
	EngineMode m_EngineMode;
};