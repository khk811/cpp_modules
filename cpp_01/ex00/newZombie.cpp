#include "Zombie.hpp"

Zombie*	newZombie(std::string name) {
	Zombie*	ret = new Zombie();

	ret->setZombieName(name);
	return ret;
}
