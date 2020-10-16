#include <iostream>
#include <thread>
#include <list>
#include <mutex>

std::list<int> g_Data;
int SIZE = 30000;
std::mutex g_Mutex;

// using mutex for access management to the variables in threads is risky
// because if it is not unlocked for whatever reason (premature termination
// or exceptions), it will lead to a deadlock

// a safer approach is to use lock_guard which is based on RAII
void download1() {
	for (int i = 0; i < SIZE; ++i) {
		//g_Mutex.lock();
		std::lock_guard<std::mutex> lgm(g_Mutex);
		g_Data.push_back(i);
		//g_Mutex.unlock();
	}
}

void download2() {
	for (int i = 0; i < SIZE; ++i) {
		//g_Mutex.lock();
		std::lock_guard<std::mutex> lgm(g_Mutex);
		g_Data.push_back(i);
		//g_Mutex.unlock();
	}
}

int main() {
	std::thread thDownloader1(download1);
	std::thread thDownloader2(download2);
	thDownloader1.join();
	thDownloader2.join();
	std::cout << g_Data.size() << std::endl;
}