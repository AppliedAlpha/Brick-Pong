#include "InGameState.h"

InGameState::InGameState(sf::RenderWindow* window) : State(window) 
{
    this->font = new sf::Font();
    this->font->loadFromFile("./resources/font/Arial.ttf");

    //Score System 초기화
    this->scrSystem = new ScoreSystem();

    // 공 초기화
    this->ball = new Ball(20.f, 5.f, 1280, 720, scrSystem);

	// GameObjects 초기화

	this->player1 = new Player();

}

InGameState::~InGameState() 
{
    delete this->font;
    delete this->ball;

    delete this->scrSystem;
}

void InGameState::EndState() 
{

}

void InGameState::UpdateInput(const float& dt) 
{
    player1->UpdateInput(dt);
}

void InGameState::Update(const float& dt) 
{
    this->CheckForQuit();

    // 공 움직임 처리
    this->ball->move();
    this->ball->checkCollisionWithWall();

    // 플레이어
	player1->Update(dt);

	// 공의 global bounds와 player의 충돌 확인
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
    // 출력 대상 미지정 시 현재 화면으로 설정
    if (!target)
        target = this->window;

    // target->draw(대상); 으로 렌더링하길 권장합니다.

    // 화면에 공 그리기
    target->draw(this->ball->getShape());

    target->draw(*this->player1->GetDrawable());
}

void InGameState::CheckForQuit()
{
    //base class
    State::CheckForQuit();

    //득점 조건 달성 시 게임 종료
    int winner_num;

    if (scrSystem->IsGameFinished(winner_num))
    {
        this->quit = true;
        std::cout << winner_num;
    }
}