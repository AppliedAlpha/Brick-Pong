#include "ScoreSystem.h"

// ������
ScoreSystem::ScoreSystem() 
{
	ResetScore(); // ������ �ʱ�ȭ�մϴ�.
}

// �Ҹ���
ScoreSystem::~ScoreSystem() {}

// ������ �缳���ϴ� �޼���
void ScoreSystem::ResetScore() 
{
	scores = std::make_pair(0, 0);
}

// Ư�� �÷��̾��� ������ ��ȯ�ϴ� �޼���
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
		// �߸��� �÷��̾� ��ȣ�� �Էµ� ���
		return -1;
	}
}

// ������ �������� Ȯ���ϴ� �޼���
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
