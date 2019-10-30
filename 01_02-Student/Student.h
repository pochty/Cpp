#pragma once
#include <string>
#include <iostream>
#include "Date.h"

class Student
{
public:
	Student() : Student("-", 0,0,0)
	{
	}
	Student(std::string _name, Date _birthDate) : name(_name), birthDate(_birthDate)
	{
	}
	Student(std::string _name, size_t _year, size_t _month, size_t _day)
	{
		name = _name;
		birthDate.SetDate(_year, _month, _day);
	}
	void SetName(std::string _name);
	std::string GetName();
	Student& SetBirthDate(Date _birthDate);
	Student& SetBirthDate(size_t _year, size_t _month, size_t _day);
	Date GetBirthDate();
	friend std::ostream& operator<<(std::ostream& os, Student st);

private:
	std::string name;
	Date birthDate;

};

