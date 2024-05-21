#include "CustomFunction.h"

// ����� �޾� X�� Ȥ�� y�� �� �߾� ��ġ ��ȯ
sf::Vector2f CustomMath::GetCenterPos(float x, float y, float width, float height)
{
    if (x == CustomMath::CENTER)
        x = 640 - width / 2;
    
    if (y == CustomMath::CENTER)
        y = 360 - height / 2;
    
    return sf::Vector2f(x, y);
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
		return sf::Vector2f(vector.x / length, vector.y / length);
	else 
		return vector;
}