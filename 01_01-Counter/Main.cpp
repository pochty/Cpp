#include <limits>
#include "Counter.h"
#include "UserInput.cpp"

using namespace std;

int main()
{
	Counter count;
	while (true)
	{
		system("cls");
		count.Print();
		cout << "\n1. Set min value\n2. Set max value\n3. Increment counter\n4. Reset counter\n0. Exit\n\n";
		cout << "Option";
		switch (GetUserInput(1,0,4))
		{
		case 1:
			cout << "Min value";
			count.SetMinVal(GetUserInput(1, INT_MIN, INT_MAX));
			break;
		case 2:
			cout << "Max value";
			count.SetMaxVal(GetUserInput(1, INT_MIN, INT_MAX));
			break;
		case 3:
			++count;
			break;
		case 4:
			count.Reset();
			break;
		case 0:
			return 0;
			break;
		default:
			return 1;
			break;
		}
	}
}