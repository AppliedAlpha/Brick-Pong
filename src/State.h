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
	
	void EndState();
	void UpdateInput(const float& dt);
	void Update(const float& dt);
	void Render(sf::RenderTarget* target);
};

