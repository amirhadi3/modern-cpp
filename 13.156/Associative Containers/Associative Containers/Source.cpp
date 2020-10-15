#include <iostream>
#include <set>
#include <functional>
#include <map>
#include <string>

void set() {
	std::set<int, std::greater<int>> s{ 0,-1,2,4,2,3,1,6,9,4,-5,6,8,-10,11 };
	for (auto x : s) {
		std::cout << x << " ";
	}

	std::cout << std::endl;

	auto it1 = s.begin();
	while (it1 != s.end()) {
		std::cout << *it1++ << " ";
	}

	std::cout << std::endl;

	auto it2 = s.end();
	while (it2 != s.begin()) {
		std::cout << *--it2 << " ";
	}
	std::cout << std::endl;

	s.insert(15);
	s.insert(7);
	s.insert(7);
	s.insert(7);					// set does not add duplicate components

	for (auto x : s) {
		std::cout << x << " ";
	}
	std::cout << std::endl;

	s.erase(0);						// erase based on value
	s.erase(s.begin());				// erase based on position
	s.erase(s.find(6));				// erase based on position
	s.erase(--s.end());				// erase based on position

	for (auto x : s) {
		std::cout << x << " ";
	}

	std::cout << std::endl;

	auto it3 = s.find(100);
	if (it3 != s.end())
		std::cout << "element found" << std::endl;
	else
		std::cout << "element not found" << std::endl;
}
void multiset() {
	std::multiset<int, std::greater<int>> s{ 0,-1,2,4,2,3,1,6,9,4,-5,6,8,-10,11 };
	for (auto x : s) {
		std::cout << x << " ";
	}

	std::cout << std::endl;

	auto it1 = s.begin();
	while (it1 != s.end()) {
		std::cout << *it1++ << " ";
	}

	std::cout << std::endl;

	auto it2 = s.end();
	while (it2 != s.begin()) {
		std::cout << *--it2 << " ";
	}
	std::cout << std::endl;

	s.insert(15);
	s.insert(7);
	s.insert(7);
	s.insert(7);					// multiset does not add duplicate components

	for (auto x : s) {
		std::cout << x << " ";
	}
	std::cout << std::endl;

	s.erase(0);						// erase based on value
	s.erase(s.begin());				// erase based on position
	s.erase(s.find(7));				// erase based on position
	s.erase(--s.end());				// erase based on position

	for (auto x : s) {
		std::cout << x << " ";
	}

	std::cout << std::endl;

	auto it3 = s.find(7);			// returns the first element with the search value
	if (it3 != s.end())
		std::cout << "element found" << std::endl;
	else
		std::cout << "element not found" << std::endl;

	auto it4 = s.equal_range(7);			//returns a std::pair<std::multiset::iterator,std::multiset::iterator>
	while (it4.first != it4.second)
		std::cout << *it4.first++ << std::endl;


}
void map() {
	std::map<int, std::string> m{
		{1,"superman"},
		{2,"batman"},
		{3,"green lantern"} };
	m.insert(std::pair<int, std::string>(8, "aquaman"));
	m.insert(std::make_pair(6, "wonder woman"));

	m[0] = "flash";	//because the key "0" does not exist in the map, it inserts the tuple

	auto itr = m.begin();
	while (itr != m.end()) {
		std::cout << itr->first << ":" << itr->second << std::endl;
		itr++;
	}

	m[0] = "kid flash";														// writes the value
	std::cout << std::endl;
	for (const auto &x:m)
		std::cout << x.first << ":" << x.second << std::endl;

	m.insert(std::make_pair(6, "power girl"));								// the value will be discarded because the key already exists.
	std::cout << std::endl;
	for (const auto& x : m)
		std::cout << x.first << ":" << x.second << std::endl;

	m.erase(0);																//erase by key value
	std::cout << std::endl;
	for (const auto& x : m)
		std::cout << x.first << ":" << x.second << std::endl;

	m.erase(--m.end());														//erase by position
	std::cout << std::endl;
	for (const auto& x : m)
		std::cout << x.first << ":" << x.second << std::endl;

	auto sItr = m.find(10);
	if (sItr != m.end())
		std::cout << "element found: key = " << sItr->first << " value = " << sItr->second << std::endl;
	else
		std::cout << "element not found" << std::endl;

	//an alternative find is to use the subscript operator
	std::cout << "the value at key = 2 is: " << m[2] << std::endl;

	//however, if it does not exist, it adds the key to the map
	std::cout << "the value at key = 10 is: " << m[10] << std::endl;
	std::cout << std::endl;
	for (const auto& x : m)
		std::cout << x.first << ":" << x.second << std::endl;

	std::cout << std::endl;
	m.erase(10);
	for (const auto& x : m)
		std::cout << x.first << ":" << x.second << std::endl;
}
void multimap() {
	std::multimap<int, std::string> m{
		{1,"superman"},
		{2,"batman"},
		{3,"green lantern"} };
	m.insert(std::pair<int, std::string>(8, "aquaman"));
	m.insert(std::make_pair(6, "wonder woman"));

	//m[0] = "flash";	// for multimap the subscript operator is not overloaded.

	auto itr = m.begin();
	while (itr != m.end()) {
		std::cout << itr->first << ":" << itr->second << std::endl;
		itr++;
	}

	//m[0] = "kid flash";													// for multimap the subscript operator is not overloaded.
	//std::cout << std::endl;
	//for (const auto& x : m)
	//	std::cout << x.first << ":" << x.second << std::endl;

	m.insert(std::make_pair(6, "power girl"));								// the value will be discarded because the key already exists.
	std::cout << std::endl;
	for (const auto& x : m)
		std::cout << x.first << ":" << x.second << std::endl;

	m.erase(0);																//erase by key value
	std::cout << std::endl;
	for (const auto& x : m)
		std::cout << x.first << ":" << x.second << std::endl;

	m.erase(--m.end());														//erase by position
	std::cout << std::endl;
	for (const auto& x : m)
		std::cout << x.first << ":" << x.second << std::endl;

	auto sItr = m.find(10);
	if (sItr != m.end())
		std::cout << "element found: key = " << sItr->first << " value = " << sItr->second << std::endl;
	else
		std::cout << "element not found" << std::endl;

	////an alternative find is to use the subscript operator				// for multimap the subscript operator is not overloaded.
	//std::cout << "the value at key = 2 is: " << m[2] << std::endl;

	////however, if it does not exist, it adds the key to the map
	//std::cout << "the value at key = 10 is: " << m[10] << std::endl;

	std::cout << std::endl;
	for (const auto& x : m)
		std::cout << x.first << ":" << x.second << std::endl;

	std::cout << std::endl;
	m.erase(10);
	for (const auto& x : m)
		std::cout << x.first << ":" << x.second << std::endl;

	std::cout << std::endl;
	auto pItr = m.equal_range(6);
	while (pItr.first != pItr.second) {
		std::cout << pItr.first->first << ":" << pItr.first->second << std::endl;
		pItr.first++;
	}

}
int main() {
	//set();
	//multiset();
	//map();
	multimap();			
	return 0;
}