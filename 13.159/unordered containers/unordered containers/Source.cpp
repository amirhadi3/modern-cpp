#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>

void unSet() {
	std::unordered_set<std::string> us;
	us.insert("hulk");
	us.insert("batman");
	us.insert("green lantern");
	us.insert("the flash");
	us.insert("wonder woman");
	us.insert("iron man");
	us.insert("wolverine");

	for (const auto& x : us)
		std::cout << "Bucket #:" << us.bucket(x) << " contains : " << x << std::endl;

	std::cout << std::endl;
	std::cout << "bucket counts: " << us.bucket_count() << std::endl;
	std::cout << "number of elements: " << us.size() << std::endl;
	std::cout << "load factor: " << us.load_factor() << std::endl;

	us.insert("dr. strange");

	for (const auto& x : us)
		std::cout << "Bucket #:" << us.bucket(x) << " contains : " << x << std::endl;

	std::cout << std::endl;
	std::cout << "bucket counts: " << us.bucket_count() << std::endl;
	std::cout << "number of elements: " << us.size() << std::endl;
	std::cout << "load factor: " << us.load_factor() << std::endl;

	us.insert("hawkman");
	for (const auto& x : us)
		std::cout << "Bucket #:" << us.bucket(x) << " contains : " << x << std::endl;
	std::cout << std::endl;
	std::cout << "bucket counts: " << us.bucket_count() << std::endl;
	std::cout << "number of elements: " << us.size() << std::endl;
	std::cout << "load factor: " << us.load_factor() << std::endl;
}
void unmSet() {
	std::unordered_multiset<std::string> ums;
	ums.insert("hulk");
	ums.insert("batman");
	ums.insert("green lantern");
	ums.insert("the flash");
	ums.insert("wonder woman");
	ums.insert("iron man");
	ums.insert("iron man");
	ums.insert("iron man");
	ums.insert("iron man");
	ums.insert("wolverine");
	ums.insert("dr. strange");
	ums.insert("hawkman");

	for (const auto& x : ums)
		std::cout << "Bucket #:" << ums.bucket(x) << " contains : " << x << std::endl;

	std::cout << std::endl;
	std::cout << "bucket counts: " << ums.bucket_count() << std::endl;
	std::cout << "number of elements: " << ums.size() << std::endl;
	std::cout << "load factor: " << ums.load_factor() << std::endl;
}
void unMap() {
	std::unordered_map<std::string, std::string> unm;
	unm.insert(std::make_pair("Batman", "Brue Wayne"));
	unm["Superman"] = "Clark Kent";
	unm.insert(std::pair<std::string, std::string>("Hulk", "Bruce Banner"));

	auto itr = unm.begin();
	while (itr != unm.end()) {
		std::cout << "Bucket #:" << unm.bucket(itr->first) << " -> " << itr->first << " : " << itr->second << std::endl;
		++itr;
	}
}
void unmMap() {
	std::unordered_multimap<std::string, std::string> unmm;
	unmm.insert(std::make_pair("Batman", "Brue Wayne"));
	unmm.insert(std::make_pair("Superman", "Clark Kent"));
	unmm.insert(std::make_pair("Superman", "Matches Malone"));
	unmm.insert(std::make_pair("Superman", "Clark Kent"));
	unmm.insert(std::make_pair("Superman", "Clark Kent"));
	unmm.insert(std::pair<std::string, std::string>("Hulk", "Bruce Banner"));

	auto itr = unmm.begin();
	while (itr != unmm.end()) {
		std::cout << "Bucket #:" << unmm.bucket(itr->first) << " -> " << itr->first << " : " << itr->second << std::endl;
		++itr;
	}
}
class employee {
	std::string m_Name;
	int m_id;
public:
	employee(std::string name, int id): m_Name(name),m_id(id){}
	const std::string & getName() const {
		return m_Name;
	}
	int getId() const {
		return m_id;
	}
};
struct empHashfobj {
	size_t operator()(const employee& emp) const {
		auto s1 = std::hash<std::string>{}(emp.getName());
		auto s2 = std::hash<int>{}(emp.getId());
		return s1 ^ s2;
	}
};
struct empEqualityfobj {
	bool operator() (const employee& e1, const employee& e2) const {
		return (e1.getId() == e2.getId());
	}
};
void Hashes() {
	std::hash<std::string> h;
	std::cout << "hash: " << h("hello") << std::endl;

	std::unordered_set<employee, empHashfobj, empEqualityfobj> us;
	us.insert(employee("umar", 123));
	us.insert(employee("bob", 456));
	us.insert(employee("joey", 789));

	for (const auto& x : us)
		std::cout << "Bucket #: " << us.bucket(x) << " -> " << x.getName() << "," << x.getId() << std::endl;
}
int main()
{
	//unSet();
	//unmSet();
	//unMap();
	//unmMap();
	Hashes();
	return 0;
}