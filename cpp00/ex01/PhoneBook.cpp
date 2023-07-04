#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): lastAdded(8) {}

int nextPosition(int currPosition) {
	if (currPosition > 7)
		return 0;
	return currPosition + 1;
}

void PhoneBook::add() {
	int position = nextPosition(lastAdded);
	std::string fN, lN, nick, ;
	std::cout << "First Name: " << std::endl;
	std::getline(std::cin, fN);

	std::cout << "Last Name" << std::endl;
	std::getline(std::cin, lN);
	std::cout << "Nickname" << std::endl;
}

void PhoneBook::search() {

}