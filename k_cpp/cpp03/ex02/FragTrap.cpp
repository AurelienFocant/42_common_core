#include "FragTrap.hpp"
#include "ClapTrap.hpp"

#include <iostream>

FragTrap::FragTrap( void ) : ClapTrap()
{
	std::cout << "FragTrap Object Constructed" << std::endl;

	this->_initFragTrapStats();
}

FragTrap::FragTrap( const FragTrap& src ) : ClapTrap(src)
{
	std::cout << "FragTrap Object Constructed by Copy" << std::endl;
}

FragTrap&	FragTrap::operator=( const FragTrap& rhs )
{
	std::cout << "FragTrap Object Copied by Assignment" << std::endl;

	if (this != &rhs) {
		ClapTrap::operator=(rhs);
	}
	return (*this);
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap Object Destroyed" << std::endl;
}


FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	std::cout
		<<	"FragTrap " + name
		<<	" Object Constructed"
		<<	std::endl;

	this->_initFragTrapStats();
}

void	FragTrap::attack		( const std::string& target )
{
	if (!this->_energyPts)
		return (this->_announceOutOfEnergy());

	this->_energyPts--;
	std::cout
		<<	"FragTrap " + this->getName()
		<<	" attacks " + target
		<<	" causing " << this->_attackDmg <<	" points of damage!"
		<<	std::endl;
}

void	FragTrap::_initFragTrapStats( void )
{
	this->_hitPts = 100;
	this->_energyPts = 100;
	this->_attackDmg = 30;
}

void	FragTrap::highFivesGuys( void )
{
	std::cout
		<<	"FragTrap " + this->getName()
		<<	" will high five you mfer!"
		<< std::endl;
}
