#include <iostream>

class animal {
public:
	void eat() {
		std::cout << "animal eating" << std::endl;
	}
	void run() {
		std::cout << "animal running" << std::endl;
	}

	void speak(){
		std::cout << "animal speaking" << std::endl;
	}
};

class dog : public animal {
public:
	void eat() {
		std::cout << "dog eating meat" << std::endl;
	}
	void speak() {
		std::cout << "dog barking" << std::endl;
	}
};
int main() {
	dog d;
	d.eat();
	d.run();
	d.speak();
	return 0;
}