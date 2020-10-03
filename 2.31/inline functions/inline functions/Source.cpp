#include <iostream>
inline int Square(int x) {
	return x * x;
}
/*#define Square(x) x*x
* macros work through text substitution
x = val+1
x*x = val+1*val+1 = val+val+1 = 11
*/
int main() {
	using namespace std;
	int val = 5;
	int result = Square(val+1);
	cout << result << endl;
	return 0;
}