#include <iostream>
#include <vector>

template<typename T>
class prettyPrinter {
	T* m_pData;
public:
	prettyPrinter(T* Data) : m_pData(Data) {}
	void print() {
		std::cout << "{" << *m_pData << "}" << std::endl;
	}
	T* getData(){
		return m_pData;
	}
};

template<>
class prettyPrinter<const char*> {
	const char* m_pData;
public:
	prettyPrinter(const char* Data) : m_pData(Data) {}
	void print() {
		std::cout << "{" << m_pData << "}" << std::endl;
	}
	const char* getData() {
		return m_pData;
	}
};

template<>
void prettyPrinter<std::vector<int>>::print() {
	std::cout << "{";
	int size = m_pData->size();
	int counter = 1;
	for (auto x : *m_pData)
	{
		std::cout << x;
		if (counter++ != size)
			std::cout << ",";
	}
	std::cout << "}";
}

template<>
void prettyPrinter<std::vector<std::vector<int>>>::print() {
	std::cout << "{\n";
	int size = m_pData->size();
	int counter = 1;
	for (auto x : *m_pData)
	{
		prettyPrinter<std::vector<int>> ip{ &x };
		ip.print();
		if (counter++ != size)
			std::cout << ",\n";
	}
	std::cout << "\n}";
}

int main() {
	int i = 5;
	float f = 8.2f;
	prettyPrinter<int> p1(&i);
	p1.print();
	prettyPrinter<float> p2(&f);
	p2.print();

	const char* p3{ "hello world" };
	prettyPrinter<const char *> p4(p3);
	p4.print();

	const char* pData = p4.getData();
	std::cout << pData << std::endl;

	std::vector<int> v{ 1,2,3,4,5 };
	prettyPrinter<std::vector<int>> p5(&v);
	p5.print();
	std::cout << std::endl;
	std::vector<std::vector<int>> v2{ {1,2,3},{4,5,6,7,8,9} };
	prettyPrinter<std::vector<std::vector<int>>> p6(&v2);
	p6.print();

	return 0;
}