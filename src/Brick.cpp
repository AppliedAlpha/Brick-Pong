#include "Brick.h"

Brick::Brick::Brick(float width, float height, const sf::Vector2f& position)
{
	this->rect_ = new sf::RectangleShape(sf::Vector2f(width, height));//50.0f, 20.0f

	this->rect_->setFillColor(sf::Color::White);
	this->rect_->setOutlineThickness(1.f);
	this->rect_->setOutlineColor(sf::Color::Black);
	this->rect_->setPosition(position);
	this->rect_->setOrigin(this->rect_->getSize() / 2.f);

}

Brick::~Brick() {
    delete this->rect_;
    this->rect_ = nullptr;
}

void Brick::Update(const float& dt)
{
	// 공과의 충돌을 검사하고, OnCollision 함수를 호출합니다.
	if (this->CheckCollision(sf::Vector2f(0.f, 0.f), 0.f))
	{
		//this->OnCollision(this);
		//delete this;
	}
}

sf::RectangleShape* Brick::GetDrawable()
{
	return this->rect_;
}

sf::RectangleShape& Brick::GetShape() {
	return *rect_; // 공의 형태 반환
}


