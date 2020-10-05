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
	if (m_pInt == nullptr)
		m_pInt = new int;
	*m_pInt = value;
}

integer integer::operator+(const integer& obj) const noexcept
{
	integer temp;
	*temp.m_pInt = *m_pInt + *obj.m_pInt;
	return temp; 
}

integer& integer::operator++() noexcept
{
	++(*m_pInt);
	return *this;
	// TODO: insert return statement here
}

integer integer::operator++(int) noexcept
{
	integer temp(*this);
	++* m_pInt;
	return temp;
	// TODO: insert return statement here
}

bool integer::operator==(const integer& obj) const
{
	return (*m_pInt == *obj.m_pInt);
}

integer& integer::operator=(const integer& obj)
{
	if (this != &obj) {
		delete m_pInt;
		m_pInt = new int(*obj.m_pInt);
	}
	return *this;
	// TODO: insert return statement here
}

integer& integer::operator=(integer&& obj)
{
	std::cout << " = (integer &&)" << std::endl;
	if (this != &obj) {
		delete m_pInt;
		m_pInt = obj.m_pInt;
		obj.m_pInt = nullptr;
	}
	return *this;
}

void integer::operator()()
{
	std::cout << *m_pInt << std::endl;
}

integer::operator int()
{
	return *m_pInt;
}

integer::~integer()
{
	std::cout << "~integer()" << std::endl;
	delete m_pInt;
}
