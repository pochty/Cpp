#include "RecordNumber.h"

RecordNumber& RecordNumber::operator()(size_t birthPart, size_t countPart)
{
	this->birthPart = birthPart;
	this->countPart = countPart;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const RecordNumber& obj)
{
	os << obj.birthPart << "-" << obj.countPart;
	return os;
}
