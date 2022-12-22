#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

// void	iter(T* addr, size_t len, F (*func)(T&));
// void	iter(T* addr, size_t len, void (*func)(T&));
template<typename T, typename F>
void	iter(T* addr, size_t len, F func) {
	for (size_t i = 0; i < len; i++)
	{
		func(addr[i]);
	}
}

// Functions  for test;
template<typename T>
void	printElement(T& a) {
	std::cout << a << std::endl;
}

template<typename T>
int		printElementRetInt(T& b) {
	std::cout << b << std::endl;
	return 0;
}

int	plusOneToInt(int c) {
	std::cout << c + 1 << std::endl;
	return c + 1;
}

bool	eraseCharL(std::string& target) {
	if (target.find('l') != std::string::npos) {
		target = target.erase(target.find('l'), 1);
		return true;
	} else {
		return false;
	}
}

#endif
