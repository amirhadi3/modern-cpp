#include <iostream>
#include <string>
int main() {

	std::string filename("C:\\temp\\newfile.txt");
	std::cout << filename << std::endl;

	std::string filename1(R"(C:\temp\newfile.txt)");
	std::cout << filename1 << std::endl;
	// our custom delimeter must be less than 16 characters and do not include white space or "\"
	std::string str(R"customdeli(C++ Introduced filesystem API "(in C++17)")customdeli");
	std::cout << str << std::endl;
	
	return 0;
}