#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& wp) : _weapon(wp) {
	this->_name = name;
}

HumanA::~HumanA() {
}

void	HumanA::attack() {
	std::cout << this->_name;
	std::cout << " attacks with their ";
	std::cout << this->_weapon.getType() << std::endl;
}
