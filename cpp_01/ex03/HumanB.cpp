#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	this->name = name;
}

HumanB::~HumanB() {
}

std::string	HumanB::getName() {
	return this->name;
}

void	HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &(weapon);
}

Weapon*	HumanB::getWeapon() {
	return this->weapon;
}

void	HumanB::attack() {
	std::cout << this->getName();
	std::cout << " attacks with their ";
	std::cout << this->getWeapon()->getType() << std::endl;
}
