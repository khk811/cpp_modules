#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void	exampleTest(void) {
	std::cout << "===Example Test===" << std::endl;
	const Animal*	meta = new Animal();
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	std::cout << "meta Type: "<< meta->getType() << " " << std::endl;
	std::cout << "j Type: "<< j->getType() << " " << std::endl;
	std::cout << "i Type: "<< i->getType() << " " << std::endl;
	meta->makeSound();
	j->makeSound();
	i->makeSound();

	delete meta;
	delete j;
	delete i;
}

void	copyTest(void) {
	std::cout << "\n===Copy Test===" << std::endl;
	const Animal*	meta = new Animal();
	Animal*			delta = new Cat();

	std::cout << "\n---Copy Assignment Operator (Animal to cat)---" << std::endl;
	*delta = *meta;
	std::cout << "delta Type: " << delta->getType() << std::endl;
	delta->makeSound();

	const Dog	gamma;
	const Dog	beta = Dog(gamma);

	std::cout << "\n---Copy Constructor Test---" << std::endl;
	std::cout << "gamma Type: "<< gamma.getType() << " " << std::endl;
	std::cout << "beta Type: "<< beta.getType() << " " << std::endl;
	gamma.makeSound();
	beta.makeSound();

	delete delta;
	delete meta;
}

void	wrongAnimalTest(void) {
	std::cout << "\n===WrongAnimal Test===" << std::endl;
	const WrongAnimal*	wrong_meta = new WrongAnimal();
	const WrongAnimal*	wrong_cat = new WrongCat();

	std::cout << "wrong_meta Type: " << wrong_meta->getType() << " " << std::endl;
	std::cout << "wrong_cat Type: " << wrong_cat->getType() << " " << std::endl;
	std::cout << "wrong_meta makeSound() test" << std::endl;
	wrong_meta->makeSound();
	std::cout << "wrong_cat makeSound() test" << std::endl;
	wrong_cat->makeSound();

	delete wrong_meta;
	delete wrong_cat;
}

int	main(void) {
	exampleTest();
	copyTest();
	wrongAnimalTest();
	std::cout << "\n===Check Memory Leaks===" << std::endl;
	system("leaks a.out");
	return 0;
}
