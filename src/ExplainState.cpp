#include "ExplainState.h"

ExplainState::ExplainState(sf::RenderWindow* window) : State(window)
{

}

ExplainState::~ExplainState()
{

}

int ExplainState::EndState()
{
	return 0;
}

void ExplainState::UpdateInput(const float& dt)
{
    this->enter_cool_.Update(dt);

    // 쿨다운이 완료된 후 엔터를 감지했다면, 타이틀 화면으로 돌아가게 해야함
    if (this->enter_cool_.IsAvailable())
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            this->enter_cool_.ReloadCoolDown();
            this->quit_ = true;
        }
        int res;
    }
}

void ExplainState::Update(const float& dt)
{
	this->UpdateInput(dt);
	this->CheckForQuit();
}

void ExplainState::Render(sf::RenderTarget* target)
{
	// 출력 대상 미지정 시 현재 화면으로 설정
	if (!target)
		target = this->window_;
}