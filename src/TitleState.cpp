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
    title_text.setCharacterSize(88);
    title_text.setFillColor(sf::Color::White);
    title_text.setString("Brick Pong");
    title_text.setPosition(CustomMath::GetCenterPos(CustomMath::CENTER, 150, title_text.getLocalBounds().width));

    std::string menu_str[] = {"Game Start", "Setting", "Exit Game"};
    for (int i = 0; i < 3; ++i)
    {
        menu_text[i].setFont(*(this->font));
        menu_text[i].setCharacterSize(48);
        menu_text[i].setFillColor(sf::Color::White);
        menu_text[i].setString(menu_str[i]);
        menu_text[i].setPosition(CustomMath::GetCenterPos(CustomMath::CENTER, 360 + 70 * i, menu_text[i].getLocalBounds().width));
    }
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

    for (int i = 0; i < 3; ++i)
        target->draw(menu_text[i]);
}