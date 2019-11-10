#include <limits>
#include "Counter.h"
#include "../00_00-adlib/GetUserInput.cpp"

using namespace std;

int main()
{
	Counter count;
	while (true)
	{
		system("cls");
		count.Print();
		cout << "\n1. Set min value\n2. Set max value\n3. Increment counter\n4. Reset counter\n0. Exit\n\n";
		switch (GetUserInput(1,0,4, "Select"))
		{
		case 1:
			count.SetMinVal(GetUserInput(1, INT_MIN, INT_MAX, "Min value"));
			break;
		case 2:
			count.SetMaxVal(GetUserInput(1, INT_MIN, INT_MAX, "Max value"));
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