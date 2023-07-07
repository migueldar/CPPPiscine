#pragma once

#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook {
	private:
		Contact	contacts[8];
		int	lastAdded;
		static std::string askForInput(const std::string inputAsker);
        static int nextPosition(int currPosition);

	public:
		PhoneBook();
		void add();
		void search();
};
