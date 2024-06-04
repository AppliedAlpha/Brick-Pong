#include "GameObject.h"
#include <vector>
#include <algorithm>

GameObject::GameObject()
{
	// ���� ������Ʈ�� �ؽ�ó�� �����ϴ� �簢���� �����մϴ�.
	this->rect_ = new sf::RectangleShape();

	// ���� ������Ʈ�� �ؽ�ó�� �����մϴ�.
	// this->SetTexture("res/texture.png");
}

GameObject::~GameObject() = default;

bool GameObject::CheckCollision(sf::Vector2f other_pos, float radius) {
	// rect�� ��ġ�� ũ�� ������ �����ɴϴ�.
	sf::Vector2f rect_pos = this->rect_->getPosition();
	sf::Vector2f rect_size = this->rect_->getSize();

	// �簢���� �� �𼭸��� ����մϴ�.
	sf::Vector2f rect_points[4] = {
		sf::Vector2f(rect_pos.x - rect_size.x / 2, rect_pos.y - rect_size.y / 2),
		sf::Vector2f(rect_pos.x + rect_size.x / 2, rect_pos.y - rect_size.y / 2),
		sf::Vector2f(rect_pos.x - rect_size.x / 2, rect_pos.y + rect_size.y / 2),
		sf::Vector2f(rect_pos.x + rect_size.x / 2, rect_pos.y + rect_size.y / 2)
	};

	// �簢���� ���� �浹�� �˻��մϴ�.
	// ���� �߽ɰ� �簢���� ���� ����� �� ������ �Ÿ��� ����մϴ�.
	float closest_x = std::max(rect_points[0].x, std::min(other_pos.x, rect_points[3].x));
	float closest_y = std::max(rect_points[0].y, std::min(other_pos.y, rect_points[3].y));

	// ���� �߽ɰ� ���� ����� �� ������ �Ÿ��� ����մϴ�.
	float distance_x = other_pos.x - closest_x;
	float distance_y = other_pos.y - closest_y;
	float distance = std::sqrt((distance_x * distance_x) + (distance_y * distance_y));

	// �Ÿ��� ���������� �۰ų� ������ �浹�մϴ�.
	return distance <= radius;
}

sf::RectangleShape* GameObject::GetDrawable()
{
	// ���� ������Ʈ�� �ؽ�ó�� ��ȯ�մϴ�.
	return this->rect_;
}

void GameObject::UpdateInput(const float& dt)
{
	// ���� ������Ʈ�� �Է��� ������Ʈ�մϴ�.
	// �� �Լ��� �Ļ� Ŭ�������� �������̵��Ͽ� ����մϴ�.
}