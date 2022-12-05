#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog Default Constructor Called" << std::endl;
	this->type = "Dog";
	this->dog_brain = new Brain();
}

Dog::Dog(Dog const& src) {
	std::cout << "Dog Copy Constructor Called" << std::endl;
	this->dog_brain = new Brain();
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

Brain*	Dog::getBrain() const {
	return this->dog_brain;
}

Dog&	Dog::operator=(Dog const& src) {
	std::cout << "Dog Copy Assignment Operator Called" << std::endl;
	if (this != &src) {
		this->type = src.type;
		*(this->dog_brain) = *(src.dog_brain);
	}
	return *this;
}
