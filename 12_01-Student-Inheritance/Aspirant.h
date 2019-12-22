#pragma once
#include "Student.h"
class Aspirant : public Student
{
public:
	Aspirant()
	{
		dissertation = "";
	}
	Aspirant(const char* name, size_t age, const char* dissertation)
	{
		this->name = name;
		this->age = age;
		this->dissertation = dissertation;
	}
	friend std::ostream& operator<<(std::ostream& os, Aspirant& obj)
	{
		os << "ID: " << obj.id << "\nName: " << obj.name << "\nAge: " << obj.age 
			<< "\nDissertation: " << obj.dissertation << std::endl;
		return os;
	}
	friend std::istream& operator>>(std::istream& is, Aspirant& obj)
	{
		std::cout << "Input name: ";
		is >> obj.name;
		std::cout << "Input age: ";
		is >> obj.age;
		std::cout << "Input dissertation: ";
		is >> obj.dissertation;
		return is;
	}

	
private:
	std::string dissertation;
};

