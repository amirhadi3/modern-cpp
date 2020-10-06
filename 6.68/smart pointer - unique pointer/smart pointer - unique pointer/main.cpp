#include <iostream>
#include "integer.h"
#include <memory>
// -* indicates c++ pointer

void display(integer* p) {
	if (!p)
		return;
	std::cout << p->getValue() << std::endl;
}

integer* getPointer(int value) {
	integer* p = new integer{value};
	return p;
}

void store1(std::unique_ptr<integer> p) {
	std::cout << "storing data into a file: " << p->getValue() << std::endl;
}

void store2(std::unique_ptr<integer> & p) {
	std::cout << "storing data into a file: " << p->getValue() << std::endl;
}

void operate(int value) {
	// -* integer* p = getPointer(value);
	std::unique_ptr<integer> p{ getPointer(value) };
	if (p == nullptr) {
		// -* p = new integer{value};
		p.reset(new integer{ value });
	}
	p->setValue(100);
	display(p.get());
	// -* delete(p);
	// -*p = nullptr;
	// -* p = new integer{};
	p.reset(new integer{});
	*p = __LINE__;
	display(p.get());
	store2(p);
	p->setValue(20);
	(*p).setValue(100);
	store1(std::move(p));
	// p cannot be used after this line because the ownership is moved to the function.
	//delete p;
}

int main() {
	operate(5);
	return 0;
}