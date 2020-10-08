#include <iostream>
#include "account.h"

int account::s_accNoGenerator = 0;

account::account(const std::string& name, float balance):m_Name(name),m_balance(balance)
{
	m_accNo = ++s_accNoGenerator;
	std::cout << "account(const std::string&, float)" << std::endl;
}

account::~account()
{
	std::cout << "~account()" << std::endl;
}

const std::string account::getName() const
{
	return m_Name;
}

float account::getBalance() const
{
	return m_balance;
}

int account::getAccountNo() const
{
	return m_accNo;
}

float account::getInterestRate() const
{
	return 0.0f;
}

void account::accumulateInterest()
{
}

void account::withdraw(float amount)
{
	if (amount < m_balance)
		m_balance -= amount;
	else
		std::cout << "insufficient balance" << std::endl;
}

void account::deposit(float amount)
{
	m_balance += amount;
}
