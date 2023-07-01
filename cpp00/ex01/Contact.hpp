#pragma once

#include <string>

class Contact {
	public:
		std::string		firstName;
		std::string		lastName;
		std::string		nickname;
		long long int	number;
		std::string		secret;

		Contact() {}
		Contact(std::string firstName, std::string lastName, std::string nickname, long long int number, std::string secret) {
			this->firstName = firstName;
			this->lastName = lastName;
			this->nickname = nickname;
			this->number = number;
			this->secret = secret;
		}
};