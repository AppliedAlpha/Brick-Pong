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
	bool ball_is_under_player = ballPos.y < playerPos.y;
	bool cur_moving_right = ballVelocity.x > 0;

	double dy = ballPos.y - playerPos.y;
	if(dy < 0) dy *= -1;

	double norm_dy = dy / (barLength * 0.5f);

	double deflection_angle = curvature * norm_dy;

	double magnitude = sqrt(pow(ballVelocity.x, 2) + pow(ballVelocity.y, 2));

	double new_x, new_y;
	if (ball_is_under_player) 
	{
		new_x = magnitude * sin(deflection_angle);
		new_y = magnitude * -cos(deflection_angle);
	}
	else 
	{
		new_x = magnitude * sin(deflection_angle);
		new_y = magnitude * cos(deflection_angle);
	}

	if (cur_moving_right) new_x *= -1;

	return sf::Vector2f(new_x, new_y);
}

void Player::OnCollision(Ball* other)
{
	if (collisionTrigger) {
		//2중 연속 충돌 : 충돌 함수 무시
		return;
	}
	collisionTrigger = true;
	// 충돌이 발생했을 때 호출되는 함수입니다.
	// 공과의 좌표 차이를 계산하여, 공의 속도를 직접 조절합니다.

	// 공의 위치
	sf::Vector2f otherPos = (other->getShape()).getPosition();
	sf::Vector2f curPos = this->rect->getPosition();

	

	sf::Vector2f newVelocity = other->getVelocity();

	//세로로 충돌했을 경우
	if (otherPos.y > curPos.y + this->rect->getSize().y || 
		otherPos.y < curPos.y - this->rect->getSize().y)
	{
		newVelocity.y *= -1;
	}
	else
	{
		newVelocity = CalculateCollisionVelocity(
			otherPos,
			curPos,
			other->getVelocity(),
			90,
			this->rect->getSize().y
		);
	}

	other->setVelocity(newVelocity);
}

void Player::ClearCollisionTrigger()
{
	collisionTrigger = false;
}

Player::Player(int playerNumber)
{
	this->playerNumber = playerNumber;
	InitVariables();

	this->rect = new sf::RectangleShape(sf::Vector2f(20.f, 70.f));
	this->rect->setPosition(
		playerNumber == 1 ?
		PLAYER1_START_POS :
		PLAYER2_START_POS
	);
}

Player::~Player()
{
	delete this->rect;

	this->rect = nullptr;

	std::cout << "Player destroyed" << std::endl;
}

void Player::Update(const float& dt)
{
	UpdateInput(dt);
	Move(dt);
}

void Player::UpdateInput(const float& dt)
{
	bool pressed_up = sf::Keyboard::isKeyPressed(playerNumber == 1 ? PLAYER1_UP_KEY : PLAYER2_UP_KEY);
	bool pressed_down = sf::Keyboard::isKeyPressed(playerNumber == 1 ? PLAYER1_DOWN_KEY : PLAYER2_DOWN_KEY);

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
	//현재 속도의 크기 계산
	float speed = sqrt(pow(velocity.x, 2) + pow(velocity.y, 2));

	//감속을 적용할 크기 계산
	float deceleration = this->deceleration * dt;

	//새로운 속도의	크기 계산
	speed -= deceleration;

	//속도가 0보다 작으면 0으로 설정
	if (speed < 0.f)
	{
		speed = 0.f;
	}

	// 속도 벡터의 방향 유지를 위해 비율 계산
	// 0으로 나누기 방지
	sf::Vector2f newVelocity = velocity;
	if (speed != 0.f)
	{
		newVelocity = (velocity / speed) * speed;
	}
	else
	{
		newVelocity = sf::Vector2f(0.f, 0.f);
	}

	//속도 적용
	this->velocity = newVelocity;
}
