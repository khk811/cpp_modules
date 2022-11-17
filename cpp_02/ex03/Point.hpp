#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	Fixed const x;
	Fixed const y;
public:
	Point();
	Point(Fixed const a, Fixed const b);
	Point(const Point& src);
	~Point();

	float	getPointX(void) const;
	float	getPointY(void) const;
	Point&	operator=(Point const& src);
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif