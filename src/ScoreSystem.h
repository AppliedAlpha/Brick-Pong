#pragma once

#include "header/stdafx.h";

/// <summary>
/// Pong Game �� �� �÷��̾��� ������ ����ϴ� �ý����Դϴ�.
/// �� ���� winning Score�� ������ ���, State�� Exit�Լ��� ȣ���Ͽ� Quit�ϰ� �˴ϴ�.
/// </summary>
class ScoreSystem 
{
private:
	int player1_score;
	int player2_score;

	const int winning_score = 5;

//	methods
	bool CheckGameFinish();
	void ResetScore();
public:
	ScoreSystem();
	~ScoreSystem();
	
	void AddScore(int player_number, int score = 1);
	int GetScore(int player_number);
	bool IsGameFinished(int& winner);
};