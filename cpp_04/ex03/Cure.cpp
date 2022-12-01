#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "Cure Default Constructor Called" << std::endl;
}

Cure::Cure(Cure const& src) {
	std::cout << "Cure Copy Constructor Called" << std::endl;
	*this = src;
}

Cure::~Cure() {
	std::cout << "Cure Destructor Called" << std::endl;
}

AMateria*	Cure::clone() const {
	return new Cure();
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals "<< target.getName() << "'s wounds *" << std::endl;
}

Cure&	Cure::operator=(Cure const& src) {
	std::cout << "Cure Copy Assignment Operator Called" << std::endl;
	if (this != &src) {
		this->type = src.type;
	}
	return *this;
}
