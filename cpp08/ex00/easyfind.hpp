#ifndef EASYFIND_HPP
#define EASYFIND_HPP

template <typename T>
int easyFind(const T& container, int N) {
	int counter = 0;

	for (typename T::const_iterator it = container.begin(); it != container.end(); it++) {
		if (*it == N)
			return counter;
		counter++;
	}
	return -1;
}

#endif
