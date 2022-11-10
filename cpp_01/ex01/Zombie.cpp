#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "OMG! THE ZOMBIE!!" << std::endl;
}

Zombie::~Zombie() {
	std::cout << this->getZombieName();
	std::cout << " was shot and killed! Goodbye!" << std::endl;
}

std::string	Zombie::getZombieName() {
	return this->name;
}

void	Zombie::setZombieName(std::string name) {
	this->name = name;
}

void	Zombie::announce() {
	std::cout << this->getZombieName();
	std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
