#include "State.h"

// State ������
State::State(sf::RenderWindow* window) 
{
	// â ������ ���� �� ������ �÷��� ���� �ʱ�ȭ
	this->window = window;
	this->quit = false;
}

// State �Ҹ���
State::~State()
{

}

// ���� State�� ������ �÷��� ���� ���¸� ��ȯ�ϴ� �Լ�
const bool& State::GetQuit() const 
{
	return this->quit;
}

void State::CheckForQuit() {
	// ���� ESCŰ�� ���� ���¶�� �����⸦ ��û�ϵ��� ���� ����
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->quit = true;
	}
}

// State ���� ��û�� �޾��� �� ���� �� �۾��� �ϴ� �Լ�
int State::EndState()
{

}

// �Է��� �޾� ó���ϴ� �Լ�
void State::UpdateInput(const float& dt) 
{
	
}

// State�� ������ ������ ������ �����ϴ� �Լ�
void State::Update(const float& dt)
{
	// ������Ʈ���� ���� State�� �����ؾ� �ϴ� �� üũ 
	this->CheckForQuit();

	// �ϴ� �����Ӹ��� �Է� Ȯ�θ� ����
	this->UpdateInput(dt);

	// ������ ����鼭 ������ ������ ����Ǵ� �ڵ���� �� ��
}

// State�� ���ŵ� ������ ȭ�鿡 �׷��ִ� �Լ�
void State::Render(sf::RenderTarget* target)
{
	// ����Ϸ��� â�� null�̶�� ���� â���� ����
	if (!target)
		target = this->window;
}