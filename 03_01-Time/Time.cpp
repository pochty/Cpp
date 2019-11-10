#include "Time.h"

int Time::count = 0;

Time::Time()
{
	hour = min = sec = 0;
	ID = count++;
}

Time::Time(int _hour, int _min, int _sec) : Time()
{
	Set(_hour, _min, _sec);
}

Time::~Time()
{
	--count;
}

int Time::userInput(int min, int max)//limit user input to the valid range
{
	int val;
	cout << "->";
	while (!(cin >> val) || val < min || val > max)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid value (range: " << min << "..." << max << ")->";
	}
	cin.ignore(1000, '\n');
	return val;
}

void Time::Offset(int _hour, int _min, int _sec)//offset time by _... values for all the fields
{
	int tmpSec = 3600 * (hour + _hour) + 60 * (min + _min) + sec + _sec;
	hour = tmpSec / 3600;
	tmpSec %= 3600;
	min = tmpSec / 60;
	sec = tmpSec % 60;
}

void Time::Set(int _hour, int _min, int _sec)
{
	hour = min = sec = 0;//set all null to use offset
	Offset(_hour, _min, _sec);
}

int Time::GetHour() { return hour; }

int Time::GetMin() { return min; }

int Time::GetSec() { return sec; }

void Time::Input()//user input
{
	int _hour{}, _min{}, _sec{};
	cout << "Enter hour";
	_hour = userInput(0, 23);
	cout << "Enter min";
	_min = userInput(0, 59);
	cout << "Enter sec";
	_sec = userInput(0, 59);
	Set(_hour, _min, _sec);
}

void Time::inputHour12()
{
	int _hour{}, _min{}, _sec{};
	char str[3]{};
	while (scanf_s("%d%*c%d%s", &_hour, &_min, str, sizeof(str)) != 3 || _hour > 12 || _min > 59)
	{
		cout << "Invalid time->";
	}
	convertFromHour12(str, _hour, _min);
}


void Time::Print()
{
	cout << ((hour < 0 || min < 0 || sec < 0) ? "-" : "") << setfill('0') << setw(2) << abs(hour) << ":" << setfill('0') << setw(2) << abs(min) << ":" << setfill('0') << setw(2) << abs(sec) << endl;
}

void Time::Print(int x, int y)//print at the specified position
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos{ (SHORT)x, (SHORT)y };
	char str[18]{};
	char smb = ((hour < 0 || min < 0 || sec < 0) ? '-' : ' ');
	sprintf_s(str, sizeof(str), "Timer %d:%c%02d:%02d:%02d", ID, smb, abs(hour), abs(min), abs(sec));
	DWORD byteWritten;
	WriteConsoleOutputCharacter(hStdout, (LPCTSTR)str, sizeof(str) - 1, pos, &byteWritten);
}

void Time::TimerForward(int _hour, int _min, int _sec)//stopwatch
{
	Offset(0, 0, 0);
	while (!(hour == _hour && min == _min && sec == _sec))
	{
		Print(50, 1);
		Sleep(1000);
		Offset(0, 0, 1);
		if (_kbhit())
		{
			if (tolower(_getch()) == 'z') break;
		}
	}
	Print(50, 1);
}

void Time::TimerBackward(int _hour, int _min, int _sec)//standard timer 
{
	Offset(_hour, _min, _sec);
	while (!(hour == 0 && min == 0 && sec == 0))
	{
		Print(50, 2);
		Sleep(1000);
		Offset(0, 0, -1);
		if (_kbhit())
		{
			if (tolower(_getch()) == 'x') break;
		}
	}
	Print(50, 2);
}

Time Time::operator+(const Time & rval) const
{
	Time res{ hour, min, sec };
	res.Offset(rval.hour, rval.min, rval.sec);
	return res;
}

Time Time::operator-(const Time & rval) const
{
	Time res{ hour, min, sec };
	res.Offset(-rval.hour, -rval.min, -rval.sec);
	return res;
}

bool Time::operator==(const Time & rval) const
{
	return 	3600 * hour + 60 * min + sec == 3600 * rval.hour + 60 * rval.min + rval.sec;
}

bool Time::operator!=(const Time & rval) const
{
	return !(operator==(rval));
}

bool Time::operator<(const Time & rval) const
{
	return  3600 * hour + 60 * min + sec < 3600 * rval.hour + 60 * rval.min + rval.sec;
}

bool Time::operator>(const Time & rval) const
{
	return 3600 * hour + 60 * min + sec > 3600 * rval.hour + 60 * rval.min + rval.sec;
}

bool Time::operator<=(const Time & rval) const
{
	return !(operator>(rval));
}

bool Time::operator>=(const Time & rval) const
{
	return !(operator<(rval));
}

void Time::convertFromHour12(const char* period, int _hour, int _min, int _sec)//convert time from 12-hour format to 24-hour format
{
	if (_stricmp(period, "am") && _stricmp(period, "pm")) throw "Invalid time period";
	hour = abs(_hour % 12);
	if (!_stricmp(period, "pm")) hour += 12;
	min = abs(_min % 60);
	sec = abs(_sec % 60);
}

ostream & operator<<(ostream & os, const Time & rval)
{
	os << ((rval.hour < 0 || rval.min < 0 || rval.sec < 0) ? "-" : "") << setfill('0') << setw(2) << abs(rval.hour) << ":" << setfill('0') << setw(2) << abs(rval.min) << ":" << setfill('0') << setw(2) << abs(rval.sec) << endl;
	return os;
}
