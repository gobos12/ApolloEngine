#include "Apollo.h"

#define ENTRYAPP(x) Win32::IApplication* EntryApplication() { return new x; }

namespace Win32
{
	class APOLLO_API IApplication
	{
	public:
		/* Application Deconstructor */
		virtual ~IApplication() { };

		/* Called to setup game settings*/
		virtual VOID SetupGameSettings() = 0;

		/* Called before initializing application */
		virtual VOID PreInitialize() = 0;

		/* Called to initialize application */
		virtual VOID Initialize() = 0;

		/* Game Loop */
		virtual VOID Update() = 0;
	};

	IApplication* EntryApplication();
}