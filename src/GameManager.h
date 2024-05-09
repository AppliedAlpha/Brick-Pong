#pragma once
#include "header/stdafx.h"
#include "State.h"

class GameManager 
{
private:
	sf::RenderWindow* window;
	sf::Event event;
	sf::Image icon;

	sf::Clock dt_clock;
	float dt;

	std::deque<State*> states;
	
	void InitWindow();
	void InitStates();

public:
	GameManager();
	virtual ~GameManager();

	void UpdateDt();
	void UpdateSFMLEvents();

	void Update();
	void Render();
	void Run();
};

