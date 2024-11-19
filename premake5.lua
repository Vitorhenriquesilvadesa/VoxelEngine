workspace "VoxelEngine"
    configurations { "Debug", "Release" }
    architecture "x64"
    startproject "VoxelEngine"

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

project "VoxelEngine"
    location "VoxelEngine"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    targetdir "bin/%{cfg.buildcfg}/VoxelEngine"
    objdir "bin-int/%{cfg.buildcfg}/VoxelEngine"

    files {
        "VoxelEngine/src/**.h",
        "VoxelEngine/src/**.cpp"
    }

    includedirs {
        "GLFW/include",
        "GLAD/include"
    }

    links {
        "GLFW",
        "GLAD",
        "opengl32"
    }

    filter "system:windows"
        systemversion "latest"
        defines { "VX_PLATFORM_WINDOWS" }

    filter "configurations:Debug"
        defines { "VX_DEBUG" }
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines { "VX_RELEASE" }
        runtime "Release"
        optimize "On"
