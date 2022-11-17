#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : hit_point(10), energy_point(10), attack_damage(10) {
	std::cout << "ClapTrap Default Constructor called" << std::endl;
	this->name = name;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src) {
	std::cout << "ClapTrap Copy Constructor called" << std::endl;
	*this = src;
}
void	ClapTrap::attack(const std::string& target) {
	if (this->energy_point > 0 && this->hit_point > 0) {
		this->energy_point -= 1;
		std::cout << "ClapTrap " << this->name;
		std::cout << " attacks " << target;
		std::cout << ", causing " << this->attack_damage;
		std::cout << " points of damage!" << std::endl;
	}
	else {
		std::cout << "ClapTrap " << this->name;
		std::cout << " Can't do anything because of its energy point!" << std::endl;
	}
}
void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->hit_point >= amount) {
		this->hit_point -= amount;
		std::cout << "ClapTrap " << this->name;
		std::cout << " took " << amount << " damage!" << std::endl;
	}
	else {
		std::cout << "Overkill: ClapTrap " << this->name;
		std::cout << " took " << amount << "(" << amount - this->hit_point << ")";
		std::cout << " damage!" << std::endl;
		this->hit_point = 0;
	}
}
void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->energy_point > 0 && this->hit_point > 0) {
		this->energy_point -= 0;
		this->hit_point += amount;
		std::cout << "ClapTrap " << this->name;
		std::cout << " repaired it self! ";
		std::cout << ": " << amount << " point" << std::endl;
	}
	else {
		std::cout << "ClapTrap " << this->name;
		std::cout << " Can't do anything because of its energy point!" << std::endl;
	}
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& src) {
	if (this != &src) {
		this->name = src.name;
		this->hit_point = src.hit_point;
		this->attack_damage = src.attack_damage;
		this->energy_point = src.energy_point;
	}
	return *this;
}
