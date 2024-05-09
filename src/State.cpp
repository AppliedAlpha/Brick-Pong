#include "State.h"

// State ������
State::State(sf::RenderWindow* window) 
{
	// â ������ ���� �� ������ �÷��� ���� �ʱ�ȭ
	this->window = window;
	this->quit = false;

	// �ӽ� ��Ʈ �ʱ�ȭ
	this->font = new sf::Font();
	// ��Ʈ �ε� ���� �� �ٷ� ����
	if (!this->font->loadFromFile("./resources/font/Arial.ttf"))
	{
		std::cout << "[!] Font Load Failed!" << std::endl;
		this->quit = true;
	}

	// �ӽ� �ؽ�Ʈ �ʱ�ȭ, ��Ʈ �� �Ӽ� ����
	this->text = new sf::Text();
	this->text->setFont(*this->font);
	this->text->setCharacterSize(72);
	this->text->setPosition(sf::Vector2f(360.f, 60.f));
	this->text->setFillColor(sf::Color::White);
	this->text->setString("Brick Pong Game");
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

// State ���� ��û�� �޾��� �� ���� �� �۾��� �ϴ� �Լ�
void State::EndState()
{

}

// �Է��� �޾� ó���ϴ� �Լ�
void State::UpdateInput(const float& dt) 
{
	// ���� ESCŰ�� ���� ���¶�� �����⸦ ��û�ϵ��� ���� ����
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->quit = true;
	}
}

// State�� ������ ������ ������ �����ϴ� �Լ�
void State::Update(const float& dt)
{
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

	// ����Ϸ��� â ���� ���� �ؽ��� ���� ȭ�鿡 �׸�
	// ����� �ӽ� �ؽ�Ʈ�� ȭ�鿡 �׷���
	target->draw(*this->text);
}