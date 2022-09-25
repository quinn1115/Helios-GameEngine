#pragma once
#include "Engine.h"


class GLFWwindow;

namespace Helios
{
	class Device
	{
	public:
		Device();
		~Device();

		void InitWindow(EngineConfig a_Config);
		void PollEvents();
		void SwapBuffers();

		void ExitWindow();

		bool IsWindowOpen();

		GLFWwindow* GetWindow() { return m_Window; }



	private:
		GLFWwindow* m_Window;
	};
}