#include "Brick.h"

Brick::Brick::Brick(float width, float height, const sf::Vector2f& position)
{
	this->rect = new sf::RectangleShape(sf::Vector2f(width, height));//50.0f, 20.0f

	this->rect->setFillColor(sf::Color::White);
	this->rect->setOutlineThickness(1.f);
	this->rect->setOutlineColor(sf::Color::Black);
	this->rect->setPosition(position);
	this->rect->setOrigin(this->rect->getSize() / 2.f);

}

Brick::~Brick()
{	
	delete this->rect;
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
	return this->rect;
}

void Brick::Clear()
{
	for (auto& object : objects)
	{
		if (typeid(*object) == typeid(Brick))
			delete object;
	}

	objects.shrink_to_fit();
}

sf::RectangleShape& Brick::getShape() {
	return *rect; // 공의 형태 반환
}


