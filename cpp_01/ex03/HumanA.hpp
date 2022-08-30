#pragma once
#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
private:
	Weapon&	_weapon;
	std::string	_name;

public:
	HumanA(std::string name, Weapon& wp);
	~HumanA();
	void	attack();
};

#endif
