#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstdlib>

template <typename T>
class Array {

private:
	T*				_arr;
	unsigned int	_len;

	class InvalidIndexException: public std::exception {
		virtual const char* what() const throw() {
			return "invalid index";
		}
	};

public:
	Array(): _arr(NULL), _len(0) {
		std::cout << "Array default constructor called" << std::endl;
	};
	Array(unsigned int len): _arr(new T[len]), _len(len) {
		std::cout << "Array params constructor called" << std::endl;
	};
	Array(Array const& other) {
		std::cout << "Array copy constructor called" << std::endl;
		*this = other;
	};
	~Array() {
		std::cout << "Array destructor called" << std::endl;
		delete[] _arr;
	};

	T& operator[](std::size_t idx) {
		if ((unsigned int) idx < _len)
			return _arr[idx];
		throw Array::InvalidIndexException();
	};

	Array& operator=(Array const& rhs) { 
		std::cout << "Array assignment operator called" << std::endl;
		_arr = new T[rhs._len];
		for (unsigned int i = 0; i < rhs._len; i++)
			_arr[i] = rhs._arr[i];
		_len = rhs._len;
		return (*this);
	};

	unsigned int size() const { return _len; }
};

#endif
