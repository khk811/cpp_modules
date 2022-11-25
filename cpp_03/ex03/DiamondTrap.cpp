#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap() {
	std::cout << "DiamondTrap Default Constructor Called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const& src) {
	std::cout << "DiamondTrap Copy Constructor Called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap Destructor Called" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(DiamondTrap const& src) {
	if (this != &src) {
		this->name = src.name;
	}
	return *this;
}
