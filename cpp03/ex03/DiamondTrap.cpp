#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("unnamed_clap_name", 100, 50, 30, 100), _name("unnamed") {
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name", 100, 50, 30, 100), _name(name) {
	std::cout << "DiamondTrap constructor called for " << name << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const& other): ClapTrap(other.ClapTrap::getName(), other.getHitP(), other.getEnergyP(), other.getAttackD(), 100), ScavTrap(), FragTrap(), _name(other.getName()) {
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& rhs) {
	this->_attackD = rhs.getAttackD();
	this->_energyP = rhs.getEnergyP();
	this->_hitP = rhs.getHitP();
	_name = rhs.getName();
	ClapTrap::_name = rhs.ClapTrap::getName();
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	return (*this);
}

std::string DiamondTrap::getName() const { return _name; }

std::ostream& operator<<(std::ostream& o, DiamondTrap const& prt) {
	o << "DiamondTrap " << prt.getName() << "(" << prt.ClapTrap::getName() << ") has " << prt.getAttackD() << " ad, " << prt.getHitP() << " hp and " << prt.getEnergyP() << " energy" << std::endl;
	return (o);
}

void DiamondTrap::whoAmI() const {
	std::cout << "DiamondTrap name is: " << _name << ", ClapTrap name is: " << ClapTrap::_name <<  std::endl;
}
