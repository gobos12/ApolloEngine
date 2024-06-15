#pragma once

#ifdef BUILD_DLL
	#define APOLLO_API __declspec(dllexport)
#else
	#define APOLLO_API __declspec(dllimport)
#endif

#define MAX_STRING_LEN 256
#define MAX_FILE_LEN 1024
#define MAX_LOG_LEN 4096

#define HInstance() GetModuleHandle(NULL)  // hInstance callback
