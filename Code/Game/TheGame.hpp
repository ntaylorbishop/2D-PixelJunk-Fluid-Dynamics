#pragma once

#include "Engine/General/Core/EngineCommon.hpp"
#include "Engine/Renderer/Cameras/Camera2D.hpp"

class FlowManager;

class TheGame {
public:
	//INIT DESTROY
	static void Initialize();
	static void Shutdown();

	static void Render();


	static Camera2D& GetCamera() { return s_theGame->m_camera; }


private:
	//STRUCTORS INIT
	TheGame();
	~TheGame();

	//UPDATE
	void Update(float deltaSeconds);

	//RENDER
	void InternalRender() const;


	Camera2D m_camera;
	FlowManager* m_waterFlow;

	static TheGame* s_theGame;
};