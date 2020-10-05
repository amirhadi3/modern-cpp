#include <iostream>
#include "integer.h"
#include <memory>			//header file that has smart pointers

class intPtr {
	integer* m_p;
public:
	intPtr(integer* p) : m_p(p) {};
	~intPtr() {
		delete m_p;
	}
	integer* operator -> () {
		return m_p;
	}

	integer & operator*() {
		return *m_p;
	}
};

void processUniqueP(std::unique_ptr<integer> ptr) {
	std::cout << ptr->getValue() << std::endl;
}

void processSharedP(std::shared_ptr<integer> ptr) {
	std::cout << ptr->getValue() << std::endl;
}

void createInteger() {
	intPtr p = new integer;
	p->setValue(5);
	std::cout << p->getValue() << std::endl;

	(*p).setValue(6);
	std::cout << p->getValue() << std::endl;
}

void createInteger_uniqueP() {
	std::unique_ptr<integer> p(new integer);
	(*p).setValue(6);
	std::cout << p->getValue() << std::endl;
	processUniqueP(std::move(p));
	// the line below is no longer valid because
	// the copy constructor of the unqiue pointer is deleted
	// however its move constructor is usable
	// thus when the ownership of resource is transferred to ptr in process
	// it cannot be used after the call to the process command.
	// ptr is deleted at the end of running the function
	//std::cout << p->getValue() << std::endl;
}

void createInteger_sharedP() {
	std::shared_ptr<integer> p(new integer);
	(*p).setValue(10);
	std::cout << p->getValue() << std::endl;
	// the copy constructor for shared pointers are not deleted
	// shared pointers have an internal reference counter
	// the counter counts the number of references to the allocated memory
	// it releases the memory when the counter is zero.
	processSharedP(p);
	std::cout << p->getValue() << std::endl;
}

int main() {
	createInteger_uniqueP();
	createInteger_sharedP();
	return 0;
}