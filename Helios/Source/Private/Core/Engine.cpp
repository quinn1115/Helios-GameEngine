#include <GLFW/glfw3.h>

#include "Core/Engine.h"
#include "Debug/Logger.h"
#include "Core/Device.h"

using namespace Helios;

HeliosEngine& Helios::Engine = *(new HeliosEngine());

void HeliosEngine::Init(EngineConfig a_Config)
{
	//Init Engine
	m_EngineConfig = a_Config;
	
	//Init Logger
	Log::Init();
	Log::LogInfo("Logger Intiated successfully");

	//Init Window/Device
	m_Device = new Device();
	m_Device->InitWindow(m_EngineConfig);
	Log::LogInfo("Window Successfully Created");
}

void HeliosEngine::Update()
{
	while (m_Device->IsWindowOpen())
	{
		glClearColor(0.75f, 0.75f, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);


		m_Device->SwapBuffers();
		m_Device->PollEvents();
	}
}

void HeliosEngine::Exit()
{
	m_Device->ExitWindow();
	

	delete& Engine;
	return;
}