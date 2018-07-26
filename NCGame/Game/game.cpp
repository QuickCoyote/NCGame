#include "game.h"
#include "engine.h"
#include "renderer.h"
#include "textureManager.h"
#include "textManager.h"
#include "inputManager.h"
#include "audioSystem.h"
#include "timer.h"
#include "vector2D.h"
#include "matrix22.h"
#include "entity.h"
#include "transformComponent.h"
#include "spriteComponent.h"
#include "shipControllerComponent.h"
#include "kinematicComponent.h"
#include "ship.h"
#include "scene.h"
#include "missile.h"
#include <assert.h>
#include <vector>
#include <iostream>

Vector2D position(400.0f, 300.0f);
float angle = 0.0f;

bool Game::Initialize()
{
	bool success = m_engine->Initialize();

	scene = new Scene();
	scene->Initialize();

	Ship* ship = new Ship();

	ship->Create(Vector2D((float)(rand() % 800), (float)(rand() % 600)));

	Missile* missile = new Missile();
	missile->Create(ship->GetComponet<TransformComponent>()->position);

	scene->AddEntity(missile);
	scene->AddEntity(ship);

	m_running = success;

	return success;
}

void Game::Shutdown()
{
	m_engine->Shutdown();
}

void Game::Update()
{
	m_running = !m_engine->IsQuit();
	m_engine->Update();
	scene->Update();

	// DRAW
	Renderer::Instance()->BeginFrame();
	Renderer::Instance()->SetColor(Color::red);

	scene->Draw();

	Renderer::Instance()->EndFrame();
}
