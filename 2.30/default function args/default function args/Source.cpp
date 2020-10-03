#include <iostream>

void CreateWindow(const char* title, int x, int y, int width, int height);

void CreateWindow(const char* title, int x = 1, int y = 1, int width = 1, int height = 1)
{
	using namespace std;
	cout << "Title : " << title << endl;
	cout << "x : " << x << endl;
	cout << "y : " << y << endl;
	cout << "width : " << width << endl;
	cout << "height : " << height << endl;
}

int main() {
	CreateWindow("Notepad",10,100,20);
}