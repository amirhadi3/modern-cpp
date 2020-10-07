#include <iostream>
#include <string>
#include <cstring>

std::string ToUpper(const std::string& str) {
    std::string out{};
    if (str.length() == 0)
        return out;
    int i{0};
    char c{};
    while (str[i])
    {
        c = str[i];
        out+=static_cast<char>(toupper(c));
        i++;
    }
	return out;
}

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

int main() {
    std::string ins;
    std::getline(std::cin, ins);
    std::cout << ToLower(ins) << std::endl;
    std::cout << ToUpper(ins) << std::endl;
    return 0;
}