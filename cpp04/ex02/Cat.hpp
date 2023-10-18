#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat: public Animal {

private:
	Brain* _brain;

public:
	Cat();
	Cat(Cat const& other);
	~Cat();
	Cat &operator=(Cat const& rhs);
	void makeSound() const;
	int addIdea(std::string idea);
	Brain* getBrain() const;
};

std::ostream& operator<<(std::ostream& o, Cat const& prt);

#endif
