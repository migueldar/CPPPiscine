#pragma once

#include <iostream>

class ClapTrap {

private:
	std::string _name;
	unsigned int _hitP;
	unsigned int _energyP;
	unsigned int _attackD;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const& other);
	~ClapTrap();
	ClapTrap &operator=(ClapTrap const& rhs);
	std::string getName() const;
	unsigned int getHitP() const;
	unsigned int getEnergyP() const;
	unsigned int getAttackD() const;
	void attack(std::string const& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

std::ostream& operator<<(std::ostream& o, ClapTrap const& prt);
