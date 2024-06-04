#pragma once

#include "header/stdafx.h"
#include "GameObject.h"
#include <vector>

class Brick : public GameObject
{
public:
	Brick(float width, float height, const sf::Vector2f& position);
	Brick(const Brick& object) = delete;
	
	sf::RectangleShape& GetShape();

	~Brick() override;

	void Update(const float& dt) override;
	sf::RectangleShape* GetDrawable() override;
};