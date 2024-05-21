#pragma once

#include "header/stdafx.h"
#include "Transform.h"
#include "GameObject.h"
#include <vector>

class Brick : public GameObject
{
protected:
	Transform* transform;
	sf::RectangleShape* rect;

	/// <summary>
	/// ������ �浹�� �߻����� �� �ش� �Լ��� ȣ��˴ϴ�.
	/// </summary>
	/// <param name="other"></param>
	virtual void OnCollision(GameObject* other) override;
public:
	Brick();
	Brick(const Brick& object) = delete;

	virtual ~Brick();

	virtual void Update(const float& dt) override;
	virtual void Render(sf::RenderTarget* target) override;
	static void Clear();
};