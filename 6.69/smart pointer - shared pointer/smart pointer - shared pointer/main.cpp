#include <iostream>
#include <memory>

class printer1 {
	std::shared_ptr<int> m_pValue{};
public:
	void setValue(std::shared_ptr<int> p) {
		m_pValue = p;
	}
	void print() {
		std::cout << "ref count: " << m_pValue.use_count() << std::endl;
		std::cout << "Value is: " << *m_pValue << std::endl;
	}
};

class printer2 {
	std::weak_ptr<int> m_pValue{};
public:
	void setValue(std::weak_ptr<int> p) {
		m_pValue = p;
	}
	void print() {
		std::cout << "ref count before locking: " << m_pValue.use_count() << std::endl;
		if (m_pValue.expired()) {
			std::cout << "Resource is no longer available" << std::endl;
			return;
		}
		auto sp = m_pValue.lock();
		std::cout << "ref count after locking: " << m_pValue.use_count() << std::endl;
		std::cout << "Value is: " << *sp << std::endl;
	}
};

int main() {
	printer2 prn;
	int num{};
	std::cin >> num;
	std::shared_ptr<int> p{ new int{num} };
	
	// if another shared pointer points to the same memory location by p
	// then the memory will not be released after one of the pointers is 
	// reset. So the code below would not work.
	// We should make one shared pointer and the others are just weak pointers.
	//std::shared_ptr<int> q{ p };
	prn.setValue(p);
	prn.print();

	if (*p > 10) {
		p = nullptr;
	}
	prn.print();
	return 0;
}