/*Draft class Person */
#pragma once
#include <string>
#include <iostream>

class Person
{
public:
	Person() : Person("-", 0, 0, "-")
	{
	}
	Person(std::string _Name) : Person()
	{
		Name = _Name;
	}
	Person(std::string _Name, char _Sex, size_t _Age, std::string _PhoneNumber)
	{
		SetName(_Name);
		SetSex(_Sex);
		SetAge(_Age);
		SetPhoneNumber(_PhoneNumber);
	}

	void SetName(std::string _Name)
	{
		Name = _Name;
	}
	std::string GetName()
	{
		return Name;
	}
	void SetAge(size_t _Age)
	{
		Age = _Age;
	}
	size_t GetAge()
	{
		return Age;
	}
	void SetSex(char _Sex)
	{
		Sex = _Sex;
	}
	char GetSex()
	{
		return Sex;
	}
	void SetPhoneNumber(std::string _PhoneNumber)
	{
		PhoneNumber = _PhoneNumber;
	}
	std::string GetPhoneNumber()
	{
		return PhoneNumber;
	}
	friend std::ostream& operator<<(std::ostream& os, Person p)
	{
		os << "\nName:\t" << p.GetName() << std::endl
			<< "Age:\t" << p.GetAge() << std::endl
			<< "Sex:\t" << (p.GetSex() ? "Female" : "Male") << std::endl
			<< "Phone:\t" << p.GetPhoneNumber() << std::endl;
		return os;
	}

private:
	std::string Name;
	char Sex;
	std::string PhoneNumber;
	size_t Age;
};

