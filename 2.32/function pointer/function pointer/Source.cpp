#include <iostream>
void print(int count, char ch)
{
	using namespace std;
	for (int i = 0; i < count; ++i)
		cout << ch << endl;
}

void endmsg() {
	using namespace std;
	cout << "End of Program" << endl;
}

int main() {
	atexit(endmsg);
	print(5, '#');
	void (*pfn)(int, char) = &print;
	(*pfn)(8, '@');
	pfn(5, '+');
	using namespace std;
	cout << "end of main" << endl;
	return 0;
}