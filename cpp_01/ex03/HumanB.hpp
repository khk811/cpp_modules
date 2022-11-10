#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
	Weapon*		weapon;
	std::string	name;

	std::string	getName();
	Weapon*		getWeapon();

public:
	HumanB(std::string name);
	~HumanB();
	void		setWeapon(Weapon& weapon);
	void		attack();
};

#endif
