#include "TitleState.h"

TitleState::TitleState(sf::RenderWindow* window) : State(window) 
{
    // 폰트 파일에서 가져와서 로드
    this->font = new sf::Font();
    this->font->loadFromFile("./resources/font/Arial.ttf");

    // 타이틀 화면 텍스트들 초기화
    this->InitTexts();
}

TitleState::~TitleState() 
{
    // 폰트 메모리 할당 해제
    delete this->font;
}

void TitleState::InitTexts()
{
    // 게임 제목 텍스트 설정
    // 순서대로 폰트, 글자 크기, 색상, 메시지, 위치
    title_text.setFont(*(this->font));
    title_text.setCharacterSize(88);
    title_text.setFillColor(sf::Color::White);
    title_text.setString("Brick Pong");
    title_text.setPosition(CustomMath::GetCenterPos(CustomMath::CENTER, 150, title_text.getLocalBounds().width));

    std::vector<std::string> menu_text = {"Game Start", "Setting", "Exit Game"};
    title_menu = new Menu(menu_text);
}

int TitleState::EndState() 
{
    return 0;
}

void TitleState::UpdateInput(const float& dt) 
{
    this->title_menu->updateInput(dt);

    int res;
    // 엔터를 감지했다면, 전환되거나 다음 State로 넘어가거나 해야함
    if ((res = this->title_menu->checkEnterPressed()) != -1)
    {
        std::cout << res;
    }
}

void TitleState::Update(const float& dt) 
{
    this->UpdateInput(dt);
    this->CheckForQuit();
}

void TitleState::Render(sf::RenderTarget* target) 
{
    // 출력 대상 미지정 시 현재 화면으로 설정
    if (!target)
        target = this->window;

    // 텍스트 렌더링
    target->draw(title_text);

    for (auto menu_text : this->title_menu->menu)
        target->draw(*menu_text);
}