#include "Student.h"

inline void Student::SetName(std::string _name)
{
	name = _name;
}

inline std::string Student::GetName()
{
	return name;
}

inline Student& Student::SetBirthDate(Date _birthDate)
{
	birthDate = _birthDate;
	return *this;
}

Student& Student::SetBirthDate(size_t _year, size_t _month, size_t _day)
{
	birthDate.SetDate(_year, _month, _day);
	return *this;
}

inline Date Student::GetBirthDate()
{
	return birthDate;
}

std::ostream& operator<<(std::ostream& os, Student st)
{
	os << st.GetName() << " " << st.GetBirthDate() << " ";
	return os;
}
