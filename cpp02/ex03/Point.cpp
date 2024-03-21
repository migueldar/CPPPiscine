#include "Point.hpp"

Point::Point() {
	// std::cout << "Point default constructor called" << std::endl;
}

Point::Point(const float a, const float b): x(Fixed(a)), y(Fixed(b)) {
	// std::cout << "Point param constructor called" << std::endl;
}

Point::Point(Point const& other): x(other.x), y(other.y) {
	// std::cout << "Point copy constructor called" << std::endl;
	*this = other;
}

Point::~Point() {
	// std::cout << "Point destructor called" << std::endl;
}

Point& Point::operator=(Point const& rhs) {
	(void) rhs;
	// std::cout << "Point assignment operator called" << std::endl;
	return (*this);
}

Point Point::operator-(Point const& rhs) const {
	return Point((this->x - rhs.x).toFloat(), (this->y - rhs.y).toFloat());
}

const Fixed& Point::getX() const {
	return x;
}

const Fixed& Point::getY() const {
	return y;
}

std::ostream& operator<<(std::ostream& o, Point const& prt) {
	o << '(' << prt.getX() << ", " << prt.getY() << ')';
	return (o);
}
