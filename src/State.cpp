#include "State.h"

// State 생성자
State::State(sf::RenderWindow* window) 
{
	// 창 포인터 변수 및 나가기 플래그 변수 초기화
	this->window = window;
	this->quit = false;

	// 임시 폰트 초기화
	this->font = new sf::Font();
	// 폰트 로드 실패 시 바로 종료
	if (!this->font->loadFromFile("./resources/font/Arial.ttf"))
	{
		std::cout << "[!] Font Load Failed!" << std::endl;
		this->quit = true;
	}

	// 임시 텍스트 초기화, 폰트 및 속성 설정
	this->text = new sf::Text();
	this->text->setFont(*this->font);
	this->text->setCharacterSize(72);
	this->text->setPosition(sf::Vector2f(360.f, 60.f));
	this->text->setFillColor(sf::Color::White);
	this->text->setString("Brick Pong Game");
}

// State 소멸자
State::~State()
{

}

// 현재 State의 나가기 플래그 변수 상태를 반환하는 함수
const bool& State::GetQuit() const 
{
	return this->quit;
}

// State 종료 요청을 받았을 시 종료 전 작업을 하는 함수
void State::EndState()
{

}

// 입력을 받아 처리하는 함수
void State::UpdateInput(const float& dt) 
{
	// 만약 ESC키를 누른 상태라면 나가기를 요청하도록 변수 설정
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->quit = true;
	}
}

// State의 정보를 프레임 단위로 갱신하는 함수
void State::Update(const float& dt)
{
	// 일단 프레임마다 입력 확인만 해줌
	this->UpdateInput(dt);

	// 게임을 만들면서 프레임 단위로 수행되는 코드들이 올 것
}

// State의 갱신된 정보를 화면에 그려주는 함수
void State::Render(sf::RenderTarget* target)
{
	// 출력하려는 창이 null이라면 현재 창으로 설정
	if (!target)
		target = this->window;

	// 출력하려는 창 위에 여러 텍스쳐 등을 화면에 그림
	// 현재는 임시 텍스트를 화면에 그려줌
	target->draw(*this->text);
}