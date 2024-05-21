#pragma once
#include "header/stdafx.h"

/// <summary>
/// Ư�� ������Ʈ�� ��ġ, ũ��, ȸ���� �����ϴ� Ŭ�����Դϴ�.
/// �� Ŭ������ ��� ���� ������Ʈ�� Field�� �����մϴ�.
/// </summary>
class Transform
{
private:
	sf::Vector2f position;
	sf::Vector2f scale;
	float rotation;

public:
	Transform();
	Transform(const sf::Vector2f& position, const sf::Vector2f& scale, const float& rotation);
	Transform(const Transform& transform);
	Transform(const sf::Vector2f& position);

	virtual ~Transform();

	const sf::Vector2f& GetPosition() const;
	const float& GetRotation() const;
	const sf::Vector2f& GetScale() const;

	void SetPosition(const sf::Vector2f& position);
	void SetScale(const sf::Vector2f& scale);
	void SetRotation(const float& rotation);
};