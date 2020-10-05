#pragma once
class integer {
	int* m_pInt;
public:
	integer();
	integer(const integer &obj);	// copy constructor: it has to be done in a pass by reference manner; 
									// otherwise, the issue with shallow copy is going to occure
	integer(int value);
	int getValue() const;
	void setValue(int value);
	~integer();
};