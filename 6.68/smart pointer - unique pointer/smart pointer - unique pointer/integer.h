#include <iostream>

#pragma once
class integer {
	int* m_pInt;
public:
	integer();
	integer(const integer& obj);	// deep copy constructor: it has to be done in a pass by reference manner; 
									// otherwise, the issue with shallow copy is going to occure
	integer(int value);
	integer(integer&& obj);

	int getValue() const;
	void setValue(int value);

	integer operator +(const integer& obj) const noexcept;
	integer& operator ++ () noexcept;		//preincrement operator
	integer operator ++ (int) noexcept;	//post increment operator
	bool operator == (const integer& obj) const;
	integer& operator = (const integer& obj);
	integer& operator = (integer&& obj);
	void operator()();
	operator int();

	friend std::istream & operator >> (std::istream& in, integer& obj);
	friend class printer;

	~integer();
};

class printer {
public:
	void print(const integer& obj) const {
		std::cout << *obj.m_pInt << std::endl;
	}
};