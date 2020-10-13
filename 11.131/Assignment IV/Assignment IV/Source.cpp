#include <iostream>
#include <string>

class employee {
public:
	std::string m_name;
	int m_id;
	int m_salary;
	employee(const std::string &name, const int &id, const int &salary) :
		m_name(name),
		m_id(id),
		m_salary(salary) {
		std::cout << "employee(const std::string&, const int &, const double &)" << std::endl;
	}
	~employee() {
		std::cout << "~employee()" << std::endl;
	}
};

class contact {
public:
	std::string m_name;
	int m_phoneNumber;
	std::string m_address;
	std::string m_eMail;
	contact(const std::string& name, const int& phoneNumber, const std::string& address, const std::string& eMail) :
		m_name(name),
		m_phoneNumber(phoneNumber),
		m_address(address),
		m_eMail(eMail) {
		std::cout << "contact(const std::string&, const int&, const std::string&, const std::string&)" << std::endl;
	}
	~contact() {
		std::cout << "~contact()" << std::endl;
	}
};

template<typename T, typename...params>
T* createObject(params...args)
{
	return new T{ args... };
}

int main() {
	int* pInt = createObject<int>(5);
	std::cout << *pInt << std::endl;

	std::string* pStr = createObject<std::string>("test");
	std::cout << *pStr << std::endl;

	contact* pContact = createObject<contact>(
		"Joey",                //Name
		987654321,             //Phone number
		"Boulevard Road, Sgr", //Address
		"joey@poash.com");

	std::cout << std::endl << "contact info:" << std::endl;
	std::cout << pContact->m_name << std::endl;
	std::cout << pContact->m_phoneNumber << std::endl;
	std::cout << pContact->m_address << std::endl;
	std::cout << pContact->m_eMail << std::endl;

	std::cout << std::endl;
	employee* pEmp = createObject<employee>(
		"Bob",    //Name
		101,      //Id
		1000);   //Salary
	std::cout << std::endl << "employee info:" << std::endl;
	std::cout << pEmp->m_name << std::endl;
	std::cout << pEmp->m_id << std::endl;
	std::cout << pEmp->m_salary << std::endl;

	delete pInt;
	delete pStr;
	delete pContact;
	delete pEmp;
	return 0;
}