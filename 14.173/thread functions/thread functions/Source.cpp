#include <iostream>
#include <thread>
#include <Windows.h>
void process() {
	std::cout << std::this_thread::get_id() << std::endl;
	for (int i = 0; i < 10; ++i) {
		std::cout << i << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

int main() {
	std::thread thProcess(process);

	// get_id() returns a unique id of the thread
	auto id = thProcess.get_id();
	std::cout << id << std::endl;

	// get the handle on the operating system
	// type: on windows: HANDLE
	//		 on linux: pthread_d
	auto thandle = thProcess.native_handle();

	// on linux it is pthread_setname_np
	SetThreadDescription(thandle, L"MyThread");

	// return the number of CPU cores.
	std::cout << "cores: " << std::thread::hardware_concurrency() << std::endl;

	thProcess.join();
	return 0;
}