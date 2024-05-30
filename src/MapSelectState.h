#pragma once
#include "State.h"

class MapSelectState : public State
{
private:

public:
	sf::Font* font;
	// 일단 필요하지 않을 것 같아 주석 처리
	// sf::Texture bgTexture;
	// sf::Sprite bgSprite;

	MapSelectState(sf::RenderWindow* window);
	virtual ~MapSelectState();

	int EndState();
	void UpdateInput(const float& dt);
	void Update(const float& dt);
	void Render(sf::RenderTarget* target);
};

