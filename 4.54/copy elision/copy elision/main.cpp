#include <iostream>
#include "integer.h"
integer add(int a, int b) {
	integer temp (a+b);
	return temp;	//named return value optimization
}

integer add1(int a, int b) {
	return integer(a + b);	//better implementation: return value optimization
}

int main() {
	//integer a = 3;

	/*
	For the above instruction, the compilers reads it equivalent to
	integer a = integer (3);
	if copy elision is deactivated (possible in linux gcc):
	the copiler first invokes 
	integer(int) constructor to make the rhs
	it then invokes the move constructor (integer(integer&&)) to move the
	rhs temporary object into a.

	when copy elision is enabled; by default in VS:
	the comiler invokes the value constructor integer(int) because 3 is of type int
	*/

	//integer a = add(2,3);

	/* if copy elision is turned off:
	integer(int)
	integer(integer &&)
	integer(integer &&);

	if copy elision is active in debug mode
	integer(int);
	integer(integer &&)

	copy elision + release mode
	integer(int)
	*/
	

	/*****For copy elision to work, the class has to have the copy and move constructors*****/
	integer b = add1(2, 3);
	std::cout << "just before function exit" << std::endl;
	return 0;
}