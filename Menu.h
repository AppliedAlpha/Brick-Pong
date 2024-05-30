
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Menu {
public:
    Menu(float width, float height);
    ~Menu();

    void draw(sf::RenderWindow& window);
    void moveUp();
    void moveDown();
    int getSelectedIndex() { return selectedIndex; }

private:
    int selectedIndex;
    sf::Font font;
    sf::Text title;  // 제목 텍스트 추가
    std::vector<sf::Text> menu;
};
