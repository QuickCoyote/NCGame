#pragma once

#include "vector2D.h"
#include "vector3D.h"
#include "matrix33.h"
#include "renderComponent.h"

class Texture;

class ENGINE_API SpriteComponent : public IRenderComponent
{
public:
	SpriteComponent(Entity* owner) : IRenderComponent(owner) {}

	void Create(const std::string& textureName);
	void Destroy();
	void Update();

	void Draw();

protected:
	Texture* m_texture = nullptr;
	Vector2D m_uv1;// = ; Vector2D(0, 0);
	Vector2D m_uv2;// = Vector2D(0, 0);
};
