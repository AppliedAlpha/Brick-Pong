#pragma once
#include "header/stdafx.h"

/// <summary>
/// 특정 오브젝트의 위치, 크기, 회전을 관리하는 클래스입니다.
/// 이 클래스는 모든 게임 오브젝트에 Field로 존재합니다.
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