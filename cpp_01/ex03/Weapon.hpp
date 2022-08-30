#pragma once
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {

private:
	std::string	_type;

public:
	Weapon(std::string type);
	Weapon();
	~Weapon();
	std::string	getType() const;
	void		setType(std::string type);
};

#endif
