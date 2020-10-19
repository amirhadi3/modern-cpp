#include <iostream>
#include <string>
#include <sstream>

template<typename T, int size, typename callback>
void forEach(T(&arr)[size], callback operation) {
	for (int i = 0; i < size - 1; ++i) {
		operation(arr[i]);
	}
}


class product {
	std::string name;
	float price;
public:
	product(const std::string& n, float p) : name(n), price(p) {

	}
	void assignFinalPrice() {
		float taxes[]{ 12,5,5 };
		float basePrice{ price };

		forEach(taxes, [basePrice, this](float tax) {
			price += basePrice * tax / 100;
			});
	}
	float getPrice() const {
		return price;
	}

	auto getDescription() {
		// in c++17 pass by value of the object parameters is an option
		// it creates a copy and prevents the risk of dangling pointers
		return [*this](const std::string& header) {
			std::ostringstream ost;
			ost << header << std::endl;
			ost << "name: " << name << std::endl;	//no need to use this->name
			ost << "price: " << price << std::endl;	// no need to use this->price
			return ost.str();
		};
	}
};

int main() {
	product *p = new product{ "watch",500 };
	p->assignFinalPrice();
	auto desc = p->getDescription();
	delete p;
	std::cout << desc("The header");

	auto f = [](int x, int y) {
		return x + y;
	};	// without using the constexpr on the function definition, it is considered as a constexpr
		// so it can be used in a constexp itself.

	constexpr auto sum = f(3, 4);
	std::cout << sum << std::endl;
}