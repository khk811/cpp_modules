#include "Zombie.hpp"

int	main(void) {
	Zombie*	the_horde_of_zombie = NULL;

	the_horde_of_zombie = zombieHorde(10, "Charles");
	delete[] the_horde_of_zombie;
	return 0;
}
