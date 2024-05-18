#pragma once
#include "State.h"

class ResultState : State
{
private:

public:
	sf::Font* font;
	sf::Texture bgTexture;
	sf::Sprite bgSprite;

	ResultState(sf::RenderWindow* window);
	virtual ~ResultState();

	void endState();
	void updateInput(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target);
};

