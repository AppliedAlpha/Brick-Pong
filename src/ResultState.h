#pragma once
#include "State.h"
#include "Menu.h"

class ResultState : public State
{
public:
	sf::Font* font;
	sf::Text result_text;
	Menu* result_menu;
	int winner_num;

	ResultState(sf::RenderWindow* window, int winner);
	virtual ~ResultState();

	void InitTexts();

	int EndState();
	void UpdateInput(const float& dt);
	void Update(const float& dt);
	void Render(sf::RenderTarget* target);

private:
	CoolDown enterCool = CoolDown(0.5f);
	int exitMenuCode = -1;
};

