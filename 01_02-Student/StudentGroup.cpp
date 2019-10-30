#pragma once
#include "StudentGroup.h"


StudentGroup& StudentGroup::operator=(const StudentGroup& that)
{
	name = that.name;
	size = that.size;
	capacity = that.capacity;
	delete[] students;
	students = new Student[capacity];
	for (size_t i = 0; i < size; i++)
	{
		students[i] = that.students[i];
	}
	return *this;
}
std::ostream& operator<<(std::ostream& os, StudentGroup group)
{
	os << "\nGroup: " << group.name << std::endl;
	for (size_t i = 0; i < group.size; i++)
	{
		os << i + 1 << ". " << group.students[i] << std::endl;
	}
	return os;
}
