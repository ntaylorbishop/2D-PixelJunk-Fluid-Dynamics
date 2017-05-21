#pragma once

#include "Engine/General/Core/EngineCommon.hpp"

class TheGame {
public:
	//INIT DESTROY
	static void Initialize();
	static void Shutdown();

	static void Render();


private:
	//STRUCTORS INIT
	TheGame();
	~TheGame();

	//UPDATE
	void Update(float deltaSeconds);

	//RENDER
	void InternalRender() const;


	static TheGame* s_theGame;
};