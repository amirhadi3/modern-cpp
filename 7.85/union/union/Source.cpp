#include <iostream>

union Test {
	int x;
	char ch;

	Test() :x{} {
		std::cout << __FUNCSIG__ << std::endl;

	}
	~Test() {
		std::cout << __FUNCSIG__ << std::endl;
	}
};

void print(const Test & t) {
	std::cout << "size: " << sizeof(Test) << std::endl;
	std::cout << ".x: " <<t.x << std::endl;
	std::cout << ".ch: " << t.ch << std::endl;
}
int main() {
	Test t;
	t.x = 100;
	print(t);
	t.ch = 'c';
	print(t);
	return 0;
}