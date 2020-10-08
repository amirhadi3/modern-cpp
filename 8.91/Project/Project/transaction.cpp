#include "account.h"
#include <iostream>
#include "checking.h"
#include <typeinfo>

void transact(account* pAccount)
{
	std::cout << "transaction started" << std::endl;
	std::cout << "initial balance: " << pAccount->getBalance() << std::endl;
	pAccount->deposit(100);
	pAccount->accumulateInterest();

	//blind downcasting
	//checking* pChecking = static_cast<checking*>(pAccount);
	//std::cout << "minimum balance: " << pChecking->getMinBalance() << std::endl;
	
	/*if (typeid(*pAccount) == typeid(checking)) {
		checking* pChecking = static_cast<checking*>(pAccount);
		std::cout << "minimum balance: " << pChecking->getMinBalance() << std::endl;
	}*/

	checking* pChecking = dynamic_cast<checking*>(pAccount);
	if (pChecking != nullptr) {
		std::cout << "minimum balance: " << pChecking->getMinBalance() << std::endl;
	}

	pAccount->withdraw(170);
	std::cout << "interest rate: " << pAccount->getInterestRate() << std::endl;
	std::cout << "final balance: " << pAccount->getBalance() << std::endl;
	std::cout << std::endl;
}
