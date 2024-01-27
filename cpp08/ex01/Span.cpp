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

int Span::shortestSpan() const {
	if (_vector.size() <= 1)
		throw BadSpanSize();

	int ret = abs(_vector[0] - _vector[1]);
	
	for (std::vector<int>::const_iterator it = _vector.cbegin(); it < _vector.cend(); it++) {
		for (std::vector<int>::const_iterator jt = it + 1; jt < _vector.cend(); jt++) {
			if (abs(*it - *jt) < ret)
				ret = abs(*it - *jt);
		}
	}

	return ret;
}

static int vector_min(std::vector<int> vec) {
	if (vec.size() == 0)
		throw ;
	
	int min = vec[0];

	for (std::vector<int>::const_iterator it = vec.cbegin(); it < vec.cend(); it++)
		if (*it < min)
			min = *it;
	return min;
}

static int vector_max(std::vector<int> vec) {
	if (vec.size() == 0)
		throw ;

	int max = vec[0];

	for (std::vector<int>::const_iterator it = vec.cbegin(); it < vec.cend(); it++)
		if (*it > max)
			max = *it;
	return max;
}

int Span::longestSpan() const {
	if (_vector.size() <= 1)
		throw BadSpanSize();
	return vector_max(_vector) - vector_min(_vector);
}

Span& Span::operator=(Span const& rhs) {
	this->_vector = rhs._vector;
	return (*this);
}
