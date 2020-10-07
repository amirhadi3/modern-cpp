#include <iostream>
#include <vector>

void print(std::vector<int> vec) {
	for (auto x : vec)
		std::cout << x << " ";
	std::cout << std::endl;
}
int main() {
	std::vector<int> data{ 1,2,3 };

	// add data to the end of the vector
	for (int i = 0; i < 5; ++i)
		data.push_back(i * 10);

	// access
	data[0] = 100;
	print(data);

	auto it = data.begin();
	std::cout << *it << std::endl;

	*it++ = 2000;
	print(data);

	*--it = 3000;
	print(data);

	*(it += 5) = 4000;
	print(data);

	// delete
	data.erase(it);
	print(data);

	// insert
	it = data.begin();
	data.insert(it+5, 6);
	print(data);
	return 0;
}