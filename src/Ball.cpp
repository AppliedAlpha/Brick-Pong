#include "Ball.h"
#include "CustomFunction.h"

// Ball Ŭ���� ������
Ball::Ball(float radius, float initial_speed, float screen_x, float screen_y, ScoreSystem* scrSystem)
    : initial_speed_(initial_speed), screen_x_(screen_x), screen_y_(screen_y) {
    shape_.setRadius(radius); // ���� ������ ����
    shape_.setFillColor(sf::Color::White); // ���� ���� ����
    ResetPosition(); // ���� �ʱ� ��ġ ����

    this->scr_system_ = scrSystem;
}

// ���� ��ġ�� �ʱ�ȭ�ϴ� �Լ�
void Ball::ResetPosition() {
    shape_.setPosition(screen_x_ / 2 - shape_.getRadius(), screen_y_ / 2 - shape_.getRadius()); // ȭ�� �߾����� ��ġ ����

	// magnitude = _initialSpeed
	float angle = CustomMath::GetRandomAngle(); // ������ ���� ����
	speed_x_ = initial_speed_ * cos(angle); // x�� �ӵ� ����
	speed_y_ = initial_speed_ * sin(angle); // y�� �ӵ� ����
}

// ���� �̵���Ű�� �Լ�
void Ball::Move() {
    shape_.move(speed_x_, speed_y_); // ���� ���� �ӵ��� �̵�
}

// ���� ȭ���� ���� �浹�ϴ��� Ȯ���ϰ� �����ϴ� �Լ�
void Ball::CheckCollisionWithWall() {
    sf::Vector2f pos = shape_.getPosition(); // ���� ���� ��ġ ��������
    if (pos.y <= 0 || pos.y >= screen_y_ - 2 * shape_.getRadius()) { // �� �Ǵ� �Ʒ� ���� �浹 ��
        speed_y_ *= -1.0f; // y�� �ӵ��� ����
    }

    // �� �� ���� �浹 ��
    if (pos.x <= 0 || pos.x >= screen_x_ - 2 * shape_.getRadius()) {
        //���� : 1, ������ : 2
        int scored_player = pos.x <= 0 ? 2 : 1;
        this->scr_system_->AddScore(scored_player);

        //�ʱ� ��ġ�� �̵�
        ResetPosition();
	}
}

// ���� ������ �浹�ϴ��� Ȯ���ϰ� �����ϴ� �Լ�
void Ball::CheckCollisionWithBrick(std::vector<Brick*>& bricks) {  // �޼��� ���ǿ��� & �߰�
	sf::Vector2f ball_pos = shape_.getOrigin(); // ���� ���� ��ġ ��������

    for (auto it = bricks.begin(); it != bricks.end(); ) {
		// ������ �浹 ��, intersects �Լ��� ����Ͽ� �浹 ���� Ȯ��
		if (shape_.getGlobalBounds().intersects((*it)->GetShape().getGlobalBounds())) {

			if (ball_pos.x  >= (*it)->GetShape().getPosition().x &&
                ball_pos.x <= (*it)->GetShape().getPosition().x + (*it)->GetShape().getSize().x) {
				speed_y_ *= -1.0f; // y�� �ӵ��� ����
            }
			else {
				speed_x_ *= -1.0f; // x�� �ӵ��� ����
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

// ���� ���¸� ��ȯ�ϴ� �Լ�
sf::CircleShape& Ball::GetShape() {
    return shape_; // ���� ���� ��ȯ
}
