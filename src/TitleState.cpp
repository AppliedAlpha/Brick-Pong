#include "TitleState.h"

TitleState::TitleState(sf::RenderWindow* window) : State(window) {
    this->font = new sf::Font();
    this->font->loadFromFile("./Resources/Arial.ttf");
}

TitleState::~TitleState() {
    delete this->font;
}

void TitleState::EndState() {

}

void TitleState::UpdateInput(const float& dt) {

}

void TitleState::Update(const float& dt) {

}

void TitleState::Render(sf::RenderTarget* target) {

}