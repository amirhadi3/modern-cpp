#include "integer.h"
#include <iostream>
void print(integer i) {
	std::cout << i.getValue() << std::endl;
}

integer add(int x, int y) {
	return integer(x + y);
}

int main() {
	// 1) allocates a memory with size of integer and value of 10
	// 2) allocates another memory at &p1 which its value is the address of 1
	int* p1 = new int(10);
	std::cout << "the int memory location is at: " << p1 << std::endl;
	std::cout << "the int* memory location is at: " << &p1 << std::endl;

	// shallow copy: only allocates memory for a pointer with the address of p1
	int* p2 = p1;
	std::cout << "the int memory location is at: " << p2 << std::endl;
	std::cout << "the int* memory location is at: " << &p2 << std::endl;

	// deep copy:
	// 1) allocates a memory with size of integer and value of *p1
	// 2) allocates another memory at &p3 which its value is the address of 1
	int* p3 = new int(*p1);
	std::cout << "the int memory location is at: " << p3 << std::endl;
	std::cout << "the int* memory location is at: " << &p3 << std::endl;

	// a user defined copy constructor has to be defined if the object needs
	// to copy pointers and etc.
	// : 1 - invoke the copy constructor
	// : 2 - an object is past into a function by value
	// : 3 - a function returns an object by value
	// : 4 - assignment operator
	// the default behavior of the compiler's syntehsized copy constructor and 
	// assignment operator is shallow copy

	integer i(5);
	integer i2(i);
	integer i3 = i2;
	integer i4 = add(1, 2);
	std::cout << i.getValue() << std::endl;
	return 0;
}