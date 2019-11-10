#pragma once
#include <iostream>
#include <stdlib.h>
#include "Card.h"
const int DESK_SIZE = 52;

class CardDesk
{
public:
	CardDesk()
	{
		_counter = 0;
		for (int i = 0; i < DESK_SIZE; ++i)
		{
			_cards[i] = i;
		}
	}

	void Shuffle()
	{
		_counter = 0;
		for (int i = 0; i < DESK_SIZE; ++i)
		{
			int rnd = rand() % DESK_SIZE;
			std::swap(_cards[i], _cards[rnd]);
		}
	}

	Card GetCard()
	{
		if (_counter++ == DESK_SIZE)
		{
			Shuffle();
		}
		return Card(_cards[_counter]);
	}

private:
	int _cards[DESK_SIZE];
	int _counter;
};


