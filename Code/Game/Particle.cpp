#include "Game/Particle.hpp"
#include "Game/TheGame.hpp"
#include "Engine/Renderer/Renderer/BeirusRenderer.hpp"


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//STRUCTORS
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------------------------------------------------------
Particle::Particle(const Vector3& position, const float radius) 
	: m_position(position)
	, m_radius(radius)
{ }


//---------------------------------------------------------------------------------------------------------------------------
Particle::~Particle() {

}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//UPDATE
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------------------------------------------------------
void Particle::Update(float deltaSeconds) {

	m_position += m_velocity * deltaSeconds;
	m_velocity += GRAVITY * deltaSeconds;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//RENDER
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------------------------------------------------------
void Particle::Render() const {

	BeirusRenderer::DrawCircle(TheGame::GetCamera(), RGBA::GREEN, m_position, m_radius);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//INTERFACE
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------------------------------------------------------
void Particle::PushUp(float bottomPlane) {

	if (m_position.y - m_radius < bottomPlane) {
		float diff = bottomPlane - (m_position.y - m_radius);
		m_position.y += diff;

		//m_velocity = -m_velocity / 2.f;
	}
}


//---------------------------------------------------------------------------------------------------------------------------
void Particle::PushLeft(float leftPlane) {

	if (m_position.x - m_radius < leftPlane) {
		float diff = leftPlane - (m_position.x - m_radius);
		m_position.x += diff;
	}
}


//---------------------------------------------------------------------------------------------------------------------------
void Particle::PushRight(float rightPlane) {

	if (m_position.x + m_radius > rightPlane) {
		float diff = (m_position.x + m_radius) - rightPlane;
		m_position.x -= diff;
	}
}