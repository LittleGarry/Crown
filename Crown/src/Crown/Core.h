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

#ifdef CW_ENABLE_ASSERTS
	#define CW_ASSERT(x, ...) {if (!(x)) {CW_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); }}
	#define CW_CORE_ASSERT(x, ...) {if (!(x)) {CW_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
#define CW_ASSERT(x, ...)
#define CW_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)