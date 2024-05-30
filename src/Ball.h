#pragma once
#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include "ScoreSystem.h"
#include "Brick.h"

class Ball {
public:
    Ball(float radius, float initial_speed, float screen_x, float screen_y, ScoreSystem* scrSystem);
    void resetPosition();
    void move();
    void checkCollisionWithWall();
    void checkCollisionWithBrick(std::vector<Brick*>& bricks);
	void setVelocity(float x, float y);
	void setVelocity(sf::Vector2f velocity);
	sf::Vector2f getVelocity();
    sf::CircleShape& getShape();

private:
    sf::CircleShape shape;
    float initial_speed;
    float speed_x;
    float speed_y;
    float screen_x;
    float screen_y;

    ScoreSystem* scrSystem;
};

#endif
