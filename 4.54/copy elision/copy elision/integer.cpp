#include "integer.h"
#include <iostream>

integer::integer()
{
	std::cout << "integer()" << std::endl;
	m_pInt = new int(0);
}

integer::integer(const integer& obj)
{
	std::cout << "integer(const integer &)" << std::endl;
	m_pInt = new int(*obj.m_pInt);
}

integer::integer(int value)
{
	std::cout << "integer(int)" << std::endl;
	m_pInt = new int(value);
}

integer::integer(integer&& obj)
{
	std::cout << "integer(integer &&)" << std::endl;
	m_pInt = obj.m_pInt;
	obj.m_pInt = nullptr;
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
	std::cout << "~integer()" << std::endl;
	delete m_pInt;
}
