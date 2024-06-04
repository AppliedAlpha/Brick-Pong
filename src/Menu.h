#pragma once
#include "header/stdafx.h"
#include "CoolDown.h"

class Menu 
{
public:
    explicit Menu(std::vector<std::string> vec);
    ~Menu();

    void UpdateInput(const float& dt);
    void MoveUp();
    void MoveDown();
    int GetSelectedIndex() const { return selected_index_; }
    int CheckEnterPressed();

    std::vector<sf::Text*> menu;

private:
    int selected_index_ = 0;
    
    CoolDown up_down_cool_ = CoolDown(0.1f);
    sf::Font* font_;
};
