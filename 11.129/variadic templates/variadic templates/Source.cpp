#include <iostream>
#include "Integer.h"

template<typename T>
void print(std::initializer_list<T> args) {
	for (auto x : args)
		std::cout << x << " ";
}

void print() {
	std::cout << std::endl;
}

//// template parameter pack
//template<typename T, typename... Params>
//// function pa rameter pack
//void print(T a, Params... args) {
//	std::cout << a << " ";
//	print(args...);
//}


template<typename T, typename... params>
void print(T &&a, params&&...args) {
	//std::cout << "number of template parameters: " << sizeof...(params) << std:: endl;
	//std::cout << "number of function arguments:  " << sizeof...(args) << std::endl;
	std::cout << a;
	if (sizeof...(args) != 0)
		std::cout << ",";
	print(std::forward<params>(args)...);
}

int main() {
	print({ 1,2,3,4,5 });
	std::cout << std::endl;
	print(1, 2, 3.5f, "a");
	Integer v{ 1 };
	print(1, "a", v, Integer{ 2 });
	return 0;
}

/*
1. print(1,2,3.5f,"a")
2. print(2,3.5f,"a")
3. print(3.5f,"a")
4. print("a")
5. print()
*/