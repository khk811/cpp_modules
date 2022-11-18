#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	Fixed	a_x(a.getFixedPointX());
	Fixed	a_y(a.getFixedPointY());
	Fixed	b_x(b.getFixedPointX());
	Fixed	b_y(b.getFixedPointY());
	Fixed	c_x(c.getFixedPointX());
	Fixed	c_y(c.getFixedPointY());
	Fixed	p_x(point.getFixedPointX());
	Fixed	p_y(point.getFixedPointY());

	Fixed	det = (b_y - c_y)*(a_x - c_x) + (c_x - b_x)*(a_y - c_y);

	Fixed	alpha = ((b_y - c_y)*(p_x - c_x) + (c_x - b_x)*(p_y - c_y)) / det;
	Fixed	beta = ((c_y - a_y)*(p_x - c_x) + (a_x - c_x)*(p_y - c_y)) / det;
	Fixed	gamma = Fixed(1) - alpha - beta;

	Fixed	zero(0);

	if (alpha > zero && beta > zero && gamma > zero)
		return true;
	else
		return false;
}
