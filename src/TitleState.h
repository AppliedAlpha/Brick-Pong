#pragma once
#include "State.h"

class TitleState : public State
{
private:

public:
	sf::Font* font;
	sf::Text title_text;
	sf::Text menu_text[3];
	// 일단 필요하지 않을 것 같아 주석 처리
	// sf::Texture bgTexture;
	// sf::Sprite bgSprite;

	TitleState(sf::RenderWindow* window);
	virtual ~TitleState();

	void InitTexts();

	void EndState();
	void UpdateInput(const float& dt);
	void Update(const float& dt);
	void Render(sf::RenderTarget* target);
};

