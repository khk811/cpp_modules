#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

#define	FIX_EPSILON	0.00390625;

class Fixed
{
private:
	int					fixed_point;
	static int const	fraction_bits = 8;

public:
	Fixed();
	Fixed(Fixed const& src);
	Fixed(int const src);
	Fixed(float const src);
	~Fixed();
	int					getRawBits(void) const;
	void				setRawBits(int const raw);
	float				toFloat(void) const;
	int					toInt(void) const;

	Fixed&				operator=(Fixed const& src);
};

std::ostream&		operator<<(std::ostream& ostrm, Fixed const& src);

#endif
