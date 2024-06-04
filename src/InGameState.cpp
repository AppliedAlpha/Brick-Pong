#include "InGameState.h"

InGameState::InGameState(sf::RenderWindow* window) : State(window) 
{
    this->font = new sf::Font();
    this->font->loadFromFile("./resources/font/Arial.ttf");

    //Score System 초기화
    this->scrSystem = new ScoreSystem();

    // 공 초기화
    this->ball = new Ball(20.f, 5.f, 1280, 720, scrSystem);
    
    //벽돌 초기화
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


	// GameObjects 초기화
    this->players.first = new Player(1);
    this->players.second = new Player(2);
}

InGameState::~InGameState() 
{
    delete this->font;
    delete this->ball;

    for (auto& brick : bricks) {
        delete brick;
    }
}

int InGameState::EndState() 
{
    return this->winner_num;
}

void InGameState::UpdateInput(const float& dt) 
{
    this->players.first->UpdateInput(dt);
    this->players.second->UpdateInput(dt);
}

void InGameState::Update(const float& dt) 
{
    // 게임 종료 확인
    this->CheckForQuit();

    // 공 움직임 처리
    this->ball->move();
    this->ball->checkCollisionWithWall();

    //벽돌 구현부
    this->ball->checkCollisionWithBrick(bricks);
        
    // 플레이어
	this->players.first->Update(dt);
    this->players.second->Update(dt);

	// 공의 global bounds와 player의 충돌 확인
	if (this->ball->getShape().getGlobalBounds().intersects(this->players.first->GetDrawable()->getGlobalBounds()))
	{
        this->players.first->OnCollision(ball);
	}
    else
	{
        this->players.first->ClearCollisionTrigger();
	}

    if (this->ball->getShape().getGlobalBounds().intersects(this->players.second->GetDrawable()->getGlobalBounds()))
    {
		this->players.second->OnCollision(ball);
	}
    else
    {
		this->players.second->ClearCollisionTrigger();
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

    for (auto& brick : bricks) {
        target->draw(brick->getShape());
    }

    // 플레이어 그리기
    target->draw(*this->players.first->GetDrawable());
    target->draw(*this->players.second->GetDrawable());
}

void InGameState::CheckForQuit()
{
    //base class
    State::CheckForQuit();

    //득점 조건 달성 시 게임 종료
    int winner;
    if(scrSystem->IsGameFinished(winner))
    {
        this->winner_num = winner;
        this->quit = true;
    }
}