#include <iostream>

// returns r-value
int add(int x, int y) {
	return x + y;
}

//returns l-value
int& transform(int& x) {
	x *= x;
	return x;
}

void print(int& x) {
	std::cout << "print(int&)" << std::endl;
}

void print(const int& x) {
	std::cout << "print(cons int&)" << std::endl;
}

void print(int&& x) {
	std::cout << "print(int&&)" << std::endl;
}

int main() {
	// x, y, z are l-valeus and 5, 10, 8 are r-values
	int x = 5;
	int y = 10;
	int z = 8;

	// expression returns r-value
	int result = (x + y) * z;

	//expression returns l-value
	++x = 6;

	int&& r1 = 6;
	int&& r2 = add(2, 3);
	int&& r3 = 7 + 2;
	int& ref = transform(x);
	const int& ref2 = 3;

	print(x);
	print(3);

	return 0;
}