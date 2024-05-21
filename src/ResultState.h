#pragma once
#include "State.h"

class ResultState : public State
{
private:

public:
	sf::Font* font;
	// 일단 필요하지 않을 것 같아 주석 처리
	// sf::Texture bgTexture;
	// sf::Sprite bgSprite;

	ResultState(sf::RenderWindow* window);
	virtual ~ResultState();

	void EndState();
	void UpdateInput(const float& dt);
	void Update(const float& dt);
	void Render(sf::RenderTarget* target);
};

