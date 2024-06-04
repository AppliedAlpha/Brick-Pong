#pragma once

#include "header/stdafx.h";
#include <vector>

/// <summary>
/// Pong Game �� �� �÷��̾��� ������ ����ϴ� �ý����Դϴ�.
/// �� ���� winning Score�� ������ ���, State�� Exit�Լ��� ȣ���Ͽ� Quit�ϰ� �˴ϴ�.
/// </summary>
class ScoreSystem 
{
private:
	std::pair<int, int> scores_;
	const int kWinningScore = 5;

//	methods
	bool CheckGameFinish() const;
	void ResetScore();
public:
	ScoreSystem();
	~ScoreSystem();
	
	void AddScore(int player_number, int score = 1);
	int GetScore(int player_number) const;
	bool IsGameFinished(int& winner);
};