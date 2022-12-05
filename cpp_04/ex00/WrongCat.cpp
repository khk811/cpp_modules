#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "WrongCat Default Constructor Called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const& src) {
	std::cout << "WrongCat Copy Constructor Called" << std::endl;
	*this = src;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat Destructor Called" << std::endl;
}

void	WrongCat::makeSound() const {
	std::cout << "WrongCat makeSound() Called" << std::endl;
	std::cout << "Meow Meow" << std::endl;
}

WrongCat&	WrongCat::operator=(WrongCat const& src) {
	std::cout << "WrongCat Copy Assignment Operator Called" << std::endl;
	if (this != &src) {
		this->type = src.type;
	}
	return *this;
}
