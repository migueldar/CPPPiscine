#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(std::string fN, std::string lN, std::string nick, std::string nbr, std::string sec): firstName(fN), lastName(lN), nickname(nick), number(nbr), secret(sec) {}

Contact::~Contact() {}

std::string Contact::truncate(std::string str) {
	if (str.length() <= 10)
		return str;
	std::string ret;
	for (int i = 0; i < 9; i++)
		ret.push_back(str[i]);
	ret.push_back('.');
	return ret;
}

std::string Contact::getTruncatedFirstName() {
	return Contact::truncate(this->firstName);
}

std::string Contact::getTruncatedLastName() {
	return Contact::truncate(this->lastName);
}

std::string Contact::getTruncatedNickname() {
	return Contact::truncate(this->nickname);
}

std::string Contact::getFirstName() {
	return this->firstName;
}

std::string Contact::getLastName() {
	return this->lastName;
}

std::string Contact::getNickname() {
	return this->nickname;
}

std::string Contact::getNumber() {
	return this->number;
}

std::string Contact::getSecret() {
	return this->secret;
}