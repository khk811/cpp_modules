#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
private:
	std::string		name;
	unsigned int	hp;
	unsigned int	ep;
	unsigned int	ad;
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const& src);
	~ClapTrap();
	void			attack(std::string const& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

	std::string		getClapTrapName();
	unsigned int	getClapTrapHP();
	unsigned int	getClapTrapEP();
	unsigned int	getClapTrapAD();

	ClapTrap&		operator=(ClapTrap const& src);
};

#endif
