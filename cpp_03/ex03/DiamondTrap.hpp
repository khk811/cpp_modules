#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string		name;
public:
	DiamondTrap();
	DiamondTrap(DiamondTrap const& src);
	DiamondTrap(std::string dia_name);
	~DiamondTrap();
	void 			whoAmI();
	DiamondTrap&	operator=(DiamondTrap const& src);
};


#endif
