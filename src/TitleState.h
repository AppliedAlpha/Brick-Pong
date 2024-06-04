#pragma once
#include "State.h"
#include "Menu.h"

class TitleState : public State
{
public:
	sf::Font* font;
	sf::Text title_text;
	Menu* title_menu{};
	// 일단 필요하지 않을 것 같아 주석 처리
	// sf::Texture bgTexture;
	// sf::Sprite bgSprite;

	explicit TitleState(sf::RenderWindow* window);
	~TitleState() override;

	void InitTexts();

	int EndState() override;
	void UpdateInput(const float& dt) override;
	void Update(const float& dt) override;
	void Render(sf::RenderTarget* target) override;

private:
	CoolDown enter_cool_ = CoolDown(0.5f);
	int exit_menu_code_ = -1;
};

