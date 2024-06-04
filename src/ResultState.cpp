#include "ResultState.h"

ResultState::ResultState(sf::RenderWindow* window, int winner) : winner_num(winner), State(window) 
{
    this->font = new sf::Font();
    this->font->loadFromFile("./resources/font/Arial.ttf");

    this->InitTexts();
}

ResultState::~ResultState() 
{
    delete this->font;
}

void ResultState::InitTexts() 
{
    result_text.setFont(*(this->font));
    result_text.setCharacterSize(88);
    result_text.setFillColor(sf::Color::White);
    result_text.setString("Player " + std::to_string(this->winner_num) + " Wins");
    result_text.setPosition(CustomMath::GetCenterPos(CustomMath::CENTER, 150, result_text.getLocalBounds().width));

    std::vector<std::string> menu_text = { "Retry", "Back to Menu" };
    result_menu = new Menu(menu_text);
}

int ResultState::EndState() 
{
    return 0;
}

void ResultState::UpdateInput(const float& dt) 
{

}

void ResultState::Update(const float& dt) 
{
    this->CheckForQuit();
}

void ResultState::Render(sf::RenderTarget* target) 
{
    if (!target)
        target = this->window;

    target->draw(result_text);
}