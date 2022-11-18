#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->fixed_point = 0;
}

Fixed::Fixed(Fixed const& src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(int const src) {
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point = src * (1 << this->fraction_bits);
}

Fixed::Fixed(float const src) {
	std::cout << "Float constructor called" << std::endl;
	this->fixed_point = roundf(src * (1 << this->fraction_bits));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixed_point;
}

void	Fixed::setRawBits(int const src) {
	std::cout << "setRawBits member function called" << std::endl;
	this->fixed_point = src;
}

float	Fixed::toFloat(void) const {
	float	ret = 0;
	float	add = FIX_UNIT;
	int		raw_bit = this->fixed_point;
	bool	is_negative = false;

	if (raw_bit < 0)
		is_negative = true;
	for (int i = 0; i < 32; i++) {
		if ((raw_bit & 1) == 1) {
			ret += add;
			add *= 2;
		}
		else {
			add *= 2;
		}
		raw_bit = raw_bit / 2;
	}
	if (is_negative == true)
		ret *= -1;
	return ret;
}

int		Fixed::toInt(void) const {
	return (this->fixed_point / (1 << this->fraction_bits));
}

Fixed&	Fixed::operator=(Fixed const& src) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->fixed_point = src.getRawBits();
	return *this;
}

std::ostream&	operator<<(std::ostream& ostrm, Fixed const& src) {
	ostrm << src.toFloat();
	return ostrm;
}
