#include "Passport.h"

Passport::Passport(const Passport& that)
{
	SetStaticFields(that.surname.c_str(), that.name.c_str(), that.patronymic.c_str(), that.sex,
		that.birthDate, that.expireDate, that.nationality.c_str());
	this->recordNo = that.recordNo;
	this->documentNo = that.documentNo;
}

Passport::Passport(const char* surname, const char* name, const char* patronymic, const char sex, int birthYear, int birthMonth, int birthDay, int expireYear, int expireMonth, int expireDay, const char* nationality)
{
	tm birthDate{ 0 };
	birthDate.tm_year = birthYear;
	birthDate.tm_mon = birthMonth;
	birthDate.tm_mday = birthDay;
	tm expireDate{ 0 };
	expireDate.tm_year = expireYear;
	expireDate.tm_mon = expireMonth;
	expireDate.tm_mday = expireDay;
	SetStaticFields(surname, name, patronymic, sex, birthDate, expireDate, nationality);
	SetDynamicFields();
}

void Passport::SetData(const char* surname, const char* name, const char* patronymic, const char sex, tm birthDate, tm expireDate, const char* nationality)
{
	SetStaticFields(surname, name, patronymic, sex, birthDate, expireDate, nationality);
	SetDynamicFields();
}

void Passport::SetStaticFields(const char* surname, const char* name, const char* patronymic, const char sex, tm birthDate, tm expireDate, const char* nationality)
{
	this->surname = surname;
	this->name = name;
	this->patronymic = patronymic;
	this->sex = sex;
	this->birthDate = birthDate;
	this->expireDate = expireDate;
	this->nationality = nationality;
}

void Passport::SetDynamicFields()//birthDate must be set
{
	std::stringstream ss;
	ss << birthDate.tm_year << birthDate.tm_mon << birthDate.tm_mday;
	this->recordNo = recordNo(atol(ss.str().c_str()), rand() % 100);
	this->documentNo = rand() % 100000;
}

std::ostream& operator<<(std::ostream& os, const Passport& obj)
{
	os << "Surname: " << obj.surname
		<< "\nName: " << obj.name
		<< "\nPatronymic: " << obj.patronymic
		<< "\nSex: " << obj.sex
		<< "\nDate of birth: " << obj.birthDate.tm_year << "-" << obj.birthDate.tm_mon << "-" << obj.birthDate.tm_mday
		<< "\nDate of expire: " << obj.expireDate.tm_year << "-" << obj.expireDate.tm_mon << "-" << obj.expireDate.tm_mday
		<< "\nNationality: " << obj.nationality
		<< "\nRecord No.: " << obj.recordNo
		<< "\nDocument No.:" << obj.documentNo << std::endl;
	return os;
}

