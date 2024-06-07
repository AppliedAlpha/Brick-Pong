#include "TitleState.h"

TitleState::TitleState(sf::RenderWindow* window) : State(window) 
{
    // ��Ʈ ���Ͽ��� �����ͼ� �ε�
    this->font = new sf::Font();
    this->font->loadFromFile("./resources/font/Arial.ttf");

    // Ÿ��Ʋ ȭ�� �ؽ�Ʈ�� �ʱ�ȭ
    this->InitTexts();
}

TitleState::~TitleState() 
{
    // ��Ʈ �޸� �Ҵ� ����
    delete this->font;
}

void TitleState::InitTexts()
{
    // ���� ���� �ؽ�Ʈ ����
    // ������� ��Ʈ, ���� ũ��, ����, �޽���, ��ġ
    title_text.setFont(*(this->font));
    title_text.setCharacterSize(88);
    title_text.setFillColor(sf::Color::White);
    title_text.setString("Brick Pong");
    title_text.setPosition(CustomMath::GetCenterPos(CustomMath::kCenter, 150, title_text.getLocalBounds().width));

    std::vector<std::string> menu_text = {"Game Start", "How To Play", "Exit Game"};
    title_menu = new Menu(menu_text);
}

int TitleState::EndState() 
{
    return this->exit_menu_code_;
}

void TitleState::UpdateInput(const float& dt) 
{
    this->title_menu->UpdateInput(dt);
    this->enter_cool_.Update(dt);

    if (this->enter_cool_.IsAvailable())
    {
        int res;

        // ���͸� �����ߴٸ�, ��ȯ�ǰų� ���� State�� �Ѿ�ų� �ؾ���
        if ((res = this->title_menu->CheckEnterPressed()) != -1)
        {
            this->enter_cool_.ReloadCoolDown();

            this->exit_menu_code_ = res;
            this->quit_ = true;
        }
    }
}

void TitleState::Update(const float& dt) 
{
    this->UpdateInput(dt);
    this->CheckForQuit();
}

void TitleState::Render(sf::RenderTarget* target) 
{
    // ��� ��� ������ �� ���� ȭ������ ����
    if (!target)
        target = this->window_;

    // �ؽ�Ʈ ������
    target->draw(title_text);

    for (auto menu_text : this->title_menu->menu)
        target->draw(*menu_text);
}