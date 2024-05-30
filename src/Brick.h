#pragma once

#include "header/stdafx.h"
#include "Transform.h"
#include "GameObject.h"
#include "Ball.h"
#include <vector>

class Brick : public GameObject
{
protected:
	Transform* transform;
	sf::RectangleShape* rect;

public:
	Brick();
	Brick(const Brick& object) = delete;

	virtual ~Brick();

	virtual void Update(const float& dt) override;
	virtual sf::RectangleShape* GetDrawable() override;

	static void Clear();

	/// <summary>
	/// 공과의 충돌이 발생했을 때 해당 함수가 호출됩니다.
	/// </summary>
	/// <param name="other"></param>
	virtual void OnCollision(Ball* other) override;
};