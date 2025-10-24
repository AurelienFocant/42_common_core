#include "DiamondTrap.hpp"

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include <iostream>

DiamondTrap::DiamondTrap( void ) :
	_name("defaultDiamondName")
{
	this->_initDiamondTrapStats();

	std::cout << "DiamondTrap Object Constructed" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap& src ) :
	ClapTrap(src),
	ScavTrap(src),
	FragTrap(src)
{
	this->_name = src.getName();

	std::cout << "DiamondTrap Object Constructed by Copy" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=( const DiamondTrap& rhs )
{
	std::cout << "DiamondTrap Object Copied by Assignment" << std::endl;

	if (this != &rhs) {
		ClapTrap::operator=(rhs);
		this->_name = rhs.getName();
	}
	return (*this);
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap Object Destroyed" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) :
	ClapTrap(name + "_clap_name"),
	ScavTrap(name),
	FragTrap(name),
	_name(name)
{
	this->_initDiamondTrapStats();

	std::cout << "DiamondTrap Object Constructed with a name" << std::endl;
}

void	DiamondTrap::attack (const std::string& target )
{
	ScavTrap::attack(target);
}

std::string	DiamondTrap::getName( void ) const
{
	return (this->_name);
}

void	DiamondTrap::whoAmI( void ) const
{
	std::cout
		<< "My name is " + this->getName()
		<< " but my ClapTrap name is " + this->ClapTrap::getName()
		<< std::endl;
}

void	DiamondTrap::_initDiamondTrapStats( void )
{
	this->_hitPts = FragTrap::_hitPts;
	this->_energyPts = ScavTrap::_energyPts;
	this->_attackDmg = FragTrap::_attackDmg;
}
