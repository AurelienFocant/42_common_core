#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap( void ) : ClapTrap()
{
	std::cout << "ScavTrap Object Constructed" << std::endl;

	_initScavTrapStats();
}

ScavTrap::ScavTrap( const ScavTrap& src ) : ClapTrap(src)
{
	std::cout << "ScavTrap Object Constructed by Copy" << std::endl;

	*this = src;
}

ScavTrap&	ScavTrap::operator=( const ScavTrap& rhs )
{
	std::cout << "ScavTrap Object Copied by Assignment" << std::endl;

	if (this != &rhs) {
		ClapTrap::operator=(rhs);
	}
	return (*this);
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap Object Destroyed" << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
	std::cout
		<<	"ScavTrap " + name
		<<	" Object Constructed"
		<<	std::endl;

	_initScavTrapStats();
}

void	ScavTrap::attack		( const std::string& target )
{
	if (this->_energyPts > 0) {
		this->_energyPts--;
		std::cout
			<<	"Scavtrap " + this->getName()
			<<	" attacks " + target
			<<	" causing " << this->_attackDmg <<	" points of damage!"
			<<	std::endl;
	}
	else {
		std::cout << "ScavTrap " << this->getName() << " has no energy left to attack." << std::endl;
	}

}

void	ScavTrap::guardGate( void )
{
	std::cout
		<<	"ScavTrap " + this->getName() + " is now in Gate keeper mode"
		<< std::endl;
}


void	ScavTrap::_initScavTrapStats( void )
{
	this->_hitPts = 100;
	this->_energyPts = 50;
	this->_attackDmg = 20;
}
