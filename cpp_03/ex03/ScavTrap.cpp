#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "ScavTrap Default Constructor Called" << std::endl;
}

ScavTrap::ScavTrap(std::string scav_name) : ClapTrap(scav_name) {
	std::cout << "Scavtrap whatever created duh" << std::endl;
	this->hp = 100;
	this->ep = 50;
	this->ad = 20;
 }


ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Destructor Called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& src) {
	std::cout << "ScavTrap Copy Constructor Called" << std::endl;
	*this = src;
}
void	ScavTrap::attack(const std::string& target) {
	if (this->ep > 0 && this->hp > 0) {
		this->ep -= 1;
		std::cout << "ScavTrap " << this->name;
		std::cout << " attacks " << target;
		std::cout << ", causing " << this->ad;
		std::cout << " points of damage!" << std::endl;
	}
	else {
		std::cout << "ScavTrap " << this->name;
		std::cout << this->name;
		std::cout << " Can't do anything: either it's dead or out of energy" << std::endl;
	}
}

void	ScavTrap::guardGate() {
	std::cout << "scav trap guard whatever" << std::endl;
}

ScavTrap&	ScavTrap::operator=(ScavTrap const& src) {
	std::cout << "ScavTrap Copy Assignment Operator Called" << std::endl;
	if (this != &src) {
		this->name = src.name;
		this->hp = src.hp;
		this->ep = src.ep;
		this->ad = src.ad;
	}
	return *this;
}
