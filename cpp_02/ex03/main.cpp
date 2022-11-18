#include "Point.hpp"

int main( void ) {
	bool	ret = bsp(Point(1, 1), Point(4, 1), Point(3, 7), Point(3, 1.007f));
	if (ret == true)
		std::cout << "true?" << std::endl;
	else
		std::cout << "false goddammit!" << std::endl;
	return 0;
}
