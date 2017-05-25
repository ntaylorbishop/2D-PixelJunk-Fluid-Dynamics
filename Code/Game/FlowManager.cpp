#include "Game/FlowManager.hpp"
#include "Game/Particle.hpp"
#include "Engine/Renderer/Renderer/BeirusRenderer.hpp"


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//STRUCTORS
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------------------------------------------------------
FlowManager::FlowManager() {

}


//---------------------------------------------------------------------------------------------------------------------------
FlowManager::~FlowManager() {

}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//UPDATE
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------------------------------------------------------
void FlowManager::UpdateFlowCollisions(float deltaSeconds) {

	for (size_t idx = 0; idx < m_particles.size(); idx++) {

		m_particles[idx]->PushLeft(LEFT_PLANE);
		m_particles[idx]->PushRight(RIGHT_PLANE);
		m_particles[idx]->PushUp(FLOOR_PLANE);
	}
}


//---------------------------------------------------------------------------------------------------------------------------
void FlowManager::UpdateParticleCollisions(float deltaSeconds) {


	for (size_t idx = 0; idx < m_particles.size(); idx++) {

		Particle* currParticle = m_particles[idx];

		for (size_t j = 0; j < m_particles.size(); j++) {
			if (idx == j) {
				continue;
			}

			Particle* otherParticle = m_particles[j];

			float dist = (currParticle->m_position - otherParticle->m_position).Length();

			Vector2 mPos = currParticle->m_position.xy();
			Vector2 oPos = otherParticle->m_position.xy();

			if (DoDiscsOverlap(mPos, currParticle->m_radius, oPos, otherParticle->m_radius)) {

				Vector2 pushDir = oPos - mPos;
				pushDir.Normalize();
				float dist = DistanceBetweenPoints(mPos, oPos);
				pushDir = pushDir * (dist - otherParticle->m_radius - currParticle->m_radius) * 0.2f;

				Vector2 newEntityPos2D = oPos - pushDir;
				m_position = Vector3(newEntityPos2D.x, newEntityPos2D.y, BASE_BLOCK_HEIGHT + m_cosmeticRadius);
				Vector2 newPos2D = mPos + pushDir;
				m_position = Vector3(newPos2D.x, newPos2D.y, BASE_BLOCK_HEIGHT + m_cosmeticRadius);
			}

			if(dist < )
		}
	}
}


//---------------------------------------------------------------------------------------------------------------------------
void FlowManager::Update(float deltaSeconds) {

	for (size_t idx = 0; idx < m_particles.size(); idx++) {
		m_particles[idx]->Update(deltaSeconds);
	}
	UpdateFlowCollisions(deltaSeconds);
	UpdateParticleCollisions(deltaSeconds);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//RENDER
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------------------------------------------------------
void FlowManager::Render() const {

	BeirusRenderer::DrawLine(Vector3(LEFT_PLANE, FLOOR_PLANE), Vector3(RIGHT_PLANE, FLOOR_PLANE), RGBA::GREEN);

	for (size_t idx = 0; idx < m_particles.size(); idx++) {
		m_particles[idx]->Render();
	}
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//SPAWNING
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------------------------------------------------------
void FlowManager::SpawnParticle(const Vector3& pos) {

	Particle* newParticle = new Particle(pos, 0.2f);
	m_particles.push_back(newParticle);
}