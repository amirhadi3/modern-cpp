#include <iostream>
#include <string>
#include <cstring>
#include <vector>

enum class Case { SENSITIVE, INSENSITIVE };

std::string ToLower(const std::string& str) {
	std::string out{};
	if (str.length() == 0)
		return out;
	int i{ 0 };
	char c{};
	while (str[i])
	{
		c = str[i];
		out += static_cast<char>(tolower(c));
		i++;
	}
	return out;
}

size_t find(
	const std::string& source,              //Source string to be searched
	const std::string& search_string,       //The string to search for
	Case searchCase = Case::INSENSITIVE,    //Choose case sensitive/insensitive search
	size_t offset = 0) {                    //Start the search from this offset
		//Implementation
	if (searchCase == Case::INSENSITIVE) {
		std::string lsource = ToLower(source);
		std::string ssource = ToLower(search_string);
		return lsource.find(ssource, offset);
	}
	else if (searchCase == Case::SENSITIVE) {
		return source.find(search_string, offset);
	}
	else
		return std::string::npos;
}

std::vector<int>
findAll(
	const std::string& target,         //Target string to be searched
	std::string search_string,         //The string to search for
	Case searchCase = Case::INSENSITIVE,//Choose case sensitive/insensitive search
	size_t offset = 0) {                //Start the search from this offset

	std::vector<int> indices;
	int pos = find(target, search_string, searchCase, offset);
	while (pos != std::string::npos) {
		indices.push_back(pos);
		offset += (pos+1);
		pos = find(target, search_string, searchCase, offset);
	}
	return indices;
}

int main() {
	std::string source{ "This is a Test a Test; you know a test" };
	std::string target{ "test" };
	size_t pos = find(source, target, Case::SENSITIVE, 0);
	if (pos == std::string::npos) {
		std::cout << "not found" << std::endl;
	}
	else
		std::cout << "found at: " << pos << std::endl;

	std::vector<int> indices = findAll(source, target, Case::INSENSITIVE, 0);
	for (auto x : indices)
		std::cout << x << std::endl;
	return 0;
}