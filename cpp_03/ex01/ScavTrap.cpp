#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "ScavTrap Default Constructor Called" << std::endl;
}

ScavTrap::ScavTrap(std::string scav_name)
	: ClapTrap()
 {
	std::cout << "Scavtrap whatever created duh" << std::endl;
	this->setClapTrapName(scav_name);
	this->setClapTrapHP(100);
	this->setClapTrapEP(50);
	this->setClapTrapAD(20);
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Destructor Called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& src) {
	std::cout << "ScavTrap Copy Constructor Called" << std::endl;
	*this = src;
}
void	ScavTrap::attack(const std::string& target) {
	if (this->getClapTrapEP() > 0 && this->getClapTrapHP() > 0) {
		this->setClapTrapEP(this->getClapTrapEP() - 1);
		std::cout << "ScavTrap " << this->getClapTrapName();
		std::cout << " attacks " << target;
		std::cout << ", causing " << this->getClapTrapAD();
		std::cout << " points of damage!" << std::endl;
	}
	else {
		std::cout << "ScavTrap " << this->getClapTrapName();
		std::cout << this->getClapTrapName();
		std::cout << " Can't do anything: either it's dead or out of energy" << std::endl;
	}
}

void	ScavTrap::guardGate() {
	std::cout << "scav trap guard whatever" << std::endl;
}

ScavTrap&	ScavTrap::operator=(ScavTrap const& src) {
	std::cout << "ScavTrap Copy Assignment Operator Called" << std::endl;
	if (this != &src) {
		this->setClapTrapName(src.getClapTrapName());
		this->setClapTrapHP(src.getClapTrapHP());
		this->setClapTrapEP(src.getClapTrapEP());
		this->setClapTrapAD(src.getClapTrapAD());
	}
	return *this;
}
