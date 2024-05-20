#include "ResultState.h"

ResultState::ResultState(sf::RenderWindow* window) : State(window) 
{
    this->font = new sf::Font();
    this->font->loadFromFile("./resources/font/Arial.ttf");
}

ResultState::~ResultState() 
{
    delete this->font;
}

void ResultState::EndState() 
{

}

void ResultState::UpdateInput(const float& dt) 
{

}

void ResultState::Update(const float& dt) 
{

}

void ResultState::Render(sf::RenderTarget* target) 
{

}