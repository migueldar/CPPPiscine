#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack: public std::stack<T> {

private:

public:
	typedef typename std::deque<T>::iterator iterator;

	MutantStack(): std::stack<T>() {};

	MutantStack(MutantStack<T> const& other) {
		*this = other;
	};

	~MutantStack() {};

	MutantStack &operator=(MutantStack<T> const& rhs) {
		this->std::stack<T>::operator=(rhs);
		return *this;
	};
	
	iterator begin() {
		return (this->c.begin());
	}

	iterator end() {
		return (this->c.end());;
	}
};

#endif
