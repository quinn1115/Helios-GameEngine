#include "Core/Engine.h"

using namespace Helios;

int main(int argc, char* argv[])
{	
	EngineConfig config;
	config.winWidth = 1920;
	config.winHeight = 1080;
	config.windowTitle = "Sandbox";
	config.projTitle = "SandBox";
	config.useVsync = false;
	config.isFullScreen = false;

	Engine.Init(config);
	Engine.Update();
	Engine.Exit();
}