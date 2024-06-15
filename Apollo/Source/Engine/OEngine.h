#pragma once

class APOLLO_API OEngine;

namespace Engine
{
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