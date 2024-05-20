#include "InGameState.h"

InGameState::InGameState(sf::RenderWindow* window) : State(window) {
    this->font = new sf::Font();
    this->font->loadFromFile("./Resources/Arial.ttf");
}

InGameState::~InGameState() {
    delete this->font;
}

void InGameState::EndState() {

}

void InGameState::UpdateInput(const float& dt) {

}

void InGameState::Update(const float& dt) {

}

void InGameState::Render(sf::RenderTarget* target) {

}