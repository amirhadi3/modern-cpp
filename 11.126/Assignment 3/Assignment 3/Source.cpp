#include <iostream>
#include <string>
#include <memory>
#include "template.h"

int main() {
	float f[6]{ 1.2f,3.4f,5.0f,9.8f,5.2f,4.3f };
	std::cout << Add(f[0], f[1]) << std::endl;
	std::cout << ArraySum(f) << std::endl;
	std::cout << Max(f) << std::endl;
	auto mm = MinMax(f);
	std::cout << "(" << mm.first << "," << mm.second << ")" << std::endl;

	std::cout << max(3, 5) << std::endl;
	std::cout << max(3.3f, 3.8f) << std::endl;

	std::string st[]{ "Amir","Hossein","Hadi","sahra","zebra" };
	auto s = Max(st);
	std::cout << s << std::endl;

	const char* ch[]{ "Amir","Hossein","Hadi","sahra","zebra" };
	std::cout << std::endl;
	
	const char* c = Max(ch);
	std::cout << c << std::endl;
	delete c;
	c = nullptr;
	return 0;
}