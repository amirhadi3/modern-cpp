#include <iostream>
void newArrays() {
	int size = 4;
	int* p = new int[size];
	for (int i = 0; i < size; i++)
		p[i] = i;
	delete[] p;
	p = nullptr;
}

void strings() {
	char* c = new char[4];
	strcpy_s(c, 4, "c++");
	std::cout << c << std::endl;
	delete[] c;
	c = nullptr;
}

void twoD() {
	int* p1 = new int[3];
	int* p2 = new int[3];

	int** pData = new int* [2];
	pData[0] = p1;
	pData[1] = p2;

	pData[0][1] = 2;
	// the delete order must be in the order that memory was allocated.
	delete[] p1; //delete []pData[0];
	delete[] p2;// delete []pData[1];
	delete[] pData;
}
int main() {
	twoD();
	return 0;
}