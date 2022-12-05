#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
// #include "Brain.hpp"

class Dog : public Animal
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
