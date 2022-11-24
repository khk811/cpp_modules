#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
private:
	std::string		name;
	unsigned int	hit_point;
	unsigned int	energy_point;
	unsigned int	attack_damage;
public:
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const& src);
	~ClapTrap();
	void			attack(std::string const& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

	ClapTrap&		operator=(ClapTrap const& src);
};

#endif
