workspace "Parbox"
	configurations {"Debug", "Release"}
	startproject "ParboxGame"
	
IncludeDir = {}
IncludeDir["GLFW"] = "Dependencies/GLFW/include"
IncludeDir["Glad"] = "Dependencies/glad/include"

group "Dependencies"
	include "Dependencies/GLFW"
	include "Dependencies/glad"
group ""
	
project "Parbox"
	location "Parbox"
	kind "SharedLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	
	targetdir ("bin/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}")
	objdir ("bin-int/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}")
	
	pchheader "pbxpch.h"
	pchsource "%{prj.name}/src/pbxpch.cpp"
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	defines
	{
		"PBX_BUILD_DLL",
		"_GLFW_WIN32",
		"_CRT_SECURE_NO_WARNINGS"
	}
	
	includedirs
	{
		"%{prj.name}/src/",
		"Dependencies/spdlog-1.x/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
	}
	
	links
	{
		"GLAD",
		"GLFW",
		"opengl32.lib"
	}
	
	filter "system:windows"
		systemversion "latest"
		
		defines
		{
			"PBX_WINDOWS"
		}
		
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/%{cfg.buildcfg}-%{cfg.system}/ParboxGame/\"")
		}
		
	filter "configurations:Debug"
		defines "PBX_DEBUG"
		runtime "Debug"
		symbols "on"
		
	filter "configurations:Release"
		defines "PBX_RELEASE"
		runtime "Release"
		optimize "on"
		
project "ParboxGame"
	location "ParboxGame"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	
	targetdir ("bin/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}")
	objdir ("bin-int/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}")
	
	pchheader "pbxclientpch.h"
	pchsource "%{prj.name}/src/pch/pbxclientpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"%{prj.name}/src/pch",
		"Parbox/src/",
		"Dependencies/spdlog-1.x/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
	}
	
	links
	{
		"Parbox"
	}
	
	filter "system:windows"
		systemversion "latest"		
		
		defines
		{
			"PBX_WINDOWS"
		}
		
	filter "configurations:Debug"
		defines "PBX_DEBUG"
		runtime "Debug"
		symbols "On"
		
	filter "configurations:Release"
		defines "PBX_RELEASE"
		runtime "Release"
		optimize "On"	