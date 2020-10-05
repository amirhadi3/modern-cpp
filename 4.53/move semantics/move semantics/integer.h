#pragma once
class integer {

public:
	int* m_pInt;
	integer();
	integer(const integer& obj);	// copy constructor: it has to be done in a pass by reference manner; 
									// otherwise, the issue with shallow copy is going to occure
	integer(int value);
	integer(integer&& obj);
	int getValue() const;
	void setValue(int value);
	~integer();
};