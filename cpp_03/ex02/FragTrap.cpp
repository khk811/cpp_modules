#include "FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << "FragTrap Default Constructor Called" << std::endl;
	this->name = "[Untitled]";
	this->hp = 100;
	this->ep = 100;
	this->ad = 30;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Desstructor Called" << std::endl;
}

FragTrap::FragTrap(FragTrap const& src) {
	std::cout << "FragTrap Copy Constructor Called" << std::endl;
	*this = src;
}

FragTrap::FragTrap(std::string frag_name) : ClapTrap(frag_name) {
	std::cout << "FragTrap String Constructor Called" << std::endl;
	this->hp = 100;
	this->ep = 100;
	this->ad = 30;
}

FragTrap&	FragTrap::operator=(FragTrap const& src) {
	std::cout << "FragTrap Copy Assignment Operator Called" << std::endl;
	if (this != &src) {
		this->name = src.name;
		this->hp = src.hp;
		this->ep = src.ep;
		this->ad = src.ad;
	}
	return *this;
}
void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap highFivesGuys() Called" << std::endl;
	if (this->ep > 0 && this->hp > 0) {
		std::cout << this->name;
		std::cout << ": Asking high-five to others" << std::endl;
	}
	else {
		std::cout << "FragTrap " << this->name;
		std::cout << " can't do anything: Not enough HP(or Ep)" << std::endl;
	}
}
