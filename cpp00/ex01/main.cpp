#include "PhoneBook.hpp"
#include <iostream>
#include <istream>
#include <string>

int main() {
	PhoneBook pb = PhoneBook();
	std::string action;

	std::cout << "WELCOME TO YOUR FAVOURITE PHONEBOOK" << std::endl;
	while (!std::cin.eof() && action != "EXIT")
	{
		std::cout << "WHAT ACTION WOULD YOU LIKE TO DO? [ADD | SEARCH | EXIT]: ";
		input a = std::getline(std::cin, action); 

		if (std::cin.eof())
		{
			std::cin.clear();
			std::cin.ignore();
			continue;
		}
		if (action == "ADD")
			pb.add();
		else if (action == "SEARCH")
			pb.search();
		else if (action != "EXIT")
		{
			//std::cin.clear();
			std::cout << "INVALID ACTION" << std::endl;
		}
	}
	
	return 0;
}