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
	player1_score = 0;
	player2_score = 0;
}

// Ư�� �÷��̾��� ������ ��ȯ�ϴ� �޼���
int ScoreSystem::GetScore(int player_number) 
{
	if (player_number == 1) 
	{
		return player1_score;
	}
	else if (player_number == 2) 
	{
		return player2_score;
	}
	else 
	{
		// �߸��� �÷��̾� ��ȣ�� �Էµ� ���
		return -1;
	}
}

// ������ �������� Ȯ���ϴ� �޼���
bool ScoreSystem::CheckGameFinish() {
	if (player1_score >= winning_score) return true;
	if (player2_score >= winning_score) return true;

	return false;
}

void ScoreSystem::AddScore(int player_number, int score)
{
	if (player_number == 1)
	{
		player1_score += score;
	}
	else if (player_number == 2)
	{
		player2_score += score;
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
		if (player1_score >= winning_score)
		{
			winner = 1;
		}
		else if (player2_score >= winning_score)
		{
			winner = 2;
		}
	}
	else winner = -1;

	return ret;
}
