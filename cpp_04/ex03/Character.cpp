#include "Character.hpp"

Character::Character() {
	std::cout << "Character Default Constructor Called" << std::endl;
	this->name = "[No_name]";
	for (int i = 0; i < 4; i++)
	{
		this->inventory[i] = NULL;
	}
}

Character::Character(Character const& src) {
	std::cout << "Character Copy Constructor Called" << std::endl;
	*this = src;
	// need deep cp;
}

Character::Character(std::string chr_name) {
	std::cout << "Character String Constructor Called" << std::endl;
	this->name = chr_name;
	for (int i = 0; i < 4; i++)
	{
		this->inventory[i] = NULL;
	}
}

Character::~Character() {
	std::cout << "Character Destructor Called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] != NULL) {
			delete this->inventory[i];
		}
	}
}

std::string const& Character::getName() const {
	return this->name;
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL) {
			this->inventory[i] = m;
			break;
		}
	}
}

void	Character::unequip(int idx) {
	if ((0 <= idx && idx < 4) && this->inventory[idx] != NULL) {
		this->inventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target) {
	if ((0 <= idx && idx < 4) && this->inventory[idx] != NULL) {
		this->inventory[idx]->use(target);
	}
}

Character&	Character::operator=(Character const& src) {
	std::cout << "Character Copy Assignment Operator Called" << std::endl;
	if (this != &src) {
		this->name = src.name;
		// need deep cp;
	}
	return *this;
}
