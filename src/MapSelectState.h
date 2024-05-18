#pragma once
#include "State.h"

class MapSelectState : State
{
private:

public:
	sf::Font* font;
	sf::Texture bgTexture;
	sf::Sprite bgSprite;

	MapSelectState(sf::RenderWindow* window);
	virtual ~MapSelectState();

	void endState();
	void updateInput(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target);
};

