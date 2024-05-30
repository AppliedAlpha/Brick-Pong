#include "GameManager.h"

// ���� ������ ������
GameManager::GameManager() 
{
	// ȭ�� ������ ���� State�� �ʱ�ȭ��
	this->InitWindow();
	this->InitStates();
}

// ���� ������ �Ҹ���
GameManager::~GameManager()
{
	// ���� ȭ�� �����͸� �Ҵ� ������
	delete this->window;
}

// ȭ�� ���� �ʱ�ȭ �Լ�
void GameManager::InitWindow() 
{
	// ���� ����, â ũ��, �ִ� ������, VSync ���� ����
	std::string title = "Brick Pong";
	sf::VideoMode window_bounds(1280, 720);
	unsigned int frame_rate_limit = 60;
	bool vertical_sync_enabled = false;

	// RenderWindow�� ����� ȭ�� �����Ϳ� �Ҵ�����
	this->window = new sf::RenderWindow(window_bounds, title);
	
	// ������ ���Ѱ� VSync �Ӽ��� ���� ȭ�鿡 ����ȭ��
	this->window->setFramerateLimit(frame_rate_limit);
	this->window->setVerticalSyncEnabled(vertical_sync_enabled);

	// TODO: ������ ���� �߰�
}

// State �ʱ�ȭ �Լ�
void GameManager::InitStates()
{
	// State ���� ���ο� State�� �־���
	// TODO: InGameState �׽�Ʈ ���� �� TitleState�� ����
	this->states.push_front(new InGameState(this->window));
}

// �����Ӹ��� �帥 �ð�(dt, deltaTime)�� ������Ʈ����
void GameManager::UpdateDt()
{
	this->dt = this->dt_clock.restart().asSeconds();
}

// SFML �̺�Ʈ�� ó���ϱ� ���� �Լ�
void GameManager::UpdateSFMLEvents()
{
	// ���� â���� �̺�Ʈ�� ���� �� ����
	while (this->window->pollEvent(this->event))
	{
		// ���� �̺�Ʈ�� ������ ���� â ����
		if (this->event.type == sf::Event::Closed)
			this->window->close();
	}
}

// �� �����Ӹ��� ���� ������ ����ϰ� �����ϴ� �Լ�
void GameManager::Update()
{
	// SFML �̺�Ʈ ó��
	this->UpdateSFMLEvents();

	// ���� State ���� ����ִ� State�� �ִٸ�
	if (!this->states.empty()) 
	{
		// ���� ����Ǵ� State�� �� ���� �տ� �ִ� State ����
		// �ش� State�� ������ ������ ������ ������
		this->states.front()->Update(this->dt);

		// ���� ���� ����Ǵ� State���� ���� ��û�� �޾��� ��
		if (this->states.front()->GetQuit())
		{
			// �ش� State ���Ḧ ���� ��ó�� �۾��� ����
			int res = this->states.front()->EndState();

			// ����� State�� InGameState���
			if (InGameState* inGameState = dynamic_cast<InGameState *>(this->states.front()))
			{
				// ���� �ڵ忡�� �޾ƿ� ���ڸ� ResultState�� �ѱ� 
				this->states.push_back(new ResultState(this->window, res));
			}

			// �ش� State�� �����͸� �����ϰ�, ������ ���ܽ�Ŵ
			delete this->states.front();
			this->states.pop_front();
		}
	}
	else 
	{
		// ���� ���� State�� ���ٸ� ȭ�� ����
		this->window->close();
	}
}

// �� �����Ӹ��� ���ŵ� ������ �ٽ� ȭ�鿡 �׷��ִ� �Լ�
void GameManager::Render()
{
	// ���� â�� �׷��� �͵��� ������
	this->window->clear();

	// ���� State ���� ����ִ� State�� �ִٸ�
	if (!this->states.empty())
		// ���� ����Ǵ� State�� ������ �� ȭ�鿡 �׷���
		this->states.front()->Render(this->window);

	// ��� �׷����� �׸� â�� ǥ����
	this->window->display();
}

// ���� ������ ����
void GameManager::Run()
{
	// ���� â�� �����ִµ���
	while (this->window->isOpen())
	{
		// �� �����Ӹ��� dt ����, ������Ʈ, �׸��⸦ �ݺ� ȣ����
		this->UpdateDt();
		this->Update();
		this->Render();
	}
}