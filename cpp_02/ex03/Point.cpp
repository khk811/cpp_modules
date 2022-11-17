#include "Point.hpp"

Point::Point() : x(0), y(0) {
}

Point::Point(Fixed const a, Fixed const b) : x(a), y(b) {
}

Point::Point(const Point& src) {
	*this = src;
}

Point::~Point() {
}

float	Point::getPointX(void) const {
	return this->x.toFloat();
}
float	Point::getPointY(void) const {
	return this->y.toFloat();
}

Point&	Point::operator=(Point const& src) {
	if (this != &src) {
		Point	temp(src.x, src.y);
		*this = temp;
	}
	return *this;
}
