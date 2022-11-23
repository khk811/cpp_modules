#include "FragTrap.hpp"


FragTrap::FragTrap() {
	std::cout << "FragTrap Default Constructor Called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Desstructor Called" << std::endl;
}

FragTrap::FragTrap(FragTrap const& src) {
	std::cout << "FragTrap Copy Constructor Called" << std::endl;
	*this = src;
}

FragTrap::FragTrap(std::string frag_name) {
	std::cout << "FragTrap String Constructor Called" << std::endl;
	clap_name = frag_name;
	this->hp = 100;
	this->ep = 100;
	this->ad = 30;
}

FragTrap&	FragTrap::operator=(FragTrap const& src) {
	std::cout << "FragTrap Copy Assignment Operator Called" << std::endl;
	if (this != &src)
	{
		this->name = src.name;
		this->hp = src.hp;
		this->ep = src.ep;
		this->ad = src.ad;
	}
	return *this;
}
void	FragTrap::highFivesGuys(void) {
	std::cout << "ASKING HIGH FIVE MAN!!!!" << std::endl;
}
