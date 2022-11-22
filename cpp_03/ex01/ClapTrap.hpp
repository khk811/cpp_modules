#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
private:
	unsigned int	hit_point;
	unsigned int	energy_point;
	unsigned int	attack_damage;
protected:
	std::string		clap_name;
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& src);
	~ClapTrap();
	void			attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

	ClapTrap&		operator=(const ClapTrap& src);
};

#endif
