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
	// void below is the return type of the threaded function
	// if the return object is not captured in a variable (result below), 
	// threading would not be achieved.
	// if std::launch::async is used as the launch policy, it will immediately start a new thread and executes the callable.
	// if std::launch::deferred is used as the launch policyt, it will defer the execution of the callable until .get() function
	// is called on the returned future object.

	std::future<int> result = std::async(std::launch::deferred, operation,10);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "main() thread continues execution ... \n";

	//.get() returns the return object of the funcion call in the thread.
	if (result.valid()) {
		std::cout << "the callable is execute now if std::launch::deferred was used" << std::endl;
		//auto sum = operation(10);
		// the line below is equivalent to the line above.
		auto sum = result.get();
		std::cout << std::endl;
		std::cout << sum << std::endl;
	}
	if (result.valid()) {
		std::cout << "after get() the result valid turns off" << std::endl;
	}
	return 0;
}