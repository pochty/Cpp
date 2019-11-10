#include "Person.h"

Person::Person(std::string _Name, char _Sex, size_t _Age, std::string _PhoneNumber)
{
	SetName(_Name);
	SetSex(_Sex);
	SetAge(_Age);
	SetPhoneNumber(_PhoneNumber);
}
std::ostream& operator<<(std::ostream& os, Person p)
{
	os << "\nName:\t" << p.GetName() << std::endl
		<< "Age:\t" << p.GetAge() << std::endl
		<< "Sex:\t" << (p.GetSex() ? "Female" : "Male") << std::endl
		<< "Phone:\t" << p.GetPhoneNumber() << std::endl;
	return os;
}