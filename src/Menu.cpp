#include "Menu.h"

Menu::Menu(std::vector<std::string> vec)
{   
    this->font_ = new sf::Font();
    this->font_->loadFromFile("./resources/font/Arial.ttf");

    this->menu.resize(vec.size());

    for (int i=0; i<this->menu.size(); i++) 
    {
        this->menu[i] = new sf::Text();

        this->menu[i]->setFont(*(this->font_));
        this->menu[i]->setFillColor(i == selected_index_ ? sf::Color::Cyan : sf::Color::White);
        this->menu[i]->setCharacterSize(40.f);
        this->menu[i]->setString(vec[i]);
        this->menu[i]->setPosition(CustomMath::GetCenterPos(CustomMath::kCenter, 360 + 75 * i, this->menu[i]->getLocalBounds().width));
    }

    selected_index_ = 0;
}

Menu::~Menu() 
{
    delete this->font_;

    for (auto item : this->menu)
        delete item;
}

void Menu::UpdateInput(const float& dt)
{
    this->up_down_cool_.Update(dt);

    bool pressed_up = sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    bool pressed_down = sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down);

    if (this->up_down_cool_.IsAvailable())
    {
        if (pressed_up) {
            this->MoveUp();
            this->up_down_cool_.ReloadCoolDown();
        }
        else if (pressed_down) {
            this->MoveDown();
            this->up_down_cool_.ReloadCoolDown();
        }
    }
   
}
int Menu::CheckEnterPressed()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        return selected_index_;
    }
    return -1;
}

void Menu::MoveUp()
{
    if (selected_index_ - 1 >= 0)
    {
        menu[selected_index_]->setFillColor(sf::Color::White);
        selected_index_--;
        menu[selected_index_]->setFillColor(sf::Color::Cyan);
    }
}

void Menu::MoveDown()
{
    if (selected_index_ + 1 < menu.size())
    {
        menu[selected_index_]->setFillColor(sf::Color::White);
        selected_index_++;
        menu[selected_index_]->setFillColor(sf::Color::Cyan);
    }
}
