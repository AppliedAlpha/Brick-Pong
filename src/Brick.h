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
	/// ������ �浹�� �߻����� �� �ش� �Լ��� ȣ��˴ϴ�.
	/// </summary>
	/// <param name="other"></param>
	virtual void OnCollision(Ball* other) override;
};