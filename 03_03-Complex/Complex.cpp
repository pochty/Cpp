#include "Complex.h"

inline double Complex::GetRe()
{
	return re_;
}

inline double Complex::GetIm()
{
	return im_;
}

inline void Complex::Set(double re, double im)
{
	re_ = re;
	im_ = im;
}

Complex Complex::operator+(const Complex& other)
{
	return Complex(re_ + other.re_, im_ + other.im_);
}

Complex Complex::operator-(const Complex& other)
{
	return Complex(re_ - other.re_, im_ - other.im_);
}

Complex Complex::operator*(const Complex& other)
{
	return Complex(re_ * other.re_ - im_ * other.im_, re_ * other.im_ + im_ * other.re_);
}

Complex Complex::operator/(const Complex& other)
{
	if (!other.re_ && !other.im_)
	{
		throw "Division by zero";
	}
	return Complex((re_ * other.re_ + im_ * other.im_) / (other.re_ * other.re_ + other.im_ * other.im_), (other.re_ * im_ - re_ * other.im_) / (other.re_ * other.re_ + other.im_ * other.im_));
}

bool Complex::operator==(const Complex& other)
{
	return re_ == other.re_ && im_ == other.im_;
}

bool Complex::operator!=(const Complex& other)
{
	return re_ != other.re_ || im_ != other.im_;
}

std::ostream& operator<<(std::ostream& os, Complex other)
{
	os << other.re_ << " + " << other.im_ << "i ";
	return os;
}

std::istream& operator>>(std::istream& is, Complex& other)
{
	std::cout << "Re+Im->";
	is >> other.re_ >> other.im_;
	return is;
}