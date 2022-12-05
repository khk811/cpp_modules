#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void	exampleTest(void) {
	const Animal*	meta = new Animal();
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	std::cout << "meta Type: "<< meta->getType() << " " << std::endl;
	std::cout << "j Type: "<< j->getType() << " " << std::endl;
	std::cout << "i Type: "<< i->getType() << " " << std::endl;
	meta->makeSound();
	j->makeSound();
	i->makeSound();

	// add operator =, cp constructor, etc;
	Animal*	delta = new Cat();

	*delta = *meta;
	std::cout << "delta Type: " << delta->getType() << std::endl;
	delta->makeSound();

	const Dog	gamma;
	const Dog	beta = Dog(gamma);

	std::cout << "gamma Type: "<< gamma.getType() << " " << std::endl;
	std::cout << "beta Type: "<< beta.getType() << " " << std::endl;
	gamma.makeSound();
	beta.makeSound();

	delete delta;
	delete meta;
	delete j;
	delete i;
}

void	wrongAnimalTest(void) {
	const WrongAnimal*	wrong_meta = new WrongAnimal();
	const WrongAnimal*	wrong_cat = new WrongCat();

	std::cout << "wrong_meta Type: " << wrong_meta->getType() << " " << std::endl;
	std::cout << "wrong_cat Type: " << wrong_cat->getType() << " " << std::endl;
	wrong_meta->makeSound();
	wrong_cat->makeSound();

	delete wrong_meta;
	delete wrong_cat;
}

int	main(void) {
	exampleTest();
	wrongAnimalTest();
	system("leaks a.out | grep 'Process'");
	return 0;
}
