#pragma once
#include <string>

class account
{
	std::string m_Name;
	int m_accNo;
	static int s_accNoGenerator;
protected:
	float m_balance;
public:
	account(const std::string & name, float balance);
	virtual ~account();

	const std::string getName() const;
	float getBalance() const;
	int getAccountNo() const;
	virtual float getInterestRate() const;

	virtual void accumulateInterest();
	virtual void withdraw(float amount);
	void deposit(float amount);

};

