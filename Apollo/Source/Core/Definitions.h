#ifdef BUILD_DLL
	#define APOLLO_API __declspec(dllexport)
#else
	#define APOLLO_API __declspec(dllimport)
#endif

#define HInstance() GetModuleHandle(NULL)  // hInstance callback
