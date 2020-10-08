#include <iostream>
#include "account.h"
#include "savings.h"
#include "checking.h"
#include "transaction.h"
#include <typeinfo>

int main() {
	/*checking acc("Bob", 100);
	transact(&acc);

	savings	acc1("James", 100, 0.05f);
	transact(&acc1);*/

	/*account* acc = new savings("Bob", 100, 0.05f);
	delete acc;*/

	checking ch("Bob", 100, 50.0f);
	account* pAccount = &ch;								//upcasting works only for pointers and references
	//checking* pChecking = static_cast<checking*>(pAccount);	//downcasting a base class pointer to a child class pointer
	transact(&ch);

	savings sv("Bob", 100, 0.05f);
	transact(&sv);

	int i{};
	float f{};
	std::string s{};

	const std::type_info & ti = typeid(i);
	const std::type_info& tf = typeid(f);
	const std::type_info& ts = typeid(s);
	const std::type_info& tc = typeid(ch);
	const std::type_info& tpa = typeid(pAccount);
	const std::type_info& tpav = typeid(*pAccount);

	std::cout << "i is a " << ti.name() << std::endl;
	std::cout << "f is a " << tf.name() << std::endl;
	std::cout << "s is a " << ts.name() << std::endl;
	std::cout << "ch is a " << tc.name() << std::endl;
	std::cout << "pAccount is a " << tpa.name() << std::endl;
	std::cout << "*pAccount is a " << tpav.name() << std::endl;
	return 0;
}