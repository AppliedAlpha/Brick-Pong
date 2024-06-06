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

    // ��ٿ��� �Ϸ�� �� ���͸� �����ߴٸ�, Ÿ��Ʋ ȭ������ ���ư��� �ؾ���
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
	// ��� ��� ������ �� ���� ȭ������ ����
	if (!target)
		target = this->window_;
}