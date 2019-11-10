#include "Matrix.h"
using namespace std;

int main()
{
	try
	{
		Matrix<int> A(2, 4);
		A.fillRand(0, 99);
		cout << "Matrix A:\n" << A << endl;
		Matrix<int> B(A);
		cout << "Matrix B:\n" << B << endl;
		cout << "A + B:\n" << A + B << endl;
		cout << "A - B:\n" << A - B << endl;
		cout << "A * B(T):\n" << A * B.transpose() << endl;
		cout << "A == B: " << boolalpha << (A == B) << endl;
		cout << "A != B: " << boolalpha << (A != B) << endl << endl;
		cout << "A[0][0] = B[1][3]:\n";
		A[0][0] = B[1][3];
		cout << A << endl << B << endl;
		cout << "Change element A\n";
		A.inputElement();
		cout << A << endl;
	}
	catch (const char* exMsg)
	{
		cout << exMsg << endl;
	}
}
