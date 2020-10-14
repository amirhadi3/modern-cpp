#include <iostream>
#include <vector>
#include <utility>

template<typename T>
struct Max {
public:
	T operator()(T a, T b) {
		return a > b ? a : b;
	}
};

template<typename T>
struct Greater {
public:
	bool operator()(T a, T b) {
		return a > b;
	}
};

template<typename T>
struct Less {
public:
	bool operator()(T a, T b) {
		return a < b;
	}
};

template<typename T>
struct MinMax {
public:
	auto operator()(T IterBegin, T IterEnd) {
		auto minvar = *IterBegin;
		auto maxvar = *IterBegin;
		for (; IterBegin < IterEnd; ++IterBegin) {
			if (*IterBegin < minvar)
				minvar = *IterBegin;
			if (*IterBegin > maxvar)
				maxvar = *IterBegin;
		}
		return std::make_pair(minvar, maxvar);
	}
};


int main() {
	//T Max(T, T); //Return largest element
	auto lMax = [](auto a, auto b) {
		return a > b ? a : b;
	};

	// bool Greater(T, T); //Return true if first argument is greater than the second
	auto lGreater = [](auto a, auto b) {
		return a > b;
	};

	//bool Less(T, T); //Return true if first argument is less than the second
	auto lLess = [](auto a, auto b) {
		return a < b;
	};

	//pair<T, T> MinMax(ItrBegin, ItrEnd);//Accept iterators of any container and return the largest and smallest element from that container.
	auto lMinMax = [](auto IterBegin, auto IterEnd) {
		auto minvar = *IterBegin;
		auto maxvar = *IterBegin;
		for (; IterBegin < IterEnd; ++IterBegin) {
			if (*IterBegin < minvar)
				minvar = *IterBegin;
			if (*IterBegin > maxvar)
				maxvar = *IterBegin;
		}
		return std::make_pair(minvar, maxvar);
	};

	Max<int> mx{};
	std::cout << "func obj:   " << mx(1, 2) << std::endl;
	std::cout << "lambda exp: " << lMax(1, 2) << std::endl;

	Greater<int> gt{};
	std::cout << "func obj:   " << std::boolalpha << gt(1, 2) << std::endl;
	std::cout << "lambda exp: " << std::boolalpha << lGreater(1, 2) << std::endl;

	Less<int> ls{};
	std::cout << "func obj:   " << std::boolalpha << ls(1, 2) << std::endl;
	std::cout << "lambda exp: " << std::boolalpha << lLess(1, 2) << std::endl;

	MinMax<std::vector<int>::iterator> mm{};
	std::vector<int> a{ 1,7,5,3,4,8,5,6,9,-1 };

	auto q = mm(a.begin(),a.end());
	std::cout << "func obj: (" << q.first << "," << q.second << ")" << std::endl;

	auto p = lMinMax(a.begin(), a.end());
	std::cout << "lambda exp: (" << p.first << "," << p.second << ")" << std::endl;
	
	return 0;
}