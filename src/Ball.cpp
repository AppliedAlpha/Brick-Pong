#include "Ball.h"

// Ball 클래스 생성자
Ball::Ball(float radius, float initial_speed, float screen_x, float screen_y, ScoreSystem* scrSystem)
    : initial_speed(initial_speed), screen_x(screen_x), screen_y(screen_y) {
    shape.setRadius(radius); // 공의 반지름 설정
    shape.setFillColor(sf::Color::White); // 공의 색상 설정
    resetPosition(); // 공의 초기 위치 설정

    this->scrSystem = scrSystem;
}

// 공의 위치를 초기화하는 함수
void Ball::resetPosition() {
    shape.setPosition(screen_x / 2 - shape.getRadius(), screen_y / 2 - shape.getRadius()); // 화면 중앙으로 위치 설정
    speed_x = initial_speed; // 초기 속도로 설정
    speed_y = initial_speed; // 초기 속도로 설정
}

// 공을 이동시키는 함수
void Ball::move() {
    shape.move(speed_x, speed_y); // 공을 현재 속도로 이동
}

// 공이 화면의 벽과 충돌하는지 확인하고 반응하는 함수
void Ball::checkCollisionWithWall() {
    sf::Vector2f pos = shape.getPosition(); // 공의 현재 위치 가져오기
    if (pos.y <= 0 || pos.y >= screen_y - 2 * shape.getRadius()) { // 위 또는 아래 벽과 충돌 시
        speed_y *= -1.0f; // y축 속도를 반전
    }

    // 양 옆 벽과 충돌 시
    if (pos.x <= 0 || pos.x >= screen_x - 2 * shape.getRadius()) {
        //왼쪽 : 1, 오른쪽 : 2
        int scoredPlayer = pos.x <= 0 ? 2 : 1;
        this->scrSystem->AddScore(scoredPlayer);

        //초기 위치로 이동
        resetPosition();
	}
}

// 공이 벽돌과 충돌하는지 확인하고 반응하는 함수
void Ball::checkCollisionWithBrick(const std::vector<sf::RectangleShape>& bricks) {
    sf::FloatRect ballBounds = shape.getGlobalBounds(); // 공의 경계 상자 가져오기
    for (const auto& brick : bricks) {
        if (ballBounds.intersects(brick.getGlobalBounds())) { // 공이 벽돌과 충돌 시
            speed_x *= -1.001f; // x축 속도를 약간 증가시키며 반전
            break;
        }
    }
}

// 공의 형태를 반환하는 함수
sf::CircleShape& Ball::getShape() {
    return shape; // 공의 형태 반환
}
