#include "GameObject.h"
#include "Transform.h"
#include <vector>
#include <algorithm>

std::vector<GameObject*> GameObject::objects;

GameObject::GameObject()
{
	// 생성된 모든 게임 오브젝트를 저장하는 벡터에 자신을 추가합니다.
	objects.push_back(this);

	// 게임 오브젝트의 위치, 크기, 회전을 관리하는 Transform을 생성합니다.
	this->transform = new Transform();
	this->transform->SetScale(sf::Vector2f(1.f, 1.f));
	this->transform->SetPosition(sf::Vector2f(0.f, 0.f));
	this->transform->SetRotation(0.f);

	// 게임 오브젝트의 텍스처를 관리하는 사각형을 생성합니다.
	this->rect = new sf::RectangleShape();

	// 게임 오브젝트의 텍스처를 설정합니다.
	// this->SetTexture("res/texture.png");
}

GameObject::~GameObject()
{
	// 게임 오브젝트의 Transform을 삭제합니다.
	delete this->transform;

	// 게임 오븝젝트의 SpriteRenderer를 삭제합니다.
	delete this->rect;

	// 게임 오브젝트를 저장하는 벡터에서 자신을 삭제합니다.
	objects.erase(std::remove(objects.begin(), objects.end(), this), objects.end());
}

void GameObject::Render(sf::RenderTarget* target)
{
	// 게임 오브젝트의 텍스처를 transform에 기반하여 렌더링합니다.
	this->rect->setPosition(this->transform->GetPosition());
	this->rect->setScale(this->transform->GetScale());
	this->rect->setRotation(this->transform->GetRotation());

	target->draw(*this->rect);
}

void GameObject::Clear()
{
	// 생성된 모든 게임 오브젝트를 삭제합니다.
	for (auto& object : objects)
	{
		delete object;
	}

	// 벡터를 비웁니다.
	objects.clear();

	// 메모리 누수를 방지하기 위해 벡터의 capacity를 0으로 설정합니다.
	objects.shrink_to_fit();

	// 벡터의 크기가 0인지 확인합니다.
	if (objects.size() == 0)
	{
		std::cout << "All game objects are cleared." << std::endl;
	}
}

void GameObject::OnCollision(GameObject* other)
{
	// 게임 오브젝트가 충돌했을 때 호출되는 함수입니다.
	// 이 함수는 파생 클래스에서 오버라이드하여 사용합니다.
}

bool GameObject::CheckCollision(sf::Vector2f otherPos, float radius) {
	// rect의 위치와 크기 정보를 가져옵니다.
	sf::Vector2f rectPos = this->rect->getPosition();
	sf::Vector2f rectSize = this->rect->getSize();

	// 사각형의 네 모서리를 계산합니다.
	sf::Vector2f rectPoints[4] = {
		sf::Vector2f(rectPos.x - rectSize.x / 2, rectPos.y - rectSize.y / 2),
		sf::Vector2f(rectPos.x + rectSize.x / 2, rectPos.y - rectSize.y / 2),
		sf::Vector2f(rectPos.x - rectSize.x / 2, rectPos.y + rectSize.y / 2),
		sf::Vector2f(rectPos.x + rectSize.x / 2, rectPos.y + rectSize.y / 2)
	};

	// 사각형과 원의 충돌을 검사합니다.
	// 원의 중심과 사각형의 가장 가까운 점 사이의 거리를 계산합니다.
	float closestX = std::max(rectPoints[0].x, std::min(otherPos.x, rectPoints[3].x));
	float closestY = std::max(rectPoints[0].y, std::min(otherPos.y, rectPoints[3].y));

	// 원의 중심과 가장 가까운 점 사이의 거리를 계산합니다.
	float distanceX = otherPos.x - closestX;
	float distanceY = otherPos.y - closestY;
	float distance = std::sqrt((distanceX * distanceX) + (distanceY * distanceY));

	// 거리가 반지름보다 작거나 같으면 충돌합니다.
	return distance <= radius;
}