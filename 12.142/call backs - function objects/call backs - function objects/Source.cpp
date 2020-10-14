#include <iostream>

//using comparator = bool(*)(int, int);

template <typename T, int size, typename comparator>
void sort(T(&arr)[size], comparator comp) {
	for (int i = 0; i < size - 1; ++i)
		for (int j = 0; j < size - 1; ++j)
			if (comp(arr[j], arr[j + 1]))
			{
				T temp = std::move(arr[j]);
				arr[j] = std::move(arr[j + 1]);
				arr[j + 1] = std::move(temp);
			}
}

bool comp1(int x, int y) {
	return x > y;
}

struct Comp
{
	bool operator()(int x, int y) {
		return x < y;
	}
};

int main() {
	int arr[]{ 1,5,4,7,3,2,9,7,6,8,4 };
	for (auto x : arr) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	//sort ascending with function pointer
	sort(arr, comp1);
	for (auto x : arr) {
		std::cout << x << " ";
	}

	// sort descending with function object => comp2(3,5): comp2.operator()(3,5)
	Comp comp2;
	sort(arr, comp2);
	std::cout << std::endl;
	for (auto x : arr) {
		std::cout << x << " ";
	}
}