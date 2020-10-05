#include <iostream>
#include "integer.h"

void print1(const integer& a) {
	std::cout << a.getValue() << std::endl;
}

void print2(const integer & a) {
	std::cout << a.getValue() << std::endl;
}

int main(){
	//initialization
	integer a1{ 5 };	//explicit invoking of the parameterzied constructor
	integer a2 = 5;		//implicit invoking of the parameterized constructor
	print1(5);
	print2(5);
	//assignment
	a1 = 6;				//invokes the parameterized constructor. it then invokes the move assignment constructor
	return 0;
}