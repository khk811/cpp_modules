#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class AAnimal
{
protected:
	std::string		type;
public:
	AAnimal();
	AAnimal(AAnimal const& src);
	virtual			~AAnimal();
	AAnimal&		operator=(AAnimal const &src);
	std::string		getType() const;
	virtual Brain*	getBrain() const = 0;
	virtual void	makeSound() const = 0;
};


#endif
