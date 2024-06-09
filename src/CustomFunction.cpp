#include "CustomFunction.h"

// ����� �޾� X�� Ȥ�� y�� �� �߾� ��ġ ��ȯ
sf::Vector2f CustomMath::GetCenterPos(float x, float y, float width, float height)
{
    if (x == CustomMath::kCenter)
        x = 640 - width / 2;
    
    if (y == CustomMath::kCenter)
        y = 360 - height / 2;
    
    return {x, y};
}

// ���� ũ�� ���ϱ�
float CustomMath::GetLength(const sf::Vector2f& vector)
{
	return std::sqrt(vector.x * vector.x + vector.y * vector.y);
}

// ���� ����ȭ (���� ������)
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

	// �浹 üũ
	if (!rect1.getGlobalBounds().intersects(circle.getGlobalBounds()))
		return false;

	// �浹 ��ġ ���, �簢���� ���� �浹 ��ġ�� ����մϴ�.
	// �浹 ��ġ�� �簢���� bound ��輱�� ��ġ�մϴ�.
	// �浹 ��ġ�� ����ϱ� ���� ���� �߽ɰ� �簢���� �߽��� ������ ������ �簢���� ��輱���� ������ ���մϴ�.

	// �簢���� �߽�
	sf::Vector2f rect_center = { rect_pos.x + rect_size.x / 2, rect_pos.y + rect_size.y / 2 };

	// �簢���� �߽ɰ� ���� �߽��� ������ ������ ����
	float slope = (circle_pos.y - rect_center.y) / (circle_pos.x - rect_center.x);

	// �簢���� ��輱�� ���� �߽��� ������ ������ ������ ���մϴ�.
	// �簢���� ��輱�� 4���� ������, ������ ������ ���մϴ�.

	// �� ��輱�� ����	
	float top_y = rect_pos.y;
	float bottom_y = rect_pos.y + rect_size.y;
	float left_x = rect_pos.x;
	float right_x = rect_pos.x + rect_size.x;

	// �� ����
	sf::Vector2f top_intersection = { (top_y - circle_pos.y) / slope + circle_pos.x, top_y };
	sf::Vector2f bottom_intersection = { (bottom_y - circle_pos.y) / slope + circle_pos.x, bottom_y };
	sf::Vector2f left_intersection = { left_x, slope * (left_x - circle_pos.x) + circle_pos.y };
	sf::Vector2f right_intersection = { right_x, slope * (right_x - circle_pos.x) + circle_pos.y };
	sf::Vector2f intersections[4] = { top_intersection, bottom_intersection, left_intersection, right_intersection };

	// ���� �� �簢���� ��輱�� ��ġ�� ������ ã���ϴ�.
	// �簢���� ��輱�� ��ġ�� ������ �簢���� ��輱�� ������ �Ÿ��� ���� ���������� �۰ų� �����ϴ�.

	// �浹 ��ġ�� ã���ϴ�.
	// ���� �߽ɿ��� �浹������ ���ϴ� ���͸� ���Ͽ�, ���� �ӵ��� ������ ������ ��찡 �ƴ϶�� valid���� �ʽ��ϴ�.

	// ������ ��ȿ���� Ȯ���ϴ� �迭
	bool is_vaild[4] = { false, false, false, false };
	for (int i = 0; i < 4; i++)
	{
		sf::Vector2f intersection = intersections[i];

		// �簢���� bound�� intersection�� �����ϴ��� Ȯ��
		if (intersection.x >= rect_pos.x && intersection.x <= rect_pos.x + rect_size.x &&
			intersection.y >= rect_pos.y && intersection.y <= rect_pos.y + rect_size.y)
		{
			// ���� �߽ɰ� ������ �Ÿ��� ���
			float distance = CustomMath::GetLength(circle_pos - intersection);

			// ���� ���������� �۰ų� ������ ��ȿ�� ����
			if (distance <= circle_radius)
			{
				is_vaild[i] = true;
			}
		}

		// ���� �߽ɿ��� �浹������ ���ϴ� ����
		sf::Vector2f collision_vector = intersection - circle_pos;

		// ���� �ӵ��� ������ ���Ͱ� �ƴ϶�� ��ȿ���� ����
		if (CustomMath::GetLength(collision_vector) != 0.0f)
		{
			sf::Vector2f normalized_velocity = CustomMath::Normalize(ball_velocity);
			sf::Vector2f normalized_collision_vector = CustomMath::Normalize(collision_vector);

			if (normalized_velocity.x != normalized_collision_vector.x || normalized_velocity.y != normalized_collision_vector.y)
			{
				is_vaild[i] = false;
			}
		}

		// ��ȿ�� �����̸� �浹 ��ġ�� ����
		if (is_vaild[i])
		{
			collision_pos = intersection;
			break;
		}
	}

	// ��ȿ�� ������ ������ �浹���� ���� ������ �Ǵ�
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
