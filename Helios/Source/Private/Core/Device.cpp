#include "glad/gl.h"
#include <GLFW/glfw3.h>
#include "Core/Device.h"
#include "Debug/Logger.h"

using namespace Helios;

Device::Device()
{}

Device::~Device()
{}

void Device::InitWindow(EngineConfig a_Config)
{
	if(!glfwInit())
	{
		return;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_Window = glfwCreateWindow(a_Config.winWidth, a_Config.winHeight, a_Config.windowTitle.c_str(), NULL, NULL);
	if(!m_Window)
	{
		Log::LogError("Failed setting up GLFW Window");
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(m_Window);


	if (!gladLoadGL(glfwGetProcAddress))
	{
		Log::LogError("Failed setting up glad");
	}

}

void Device::PollEvents()
{
	glfwPollEvents();
}

void Device::SwapBuffers()
{
	glfwSwapBuffers(m_Window);
}

void Device::ExitWindow()
{
	glfwTerminate();
}

bool Helios::Device::IsWindowOpen()
{
	return !glfwWindowShouldClose(m_Window);
}
