#pragma once
#include "header/stdafx.h"

class Menu {
public:
    Menu(std::vector<std::string> vec);
    ~Menu();

    void updateInput(const float& dt);
    void moveUp();
    void moveDown();
    int getSelectedIndex() { return selectedIndex; }

    std::vector<sf::Text*> menu;

private:
    int selectedIndex = 0;
    float coolDown = 0.1f;
    const float inputDelay = 0.1f;
    sf::Font* font;
};
