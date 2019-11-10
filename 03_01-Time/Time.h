#pragma once
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <thread>
#include <conio.h>

using namespace std; 

class Time
{
	int hour;
	int min;
	int sec;
	static int count;//counter for the timer ID
	int ID;

public:
	Time();
	Time(int _hour, int _min, int _sec);
	~Time();
	int userInput(int min, int max);
	void Offset(int _hour, int _min, int _sec);
	void Set(int _hour, int _min, int _sec);
	int GetHour();
	int GetMin();
	int GetSec();
	void Input();
	void inputHour12();
	void Print();
	void Print(int x, int y);
	void TimerForward(int _hour, int _min, int _sec);
	void TimerBackward(int _hour, int _min, int _sec);
	Time operator+(const Time& rval) const;
	Time operator-(const Time& rval) const;
	bool operator==(const Time& rval) const;
	bool operator!=(const Time& rval) const;
	bool operator<(const Time& rval) const;
	bool operator>(const Time& rval) const;
	bool operator<=(const Time& rval) const;
	bool operator>=(const Time& rval) const;
	void convertFromHour12(const char* period, int _hour, int _min, int _sec = 0);
	friend ostream& operator<<(ostream& os, const Time& rval);
};

