#pragma once

#include "header/stdafx.h";

/// <summary>
/// Pong Game 속 두 플레이어의 점수를 계산하는 시스템입니다.
/// 한 쪽이 winning Score에 도달할 경우, State에 Exit함수를 호출하여 Quit하게 됩니다.
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