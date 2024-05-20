#pragma once
#include "header/stdafx.h"

class State
{
private:
	sf::Font* font;
	sf::Text* text;

protected:
	sf::RenderWindow* window;
	bool quit;

public:
	State(sf::RenderWindow* window);
	virtual ~State();

	const bool& GetQuit() const;
	
	// 순수 가상 함수 처리
	// 모든 State들이 필수적으로 override해야 함
	virtual void EndState() = 0;
	virtual void UpdateInput(const float& dt) = 0;
	virtual void Update(const float& dt) = 0;
	virtual void Render(sf::RenderTarget* target) = 0;
};

