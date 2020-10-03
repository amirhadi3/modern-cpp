#include <iostream>

void Add(int a, int b, int& result)
{
	result = a + b;
}

void Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void Factorial(int a, int& result)
{
	result = 1;
	for (int i = 1; i <= a; ++i)
		result = result * i;
}

int main() {
	using namespace std;
	int a = 5;
	int b = 6;
	int c;

	Add(a, b, c);
	cout << c << endl;
	swap(a, b);
	cout << a << " " << b << endl;
	Factorial(a, c);
	cout << c << endl;
}