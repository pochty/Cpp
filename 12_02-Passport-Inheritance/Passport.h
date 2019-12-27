#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include "RecordNumber.h"

class Passport
{
public:
	Passport()
	{

	}
	Passport(const Passport& that);
	Passport(const char* surname, const char* name, const char* patronymic, const char sex,
		tm birthDate, tm expireDate, const char* nationality)
	{
		SetData(surname, name, patronymic, sex, birthDate, expireDate, nationality);
	}
	Passport(const char* surname, const char* name, const char* patronymic, const char sex,
		int birthYear, int birthMonth, int birthDay, int expireYear, int expireMonth, int expireDay, const char* nationality);
	void SetData(const char* surname, const char* name, const char* patronymic, const char sex,
		tm birthDate, tm expireDate, const char* nationality);
	friend std::ostream& operator<<(std::ostream& os, const Passport& obj);

protected:
	std::string surname;
	std::string name;
	std::string patronymic;
	char sex;
	tm birthDate;
	tm expireDate;
	std::string nationality;
	RecordNumber recordNo;
	size_t documentNo;

	void SetStaticFields(const char* surname, const char* name, const char* patronymic,
		const char sex, tm birthDate, tm expireDate, const char* nationality);
	void SetDynamicFields();
};

