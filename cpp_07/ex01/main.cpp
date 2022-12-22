#include "iter.hpp"

int	main(void) {
	int	int_arr[4] = {42, 21, 0, 100};

	iter(int_arr, 4, printElement<int>);
	return 0;
}
