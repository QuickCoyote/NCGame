#pragma once
#include "engine.h"
#include "physicsComponent.h"

class ENGINE_API KinematicComponent : public IPhysicsComponent
{
public:
	KinematicComponent(Entity* owner) : IPhysicsComponent(owner) {}

	void Create(float velocityMax = 500.0f, float dampening = 1.0f, bool enableGravity = false);
	void Destroy();
	void Update();

	virtual void SetVelocity(const Vector2D& velocity);
	virtual const Vector2D& GetVelocity() const;
	virtual void SetVelocityMax(float velocityMax);

	virtual void ApplyForce(const Vector2D& force, eForceType forceType);
	virtual void EnableGravity(bool enableGravity = true);

protected:
	bool m_enableGravity = false;
	float m_dampening = 1.0f;
	eForceType m_forceType;
	Vector2D m_velocity;
	float m_velocityMax;
	Vector2D m_force;

};

