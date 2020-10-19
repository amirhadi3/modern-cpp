#include<iostream>

[[deprecated("the function createIntArray is deprecated")]]
int* createIntArray(size_t size) {
	return new int[size];
}

template<typename T>
[[nodiscard]]
T* createArray(size_t size) {
	return new T[size];
}

class [[deprecated("this class is replaced by newTest class")]] test {

};

namespace [[deprecated("do not use")]] A {

}

class [[nodiscard]]  number  {

};

number createNum() {
	return number{};
}

int main() {
	//createIntArray(2);
	//test t;
	//using namespace A;
	//auto p = createArray<int>(3);
	createNum();
	return 0;
}