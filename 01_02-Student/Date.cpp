#include "Date.h"

std::ostream& operator<<(std::ostream& os, Date dt)
{
	os << dt.day << "." << dt.month << "." << dt.year;
	return os;
}
