#include "InGameState.h"

InGameState::InGameState(sf::RenderWindow* window) : State(window) 
{
    this->font = new sf::Font();
    this->font->loadFromFile("./resources/font/Arial.ttf");

    // �� �ʱ�ȭ
    this->ball = new Ball(20.f, 5.f, 1280, 720);

    //Score System �ʱ�ȭ
    this->scrSystem = new ScoreSystem();
}

InGameState::~InGameState() 
{
    delete this->font;
    delete this->ball;
}

void InGameState::EndState() 
{

}

void InGameState::UpdateInput(const float& dt) 
{

}

void InGameState::Update(const float& dt) 
{
    // �� ������ ó��
    this->ball->move();
}

void InGameState::Render(sf::RenderTarget* target) 
{
    // ��� ��� ������ �� ���� ȭ������ ����
    if (!target)
        target = this->window;

    // target->draw(���); ���� �������ϱ� �����մϴ�.

    // ȭ�鿡 �� �׸���
    target->draw(this->ball->getShape());
}

void InGameState::CheckForQuit()
{
    //base class
    State::CheckForQuit();

    //���� ���� �޼� �� ���� ����
    int winner_num;
    if(scrSystem->IsGameFinished(winner_num))
    {
        this->quit = true;
    }
}