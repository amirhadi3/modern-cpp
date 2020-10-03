#include <iostream>

int main() {
	using namespace std;
	int x = 5;
	int y = 10;
	const int MAX = 12;
	int& ref_x1 = x;
	const int& ref_x2 = x;	

	ref_x1 = y;
	//ref_x2 = y;					// invalid because ref_x2 is a reference to a constant integer

	const int* ptr1 = &x;
	int* const ptr2 = &x;
	const int* const ptr3 = &x;

	ptr1 = &y;					// valid becuase the pointer is not constant but the pointee
	///ptr2 = &y;				// invalid because the pointer itself is constant
	//ptr3 = &y;				// invalid because the pointer and the pointee are constant

	//*ptr1 = y;				// invalid becuase the pointee is constant (value)
	*ptr2 = y;					// valid because the pointee itself is not constant but the pointer
	//*ptr3 = y;				// invalid because the pointer and the pointee are constant

	const int* ptr4 = &MAX;
	//int* ptr5 = &MAX;			// invalid because the value of the pointer can be modified which in turn changes the value of MAX which is constant			

	const int& r1 = ref_x1;		
	//int& r2 = ref_x2;			//invaid because r2 can reference to a different variable which correspondigly changes ref_X2 which is declared constant

	//int*& p_ref1 = ptr1;
	/* must be changed to below because p_ref1 is a reference type that is bout to a pinter which has a constant pointee*/ 
	const int*& p_ref1 = ptr1;
	
	//const int*& p_ref2 = ptr2;
	/*must be changed to below because p_ref2 is a pointer to a constant reference that is bound to ptr2*/
	int* const& p_ref2 = ptr2;

	const int& tex = 1;
	cout << &tex << endl;
}