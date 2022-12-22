#include <iostream>
#include "whatever.hpp"

void	exampleTest(void) {
	std::cout << "\n\n===The test in the subject===\n" << std::endl;
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

void	swapTest(void) {
	std::cout << "\n\n===Test swap() : using float===\n" << std::endl;
	float	a = 42.024f;
	float	b = 24.042f;

	std::cout << "Before swap => a: " << a << ", b: " << b << std::endl;
	swap<float>(a, b);
	std::cout << "\nAfter swap => a: " << a << ", b: " << b << std::endl;
}

void	minTest(void) {
	std::cout << "\n\n===Test min() : using std::string===\n" << std::endl;
	std::string	str_a = "AAAAAAA";
	std::string str_b = "BBBBBBB";

	std::cout << "str_a: " << str_a << ", str_b: " << str_b << std::endl;
	std::cout << "min() result: " << min(str_a, str_b) << std::endl;
}

void	maxTest(void) {
	std::cout << "\n\n===Test max() : using unsigned int===\n" << std::endl;
	unsigned int	x = 420000;
	unsigned int	y = 101;

	std::cout << "x: " << x << ", y: " << y << std::endl;
	std::cout << "max() result: " << max(x, y) << std::endl;
}

int main( void ) {
	exampleTest();
	swapTest();
	minTest();
	maxTest();
	return 0;
}
