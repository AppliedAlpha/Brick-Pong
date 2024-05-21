#include "GameObject.h"
#include "Transform.h"
#include <vector>
#include <algorithm>

std::vector<GameObject*> GameObject::objects;

GameObject::GameObject()
{
	// ������ ��� ���� ������Ʈ�� �����ϴ� ���Ϳ� �ڽ��� �߰��մϴ�.
	objects.push_back(this);

	// ���� ������Ʈ�� ��ġ, ũ��, ȸ���� �����ϴ� Transform�� �����մϴ�.
	this->transform = new Transform();
	this->transform->SetScale(sf::Vector2f(1.f, 1.f));
	this->transform->SetPosition(sf::Vector2f(0.f, 0.f));
	this->transform->SetRotation(0.f);

	// ���� ������Ʈ�� �ؽ�ó�� �����ϴ� �簢���� �����մϴ�.
	this->rect = new sf::RectangleShape();

	// ���� ������Ʈ�� �ؽ�ó�� �����մϴ�.
	// this->SetTexture("res/texture.png");
}

GameObject::~GameObject()
{
	// ���� ������Ʈ�� Transform�� �����մϴ�.
	delete this->transform;

	// ���� ������Ʈ�� SpriteRenderer�� �����մϴ�.
	delete this->rect;

	// ���� ������Ʈ�� �����ϴ� ���Ϳ��� �ڽ��� �����մϴ�.
	objects.erase(std::remove(objects.begin(), objects.end(), this), objects.end());
}

void GameObject::Render(sf::RenderTarget* target)
{
	// ���� ������Ʈ�� �ؽ�ó�� transform�� ����Ͽ� �������մϴ�.
	this->rect->setPosition(this->transform->GetPosition());
	this->rect->setScale(this->transform->GetScale());
	this->rect->setRotation(this->transform->GetRotation());

	target->draw(*this->rect);
}

void GameObject::Clear()
{
	// ������ ��� ���� ������Ʈ�� �����մϴ�.
	for (auto& object : objects)
	{
		delete object;
	}

	// ���͸� ���ϴ�.
	objects.clear();

	// �޸� ������ �����ϱ� ���� ������ capacity�� 0���� �����մϴ�.
	objects.shrink_to_fit();

	// ������ ũ�Ⱑ 0���� Ȯ���մϴ�.
	if (objects.size() == 0)
	{
		std::cout << "All game objects are cleared." << std::endl;
	}
}

void GameObject::OnCollision(GameObject* other)
{
	// ���� ������Ʈ�� �浹���� �� ȣ��Ǵ� �Լ��Դϴ�.
	// �� �Լ��� �Ļ� Ŭ�������� �������̵��Ͽ� ����մϴ�.
}

bool GameObject::CheckCollision(sf::Vector2f otherPos, float radius) {
	// rect�� ��ġ�� ũ�� ������ �����ɴϴ�.
	sf::Vector2f rectPos = this->rect->getPosition();
	sf::Vector2f rectSize = this->rect->getSize();

	// �簢���� �� �𼭸��� ����մϴ�.
	sf::Vector2f rectPoints[4] = {
		sf::Vector2f(rectPos.x - rectSize.x / 2, rectPos.y - rectSize.y / 2),
		sf::Vector2f(rectPos.x + rectSize.x / 2, rectPos.y - rectSize.y / 2),
		sf::Vector2f(rectPos.x - rectSize.x / 2, rectPos.y + rectSize.y / 2),
		sf::Vector2f(rectPos.x + rectSize.x / 2, rectPos.y + rectSize.y / 2)
	};

	// �簢���� ���� �浹�� �˻��մϴ�.
	// ���� �߽ɰ� �簢���� ���� ����� �� ������ �Ÿ��� ����մϴ�.
	float closestX = std::max(rectPoints[0].x, std::min(otherPos.x, rectPoints[3].x));
	float closestY = std::max(rectPoints[0].y, std::min(otherPos.y, rectPoints[3].y));

	// ���� �߽ɰ� ���� ����� �� ������ �Ÿ��� ����մϴ�.
	float distanceX = otherPos.x - closestX;
	float distanceY = otherPos.y - closestY;
	float distance = std::sqrt((distanceX * distanceX) + (distanceY * distanceY));

	// �Ÿ��� ���������� �۰ų� ������ �浹�մϴ�.
	return distance <= radius;
}