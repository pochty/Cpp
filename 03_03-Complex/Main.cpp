#include "Complex.h"
#include <iomanip>
using namespace std;
int main()
{
	Complex z;
	std::cin >> z;
	std::cout << z << endl;
	Complex z1(1, 2);
	Complex z2(3, 4);
	try
	{
		std::cout << "z1: " << z1 << "\nz2: " << z2 << std::endl;
		cout << "z1 + z2: " << (z1 + z2) << endl;
		cout << "z1 - z2: " << (z1 - z2) << endl;
		cout << "z1 * z2: " << (z1 * z2) << endl;
		cout << "z1 / z2: " << (z1 / z2) << endl;
		cout << "z1 == z2: " << boolalpha << (z1 == z2) << endl;
		cout << "z1 != z2: " << boolalpha << (z1 != z2) << endl;
	}
	catch (const char* msg)
	{
		cout << msg;
	}
}