#pragma once

/*Promts the user to input value in a defined range
type - Defines the return value type
min - Min value of the defined range
max - Max value of the defined range*/
template<class T>
T GetUserInput(T type, T min, T max)
{
	std::cout << "->";
	T val;
	while (!(std::cin >> val) || val < min || val > max)
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Invalid value, try again->";
	}
	return val;
}
