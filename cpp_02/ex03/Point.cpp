#include "Point.hpp"

Point::Point() : x(0), y(0) {
}

Point::Point(float const a, float const b) : x(a), y(b) {
}

Point::Point(Point const& src) {
	*this = src;
}

Point::~Point() {
}

Fixed const&	Point::getFixedPointX() const {
	return this->x;
}
Fixed const&	Point::getFixedPointY(void) const {
	return this->y;
}

Point&	Point::operator=(Point const& src) {
	(void)src;
	return *this;
}
