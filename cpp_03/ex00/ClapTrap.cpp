#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "ClapTrap Default Constructor called" << std::endl;
	this->name = "[Untitled]";
	this->hp = 10;
	this->ep = 10;
	this->ad = 0;
}

ClapTrap::ClapTrap(std::string name) {
	std::cout << "ClapTrap String Constructor called" << std::endl;
	this->name = name;
	this->hp = 10;
	this->ep = 10;
	this->ad = 0;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& src) {
	std::cout << "ClapTrap Copy Constructor called" << std::endl;
	*this = src;
}
void	ClapTrap::attack(std::string const& target) {
	if (this->ep > 0 && this->hp > 0) {
		this->ep -= 1;
		std::cout << "ClapTrap " << this->name;
		std::cout << " attacks " << target;
		std::cout << ", causing " << this->ad;
		std::cout << " points of damage!" << std::endl;
	}
	else {
		std::cout << "ClapTrap " << this->name;
		std::cout << " Can't do anything because of its energy point!" << std::endl;
	}
}
void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->hp >= amount) {
		this->hp -= amount;
		std::cout << "ClapTrap " << this->name;
		std::cout << " took " << amount << " damage!" << std::endl;
	}
	else {
		std::cout << "Overkill: ClapTrap " << this->name;
		std::cout << " took " << amount << "(" << amount - this->hp << ")";
		std::cout << " damage!" << std::endl;
		this->hp = 0;
	}
}
void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->ep > 0 && this->hp > 0) {
		this->ep -= 0;
		this->hp += amount;
		std::cout << "ClapTrap " << this->name;
		std::cout << " repaired it self! ";
		std::cout << ": " << amount << " point" << std::endl;
	}
	else {
		std::cout << "ClapTrap " << this->name;
		std::cout << " Can't do anything because of its energy point!" << std::endl;
	}
}

std::string		ClapTrap::getClapTrapName() const {
	return this->name;
}

unsigned int	ClapTrap::getClapTrapHP() const {
	return this->hp;
}

unsigned int	ClapTrap::getClapTrapEP() const {
	return this->ep;
}

unsigned int	ClapTrap::getClapTrapAD() const {
	return this->ad;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const& src) {
	if (this != &src) {
		this->name = src.name;
		this->hp = src.hp;
		this->ad = src.ad;
		this->ep = src.ep;
	}
	return *this;
}
