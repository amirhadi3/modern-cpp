#include <iostream>
#include <fstream>
int main() {
	auto f = [y = 5](int arg) {
		return arg + y;
	};
	int x{ 12 };
	auto g = [y = x](int i) {
		return i * y;
	};
	auto h = [f](int i){
		return i * f(20);
	};
	std::cout << f(10) << std::endl;
	std::cout << g(12) << std::endl;
	std::cout << h(12) << std::endl;

	std::ofstream out{ "file.txt" };
	[out = std::move(out)](int x) mutable {
		out << x;
	} (200);

	out << "test it out baby"; //does not do anything because of the move operator
}