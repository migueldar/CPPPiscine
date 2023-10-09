#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap {

public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(FragTrap const& other);
	~FragTrap();
	FragTrap &operator=(FragTrap const& rhs);
	void highFivesGuys() const;
};

std::ostream& operator<<(std::ostream& o, FragTrap const& prt);
