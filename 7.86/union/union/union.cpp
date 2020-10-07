#include <iostream>
#include <string>

union Test {
	int x ;
	char ch ;
	double d ;
	Test(): ch{'a'} {
		std::cout << __FUNCSIG__ << std::endl; 
	}
	~Test() {
		std::cout << __FUNCSIG__ << std::endl; 
	}
};

struct A {
	A() {
		std::cout << __FUNCSIG__ << std::endl;
	}
	~A() {
		std::cout << __FUNCSIG__ << std::endl;
	}

	A(const A& other) {
		std::cout << __FUNCSIG__ << std::endl;
	}

	A(A&& other) noexcept{
		std::cout << __FUNCSIG__ << std::endl;
	}

	A& operator=(const A& other) {
		std::cout << __FUNCSIG__ << std::endl;
		if (this == &other)
			return *this;
		return *this;
	}

	A& operator=(A&& other) noexcept {
		std::cout << __FUNCSIG__ << std::endl;
		if (this == &other)
			return *this;
		return *this;
	}
};

struct B {

	B() {
		std::cout << __FUNCSIG__ << std::endl;

	}
	~B() {
		std::cout << __FUNCSIG__ << std::endl;

	}

	B(const B& other) {
		std::cout << __FUNCSIG__ << std::endl ;
	}

	B(B&& other) noexcept {
		std::cout << __FUNCSIG__ << std::endl ;
	}

	B& operator=(const B& other) {
		std::cout << __FUNCSIG__ << std::endl ;
		if (this == &other)
			return *this;
		return *this;
	}

	B& operator=(B&& other) noexcept {
		std::cout << __FUNCSIG__ << std::endl ;
		if (this == &other)
			return *this;
		return *this;
	}
	virtual void Foo(){}
	
};

union UDT {
	A a ;
	B b ;
	std::string s ;
	UDT() {
		std::cout << __FUNCSIG__ << std::endl;
	}
	~UDT() {
		std::cout << __FUNCSIG__ << std::endl;
	}
};
int main() {
	UDT udt;
	using namespace std::string_literals;

	// errors becuase .s does not exist yet
	// udt.s = "hello world"s;

	new(&udt.s) std::string{ "hello world" }; //placement new is another form of new that only initializes the memory but does not allocated
	std::cout << udt.s << std::endl;

	new(&udt.a) A{};
	udt.a.~A();

}