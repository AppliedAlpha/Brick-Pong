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
    this->result_menu->updateInput(dt);
    this->enterCool.Update(dt);

    if (this->enterCool.IsAvailable())
    {
        int res;

        // 엔터를 감지했다면, 전환되거나 다음 State로 넘어가거나 해야함
        if ((res = this->result_menu->checkEnterPressed()) != -1)
        {
            this->enterCool.ReloadCoolDown();

            this->exitMenuCode = res;
            this->quit = true;
        }
    }
}

void ResultState::Update(const float& dt) 
{
    this->UpdateInput(dt);
    this->CheckForQuit();
}

void ResultState::Render(sf::RenderTarget* target) 
{
    if (!target)
        target = this->window;

    target->draw(result_text);

    for (auto menu_text : this->result_menu->menu)
        target->draw(*menu_text);
}