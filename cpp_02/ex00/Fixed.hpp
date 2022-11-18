#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int					fixed_point;
	static int const	fraction_bits = 8;
public:
	Fixed();
	Fixed(Fixed const& src);
	~Fixed();
	int					getRawBits(void) const;
	void				setRawBits(int const raw);

	Fixed&				operator=(Fixed const& src);
};

#endif
