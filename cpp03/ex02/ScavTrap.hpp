#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {

public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const& other);
	~ScavTrap();
	ScavTrap &operator=(ScavTrap const& rhs);
	void attack(std::string const& target);
	void guardGate() const;
};

std::ostream& operator<<(std::ostream& o, ScavTrap const& prt);
