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
	void			setClapTrapName(std::string new_name);
	unsigned int	getClapTrapHP();
	void			setClapTrapHP(unsigned int new_hp);
	unsigned int	getClapTrapEP();
	void			setClapTrapEP(unsigned int new_ep);
	unsigned int	getClapTrapAD();
	void			setClapTrapAD(unsigned int new_ad);

	ClapTrap&		operator=(ClapTrap const& src);
};

#endif
