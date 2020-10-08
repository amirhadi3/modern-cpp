#pragma once
#include "account.h"
#include <iostream>

class savings :
    public account
{
    float m_Rate;
public:
    savings(const std::string & name, float balance, float rate);
    ~savings();

    float getInterestRate() const;

    void accumulateInterest();
};

