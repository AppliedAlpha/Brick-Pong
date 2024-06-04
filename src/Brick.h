#pragma once

#include "header/stdafx.h"
#include "GameObject.h"
#include <vector>

class Brick : public GameObject
{
protected:
	sf::RectangleShape* rect;

public:
	Brick(float width, float height, const sf::Vector2f& position);
	Brick(const Brick& object) = delete;
	
	sf::RectangleShape& getShape();

	virtual ~Brick();

	virtual void Update(const float& dt) override;
	virtual sf::RectangleShape* GetDrawable() override;

	static void Clear();
};