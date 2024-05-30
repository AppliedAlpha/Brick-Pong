#pragma once
#include "State.h"
#include "Ball.h"
#include "ScoreSystem.h"
#include "Player.h"
#include "GameObject.h"

class InGameState : public State
{
private:

public:
	sf::Font* font;
	// 일단 필요하지 않을 것 같아 주석 처리
	// sf::Texture bgTexture;
	// sf::Sprite bgSprite;

	Ball* ball;
	ScoreSystem* scrSystem;
	Player* player1;
	Player* player2;

	int winner_num = -1;

	InGameState(sf::RenderWindow* window);
	virtual ~InGameState();

	virtual void CheckForQuit();

	int EndState();
	void UpdateInput(const float& dt);
	void Update(const float& dt);
	void Render(sf::RenderTarget* target);
};


