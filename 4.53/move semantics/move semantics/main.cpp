#include <iostream>
#include "integer.h"
integer add(const integer& a, const integer& b) {
	integer temp;
	temp.setValue(a.getValue() + b.getValue());
	std::cout << temp.m_pInt << std::endl;
	return temp;
}
int main() {
	integer a(1), b(3);
	integer c = add(a, b);
	std::cout << c.m_pInt << std::endl;
	//a.setValue(add(a, b).getValue());
	std::cout << "just before function exit" << std::endl;
	return 0;
}