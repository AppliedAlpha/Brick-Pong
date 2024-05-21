#pragma once
#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

class Ball {
public:
    Ball(float radius, float initial_speed, float screen_x, float screen_y);
    void resetPosition();
    void move();
    void checkCollisionWithWall();
    void checkCollisionWithBrick(const std::vector<sf::RectangleShape>& bricks);
    sf::CircleShape& getShape();

private:
    sf::CircleShape shape;
    float initial_speed;
    float speed_x;
    float speed_y;
    float screen_x;
    float screen_y;
};

#endif
