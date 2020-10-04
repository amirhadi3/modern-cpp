#include <iostream>
struct point {
	int x;
	int y;
};

void drawLine(int x1, int y1, int x2, int y2) {

}

void drawLine(point start, point end) {
	std::cout << "line from (" << start.x << "," << start.y
		<< ") to (" << end.x << "," << end.y << ")" << std::endl;
}

int main() {
	point s{ 10, 2 };
	point e{ 3,4 };
	drawLine(s, e);
	return 0;
}