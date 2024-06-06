#pragma once
#include "State.h"
#include "Menu.h"

class ExplainState : public State
{
public:
	// sf::Font* font;
	// sf::Text title_text;

	explicit ExplainState(sf::RenderWindow* window);
	~ExplainState() override;

	// void InitTexts();

	int EndState() override;
	void UpdateInput(const float& dt) override;
	void Update(const float& dt) override;
	void Render(sf::RenderTarget* target) override;

private:
	CoolDown enter_cool_ = CoolDown(0.5f);
};

