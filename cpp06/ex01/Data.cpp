#include "Data.hpp"

Data::Data(): _a(0), _b(1) {
	std::cout << "Data default constructor called" << std::endl;
}

Data::Data(Data const& other): _a(0), _b(1)  {
	std::cout << "Data copy constructor called" << std::endl;
	*this = other;
}

Data::~Data() {
	std::cout << "Data destructor called" << std::endl;
}

Data& Data::operator=(Data const& rhs) {
	_a = rhs._a;
	_b = rhs._b;

	std::cout << "Data copy assignment operator called" << std::endl;
	return (*this);
}

int Data::getA() const {
	return _a;
}

int Data::getB() const {
	return _b;
}

void Data::setA(int n) {
	_a = n;
}

void Data::setB(int n) {
	_b = n;
}

std::ostream& operator<<(std::ostream& o, Data const& prt) {
	o << prt.getA() << ", " << prt.getB();
	return (o);
}
