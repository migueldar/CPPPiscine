#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("unnamed"), _hitP(10), _energyP(10), _attackD(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitP(10), _energyP(10), _attackD(0) {
	std::cout << "ClapTrap constructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& other) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const& rhs) {
	this->_attackD = rhs.getAttackD();
	this->_energyP = rhs.getEnergyP();
	this->_hitP = rhs.getHitP();
	this->_name = rhs.getName();
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	return (*this);
}

std::ostream& operator<<(std::ostream& o, ClapTrap const& prt) {
	o << "ClapTrap " << prt.getName() << " has " << prt.getAttackD() << " ad, " << prt.getHitP() << " hp and " << prt.getEnergyP() << " energy" << std::endl;
	return (o);
}

std::string ClapTrap::getName() const { return _name; }

unsigned int ClapTrap::getHitP() const { return _hitP; }

unsigned int ClapTrap::getEnergyP() const { return _energyP; }

unsigned int ClapTrap::getAttackD() const { return _attackD; }

void ClapTrap::attack(std::string const& target) {
	if (!_hitP)
		std::cout << "ClapTrap " << _name << " cant attack, its dead"  << std::endl;
	else if (!_energyP)
		std::cout << "ClapTrap " << _name << " cant attack, not enough energy points"  << std::endl;
	else {
		_energyP--;
		std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attackD << " points of damage" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (amount > _hitP)
		amount = _hitP;
        
	if (!_hitP)
		std::cout << "ClapTrap " << _name << " cant take damage, its dead" << std::endl;
	else {
		_hitP -= amount;	
		std::cout << "ClapTrap " << _name << " takes " << amount << " damage, " << _hitP << " health reamining" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (amount > 10 - _hitP)
		amount = 10 - _hitP;
        
	if (!_hitP)
		std::cout << "ClapTrap " << _name << " cant be repaired, its dead"  << std::endl;
	else if (!_energyP)
		std::cout << "ClapTrap " << _name << " cant be repaired, not enough energy points"  << std::endl;
	else if (_hitP == 10)
		std::cout << "ClapTrap " << _name << " cant be repaired, already at full health"  << std::endl;
	else {
		_hitP += amount;
		_energyP--;
		std::cout << "ClapTrap " << _name << " repairs " << amount << " hit points, " << _hitP << " health remaining" << std::endl;
	}
}

