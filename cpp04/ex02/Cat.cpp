#include "Cat.hpp"

Cat::Cat(): Animal("Cat"), _brain(new Brain()) {
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(Cat const& other): Animal(), _brain(new Brain()) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = other;
}

Cat::~Cat() {
	delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(Cat const& rhs) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	_type = rhs._type;
	*_brain = *(rhs._brain);
	return (*this);
}

void Cat::makeSound() const {
	std::cout << "Meooooow" << std::endl;
}

int Cat::addIdea(std::string idea) {
	return _brain->addIdea(idea);
}

Brain* Cat::getBrain() const {
	return _brain;
}

std::ostream& operator<<(std::ostream& o, Cat const& prt) {
	o << "Cat's " << *(prt.getBrain()) << std::endl;
	return (o);
}
