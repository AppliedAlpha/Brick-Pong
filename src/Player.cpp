#include "Player.h"
#include "Ball.h"

void Player::InitVariables()
{
	this->rect_ = new sf::RectangleShape(sf::Vector2f(5.f, 70.f));

	this->velocity_ = sf::Vector2f(0.f, 0.f);
	this->acceleration_ = PLAYER_ACCELERATION;
	this->deceleration_ = PLAYER_DECELERATION;
	this->max_speed_ = PLAYER_MAX_SPEED;

	this->rect_->setFillColor(sf::Color::White);
	this->rect_->setOutlineThickness(1.f);

    collision_trigger_ = false;
}

sf::Vector2f Player::CalculateCollisionVelocity(
	sf::Vector2f ball_pos,
	sf::Vector2f player_pos,
	sf::Vector2f ball_velocity,
	double curvature,
	double bar_length
) {
	bool ball_is_under_player = ball_pos.y < player_pos.y;
	bool cur_moving_right = ball_velocity.x > 0;

	double dy = ball_pos.y - player_pos.y;
	if(dy < 0) dy *= -1;

	double norm_dy = dy / (bar_length * 0.5f);

	double deflection_angle = curvature * norm_dy;

	double magnitude = sqrt(pow(ball_velocity.x, 2) + pow(ball_velocity.y, 2));

	float new_x, new_y;
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

	return {new_x, new_y};
}

void Player::OnCollision(Ball* other)
{
	if (collision_trigger_) {
		//2중 연속 충돌 : 충돌 함수 무시
		return;
	}
    collision_trigger_ = true;
	// 충돌이 발생했을 때 호출되는 함수입니다.
	// 공과의 좌표 차이를 계산하여, 공의 속도를 직접 조절합니다.

	// 공의 위치
	sf::Vector2f other_pos = (other->GetShape()).getPosition();
	sf::Vector2f cur_pos = this->rect_->getPosition();

	

	sf::Vector2f new_velocity = other->GetVelocity();

	//세로로 충돌했을 경우
	if (other_pos.y > cur_pos.y + this->rect_->getSize().y ||
        other_pos.y < cur_pos.y - this->rect_->getSize().y)
	{
        new_velocity.y *= -1;
	}
	else
	{
        new_velocity = CalculateCollisionVelocity(
                other_pos,
                cur_pos,
                other->GetVelocity(),
                90,
                this->rect_->getSize().y
		);
	}

    other->SetVelocity(new_velocity);
}

void Player::ClearCollisionTrigger()
{
    collision_trigger_ = false;
}

Player::Player(int player_number)
{
	this->player_number_ = player_number;
	InitVariables();

	this->rect_ = new sf::RectangleShape(sf::Vector2f(20.f, 70.f));
	this->rect_->setPosition(
            player_number == 1 ?
            PLAYER1_START_POS :
            PLAYER2_START_POS
	);
}

Player::~Player()
{
	delete this->rect_;
	this->rect_ = nullptr;

	std::cout << "Player destroyed" << std::endl;
}

void Player::Update(const float& dt)
{
	UpdateInput(dt);
	Move(dt);
}

void Player::UpdateInput(const float& dt)
{
	bool pressed_up = sf::Keyboard::isKeyPressed(player_number_ == 1 ? PLAYER1_UP_KEY : PLAYER2_UP_KEY);
	bool pressed_down = sf::Keyboard::isKeyPressed(player_number_ == 1 ? PLAYER1_DOWN_KEY : PLAYER2_DOWN_KEY);

	//Move player
	if (pressed_up)
	{
		velocity_.y -= acceleration_;
	}
	else if (pressed_down)
	{
		velocity_.y += acceleration_;
	}

	//Limit velocity_
	if (sqrt(pow(velocity_.x, 2) + pow(velocity_.y, 2)) > max_speed_)
	{
        velocity_ = (velocity_ / (float)sqrt(pow(velocity_.x, 2) + pow(velocity_.y, 2))) * max_speed_;
	}
}

sf::RectangleShape* Player::GetDrawable()
{
	return this->rect_;
}

void Player::Move(const float& dt)
{
	//Move rect_ by velocity_
	this->rect_->move(this->velocity_ * dt);

	//Deceleration by time
	Stop(dt);

	// clamp out of map
	if (this->rect_->getPosition().y < 0.f)
	{
		this->rect_->setPosition(this->rect_->getPosition().x, 0.f);
	}
	else if (this->rect_->getPosition().y + this->rect_->getSize().y > 720)
	{
		this->rect_->setPosition(this->rect_->getPosition().x, 720 - this->rect_->getSize().y);
	}
}

void Player::Stop(const float& dt)
{
	//현재 속도의 크기 계산
	float speed = sqrt(pow(velocity_.x, 2) + pow(velocity_.y, 2));

	//감속을 적용할 크기 계산
	float deceleration = this->deceleration_ * dt;

	//새로운 속도의	크기 계산
	speed -= deceleration;

	//속도가 0보다 작으면 0으로 설정
	if (speed < 0.f)
	{
		speed = 0.f;
	}

	// 속도 벡터의 방향 유지를 위해 비율 계산
	// 0으로 나누기 방지
	sf::Vector2f new_velocity = velocity_;
	if (speed != 0.f)
	{
        new_velocity = (velocity_ / speed) * speed;
	}
	else
	{
        new_velocity = sf::Vector2f(0.f, 0.f);
	}

	//속도 적용
	this->velocity_ = new_velocity;
}
