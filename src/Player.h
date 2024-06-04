#pragma once
#include "header/stdafx.h"
#include "GameObject.h"
#include "Ball.h"

//defines
// 1280, 720 기준으로 설정
#define PLAYER1_START_POS sf::Vector2f(100, 360)
#define PLAYER2_START_POS sf::Vector2f(1180, 360)

#define PLAYER_ACCELERATION 20.f
#define PLAYER_DECELERATION .9f
#define PLAYER_MAX_SPEED 500.f
#define PLAYER_CURVATURE 10.f

//player_key_settings. 
//if setting system is implemented, this should be moved to a separate file.
#define PLAYER1_UP_KEY sf::Keyboard::Key::W
#define PLAYER1_DOWN_KEY sf::Keyboard::Key::S

#define PLAYER2_UP_KEY sf::Keyboard::Key::Up
#define PLAYER2_DOWN_KEY sf::Keyboard::Key::Down

class Player : public GameObject
{
private:
	int playerNumber;

	// ==============PHYSICS VARIABLES================
	sf::Vector2f velocity;
	float acceleration;
	float deceleration;

	float maxSpeed;

	// ==============FUNCTIONS================
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
	Player(int playerNumber);
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
	void OnCollision(Ball* other);
	void ClearCollisionTrigger();
};