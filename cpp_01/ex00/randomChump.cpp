#include "Zombie.hpp"

void	randomChump(std::string name) {
	Zombie	stack_zombie;

	stack_zombie.setZombieName(name);
	stack_zombie.announce();
}
