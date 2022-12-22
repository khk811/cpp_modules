#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T, typename F>
void	iter(T* addr, size_t len, F func) {
	for (size_t i = 0; i < len; i++)
	{
		func(addr[i]);
	}
}

// Function template for test;
template<typename T>
void	printElement(T a) {
	std::cout << a << std::endl;
}


#endif
