#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->fixed_point = 0;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed& fix) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fix;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixed_point;
}

void	Fixed::setRawBits(int const src) {
	std::cout << "setRawBits member function called" << std::endl;
	this->fixed_point = src;
}

Fixed&	Fixed::operator=(Fixed const& src) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->fixed_point = src.getRawBits();
	return *this;
}
