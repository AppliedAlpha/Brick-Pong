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
    result_text.setPosition(CustomMath::GetCenterPos(CustomMath::kCenter, 150, result_text.getLocalBounds().width));

    std::vector<std::string> menu_text = { "Retry", "Back to Title" };
    result_menu = new Menu(menu_text);
}

int ResultState::EndState() 
{
    return this->exit_menu_code_;
}

void ResultState::UpdateInput(const float& dt) 
{
    this->result_menu->UpdateInput(dt);
    this->enter_cool_.Update(dt);

    if (this->enter_cool_.IsAvailable())
    {
        int res;

        // 엔터를 감지했다면, 전환되거나 다음 State로 넘어가거나 해야함
        if ((res = this->result_menu->CheckEnterPressed()) != -1)
        {
            this->enter_cool_.ReloadCoolDown();

            this->exit_menu_code_ = res;
            this->quit_ = true;
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
        target = this->window_;

    target->draw(result_text);

    for (auto menu_text : this->result_menu->menu)
        target->draw(*menu_text);
}