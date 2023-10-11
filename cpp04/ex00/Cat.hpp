#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat: public Animal {

public:
	Cat();
	Cat(Cat const& other);
	~Cat();
	Cat &operator=(Cat const& rhs);
	void makeSound() const;
};

#endif