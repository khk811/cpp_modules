#include "AAnimal.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void	setAnimalArray(AAnimal** arr, int arr_size) {
	if (arr_size < 0)
		return;
	std::cout << "===AAnimal Array Construction===" << std::endl;
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

void	deleteAnimalArray(AAnimal** arr, int arr_size) {
	if (arr_size < 0)
		return ;
	std::cout << "===AAnimal Array Destruction===" << std::endl;
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
	AAnimal*	animal_arr[10];

	setAnimalArray(animal_arr, arr_size);

	std::cout << "\n===class Dog, class Cat Member Function Test===" << std::endl;
	// Animal class func test;
	std::cout << "---AAnimal Class member function test---" << std::endl;
	std::cout << "animal_arr[0] type: " << animal_arr[0]->getType() << std::endl;
	animal_arr[0]->makeSound();
	std::cout << "animal_arr[6] type: " << animal_arr[6]->getType() << std::endl;
	animal_arr[6]->makeSound();
	// getBrain(), setIdea(), printAllIdeas() test;
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
	std::cout << "\n===Deep Copy Test===" << std::endl;
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

void	instanceTest(void) {
	Dog			hot_dog;
	AAnimal*	hot_cat = new Cat();
	Animal		base_animal;
	// AAnimal		abstract_animal;

	std::cout << "\n===Instantiation Test===" << std::endl;
	std::cout << "---Class Dog Instantiation Test---" << std::endl;
	std::cout << "Dog hot_dog type: " << hot_dog.getType() << std::endl;
	hot_dog.makeSound();
	hot_dog.getBrain()->setIdea("ketchup please!");
	hot_dog.getBrain()->printAllIdeas();
	std::cout << "---Class Cat Instantiation Test---" << std::endl;
	std::cout << "Cat hot_cat type: " << hot_cat->getType() << std::endl;
	hot_cat->makeSound();
	hot_cat->getBrain()->setIdea("I'm not a hot dog");
	hot_cat->getBrain()->printAllIdeas();
	std::cout << "---Class Animal Instantiation Test---" << std::endl;
	std::cout << "Animal base_animal type: " << base_animal.getType() << std::endl;
	base_animal.makeSound();
	// std::cout << "---Class AAnimal Instantiation Test---" << std::endl;
	// std::cout << "AAnimal abstract_animal type: " << abstract_animal.getType() << std::endl;
	// abstract_animal.makeSound();
	delete hot_cat;
}

int	main(void) {
	classMemberFuncTest();
	deepCopyTest();
	instanceTest();
	std::cout << "\n=== Check Memory Leaks ===" << std::endl;
	system("leaks a.out");
	return 0;
}
