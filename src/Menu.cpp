#include "Menu.h"

Menu::Menu(std::vector<std::string> vec)
{
    this->upDownCool = CoolDown(0.1f);
    this->enterCool = CoolDown(0.5f);
    
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
    this->upDownCool.Update(dt);
    this->enterCool.Update(dt);

    bool pressed_up = sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    bool pressed_down = sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down);

    if (this->upDownCool.IsAvailable())
    {
        if (pressed_up) {
            this->moveUp();
            this->upDownCool.ReloadCoolDown();
        }
        else if (pressed_down) {
            this->moveDown();
            this->upDownCool.ReloadCoolDown();
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
