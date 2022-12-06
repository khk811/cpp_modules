#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice Default Constructor Called" << std::endl;
}

Ice::Ice(Ice const& src) {
	std::cout << "Ice Copy Constructor Called" << std::endl;
	*this = src;
}

Ice::~Ice() {
	std::cout << "Ice Destructor Called" << std::endl;
}

AMateria*	Ice::clone() const {
	return new Ice();
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at "<< target.getName() << " *" << std::endl;
}

Ice&	Ice::operator=(Ice const& src) {
	std::cout << "Ice Copy Assignment Operator Called" << std::endl;
	(void)src;
	return *this;
}
