#pragma once

#include <iostream>

typedef unsigned int	uint;

class ClapTrap {

protected:
	std::string _name;
	uint _hitP;
	uint _energyP;
	uint _attackD;
	uint const _maxhp;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const& other);
	ClapTrap(std::string name, uint hp, uint ep, uint ad, uint maxhp);
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
