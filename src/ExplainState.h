#pragma once
#include "State.h"
#include "Menu.h"

class ExplainState : public State
{
public:
	sf::Texture bg_texture;
	sf::Sprite bg_sprite;

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

