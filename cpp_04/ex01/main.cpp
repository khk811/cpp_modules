#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void	setAnimalArray(Animal** arr, int arr_size) {
	if (arr_size < 0)
		return;
	std::cout << "===Animal Array Construction===" << std::endl;
	for (int i = 0; i < arr_size; i++)
	{
		if (0 <= i && i < (arr_size / 2)) {
			std::cout << "Dog[" << i << "] created"  << std::endl;
			arr[i] = new Dog();
		}
		else {
			std::cout << "Cat[" << i << "] created"  << std::endl;
			arr[i] = new Cat();
		}
	}
}

void	deleteAnimalArray(Animal** arr, int arr_size) {
	if (arr_size < 0)
		return ;
	std::cout << "===Animal Array Destruction===" << std::endl;
	for (int i = 0; i < arr_size; i++)
	{
		if (arr[i]->getType() == "Dog") {
			std::cout << "Dog[" << i << "] deleted"  << std::endl;
		}
		else {
			std::cout << "Cat[" << i << "] deleted"  << std::endl;
		}
		delete arr[i];
	}
}

void	classMemberFuncTest(void) {
	int		arr_size = 10;
	Animal*	animal_arr[arr_size];

	setAnimalArray(animal_arr, arr_size);

	std::cout << "===class Dog, class Cat Member Function Test===" << std::endl;
	// setIdea(), printAllIdeas() test;
	std::cout << "---basic setIdea(), printAllIdeas() test---" << std::endl;
	animal_arr[0]->getBrain()->printAllIdeas();
	animal_arr[2]->getBrain()->setIdea("Need to chaise squarrel!!");
	animal_arr[2]->getBrain()->printAllIdeas();
	animal_arr[7]->getBrain()->setIdea("I'm a lucky cat");
	animal_arr[7]->getBrain()->printAllIdeas();

	// setIdea to 100, check the brain is full or not;
	std::cout << "---check Brain array---" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		animal_arr[1]->getBrain()->setIdea("STOP THINKING");
	}
	animal_arr[1]->getBrain()->setIdea("STOP THINKING");
	animal_arr[1]->getBrain()->printAllIdeas();

	deleteAnimalArray(animal_arr, arr_size);
}

void	deepCopyTest(void) {
	// deep cp check;
	std::cout << "" << std::endl;
	std::cout << "===Deep Copy Test===" << std::endl;
	std::cout << "---Copy Assignment Operator test---" << std::endl;
	const Cat*	const_cat = new Cat();
	Cat*		copy_cat = new Cat();

	const_cat->getBrain()->setIdea("Hi! I'm Const cat");
	*(copy_cat) = *(const_cat);
	const_cat->getBrain()->printAllIdeas();
	copy_cat->getBrain()->printAllIdeas();
	std::cout << "const_cat's [0] idea: ";
	const_cat->getBrain()->printIdeaNAddr(0);
	std::cout << "copy_cat's [0] idea: ";
	copy_cat->getBrain()->printIdeaNAddr(0);
	std::cout << "const_cat's Brain address: " << const_cat->getBrain() << std::endl;
	std::cout << "copy_cat's Brain address: " << copy_cat->getBrain() << std::endl;

	std::cout << "---Copy Constructor test---" << std::endl;
	Cat*		clone_cat = new Cat(*(const_cat));

	clone_cat->getBrain()->printAllIdeas();
	std::cout << "clone_cat's [0] idea: ";
	clone_cat->getBrain()->printIdeaNAddr(0);
	std::cout << "const_cat's Brain address: " << const_cat->getBrain() << std::endl;
	std::cout << "clone_cat's Brain address: " << clone_cat->getBrain() << std::endl;

	delete const_cat;
	delete copy_cat;
	delete clone_cat;
}

int	main(void) {
	classMemberFuncTest();
	deepCopyTest();
	std::cout << "\n=== Check Memory Leaks ===" << std::endl;
	system("leaks a.out");
	return 0;
}
