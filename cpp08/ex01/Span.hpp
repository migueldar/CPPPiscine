#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span {

private:
	std::vector<int>	_vector;
	const unsigned int	_maxsize;
	Span();
	Span &operator=(Span const& rhs);

	class BadSpanSize: public std::exception {
		virtual const char* what() const throw() {
			return "Span only has 0 or 1 elements";
		}
	};

	class FullSpan: public std::exception {
		virtual const char* what() const throw() {
			return "Span is full";
		}
	};

public:
	Span(unsigned int counter);
	Span(Span const& other);
	~Span();

	int shortestSpan() const;
	int longestSpan() const;
	void addNumber(int n);

	template <typename T>
	void addNumbers(T begin, T end) {
		while (begin < end) {
			this->addNumber(*begin);
			begin++;
		}
	};
};

#endif
