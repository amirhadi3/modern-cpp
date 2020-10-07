#include <iostream>
#include <string>
#include <cstring>

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

int main() {
	size_t pos = find("This is a Test", "Test", Case::SENSITIVE, 0);
    if (pos == std::string::npos) {
        std::cout << "not found" << std::endl;
    }
    else
        std::cout << "found at: " << pos << std::endl;
	return 0;
}