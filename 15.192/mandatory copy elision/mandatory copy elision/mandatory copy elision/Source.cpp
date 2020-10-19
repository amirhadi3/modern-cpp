#include <iostream>
#define DELETE_COPY_MOVE

class number {
public:
	number(int num) {
		std::cout << "parameterized ctor \n";
	}
#ifdef DELETE_COPY_MOVE
	number(const number& num) = delete;
	number(number&&) = delete;
#else
	number(const number& num) {
		std::cout << "copy ctor\n";
	}
	number(number&&) {
		std::cout << "move ctor\n";
	}
#endif
};

void foo(number n) {

}

number create() {
	//number n{ 0 };
	//return n;

	return number{0};

}

template<typename T, typename... params>
T create(params&& ... args) {
	return T{ args... };
}

int main() {
	number n1 = number{ 3 };
	foo(number{ 3 });
	number n2 = create();

	auto n3 = create<number>(3);
}