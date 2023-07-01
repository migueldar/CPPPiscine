#pragma once

#include <iostream>
#include "Contact.hpp"

class PhoneBook {
	private:
		Contact	contacts[8];
		bool 	full;
		int		lastAdded;
	public:
		PhoneBook() {
			full = false;
			lastAdded = 8;
		}

		void add();
		void search();
};
