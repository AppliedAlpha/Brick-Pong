#pragma once
#include "header/stdafx.h"
#include "State.h"
#include "TitleState.h"
#include "InGameState.h"
#include "ResultState.h"
#include "ExplainState.h"

class GameManager 
{
private:
	sf::RenderWindow* window_;
	sf::Event event_;
	sf::Image icon_;

	sf::Clock dt_clock_;
	float dt_;

	std::deque<State*> states_;
	
	void InitWindow();
	void InitStates();

public:
	GameManager();
	virtual ~GameManager();

	void UpdateDt();
	void UpdateSfmlEvents();

	void Update();
	void Render();
	void Run();
};

