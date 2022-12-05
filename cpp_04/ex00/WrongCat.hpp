#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(WrongCat const& src);
	~WrongCat();
	void	makeSound() const;
	WrongCat&	operator=(WrongCat const& src);
};

#endif
