#pragma once

#include <iostream>
#include <istream>
#include <string>
#include "Contact.hpp"

class PhoneBook {
	private:
		Contact	contacts[8];
		int		lastAdded;

	public:
		PhoneBook();
		void add();
		void search();
};
