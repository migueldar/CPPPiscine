#pragma once

#include <string>
#include <iostream>
#include <iomanip>

class Contact {
	private:
		std::string		firstName;
		std::string		lastName;
		std::string		nickname;
		long long int	number;
		std::string		secret;
		
	public:
		Contact();
		Contact(std::string fN, std::string lN, std::string nick, long long int nbr, std::string sec);
		~Contact();
};