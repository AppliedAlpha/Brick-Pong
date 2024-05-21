#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


class CustomMath
{
public:
    static const int CENTER = -1;

    static sf::Vector2f GetCenterPos(float x = CENTER, float y = CENTER, float width = 0.f, float height = 0.f);
    static float GetLength(const sf::Vector2f& vector);
    static sf::Vector2f Normalize(const sf::Vector2f& vector);
};