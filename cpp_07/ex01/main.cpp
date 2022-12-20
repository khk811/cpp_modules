#include "iter.hpp"

template<typename T, std::size_t N>
void	iter(T* addr, size_t len, T (&arr)[N]) {
	std::cout << "addr: " << addr << std::endl;
	for (size_t i = 0; i < len; i++)
	{
		std::cout << i << ": " << arr[i] << std::endl;
	}
}

int	main(void) {
	int	int_arr[3] = {42, 21, 84};

	iter<int>(int_arr, 3, int_arr);


	std::string	str_arr[4] = {"hello", "world", "42", "Seoul"};

	iter<std::string>(str_arr, 4, str_arr);

	float	float_arr[5] = {42.024, 3.14, 0.123, 24.042, 0.001};

	iter<float>(float_arr, 5, float_arr);

	return 0;
}
