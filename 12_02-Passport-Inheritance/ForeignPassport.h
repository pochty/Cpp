#pragma once
#include "Passport.h"

class ForeignPassport : public Passport
{
public:
	ForeignPassport(const char* surname, const char* name, const char* patronymic, const char sex,
		int birthYear, int birthMonth, int birthDay, int expireYear, int expireMonth, int expireDay, 
		const char* nationality, const char* visa);
	friend std::ostream& operator<<(std::ostream& os, const ForeignPassport& obj);

private:
	std::string visa;

};

