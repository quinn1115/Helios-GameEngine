workspace "HeliosEngine"
    architecture "x64"

    configurations
    {
       "Debug",
       "Release"
    }

    startproject "Sandbox"

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    IncludeDir = {}
    IncludeDir["GLFW"] = "Helios/ThirdParty/GLFW/include"
    IncludeDir["GLAD"] = "Helios/ThirdParty/GLAD/include"
    IncludeDir["GLM"] = "Helios/ThirdParty/glm"
    IncludeDir["spdlog"] = "Helios/ThirdParty/spdlog/include"
    IncludeDir["ImGui"] = "Helios/ThirdParty/imgui"
    IncludeDir["TinyGLTF"] = "Helios/ThirdParty/tinygltf"
    
project "Helios"
    location "Helios"
    kind "StaticLib"
    language "c++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir ("Binaries/" .. outputdir .. "/%{prj.name}")
    objdir ("Intermediate/" ..outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/Source/Public/**.h",
        "%{prj.name}/Source/Private/**.cpp",
    }

    includedirs
    {
        "%{prj.name}/Source/Public;",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.GLAD}",
        "%{IncludeDir.GLM}",
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.ImGUi}",
    }

    libdirs {"Helios/ThirdParty/GLFW/lib-vc2019"}
    links
    {
        "glfw3.lib",
        "opengl32.lib"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "HELIOS_PLATFORM_WINDOWS"
        }
    
    filter "configurations:Debug"
        defines "HELIOS_DEBUG"
        symbols "on"
    filter "configurations:Release"
        defines "HELIOS_RELEASE"
        optimize "on"

project "Sandbox"
    location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	

	targetdir ("binaries/" .. outputdir .. "/%{prj.name}")
	objdir ("intermediate/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/Source/Public/**.h",
		"%{prj.name}/Source/Private/**.cpp"
	}

    includedirs
    {
        "Helios/ThirdParty/spdlog/include;",
        "Helios/ThirdParty/GLFW/include;",
        "Helios/Source/Public"

    }

    links
    {
        "Helios"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "HELIOS_PLATFORM_WINDOWS"
        }
    
        filter "configurations:Debug"
		defines "HELIOS_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "HELIOS_RELEASE"
		optimize "on"