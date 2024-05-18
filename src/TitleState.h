#pragma once
#include "State.h"

class TitleState : State
{
private:

public:
	sf::Font* font;
	sf::Texture bgTexture;
	sf::Sprite bgSprite;

	TitleState(sf::RenderWindow* window);
	virtual ~TitleState();

	void endState();
	void updateInput(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target);
};

