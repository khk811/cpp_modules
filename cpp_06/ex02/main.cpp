#include "DerivedClass.hpp"
#include <ctime>
#include <cstdlib>

Base * generate(void) {
	srand(static_cast<unsigned int>(time(NULL)));
	int chance = rand() % 10;
	Base*	ret;

	if (0 <= chance && chance <= 2) {
		ret = new A();
	} else if (3 <= chance && chance <= 5) {
		ret = new B();
	} else {
		ret = new C();
	}
	return ret;
}

void identify(Base* p) {
	A*		derived_a = dynamic_cast<A*>(p);
	B*		derived_b = dynamic_cast<B*>(p);
	C*		derived_c = dynamic_cast<C*>(p);

	if (derived_a != NULL) {
		std::cout << "A" << std::endl;
	} else if (derived_b != NULL) {
		std::cout << "B" << std::endl;
	} else  if (derived_c != NULL) {
		std::cout << "C" << std::endl;
	}
}

//void identify(Base& p);
// try & catch => throw exception;

void identify(Base& p) {
	try
	{
		A	is_a = dynamic_cast<A&>(p);
	}
	catch(const std::exception& e)
	{
		std::cout << "is not A" << std::endl;
	}
	try
	{
		B	is_b = dynamic_cast<B&>(p);
	}
	catch(const std::exception& e)
	{
		std::cout << "is not B" << std::endl;
	}
	try
	{
		C	is_c = dynamic_cast<C&>(p);
	}
	catch(const std::exception& e)
	{
		std::cout << "is not C" << std::endl;
	}
}

int	main(void) {
	Base*	test = generate();

	identify(test);
	identify(*test);
	return 0;
}
