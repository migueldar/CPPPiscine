#include "Zombie.hpp"

void randomChump(std::string name) {
	Zombie random = Zombie(name);
	random.announce();
}