#pragma once

#ifdef CW_PLATFORM_WINDOWS
	#ifdef CW_BUILD_DLL
		#define CROWN_API __declspec(dllexport)
	#else
		#define CROWN_API __declspec(dllimport)
	#endif
#else
#error Crown only supports Windows!
#endif

#define BIT(x) (1 << x)