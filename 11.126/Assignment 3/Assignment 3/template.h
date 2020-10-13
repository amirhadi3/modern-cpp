#pragma once
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
template<typename T, int size>
T ArraySum(T(&pArr)[size]) {
	T sum{ 0 };
	for (int i = 0; i < size; i++)
		sum += pArr[i];
	return sum;
}

template <typename T, int size>
//Return the largest element in the array
T Max(T(&pArr)[size]) {
	T l{ pArr[0] };
	for (int i = 1; i < size; i++)
		l = pArr[i] > l ? pArr[i] : l;
	return l;
}

//Return the smallest and largest element in a pair
template <typename T, int size>
std::pair<T, T> MinMax(T(&pArr)[size]) {
	std::pair<T, T> p;
	p.second = Max(pArr);
	T s{ pArr[0] };
	for (int i = 1; i < size; i++)
		s = pArr[i] < s ? pArr[i] : s;
	p.first = s;
	return p;
}

// Explicit Specialization for an array of const char*
template<> const char* Max <const char*, 5>(const char* (&arr)[5]);

// Explicit Specialization for an array of std::strings.
template<> std::string Max <std::string, 5>(std::string(&arr)[5]);