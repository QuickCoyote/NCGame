#include "scene.h"
#include "assert.h"

bool Scene::Initialize()
{
	return true;
}

void Scene::Shutdown()
{
	for (Entity* entity : m_entities)
	{
		entity->Destroy();
	}
	m_entities.clear();
}

void Scene::Update()
{
	for (Entity* entity : m_entities)
	{
		entity->Update();
	}
}

void Scene::Draw()
{
	for (Entity* entity : m_entities)
	{
		entity->Draw();
	}
}

void Scene::AddEntity(Entity * entity)
{
	assert(entity);
	assert(find(m_entities.begin(), m_entities.end(), entity) == m_entities.end());

	m_entities.push_back(entity);
}

void Scene::RemoveEntity(Entity * entity)
{
	assert(entity);
	assert(find(m_entities.begin(), m_entities.end(), entity) != m_entities.end());

	auto iter = std::find(m_entities.begin(), m_entities.end(), entity);
	delete *iter;
	m_entities.erase(iter);
}

Entity * Scene::Find(const ID & id)
{
	Entity* foundEntity = nullptr;
	for (Entity* entity : m_entities)
	{
		if (*entity == id)
		{
			foundEntity = entity;
			break;
		}
	}
	return foundEntity;
}
