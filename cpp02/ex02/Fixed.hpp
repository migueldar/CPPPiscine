#pragma once

#include <iostream>
#include <cmath>
#include <ostream>

class Fixed {
private:
	int _rawBits;
	static const int _fracBits = 8;
	
public:
	Fixed();
	Fixed(int const n);
	Fixed(float const n);
	Fixed(Fixed const& other);
	~Fixed();
	
	Fixed& operator=(Fixed const& rhs);
	
	bool operator>(Fixed const& rhs);
	bool operator>=(Fixed const& rhs);
	bool operator<(Fixed const& rhs);
	bool operator<=(Fixed const& rhs);
	bool operator==(Fixed const& rhs);
	bool operator!=(Fixed const& rhs);

	Fixed operator+(Fixed const& rhs);
	Fixed operator-(Fixed const& rhs);
	Fixed operator*(Fixed const& rhs);
	Fixed operator/(Fixed const& rhs);

	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

	static Fixed& min(Fixed& lhs, Fixed& rhs);
	static Fixed const& min(Fixed const& lhs, Fixed const& rhs);
	static Fixed& max(Fixed& lhs, Fixed& rhs);
	static Fixed const& max(Fixed const& lhs, Fixed const& rhs);
	
	int getRawBits() const;
	void setRawBits(int const raw);
	float toFloat() const;
	int toInt() const;
};

std::ostream& operator<<(std::ostream& o, Fixed const& rhs);
