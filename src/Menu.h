
#pragma once
#include "header/stdafx.h"

class Menu {
public:
    Menu(std::vector<std::string> vec);
    Menu(float width, float height);
    ~Menu();

    void draw(sf::RenderWindow& window);
    void moveUp();
    void moveDown();
    int getSelectedIndex() { return selectedIndex; }

    std::vector<sf::Text*> menu;

private:
    int selectedIndex = 0;
    sf::Font* font;
};
