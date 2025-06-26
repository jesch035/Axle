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

#ifdef AX_CONFIG_DEBUG
	#define AX_ASSERT(x, ...) { if(!x) { AX_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define AX_CORE_ASSERT(x, ...) { if(!(x)) { AX_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define AX_ASSERT(x, ...)
	#define AX_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)