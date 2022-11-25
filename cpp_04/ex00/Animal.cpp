#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal Default Constructor Called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal Destructor Called" << std::endl;
}

Animal::Animal(Animal const& src) {
	std::cout << "Animal Copy Constructor Called" << std::endl;
	*this = src;
}

Animal&		Animal::operator=(Animal const &src) {
	std::cout << "Animal Copy Assignment Operator Called" << std::endl;
	if (this != &src) {
		this->type = src.type;
	}
	return *this;
}
