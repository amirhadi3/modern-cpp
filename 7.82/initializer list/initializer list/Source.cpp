#include <iostream>
#include <string>
#include <initializer_list>
#include <cassert>

class custObj {
public:
	int m_x{};
	int m_y{};
	custObj() = default;
	custObj(int x, int y) {
		m_x = x;
		m_y = y;
	}
	friend std::ostream& operator << (std::ostream& out, custObj& obj);
};

std::ostream& operator<< (std::ostream& out, custObj& obj) {
	out << obj.m_x << " " << obj.m_y;
	return out;
}

class bag {
	custObj arr[10];
	int m_size{};
public:
	bag() = default;
	bag(std::initializer_list<custObj> list) {
		assert(list.size() < 10);
		auto it = list.begin();
		while (it != list.end()) {
			add(*it);
			++it;
		}
	}

	void add(custObj obj) {
		assert(m_size < 10);
		arr[m_size++] = obj;
	}
	void remove() {
		--m_size;
	}
	custObj & operator[](int index) {
		return arr[index];
	}
	int getSize() {
		return m_size;
	}
};

void print(std::initializer_list<custObj> list) {
	for (auto item : list)
		std::cout << item << std::endl;
}

int main() {
	int x{};
	float y{ 1.2f };
	int arr[4]{ 1,2,3,4 };
	std::cout << x << std::endl;
	std::cout << y << std::endl;
	
	std::string s{};
	std::string si{ "hello" };
	std::string sarr[10]{ "this", "is" , "a", "test","don't","panick","and", "you", "stay","calm" };

	std::cout << s << std::endl;
	std::cout << si << std::endl;
	for (auto ls : sarr)
		std::cout << ls << std::endl ;

	// all below are initializer lists
	std::initializer_list<int> data1 = { 1,2,3,4 };
	std::initializer_list<int> data2{ 1,2,3,4 };
	auto data3 = { 1,2,3,4 };

	// initializer lists are commonly used with container classes
	// container classes are those that hold objects of another class

	bag b;
	b.add(custObj(0, 1));
	b.add(custObj(1, 2));
	b.add(custObj(2, 3));
	b.add(custObj(3, 4));
	std::cout << "b is:" << std::endl;
	for (int i = 0; i < b.getSize(); ++i) {
		std::cout << b[i] << std::endl;
	}

	std::cout << "b2 is:" << std::endl;
	bag b2{ custObj(5,6),custObj(6,7),custObj(7,8) };
	for (int i = 0; i < b2.getSize(); ++i) {
		std::cout << b2[i] << std::endl;
	}

	std::cout << "print an initializer list" << std::endl;
	std::initializer_list<custObj> list = { custObj(8,9),custObj(9,10),custObj(10,11) };
	print(list);

	custObj objarr[10]{custObj(1,2),custObj(2,3),custObj(3,4),custObj(4,5)};
	for (auto item : objarr)
		std::cout << item << std::endl;
	return 0;
}