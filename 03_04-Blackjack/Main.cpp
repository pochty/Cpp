#include "CardDesk.h"
#include "Player.h"
#include <time.h>
#include "../00_00-adlib/GetUserInput.cpp"
using namespace std;

int main()
{
	srand(time(NULL));
	Player player;
	Player pc;
	CardDesk desk;
	desk.Shuffle();
	while (true)
	{
		system("cls");
		cout << "Blackjack\t\tScore:"<< player.GetScore() << "\n1. Take card\n2. End\n0. Exit\n";
		switch (GetUserInput(1,0,2,"Select"))
		{
		case 1:
		{
			Card card(desk.GetCard());
			player.TakeCard(card);
			cout << card << endl;
			system("pause");
			pc.TakeCard(desk.GetCard());
			break;
		}
		case 2:
		{
			while (pc.GetScore() < 18)
			{
				pc.TakeCard(desk.GetCard());
			}
			int playerScore = player.GetScore();
			int pcScore = pc.GetScore();
			cout << "Your score: " << playerScore << endl
				<< "PC score: " << pcScore << endl;
			if (playerScore < 22 && playerScore > pcScore)
			{
				cout << "You win!\n";
			}
			else if (playerScore < 22 && playerScore == pcScore)
			{
				cout << "Push\n";
			}
			else
			{
				cout << "You lose\n";
			}
		}
		case 0:
			return 0;
		default:
			return 1;
		}
	}
}