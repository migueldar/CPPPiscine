#pragma once

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {
private:
	std::string _name;

public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap const& other);
	~DiamondTrap();
	DiamondTrap &operator=(DiamondTrap const& rhs);
	std::string getName() const;
	void whoAmI() const;
};

std::ostream& operator<<(std::ostream& o, DiamondTrap const& prt);
