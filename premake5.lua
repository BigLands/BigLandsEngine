workspace "BigLandsEngine"
  architecture "x64"

  configurations
  {
    "Debug",
    "Release",
    "Dist"
  }

  outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

  startproject "Project"


  project "BigLandsEngine"
    location "BigLandsEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "bepch.h"
    pchsource "BigLandsEngine/src/bepch.cpp"

    files
    {
      "%{prj.name}/src/**.h",
      "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
      "BigLandsEngine/vendor/spdlog/include",
      "BigLandsEngine/src"
    }

    filter "system:windows"
      cppdialect "C++17"
      staticruntime "On"
      systemversion "latest"

      defines
      {
        "BE_PLATFORM_WINDOWS",
        "BE_BULD_DLL"
      }

      postbuildcommands
      {
        "{MKDIR} ../bin/" .. outputdir .. "/Project",
        "{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Project"
      }

    filter "configurations:Debug"
      defines "BE_DEBUG"
      symbols "On"

    filter "configurations:Release"
      defines "BE_RELEASE"
      optimize "On"

    filter "configurations:Dist"
      defines "BE_DIST"
      optimize "On"

  project "Project"
    location "Project"
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
      "BigLandsEngine/vendor/spdlog/include",
      "BigLandsEngine/src"
    }

    links
    {
      "BigLandsEngine"
    }

    filter "system:windows"
      cppdialect "C++17"
      staticruntime "On"
      systemversion "latest"

      defines
      {
        "BE_PLATFORM_WINDOWS"
      }

    filter "configurations:Debug"
      defines "BE_DEBUG"
      symbols "On"

    filter "configurations:Release"
      defines "BE_RELEASE"
      optimize "On"

    filter "configurations:Dist"
      defines "BE_DIST"
      optimize "On"
