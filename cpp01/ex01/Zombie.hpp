#pragma once

#include <iostream>

class Zombie {
	private:
		std::string _name;

	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void announce();
		void setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);