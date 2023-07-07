#pragma once

#include <string>
#include <iostream>
#include <iomanip>

class Contact {
	private:
		std::string		firstName;
		std::string		lastName;
		std::string		nickname;
		int				number;
		std::string		secret;
		static std::string truncate(std::string str);

	public:
		Contact();
		Contact(std::string fN, std::string lN, std::string nick, int nbr, std::string sec);
		~Contact();
		std::string getTruncatedFirstName();
		std::string getTruncatedLastName();
		std::string getTruncatedNickname();
};