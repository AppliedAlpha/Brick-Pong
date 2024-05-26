#include "InGameState.h"

InGameState::InGameState(sf::RenderWindow* window) : State(window) 
{
    this->font = new sf::Font();
    this->font->loadFromFile("./resources/font/Arial.ttf");

    //Score System �ʱ�ȭ
    this->scrSystem = new ScoreSystem();

    // �� �ʱ�ȭ
    this->ball = new Ball(20.f, 5.f, 1280, 720, scrSystem);
    
    //���� �ʱ�ȭ
    int rows = 8;
    int bricks_per_row = 3;
    float Brick_x = 30.0f;
    float Brick_y = 90.0f;
    float Brick_itv = 10.0f;
    float Brick_row_gap = 6.0f * Brick_x;
    float total_height = rows * Brick_y + (rows - 1) * Brick_itv;
    float start_y = (720 - total_height) / 2;

    for (int row = 0; row < rows; row++) {
        for (int i = 0; i < bricks_per_row; i++) {
            float x = (1280 - (bricks_per_row * (Brick_x + Brick_row_gap) - Brick_row_gap)) / 2 + i * (Brick_x + Brick_row_gap);
            float y = start_y + row * (Brick_y + Brick_itv);
            bricks.push_back(new Brick(Brick_x, Brick_y, sf::Vector2f(x, y)));
        }
    }

}

InGameState::~InGameState() 
{
    delete this->font;
    delete this->ball;

    for (auto& brick : bricks) {
        delete brick;
    }
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
    this->ball->checkCollisionWithWall();

    //���� ������
    
}

void InGameState::Render(sf::RenderTarget* target) 
{
    // ��� ��� ������ �� ���� ȭ������ ����
    if (!target)
        target = this->window;

    // target->draw(���); ���� �������ϱ� �����մϴ�.

    // ȭ�鿡 �� �׸���
    target->draw(this->ball->getShape());

    for (auto& brick : bricks) {
        target->draw(brick->getShape());
    }


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