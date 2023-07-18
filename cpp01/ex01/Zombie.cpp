#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "Zombie" << " createz" << std::endl;
}

Zombie::Zombie(std::string name): _name(name) {
	std::cout << "Zombie " << name << " createz" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "Zombie " << _name << " deztroyed" << std::endl;
}

void Zombie::setName(std::string name) {
	_name = name;
}

void Zombie::announce() {
	std::cout << _name << ": BraiiiiiiinnnzzzZ" << std::endl;
}