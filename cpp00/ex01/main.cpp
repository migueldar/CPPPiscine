#include "PhoneBook.hpp"

int main() {
	PhoneBook pb = PhoneBook();
	std::string action;

	std::cout << "WELCOME TO YOUR FAVOURITE PHONEBOOK" << std::endl;
	while (action != "EXIT")
	{
		std::cout << "WHAT ACTION WOULD YOU LIKE TO DO? [ADD | SEARCH | EXIT]: ";
		std::getline(std::cin, action); 

		if (std::cin.eof())
			return 1;
		if (action == "ADD")
			pb.add();
		else if (action == "SEARCH")
			pb.search();
		else if (action != "EXIT")
			std::cout << "INVALID ACTION" << std::endl;
	}
	return 0;
}
