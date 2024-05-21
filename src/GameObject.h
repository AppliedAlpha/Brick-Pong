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
	/// ������ �浹�� �߻����� �� �ش� �Լ��� ȣ��˴ϴ�.
	/// </summary>
	/// <param name="other"></param>
	virtual void OnCollision(GameObject* other);

	// ������ �浹�� �˻��մϴ�.
	bool CheckCollision(sf::Vector2f otherPos, float radius);

public:
	GameObject();
	GameObject(const GameObject& object) = delete;

	virtual ~GameObject();

	virtual void Update(const float& dt) = 0;
	virtual void Render(sf::RenderTarget* target) = 0;
	static void Clear();
};