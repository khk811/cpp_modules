#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"

class Dog : public AAnimal
{
private:
	Brain*	dog_brain;
public:
	Dog();
	Dog(Dog const& src);
	~Dog();
	void	makeSound() const;
	Brain*	getBrain() const;
	Dog&	operator=(Dog const& src);
};

#endif
