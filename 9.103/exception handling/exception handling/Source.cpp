#include <iostream>
#include <memory>
#include <vector>
class test {
public:
	test(){
		std::cout << "test(): allocate resources" << std::endl;
	}
	~test(){
		std::cout << "~test(): release resources" << std::endl;
	}
};

int processRecords(const int& count) {
	//test t1;					// will be released because it is created on the stack
	//test* t2 = new test;		// will not be released if exception happens
	std::unique_ptr<test> t3(new test);

	if (count < 10) {
		throw std::out_of_range("Count should be greater than 10");
	}
	//int* p = new int[count];	// not recommended because in stack unwinding after throw
								// the resources on the heap will not be released and it
								// will cause memory leakage.
	//int* pArray = (int *) malloc(count * sizeof(int));
	
	std::vector<int> p;
	std::vector<int> pArray;
	p.reserve(count);
	pArray.reserve(count);
	
	//if (pArray == nullptr) {
	//	throw std::runtime_error("failed to allocated memory");
	//}
	
	for (int i = 0; i < count; i++) {
		pArray.push_back(i);
	}
	
	//free(pArray);
	//delete[] p;
	//delete t2;
	return 0;
}

int main() {
	try {
		//processRecords(std::numeric_limits<int>::max());
		processRecords(5);
	}
	//catch (std::runtime_error& ex) {
	//	std::cout << ex.what() << std::endl;
	//}
	//catch (std::out_of_range& ex) {
	//	std::cout << ex.what() << std::endl;
	//}
	//catch (std::bad_alloc& ex) {
	//	std::cout << ex.what() << std::endl;
	//}
	//catch (std::exception& ex) {
	//	std::cout << ex.what() << std::endl;
	//}
	catch (...) {	// not very useful becuase it is not specific on what happened.
					// if used, must be the last. Otherwise, it always will be called and 
					// and the other catch blocks do noting
		std::cout << "Exception Occurred" << std::endl;
	}
	return 0;
}