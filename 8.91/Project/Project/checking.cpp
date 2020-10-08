#include "checking.h"
#include <iostream>

checking::checking(const std::string& name, float balance, float minBalance) : account(name, balance),m_minBalance(minBalance)
{
	std::cout << "checking(const std::string&, float, float)" << std::endl;
}

checking::~checking()
{
	std::cout << "~checking()" << std::endl;
}

float checking::getMinBalance() const
{
	return m_minBalance;
}

void checking::withdraw(float amount)
{
	if (amount <= m_balance - m_minBalance)
		account::withdraw(amount);
	else
		std::cout << "invalid amount" << std::endl;
}
