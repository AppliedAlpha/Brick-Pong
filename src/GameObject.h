#pragma once
#include "header/stdafx.h"
#include "Transform.h"
#include <vector>

class GameObject
{
protected:
	static std::vector<GameObject*> objects;
	Transform* transform;
	sf::RectangleShape* rect;

	/// <summary>
	/// 공과의 충돌이 발생했을 때 해당 함수가 호출됩니다.
	/// </summary>
	/// <param name="other"></param>
	virtual void OnCollision(GameObject* other);

	// 공과의 충돌을 검사합니다.
	bool CheckCollision(sf::Vector2f otherPos, float radius);

public:
	GameObject();
	GameObject(const GameObject& object) = delete;

	virtual ~GameObject();

	virtual void Update(const float& dt) = 0;
	virtual void Render(sf::RenderTarget* target) = 0;
	static void Clear();
};