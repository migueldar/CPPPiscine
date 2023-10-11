#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("non-specific") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): _type(type) {
	std::cout << "WrongAnimal string constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& other) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = other;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const& rhs) {
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	this->_type = rhs._type;
	return (*this);
}

std::string const& WrongAnimal::getType() const {
	return this->_type;
}

void WrongAnimal::makeSound() const {
	std::cout << "Non-specific Wronganimal sound" << std::endl;
}

std::ostream& operator<<(std::ostream& o, WrongAnimal const& prt) {
	o << "WrongAnimal with type " << prt.getType() << std::endl;
	return (o);
}
