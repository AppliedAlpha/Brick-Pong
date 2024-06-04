#pragma once
#include "State.h"
#include "Ball.h"
#include "Brick.h"
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
	ScoreSystem* scr_system;
	std::vector<Brick*> bricks;
	std::pair<Player*, Player*> players;

	int winner_num = -1;

	explicit InGameState(sf::RenderWindow* window);
	~InGameState() override;

	void CheckForQuit() override;

	int EndState() override;
	void UpdateInput(const float& dt) override;
	void Update(const float& dt) override;
	void Render(sf::RenderTarget* target) override;
};


