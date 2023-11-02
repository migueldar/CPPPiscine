#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template <typename T>
int easyFind(const T& container, int n) {
	typename T::const_iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		return -1;
	return std::distance(container.begin(), it);
}

#endif
