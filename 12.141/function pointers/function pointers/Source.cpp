#include <iostream>

using comparator = bool(*)(int, int);

template <typename T, int size>
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

bool comp(int x, int y) {
	return x > y;
}

int main() {
	int arr[]{ 1,5,4,7,3,2,9,7,6,8,4 };
	for (auto x : arr) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	sort(arr,comp);
	for (auto x : arr) {
		std::cout << x << " ";
	}
}