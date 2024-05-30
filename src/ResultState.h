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

	sf::Text result_text;
	sf::Text menu_text[2];
	int winner_num;

	ResultState(sf::RenderWindow* window, int winner);
	virtual ~ResultState();

	void InitTexts();

	void EndState();
	void UpdateInput(const float& dt);
	void Update(const float& dt);
	void Render(sf::RenderTarget* target);
};

