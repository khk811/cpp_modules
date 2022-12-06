#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"

class Cat : public AAnimal
{
private:
	Brain*	cat_brain;
public:
	Cat();
	Cat(Cat const& src);
	~Cat();
	void	makeSound() const;
	Brain*	getBrain() const;
	Cat&	operator=(Cat const& src);
};

#endif
