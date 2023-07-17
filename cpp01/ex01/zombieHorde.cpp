#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
	Zombie* horde = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		std::cout << i << std::endl;
		horde[i] = Zombie(name);
		std::cout << "paris" << std::endl;
	}

	int i = 0;
	for (int j = 0; j < 999999999; j++)
		i += j;

	return horde;
}
