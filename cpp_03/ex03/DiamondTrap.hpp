#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap
{
private:
	std::string	name;
public:
	DiamondTrap();
	DiamondTrap(DiamondTrap const& src);
	~DiamondTrap();
	DiamondTrap&	operator=(DiamondTrap const& src);
};


#endif
