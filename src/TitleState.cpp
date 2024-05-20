#include "TitleState.h"

TitleState::TitleState(sf::RenderWindow* window) : State(window) 
{
    this->font = new sf::Font();
    this->font->loadFromFile("./resources/font/Arial.ttf");

    this->InitTexts();
}

TitleState::~TitleState() 
{
    delete this->font;
}

void TitleState::InitTexts()
{
    title_text.setFont(*(this->font));
    title_text.setCharacterSize(24);
    title_text.setFillColor(sf::Color::White);
    title_text.setPosition(sf::Vector2f(400., 200.));
    title_text.setString("Brick Pong");
    std::cout << "??";
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

    // 텍스트 렌더링
    target->draw(title_text);
}