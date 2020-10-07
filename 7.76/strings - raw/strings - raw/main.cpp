#include <iostream>
#include <cstring>
#include <string>
#include "stdio.h"

const char* combine(const char* pFirst, const char* pLast) {
	char* fullN = new char[strlen(pFirst)+strlen(pLast)+1];
	strcpy(fullN, pFirst);
	strcat(fullN, pLast);
	return fullN;
}

void usingstdString() {
	// initialize and assign:
	std::string s = "hello";
	s = "hello";

	// access characters
	s[0] = 'w';
	char ch = s[0];

	std::cout << s << std::endl;

	std::cin >> s;

	std::getline(std::cin, s);

	// size
	s.length();

	// insert & concatentate
	std::string s1{ "hello" }, s2{ "world" };
	s = s1 + s2;
	s += s;

	s.insert(6, "dear");

	// comparison
	if (s1 == s2) { std::cout << "equal" << std::endl; }
	else if (s1 > s2) { std::cout << "greater than" << std::endl; }
	else if (s1 != s2) { std::cout << "not equal to" << std::endl; }

	//removal
	s.erase(); //clears out the entire string
	s.clear(); //same as above

	s.erase(0, 5); //erases the first five strings
	//search

	auto pos = s.find("world", 0);
	if (pos != std::string::npos) {
		std::cout << "found" << std::endl;
	}
}

std::string combine(const std::string& fN, const std::string& lN) {
	return fN+lN;
}

int main() {
	//char firstN[10];
	//char lastN[10];

	//std::cin.getline(firstN, 10);
	//std::cin.getline(lastN, 10);

	//const char* pFullN = combine(firstN, lastN);
	////inser into the database

	//std::cout << pFullN << std::endl;
	//delete pFullN;

	//usingstdString();

	std::string fN;
	std::string lN;

	std::getline(std::cin, fN);
	std::getline(std::cin, lN);

	std::cout << fN + lN << std::endl;
	std::cout << combine(fN,lN) << std::endl;

	printf("%s", fN.c_str());

	return 0;
}
