#include <iostream>
#include <list>
#include <thread>

std::list<int> g_Data;
const int SIZE = 5000000;

class String {
public:
	String() { std::cout << "String()" << std::endl; }
	String(const String &){ std::cout << "String(const String &)" << std::endl; }
	String& operator=(const String&) {
		std::cout << "operator = (const String &)" << std::endl;
		return *this;
	}
	~String() { std::cout << "~String()" << std::endl; }
};

void download(const String& file, const int& size) {
	//std::cout << "[downloader] started download file: " << file << " of size " << size << std::endl;
	for (int i = 0; i < SIZE; ++i) {
		g_Data.push_back(i);
	}
	std::cout << "[Downloader] finished download" << std::endl;
}

int main() {
	String file;
	int size{ 4 };
	std::cout << "[main] user started an operation" << std::endl;
	//std::ref must be used with threads to pass in argument by reference
	//std::cref must be used with threads to pass in arguments as constant reference
	std::thread thDownloader(download, std::cref(file), size);	// creates thDownloader thread and immediately executes the callable
	//thDownloader.detach();									// when a thread is detached, it is no longer joinable and .join() cannot be called on it
	std::cout << "[main] user started another operation" << std::endl;
	if (thDownloader.joinable())
		thDownloader.join();								// blocks the main thread until the thDownloader finishes
	else
		system("Pause");
	//std::cout << file << std::endl;
	return 0;
}