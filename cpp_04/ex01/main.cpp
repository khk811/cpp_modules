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
	Animal*	animal_arr[10];

	setAnimalArray(animal_arr, arr_size);

	std::cout << "===class Dog, class Cat Member Function Test===" << std::endl;
	// Animal class func test;
	std::cout << "---Animal Class member function test---" << std::endl;
	std::cout << "animal_arr[0] type: " << animal_arr[0]->getType() << std::endl;
	animal_arr[0]->makeSound();
	std::cout << "animal_arr[6] type: " << animal_arr[6]->getType() << std::endl;
	animal_arr[6]->makeSound();
	// setIdea(), printAllIdeas() test;
	std::cout << "---basic setIdea(), printAllIdeas() test---" << std::endl;
	animal_arr[0]->getBrain()->printAllIdeas();
	animal_arr[2]->getBrain()->setIdea("Need to chaise squarrels!!");
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

void	extraTest(void) {
	std::cout << "\n===Extra Test: Up-casting, Down-casting===" << std::endl;
	std::cout << "---Up-casting---" << std::endl;
	Dog		hot_dog;
	Animal*	hot_animal = &(hot_dog); // upcasting;

	std::cout << "hot_dog type: " << hot_dog.getType() << std::endl;
	hot_dog.makeSound();
	std::cout << "hot_animal type: " << hot_animal->getType() << std::endl;
	hot_animal->makeSound();
	hot_animal->getBrain()->printAllIdeas();

	std::cout << "---Down-casting---" << std::endl;
	Dog*	cool_dog = (Dog*)hot_animal; // downcasting;

	std::cout << "cool_dog type: " << cool_dog->getType() << std::endl;
	cool_dog->makeSound();
}

int	main(void) {
	classMemberFuncTest();
	deepCopyTest();
	extraTest();
	std::cout << "\n=== Check Memory Leaks ===" << std::endl;
	system("leaks a.out");
	return 0;
}
