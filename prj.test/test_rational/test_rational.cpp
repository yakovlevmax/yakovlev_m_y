#include "rational.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

bool TestParse(const std::string& str) {
	istringstream istrm(str);
	Rational z;
	istrm >> z;
	if (istrm.good()) {
		cout << "Read success: " << str << " -> " << z << endl;
	}
	else {
		cout << "Read error : " << str << " -> " << z << endl;
	}
	return istrm.good();
}

int main()
{
	Rational x(3,4);
	Rational y(7, 15);
	x += Rational(12, 5);
	cout << x<<" + "<<y<<" = "<< x+y << endl;
	cout << x << " - " << y << " = " << x - y << endl;
	cout << x << " * " << y << " = " << x * y << endl;
	cout << x << " / " << y << " = " << x / y << endl;
	TestParse("{-8/9}");
	TestParse("{-8/ -9}");
	TestParse("{81/ -9}");
	TestParse("{3 /6}");
	TestParse("{8/9");
	return 0;
}