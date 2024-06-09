#include "CustomFunction.h"

// 사이즈를 받아 X축 혹은 y축 상 중앙 위치 반환
sf::Vector2f CustomMath::GetCenterPos(float x, float y, float width, float height)
{
    if (x == CustomMath::kCenter)
        x = 640 - width / 2;
    
    if (y == CustomMath::kCenter)
        y = 360 - height / 2;
    
    return {x, y};
}

// 벡터 크기 구하기
float CustomMath::GetLength(const sf::Vector2f& vector)
{
	return std::sqrt(vector.x * vector.x + vector.y * vector.y);
}

// 벡터 정규화 (방향 정보만)
sf::Vector2f CustomMath::Normalize(const sf::Vector2f& vector) {	
	float length = CustomMath::GetLength(vector);
	
	if (length != 0.0f)
		return {vector.x / length, vector.y / length};
	else 
		return vector;
}

bool CustomMath::CheckCollision(const sf::RectangleShape& rect1, const sf::CircleShape& circle, sf::Vector2f& collision_pos, const sf::Vector2f& ball_velocity)
{
	sf::Vector2f circle_pos = circle.getPosition();
	sf::Vector2f rect_pos = rect1.getPosition();
	sf::Vector2f rect_size = { rect1.getSize().x, rect1.getSize().y };
	float circle_radius = circle.getRadius();

	// 충돌 체크
	if (!rect1.getGlobalBounds().intersects(circle.getGlobalBounds()))
		return false;

	// 충돌 위치 계산, 사각형과 원의 충돌 위치를 계산합니다.
	// 충돌 위치는 사각형의 bound 경계선에 위치합니다.
	// 충돌 위치를 계산하기 위해 원의 중심과 사각형의 중심을 연결한 직선과 사각형의 경계선과의 교점을 구합니다.

	// 사각형의 중심
	sf::Vector2f rect_center = { rect_pos.x + rect_size.x / 2, rect_pos.y + rect_size.y / 2 };

	// 사각형의 중심과 원의 중심을 연결한 직선의 기울기
	float slope = (circle_pos.y - rect_center.y) / (circle_pos.x - rect_center.x);

	// 사각형의 경계선과 원의 중심을 연결한 직선의 교점을 구합니다.
	// 사각형의 경계선은 4개가 있으며, 각각의 교점을 구합니다.

	// 네 경계선의 직선	
	float top_y = rect_pos.y;
	float bottom_y = rect_pos.y + rect_size.y;
	float left_x = rect_pos.x;
	float right_x = rect_pos.x + rect_size.x;

	// 네 교점
	sf::Vector2f top_intersection = { (top_y - circle_pos.y) / slope + circle_pos.x, top_y };
	sf::Vector2f bottom_intersection = { (bottom_y - circle_pos.y) / slope + circle_pos.x, bottom_y };
	sf::Vector2f left_intersection = { left_x, slope * (left_x - circle_pos.x) + circle_pos.y };
	sf::Vector2f right_intersection = { right_x, slope * (right_x - circle_pos.x) + circle_pos.y };
	sf::Vector2f intersections[4] = { top_intersection, bottom_intersection, left_intersection, right_intersection };

	// 교점 중 사각형의 경계선에 위치한 교점을 찾습니다.
	// 사각형의 경계선에 위치한 교점은 사각형의 경계선과 교점의 거리가 원의 반지름보다 작거나 같습니다.

	// 충돌 위치를 찾습니다.
	// 원의 중심에서 충돌점으로 향하는 벡터를 구하여, 공의 속도와 평행한 벡터일 경우가 아니라면 valid하지 않습니다.

	// 교점이 유효한지 확인하는 배열
	bool is_vaild[4] = { false, false, false, false };
	for (int i = 0; i < 4; i++)
	{
		sf::Vector2f intersection = intersections[i];

		// 사각형의 bound가 intersection을 포함하는지 확인
		if (intersection.x >= rect_pos.x && intersection.x <= rect_pos.x + rect_size.x &&
			intersection.y >= rect_pos.y && intersection.y <= rect_pos.y + rect_size.y)
		{
			// 원의 중심과 교점의 거리를 계산
			float distance = CustomMath::GetLength(circle_pos - intersection);

			// 원의 반지름보다 작거나 같으면 유효한 교점
			if (distance <= circle_radius)
			{
				is_vaild[i] = true;
			}
		}

		// 공의 중심에서 충돌점으로 향하는 벡터
		sf::Vector2f collision_vector = intersection - circle_pos;

		// 공의 속도와 평행한 벡터가 아니라면 유효하지 않음
		if (CustomMath::GetLength(collision_vector) != 0.0f)
		{
			sf::Vector2f normalized_velocity = CustomMath::Normalize(ball_velocity);
			sf::Vector2f normalized_collision_vector = CustomMath::Normalize(collision_vector);

			if (normalized_velocity.x != normalized_collision_vector.x || normalized_velocity.y != normalized_collision_vector.y)
			{
				is_vaild[i] = false;
			}
		}

		// 유효한 교점이면 충돌 위치로 설정
		if (is_vaild[i])
		{
			collision_pos = intersection;
			break;
		}
	}

	// 유효한 교점이 없으면 충돌하지 않은 것으로 판단
	if (!is_vaild[0] && !is_vaild[1] && !is_vaild[2] && !is_vaild[3])
		return false;	

	return true;
}

float CustomMath::GetRandomAngle()
{
	// set rand seed to current time
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	return (std::rand() % 360) * 3.141592 / 180;
}
