#pragma once

#include "engine.h"

int wmain(int argc, char* argv[])
{
	Engine engine;

	engine.Initialize();
	while (!engine.IsQuit())
	{
		engine.Update();
	}
	engine.Shutdown();

	return 0;
}