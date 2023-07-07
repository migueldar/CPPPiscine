#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): lastAdded(8) {}

int PhoneBook::nextPosition(int currPosition) {
	if (currPosition > 7) return 0;
	return currPosition + 1;
}

std::string PhoneBook::askForInput(const std::string inputAsker) {
	std::string aux;

	while (aux.empty()) {
		std::cout << inputAsker << ": ";
		std::getline(std::cin, aux);
		if (std::cin.eof()) exit(1);
		if (aux.empty())
			std::cout << inputAsker << " cannot be empty, try again" << std::endl;
	}
	return aux;
}

void PhoneBook::add() {
    int position = PhoneBook::nextPosition(lastAdded);
	std::string fN, lN, nick, numberStr, secret;
	
	fN = PhoneBook::askForInput("First name");
	lN = PhoneBook::askForInput("Last name");
	nick = PhoneBook::askForInput("Nickname");
	//check if its a number (and has 9 digits)

	while (numberStr.length() != 9)
		numberStr = PhoneBook::askForInput("Number");
		
	secret = PhoneBook::askForInput("Darkest secret");

	(this->contacts)[position] = Contact(fN, lN, nick, std::stoi(numberStr), secret);
}

void PhoneBook::search() {
	std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
	for (int i = 0; i < 8; i++) {
		std::cout << '|' << std::setw(10) << i + 1 << '|';
		std::cout << std::setw(10) << (this->contacts)[i].getTruncatedFirstName() << '|';
		std::cout << std::setw(10) << (this->contacts)[i].getTruncatedLastName() << '|';
		std::cout << std::setw(10) << (this->contacts)[i].getTruncatedNickname() << '|';
		std::cout << std::endl;
	}
}
