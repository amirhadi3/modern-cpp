#include <iostream>

int sum() {
	return 0;
};

template<typename T, typename...Args>
auto sum(T a, Args ... arg) {
	return a + sum(arg ...);
}

template<typename...Args>
auto sumUnaryFold(Args ... arg) {
	return (arg + ...);
}

template<typename...Args>
auto sumBinaryFold(Args...arg) {
	return (arg + ... + 0); 
}

template<typename ... Args>
auto anyof(Args...arg) {
	return ((arg % 2 == 0) || ...);
}

template <typename ...Args>
auto allof(Args...arg) {
	return ((arg % 2 == 0) && ...);
}

template<typename ... Args, typename predicate>
auto allofp(predicate p, Args ... arg) {
	return (... && p(arg));
}

template<typename ... Args>
auto printer(Args ... arg) {
	(std::cout << ... << arg);
}
int main() {
	std::cout << "variadic template sum: " << sum(1, 2, 3, 4, 5) << std::endl;
	std::cout << "unary folding expressions sum: " << sumUnaryFold(1, 2, 3, 4, 5) << std::endl;
	std::cout << "binary folding expressions sum: " << sumBinaryFold() << std::endl;
	std::cout << "binary folding expressions sum: " << sumBinaryFold(1, 2, 3, 4, 5) << std::endl;
	std::cout << "unary folding expressions anyof-even: " << anyof(1, 3, 3, 5, 5) << std::endl;
	std::cout << "unary folding expressions allof-even: " << allof(1, 2, 3, 4, 5) << std::endl;
	std::cout << "unary folding expressions printer: " << std::endl; printer(1, 2, 3, 4, "test", "t"); std::cout << std::endl;
	std::cout << "unary folding expressions all of even with predicate: " << allofp([](auto x) {return (x % 2 == 0); }, 1, 2, 3, 4) << std::endl;
	return 0;
}