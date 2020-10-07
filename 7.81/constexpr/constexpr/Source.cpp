#include <iostream>

constexpr int add(int x, int y) {
	return x + y;
}

constexpr int getNumber() {
	return 43;
}

constexpr int max(int x, int y) {
	return x > y ? x : y;
}

constexpr int max2(int x, int y) {
	if (x > y)
		return x;
	else
		return y;
}

int main() {
	// behaves as a constexpr function
	constexpr int i = getNumber();
	int arr[i];

	// behaves as a constexpr function
	const int j = getNumber();
	int arr1[j];

	// behaves as anormal function;
	int x = getNumber();


	constexpr int sum = add(3, 5);

	constexpr int sum2 = add(3, 5);

	return 0;
}


/* constant expression function rules
1. should accept and return literal types only
(void, scalar (int, float, double, char), references, etc.)

2. all constant expression are implicitly inline
*/