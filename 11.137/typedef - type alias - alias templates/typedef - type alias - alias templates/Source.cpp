#include <iostream>
#include <vector>
#include <list>

// typedef 
// typedefenitions cannot be templatized
typedef unsigned int UINT1;
typedef const char* (*PFN1)(int);	// a function pointer that accepts an int as input and returns a const char *

class Employee {
	std::string m_name;
	UINT1 m_id;
public:
	Employee(std::string name, int id) :m_name(name), m_id(id) {}
};

const char* getErrorMessage(int errorNum) {
	return "Empty";
}

typedef std::vector<std::list<Employee>> Teams1;

void showError1(PFN1 pfn) {
	std::cout << pfn(3) << std::endl;
}


// typealias
using UINT2 = unsigned int;
using PFN2 = const char* (*)(int);

template<typename T>
using Teams2 = std::vector<std::list<T>>;

void showError2(PFN2 pfn) {
	std::cout << pfn(3) << std::endl;
}

int main() {

	// using typedef
	UINT1 a = 4;
	Teams1 testTeam;
	Teams1::iterator i1 = testTeam.begin();
	std::cout << a << std::endl;
	PFN1 pfn1 = getErrorMessage;
	showError1(pfn1);

	// using typealias
	UINT2 b = 4;
	std::cout << b << std::endl;
	Teams2<std::string> testTeamNames;
	Teams2<UINT2> testTeamID;
	Teams2<UINT2>::iterator i2 = testTeamID.begin();
	auto i3 = testTeamNames.begin();
	PFN2 pfn2 = getErrorMessage;
	showError2(pfn2);
	return 0;
}