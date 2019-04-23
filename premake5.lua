workspace "Crown"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

startproject "Sandbox"

IncludeDir = {}
IncludeDir["GLFW"] = "Crown/vendor/GLFW/include"

include "Crown/vendor/GLFW"

project "Crown"
	location "Crown"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "cwpch.h"
	pchsource "Crown/src/cwpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links 
	{ 
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CW_PLATFORM_WINDOWS",
			"CW_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "CW_DEBUG"
		buildoptions "/MDd"
		symbols "On"
	
	filter "configurations:Release"
		defines "CW_RELEASE"
		buildoptions "/MD"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Crown/src",
		"Crown/vendor/spdlog/include"
	}

	links
	{
		"Crown"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"CW_PLATFORM_WINDOWS"
		}
	
	filter "configurations:Debug"
		defines "CW_DEBUG"
		buildoptions "/MDd"
		symbols "On"
	
	filter "configurations:Release"
		defines "CW_RELEASE"
		buildoptions "/MD"
		optimize "On"
