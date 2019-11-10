#include "Time.h"
//#define TIMER
using namespace std;

int main()
{
#ifdef TIMER
	Time tmp;
	Time tmp2;
	cout << "Forward timer (seconds, minutes, hours):\n";
	thread thr1(&Time::TimerForward, tmp, tmp.userInput(0, 23), tmp.userInput(0, 59), tmp.userInput(0, 59));
	cout << "Backward timer (seconds, minutes, hours):\n";
	thread thr2(&Time::TimerBackward, tmp2, tmp2.userInput(0, 23), tmp2.userInput(0, 59), tmp2.userInput(0, 59));
	cout << "Press 'z' to stop forward timer or 'x' to stop backward timer\n";
	thr2.join();
	thr1.join();
#endif // TIMER

	Time T1(rand() % 24, rand() % 60, rand() % 60);
	Time T2(T1);
	Time T3(rand() % 24, rand() % 60, rand() % 60);

	cout << "Time T1: " <<  T1 << endl << "Time T2: " << T2 << endl << "Time T3: " << T3 << endl;
	cout << "T1 - T2: " << T1 - T2 << endl;
	cout << "T1 + T2: " << T1 + T2 << endl;
	cout << "T1 == T2: " << boolalpha << (T1 == T2) << endl;
	cout << "T1 != T2: " << boolalpha << (T1 != T2) << endl;
	cout << "T1 < T3: " << boolalpha << (T1 < T3) << endl;
	cout << "T1 > T3: " << boolalpha << (T1 > T3) << endl;
	cout << "T1 <= T3: " << boolalpha << (T1 <= T3) << endl;
	cout << "T1 >= T2: " << boolalpha << (T1 >= T2) << endl << endl;
	cout << "Input time in 12-hour format (i.e., 11:11 am): ";
	try
	{
		T2.inputHour12();
	}
	catch (const char* excMsg)
	{
		cout << excMsg << endl;
	}
	cout << "T2 in 24-hour format: " << T2 << endl;

}