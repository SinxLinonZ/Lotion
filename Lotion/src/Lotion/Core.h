#pragma once

#ifdef LT_PLATFORM_WINDOWS
	#ifdef LT_BUILD_DLL
		#define LOTION_API __declspec(dllexport)
	#else
		#define LOTION_API __declspec(dllimport)
	#endif
#else
	#error Lotion only supports Windows.
#endif

#ifdef LT_ENABLE_ASSERTS
	#define LT_ASSERT(x, ...) { if(!(x)) { LT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define LT_CORE_ASSERT(x, ...) { if(!(x)) { LT_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define LT_ASSERT(x, ...)
	#define LT_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)