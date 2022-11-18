#include "Point.hpp"

Point::Point() : x(0), y(0) {
}

Point::Point(Fixed const a, Fixed const b) : x(a), y(b) {
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
	if (this != &src) {
		Point	temp(src.x, src.y);
		*this = temp;
	}
	return *this;
}
