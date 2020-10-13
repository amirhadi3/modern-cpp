#include <iostream>

template<typename T, int size>
class stack {
	T m_buffer[size];
	int m_top{ -1 };
public:
	stack() = default;
	stack(const stack& obj) {
		m_top = obj.m_top;
		for (int i = 0; i <= m_top; ++i) {
			m_buffer[i] = obj.m_buffer[i];
		}
	}
	void push(const T& elem) {
		m_buffer[++m_top] = elem;
	}
	void pop();
	const T& top() const {
		return m_buffer[m_top];
	}
	bool isEmty() const {
		return m_top == -1;
	}

	// stack with no template parameters can be used inside the class
	// it is called short hand notation; you do not need to specify template parameters
	// you can use it only if that type occurs inside the class definition.
	// you can also use the long hand notation but that is not required.
	//static stack create() {
	//	return stack(); // it could be stack <T,size>
	//}

	static stack create();
};

// external definition of a member function in class templates
// The template parameters are parts of the type of the class
template<typename T, int size>
void stack<T, size>::pop() {
	--m_top;
}

// external definition of the factory member function
template<typename T, int size>
stack<T, size> stack<T, size>::create() {
	return stack<T,size>();
}

int main() {
	stack<int, 10> s;
	s.push(3);
	s.push(1);
	s.push(6);
	s.push(9);

	stack<int, 10> s1 = stack<int, 10>::create();

	auto s2 = s;

	std::cout << typeid(s2).name() << std::endl;
	while (!s2.isEmty()) {
		std::cout << s2.top() << " ";
		s2.pop();
	}
	return 0;
}