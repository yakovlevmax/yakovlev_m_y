struct Complex {
	Complex() 
	{
		real_ = 0.0;
		im_ = 0.0;
	};

	explicit Complex(double real);

	Complex(double real, double imaginary);

	friend std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs);
	friend std::istream& operator>>(std::istream& istrm, Complex& rhs);

	friend Complex operator*(const Complex& lhs, const Complex& rhs);
	friend Complex operator-(const Complex& lhs, const Complex& rhs);
	friend Complex operator+(const Complex& lhs, const Complex& rhs);
	friend Complex operator*(const Complex& lhs, double rhs);
	friend Complex operator/(const Complex& lhs, const Complex& rhs);
	bool operator==(const Complex& rhs) const;
	bool operator!=(const Complex& rhs) const;

	
	Complex& operator+=(const Complex& rhs);
	Complex& operator+=(double rhs);

	Complex& operator-=(const Complex& rhs);
	Complex& operator-=(double rhs);

	Complex& operator*=(const Complex& rhs);
	Complex& operator*=(double rhs);


	std::ostream& WriteTo(std::ostream& ostrm) const;
	std::istream& ReadFrom(std::istream& istrm);

private:
	double real_{ 0.0 };
	double im_{ 0.0 };

	static const char left_brace_{ '{' };
	static const char separator_{ ',' };
	static const char right_brace_{ '}' };

	static bool DoubleEquals(double a, double b, double epsilon = 0.00000001);
};

