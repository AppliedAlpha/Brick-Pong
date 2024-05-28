#include "Player.h"
#include "Ball.h"

void Player::InitVariables()
{
	this->rect = new sf::RectangleShape(sf::Vector2f(5.f, 70.f));

	this->velocity = sf::Vector2f(0.f, 0.f);
	this->acceleration = PLAYER_ACCELERATION;
	this->deceleration = PLAYER_DECELERATION;
	this->maxSpeed = PLAYER_MAX_SPEED;

	this->rect->setFillColor(sf::Color::White);
	this->rect->setOutlineThickness(1.f);

	collisionTrigger = false;
}

sf::Vector2f Player::CalculateCollisionVelocity(
	sf::Vector2f ballPos,
	sf::Vector2f playerPos,
	sf::Vector2f ballVelocity,
	double curvature,
	double barLength
) {
	double dy = ballPos.y - playerPos.y;

	double norm_dy = dy / (barLength * 0.5f);

	double deflection_angle = curvature * norm_dy;

	double magnitude = sqrt(pow(ballVelocity.x, 2) + pow(ballVelocity.y, 2));

	double new_x = magnitude * cos(deflection_angle);
	double new_y = magnitude * sin(deflection_angle);

	return sf::Vector2f(new_x, new_y);
}

void Player::OnCollision(Ball* other)
{
	if (collisionTrigger) {
		//2�� ���� �浹 : �浹 �Լ� ����
		return;
	}
	collisionTrigger = true;
	// �浹�� �߻����� �� ȣ��Ǵ� �Լ��Դϴ�.
	// ������ ��ǥ ���̸� ����Ͽ�, ���� �ӵ��� ���� �����մϴ�.

	// ���� ��ġ
	sf::Vector2f otherPos = (other->getShape()).getPosition();
	sf::Vector2f curPos = this->rect->getPosition();

	

	sf::Vector2f newVelocity = other->getVelocity();

	//���η� �浹���� ���
	if (otherPos.y > curPos.y + this->rect->getSize().y || 
		otherPos.y < curPos.y - this->rect->getSize().y)
	{
		newVelocity.y *= -1;
	}
	else
	{
		//newVelocity = CalculateCollisionVelocity(
		//otherPos,
		//curPos,
		//newVelocity,
		//PLAYER_CURVATURE,
		//this->rect->getSize().y * 2
		//);
		
		newVelocity.x *= -1;
	}

	other->setVelocity(newVelocity);
}

void Player::ClearCollisionTrigger()
{
	collisionTrigger = false;
}

Player::Player()
{
	InitVariables();

	this->rect = new sf::RectangleShape(sf::Vector2f(20.f, 70.f));
	this->rect->setPosition(PLAYER_START_POS);
}

Player::~Player()
{
	delete this->rect;
	delete this->transform;

	this->rect = nullptr;
	this->transform = nullptr;

	std::cout << "Player destroyed" << std::endl;
}

void Player::Update(const float& dt)
{
	UpdateInput(dt);
	Move(dt);
}

void Player::UpdateInput(const float& dt)
{
	bool pressed_up = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
	bool pressed_down = sf::Keyboard::isKeyPressed(sf::Keyboard::S);

	//Move player
	if (pressed_up)
	{
		velocity.y -= acceleration;
	}
	else if (pressed_down)
	{
		velocity.y += acceleration;
	}

	//Limit velocity
	if (sqrt(pow(velocity.x, 2) + pow(velocity.y, 2)) > maxSpeed)
	{
		velocity = (velocity / (float)sqrt(pow(velocity.x, 2) + pow(velocity.y, 2))) * maxSpeed;
	}
}

sf::RectangleShape* Player::GetDrawable()
{
	return this->rect;
}

void Player::Move(const float& dt)
{
	//move rect by velocity
	this->rect->move(this->velocity * dt);

	//Deceleration by time
	Stop(dt);

	// clamp out of map
	if (this->rect->getPosition().y < 0.f)
	{
		this->rect->setPosition(this->rect->getPosition().x, 0.f);
	}
	else if (this->rect->getPosition().y + this->rect->getSize().y > 720)
	{
		this->rect->setPosition(this->rect->getPosition().x, 720 - this->rect->getSize().y);
	}
}

void Player::Stop(const float& dt)
{
	//���� �ӵ��� ũ�� ���
	float speed = sqrt(pow(velocity.x, 2) + pow(velocity.y, 2));

	//������ ������ ũ�� ���
	float deceleration = this->deceleration * dt;

	//���ο� �ӵ���	ũ�� ���
	speed -= deceleration;

	//�ӵ��� 0���� ������ 0���� ����
	if (speed < 0.f)
	{
		speed = 0.f;
	}

	// �ӵ� ������ ���� ������ ���� ���� ���
	// 0���� ������ ����
	sf::Vector2f newVelocity = velocity;
	if (speed != 0.f)
	{
		newVelocity = (velocity / speed) * speed;
	}
	else
	{
		newVelocity = sf::Vector2f(0.f, 0.f);
	}

	//�ӵ� ����
	this->velocity = newVelocity;
}