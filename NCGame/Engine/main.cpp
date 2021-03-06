// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "vector2D.h"
#include "core.h"
#include "math.h"
#include "color.h"
#include "transform.h"
#include "shape.h"
#include "matrix22.h"
#include "game.h"
#include <fstream>

using namespace nce;

bool Update(float dt)
{
	bool quit = false;
	if (Core::Input::IsPressed(Core::Input::KEY_ESCAPE))
	{
		quit = true;
	}

	GAME.Update(dt);

	return quit;
}

void Draw(Core::Graphics& graphics)
{
	GAME.Draw(graphics);
}

int main()
{
	GAME.Initialize();

	char name[32];
	strcpy_s(name, "hello");
	Core::Init(name, 800, 600);
	Core::RegisterUpdateFn(Update);
	Core::RegisterDrawFn(Draw);
	Core::GameLoop();
	Core::Shutdown();

    return 0;
}
