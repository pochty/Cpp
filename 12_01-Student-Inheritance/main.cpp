#pragma once
#include "Student.h"
#include "Aspirant.h"

size_t Student::counter = 0;

int main()
{
	std::cout << "Add student" << endl;
	Student st("student1", 20);
	Student st2;
	std::cin >> st2;
	std::cout << st << std::endl << st2;
	std::cout << "Add aspirant" << endl;
	Aspirant as;
	std::cin >> as;
	std::cout << as;

}