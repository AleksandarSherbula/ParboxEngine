#pragma once

#ifdef PBX_WINDOWS
	#ifdef PBX_BUILD_DLL
		#define PARBOX_DLL __declspec(dllexport)
	#else
		#define PARBOX_DLL __declspec(dllimport)
	#endif
#else
	#error Parbox only supports Windows!
#endif

namespace pbx
{

	struct Color
	{
		float r, g, b, a;
	};

	const Color
		RED = { 255.0f, 0.0f, 0.0f, 255.0f },
		GREEN = { 0.0f, 255.0f, 0.0f, 255.0f },
		BLUE = { 0.0f, 0.0f, 255.0f, 255.0f },
		YELLOW = { 255.0f, 255.0f, 0.0f, 255.0f },
		CYAN = { 0.0f, 255.0f, 255.0f, 255.0f },
		MAGENTA = { 255.0f, 0.0f, 255.0f, 255.0f },
		WHITE = { 255.0f, 255.0f, 255.0f, 255.0f };

}