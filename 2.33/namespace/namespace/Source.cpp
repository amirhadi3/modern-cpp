#include <iostream>
namespace avg {
	float calculate(float x, float y) {
		return (x + y) / 2;
	}
}

namespace basic {
	float calculate(float x, float y) {
		return x + y;
	}
}

namespace sort {
	void quicksort() {

	}
	void insertionsort() {

	}
	void mergesort() {

	}
	namespace comparison {
		void less() {

		}
		void greater() {

		}
	}
}

namespace {
	void internalfunction() {

	}
}

int main()
{
	using std::cout;
	using std::endl;
	cout << avg::calculate(3.9f,8.2f) << endl;
	cout << basic::calculate(3.9f, 8.2f) << endl;

	sort::comparison::less();
	internalfunction();
	return 0;
}