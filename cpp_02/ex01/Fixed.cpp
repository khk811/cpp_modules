#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->fixed_point = 0;
}

Fixed::Fixed(const Fixed& fix) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fix;
}

Fixed::Fixed(const int src) {
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point = src << this->fraction_bits;
}

Fixed::Fixed(const float src) {
	std::cout << "Float constructor called" << std::endl;
	this->fixed_point = roundf(src);

	float	src_frac = src - roundf(src);
	std::cout << src_frac << std::endl;
	float	subtrac = 0.5;

	for (int i = 0; i < this->fraction_bits; i++)
	{
		// std::cout << subtrac << std::endl;
		if (src_frac - subtrac >= 0) {
			this->fixed_point  = this->fixed_point << 1;
			this->fixed_point += 1;
			src_frac = src_frac - subtrac;
			subtrac *= 0.5;
		}
		else {
			this->fixed_point  = this->fixed_point << 1;
			subtrac *= 0.5;
		}
	}
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
	float	add = 0.00390625;
	int		raw_bit = this->fixed_point;

	for (int i = 0; i < 32; i++) {
		if ((raw_bit & 1) == 1) {
			ret += add;
			add *= 2;
		}
		else {
			add *= 2;
		}
		raw_bit = raw_bit >> 1;
	}
	return ret;
}

int		Fixed::toInt(void) const {
	return (this->fixed_point >> this->fraction_bits);
}

Fixed&	Fixed::operator=(Fixed const& src) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->fixed_point = src.getRawBits();
	return *this;
}

std::ostream&	operator<<(std::ostream& ostr, const Fixed& src) {
	ostr << src.toFloat();
	return ostr;
}
