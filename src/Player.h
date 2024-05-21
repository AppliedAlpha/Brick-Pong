#pragma once
#include "header/stdafx.h"
#include "GameObject.h"

class Player : public GameObject
{
private:
	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	sf::Vector2f maxVelocity;
	sf::Vector2f minVelocity;

	float accelerationSpeed;
	float decelerationSpeed;
	float maxSpeed;
	float minSpeed;

	void InitVariables();

protected:
	Transform* transform;
	sf::RectangleShape* rect;

	/// <summary>
	/// 공과의 충돌이 발생했을 때 해당 함수가 호출됩니다.
	/// </summary>
	/// <param name="other"></param>
	virtual void OnCollision(GameObject* other) override;

public:
	Player();
	Player(const Player& object) = delete;

	virtual ~Player();

	virtual void Update(const float& dt) override;
	virtual void Render(sf::RenderTarget* target) override;

	void Move(const float& dt, const float dir_x, const float dir_y);
	void Stop(const float& dt);
	void SetVelocity(const sf::Vector2f& velocity);
	void SetAcceleration(const sf::Vector2f& acceleration);
	void SetMaxVelocity(const sf::Vector2f& maxVelocity);
	void SetMinVelocity(const sf::Vector2f& minVelocity);
	void SetAccelerationSpeed(const float& accelerationSpeed);
	void SetDecelerationSpeed(const float& decelerationSpeed);
	void SetMaxSpeed(const float& maxSpeed);
	void SetMinSpeed(const float& minSpeed);
	const sf::Vector2f& GetVelocity() const;
	const sf::Vector2f& GetAcceleration() const;
	const sf::Vector2f& GetMaxVelocity() const;
	const sf::Vector2f& GetMinVelocity() const;
	const float& GetAccelerationSpeed() const;
	const float& GetDecelerationSpeed() const;
	const float& GetMaxSpeed() const;
	const float& GetMinSpeed() const;

	static void Clear();
};