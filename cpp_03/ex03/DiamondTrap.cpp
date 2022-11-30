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
	this->name = dia_name;
	ClapTrap::name = dia_name.append("_clap_trap");
	this->ep = 50;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap Destructor Called" << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap whoAmI() Called" << std::endl;
	if (this->ep > 0 && this->hp > 0) {
		std::cout << "'I am " << this->name << ".'" << std::endl;
		std::cout << "'In ClapTrap name, I am " << ClapTrap::name << ".'" << std::endl;
	}
	else {
		std::cout << "DiamondTrap " << this->name;
		std::cout << " can't do anything: Not enough HP(or Ep)" << std::endl;
	}
}

DiamondTrap&	DiamondTrap::operator=(DiamondTrap const& src) {
	std::cout << "DiamondTrap Copy Assignment Operator Called" << std::endl;
	if (this != &src) {
		this->name = src.name;
		this->hp = src.hp;
		this->ep = src.ep;
		this->ad = src.ad;
	}
	return *this;
}
