#pragma once
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
private:
	Weapon*	_weapon;
	std::string	_name;

public:
	HumanB(std::string name);
	~HumanB();
	void	setWeapon(Weapon& weapon);
	std::string	getWeapon() const;
	void	attack();
};

#endif
