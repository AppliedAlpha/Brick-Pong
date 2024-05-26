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
	// ������ �浹�� �˻��ϰ�, OnCollision �Լ��� ȣ���մϴ�.
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
	// �浹�� �߻����� �� ȣ��Ǵ� �Լ��Դϴ�.
	// ������ ��ǥ ���̸� ����Ͽ�, ���� �ӵ��� ���� �����մϴ�.
}

sf::RectangleShape& Brick::getShape() {
	return *rect; // ���� ���� ��ȯ
}


