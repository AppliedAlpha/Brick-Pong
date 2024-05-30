
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
    sf::Text title;  // ���� �ؽ�Ʈ �߰�
    std::vector<sf::Text> menu;
};
