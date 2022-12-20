#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

// len 부분에 N이 들어갈 수 있는지 볼것.
template<typename T, std::size_t N>
void	iter(T* addr, size_t len, T (&arr)[N]);

#endif
