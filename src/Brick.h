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
	/// 공과의 충돌이 발생했을 때 해당 함수가 호출됩니다.
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