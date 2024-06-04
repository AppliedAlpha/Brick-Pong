#pragma once
#include "header/stdafx.h"
#include <vector>

class GameObject
{
protected:
    sf::RectangleShape* rect_;

	// 공과의 충돌을 검사합니다.
	bool CheckCollision(sf::Vector2f other_pos, float radius);

public:
	GameObject();
	GameObject(const GameObject& object) = delete;

	virtual ~GameObject();

	virtual void Update(const float& dt) = 0;
	virtual void UpdateInput(const float& dt);

	virtual sf::RectangleShape* GetDrawable();
};