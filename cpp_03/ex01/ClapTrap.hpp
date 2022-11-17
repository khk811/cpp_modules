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
	ClapTrap(const ClapTrap& src);
	~ClapTrap();
	void			attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

	ClapTrap&		operator=(const ClapTrap& src);
};

#endif
