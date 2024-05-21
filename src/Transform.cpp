#include "Transform.h"

const sf::Vector2f& Transform::GetScale() const
{
	return this->scale;
}

const sf::Vector2f& Transform::GetPosition() const
{
	return this->position;
}

const float& Transform::GetRotation() const
{
	return this->rotation;
}

void Transform::SetScale(const sf::Vector2f& scale)
{
	this->scale = scale;
}

void Transform::SetPosition(const sf::Vector2f& position)
{
	this->position = position;
}

void Transform::SetRotation(const float& rotation)
{
	this->rotation = rotation;
}

Transform::Transform()
{
	this->position = sf::Vector2f(0.f, 0.f);
	this->scale = sf::Vector2f(1.f, 1.f);
	this->rotation = 0.f;
}

Transform::Transform(const sf::Vector2f& position, const sf::Vector2f& scale, const float& rotation)
{
	this->position = position;
	this->scale = scale;
	this->rotation = rotation;
}

Transform::Transform(const Transform& transform)
{
	this->position = transform.position;
	this->scale = transform.scale;
	this->rotation = transform.rotation;
}

Transform::Transform(const sf::Vector2f& position)
{
	this->position = position;
	this->scale = sf::Vector2f(1.f, 1.f);
	this->rotation = 0.f;
}

Transform::~Transform()
{}
