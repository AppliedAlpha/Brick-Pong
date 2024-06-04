#pragma once
#include "header/stdafx.h"
#include "CoolDown.h"

class Menu 
{
public:
    Menu(std::vector<std::string> vec);
    ~Menu();

    void updateInput(const float& dt);
    void moveUp();
    void moveDown();
    int getSelectedIndex() { return selectedIndex; }
    int checkEnterPressed();

    std::vector<sf::Text*> menu;

private:
    int selectedIndex = 0;
    
    CoolDown upDownCool, enterCool;
    sf::Font* font;
};
