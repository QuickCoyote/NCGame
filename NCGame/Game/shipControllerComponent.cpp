#include "shipControllerComponent.h"
#include "transformComponent.h"
#include "kinematicComponent.h"
#include "entity.h"
#include "inputManager.h"
#include "matrix22.h"
#include "timer.h"
#include "missile.h"

void ShipControllerComponent::Create(float speed)
{
	m_speed = speed;
	InputManager::Instance()->AddAction("left", SDL_SCANCODE_LEFT, InputManager::eDevice::KEYBOARD);
	InputManager::Instance()->AddAction("right", SDL_SCANCODE_RIGHT, InputManager::eDevice::KEYBOARD);
	InputManager::Instance()->AddAction("fire", SDL_SCANCODE_SPACE, InputManager::eDevice::KEYBOARD);

}

void ShipControllerComponent::Destroy()
{
}

void ShipControllerComponent::Update()
{
	Vector2D force = Vector2D::zero;
	TransformComponent* transform = m_owner->GetComponet<TransformComponent>();
	if ((InputManager::Instance()->GetActionButton("left") == InputManager::eButtonState::PRESSED) ||
	(InputManager::Instance()->GetActionButton("left") == InputManager::eButtonState::HELD))
	{
		force = force + Vector2D::left;
	}
	if ((InputManager::Instance()->GetActionButton("right") == InputManager::eButtonState::PRESSED) ||
	(InputManager::Instance()->GetActionButton("right") == InputManager::eButtonState::HELD))
	{
		force = force + Vector2D::right;
	}

	if ((InputManager::Instance()->GetActionButton("fire") == InputManager::eButtonState::PRESSED) ||
		(InputManager::Instance()->GetActionButton("fire") == InputManager::eButtonState::HELD))
	{
		
		//fire missle / create missile;
	}

	Matrix22 mx;
	mx.Rotate(transform->rotation * Math::DegreesToRadians);

	KinematicComponent* kinematic = m_owner->GetComponet <KinematicComponent>();
	if (kinematic)
	{
		kinematic->ApplyForce(force * m_speed * mx, KinematicComponent::VELOCITY);
	}
	//force = force * m_speed * Timer::Instance()->DeltaTime() * mx;
	//transform->position += force;
}