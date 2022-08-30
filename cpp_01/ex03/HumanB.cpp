#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	this->_name = name;
}

HumanB::~HumanB() {
}

void	HumanB::setWeapon(Weapon& weapon) {
	this->_weapon = &(weapon);
}

std::string	HumanB::getWeapon() const {
	return (*(this->_weapon)).getType();
}

void	HumanB::attack() {
	std::cout << this->_name;
	std::cout << " attacks with their ";
	std::cout << (*(this->_weapon)).getType() << std::endl;
}
