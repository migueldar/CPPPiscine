#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;  
}

Fixed::Fixed(int const n) {
	std::cout << "Int constructor called" << std::endl;
	_rawBits = n << _fracBits;
}

Fixed::Fixed(float const n) {
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(n * (1 << _fracBits));
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
	this->_rawBits = rhs._rawBits;
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

float Fixed::toFloat() const { return (float)_rawBits / (1 << _fracBits); }

int Fixed::toInt() const { return _rawBits >> _fracBits; }

std::ostream& operator<<(std::ostream& o, Fixed const& rhs) {
    o << rhs.toFloat();
	return o;
}
