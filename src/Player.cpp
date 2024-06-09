#include "Player.h"
#include "Ball.h"
#include "CustomFunction.h"

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
	sf::Vector2f player_pos,
	sf::Vector2f collision_pos,
	sf::Vector2f ball_velocity,
	double curvature,
	double bar_length)
{
	// 1. �浹 ������ �÷��̾� �߽� ������ ���� ���
	double col_length = collision_pos.y - player_pos.y;

	// 2. �浹 ������ ���� �����ڸ��� �������� ���� ���
	double slope = 1.0 - std::abs(col_length - bar_length / 2.0) * curvature;

	// 3. ���ο� �ӵ� ���� ���
	sf::Vector2f new_velocity = ball_velocity;

	// new velocity normalize
	new_velocity.x = ball_velocity.x * slope;
	new_velocity.y = -ball_velocity.y * slope;

	new_velocity = CustomMath::GetLength(ball_velocity) * CustomMath::Normalize(new_velocity);
	return new_velocity;
}


void Player::OnCollision(Ball* other)
{
	// �浹�� �߻����� �� ȣ��Ǵ� �Լ��Դϴ�.
	// ������ ��ǥ ���̸� ����Ͽ�, ���� �ӵ��� ���� �����մϴ�.
	if (collision_trigger_) {
		//2�� ���� �浹 : �浹 �Լ� ����
		return;
	}
    collision_trigger_ = true;

	sf::Vector2f col_position = sf::Vector2f(0, 0);
	CustomMath::CheckCollision(
		*this->rect_, other->GetShape(), col_position, other->GetVelocity()
	);

	

	sf::Vector2f new_velocity = other->GetVelocity();

	//���η� �浹���� ��� : �簢���� �� x�ȿ� ������ ���
	if (col_position.x >= this->rect_->getPosition().x && col_position.x <= this->rect_->getPosition().x + this->rect_->getSize().x)
	{
		//y�� ����
		new_velocity.y = -new_velocity.y;
	}
	else
	{
		
        new_velocity = CalculateCollisionVelocity(
				this->rect_->getOrigin(),
				col_position,
                other->GetVelocity(),
                PLAYER_CURVATURE,
                this->rect_->getSize().y
		);
		

		//x�� ����
		//new_velocity.x = -new_velocity.x;
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
	//���� �ӵ��� ũ�� ���
	float speed = sqrt(pow(velocity_.x, 2) + pow(velocity_.y, 2));

	//������ ������ ũ�� ���
	float deceleration = this->deceleration_ * dt;

	//���ο� �ӵ���	ũ�� ���
	speed -= deceleration;

	//�ӵ��� 0���� ������ 0���� ����
	if (speed < 0.f)
	{
		speed = 0.f;
	}

	// �ӵ� ������ ���� ������ ���� ���� ���
	// 0���� ������ ����
	sf::Vector2f new_velocity = velocity_;
	if (speed != 0.f)
	{
        new_velocity = (velocity_ / speed) * speed;
	}
	else
	{
        new_velocity = sf::Vector2f(0.f, 0.f);
	}

	//�ӵ� ����
	this->velocity_ = new_velocity;
}
