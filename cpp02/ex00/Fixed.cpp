#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;  
}

Fixed::Fixed(Fixed const& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_rawBits = rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return _rawBits;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_rawBits = raw;
}
