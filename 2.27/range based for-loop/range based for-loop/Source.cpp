#include <iostream>
int main() {
	using namespace std;
	int arr[] = { 1,2,3,4,5 };
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	for (int x : arr) {
		cout << x << " ";
	}
	cout << endl;
	// copies the value of the array elements into x
	// changing x does not change the array elements
	for (auto x : arr) {
		x = x - 1;
		cout << x << " ";
	}
	cout << endl;
	// modifies the array
	for (auto& x : arr) {
		x = x - 1;
		cout << x << " ";
	}
	cout << endl;
	// changing x is not allowed
	for (const auto& x : arr)
	{
		//x = x - 1; changing x is not allowed
		cout << x << " ";
	}

	cout << endl;
	int* beg1 = &arr[0]; //arr
	int* end1 = &arr[5];

	while (beg1 != end1)
	{
		cout << *beg1 << ' ';
		++beg1;
	}

	// begin and end functions are added in c++11;
	// in c++11 standard the beg2 and end2 must be of the same type 
	// this is not a requirement in c++17
	cout << endl;
	auto &&range = arr; //forward referencing allows for using r-values and l-values on the right side of the assignment opertor.
	auto beg2 = begin(range);
	auto end2 = end(range);
	for (; beg2 < end2; ++beg2)
	{
		auto v = *beg2;
		cout << v << " ";
	}
	


}