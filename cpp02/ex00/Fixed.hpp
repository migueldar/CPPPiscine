#pragma once

#include <iostream>

class Fixed {
private:
	int _rawBits;
	static const int _fracBits = 8;
	
public:
	Fixed();
	Fixed(Fixed const& other);
	~Fixed();
	Fixed& operator=(Fixed const& rhs);
	int getRawBits() const;
	void setRawBits(int const raw);
};
