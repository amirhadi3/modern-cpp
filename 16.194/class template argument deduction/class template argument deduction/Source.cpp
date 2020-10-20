#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <string>

template<typename T>
class Data {
	T m_T;
public:
	Data(const T &t):m_T(t) {}
};

// deduction directives (guides)
Data(const char*)->Data <std::string>;
Data(int)->Data<long>;

int main() {
	// in c++17, there is no need to indicate the storage types
	// thanks to class template argument deduction

	std::pair<int, int> p0{ 1,2 };

	std::pair p1{1,2};
	std::pair p2 = std::make_pair(2, 3);

	std::vector<int> v0{ 1,2,3,5,6 };

	std::vector v = { 3,4,2 };

	std::mutex m;
	std::lock_guard lck{ m };

	Data d1{ 5 };
	Data d2{ 8.2f };
	Data d3{ "Hello" };

	Data d4 = d1;
	auto d5 = new Data{ 6 };
	delete d5;

	return 0;
}
