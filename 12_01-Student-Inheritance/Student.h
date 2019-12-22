#pragma once
#include <iostream>
#include <string>

class Student
{
public:
	Student();
	Student(std::string name, size_t age);
	Student(const char* name, size_t age);
	friend std::ostream& operator<<(std::ostream& os, const Student& obj);
	friend std::istream& operator>>(std::istream& is, Student& obj);

protected:
	static size_t counter;
	size_t id;
	std::string name;
	size_t age;

};

