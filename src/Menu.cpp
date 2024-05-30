
#include "Menu.h"

Menu::Menu(float width, float height) {
    if (!font.loadFromFile("resources/font/Arial.ttf")) {
        // 에러 처리
    }

    // 제목 텍스트 초기화
    title.setFont(font);
    title.setFillColor(sf::Color::White);
    title.setString("Brick Pong Game");
    title.setCharacterSize(36); // 제목 크기 설정
    title.setPosition(sf::Vector2f(width / 2.0f - title.getGlobalBounds().width / 2.0f, height / 10.0f));

    std::string menuItems[] = { "Game Start", "Setting", "Exit Game" };
    for (int i = 0; i < 3; i++) {
        sf::Text text;
        text.setFont(font);
        text.setFillColor(i == 0 ? sf::Color::Cyan : sf::Color::White);
        text.setString(menuItems[i]);
        text.setPosition(sf::Vector2f(width / 2.0f - text.getGlobalBounds().width / 2.0f, height / (3 + 1) * (i + 2))); // 메뉴 위치 조정
        menu.push_back(text);
    }

    selectedIndex = 0;
}
Menu::~Menu() {}

void Menu::draw(sf::RenderWindow& window) {
    window.draw(title); // 제목 텍스트 그리기
    for (auto& item : menu) {
        window.draw(item);
    }
}




void Menu::moveUp() {
    if (selectedIndex - 1 >= 0) {
        menu[selectedIndex].setFillColor(sf::Color::White);
        selectedIndex--;
        menu[selectedIndex].setFillColor(sf::Color::Cyan);
    }
}

void Menu::moveDown() {
    if (selectedIndex + 1 < menu.size()) {
        menu[selectedIndex].setFillColor(sf::Color::White);
        selectedIndex++;
        menu[selectedIndex].setFillColor(sf::Color::Cyan);
    }
}
