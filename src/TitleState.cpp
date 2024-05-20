#include "TitleState.h"

TitleState::TitleState(sf::RenderWindow* window) : State(window) 
{
    this->font = new sf::Font();
    this->font->loadFromFile("./resources/font/Arial.ttf");
}

TitleState::~TitleState() 
{
    delete this->font;
}

void TitleState::EndState() 
{

}

void TitleState::UpdateInput(const float& dt) 
{
    this->CheckForQuit();
}

void TitleState::Update(const float& dt) 
{

}

void TitleState::Render(sf::RenderTarget* target) 
{
    if (!target)
        target = this->window;
}