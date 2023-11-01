#include <vector>
#include <list>
#include <iostream>
#include "easyfind.hpp"

int main() {
	{
		std::vector<int> v(1, 1);
		std::cout << easyFind(v, 2) << std::endl;
	}

	{
		std::list<int> l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);
		l.push_back(4);
		l.push_back(5);
		std::cout << easyFind(l, 3) << std::endl;
	}

	{
		std::list<int> l;
		std::cout << easyFind(l, 3) << std::endl;
	}
}