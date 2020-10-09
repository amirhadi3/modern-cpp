#include <iostream>
#include <memory>
#include <vector>
class A {
public:
	A() {
		std::cout << "A()" << std::endl;
	}
	~A() {
		std::cout << "~A()" << std::endl;
	}
};

class B {
public:
	B() {
		std::cout << "B()" << std::endl;
	}
	~B() {
		std::cout << "~B()" << std::endl;
	}
};

class test {
	std::unique_ptr<A> pA{};
	B b{};
	std::unique_ptr<int> pInt{};
	std::vector<int> pArr;
	std::string pStr;
public:
	test() {
		std::cout << "Test():Acquire resources" << std::endl;
		pA.reset(new A);
		throw std::runtime_error("failed to initialize");
	}
	~test() { std::cout << "~Test():Release resources" << std::endl; }
};

int main() {
	try {
		test t;
	}
	catch (std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}