#include "ForeignPassport.h"

ForeignPassport::ForeignPassport(const char* surname, const char* name, const char* patronymic, const char sex, int birthYear, int birthMonth, int birthDay, int expireYear, int expireMonth, int expireDay, const char* nationality, const char* visa)
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
	this->visa = visa;
}

std::ostream& operator<<(std::ostream& os, const ForeignPassport& obj)
{
	os << "Surname: " << obj.surname
		<< "\nName: " << obj.name
		<< "\nPatronymic: " << obj.patronymic
		<< "\nSex: " << obj.sex
		<< "\nDate of birth: " << obj.birthDate.tm_year << "-" << obj.birthDate.tm_mon << "-" << obj.birthDate.tm_mday
		<< "\nDate of expire: " << obj.expireDate.tm_year << "-" << obj.expireDate.tm_mon << "-" << obj.expireDate.tm_mday
		<< "\nNationality: " << obj.nationality
		<< "\nRecord No.: " << obj.recordNo
		<< "\nDocument No.:" << obj.documentNo
		<< "\nVisa: " << obj.visa << std::endl;
	return os;
}