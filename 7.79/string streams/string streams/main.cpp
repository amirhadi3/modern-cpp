#include <iostream>
#include <string>
#include <sstream>

int main() {
	int a{ 6 }, b{ 10 }, sum{ a + b };
	std::cout << "sum of " << a << " & " << b << " is: " << sum << std::endl;
	std::stringstream ss{};
	ss << "sum of " << a << " & " << b << " is: " << sum << std::endl;
	std::cout << ss.str() << std::endl;
	std::string s = ss.str();	//return the copy of the buffer as a standard string object
	ss.str("Replace the content of ss buffer");
	std::cout << ss.str() << std::endl;
	ss.str("");
	//convert primitive types to string objects:
	ss << sum << std::endl;
	auto ssum = ss.str();
	std::cout << ssum;

	float rand = 12.7f;
	ss.str("");
	ss << rand;
	std::string sr{ ss.str() };
	std::cout << sr << std::endl;

	//alternatively;
	std::cout << std::to_string(sum) << std::endl;
	std::cout << std::to_string(12.7f) << std::endl;

	//parsing data in a string stream
	std::string ps{ "89 98 120" };
	ss.str(ps);
	while (ss >> a) {
		std::cout << a << " ";
	}
	std::cout << std::endl;

	ps = "18.9";
	rand = std::stof(ps);
	sum = std::stoi("12");
	std::cout << rand << " " << sum << std::endl;

	return 0;
}