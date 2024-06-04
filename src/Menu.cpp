#include "Menu.h"

Menu::Menu(std::vector<std::string> vec)
{
    this->font = new sf::Font();
    this->font->loadFromFile("./resources/font/Arial.ttf");

    this->menu.resize(vec.size());

    for (int i=0; i<this->menu.size(); i++) 
    {
        this->menu[i] = new sf::Text();

        this->menu[i]->setFont(*(this->font));
        this->menu[i]->setFillColor(i == selectedIndex ? sf::Color::Cyan : sf::Color::White);
        this->menu[i]->setCharacterSize(40.f);
        this->menu[i]->setString(vec[i]);
        this->menu[i]->setPosition(CustomMath::GetCenterPos(CustomMath::CENTER, 360 + 75 * i, this->menu[i]->getLocalBounds().width));
    }

    selectedIndex = 0;
}

Menu::~Menu() 
{
    delete this->font;

    for (auto item : this->menu)
        delete item;
}

void Menu::updateInput(const float& dt) 
{
    bool pressed_up = sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    bool pressed_down = sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down);

    // std::cout << coolDown << std::endl;

    // ���� ��ٿ� ���̶�� (���� �Է� Ȯ�α��� ��� ���̶��)
    if (coolDown > 0.f) 
    {
        // ��� �ð� ���� (0�� �̸����� �������� ����)
        coolDown -= dt;

        if (coolDown < 0.f)
            coolDown = 0.f;
    }

    // Ű �����Ⱑ ������ ���¶�� Ȯ��
    if (coolDown == 0.f) 
    {
        if (pressed_up) {
            this->moveUp();
            coolDown = inputDelay;
        }
        else if (pressed_down) {
            this->moveDown();
            coolDown = inputDelay;
        }
    }
   
}
int Menu::checkEnterPressed() 
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        return selectedIndex;
    }
    return -1;
}

void Menu::moveUp() 
{
    if (selectedIndex - 1 >= 0) 
    {
        menu[selectedIndex]->setFillColor(sf::Color::White);
        selectedIndex--;
        menu[selectedIndex]->setFillColor(sf::Color::Cyan);
    }
}

void Menu::moveDown() 
{
    if (selectedIndex + 1 < menu.size()) 
    {
        menu[selectedIndex]->setFillColor(sf::Color::White);
        selectedIndex++;
        menu[selectedIndex]->setFillColor(sf::Color::Cyan);
    }
}
