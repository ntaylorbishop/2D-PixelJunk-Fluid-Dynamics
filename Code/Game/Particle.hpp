#pragma once

#include "Engine/Math/Vector3.hpp"

const Vector3 GRAVITY = Vector3(0.f, -9.8f, 0.f);

class Particle {
public:
	//STRUCTORS
	Particle(const Vector3& position, const float radius);
	~Particle();

	//UPDATE
	void Update(float deltaSeconds);

	//RENDER
	void Render() const;

	//INTERFACE
	void PushUp(float bottomPlane);
	void PushLeft(float leftPlane);
	void PushRight(float rightPlane);


private:
	Vector3 m_position	= Vector3::ZERO;
	float	m_radius	= 0.f;
	Vector3 m_velocity	= Vector3::ZERO;
};