#pragma once
#include <iostream>

class RecordNumber
{
public:
	RecordNumber(){}
	RecordNumber& operator()(size_t birthPart, size_t countPart);
	friend std::ostream& operator<<(std::ostream& os, const RecordNumber& obj);

private:
	size_t birthPart;
	size_t countPart;
};

