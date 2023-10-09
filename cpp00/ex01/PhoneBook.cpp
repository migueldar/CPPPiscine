#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): lastAdded(8) {}

PhoneBook::~PhoneBook() {}

int PhoneBook::nextPosition(int currPosition) {
	if (currPosition > 6) return 0;
	return currPosition + 1;
}

bool allDigits(const std::string str) {
	for (size_t i = 0; i < str.length(); ++i)
		if (!isdigit(str[i]))
			return false;
	return true;
}

bool allSpaces(const std::string str) {
	for (size_t i = 0; i < str.length(); ++i)
		if (!isspace(str[i]))
			return false;
	return true;
}

std::string substituteChar(std::string str, char from, char to) {
	for (size_t i = 0; i < str.length(); ++i) 
		if (str[i] == from)
			str[i] = to;
	return str;
}

std::string PhoneBook::askForInput(const std::string inputAsker) {
	std::string aux;

	while (aux.empty() || allSpaces(aux)) {
		std::cout << inputAsker << ": ";
		std::getline(std::cin, aux);
		if (std::cin.eof()) exit(1);
		if (aux.empty() || allSpaces(aux))
			std::cout << "Cannot be empty, try again" << std::endl;
	}
	aux = substituteChar(aux, '\t', ' ');
	return aux;
}

//handle empty with all spaces
void PhoneBook::add() {
    int position = PhoneBook::nextPosition(this->lastAdded);
	std::string fN, lN, nick, number, secret;
	
	fN = PhoneBook::askForInput("First name");
	lN = PhoneBook::askForInput("Last name");
	nick = PhoneBook::askForInput("Nickname");

	while (number.length() != 9 || !allDigits(number)) {
		number = PhoneBook::askForInput("Number");
		if (number.length() != 9 || !allDigits(number))
			std::cout << "Number should be 9 digits" << std::endl;
	}
	secret = PhoneBook::askForInput("Darkest secret");

	(this->contacts)[position] = Contact(fN, lN, nick, number, secret);
	this->lastAdded = position;
	std::cout << std::endl;
}

void PhoneBook::search() {
	if ((this->contacts)[0].getNumber().empty()) {
		std::cout << "Contacts list is empty, add a contact before using the SEARCH action" << std::endl;
		return ;
	}

	std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
	for (int i = 0; i < 8; i++) {
		std::cout << '|' << std::setw(10) << i + 1 << '|';
		std::cout << std::setw(10) << (this->contacts)[i].getTruncatedFirstName() << '|';
		std::cout << std::setw(10) << (this->contacts)[i].getTruncatedLastName() << '|';
		std::cout << std::setw(10) << (this->contacts)[i].getTruncatedNickname() << '|';
		std::cout << std::endl;
	}
	std::string index;

	while (index.length() != 1 || index[0] < '1' || index[0] > '8' || (this->contacts)[index[0] - '1'].getNumber().empty()) {
		std::cout << "Enter an index to display contact info: ";
		std::getline(std::cin, index);
		if (std::cin.eof()) exit(1);
		if (index.length() != 1 || index[0] < '1' || index[0] > '8' || (this->contacts)[index[0] - '1'].getNumber().empty())
			std::cout << "Invalid index, try again" << std::endl;
	}
	
	Contact selected = (this->contacts)[index[0] - '1'];
	std::cout << std::endl << "CONTACT INFO: " << std::endl;
	std::cout << "First name: " << selected.getFirstName() << std::endl;
	std::cout << "Second name: " << selected.getLastName() << std::endl;
	std::cout << "Nickname: " << selected.getNickname() << std::endl;
	std::cout << "Number: " << selected.getNumber() << std::endl;
	std::cout << "Darkest secret: " << selected.getSecret() << std::endl << std::endl; 
}
