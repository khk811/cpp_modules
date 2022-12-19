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

	std::cout << "\n\n---identify(base *) func()---" << std::endl;
	if (derived_a != NULL) {
		std::cout << "A" << std::endl;
	} else if (derived_b != NULL) {
		std::cout << "B" << std::endl;
	} else  if (derived_c != NULL) {
		std::cout << "C" << std::endl;
	}
}

void identify(Base& p) {
	std::cout << "\n\n---identify(base &) func()---" << std::endl;
	try
	{
		A	is_a = dynamic_cast<A&>(p);
		std::cout << "A\n\n" << std::endl;
	}
	catch(const std::exception& e)
	{
		e.what();
	}
	try
	{
		B	is_b = dynamic_cast<B&>(p);
		std::cout << "B\n\n" << std::endl;
	}
	catch(const std::exception& e)
	{
		e.what();
	}
	try
	{
		C	is_c = dynamic_cast<C&>(p);
		std::cout << "C\n\n" << std::endl;
	}
	catch(const std::exception& e)
	{
		e.what();
	}
	std::cout << "\n\n" << std::endl;
}

int	main(void) {
	Base*	test = generate();

	identify(test);
	identify(*test);
	delete test;
	system("leaks a.out");
	return 0;
}
