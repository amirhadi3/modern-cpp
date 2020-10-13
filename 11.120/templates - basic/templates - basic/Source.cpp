#include <iostream>

template < typename T>
T max(T a, T b) {
	return a > b ? a : b;
}

//Return the sum of two elements
template<typename T>
T Add(T x, T y) {
	return x + y;
}

//Returns the sum of array elements
template<typename T>
T ArraySum(T* pArr, int arrSize) {
	T sum{ 0 };
	for (int i = 0; i< arrSize; i++)
		sum += pArr[i];
	return sum;
}

template <typename T>
//Return the largest element in the array
T Max(T* pArr, int arrSize) {
	T l{ pArr[0] };
	for (int i = 1; i < arrSize; i++)
		l = pArr[i] > l ? pArr[i] : l;
	return l;
}

//Return the smallest and largest element in a pair
template <typename T>
std::pair<T, T> MinMax(T* pArr, int arrSize) {
	std::pair<T, T> p;
	p.second = Max(pArr, arrSize);
	T s{ pArr[0] };
	for (int i = 1; i < arrSize; i++)
		s = pArr[i] < s ? pArr[i] : s;
	p.first = s;
	return p;
}


int main() {
	float f[6]{ 1.2,3.4,5,9.8,5.2,4.3 };
	std::cout << Add(f[0], f[1]) << std::endl;
	std::cout << ArraySum(f, 6) << std::endl;
	std::cout << Max(f, 6) << std::endl;
	auto mm = MinMax(f, 6);
	std::cout << "(" << mm.first << "," << mm.second << ")" << std::endl;

	std::cout << max(3, 5) << std::endl;
	std::cout << max(3.3f, 3.8f) << std::endl;
	return 0;
}