#include "Fixed.hpp"

int main( void ) {
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}

	std::cout << std::endl << std::endl;

	{
		Fixed c(19.16f);
		Fixed d(-2);
		
		std::cout << c-- << std::endl;
		std::cout << c << std::endl;
		std::cout << --c << std::endl;
		c++;
		c++;

		std::cout << c + d << std::endl;
		std::cout << c - d << std::endl;
		std::cout << c * d << std::endl;
		std::cout << c / d << std::endl;
		std::cout << Fixed::min(c, d) << std::endl;
		std::cout << Fixed::max(c, d) << std::endl;
		std::cout << (c > d) << std::endl;
		std::cout << (c < d) << std::endl;
		std::cout << (c >= d) << std::endl;
		std::cout << (c <= d) << std::endl;
		std::cout << (c == d) << std::endl;
		std::cout << (c != d) << std::endl;
	}

	std::cout << std::endl << std::endl;
	
	{
		Fixed const e(1);
		Fixed const f(2.2f);

		std::cout << Fixed::min(e, f) << std::endl;
		std::cout << Fixed::max(e, f) << std::endl;
	}
		
	return 0;
}
