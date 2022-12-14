#include "DerivedClass.hpp"

A::A() {
	std::cout << "A Constructor Called" << std::endl;
}

A::~A() {
	std::cout << "A Destructor Called" << std::endl;
}

B::B() {
	std::cout << "B Constructor Called" << std::endl;
}

B::~B() {
	std::cout << "B Destructor Called" << std::endl;
}

C::C() {
	std::cout << "C Constructor Called" << std::endl;
}

C::~C() {
	std::cout << "C Destructor Called" << std::endl;
}
