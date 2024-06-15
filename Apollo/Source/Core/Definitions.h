#pragma once

#ifdef BUILD_DLL
	#define APOLLO_API __declspec(dllexport)
#else
	#define APOLLO_API __declspec(dllimport)
#endif

#define MAX_STRING_LEN 256

#define HInstance() GetModuleHandle(NULL)  // hInstance callback
