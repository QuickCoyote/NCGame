#include "ship.h"
#include "transformComponent.h"
#include "spriteComponent.h"
#include "kinematicComponent.h"
#include "shipControllerComponent.h"

void Ship::Create(const Vector2D position)
{
	TransformComponent* transformComponent = AddComponent<TransformComponent>();
	transformComponent->Create(position);
	//AddComponent(transformComponent);

	ShipControllerComponent* shipControlComponent = AddComponent<ShipControllerComponent>();
	shipControlComponent->Create(400.0f);
	//AddComponent(shipControlComponent);

	KinematicComponent* kinematic = AddComponent<KinematicComponent>();
	kinematic->Create(1000.0f, 0.2f);
	//AddComponent(kinematic);

	SpriteComponent* spriteComponent = AddComponent<SpriteComponent>();
	spriteComponent->Create("..\\content\\ship.png");
	//AddComponent(spriteComponent);
}