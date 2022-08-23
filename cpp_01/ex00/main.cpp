#include "Zombie.hpp"

int	main(void) {
	Zombie*	heap_zombie;

	heap_zombie = newZombie("Alex");
	heap_zombie->announce();
	delete heap_zombie;
	randomChump("Brad");
	return 0;
}
