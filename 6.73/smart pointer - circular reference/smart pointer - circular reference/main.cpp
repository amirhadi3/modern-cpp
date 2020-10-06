#include <iostream>
#include <memory>
class employee;

/* pointer implementation - no memory leak*/
//class project {
//public:
//	employee* m_emp{};
//	project() {
//		std::cout << "project()" << std::endl;
//	}
//	~project() {
//		std::cout << "~project()" << std::endl;
//	}
//};
//
//class employee {
//public:
//	project* m_prj{};
//	employee() {
//		std::cout << "employee()" << std::endl;
//	}
//	~employee() {
//		std::cout << "~employee()" << std::endl;
//	}
//};
//
//int main() {
//	project* prj = new project{};
//	employee* emp = new employee{};
//
//	emp->m_prj = prj;
//	prj->m_emp = emp;
//
//	delete prj;
//	delete emp;
//}


/* shared pointer implementation - memory leak: deconstructors are not called*/
//class project {
//public:
//	std::shared_ptr<employee> m_emp{};
//	project() {
//		std::cout << "project()" << std::endl;
//	}
//	~project() {
//		std::cout << "~project()" << std::endl;
//	}
//};
//
//class employee {
//public:
//	std::shared_ptr<project> m_prj{};
//	employee() {
//		std::cout << "employee()" << std::endl;
//	}
//	~employee() {
//		std::cout << "~employee()" << std::endl;
//	}
//};
//
//int main() {
//	std::shared_ptr<project> prj{ new project{} };
//	std::shared_ptr<employee> emp{ new employee{} };
//
//	emp->m_prj = prj;
//	prj->m_emp = emp;
//}


/* weak pointer implementation - no memory leak
   weak pointer need to be used only for one of
   the object in circular referencing but there 
   is no harm in having it on both of them.
   */
class project {
public:
	std::weak_ptr<employee> m_emp{};
	project() {
		std::cout << "project()" << std::endl;
	}
	~project() {
		std::cout << "~project()" << std::endl;
	}
};

class employee {
public:
	std::weak_ptr<project> m_prj{};
	employee() {
		std::cout << "employee()" << std::endl;
	}
	~employee() {
		std::cout << "~employee()" << std::endl;
	}
};

int main() {
	std::shared_ptr<project> prj{ new project{} };
	std::shared_ptr<employee> emp{ new employee{} };

	emp->m_prj = prj;
	prj->m_emp = emp;
}