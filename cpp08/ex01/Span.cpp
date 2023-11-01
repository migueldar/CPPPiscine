#include "Span.hpp"

Span::Span(): _maxsize(0) {}

Span::Span(unsigned int i): _maxsize(i) {}

Span::Span(Span const& other): _maxsize(other._maxsize) {
	std::cout << "Span copy constructor called" << std::endl;
	*this = other;
}

Span::~Span() {}

void Span::addNumber(int n) {
	if (_vector.size() == _maxsize)
		throw FullSpan();
	_vector.push_back(n);
}

int Span::shortestSpan() {
	if (_vector.size() <= 1)
		throw BadSpanSize();
	return 0;
}

int Span::longestSpan() {
	if (_vector.size() <= 1)
		throw BadSpanSize();
	return 0;
}

Span& Span::operator=(Span const& rhs) {
	this->_vector = rhs._vector;
	return (*this);
}

std::ostream& operator<<(std::ostream& o, Span const& prt) {
	(void) prt;
	return (o);
}
