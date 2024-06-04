#include "ScoreSystem.h"

// 생성자
ScoreSystem::ScoreSystem() 
{
	ResetScore(); // 점수를 초기화합니다.
}

// 소멸자
ScoreSystem::~ScoreSystem() = default;

// 점수를 재설정하는 메서드
void ScoreSystem::ResetScore() 
{
    scores_ = std::make_pair(0, 0);
}

// 특정 플레이어의 점수를 반환하는 메서드
int ScoreSystem::GetScore(int player_number) const
{
	if (player_number == 1) 
	{
		return scores_.first;
	}
	else if (player_number == 2) 
	{
		return scores_.second;
	}
	else 
	{
		// 잘못된 플레이어 번호가 입력된 경우
		return -1;
	}
}

// 게임이 끝났는지 확인하는 메서드
bool ScoreSystem::CheckGameFinish() const {
	return std::max(scores_.first, scores_.second) >= kWinningScore;
}

void ScoreSystem::AddScore(int player_number, int score)
{
	if (player_number == 1)
	{
        scores_.first += score;
	}
	else if (player_number == 2)
	{
        scores_.second += score;
	}

	CheckGameFinish();
}

/// <summary>
/// 게임 종료 여부와, 승자 플레이어의 번호를 반환합니다.
/// </summary>
/// <param name="winner">승자의 번호를 Reference Value로 적용합니다. </param>
/// <returns>게임 종료 여부를 반환합니다.</returns>
bool ScoreSystem::IsGameFinished(int& winner)
{
	bool ret = CheckGameFinish();

	if (ret)
	{
		if (scores_.first >= kWinningScore)
		{
			winner = 1;
		}
		else if (scores_.second >= kWinningScore)
		{
			winner = 2;
		}
	}
	else winner = -1;

	return ret;
}
