#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string	type;
public:
	AMateria();
	AMateria(AMateria const& src);
	AMateria(std::string const& type);
	std::string const&	getType() const; //Returns the materia type
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);
	virtual ~AMateria();
	AMateria&	operator=(AMateria const& src);
};


#endif
