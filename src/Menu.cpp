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

    // 현재 쿨다운 중이라면 (다음 입력 확인까지 대기 중이라면)
    if (coolDown > 0.f) 
    {
        // 대기 시간 감소 (0초 미만으로 내려가지 않음)
        coolDown -= dt;

        if (coolDown < 0.f)
            coolDown = 0.f;
    }

    // 키 누르기가 가능한 상태라면 확인
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
