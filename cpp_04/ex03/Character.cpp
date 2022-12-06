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
	this->name = src.name;
	for (int i = 0; i < 4; i++)
	{
		if (src.inventory[i] != NULL) {
			this->inventory[i] = src.inventory[i]->clone();
		}
		else {
			this->inventory[i] = NULL;
		}
	}
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
			std::cout << this->name << " equiped " << m->getType() << std::endl;
			return;
		}
	}
}

void	Character::unequip(int idx) {
	if ((0 <= idx && idx < 4) && this->inventory[idx] != NULL) {
		std::cout << this->name << " unequiped " << this->inventory[idx]->getType() << std::endl;
		this->inventory[idx] = NULL;
		return;
	}
}

void	Character::use(int idx, ICharacter& target) {
	if ((0 <= idx && idx < 4) && this->inventory[idx] != NULL) {
		this->inventory[idx]->use(target);
		return;
	}
}

Character&	Character::operator=(Character const& src) {
	std::cout << "Character Copy Assignment Operator Called" << std::endl;
	if (this != &src) {
		this->name = src.name;
		for (int i = 0; i < 4; i++)
		{
			if (src.inventory[i] != NULL) {
				if (this->inventory[i] != NULL) {
					delete this->inventory[i];
				}
				this->inventory[i] = src.inventory[i]->clone();
			}
			else {
				if (this->inventory[i] != NULL) {
					delete this->inventory[i];
				}
				this->inventory[i] = NULL;
			}
		}

	}
	return *this;
}
