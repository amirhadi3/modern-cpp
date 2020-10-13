#include <iostream>

template <typename T>
T max(T x, T y)
{
	std::cout << typeid(T).name() << std::endl;
	return x > y ? x : y;
}

template char max(char, char); //explicit instantiation of a function template

//explicit specialization
template<> const char* max<const char*>(const char* x, const char* y) {
	std::cout << "max <const char *>()" << std::endl;
	return strcmp(x, y) > 0 ? x : y;
}

template<int size>
void print1() {
	std::cout << size << std::endl;
}

// not-type template arguments are used in order to pass
// an array into a function.
template<typename T, int size>
void print2(T(&ref)[size]) {
	for (int i = 0; i < size; i++)
		std::cout << ref[i] << std::endl;
}

template<typename T>
T sum1(T* parr, int size) {
	T sum{};
	for (int i = 0; i < size; ++i)
		sum += parr[i];
	return sum;
}

template<typename T, int size>
T sum2(T (&ref)[size]) {
	T sum{};
	for (int i = 0; i < size; ++i)
		sum += ref[i];
	return sum;
}


int main() {
	max(3, 5);
	max(3.2, 5.2);
	max(static_cast<float>(5), 6.2f);
	max<double>(5, 6.8);
	int (*fnPtr)(int, int) = max;

	const char* b{ "B" };
	const char* a{ "A" };

	std::cout << max(a, b) << std::endl;

	print1<3>();

	int arr[]{ 1,2,3 };
	int(&ref)[sizeof(arr) / sizeof(int)]{ arr };
	std::cout << sizeof(ref) << std::endl;

	auto s = sum2 (arr);
	std::cout << s << std::endl;

	std::cout << std::begin(arr) <<std::endl;
	std::cout << std::end(arr) << std::endl;
}