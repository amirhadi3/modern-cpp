#include <iostream>
#include <string>
#include "template.h"

// Explicit Specialization for an array of const char*
template<> const char* Max <const char*, 5>(const char* (&arr)[5]) {
	std::cout << "Max <const char *, 5>" << std::endl;
	char * l = new char[10];
	strcpy_s(l, 10, arr[0]);
	for (int i = 1; i < 5; i++)
	{
		strcpy_s(l, 10, (strcmp(arr[i], l) > 0 ? arr[i] : l));
	}
	return l;
}

// Explicit Specialization for an array of std::strings.
template<> std::string Max <std::string, 5>(std::string(&arr)[5]) {
	std::cout << "Max <std::string, 5>" << std::endl;
	std::string l{ arr[0] };
	for (auto str : arr)
	{
		l = strcmp(str.c_str(), l.c_str()) > 0 ? str : l;
	}
	return l;
}