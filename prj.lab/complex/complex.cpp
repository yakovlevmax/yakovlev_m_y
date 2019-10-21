#include <iostream>
#include <sstream>
#include <cmath>
#include "complex.h" 

Complex::Complex(const double real)
{
	real_ = real;
	im_ = 0.0;
}
Complex::Complex(const double real, const double im)
{
	real_ = real;
	im_ = im;
}

Complex& Complex::operator+=(const Complex& rhs) 
{
	real_ += rhs.real_;
	im_ += rhs.im_;
	return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs) 
{
	Complex sum = lhs;
	sum += rhs;
	return sum;
}

Complex& Complex::operator-=(const Complex& rhs)
{
	real_ -= rhs.real_;
	im_ -= rhs.im_;
	return *this;
}

Complex operator-(const Complex& lhs, const Complex& rhs)
{
	Complex diff = rhs;
	diff -= rhs;
	return diff;
}

Complex& Complex::operator*=(const double rhs) 
{
	real_ *= rhs;
	im_ *= rhs;
	return *this;
}


std::ostream& Complex::WriteTo(std::ostream& ostrm) const 
{
	ostrm << left_brace_ << real_ << separator_ << im_ << right_brace_;
	return ostrm;
}

std::istream& Complex::ReadFrom(std::istream& istrm) {
	char left_brace(0);
	double real(0.0);
	char comma(0);
	double imaginary(0.0);
	char right_brace(0);
	istrm >> left_brace >> real >> comma >> imaginary >> right_brace;
	if (istrm.good()) {
		if ((Complex::left_brace_ == left_brace) && (Complex::separator_ == comma) &&
			(Complex::right_brace_ == right_brace)) {
			real_ = real;
			im_ = imaginary;
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}



Complex& Complex::operator*=(const Complex& rhs) 
{
	real_ = real_ * rhs.real_ - im_ * rhs.im_;
	im_ = real_ * rhs.im_ + rhs.real_ * im_;
	return *this;
}

Complex operator*(const Complex& lhs, const Complex& rhs)
{
	Complex mul = lhs;
	mul *= rhs;
	return mul;
}

bool Complex::operator==(const Complex& rhs) const
{
	return DoubleEquals(real_, rhs.real_) && DoubleEquals(im_, rhs.im_);
}

bool Complex::operator!=(const Complex& rhs) const 
{
	return !operator==(rhs);
}

bool Complex::DoubleEquals(const double a, const double b, const double epsilon)
{
	return std::abs(a - b) < epsilon;
}

std::istream& operator>>(std::istream& istrm, Complex& rhs) 
{
	return rhs.ReadFrom(istrm);
}

std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) 
{
	return rhs.WriteTo(ostrm);
}

Complex& Complex::operator-=(const double rhs)
{
	return operator-=(Complex(rhs)); 
}

Complex& Complex::operator+=(const double rhs)
{
	{return operator+=(Complex(rhs)); }
}


Complex operator*(const Complex& lhs, double rhs)
{
	return Complex(lhs.real_ * rhs, lhs.im_ * rhs);
}

Complex operator/(const Complex& lhs, const Complex& rhs)
{
	if (rhs == Complex())
		throw("Division by zero!");
	double real = (lhs.real_ * rhs.real_ + lhs.im_ * rhs.im_) / (rhs.real_*rhs.real_ + rhs.im_*rhs.im_);
	double im = (rhs.real_ * lhs.im_ + lhs.real_ * rhs.im_) / (rhs.real_ * rhs.real_ + rhs.im_ * rhs.im_);
	return Complex(real, im);
}