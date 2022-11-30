#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void) {
	const	Animal*	meta = new Animal();
	const	Animal*	j = new Dog();
	const	Animal*	i = new Cat();

	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	meta->makeSound();
	j->makeSound();
	i->makeSound();
	return 0;
}
