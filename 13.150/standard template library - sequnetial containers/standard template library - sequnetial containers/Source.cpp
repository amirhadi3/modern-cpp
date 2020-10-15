#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>

void array() {
	std::array<int, 5> arr{ 1,2,3 };				// std::array is static and its size cannot change at runtime
	for (int i = 0; i < arr.size(); ++i)
		arr[i] = i;

	for (auto x : arr)							// range based for loop
		std::cout << x << " ";

	auto it = arr.begin();						// begin iterator. end iterator is arr.end()
	std::cout << std::endl;
	std::cout << arr.data() << std::endl;		// arr.data() returns a pointer to the begining of the array - can be used as input to c functions
	std::cout << arr.max_size() << std::endl;
	std::cout << arr.back() << std::endl;		// Reference to the last element.
	arr.fill(0);								// Assigns the given value value to all elements in the container.
	for (auto x : arr)							// range based for loop
		std::cout << x << " ";
}
void vector() {
	std::vector<int> coll;
	for (int i = 0; i < 10; ++i)
		coll.push_back(i);

	std::cout << coll.size() << std::endl;
	std::cout << coll[5] << std::endl;
	auto it = coll.begin();

	while (it != coll.end())
		std::cout << *it++ << " ";

	std::cout << std::endl;

	coll.insert(coll.begin() + 5, { 10,20,30,40 });

	for (auto x : coll)
		std::cout << x << " ";

	std::cout << std::endl;

	coll.erase(coll.end() - 6);
	for (auto x : coll)
		std::cout << x << " ";

	std::cout << std::endl;

	// coll.erase(coll.end()); not allowed because call.end() points to the position one beyond the last element and it is not dereferenc eable

	coll.pop_back();
	for (auto x : coll)
		std::cout << x << " ";

	std::cout << std::endl;
}
void deque() {
	std::deque<int> coll;
	for (int i = 0; i < 5; ++i)
		coll.push_back(i);

	std::cout << coll.size() << std::endl;
	std::cout << coll[2] << std::endl;

	for (int i = 0; i < 5; ++i)
		coll.push_front(i);

	std::cout << coll.size() << std::endl;
	std::cout << coll[5] << std::endl;

	auto it = coll.begin();

	while (it != coll.end())
		std::cout << *it++ << " ";

	std::cout << std::endl;

	coll.insert(coll.begin() + 5, { 10,20,30,40 });

	for (auto x : coll)
		std::cout << x << " ";

	std::cout << std::endl;

	coll.erase(coll.end() - 6);
	for (auto x : coll)
		std::cout << x << " ";

	std::cout << std::endl;

	// coll.erase(coll.end()); not allowed because call.end() points to the position one beyond the last element and it is not dereferenc eable

	coll.pop_back();
	for (auto x : coll)
		std::cout << x << " ";

	std::cout << std::endl;

	coll.pop_front();
	for (auto x : coll)
		std::cout << x << " ";

	std::cout << std::endl;
}
void list() {
	std::list<int> lis;
	for (int i = 0; i < 5; ++i)
		lis.push_back(i);

	for (auto x : lis)
		std::cout << x << " ";
	std::cout << std::endl;

	for (int i = 0; i < 5; ++i)
		lis.push_front(i * 10);

	for (auto x : lis)
		std::cout << x << " ";
	std::cout << std::endl;

	lis.pop_back();
	lis.pop_front();

	auto it = lis.begin();
	while (it != lis.end())
		std::cout << *it++ << " ";
	std::cout << std::endl;

	lis.insert(--it, 100);
	for (auto x : lis)
		std::cout << x << " ";
	std::cout << std::endl;

	lis.erase(++lis.begin());
	for (auto x : lis)
		std::cout << x << " ";
	std::cout << std::endl;
}
void forward_list() {
	std::forward_list<int> flis;
	for (int i = 0; i < 10; ++i)
		flis.push_front(i * 10);

	auto it = flis.begin();
	
	while (it != flis.end())
		std::cout << *it++ << " ";
	std::cout << std::endl;

	for (auto x : flis)
		std::cout << x << " ";
	std::cout << std::endl;

	flis.insert_after(flis.begin(), 1000);
	for (auto x : flis)
		std::cout << x << " ";
	std::cout << std::endl;

	//flis.insert_after(flis.end(), 2000);
	//for (auto x : flis)
	//	std::cout << x << " ";
	//std::cout << std::endl;

	flis.erase_after(flis.begin());
	for (auto x : flis)
		std::cout << x << " ";
	std::cout << std::endl;

	//flis.erase_after(flis.end());
	//for (auto x : flis)
	//	std::cout << x << " ";
	//std::cout << std::endl;

}
int main() {
	//array();
	//vector();
	//deque();
	//list();
	forward_list();
	return 0;
}