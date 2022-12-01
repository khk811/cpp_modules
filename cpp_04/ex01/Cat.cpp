#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat Default Constructor Called" << std::endl;
	this->type = "Cat";
	this->cat_brain = new Brain();
}

Cat::Cat(Cat const& src) {
	std::cout << "Cat Copy Constructor Called" << std::endl;
	*this = src;
}

Cat::~Cat() {
	delete this->cat_brain;
	std::cout << "Cat Destructor Called" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "Cat makeSound() Called" << std::endl;
	std::cout << "Meow Meow" << std::endl;
}

Cat&	Cat::operator=(Cat const& src) {
	std::cout << "Cat Copy Assignment Operator Called" << std::endl;
	if (this != &src) {
		this->type = src.type;
		// need deep copy of brain arr;
	}
	return *this;
}
