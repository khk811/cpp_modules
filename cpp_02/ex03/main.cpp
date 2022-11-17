#include "Point.hpp"

int main( void ) {
	bool	ret = bsp(Point(Fixed(1), Fixed(1)), Point(Fixed(4), Fixed(1)), Point(Fixed(3), Fixed(7)), Point(Fixed(3), Fixed(1.002f)));
	if (ret == true)
		std::cout << "true?" << std::endl;
	else
		std::cout << "false goddammit!" << std::endl;
	return 0;
}
