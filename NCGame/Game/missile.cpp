#include "missile.h"
#include "transformComponent.h"
#include "spriteComponent.h"
#include "kinematicComponent.h"
#include "shipControllerComponent.h"

void Missile::Create(const Vector2D position)
{
	TransformComponent* transformComponent = AddComponent<TransformComponent>();
	transformComponent->Create(position);
	//AddComponent(transformComponent);

	KinematicComponent* kinematic = AddComponent<KinematicComponent>();
	kinematic->Create(1000.0f, 0.2f);
	//AddComponent(kinematic);

	SpriteComponent* spriteComponent = AddComponent<SpriteComponent>();
	spriteComponent->Create("..\\content\\missile.png");
	//AddComponent(spriteComponent);
}