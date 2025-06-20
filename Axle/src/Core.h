#pragma once

#ifdef AX_PLATFORM_WINDOWS
	#ifdef AX_BUILD_DLL
		#define AXLE_API __declspec(dllexport)
	#else
		#define AXLE_API __declspec(dllimport)
	#endif
#else
	#error Axle currently only supports Windows!
#endif