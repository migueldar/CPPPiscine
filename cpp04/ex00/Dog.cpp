#include "Dog.hpp"

Dog::Dog(): Animal("Dog") {
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const& other): Animal() {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(Dog const& rhs) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	this->_type = rhs._type;
	return (*this);
}

void Dog::makeSound() const {
	std::cout << "Woof woof" << std::endl;
}

