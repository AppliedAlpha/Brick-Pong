#pragma once
#include "State.h"
#include "Menu.h"

class ResultState : public State
{
public:
	sf::Font* font;
	sf::Text result_text;
	Menu* result_menu{};
	int winner_num;

	ResultState(sf::RenderWindow* window, int winner);
	~ResultState() override;

	void InitTexts();

	int EndState() override;
	void UpdateInput(const float& dt) override;
	void Update(const float& dt) override;
	void Render(sf::RenderTarget* target) override;

private:
	CoolDown enter_cool_ = CoolDown(0.5f);
	int exit_menu_code_ = -1;
};

