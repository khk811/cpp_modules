#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal Default Constructor Called" << std::endl;
	this->type = "( insert WrongAnimal type here)";
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal Destructor Called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& src) {
	std::cout << "WrongAnimal Copy Constructor Called" << std::endl;
	*this = src;
}

void	WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal makesound() Called" << std::endl;
	std::cout << "( insert WrongAnimal sound here )" << std::endl;
}

std::string	WrongAnimal::getType() const {
	return this->type;
}

WrongAnimal&		WrongAnimal::operator=(WrongAnimal const &src) {
	std::cout << "WrongAnimal Copy Assignment Operator Called" << std::endl;
	if (this != &src) {
		this->type = src.type;
	}
	return *this;
}
