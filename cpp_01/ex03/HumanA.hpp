#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {

private:

	Weapon&	weapon;
	std::string	name;

	std::string	getName();
	Weapon&		getWeapon();

public:

	HumanA(std::string name, Weapon& wp);
	~HumanA();
	void		attack();

};

#endif
