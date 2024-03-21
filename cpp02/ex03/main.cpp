#include "Point.hpp"

int main() {
	{
		Point a(1, 0);
		Point b(0, 0);
		Point c(0, 1);
		Point point1(0.2, 0.2);
		Point point2(0.5, 0.5);
		std::cout << "P1: " << bsp(a, b, c, point1) << std::endl;
		std::cout << "P2: " << bsp(a, b, c, point2) << std::endl;
	}
	{
		Point a(1, 1);
		Point b(2, 2);
		Point c(3, 3);
		Point point(2, 2);
		std::cout << "P3: " << bsp(a, b, c, point) << std::endl;
	}
	{
		Point a(1, 1);
		Point b(1, 1);
		Point c(1, 1);
		Point point(1, 1);
		std::cout << "P4: " << bsp(a, b, c, point) << std::endl;
	}
	{
		Point a(1, 1);
		Point b(2, 4);
		Point c(4, 1);
		Point point1(2, 2);
		Point point2(3, 3);
		std::cout << "P5: " << bsp(a, b, c, point1) << std::endl;
		std::cout << "P6: " << bsp(a, b, c, point2) << std::endl;
	}
	return 0;
}
