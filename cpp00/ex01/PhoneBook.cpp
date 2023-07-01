#include "PhoneBook.hpp"
#include <string>

int nextPosition(int currPosition) {
	if (currPosition > 7)
		return 0;
	return currPosition + 1;
}

void PhoneBook::add () {
	// int position = nextPosition(lastAdded);
	// std::string a;
	// int x;
	std::cout << "First Name: " << std::endl;
	// std::getline(std::cin, a);
	// std::cin >> a;
	// std::cout << a << std::endl;
}

void PhoneBook::search () {
	std::cout << "SEARC" << std::endl;
}