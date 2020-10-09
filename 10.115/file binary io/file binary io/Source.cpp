#include <iostream>
#include <fstream>
#include <string>

struct record {
	int id;
	char name[10];
};

void writeRecord(record *p) {
	std::ofstream binstream("records", std::ios::binary | std::ios::out);
	binstream.write((char*)p, sizeof(record));
	binstream.close();
}

record getRecord() {
	std::ifstream binstream("records", std::ios::binary | std::ios::in);
	record r;
	binstream.read((char*)&r, sizeof(record));
	binstream.close();
	return r;
}



int main() {
	record r;
	r.id = 1001;
	strcpy_s(r.name, sizeof(r.name), "Amir");
	writeRecord(&r);
	r = getRecord();
	std::cout << r.id << std::endl;
	std::cout << r.name << std::endl;

	std::ofstream textstream("data");
	textstream << 12345678;

	std::ofstream binstream("binary",std::ios::binary | std::ios::out);
	int num{ 12345678 };
	binstream.write((const char*)&num, sizeof(num));
	binstream.close();

	std::ifstream input("binary", std::ios::binary | std::ios::in);
	num = 0;
	input.read((char*)&num, sizeof(num));
	std::cout << num << std::endl;
	return 0;
}