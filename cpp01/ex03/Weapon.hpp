#include <iostream>

#pragma once

class Weapon {
	private:
		std::string _type;

	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();
		void announce();
};