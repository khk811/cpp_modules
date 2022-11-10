#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& wp) : weapon(wp) {
	this->name = name;
}

HumanA::~HumanA() {
}

std::string	HumanA::getName() {
	return this->name;
}

Weapon&	HumanA::getWeapon() {
	return this->weapon;
}

void	HumanA::attack() {
	std::cout << this->getName();
	std::cout << " attacks with their ";
	std::cout << this->getWeapon().getType() << std::endl;
}
