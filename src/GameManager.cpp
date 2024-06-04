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
	delete this->window_;
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
	this->window_ = new sf::RenderWindow(window_bounds, title);
	
	// ������ ���Ѱ� VSync �Ӽ��� ���� ȭ�鿡 ����ȭ��
	this->window_->setFramerateLimit(frame_rate_limit);
	this->window_->setVerticalSyncEnabled(vertical_sync_enabled);

	// TODO: ������ ���� �߰�
}

// State �ʱ�ȭ �Լ�
void GameManager::InitStates()
{
	// State ���� ���ο� State�� �־���
	// TODO: InGameState �׽�Ʈ ���� �� TitleState�� ����
	this->states_.push_front(new TitleState(this->window_));
}

// �����Ӹ��� �帥 �ð�(dt_, deltaTime)�� ������Ʈ����
void GameManager::UpdateDt()
{
	this->dt_ = this->dt_clock_.restart().asSeconds();
}

// SFML �̺�Ʈ�� ó���ϱ� ���� �Լ�
void GameManager::UpdateSfmlEvents()
{
	// ���� â���� �̺�Ʈ�� ���� �� ����
	while (this->window_->pollEvent(this->event_))
	{
		// ���� �̺�Ʈ�� ������ ���� â ����
		if (this->event_.type == sf::Event::Closed)
			this->window_->close();
	}
}

// �� �����Ӹ��� ���� ������ ����ϰ� �����ϴ� �Լ�
void GameManager::Update()
{
	// SFML �̺�Ʈ ó��
    this->UpdateSfmlEvents();

	// ���� State ���� ����ִ� State�� �ִٸ�
	if (!this->states_.empty())
	{
		// ���� ����Ǵ� State�� �� ���� �տ� �ִ� State ����
		// �ش� State�� ������ ������ ������ ������
		this->states_.front()->Update(this->dt_);

		// ���� ���� ����Ǵ� State���� ���� ��û�� �޾��� ��
		if (this->states_.front()->GetQuit())
		{
			// �ش� State ���Ḧ ���� ��ó�� �۾��� ����
			int res = this->states_.front()->EndState();

			// ����� State�� TitleState���
			if (auto* title_state = dynamic_cast<TitleState*>(this->states_.front()))
			{
				// Ÿ��Ʋ���� Start Game�� ������ �� ���� ����� �������� ����
				if (res == 0)
					this->states_.push_back(new InGameState(this->window_));
			}

			// ����� State�� InGameState���
			if (auto* in_game_state = dynamic_cast<InGameState *>(this->states_.front()))
			{
				// ���� �ڵ忡�� �޾ƿ� ���ڸ� ResultState�� �ѱ� 
				this->states_.push_back(new ResultState(this->window_, res));
			}

			// ����� State�� ResultState���
			if (dynamic_cast<ResultState *>(this->states_.front()))
			{
				// Retry, Back to Title�� ������ �� ���� ����� �־���
				if (res == 0)
					this->states_.push_back(new InGameState(this->window_));

				else if (res == 1)
					this->states_.push_back(new TitleState(this->window_));
			}

			// �ش� State�� �����͸� �����ϰ�, ������ ���ܽ�Ŵ
			delete this->states_.front();
			this->states_.pop_front();
		}
	}
	else 
	{
		// ���� ���� State�� ���ٸ� ȭ�� ����
		this->window_->close();
	}
}

// �� �����Ӹ��� ���ŵ� ������ �ٽ� ȭ�鿡 �׷��ִ� �Լ�
void GameManager::Render()
{
	// ���� â�� �׷��� �͵��� ������
	this->window_->clear();

	// ���� State ���� ����ִ� State�� �ִٸ�
	if (!this->states_.empty())
		// ���� ����Ǵ� State�� ������ �� ȭ�鿡 �׷���
		this->states_.front()->Render(this->window_);

	// ��� �׷����� �׸� â�� ǥ����
	this->window_->display();
}

// ���� ������ ����
void GameManager::Run()
{
	// ���� â�� �����ִµ���
	while (this->window_->isOpen())
	{
		// �� �����Ӹ��� dt_ ����, ������Ʈ, �׸��⸦ �ݺ� ȣ����
		this->UpdateDt();
		this->Update();
		this->Render();
	}
}