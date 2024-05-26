#include "Brick.h"

Brick::Brick::Brick(float width, float height, const sf::Vector2f& position)
{


	this->transform = new Transform();
	this->rect = new sf::RectangleShape(sf::Vector2f(width, height));//50.0f, 20.0f

	this->rect->setFillColor(sf::Color::White);
	this->rect->setOutlineThickness(1.f);
	this->rect->setOutlineColor(sf::Color::Black);

	this->transform->SetPosition(position);

	this->rect->setPosition(this->transform->GetPosition());
	this->rect->setOrigin(this->rect->getSize() / 2.f);

}

Brick::~Brick()
{	
	delete this->transform;
	delete this->rect;
}

void Brick::Update(const float& dt)
{
	// 공과의 충돌을 검사하고, OnCollision 함수를 호출합니다.
	if (this->CheckCollision(sf::Vector2f(0.f, 0.f), 0.f))
	{
		this->OnCollision(this);
		delete this;
	}
}

void Brick::Render(sf::RenderTarget* target)
{
	target->draw(*this->rect);
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

void Brick::OnCollision(GameObject* other)
{
	// 충돌이 발생했을 때 호출되는 함수입니다.
	// 공과의 좌표 차이를 계산하여, 공의 속도를 직접 조절합니다.
}

sf::RectangleShape& Brick::getShape() {
	return *rect; // 공의 형태 반환
}


