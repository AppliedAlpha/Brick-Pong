#include "Ball.h"

// Ball 클래스 생성자
Ball::Ball(float radius, float initial_speed, float screen_x, float screen_y, ScoreSystem* scrSystem)
    : initial_speed_(initial_speed), screen_x_(screen_x), screen_y_(screen_y) {
    shape_.setRadius(radius); // 공의 반지름 설정
    shape_.setFillColor(sf::Color::White); // 공의 색상 설정
    ResetPosition(); // 공의 초기 위치 설정

    this->scr_system_ = scrSystem;
}

// 공의 위치를 초기화하는 함수
void Ball::ResetPosition() {
    shape_.setPosition(screen_x_ / 2 - shape_.getRadius(), screen_y_ / 2 - shape_.getRadius()); // 화면 중앙으로 위치 설정
    speed_x_ = initial_speed_; // 초기 속도로 설정
    speed_y_ = 0; // 초기 속도로 설정
}

// 공을 이동시키는 함수
void Ball::Move() {
    shape_.move(speed_x_, speed_y_); // 공을 현재 속도로 이동
}

// 공이 화면의 벽과 충돌하는지 확인하고 반응하는 함수
void Ball::CheckCollisionWithWall() {
    sf::Vector2f pos = shape_.getPosition(); // 공의 현재 위치 가져오기
    if (pos.y <= 0 || pos.y >= screen_y_ - 2 * shape_.getRadius()) { // 위 또는 아래 벽과 충돌 시
        speed_y_ *= -1.0f; // y축 속도를 반전
    }

    // 양 옆 벽과 충돌 시
    if (pos.x <= 0 || pos.x >= screen_x_ - 2 * shape_.getRadius()) {
        //왼쪽 : 1, 오른쪽 : 2
        int scored_player = pos.x <= 0 ? 2 : 1;
        this->scr_system_->AddScore(scored_player);

        //초기 위치로 이동
        ResetPosition();
	}
}

// 공이 벽돌과 충돌하는지 확인하고 반응하는 함수
void Ball::CheckCollisionWithBrick(std::vector<Brick*>& bricks) {  // 메서드 정의에서 & 추가
    sf::FloatRect ballBounds = shape_.getGlobalBounds(); // 공의 경계 상자 가져오기
    for (auto it = bricks.begin(); it != bricks.end(); ) {
        if (ballBounds.intersects((*it)->GetShape().getGlobalBounds())) { // 공이 벽돌과 충돌 시
            speed_x_ *= -1.001f; // x축 속도를 약간 증가시키며 반전

            // 충돌한 벽돌 삭제
            delete* it;
            it = bricks.erase(it);
        }
        else {
            ++it;
        }
    }
}

void Ball::SetVelocity(float x, float y)
{
    speed_x_ = x;
    speed_y_ = y;
}

void Ball::SetVelocity(sf::Vector2f velocity)
{
    speed_x_ = velocity.x;
    speed_y_ = velocity.y;
}

sf::Vector2f Ball::GetVelocity() const
{
	return {speed_x_, speed_y_};
}

// 공의 형태를 반환하는 함수
sf::CircleShape& Ball::GetShape() {
    return shape_; // 공의 형태 반환
}
