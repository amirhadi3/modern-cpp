#include <iostream>

int main() {
	int* p = new int(5);
	std::cout << *p << std::endl;
	*p = 10;
	std::cout << *p << std::endl;
	delete p;
	p = nullptr;
}