#include "iter.hpp"

template<typename T, typename F>
void	iter(T* addr, size_t len, F func) {
	for (size_t i = 0; i < len; i++)
	{
		func(addr[i]);
	}
}

template<typename T>
void	printElement(T a) {
	std::cout << a << std::endl;
}

int	main(void) {
	int	int_arr[4] = {42, 21, 0, 100};

	iter(int_arr, 4, printElement<int>);
	return 0;
}
