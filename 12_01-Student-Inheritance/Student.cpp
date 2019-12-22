#include "Student.h"

Student::Student()
{
	id = counter++;
	name = "";
	age = 0;
}

Student::Student(std::string name, size_t age) : name(name), age(age)
{
	id = counter++;
}

Student::Student(const char* name, size_t age)
{
	id = counter++;
	this->name = name;
	this->age = age;
}

std::ostream& operator<<(std::ostream& os, const Student& obj)
{
	os << "ID: " << obj.id << "\nName: " << obj.name << "\nAge: " << obj.age << std::endl;
	return os;
}
std::istream& operator>>(std::istream& is, Student& obj)
{
	std::cout << "Input name: ";
	is >> obj.name;
	std::cout << "Input age: ";
	is >> obj.age;
	return is;
}
