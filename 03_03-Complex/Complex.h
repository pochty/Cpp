/*Class Complex number*/
#pragma once
#include <iostream>

class Complex
{
public:
	Complex(double re, double im) : re_(re), im_(im)
	{
	}
	Complex() : Complex(0.0, 0.0)
	{
	}
	double GetRe();
	double GetIm();
	void Set(double re, double im);
	Complex operator+(const Complex& other);
	Complex operator-(const Complex& other);
	Complex operator*(const Complex& other);
	Complex operator/(const Complex& other);
	bool operator==(const Complex& other);
	bool operator!=(const Complex& other);
	friend std::ostream& operator<<(std::ostream& os, Complex other);
	friend std::istream& operator>>(std::istream& is, Complex& other);

private:
	double re_;//real part
	double im_;//imaginary part
};

