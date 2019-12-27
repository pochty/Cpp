#include "Passport.h"
#include "ForeignPassport.h"

int main()
{
	srand((size_t)time(0));
	Passport pass;
	tm bd{0};
	bd.tm_year = 1990;
	bd.tm_mon = 10;
	bd.tm_mday = 11;
	pass.SetData("surname1", "name1", "patronymic1", 'm', bd, bd, "ukr");
	Passport pass1("surname1", "name1", "patronymic1", 'm', 1990, 1, 1, 1990, 12, 12, "ukr");
	Passport pass2("surname2", "name2", "patronymic2", 'f', 1992, 2, 2, 2000, 11, 11, "ukr");
	ForeignPassport fpass("surname1", "name1", "patronymic1", 'm', 1993, 1, 1, 1999, 12, 12, "ukr", "visa1");
	std::cout << pass1 << std::endl << pass2 << std::endl << fpass;

}