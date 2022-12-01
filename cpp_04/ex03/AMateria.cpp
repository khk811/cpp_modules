#include "AMateria.hpp"

AMateria::AMateria() {
	std::cout << "AMateria Default Constructor Called" << std::endl;
}

AMateria::AMateria(AMateria const& src) {
	std::cout << "AMateria Copy Constructor Called" << std::endl;
	*this = src;

}

AMateria::AMateria(std::string const& type) {
	std::cout << "AMateria String Constructor Called" << std::endl;
	this->type = type;
}

AMateria::~AMateria() {
	std::cout << "AMateria Destructor Called" << std::endl;
}

std::string const&	AMateria::getType() const {
	return this->type;
}

// virtual void		AMateria::use(ICharacter& target);

AMateria&	AMateria::operator=(AMateria const& src) {
	std::cout << "AMateria Default Constructor Called" << std::endl;
	if (this != &src) {
		this->type = src.type;
	}
	return *this;
}
