#pragma once
#include <string>


namespace Helios
{
	class Device;

	struct EngineConfig
	{
		int winWidth = 1280;
		int winHeight = 720;
		bool isFullScreen = false;
		bool useVsync = true;
		std::string projTitle = "Sandbox Game";
		std::string windowTitle = "SandBox Game";
	};

	class HeliosEngine
	{
	public:

		void Init(EngineConfig a_Config);
		void Update();
		void Exit();

	private:

		EngineConfig m_EngineConfig;
		Device* m_Device;
	};

	extern HeliosEngine& Engine;
}