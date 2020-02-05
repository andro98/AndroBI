#pragma once

#ifdef ABI_PLATFORM_WINDOWS
	#ifdef ABI_BUILD_DLL
		#define ANDROBI_API __declspec(dllexport)
	#else
		#define ANDROBI_API __declspec(dllimport)
	#endif
#else 
	#error AndroBI only support Windows!
#endif