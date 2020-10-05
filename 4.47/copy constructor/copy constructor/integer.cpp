#include "integer.h"
#include <iostream>

integer::integer()
{
	std::cout << "default constructor is called" << std::endl;
	m_pInt = new int(0);
}

integer::integer(const integer& obj)
{
	std::cout << "copy constructor is called" << std::endl;
	m_pInt = new int(*obj.m_pInt);
}

integer::integer(int value)
{
	std::cout << "value constructor is called" << std::endl;
	m_pInt = new int(value);
}

int integer::getValue() const
{
	return *m_pInt;
}

void integer::setValue(int value)
{
	*m_pInt = value;
}

integer::~integer()
{
	delete m_pInt;
}
