workspace "Lotion"
    architecture "x64"
    
    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }
    
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Lotion/vendor/GLFW/include"
IncludeDir["Glad"] = "Lotion/vendor/Glad/include"

include "Lotion/vendor/GLFW"
include "Lotion/vendor/Glad"

project "Lotion"
    location "Lotion"
    kind "SharedLib"
    language "C++"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "ltpch.h"
    pchsource "Lotion/src/ltpch.cpp"
    
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }
    
    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}"
    }
    
    links
    {
        "GLFW",
        "Glad",
        "opengl32.lib"
    }
    
    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        
        defines
        {
            "LT_PLATFORM_WINDOWS",
            "LT_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }
        
        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    
    filter "configurations:Debug"
        defines "LT_DEBUG"
        buildoptions "/MDd"
        symbols "On"
    
    filter "configurations:Release"
        defines "LT_Release"
        buildoptions "/MD"
        optimize "On"
    
    filter "configurations:Dist"
        defines "LT_DIST"
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
        "Lotion/vendor/spdlog/include",
        "Lotion/src"
    }
    
    links
    {
        "Lotion"
    }
    
    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        
        defines
        {
            "LT_PLATFORM_WINDOWS"
        }
    
    filter "configurations:Debug"
        defines "LT_DEBUG"
        buildoptions "/MDd"
        symbols "On"
    
    filter "configurations:Release"
        defines "LT_Release"
        buildoptions "/MD"
        optimize "On"
    
    filter "configurations:Dist"
        defines "LT_DIST"
        buildoptions "/MD"
        optimize "On"
