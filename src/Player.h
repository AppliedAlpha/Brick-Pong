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
#define PLAYER_CURVATURE 90.f

//player_key_settings. 
//if setting system is implemented, this should be moved to a separate file.
#define PLAYER1_UP_KEY sf::Keyboard::Key::W
#define PLAYER1_DOWN_KEY sf::Keyboard::Key::S

#define PLAYER2_UP_KEY sf::Keyboard::Key::Up
#define PLAYER2_DOWN_KEY sf::Keyboard::Key::Down

class Player : public GameObject
{
private:
	int player_number_;

	// ==============PHYSICS VARIABLES================
	sf::Vector2f velocity_;
	float acceleration_{};
	float deceleration_{};

	float max_speed_{};

	// ==============FUNCTIONS================
	void InitVariables();

	/// <summary>
	/// 공 위치와 플레이어 위치, 공의 속도, 곡률, 바의 길이를 이용하여 
	/// 공의 새로운 속도 벡터를 계산합니다.
	/// </summary>
	/// <param name="ball_pos">공의 중심좌표</param>
	/// <param name="player_pos">player의 중심좌표</param>
	/// <param name="ball_velocity">공의 속도</param>
	/// <param name="curvature">곡률, 0일경우 회전이 존재하지 않으며, 최대 90일 경우 끝에 닿으면 수직으로 튑니다.</param>
	/// <param name="bar_length">Player bar의 길이</param>
	/// <returns>계산된 공의 새로운 속도를 반환합니다. </returns>
	static sf::Vector2f CalculateCollisionVelocity(
		sf::Vector2f player_pos,
		sf::Vector2f collision_pos,
		sf::Vector2f ball_velocity,

		double curvature,
		double bar_length
	);

	bool collision_trigger_{};

protected:
//	sf::RectangleShape* rect_;

public:
	explicit Player(int player_number);
	Player(const Player& object) = delete;

	~Player() override;

	void Update(const float& dt) override;
	void UpdateInput(const float& dt) override;
	sf::RectangleShape* GetDrawable() override;

	void Move(const float& dt);
	void Stop(const float& dt);

	/// <summary>
	/// 공과의 충돌이 발생했을 때 해당 함수가 호출됩니다.
	/// </summary>
	/// <param name="other"></param>
	void OnCollision(Ball* other);
	void ClearCollisionTrigger();
};