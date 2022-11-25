#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	std::cout << "DiamondTrap Default Constructor Called" << std::endl;
	this->ep = 50;
}

DiamondTrap::DiamondTrap(DiamondTrap const& src) {
	std::cout << "DiamondTrap Copy Constructor Called" << std::endl;
	*this = src;
}

DiamondTrap::DiamondTrap(std::string dia_name)
: ClapTrap(dia_name), ScavTrap(dia_name), FragTrap(dia_name) {
	std::cout << "DiamondTrap String Constructor Called" << std::endl;
	this->ep = 50;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap Destructor Called" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(DiamondTrap const& src) {
	if (this != &src) {
		this->name = src.name;
		this->hp = src.hp;
		this->ep = src.ep;
		this->ad = src.ad;
	}
	return *this;
}
