#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("unnamed", 100, 100, 30, 100) {
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name, 100, 100, 30, 100) {
	std::cout << "FragTrap constructor called for " << name << std::endl;
}

FragTrap::FragTrap(FragTrap const& other): ClapTrap(other.getName(), other.getHitP(), other.getEnergyP(), other.getAttackD(), 100) {
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const& rhs) {
	this->_attackD = rhs.getAttackD();
	this->_energyP = rhs.getEnergyP();
	this->_hitP = rhs.getHitP();
	this->_name = rhs.getName();
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	return (*this);
}

std::ostream& operator<<(std::ostream& o, FragTrap const& prt) {
	o << "FragTrap " << prt.getName() << " has " << prt.getAttackD() << " ad, " << prt.getHitP() << " hp and " << prt.getEnergyP() << " energy" << std::endl;
	return (o);
}

void FragTrap::highFivesGuys() const {
	std::cout << "FragTrap " << _name << " highs five to guys" << std::endl;
}
