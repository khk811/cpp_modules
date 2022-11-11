#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "OMG! THE ZOMBIE!!" << std::endl;
}

Zombie::~Zombie() {
	std::cout << this->name << " was shot and killed! Goodbye!" << std::endl;
}

void	Zombie::setZombieName(std::string name) {
	this->name = name;
}

void	Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
