#include <iostream>

int main() {
	static_assert(sizeof(void*) == 4, "compile in 32 bit mode only");
	if (sizeof(void*) != 4)
	{
		std::cout << "not 32-bit mode \n";
		return 0;
	}
	else
	{
		//allright
	}
	return 0;
}