#pragma once
#include "CardDesk.h"

class Player
{
public:
	Player()
	{
		_score = 0;
		_turn = 0;
	}
	void TakeCard(Card card)
	{
		int rank = card.GetRank() + 2;
		if (rank < 11)
		{
			_score += rank;
		}
		else if (rank < 14)
		{
			_score += 10;
		}
		else
		{
			if (_score + 11 < 22)
			{
				_score += 11;
			}
			else
			{
				_score += 1;
			}
		}
	}
	int GetScore()
	{
		return _score;
	}

private:
	int _score;
	int _turn;
};

