#pragma once
#include "State.h"

class InGameState : State
{
private:

public:
	sf::Font* font;
	sf::Texture bgTexture;
	sf::Sprite bgSprite;

	InGameState(sf::RenderWindow* window);
	virtual ~InGameState();

	void endState();
	void updateInput(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target);
};


