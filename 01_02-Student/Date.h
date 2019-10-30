#pragma once
#include <iostream>
/*Simplified date without checks*/
class Date
{
public:
	Date()
	{
	}
	Date(size_t _year, size_t _month, size_t _day) : year(_year), month(_month), day(_day)
	{
	}
	Date& SetDate(size_t _year, size_t _month, size_t _day)//Can't move to Date.cpp, unresolved external symbol????
	{
		year = _year;
		month = _month;
		day = _day;
		return *this;
	}
	friend std::ostream& operator<<(std::ostream& os, Date dt);

private:
	size_t year;
	size_t month;
	size_t day;
};

