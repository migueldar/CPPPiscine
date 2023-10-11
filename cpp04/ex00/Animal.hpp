#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {

protected:
	std::string _type;

public:
	Animal();
	Animal(std::string type);
	Animal(Animal const& other);
	virtual ~Animal();
	Animal &operator=(Animal const& rhs);
	std::string const& getType() const;
	virtual void makeSound() const;
};

std::ostream& operator<<(std::ostream& o, Animal const& prt);

#endif