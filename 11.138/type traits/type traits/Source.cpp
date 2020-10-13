#include <iostream>
#include <type_traits>

template <typename T>
T Divide(T a, T b) {
	if (std::is_floating_point<T>::value == false)
	{
		std::cout << "inputs must be floating points\n";
		return 0;
	}
	return a / b;
}

template<typename T>
void check(T&&) {
	std::cout << std::boolalpha;
	std::cout << "is reference? " << std::is_reference<T>::value << std::endl;
	std::cout << "after removing: " << std::is_reference<typename std::remove_reference<T>::type>::value << std::endl;
}

int main() {
	std::cout << std::boolalpha
		<< "is integer? "
		<< std::is_integral<int>::value << std::endl;
	std::cout << Divide(5, 2) << std::endl;

	check(5);
	int value{ 6 };
	check(value);
	return 0;
}