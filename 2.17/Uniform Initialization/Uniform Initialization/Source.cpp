#include <string>
int main() {
	int a1;									//uninitialized 
	int a2 = 0;								//copy initialization
	int a3(5);								//direct initialization
	std::string s1;							//uninitialized
	std::string s2("C++");					//direct initialization

	char c1[8];								//uninitialized
	char c2[8]("hello");					//direct initialization
	char c3[8]({ "hello" });				//direct initialization
	char c4[8] = {'\0' };					//copy initialization
	char c5[8] = {'a','b','c','d' };		//copy initialization
	char c6[8] = { "abcd" };				//copy initialization
	char c7[8] = "hello";					//copy initialization

	int b1{};								//value initialization
	//int b2();								//most vexing parse --> it creates a function
											//with void input and int output
	int b3{ 8 };							//direct initialization
	
	char c8[8]{};							//value initialization
	char c9[8]{ "hello" };					//direct initialization
	char c10[8]{ 'a','b','c' };				//direct initialization

	int* p1 = new int{};					//value initialization
	int* p2 = new int{ 6 };					//direct initialization
	
	char* p3 = new char[8]{};				//value initialization
	char* p4 = new char[8]{'a','b','c'};	//direct initialization

	/* below are examples of narrowing conversion
	float f{2.5};
	int i{ f };

	or

	int i{};
	float f{i};
	*/
}

/*
1. value initialization => T obj {};
2. direct initialization => T obj{v};
3. copy initialization => T obj = v; (must be avoided for user defined objects
									 ;recommended to use for primitives)
direction initialization:
1. forces initialization
2. you can use direct initialization for array types
3. it prevents narrowing conversions (floating point to integer or integer to floating point)
4. uniform syntax
*/