#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

template<typename T>
class Matrix
{
public:
	Matrix()
	{
		sizeD1 = sizeD2 = 0;
		arr = nullptr;
	}

	Matrix(size_t sizeD1, size_t sizeD2) : sizeD1(sizeD1), sizeD2(sizeD2)
	{
		newMem();
	}

	~Matrix()
	{
		freeMem();
	}

	friend ostream& operator<<(ostream& os, const Matrix& rval)
	{
		for (size_t i = 0; i < rval.sizeD1; i++)
		{
			for (size_t j = 0; j < rval.sizeD2; j++)
			{
				os << rval.arr[i][j] << "\t";
			}
			os << endl;
		}
		return os;
	}

	friend istream& operator>>(istream& is, const Matrix& rval)
	{
		cout << "Enter the matrix values:\n";
		for (size_t i = 0; i < rval.sizeD1; i++)
		{
			for (size_t j = 0; j < rval.sizeD2; j++)
			{
				cout << "Val " << i * rval.sizeD2 + j + 1 << " of " << rval.sizeD1 * rval.sizeD2 << "->";
				is >> rval.arr[i][j];
			}
		}
		return is;
	}

	T* operator[](size_t i)
	{
		if (i >= sizeD1) throw "Out of range";
		return arr[i];
	}

	Matrix& operator=(const Matrix& rval)
	{
		if (sizeD1 != rval.sizeD1 || sizeD2 != rval.sizeD2)
		{
			freeMem();
			sizeD1 = rval.sizeD1;
			sizeD2 = rval.sizeD2;
			newMem();
		}
		copyByte(rval);
		return *this;
	}

	Matrix(const Matrix& rval)
	{
		sizeD1 = rval.sizeD1;
		sizeD2 = rval.sizeD2;
		newMem();
		copyByte(rval);
	}

	bool operator==(const Matrix& rval) const
	{
		if (sizeD1 != rval.sizeD1 || sizeD2 != rval.sizeD2) throw "Size mismatch";
		for (size_t i = 0; i < sizeD1; i++)
		{
			for (size_t j = 0; j < sizeD2; j++)
			{
				if (arr[i][j] != rval.arr[i][j]) return false;
			}
		}
		return true;
	}

	bool operator!=(const Matrix& rval) const
	{
		return !(*this == rval);
	}

	Matrix operator+(const Matrix& rval) const
	{
		if (sizeD1 != rval.sizeD1 || sizeD2 != rval.sizeD2) throw "Size mismatch";
		Matrix tmp(*this);
		for (size_t i = 0; i < sizeD1; i++)
		{
			for (size_t j = 0; j < sizeD2; j++)
			{
				tmp.arr[i][j] += rval.arr[i][j];
			}
		}
		return tmp;
	}

	Matrix operator-(const Matrix& rval) const
	{
		if (sizeD1 != rval.sizeD1 || sizeD2 != rval.sizeD2) throw "Size mismatch";
		Matrix tmp(*this);
		for (size_t i = 0; i < sizeD1; i++)
		{
			for (size_t j = 0; j < sizeD2; j++)
			{
				tmp.arr[i][j] -= rval.arr[i][j];
			}
		}
		return tmp;
	}

	Matrix operator*(const Matrix rval) const
	{
		if (sizeD2 != rval.sizeD1) throw "Size mismatch";
		Matrix tmp(sizeD1, rval.sizeD2);
		tmp.sizeD1 = sizeD1;
		tmp.sizeD2 = rval.sizeD2;
		for (size_t i = 0; i < tmp.sizeD1; i++)
		{
			for (size_t j = 0; j < tmp.sizeD2; j++)
			{
				for (size_t k = 0; k < sizeD2; k++)
				{
					tmp.arr[i][j] += arr[i][k] * rval.arr[k][j];
				}
			}
		}
		return tmp;
	}

	Matrix transpose() const//transpose matrix
	{
		Matrix tmp(sizeD2, sizeD1);
		for (size_t i = 0; i < sizeD1; i++)
		{
			for (size_t j = 0; j < sizeD2; j++)
			{
				tmp.arr[j][i] = arr[i][j];
			}
		}
		return tmp;
	}

	void fillRand(int min, int max)//fill matrix with random values from min to max
	{
		for (size_t i = 0; i < sizeD1; i++)
		{
			for (size_t j = 0; j < sizeD2; j++)
			{
				arr[i][j] = randVal(min, max, arr[i][j]);
			}
		}
	}

	T& inputElement()//to be revised
	{
		cout << "i->";
		size_t vali;
		cin >> vali;
		cout << "j->";
		size_t valj;
		cin >> valj;
		if (vali >= sizeD1 || valj >= sizeD2) throw "Out of range";
		cout << "val->";
		T tmpv;
		cin >> tmpv;
		arr[vali][valj] = tmpv;
		return arr[vali][valj];
	}

private:
	size_t sizeD1;
	size_t sizeD2;
	T** arr;//matrix

	void newMem()//allocate memory
	{
		arr = new T * [sizeD1];
		for (size_t i = 0; i < sizeD1; i++)
		{
			arr[i] = new T[sizeD2]{};
		}
	}

	void freeMem()//free memory
	{
		if (arr)
		{
			for (size_t i = 0; i < sizeD1; i++)
			{
				delete[] arr[i];
			}
			delete arr;
			arr = nullptr;
		}
	}

	void copyByte(const Matrix& rval)//copy mem range
	{
		for (size_t i = 0; i < sizeD1; i++)
		{
			memmove_s(arr[i], sizeD2 * sizeof(T), rval.arr[i], rval.sizeD2 * sizeof(T));
		}
	}

	int randVal(int min, int max, int)//random value for int
	{
		return rand() % (max - min + 1) + min;
	}

	double randVal(int min, int max, double)//random value for double
	{
		return rand() % (max - min + 1) + min + rand() % 100 / 100.;
	}

	char randVal(int min, int max, char)//random value for char
	{
		return rand() % ('z' - 'a' + 1) + 'a';
	}

};


