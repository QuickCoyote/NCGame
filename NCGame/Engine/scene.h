#pragma once
#include "engine.h"
#include "entity.h"
#include <vector>

class ENGINE_API Scene
{
public:
	Scene() {}
	~Scene() {}

	bool Initialize();
	void Shutdown();
	void Update();
	void Draw();

	void AddEntity(Entity* entity);
	void RemoveEntity(Entity* entity);

	Entity* Find(const ID& id);

protected:
	std::vector<Entity*> m_entities;
};

