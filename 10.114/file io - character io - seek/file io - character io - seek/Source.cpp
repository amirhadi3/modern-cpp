#include <iostream>
#include <fstream>
#include <string>

void write() {
	std::ofstream out{ "test.txt" };
	if (!out) {
		std::cout << "could not open file for writing" << std::endl;
		return;
	}

	std::string message{ "C++ was invented by Bjarne" };
	//character write
	for (char& ch : message)
		out.put(ch);

	// could be std::ios::beg, std:ios::cur, std::ios::end
	out.seekp(5, std::ios::beg);
	std::cout << "the getptr position is:" << out.tellp() << std::endl;
	out.put('#');

	out.close();
}

void read() {
	std::ifstream input{ "test.txt" };
	if (!input) {
		std::cout << "could not open file for reading" << std::endl;
		return;
	}

	// could be std::ios::beg, std:ios::cur, std::ios::end
	input.seekg(3, std::ios::beg); 
	std::cout << "the getptr position is:" << input.tellg() << std::endl;
	char ch;
	while (input.get(ch))
		std::cout << ch;
	input.close();
}

void usingfstream() {
	std::fstream stream{ "file.txt" };
	if (!stream) // file does not exist
	{
		std::cout << "file does not exist, creation in progress";
		std::ofstream out("file.txt");
		out.close();
		stream.open("file.txt");
	}
	stream << "hello world" << std::endl;
	std::cout << std::endl;
	std::cout << "after writing to the file the putptr and getptr are at:" << std::endl;
	std::cout << "putptr: " << stream.tellp() << std::endl;
	std::cout << "getptr: " << stream.tellg() << std::endl;

	// so we move the get ptr to the begining of the file and start reading from it.
	stream.seekg(0);

	std::cout << "putptr: " << stream.tellp() << std::endl;
	std::cout << "getptr: " << stream.tellg() << std::endl;

	char ch{};
	while (stream.get(ch))
		std::cout << ch;
	
	stream.clear();
	stream.seekg(0);

	std::string line;
	std::getline(stream, line);
	std::cout << line << std::endl;
	stream.close();
}
int main() {
	write();
	read();
	usingfstream();
	return 0;
}