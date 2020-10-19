#include <iostream>

class evaluationOrder {
public:
	evaluationOrder & first(int) {
		std::cout << __FUNCSIG__ << std::endl;
		return *this;
	}
	evaluationOrder & second(int) {
		std::cout << __FUNCSIG__ << std::endl;
		return *this;
	}
};

int firstExpression(int) {
	std::cout << __FUNCSIG__ << std::endl;
	return 0;
}

int secondExpression(int) {
	std::cout << __FUNCSIG__ << std::endl;
	return 0;
}

int main() {
	// the execution order is different in c++14 and c++17
	evaluationOrder eo;
	eo.first(firstExpression(0)).second(secondExpression(0));
}