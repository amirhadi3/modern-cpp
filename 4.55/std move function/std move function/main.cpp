#include <iostream>
#include "integer.h"

void print(integer val) {
	std::cout << "print the m_pInt: " << val.getValue() << std::endl;
}

int main() {
	integer a(1);
	std::cout << a.m_pInt << std::endl;
	std::cout << "after definition: a.m_pInt: " << a.m_pInt << std::endl;

	// the two lines below are identical. the second one uses the std::move function which is more readable. it is in utility header file
	//integer b{ static_cast<integer&&>(a)};
	integer b{ std::move(a) };
	std::cout << "after move assignment: b.m_pInt: " << b.m_pInt << std::endl;

	std::cout << "after move assignement a.m_pInt: " << a.m_pInt << std::endl;
	a.setValue(10);
	std::cout << "after reinitialization a.m_pInt: " << a.m_pInt << std::endl;

	// a potential application of std::move is when the resources allocated to an object are no longer needed after an operation
	// an example is we print the content of a and we no longer need its resources:
	print(std::move(a));

	return 0;
}