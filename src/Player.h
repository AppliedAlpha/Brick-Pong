#pragma once
#include "header/stdafx.h"
#include "GameObject.h"
#include "Ball.h"

//defines
// 1280, 720 �������� ����
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
	/// �� ��ġ�� �÷��̾� ��ġ, ���� �ӵ�, ���, ���� ���̸� �̿��Ͽ� 
	/// ���� ���ο� �ӵ� ���͸� ����մϴ�.
	/// </summary>
	/// <param name="ball_pos">���� �߽���ǥ</param>
	/// <param name="player_pos">player�� �߽���ǥ</param>
	/// <param name="ball_velocity">���� �ӵ�</param>
	/// <param name="curvature">���, 0�ϰ�� ȸ���� �������� ������, �ִ� 90�� ��� ���� ������ �������� Ƨ�ϴ�.</param>
	/// <param name="bar_length">Player bar�� ����</param>
	/// <returns>���� ���� ���ο� �ӵ��� ��ȯ�մϴ�. </returns>
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
	/// ������ �浹�� �߻����� �� �ش� �Լ��� ȣ��˴ϴ�.
	/// </summary>
	/// <param name="other"></param>
	void OnCollision(Ball* other);
	void ClearCollisionTrigger();
};