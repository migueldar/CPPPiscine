#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("unnamed", 100, 50, 20, 100) {
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name, 100, 50, 20, 100) {
	std::cout << "ScavTrap constructor called for " << name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& other): ClapTrap(other.getName(), other.getHitP(), other.getEnergyP(), other.getAttackD(), 100) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const& rhs) {
	this->_attackD = rhs.getAttackD();
	this->_energyP = rhs.getEnergyP();
	this->_hitP = rhs.getHitP();
	this->_name = rhs.getName();
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	return (*this);
}

std::ostream& operator<<(std::ostream& o, ScavTrap const& prt) {
	o << "ScavTrap " << prt.getName() << " has " << prt.getAttackD() << " ad, " << prt.getHitP() << " hp and " << prt.getEnergyP() << " energy" << std::endl;
	return (o);
}

void ScavTrap::attack(std::string const& target) {
	if (!_hitP)
		std::cout << "ScavTrap " << _name << " cant attack, its dead"  << std::endl;
	else if (!_energyP)
		std::cout << "ScavTrap " << _name << " cant attack, not enough energy points"  << std::endl;
	else {
		_energyP--;
		std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _attackD << " points of damage" << std::endl;
	}
}

void ScavTrap::guardGate() const {
	std::cout << "ScavTrap " << _name << " is now in gate keeper mode" << std::endl;
}
