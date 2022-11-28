#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(FragTrap const& src);
	FragTrap(std::string frag_name);
	~FragTrap();
	FragTrap&		operator=(FragTrap const& src);
	void			highFivesGuys(void);
};


#endif
