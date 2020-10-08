#include "savings.h"

savings::savings(const std::string& name, float balance, float rate): account(name,balance),m_Rate(rate)
{
	std::cout << "savings(const std::string&, float, float)" << std::endl;
}

savings::~savings()
{
	std::cout << "~savings()" << std::endl;
}

float savings::getInterestRate() const
{
	return m_Rate;
}

void savings::accumulateInterest()
{
	m_balance += (m_balance * m_Rate);
}
