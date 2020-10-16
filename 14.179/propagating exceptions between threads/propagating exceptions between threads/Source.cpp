#include <future>
#include <iostream>
#include <thread>

int operation(std::promise<int>& data) {
	using namespace std::chrono_literals;
	auto f = data.get_future();
	std::cout << "[Task] waiting for count \n";
	try {
		auto count = f.get();
		std::cout << "[Task] count acquired \n";
		int sum{};
		for (int i = 0; i < count; ++i) {
			std::cout << '.';
			sum += i;
			std::this_thread::sleep_for(300ms);
		}
		return sum;
	}
	catch (std::exception& ex) {
		std::cout << "[Task] Exception: " << ex.what() << std::endl;
		throw std::runtime_error{ "sum not available" };
	}
}
/* alternativvely we could have passed in the future object directly
int operation(std::future<int>& f) {
	auto count = f.get();
	int sum{};
	for (int i = 0; i < count; ++i) {
		std::cout << '.';
		sum += i;
	}
	return sum;
}
*/

int main() {
	using namespace std::chrono_literals;
	std::promise<int> data;
	std::future<int> result = std::async(std::launch::async, operation, std::ref(data));
	/* the lines above should have been replaced by the lines below if we had passed in the future object
	std::future<int> f = data.get_future();;
	std::future<int> result = std::async(std::launch::async, operation, std::ref(f));
	*/
	try {
		throw std::runtime_error{ "data not available" };
		std::this_thread::sleep_for(1s);
		std::cout << "[main] setting the data in promise\n";
		data.set_value(20);
	}
	catch (std::exception& ex) {
		data.set_exception(std::make_exception_ptr(ex));
	}
	try {
		if (result.valid()) {
			std::cout << std::endl << "[main] sum: " << result.get() << std::endl;
		}
	}
	catch (std::exception& ex) {
		std::cout << "[Main] Exception: " << ex.what() << std::endl;
	}
	return 0;
}