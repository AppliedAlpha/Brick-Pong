#include "ScoreSystem.h"

// ������
ScoreSystem::ScoreSystem() 
{
	ResetScore(); // ������ �ʱ�ȭ�մϴ�.
}

// �Ҹ���
ScoreSystem::~ScoreSystem() = default;

// ������ �缳���ϴ� �޼���
void ScoreSystem::ResetScore() 
{
    scores_ = std::make_pair(0, 0);
}

// Ư�� �÷��̾��� ������ ��ȯ�ϴ� �޼���
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
		// �߸��� �÷��̾� ��ȣ�� �Էµ� ���
		return -1;
	}
}

// ������ �������� Ȯ���ϴ� �޼���
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
/// ���� ���� ���ο�, ���� �÷��̾��� ��ȣ�� ��ȯ�մϴ�.
/// </summary>
/// <param name="winner">������ ��ȣ�� Reference Value�� �����մϴ�. </param>
/// <returns>���� ���� ���θ� ��ȯ�մϴ�.</returns>
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
