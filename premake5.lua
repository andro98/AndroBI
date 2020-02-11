solution "AndroBI"
	architecture "x86_64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "AndroBI"
	location "AndroBI"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

	pchheader "abipch.h"
	pchsource "AndroBI/src/abipch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ABI_PLATFORM_WINDOWS",
			"ABI_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir.. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "ABI_DEBUG"
		symbols	"On"
		
	filter "configurations:Release"
		defines "ABI_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "ABI_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"AndroBI/vendor/spdlog/include",
		"AndroBI/src"
	}

	links
	{
		"AndroBI"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ABI_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "ABI_DEBUG"
		symbols	"On"
		
	filter "configurations:Release"
		defines "ABI_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "ABI_DIST"
		optimize "On"