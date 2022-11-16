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
};

std::ostream&		operator<<(std::ostream& ostrm, const Fixed& src);

#endif
