#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected:
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

	std::string		getClapTrapName() const;
	unsigned int	getClapTrapHP() const;
	unsigned int	getClapTrapEP() const;
	unsigned int	getClapTrapAD() const;

	ClapTrap&		operator=(ClapTrap const& src);
};

#endif
