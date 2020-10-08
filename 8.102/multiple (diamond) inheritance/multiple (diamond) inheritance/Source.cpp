#include <iostream>
#include <string>

class stream {
	std::string m_fileName;
public:
	stream(const std::string& filename): m_fileName(filename) {
		std::cout << "stream(const std::string&)" << std::endl;
	}
	const std::string& getFileName() const {
		return m_fileName;
	}
	~stream() {
		std::cout << "~stream(const std::string&)" << std::endl;
	}
};

class outputStream : virtual public stream {
	std::ostream& out;
public:
	outputStream(std::ostream& o, const std::string& filename) : out(o), stream(filename) {
		std::cout << "outputStream(std::ostream&, const std::string&)" << std::endl;
	}

	std::ostream& operator << (const std::string& data) {
		out << data;
		return out;
	}

	~outputStream() {
		std::cout << "~outputStream( )" << std::endl;
	}
};

class inputStream : virtual public stream {
	std::istream& in;
public:
	inputStream(std::istream& i, const std::string& filename) : in(i), stream(filename) {
		std::cout << "inputStream(std::istream&, const std::string&)" << std::endl;
	}

	std::istream& operator >> (std::string& data) {
		in >> data;
		return in;
	}

	~inputStream() {
		std::cout << "~inputStream( )" << std::endl;
	}

};

class ioStream :public outputStream, public inputStream {
public:
	ioStream(const std::string& filename) :outputStream(std::cout, filename), inputStream(std::cin, filename), stream(filename) {
		std::cout << "ioStream(const std::string&)" << std::endl;
	}
	~ioStream(){ 
		std::cout << "~ioStream()" << std::endl;
	}
};

int main() {
	ioStream stream("doc.txt");
	std::string data;
	stream >> data;
	stream << data;
	stream << stream.getFileName() << std::endl;

	outputStream ostream(std::cout, "doc1.txt");
	ostream << data << std::endl;

	return 0;
}