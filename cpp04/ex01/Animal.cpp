#include "Animal.hpp"

Animal::Animal(): _type("non-specific") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type): _type(type) {
	std::cout << "Animal string constructor called" << std::endl;
}

Animal::Animal(Animal const& other) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = other;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(Animal const& rhs) {
	std::cout << "Animal copy assignment operator called" << std::endl;
	_type = rhs._type;
	return (*this);
}

std::string const& Animal::getType() const {
	return this->_type;
}

void Animal::makeSound() const {
	std::cout << "Non-specific animal sound" << std::endl;
}

std::ostream& operator<<(std::ostream& o, Animal const& prt) {
	o << "Animal with type " << prt.getType() << std::endl;
	return (o);
}
