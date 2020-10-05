#include <iostream>
class integer {
	int m_value{ 0 };
public:
	integer() = default;	// because another constructor is defined, the default constructor is not generated automatically
							// adding the default keyword instructs the compiler to generate it.
	integer(int value) {
		m_value = value;
	}

	integer(const integer&) = delete;	 // instructs the compiler not to generate the copy constructor by default.
	void setValue(int value) {
		m_value = value;
		std::cout << m_value << std::endl;
	}

	void setValue(const float&) = delete;
};

int main() {
	integer a;			// cals the default constructor
	integer b(1);		// call the second constructor
	//integer c(a);		// invalid because the compiler is instructed not to generate the copy constructor
	//a.setValue(6.71f);	// invalid because the compiler is instructed not to generate this function signature.
	a.setValue(10);
	int x = 12;
	++x = 6;
	std::cout << x << std::endl;
	return 0;
}