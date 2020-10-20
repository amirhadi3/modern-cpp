#include <iostream>
#include <type_traits>
#include <string>
template<typename T>
void print(const T& value) {
	if constexpr (std::is_pointer_v<T>)
		std::cout << *value << std::endl;
	else if constexpr (std::is_array_v<T>) {
		for (auto v : value)
			std::cout << v << " ";
		std::cout << std::endl;
	}
	else
		std::cout << value << std::endl;
}

template<typename T>
std::string toString(T value) {
	if constexpr (std::is_arithmetic_v<T>)
		return std::to_string(value);
	else
		return std::string{ value };
}

void checkMode() {
	if constexpr (sizeof(void*) == 4)
		std::cout << "32-bit\n";
	else if constexpr (sizeof(void*) == 8)
		std::cout << "64-bit\n";
	else
		std::cout << "mode unknown\n";
}

int main() {
	int value{ 5 };
	print(value);
	print(&value);
	int arr[] = { 1,2,3,4,5 };
	print(arr);

	auto s = toString(value);
	std::cout << s << std::endl;

	checkMode();
	return 0;
}