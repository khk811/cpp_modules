#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain*	cat_brain;
public:
	Cat();
	Cat(Cat const& src);
	~Cat();
	void	makeSound() const;
	Cat&	operator=(Cat const& src);
};

#endif
