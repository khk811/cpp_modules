#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog Default Constructor Called" << std::endl;
	this->type = "Dog";
	this->dog_brain = new Brain();
}

Dog::Dog(Dog const& src) {
	std::cout << "Dog Copy Constructor Called" << std::endl;
	*this = src;
}

Dog::~Dog() {
	delete this->dog_brain;
	std::cout << "Dog Destructor Called" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "Dog makeSound() Called" << std::endl;
	std::cout << "Woof Woof" << std::endl;
}

Dog&	Dog::operator=(Dog const& src) {
	std::cout << "Dog Copy Assignment Operator Called" << std::endl;
	if (this != &src) {
		this->type = src.type;
		// need deep copy of brain arr;
	}
	return *this;
}
