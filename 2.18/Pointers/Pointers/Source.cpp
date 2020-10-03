#include <iostream>

int main() {
	using namespace std;
	int i = 10;
	char c[8]{ "home" };

	void* ptr;						// a void pointer can point to any type
	ptr = nullptr;
	cout << "void pointer poiting to nullptr: " << ptr << endl;
	cout << "dereference operator cannot be used on a nullptr" << endl << endl;
	
	ptr = &i;
	cout << "void pointer poiting to an integer:" << ptr << endl;
	cout << "void must be cast before dereferencing:" << *(int*)ptr << endl << endl;
	
	ptr = c;
	cout << "void pointer poiting to a char array:" << ptr << endl;
	cout << "void must be cast before dereferencing:" << (char*)ptr << endl << endl;

	ptr = &c;
	cout << "void pointer poiting to a char array:" << ptr << endl;
	cout << "void must be cast before dereferencing:" << (char*)ptr << endl << endl;

	cout << c << endl;
	cout << &c << endl;
	cout << *c << endl;

	int* ptr2;
	//Always try to initialize pointers to nullptr
	int* ptr1 = nullptr;
	//cout << *ptr1 << "\n";
	//*ptr1 = 5;
	return 0;
}