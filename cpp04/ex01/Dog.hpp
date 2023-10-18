#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog: public Animal {

private:
	Brain* _brain;

public:
	Dog();
	Dog(Dog const& other);
	~Dog();
	Dog &operator=(Dog const& rhs);
	void makeSound() const;
	int addIdea(std::string idea);
	Brain* getBrain() const;
};

std::ostream& operator<<(std::ostream& o, Dog const& prt);

#endif
