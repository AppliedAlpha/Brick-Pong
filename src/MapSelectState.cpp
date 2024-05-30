#include "MapSelectState.h"

MapSelectState::MapSelectState(sf::RenderWindow* window) : State(window) 
{
    this->font = new sf::Font();
    this->font->loadFromFile("./resources/font/Arial.ttf");
}

MapSelectState::~MapSelectState() 
{
    delete this->font;
}

int MapSelectState::EndState() 
{

}

void MapSelectState::UpdateInput(const float& dt) 
{

}

void MapSelectState::Update(const float& dt) 
{

}

void MapSelectState::Render(sf::RenderTarget* target) 
{

}