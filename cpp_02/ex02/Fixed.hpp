#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					fixed_point;
	static const int	fraction_bits = 8;

public:
	Fixed();
	Fixed(const Fixed& fix);
	Fixed(const int src);
	Fixed(const float src);
	~Fixed();
	int					getRawBits(void) const;
	void				setRawBits(int const raw);
	float				toFloat(void) const;
	int					toInt(void) const;

	Fixed&				operator=(Fixed const& src);

	bool				operator>(Fixed const& src);
	bool				operator>=(Fixed const& src);
	bool				operator<(Fixed const& src);
	bool				operator<=(Fixed const& src);
	bool				operator==(Fixed const& src);
	bool				operator!=(Fixed const& src);

	Fixed				operator+(Fixed const& src);
	Fixed				operator-(Fixed const& src);
	Fixed				operator*(Fixed const& src);
	Fixed				operator/(Fixed const& src);

	Fixed&				operator++(void);
	Fixed				operator++(int);
	Fixed&				operator--(void);
	Fixed				operator--(int);

	static const Fixed&	min(Fixed& a, Fixed& b);
	static const Fixed&	min(Fixed const& a, Fixed const& b);
	static const Fixed&	max(Fixed& a, Fixed& b);
	static const Fixed&	max(Fixed const& a, Fixed const& b);
};

std::ostream&		operator<<(std::ostream& ostrm, const Fixed& src);

#endif
