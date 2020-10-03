#include <iostream>
void print(int* ptr)
{
	using namespace std;
	cout << "print-->x: " << *ptr << endl;
	*ptr = 5;
}

void print1(const int* ptr)						// good practice when the function should not modify the input value
{
	using namespace std;
	cout << "print1-->x: " << *ptr << endl;
	//*ptr = 5;									// the value of *ptr cannot be changed inside the function 
												// because of the const qualifier at the function input definition

	int y = 20;									// although ptr points to a new local variable, it has no effect
	ptr = &y;									// this is because ptr is a new local variable itself which its value is the 
												// address of passed input.
}

void print2(int& ref)
{
	using namespace std;
	cout << "print2-->x: " << ref << endl;
	ref = 30;
}

void print3(const int& ref)
{
	using namespace std;
	cout << "print3-->x: " << ref << endl;
	// ref = 30;								// not allowed becuase of the const qualifier
}

int main() {
	using namespace std;

	//the two below are the same; however, it is best practice to put const before the data type
	const int CHUNK_SIZE = 512;
	int const CHUNK_SIZE2 = 512;

	int x = 10;

	// int* ptr = &CHUNK_SIZE;					// not allowed: creating a pointer to a constant --> the pointer itself must be constant

	const int* ptr = &CHUNK_SIZE;				// this indicates that the address that ptr is pointing to itslef is not constant but 
												// the value is constant

	//*ptr = 512;								// this line creates an error because the value that ptr is pointing to is constant
	ptr = &x;									// the pointer can point to another variable
	//*ptr = 5;									// even though the pointer points to another variable, the dereference operator cannot
												// be used to modify its value because in the declaration, it was specified that the value
												// that the pointer is poiting to is constant.
	//*****************************

	const int* const ptr1 = &CHUNK_SIZE;
	//ptr1 = &x;								// not allowed anymore because the address of the pointer is also specified to be constant

	print(&x);
	print1(&x);
	cout << "main-->x: " << x << endl;



	//******************************
	//int& = 5;									// this is not allowed because a reference type is always bound to an l-value
	const int& ref = 5;							// the const qualifers allows to have an r-value assigned to a reference type because it is guaranteed that
												// no one can modify the value in the reference. consequently it does not need an address
	
	//int& ref2 = *ptr;							// not allowed, same as above
	const int& ref3 = *ptr;						
	cout << &ref << endl;

	print2(x);
	print3(x);
	cout << "main-->x: " << x << endl;

	//print2(3);								// not allowed because an r-value cannot be assigned to a reference type
	print3(3);									// allowed because and r-value can be assigned to a const reference type as mentioned above.

	return 0;
}