#include <iostream>

struct Rational {

	Rational()
	{
		num_ = 0;
		den_ = 1;
	}

	explicit Rational(int num);

	Rational(int num, int den);

	bool operator==(const Rational& rhs) const;

	bool operator!=(const Rational& rhs) const;

	friend Rational operator+(const Rational& lhs, const Rational& rhs);

	friend Rational operator-(const Rational& lhs, const Rational& rhs);

	friend Rational operator*(Rational lhs, Rational rhs);

	friend Rational operator/(Rational lhs, Rational rhs);

	Rational& operator/=(const Rational rhs);

	Rational& operator+=(const Rational& rhs);

	Rational& operator+=(int rhs);

	Rational& operator*=(int rhs);

	Rational& operator*=(const Rational& rhs);

	std::ostream& WriteTo(std::ostream& ostrm) const;

	std::istream& ReadFrom(std::istream& istrm);

	friend std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs);

	friend std::istream& operator>>(std::istream& istrm, Rational& rhs);


	static const char left_brace_{ '{' };
	static const char separator_{ '/' };
	static const char right_brace_{ '}' };

	void simplify();

	void check();

	static int GCD(int n, int d);

	private:
		int num_;
		int den_;
};