#include <future>
#include <iostream>
#include <thread>

int operation(int count) {
	using namespace std::chrono_literals;
	int sum{};
	for (int i = 0; i < count; ++i) {
		sum += i;
		std::cout << '.';
		std::this_thread::sleep_for(300ms);
	}
	return sum;
}

int main() {
	using namespace std::chrono_literals;
	std::future<int> result = std::async(std::launch::async, operation, 10);
	std::cout << "main() thread continues execution ... \n";
	if (result.valid()) {
		auto timepoint = std::chrono::system_clock::now();			// read current time
		timepoint += std::chrono::seconds(2s);						// add two seconds to the timepoint
		auto status = result.wait_until(timepoint);					// wait until the timepoint
		switch (status)
		{
		case std::future_status::ready:
			std::cout << "result is ready \n";
			break;
		case std::future_status::timeout:
			std::cout << "task is still running \n";
			break;
		case std::future_status::deferred:
			std::cout << "task is synchronous \n";
			break;
		}
		auto sum = result.get();	// blocking
		std::cout << std::endl;
		std::cout << sum << std::endl;
	}
	return 0;
}