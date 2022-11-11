#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& wp) : weapon(wp) {
	this->name = name;
}

HumanA::~HumanA() {
}

void	HumanA::attack() {
	std::cout << this->name << " attacks with their " \
	<< this->weapon.getType() << std::endl;
}
