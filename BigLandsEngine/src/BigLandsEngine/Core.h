#pragma once

#ifdef BE_PLATFORM_WINDOWS
	#ifdef BE_BULD_DLL
		#define BIGLANDSENGINE_API __declspec (dllexport)
#else
		#define BIGLANDSENGINE_API __declspec (dllimport)
	#endif
#else
	#error BigLandsEngine is only on windows at this time please check back later for updates

#endif