#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point {

private:
	const Fixed x;
	const Fixed y;

public:
	Point();
	Point(const float a, const float b);
	Point(Point const& other);
	~Point();
	Point &operator=(Point const& rhs);
	Point operator-(Point const& rhs) const;
	const Fixed& getX() const;
	const Fixed& getY() const;
};

std::ostream &operator<<(std::ostream &o, Point const &prt);
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
