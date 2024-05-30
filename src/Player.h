#pragma once
#include "header/stdafx.h"
#include "GameObject.h"
#include "Ball.h"

//defines
#define PLAYER_START_POS sf::Vector2f(1000, 360)
#define PLAYER_ACCELERATION 20.f
#define PLAYER_DECELERATION .9f
#define PLAYER_MAX_SPEED 500.f
#define PLAYER_CURVATURE 10.f

class Player : public GameObject
{
private:
	sf::Vector2f velocity;
	float acceleration;
	float deceleration;

	float maxSpeed;

	void InitVariables();
	sf::Vector2f CalculateCollisionVelocity(
		sf::Vector2f ballPos,
		sf::Vector2f playerPos,
		sf::Vector2f ballVelocity,

		double curvature,
		double barLength
	);

	bool collisionTrigger;

protected:
	Transform* transform;
	sf::RectangleShape* rect;

public:
	Player();
	Player(const Player& object) = delete;

	virtual ~Player();

	virtual void Update(const float& dt) override;
	virtual void UpdateInput(const float& dt) override;
	virtual sf::RectangleShape* GetDrawable() override;

	void Move(const float& dt);
	void Stop(const float& dt);

	/// <summary>
	/// 공과의 충돌이 발생했을 때 해당 함수가 호출됩니다.
	/// </summary>
	/// <param name="other"></param>
	virtual void OnCollision(Ball* other) override;
	void ClearCollisionTrigger();
};