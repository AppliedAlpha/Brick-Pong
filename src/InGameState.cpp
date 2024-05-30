#include "InGameState.h"

InGameState::InGameState(sf::RenderWindow* window) : State(window) 
{
    this->font = new sf::Font();
    this->font->loadFromFile("./resources/font/Arial.ttf");

    //Score System �ʱ�ȭ
    this->scrSystem = new ScoreSystem();

    // �� �ʱ�ȭ
    this->ball = new Ball(20.f, 5.f, 1280, 720, scrSystem);

	// GameObjects �ʱ�ȭ

	this->player1 = new Player();

}

InGameState::~InGameState() 
{
    delete this->font;
    delete this->ball;

    delete this->scrSystem;
}

int InGameState::EndState() 
{
    return this->winner_num;
}

void InGameState::UpdateInput(const float& dt) 
{
    player1->UpdateInput(dt);
}

void InGameState::Update(const float& dt) 
{
    this->CheckForQuit();

    // �� ������ ó��
    this->ball->move();
    this->ball->checkCollisionWithWall();

    // �÷��̾�
	player1->Update(dt);

	// ���� global bounds�� player�� �浹 Ȯ��
	if (this->ball->getShape().getGlobalBounds().intersects(this->player1->GetDrawable()->getGlobalBounds()))
	{
		this->player1->OnCollision(ball);
	}
    else
	{
		this->player1->ClearCollisionTrigger();
	}
}

void InGameState::Render(sf::RenderTarget* target) 
{
    // ��� ��� ������ �� ���� ȭ������ ����
    if (!target)
        target = this->window;

    // target->draw(���); ���� �������ϱ� �����մϴ�.

    // ȭ�鿡 �� �׸���
    target->draw(this->ball->getShape());

    target->draw(*this->player1->GetDrawable());
}

void InGameState::CheckForQuit()
{
    //base class
    State::CheckForQuit();

    //���� ���� �޼� �� ���� ����
    int winner;

    if (scrSystem->IsGameFinished(winner))
    {
        this->winner_num = winner;
        this->quit = true;
    }
}