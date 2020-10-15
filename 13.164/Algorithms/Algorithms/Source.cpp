#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

class employee {
	std::string m_name;
	int m_id;
	std::string m_progLang;
public:
	employee(const std::string& n, const int& id, const std::string& pl) :
		m_name(n), m_id(id), m_progLang(pl) {}
	const std::string& getName() const {
		return m_name;
	};
	const int& getId() const {
		return m_id;
	};
	const std::string& getProgLang() const {
		return m_progLang;
	};

	// the less than operator must be overloaded for the class so that 
	// the sort alogorithm works on the vector.
	// when creating a set, the less than operator is also needed
	bool operator<(const employee& e) const {
		return m_id < e.getId();
	}
};

struct empComp {
	bool operator()(const employee& e1, const employee e2) const {
		return e1.getId() > e2.getId();
	}
};

struct empIds {
	std::vector<int> m_ids{};
	void operator()(const employee& e) {
		if (e.getProgLang() == "c++") {
			m_ids.push_back(e.getId());
		}
	}
};

void userDefined() {
	std::vector<employee> v{
		employee{ "umar", 101, "c++" },
		employee{ "bob", 202, "java" },
		employee{ "joey", 200, "c++" }
	};

	//sort
	std::sort(v.begin(), v.end());
	std::cout << std::endl << "sort based on id" << std::endl;
	for (auto x : v)
		std::cout << x.getName() << " : " << x.getId() << "->" << x.getProgLang() << std::endl;

	std::cout << std::endl << "sort based on name" << std::endl;
	std::sort(v.begin(), v.end(), [](const auto& e1, const auto& e2) {return e1.getName() < e2.getName(); });
	for (auto x : v)
		std::cout << x.getName() << " : " << x.getId() << "->" << x.getProgLang() << std::endl;

	std::cout << std::endl << "set constructed by specifying a predicate comparator:" << std::endl;
	std::set < employee, empComp> s{
		employee{ "umar", 101, "c++" },
		employee{ "bob", 202, "java" },
		employee{ "joey", 200, "c++" }
	};
	for (auto x : s)
		std::cout << x.getName() << " : " << x.getId() << "->" << x.getProgLang() << std::endl;

	//count and count_if
	//int cppcount = std::count(v.begin(), v.end(), employee{ "",0,"c++" }); //compiler error because  == is not overloaded for employee
	int cppCount = std::count_if(v.begin(), v.end(), [](const employee& e) {return e.getProgLang() == "c++"; });
	std::cout << std::endl << "number of c++ programmers: " << cppCount << std::endl;


	//find and find_if
	//int findJava = std::find(v.begin(), v.end(), employee{ "",0,"c++" }); //compiler error because  == is not overloaded for employee
	auto findJava = std::find_if(s.begin(), s.end(), [](const employee& e) {return e.getProgLang() == "java"; });
	if (findJava != s.end())
		std::cout << findJava->getName() << " with id: " << findJava->getId() << " is a " << findJava->getProgLang() << " programmer" << std::endl;
	else
		std::cout << "no java programmer" << std::endl;

	//foreach
	std::for_each(s.begin(), s.end(), [](const employee& e) {
		std::cout << e.getName() << std::endl; });

	//for_each returns a copy of the call back
	auto fIds = std::for_each(s.begin(), s.end(), empIds());
	for (auto x : fIds.m_ids)
		std::cout << "id:" << x << std::endl;
}

int main()
{
	userDefined();
	return 0;
}