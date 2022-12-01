#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void test(void) {
	Animal*		les_animaux[4];

	for (size_t i = 0; i < 4; i++)
	{
		if (0 <= i && i < 2) {
			les_animaux[i] = new Dog();
		}
		else {
			les_animaux[i] = new Cat();
		}
	}
	for (size_t i = 0; i < 4; i++)
	{
		les_animaux[i]->makeSound();
	}
	for (size_t i = 0; i < 4; i++)
	{
		delete les_animaux[i];
	}
}

int	main(void) {
	test();
	system("leaks a.out");
	return 0;
}
