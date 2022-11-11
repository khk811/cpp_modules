#include "Zombie.hpp"

int	main(void) {
	Zombie*	the_horde_of_zombie = NULL;

	the_horde_of_zombie = zombieHorde(10, "Charles");
	for (int i = 0; i < 10; i++) {
		the_horde_of_zombie[i].announce();
		std::cout << "zombie " << i << " has been created!!" << std::endl;
	}
	delete[] the_horde_of_zombie;
	return 0;
}
