#include "Point.hpp"

static Fixed independentTerm(const Point& v, const Point& p) {
	return (v.getX() * p.getY() - v.getY() * p.getX());
}

static Fixed substituteInEq(const Point& v, const Fixed& indep, const Point& subs) {
	return (v.getY() * subs.getX() - v.getX() * subs.getY() + indep);
}

static bool isInSame(const Point& g1, const Point& g2, const Point& p1, const Point& p2) {
	Point v = g1 - g2;
	Fixed in = independentTerm(v, g1);

	return (substituteInEq(v, in, p1) * substituteInEq(v, in, p2) > 0);
}

//Returns: 	true if the point is inside the triangle, false otherwise.
//			If the point is a vertex or on edge, it will return false.
bool bsp(Point const a, Point const b, Point const c, Point const point) {
	return isInSame(a, b, c, point) && isInSame(a, c, b, point) && isInSame(b, c, a, point);
}
