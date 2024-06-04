#include "GameObject.h"
#include <vector>
#include <algorithm>

GameObject::GameObject()
{
	// 게임 오브젝트의 텍스처를 관리하는 사각형을 생성합니다.
	this->rect_ = new sf::RectangleShape();

	// 게임 오브젝트의 텍스처를 설정합니다.
	// this->SetTexture("res/texture.png");
}

GameObject::~GameObject() = default;

bool GameObject::CheckCollision(sf::Vector2f other_pos, float radius) {
	// rect의 위치와 크기 정보를 가져옵니다.
	sf::Vector2f rect_pos = this->rect_->getPosition();
	sf::Vector2f rect_size = this->rect_->getSize();

	// 사각형의 네 모서리를 계산합니다.
	sf::Vector2f rect_points[4] = {
		sf::Vector2f(rect_pos.x - rect_size.x / 2, rect_pos.y - rect_size.y / 2),
		sf::Vector2f(rect_pos.x + rect_size.x / 2, rect_pos.y - rect_size.y / 2),
		sf::Vector2f(rect_pos.x - rect_size.x / 2, rect_pos.y + rect_size.y / 2),
		sf::Vector2f(rect_pos.x + rect_size.x / 2, rect_pos.y + rect_size.y / 2)
	};

	// 사각형과 원의 충돌을 검사합니다.
	// 원의 중심과 사각형의 가장 가까운 점 사이의 거리를 계산합니다.
	float closest_x = std::max(rect_points[0].x, std::min(other_pos.x, rect_points[3].x));
	float closest_y = std::max(rect_points[0].y, std::min(other_pos.y, rect_points[3].y));

	// 원의 중심과 가장 가까운 점 사이의 거리를 계산합니다.
	float distance_x = other_pos.x - closest_x;
	float distance_y = other_pos.y - closest_y;
	float distance = std::sqrt((distance_x * distance_x) + (distance_y * distance_y));

	// 거리가 반지름보다 작거나 같으면 충돌합니다.
	return distance <= radius;
}

sf::RectangleShape* GameObject::GetDrawable()
{
	// 게임 오브젝트의 텍스처를 반환합니다.
	return this->rect_;
}

void GameObject::UpdateInput(const float& dt)
{
	// 게임 오브젝트의 입력을 업데이트합니다.
	// 이 함수는 파생 클래스에서 오버라이드하여 사용합니다.
}