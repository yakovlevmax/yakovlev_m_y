#include <iostream>
#include "rational.h"

Rational::Rational(const int num)
{
	num_ = num;
	den_ = 1;
}

Rational::Rational(const int num, const int den) : num_(num), den_(den) {
	check();
	simplify();
}

bool Rational::operator==(const Rational& rhs) const 
{
	return (num_ == rhs.num_) && (den_ == rhs.den_);
}

bool Rational::operator!=(const Rational& rhs) const 
{
	return !operator==(rhs);
}

Rational operator+(const Rational& lhs, const Rational& rhs) 
{
	Rational sum = lhs;
	sum += rhs;
	return sum;
}

Rational operator-(const Rational& lhs, const Rational& rhs)
{
	int numerator = lhs.num_ * rhs.den_ - rhs.num_ * lhs.den_;
	int denominator = lhs.den_ * rhs.den_;
	return Rational(numerator, denominator);
}

Rational& Rational::operator/=(const Rational rhs)
{
	num_ *= rhs.den_;
	den_ *= rhs.num_;
	simplify();
	return *this;
}

Rational operator/(Rational lhs, Rational rhs)
{
	Rational res = lhs;
	res /= lhs;
	return res;
}

Rational& Rational::operator+=(const Rational& rhs) 
{
	num_ = num_ * rhs.den_ + rhs.num_ * den_;
	den_ *= rhs.den_;
	simplify();
	return *this;
}

Rational& Rational::operator+=(const int rhs) 
{
	return operator+=(Rational(rhs));
}

Rational& Rational::operator*=(const int rhs)
{
	num_ *= rhs;
	simplify();
	return *this;
}

Rational& Rational::operator*=(const Rational& rhs)
{
	num_ *= rhs.num_;
	den_ *= rhs.den_;
	simplify();
	return *this;
}

Rational operator*(Rational lhs, Rational rhs)
{
	Rational mul = lhs;
	lhs *= rhs;
	return lhs;
}



int Rational::GCD(int n, int d) 
{
	while (d) {
		n %= d;
		std::swap(n, d);
	}
	return n;
}

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs)
{
	return rhs.WriteTo(ostrm);
}

std::istream& operator>>(std::istream& istrm, Rational& rhs)
{
	return rhs.ReadFrom(istrm);
}

std::ostream& Rational::WriteTo(std::ostream& ostrm) const
{
	ostrm << left_brace_ << num_ << separator_ << den_ << right_brace_;
	return ostrm;
}

std::istream& Rational::ReadFrom(std::istream& istrm) 
{
	char left_brace('{');
	int numerator(0);
	char slash('/');
	int denominator(1);
	char right_brace('}');
	istrm >> left_brace >> numerator >> slash >> denominator >> right_brace;
	if (istrm.good()) {
		if ((Rational::left_brace_ == left_brace) && (Rational::separator_ == slash) &&
			(Rational::right_brace_ == right_brace)) {
			Rational::num_ = numerator;
			Rational::den_ = denominator;
			Rational::check();
			Rational::simplify();
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}

void Rational::check()
{
	if (den_ == 0) {
		throw ("Zero denominator!");
	}
}

void Rational::simplify() 
{
	if (den_ < 0) {
		num_ *= -1;
		den_ *= -1;
	}
	int g = GCD(num_, den_);
	num_ /= g;
	den_ /= g;
}