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

	/// <summary>
	/// �� ��ġ�� �÷��̾� ��ġ, ���� �ӵ�, ���, ���� ���̸� �̿��Ͽ� 
	/// ���� ���ο� �ӵ� ���͸� ����մϴ�.
	/// </summary>
	/// <param name="ballPos">���� �߽���ǥ</param>
	/// <param name="playerPos">player�� �߽���ǥ</param>
	/// <param name="ballVelocity">���� �ӵ�</param>
	/// <param name="curvature">���, 0�ϰ�� ȸ���� �������� ������, �ִ� 90�� ��� ���� ������ �������� Ƨ�ϴ�.</param>
	/// <param name="barLength">Player bar�� ����</param>
	/// <returns>���� ���� ���ο� �ӵ��� ��ȯ�մϴ�. </returns>
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
	/// ������ �浹�� �߻����� �� �ش� �Լ��� ȣ��˴ϴ�.
	/// </summary>
	/// <param name="other"></param>
	void OnCollision(Ball* other);
	void ClearCollisionTrigger();
};