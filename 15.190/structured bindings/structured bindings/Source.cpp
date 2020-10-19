#include <iostream>
#include <string>
#include <map>
struct person {
	std::string m_name;
	int m_age;
	person() = default;
	person(std::string name, int age) : m_name(name), m_age(age) {};
};

struct s {
	int ar1[8];
	char ch1[256];
};
int main() {
	// structured binding with objects
	person p{ "amir",32 };
	auto	[name1, age1] = p;		// structured binding - anonymous entity will be created as a copy of the object p. const and volatile qualifiers can be used
	name1 = "delta";
	std::cout << p.m_name << std::endl;
	auto&	[name2, age2] = p;		// structured binding - an anonymous entity will be created as a reference to the object p
	name2 = "delta";
	std::cout << p.m_name << std::endl;
	
	//structured bining with pairs
	std::pair<int,int> x{ 1,2 };
	auto [x1, x2] = x;

	std::cout << "("<< x1 << "," << x2 << ")" << std::endl;

	// structured binidng with map
	std::map<int, std::string> errorInfo{ {1, "not available"},{2, "ports in use"} };
	for (auto err: errorInfo)
		std::cout << err.first << ":" << err.second << std::endl;
	for (auto [key, value] : errorInfo)
		std::cout << key << ":" << value << std::endl;

	int arr[] = { 1,2,3 };
	auto [a, b, c] = arr;
	std::cout << a << b << c << std:: endl;

	auto arr2 = arr;		//arr2 is a pointer to arr[0]; the array automatically decays to a pointer

	s S1{};
	auto [sInt, sChar] = S1;	//sInt and sChar are array types here
}