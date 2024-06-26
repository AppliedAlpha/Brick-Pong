#include "GameManager.h"

// 게임 관리자 생성자
GameManager::GameManager() 
{
	// 화면 변수와 현재 State를 초기화함
	this->InitWindow();
	this->InitStates();
}

// 게임 관리자 소멸자
GameManager::~GameManager()
{
	// 현재 화면 포인터를 할당 해제함
	delete this->window_;
}

// 화면 변수 초기화 함수
void GameManager::InitWindow() 
{
	// 게임 제목, 창 크기, 최대 프레임, VSync 관리 변수
	std::string title = "Brick Pong";
	sf::VideoMode window_bounds(1280, 720);
	unsigned int frame_rate_limit = 60;
	bool vertical_sync_enabled = false;

	// RenderWindow를 만들어 화면 포인터에 할당해줌
	this->window_ = new sf::RenderWindow(window_bounds, title);
	
	// 프레임 제한과 VSync 속성을 현재 화면에 동기화함
	this->window_->setFramerateLimit(frame_rate_limit);
	this->window_->setVerticalSyncEnabled(vertical_sync_enabled);

	// TODO: 아이콘 설정 추가
}

// State 초기화 함수
void GameManager::InitStates()
{
	// State 덱에 새로운 State를 넣어줌
	// TODO: InGameState 테스트 종료 시 TitleState로 변경
	this->states_.push_front(new TitleState(this->window_));
}

// 프레임마다 흐른 시각(dt_, deltaTime)을 업데이트해줌
void GameManager::UpdateDt()
{
	this->dt_ = this->dt_clock_.restart().asSeconds();
}

// SFML 이벤트를 처리하기 위한 함수
void GameManager::UpdateSfmlEvents()
{
	// 현재 창에서 이벤트가 있을 시 실행
	while (this->window_->pollEvent(this->event_))
	{
		// 종료 이벤트를 받으면 현재 창 종료
		if (this->event_.type == sf::Event::Closed)
			this->window_->close();
	}
}

// 매 프레임마다 여러 정보를 계산하고 갱신하는 함수
void GameManager::Update()
{
	// SFML 이벤트 처리
    this->UpdateSfmlEvents();

	// 현재 State 덱에 들어있는 State가 있다면
	if (!this->states_.empty())
	{
		// 현재 실행되는 State는 덱 가장 앞에 있는 State 원소
		// 해당 State의 정보를 프레임 단위로 갱신함
		this->states_.front()->Update(this->dt_);

		// 만약 현재 실행되는 State에서 종료 요청을 받았을 시
		if (this->states_.front()->GetQuit())
		{
			// 해당 State 종료를 위한 전처리 작업을 해줌
			int res = this->states_.front()->EndState();

			// 종료된 State가 TitleState라면
			if (auto* title_state = dynamic_cast<TitleState*>(this->states_.front()))
			{
				// 타이틀에서 Start Game을 눌렀을 때 다음 장면을 게임으로 설정
				if (res == 0)
					this->states_.push_back(new InGameState(this->window_));

				else if (res == 1)
					this->states_.push_back(new ExplainState(this->window_));
			}

			// 종료된 State가 InGameState라면
			if (auto* in_game_state = dynamic_cast<InGameState *>(this->states_.front()))
			{
				// 종료 코드에서 받아온 승자를 ResultState로 넘김 
				this->states_.push_back(new ResultState(this->window_, res));
			}

			// 종료된 State가 ResultState라면
			if (dynamic_cast<ResultState *>(this->states_.front()))
			{
				// Retry, Back to Title을 눌렀을 때 다음 장면을 넣어줌
				if (res == 0)
					this->states_.push_back(new InGameState(this->window_));

				else if (res == 1)
					this->states_.push_back(new TitleState(this->window_));
			}

			// 종료된 State가 ExplainState라면 다시 타이틀로 전환
			if (dynamic_cast<ExplainState*>(this->states_.front()))
				this->states_.push_back(new TitleState(this->window_));

			// 해당 State의 포인터를 해제하고, 덱에서 제외시킴
			delete this->states_.front();
			this->states_.pop_front();
		}
	}
	else 
	{
		// 덱에 남은 State가 없다면 화면 종료
		this->window_->close();
	}
}

// 매 프레임마다 갱신된 정보를 다시 화면에 그려주는 함수
void GameManager::Render()
{
	// 현재 창에 그려진 것들을 삭제함
	this->window_->clear();

	// 현재 State 덱에 들어있는 State가 있다면
	if (!this->states_.empty())
		// 현재 실행되는 State의 정보를 이 화면에 그려줌
		this->states_.front()->Render(this->window_);

	// 모두 그렸으면 그린 창을 표시함
	this->window_->display();
}

// 게임 관리자 실행
void GameManager::Run()
{
	// 게임 창이 열려있는동안
	while (this->window_->isOpen())
	{
		// 매 프레임마다 dt_ 갱신, 업데이트, 그리기를 반복 호출함
		this->UpdateDt();
		this->Update();
		this->Render();
	}
}