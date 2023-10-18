#include "Dog.hpp"

Dog::Dog(): Animal("Dog"), _brain(new Brain()){
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const& other): Animal() {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
}

Dog::~Dog() {
	delete _brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(Dog const& rhs) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	_type = rhs._type;
	_brain = new Brain();
	*_brain = *(rhs._brain);
	return (*this);
}

void Dog::makeSound() const {
	std::cout << "Woof woof" << std::endl;
}

