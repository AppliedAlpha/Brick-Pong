#include "Ball.h"

// Ball Ŭ���� ������
Ball::Ball(float radius, float initial_speed, float screen_x, float screen_y)
    : initial_speed(initial_speed), screen_x(screen_x), screen_y(screen_y) {
    shape.setRadius(radius); // ���� ������ ����
    shape.setFillColor(sf::Color::White); // ���� ���� ����
    resetPosition(); // ���� �ʱ� ��ġ ����
}

// ���� ��ġ�� �ʱ�ȭ�ϴ� �Լ�
void Ball::resetPosition() {
    shape.setPosition(screen_x / 2 - shape.getRadius(), screen_y / 2 - shape.getRadius()); // ȭ�� �߾����� ��ġ ����
    speed_x = initial_speed; // �ʱ� �ӵ��� ����
    speed_y = initial_speed; // �ʱ� �ӵ��� ����
}

// ���� �̵���Ű�� �Լ�
void Ball::move() {
    shape.move(speed_x, speed_y); // ���� ���� �ӵ��� �̵�
}

// ���� ȭ���� ���� �浹�ϴ��� Ȯ���ϰ� �����ϴ� �Լ�
void Ball::checkCollisionWithWall() {
    sf::Vector2f pos = shape.getPosition(); // ���� ���� ��ġ ��������
    if (pos.y <= 0 || pos.y >= screen_y - 2 * shape.getRadius()) { // �� �Ǵ� �Ʒ� ���� �浹 ��
        speed_y *= -1.0f; // y�� �ӵ��� ����
    }
}

// ���� ������ �浹�ϴ��� Ȯ���ϰ� �����ϴ� �Լ�
void Ball::checkCollisionWithBrick(const std::vector<sf::RectangleShape>& bricks) {
    sf::FloatRect ballBounds = shape.getGlobalBounds(); // ���� ��� ���� ��������
    for (const auto& brick : bricks) {
        if (ballBounds.intersects(brick.getGlobalBounds())) { // ���� ������ �浹 ��
            speed_x *= -1.001f; // x�� �ӵ��� �ణ ������Ű�� ����
            break;
        }
    }
}

// ���� ���¸� ��ȯ�ϴ� �Լ�
sf::CircleShape& Ball::getShape() {
    return shape; // ���� ���� ��ȯ
}
