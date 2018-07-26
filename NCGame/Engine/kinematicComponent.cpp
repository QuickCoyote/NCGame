#include "kinematicComponent.h"
#include "timer.h"
#include "physics.h"
#include "transformComponent.h"
#include "entity.h"

void KinematicComponent::Create(float velocityMax, float dampening, bool enableGravity)
{
	m_velocityMax = velocityMax;
	m_dampening = dampening;
	m_enableGravity = enableGravity;

	m_forceType = eForceType::FORCE;
	m_force = Vector2D::zero;
	m_velocity = Vector2D::zero;
}

void KinematicComponent::Destroy()
{
	//
}

void KinematicComponent::Update()
{
	float dt = Timer::Instance()->DeltaTime();
	Vector2D force = (m_enableGravity) ? m_force + Physics::Instance()->GetGravity() : m_force;
	m_velocity = m_velocity + (force * dt);
	float magnitude = m_velocity.Length();
	if (magnitude > m_velocityMax)
	{
		m_velocity = m_velocity.Normalized() * m_velocityMax;
	}
	
	TransformComponent* transform = m_owner->GetComponet<TransformComponent>();
	if (transform)
	{
		transform->position = transform->position + (m_velocity *dt);
	}

	m_velocity = m_velocity * pow(m_dampening, dt);

	if (m_forceType == eForceType::IMPULSE)
	{
		m_force = Vector2D::zero;
	}

}

void KinematicComponent::SetVelocity(const Vector2D & velocity)
{
	m_velocity = velocity;
}

const Vector2D & KinematicComponent::GetVelocity() const
{
	return m_velocity;
}

void KinematicComponent::SetVelocityMax(float velocityMax)
{
	m_velocityMax = velocityMax;
}

void KinematicComponent::ApplyForce(const Vector2D & force, eForceType forceType)
{

	m_forceType = forceType;

	switch (m_forceType)
	{
	case eForceType::FORCE:
		m_force = force;
		break;
	case eForceType::IMPULSE:
		m_force = force;
		break;
	case eForceType::VELOCITY:
		m_force = Vector2D::zero;
		m_velocity = force;
		break;
	}
}

void KinematicComponent::EnableGravity(bool enableGravity)
{
	m_enableGravity = enableGravity;
}
