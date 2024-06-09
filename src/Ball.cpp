#include "Ball.h"
#include "CustomFunction.h"

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

	// magnitude = _initialSpeed
	float angle = CustomMath::GetRandomAngle(); // 랜덤한 각도 설정
	speed_x_ = initial_speed_ * cos(angle); // x축 속도 설정
	speed_y_ = initial_speed_ * sin(angle); // y축 속도 설정
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
	sf::Vector2f ball_pos = shape_.getOrigin(); // 공의 현재 위치 가져오기

    for (auto it = bricks.begin(); it != bricks.end(); ) {
		// 벽돌과 충돌 시, intersects 함수를 사용하여 충돌 여부 확인
		if (shape_.getGlobalBounds().intersects((*it)->GetShape().getGlobalBounds())) {

			if (ball_pos.x  >= (*it)->GetShape().getPosition().x &&
                ball_pos.x <= (*it)->GetShape().getPosition().x + (*it)->GetShape().getSize().x) {
				speed_y_ *= -1.0f; // y축 속도를 반전
            }
			else {
				speed_x_ *= -1.0f; // x축 속도를 반전
			}


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
