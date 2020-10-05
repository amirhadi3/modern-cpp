#include <iostream>
#include "integer.h"

//integer operator + (const integer& a, const integer& b) noexcept {
//	integer temp;
//	temp.setValue(a.getValue() + b.getValue());
//	return temp;
//}

integer operator+ (const int& x, const integer& b) {
	integer temp;
	temp.setValue(x + b.getValue());
	return temp;
}

std::ostream & operator << (std::ostream & out, const integer& obj) {
	out << obj.getValue();
	return out;
}

std::istream & operator >> (std::istream & in, integer& obj) {
	int x;
	in >> x;
	*obj.m_pInt = x;
	return in;
}

int main() {
	// + operator
	integer a(1), b(2);
	integer sum = a + b;
	
	sum = sum + 5; //sum.operator+(5)
	sum = 5 + sum; //it has to be overloaded as a global function (above) because 5 is not of type integer;

	// left and right increment operator
	++sum;
	std::cout << sum.getValue() << std::endl;
	std::cout << (sum++).getValue() << std::endl;

	// comparision operator
	if (a == b)
		std::cout << "same" << std::endl;
	else
		std::cout << "not same" << std::endl;

	// assignment operator
	integer c = a;
	std::cout << c.getValue() << std::endl;

	c = b;
	std::cout << c.getValue() << std::endl;

	//extraction and insertion operators

	// after a global function were defined to overload the insertion operator for the class integer
	// it can be used as below
	std::cout << c << std::endl;
	// the line above is interpreted as
	operator << (std::cout, c).operator<<(std::endl);

	std::cin >> a >> b;
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	// function call operator --> can be used as callback 
	sum();

	//friend class
	printer p;
	p.print(a);

	return 0;
}