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
	this->fixed_point = src * 256;
}

Fixed::Fixed(const float src) {
	std::cout << "Float constructor called" << std::endl;
	this->fixed_point = roundf(src * 256);
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
	return (this->fixed_point / 256);
}

Fixed&	Fixed::operator=(Fixed const& src) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->fixed_point = src.getRawBits();
	return *this;
}

bool	Fixed::operator>(Fixed const& src) {
	if (this->fixed_point > src.fixed_point)
		return true;
	else
		return false;
}

bool	Fixed::operator>=(Fixed const& src) {
	if (this->fixed_point >= src.fixed_point)
		return true;
	else
		return false;
}

bool	Fixed::operator<(Fixed const& src) {
	if (this->fixed_point < src.fixed_point)
		return true;
	else
		return false;
}

bool	Fixed::operator<=(Fixed const& src) {
	if (this->fixed_point <= src.fixed_point)
		return true;
	else
		return false;
}

bool	Fixed::operator==(Fixed const& src) {
	if (this->fixed_point == src.fixed_point)
		return true;
	else
		return false;
}

bool	Fixed::operator!=(Fixed const& src) {
	if (this->fixed_point != src.fixed_point)
		return true;
	else
		return false;
}

Fixed	Fixed::operator+(Fixed const& src) {
	return Fixed(this->toFloat() + src.toFloat());
}

Fixed	Fixed::operator-(Fixed const& src) {
	return Fixed(this->toFloat() - src.toFloat());
}

Fixed	Fixed::operator*(Fixed const& src) {
	return Fixed(this->toFloat() * src.toFloat());
}

Fixed	Fixed::operator/(Fixed const& src) {
	return Fixed(this->toFloat() / src.toFloat());
}

Fixed&	Fixed::operator++(void) {
	this->fixed_point += 1;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed	temp(*this);

	this->fixed_point += 1;
	return temp;
}

Fixed&	Fixed::operator--(void) {
	this->fixed_point -= 1;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed	temp(*this);

	this->fixed_point -= 1;
	return temp;
}

const Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	if (a.fixed_point > b.fixed_point)
		return b;
	else
		return a;
}

const Fixed&	Fixed::min(Fixed const& a, Fixed const& b) {
	if (a.fixed_point > b.fixed_point)
		return b;
	else
		return a;
}

const Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	if (a.fixed_point > b.fixed_point)
		return a;
	else
		return b;
}

const Fixed&	Fixed::max(Fixed const& a, Fixed const& b) {
	if (a.fixed_point > b.fixed_point)
		return a;
	else
		return b;
}

std::ostream&	operator<<(std::ostream& ostr, const Fixed& src) {
	ostr << src.toFloat();
	return ostr;
}
