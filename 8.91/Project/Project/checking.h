#pragma once
#include "account.h"
class checking :
    public account
{
    float m_minBalance;
public:
    using account::account;
    checking(const std::string& name, float balance, float minBalance);
    ~checking();
    float getMinBalance() const;
    void withdraw(float amount);
};

