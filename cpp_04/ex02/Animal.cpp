#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal Default Constructor Called" << std::endl;
	this->type = "(null)";
}

Animal::~Animal() {
	std::cout << "Animal Destructor Called" << std::endl;
}

Animal::Animal(Animal const& src) {
	std::cout << "Animal Copy Constructor Called" << std::endl;
	*this = src;
}

void	Animal::makeSound() const {
	std::cout << "Animal makesound() Called" << std::endl;
	std::cout << "( insert Animal sound here )" << std::endl;
}

std::string	Animal::getType() const {
	return this->type;
}

Animal&		Animal::operator=(Animal const &src) {
	std::cout << "Animal Copy Assignment Operator Called" << std::endl;
	if (this != &src) {
		this->type = src.type;
	}
	return *this;
}
