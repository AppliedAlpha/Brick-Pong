#include "ScoreSystem.h"

// 생성자
ScoreSystem::ScoreSystem() 
{
	ResetScore(); // 점수를 초기화합니다.
}

// 소멸자
ScoreSystem::~ScoreSystem() {}

// 점수를 재설정하는 메서드
void ScoreSystem::ResetScore() 
{
	scores = std::make_pair(0, 0);
}

// 특정 플레이어의 점수를 반환하는 메서드
int ScoreSystem::GetScore(int player_number) 
{
	if (player_number == 1) 
	{
		return scores.first;
	}
	else if (player_number == 2) 
	{
		return scores.second;
	}
	else 
	{
		// 잘못된 플레이어 번호가 입력된 경우
		return -1;
	}
}

// 게임이 끝났는지 확인하는 메서드
bool ScoreSystem::CheckGameFinish() {
	return std::max(scores.first, scores.second) >= winning_score;
}

void ScoreSystem::AddScore(int player_number, int score)
{
	if (player_number == 1)
	{
		scores.first += score;
	}
	else if (player_number == 2)
	{
		scores.second += score;
	}

	CheckGameFinish();
}

/// <summary>
/// Returns whether the game is over or not and the winner's number
/// </summary>
/// <param name="winner">Winner's number by reference value</param>
/// <returns>Returning Has Game Overred</returns>
bool ScoreSystem::IsGameFinished(int& winner)
{
	bool ret = CheckGameFinish();

	if (ret)
	{
		if (scores.first >= winning_score)
		{
			winner = 1;
		}
		else if (scores.second >= winning_score)
		{
			winner = 2;
		}
	}
	else winner = -1;

	return ret;
}
