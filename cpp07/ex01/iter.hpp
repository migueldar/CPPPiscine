#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void	print(T a) {
	std::cout << a << std::endl;
}

template <typename T, typename U>
void	iter(T* array, unsigned int len, U (*func)(T)) {
	for (unsigned int i = 0; i < len; i++) {
		func(array[i]);
	}
}

#endif
