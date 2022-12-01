#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(Ice const &src);
	~Ice();
	AMateria*	clone() const;
	void		use(ICharacter& target);
	Ice&		operator=(Ice const& src);
};

#endif
