#include <iostream>
#include "integer.h"
class product {
	integer p_id;
	int x;
public:
	product(const integer & id) :p_id(id), x(id.getValue()) {
		std::cout << "product(const integer &)" << std::endl;
	}

	~product() {
		std::cout << "~product()" << std::endl;
	}
};
int main() {
	// initialization
	integer a(5);

	// assignment
	a = 7;

	product p(a);
	return 0;
}