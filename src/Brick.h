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
	Brick(float width, float height, const sf::Vector2f& position);
	Brick(const Brick& object) = delete;
	
	sf::RectangleShape& getShape();

	virtual ~Brick();

	virtual void Update(const float& dt) override;
	virtual void Render(sf::RenderTarget* target) override;
	static void Clear();
};