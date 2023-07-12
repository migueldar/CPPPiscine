#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>

class Contact {
	private:
		std::string		firstName;
		std::string		lastName;
		std::string		nickname;
		std::string		number;
		std::string		secret;
		static std::string truncate(std::string str);

	public:
		Contact();
		Contact(std::string fN, std::string lN, std::string nick, std::string nbr, std::string sec);
		~Contact();
		std::string getTruncatedFirstName();
		std::string getTruncatedLastName();
		std::string getTruncatedNickname();
		std::string getFirstName();
		std::string getLastName();
		std::string getNickname();
		std::string getNumber();
		std::string getSecret();
};