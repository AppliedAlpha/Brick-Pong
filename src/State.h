#pragma once
#include "header/stdafx.h"

class State
{
private:

protected:
	sf::RenderWindow* window_;
	bool quit_;

public:
	explicit State(sf::RenderWindow* window);
	virtual ~State();

	const bool& GetQuit() const;
	virtual void CheckForQuit();
	
	// 순수 가상 함수 처리
	// 모든 State들이 필수적으로 override해야 함
	virtual int EndState() = 0;
	virtual void UpdateInput(const float& dt) = 0;
	virtual void Update(const float& dt) = 0;
	virtual void Render(sf::RenderTarget* target) = 0;
};

