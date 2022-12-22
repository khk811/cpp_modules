#include "iter.hpp"

int	main(void) {
	int	int_arr[4] = {42, 21, 0, 100};

	iter(int_arr, 4, printElement<int>);
	iter(int_arr, 4, printElementRetInt<int>);
	iter(int_arr, 4, plusOneToInt);
	// iter(int_arr, 4, printSomething);

	std::string	str_arr[3] = {"Hello", "World", "42Seoul"};
	iter(str_arr, 3, printElement<std::string>);
	iter(str_arr, 3, eraseCharL);
	iter(str_arr, 3, printElement<std::string>);
	return 0;
}
