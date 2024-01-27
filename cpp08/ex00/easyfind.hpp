#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template <typename T>
int easyFind(const T& container, int n) {
	typename T::const_iterator it = std::find(container.cbegin(), container.cend(), n);
	if (it == container.cend())
		return -1;
	return std::distance(container.cbegin(), it);
}

#endif
