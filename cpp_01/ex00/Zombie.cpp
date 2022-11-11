#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "OMG! THE ZOMBIE!!" << std::endl;
}

Zombie::Zombie(std::string name) {
	std::cout << "OMG! THE ZOMBIE!!" << std::endl;
	this->name = name;
}

Zombie::~Zombie() {
	std::cout << this->name << " was shot and killed! Goodbye!" << std::endl;
}

void	Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
