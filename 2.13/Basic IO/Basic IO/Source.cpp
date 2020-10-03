#include <iostream>

int main() {
	using namespace std;
	cout << "enter your name:" << endl;
	char buff[512];
	cin.getline(buff, 64, '\n');
	cout << "your name is:" << buff << endl;
	return 0;
}