workspace "ZenEngine"
    configurations { "Debug", "Release" }
    architecture "x64"
    startproject "ZenEngine"

project "GLM"
    location "GLM"
    kind "StaticLib"
    language "C++"
    targetdir "bin/%{cfg.buildcfg}/GLM"
    objdir "bin-int/%{cfg.buildcfg}/GLM"

    files {
        "GLM/**.hpp",
        "GLM/*.hpp",
        "GLM/glm.cpp"
    }

    includedirs {
        "GLM/glm"
    }

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        runtime "Release"
        optimize "On"

project "GLFW"
    location "GLFW"
    kind "StaticLib"
    language "C"
    targetdir "bin/%{cfg.buildcfg}/GLFW"
    objdir "bin-int/%{cfg.buildcfg}/GLFW"

    files {
        "GLFW/src/*.c",
        "GLFW/include/GLFW/*.h"
    }

    includedirs {
        "GLFW/include"
    }

    filter "system:windows"
        systemversion "latest"
        defines { "_GLFW_WIN32" }

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        runtime "Release"
        optimize "On"

project "GLAD"
    location "GLAD"
    kind "StaticLib"
    language "C"
    targetdir "bin/%{cfg.buildcfg}/GLAD"
    objdir "bin-int/%{cfg.buildcfg}/GLAD"

    files {
        "GLAD/src/glad.c",
        "GLAD/include/**.h"
    }

    includedirs {
        "GLAD/include"
    }

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        runtime "Release"
        optimize "On"

project "ZenEngine"
    location "ZenEngine"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    targetdir "bin/%{cfg.buildcfg}/ZenEngine"
    objdir "bin-int/%{cfg.buildcfg}/ZenEngine"

    files {
        "ZenEngine/src/**.h",
        "ZenEngine/src/**.cpp"
    }

    includedirs {
        "GLFW/include",
        "GLAD/include",
        "GLM",
        "ZenEngine/src/Engine",
        "ZenEngine/src/Engine/Component",
        "ZenEngine/src/Engine/Rendering",
        "ZenEngine/src",
    }

    links {
        "GLFW",
        "GLAD",
        "GLM",
        "opengl32"
    }

    filter "system:windows"
        systemversion "latest"
        defines { "VX_PLATFORM_WINDOWS" }

    filter "configurations:Debug"
        defines { "ZEN_DEBUG" }
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines { "ZEN_RELEASE" }
        runtime "Release"
        optimize "On"

project "ImGui"
    location "ImGui"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    targetdir "bin/%{cfg.buildcfg}/ImGui"
    objdir "bin-int/%{cfg.buildcfg}/ImGui"

    files {
        "ImGui/**.h",
        "ImGui/**.cpp"
    }

    filter "system:windows"
        systemversion "latest"
        defines { "VX_PLATFORM_WINDOWS" }

    filter "configurations:Debug"
        defines { "ZEN_DEBUG" }
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines { "ZEN_RELEASE" }
        runtime "Release"
        optimize "On"
