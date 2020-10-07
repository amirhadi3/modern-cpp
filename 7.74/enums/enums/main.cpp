#include <iostream>

//#define RED 0
//const int GREEN = 1;
//
//void fillcolor(int color) {
//	//  fill color background with some color
//	if (color == 0) {
//		std::cout << "RED" << std::endl;
//	}
//	else if (color == 1) {
//		std::cout << "GREEN" << std::endl;
//	}
//	else if (color == 2) {
//		std::cout << "BLUE" << std::endl;
//	}
//}

enum color{RED = 10,GREEN,BLUE};
void fillcolor(color c) {
	if (c == RED) {
		std::cout << "RED" << std::endl;
	}
	else if (c == GREEN) {
		std::cout << "GREEN" << std::endl;
	}
	else if (c == BLUE) {
		std::cout << "BLUE" << std::endl;
	}
}

enum class scopedColor: char {RED = 'e',GREEN,BLUE};
void fillcolor(scopedColor c) {
	if (c == scopedColor::RED) {
		std::cout << "RED" << std::endl;
	}
	else if (c == scopedColor::GREEN) {
		std::cout << "GREEN" << std::endl;
	}
	else if (c == scopedColor::BLUE) {
		std::cout << "BLUE" << std::endl;
	}
}

int main() {
	color c{ RED };
	fillcolor(c);
	fillcolor(GREEN);
	fillcolor(static_cast<color>(12));
	fillcolor(scopedColor::GREEN);
	return 0;
}