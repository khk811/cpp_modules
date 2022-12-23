#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T, typename F>
void	iter(T* addr, size_t len, F (*func)(T&)) {
	for (size_t i = 0; i < len; i++)
	{
		func(addr[i]);
	}
}

template<typename T, typename F>
void	iter(T* addr, size_t len, F (*func)(T const&)) {
	for (size_t i = 0; i < len; i++)
	{
		func(addr[i]);
	}
}

// Functions for test;
template<typename T>
void	printElement(T& a) {
	std::cout << a << std::endl;
}

template<typename T>
T const*	printElementAddr(T const& a) {
	std::cout << &a << std::endl;
	return &a;
}

int	plusOneToInt(int& c) {
	c += 1;
	return c;
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
