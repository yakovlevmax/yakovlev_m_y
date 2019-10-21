#include<iostream>
#include<sstream>
#include "complex.h"

bool TestParse(const std::string& str) {
	using namespace std;
	istringstream istrm(str);
	Complex z;
	istrm >> z;
	if (istrm.good()) {
		cout << "Read success: " << str << " -> " << z << endl;
	}
	else {
		cout << "Read error : " << str << " -> " << z << endl;
	}
	return istrm.good();
}

int main() {
	using namespace std;

	Complex x;
	Complex y;
	x -= Complex(3, 4);
	y += Complex(8.0, 32.22);
	TestParse("{8.9,9}");
	TestParse("{8.9, 9}");
	TestParse("{8.9,9");
	cout << x<<" + "<< y << " = " << x + y<<endl;
	cout << x << " - " << y << " = " << x + y << endl;
	cout << x << " * " << y << " = " << x * y << endl;
	cout << x << " * 5 = " << x * 5.0 << endl;
	cout << x << " / " << y << " = " << x / y << endl;
	return 0;
}

