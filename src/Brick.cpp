#include "Brick.h"

Birck::Birck()
{
	this->transform = new Transform();
	this->rect = new sf::RectangleShape(sf::Vector2f(50.f, 20.f));

	this->rect->setFillColor(sf::Color::White);
	this->rect->setOutlineThickness(1.f);
	this->rect->setOutlineColor(sf::Color::Black);

	this->transform->SetPosition(sf::Vector2f(0.f, 0.f));
	this->transform->SetScale(sf::Vector2f(1.f, 1.f));
	this->transform->SetRotation(0.f);

	this->rect->setPosition(this->transform->GetPosition());
	this->rect->setOrigin(this->rect->getSize() / 2.f);
	this->rect->setRotation(this->transform->GetRotation());
	this->rect->setScale(this->transform->GetScale());
}

Birck::~Birck()
{
	delete this->transform;
	delete this->rect;
}

void Birck::Update(const float& dt)
{
	// 공과의 충돌을 검사하고, OnCollision 함수를 호출합니다.
	if (this->CheckCollision(sf::Vector2f(0.f, 0.f), 0.f))
	{
		this->OnCollision(this);
		delete this;
	}
}

void Birck::Render(sf::RenderTarget* target)
{
	target->draw(*this->rect);
}

void Birck::Clear()
{
	for (auto& object : objects)
	{
		if (typeid(*object) == typeid(Birck))
			delete object;
	}

	objects.shrink_to_fit();
}

void Birck::OnCollision(GameObject* other)
{
	// 충돌이 발생했을 때 호출되는 함수입니다.
	// 공과의 좌표 차이를 계산하여, 공의 속도를 직접 조절합니다.
}


