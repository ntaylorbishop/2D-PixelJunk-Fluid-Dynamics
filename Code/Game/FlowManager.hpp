#pragma once

#include "Engine/General/Core/EngineCommon.hpp"
#include "Engine/Math/Vector3.hpp"

class Particle;

const float FLOOR_PLANE = -4.f;
const float LEFT_PLANE	= -4.f;
const float RIGHT_PLANE = 4.f;

class FlowManager {
public:
	//STRUCTORS
	FlowManager();
	~FlowManager();

	//UPDATE
	void UpdateFlowCollisions(float deltaSeconds);
	void UpdateParticleCollisions(float deltaSeconds);
	void Update(float deltaSeconds);

	//RENDER
	void Render() const;

	//SPAWN
	void SpawnParticle(const Vector3& pos);

private:
	std::vector<Particle*> m_particles;
};