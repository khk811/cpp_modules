#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : hp(10), ep(10), ad(10) {
	std::cout << "ClapTrap Default Constructor called" << std::endl;
	this->name = name;
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

std::string		ClapTrap::getClapTrapName() {
	return this->name;
}

void			ClapTrap::setClapTrapName(std::string new_name) {
	this->name = new_name;
}

unsigned int	ClapTrap::getClapTrapHP() {
	return this->hp;
}

void			ClapTrap::setClapTrapHP(unsigned int new_hp) {
	this->hp = new_hp;
}

unsigned int	ClapTrap::getClapTrapEP() {
	return this->ep;
}

void			ClapTrap::setClapTrapEP(unsigned int new_ep) {
	this->ep = new_ep;
}

unsigned int	ClapTrap::getClapTrapAD() {
	return this->ad;
}

void			ClapTrap::setClapTrapAD(unsigned int new_ad) {
	this->ad = new_ad;
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
