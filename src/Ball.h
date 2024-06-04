#pragma once
#ifndef BRICK_PONG_BALL_H
#define BRICK_PONG_BALL_H

#include <SFML/Graphics.hpp>
#include "ScoreSystem.h"
#include "Brick.h"

class Ball {
public:
    Ball(float radius, float initial_speed, float screen_x, float screen_y, ScoreSystem* scrSystem);
    void ResetPosition();
    void Move();
    void CheckCollisionWithWall();
    void CheckCollisionWithBrick(std::vector<Brick*>& bricks);
	void SetVelocity(float x, float y);
	void SetVelocity(sf::Vector2f velocity);
	sf::Vector2f GetVelocity() const;
    sf::CircleShape& GetShape();

private:
    sf::CircleShape shape_;
    float initial_speed_;
    float speed_x_{};
    float speed_y_{};
    float screen_x_;
    float screen_y_;

    ScoreSystem* scr_system_;
};

#endif
