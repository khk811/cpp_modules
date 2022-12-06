#include "AAnimal.hpp"

AAnimal::AAnimal() {
	std::cout << "AAnimal Default Constructor Called" << std::endl;
	this->type = "( insert animal type here )";
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal Destructor Called" << std::endl;
}

AAnimal::AAnimal(AAnimal const& src) {
	std::cout << "AAnimal Copy Constructor Called" << std::endl;
	*this = src;
}

std::string	AAnimal::getType() const {
	return this->type;
}

AAnimal&		AAnimal::operator=(AAnimal const &src) {
	std::cout << "AAnimal Copy Assignment Operator Called" << std::endl;
	if (this != &src) {
		this->type = src.type;
	}
	return *this;
}
