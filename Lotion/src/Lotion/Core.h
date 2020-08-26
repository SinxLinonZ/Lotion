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

#define BIT(x) (1 << x)