#include <iostream>

template<typename T>
struct unnamed {
	T operator()(T x, T y) {
		std::cout << "sum(T ,T) function object" << std::endl;
		return x + y;
	}
};

int main() {
	auto fn = []()
	{
		std::cout << "welcome to lambda expressions" << std::endl;
	};
	fn();

	std::cout << typeid(fn).name() << std::endl;
	
	auto sum = [](int x, int y) noexcept {
		std::cout << "sum(int ,int) lambda expression" << std::endl;
		return x + y;
	};
	auto sum1 = [](auto x, auto y) {
		std::cout << "sum(auto ,auto) lambda expression" << std::endl;
		return x + y;
	};
	std::cout << std::endl;
	unnamed<float> s;

	std::cout << sum(3, 5) << std::endl;
	std::cout << sum1(3.2f, 5) << std::endl;
	std::cout << s(3, 5) << std::endl;
	return 0;
}