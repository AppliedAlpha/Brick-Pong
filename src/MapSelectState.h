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

	explicit MapSelectState(sf::RenderWindow* window);
	~MapSelectState() override;

	int EndState() override;
	void UpdateInput(const float& dt) override;
	void Update(const float& dt) override;
	void Render(sf::RenderTarget* target) override;
};

