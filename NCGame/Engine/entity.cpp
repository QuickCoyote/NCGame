#include "entity.h"
#include "assert.h"
#include "renderComponent.h"

void Entity::Update()
{
	for (Component* comp : m_components)
	{
		comp->Update();
	}
}

void Entity::Draw()
{
	IRenderComponent* iRend = GetComponet<IRenderComponent>();
	if (iRend)
	{
		iRend->Draw();
	}
}

void Entity::Destroy()
{
	for (Component* component : m_components)
	{
		component->Destroy();
	}
	m_components.clear();
}

void Entity::AddComponent(Component * componet)
{
	assert(componet);
	assert(std::find(m_components.begin(), m_components.end(), componet) == m_components.end());
	m_components.push_back(componet);
}

void Entity::RemoveCompenent(Component * componet)
{
	assert(std::find(m_components.begin(), m_components.end(), componet) != m_components.end());
	auto iter = std::find(m_components.begin(), m_components.end(), componet);
	delete *iter;
	m_components.erase(iter);
}
