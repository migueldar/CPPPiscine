#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {

protected:
	std::string _type;

public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(WrongAnimal const& other);
	virtual ~WrongAnimal();
	WrongAnimal &operator=(WrongAnimal const& rhs);
	std::string const& getType() const;
	void makeSound() const;
};

std::ostream& operator<<(std::ostream& o, WrongAnimal const& prt);

#endif