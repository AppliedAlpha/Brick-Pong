#include "src/GameManager.h"

// ���α׷��� ������
int main()
{
    // ������ �����ϴ� Ŭ������ ����� �����Ŵ
    GameManager game;
    game.Run();

    return 0;
}


/*
#include <SFML/Graphics.hpp>
#include "Menu.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Brick Pong");
    Menu menu(window.getSize().x, window.getSize().y);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                case sf::Keyboard::Up:
                    menu.moveUp();
                    break;
                case sf::Keyboard::Down:
                    menu.moveDown();
                    break;
                case sf::Keyboard::Return:
                    switch (menu.getSelectedIndex()) {
                    case 0:
                        std::cout << "Game Start pressed" << std::endl;
                        // ���� ���� ���� �߰�
                        break;
                    case 1:
                        std::cout << "Setting pressed" << std::endl;
                        // ���� �޴� ���� �߰�
                        break;
                    case 2:
                        window.close();
                        break;
                    }
                    break;
                }
            }
        }

        window.clear();
        menu.draw(window);
        window.display();
    }

    return 0;
}
*/