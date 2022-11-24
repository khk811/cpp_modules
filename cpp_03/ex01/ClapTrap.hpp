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

	std::string		getClapTrapName() const;
	void			setClapTrapName(std::string new_name);
	unsigned int	getClapTrapHP() const;
	void			setClapTrapHP(unsigned int new_hp);
	unsigned int	getClapTrapEP() const;
	void			setClapTrapEP(unsigned int new_ep);
	unsigned int	getClapTrapAD() const;
	void			setClapTrapAD(unsigned int new_ad);

	ClapTrap&		operator=(ClapTrap const& src);
};

#endif
