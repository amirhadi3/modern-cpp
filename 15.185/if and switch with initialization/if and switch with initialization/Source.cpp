#include <iostream>
#include <string>
#include <fstream>
//void alloc() {
//	int* p = (int*)malloc(sizeof(int));
//	if (p != nullptr) {
//		*p = 5;
//		free(p);
//	}
//}

void alloc() {
	if (int* p = (int*)malloc(sizeof(int)); p != nullptr) {
		*p = 5;
		free(p);
	}
	else {
		// p will be accessible here as well
	}
}

void write(const std::string & data) {
	// out is only accessible within the if ... elif ... else statements
	if (std::ofstream out{ "file.txt" }; data.empty()) {
		std::cout << "no data to write" << std::endl;
	}
	else {
		out << data << std::endl;
	}
}

void usingSwitch(int && errorCode) {
	switch (std::ofstream error{ "error.txt" }; errorCode) {
	case 0:
		error << "invalid parameter \n";
		break;
	case 1:
		error << "could not read from the file \n";
		break;
	default:
		error << "error code unknown \n";
		break;
	}
}

int main() {
	alloc();
	write("this is a test");
	usingSwitch(0);
	return 0;
}