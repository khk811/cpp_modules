#include "iter.hpp"

void	intArrayTest(void) {
	std::cout << "\n\n\n===Array Test: [ int ]===\n" << std::endl;
	int	int_arr[4] = {42, 21, 0, 100};

	std::cout << "\n---printElementAddr() : function template---\n" << std::endl;
	iter(int_arr, 4, printElementAddr<int>);
	std::cout << "\n---printElement() : function template---\n" << std::endl;
	iter(int_arr, 4, printElement<int>);
	std::cout << "\n=> Using plusOneToInt(): add 1 to int parameter" << std::endl;
	iter(int_arr, 4, plusOneToInt);
	std::cout << "\n---print after plusOneToInt()---\n" << std::endl;
	iter(int_arr, 4, printElement<int>);
	// Error case: pass non-function parameter as third parameter;
	// iter(int_arr, 4, 100);
}

void	stringArrayTest(void) {
	std::cout << "\n\n\n===Array Test: [ std::string ]===\n" << std::endl;
	std::string	str_arr[3] = {"Hello", "World", "42Seoul"};

	std::cout << "\n---printElementAddr() : function template---\n" << std::endl;
	iter(str_arr, 3, printElementAddr<std::string>);
	std::cout << "\n---printElement() : function template---\n" << std::endl;
	iter(str_arr, 3, printElement<std::string>);
	std::cout << "\n=> Using eraseCharL(): erase 'l', if the string has char 'l'" << std::endl;
	iter(str_arr, 3, eraseCharL);
	std::cout << "\n---print after eraseCharL()---\n" << std::endl;
	iter(str_arr, 3, printElement<std::string>);
}

int	main(void) {
	intArrayTest();
	stringArrayTest();
	return 0;
}
