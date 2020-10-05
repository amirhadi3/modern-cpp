#include <iostream>

int main() {
	int a(5), b(2);
	float f1 = a / b;										//implicit conversion - integer to float may result in loss of data
	f1 = (float)a / b;									// c-style cast not recommended in c++ because they do not check for the validness of the cast and c-style casts discard the qualifiers
	std::cout << f1 << std::endl;
	float f2 = static_cast<float>(a) / b;				// static cast is superior than c style casting because it cheks for validness
	std::cout << f2 << std::endl;
	char* p = (char*)&a;								// not right!!!!!!!!!!!!!!!!!!!!!!!!
	//p = static_cast<char*>(&a);						// errors because conversion from int* to char* is not allowed
	p = reinterpret_cast<char*>(&a);					// re-interpret cast does not discard the qualifiers


	/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
	const int x = 10;
	int* q = (int*)&x;
	*q = 26;

	std::cout << "c-style cast" << std::endl;
	std::cout << "x : " << x << std::endl;
	std::cout << "*q: " << *q << std::endl;
	std::cout << "&x: " << &x << std::endl;
	std::cout << "q : " << q << std::endl;

	/*
	x : 10
	*q: 26
	&x: 00CFF93C
	q : 00CFF93C
	*/
	/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

	/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
	const int x1 = 10;
	int* q1 = const_cast<int*>(&x1);
	*q1 = 26;
	std::cout << "const_cast" << std::endl;
	std::cout << "x : " << x1 << std::endl;
	std::cout << "*q: " << *q1 << std::endl;
	std::cout << "&x: " << &x1 << std::endl;
	std::cout << "q : " << q1 << std::endl;
	/*
	x : 10
	*q: 26
	&x: 00CFF93C
	q : 00CFF93C
	*/
	/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
	return 0;
}