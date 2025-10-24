#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap( void ) :
	_name("defaultName"),
	_hitPts(10),
	_energyPts(10),
	_attackDmg(0)
{
	std::cout << "ClapTrap Object Constructed" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& src )
{
	std::cout << "ClapTrap Object Constructed by Copy" << std::endl;

	if (this != &src) {
		this->_name = src._name;
		this->_hitPts = src._hitPts;
		this->_energyPts = src._energyPts;
		this->_attackDmg = src._attackDmg;
	}
}

ClapTrap&	ClapTrap::operator=( const ClapTrap& rhs )
{
	std::cout << "ClapTrap Object copied by Assignment" << std::endl;

	this->_name = rhs._name;
	this->_hitPts = rhs._hitPts;
	this->_energyPts = rhs._energyPts;
	this->_attackDmg = rhs._attackDmg;
	return (*this);
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap Object Destroyed" << std::endl;
}


ClapTrap::ClapTrap( std::string name) :
	_name(name),
	_hitPts(10),
	_energyPts(10),
	_attackDmg(0)
{
	std::cout
		<< "ClapTrap " + name
		<< " Object Constructed"
		<< std::endl;
}

std::string	ClapTrap::getName( void ) const
{
	return (this->_name);
}

void		ClapTrap::setName( std::string name )
{
	this->_name = name;
}


void	ClapTrap::attack( const std::string& target )
{
	if (!this->_energyPts)
		return (this->_announceOutOfEnergy());

	this->_energyPts--;
	std::cout
		<<	"ClapTrap " + this->_name
		<<	" attacks " + target
		<<	" causing " << this->_attackDmg <<	" points of damage!"
		<<	std::endl;
}

void	ClapTrap::takeDamage	( unsigned int amount )
{
	if (amount > static_cast<unsigned int>(this->_hitPts))
		amount = this->_hitPts;
	this->_hitPts -= amount;

	std::cout
		<<	this->_name + " took "
		<<	amount	<<	"damage"
		<<	std::endl;

	if (!this->_hitPts)
		this->_announceIsDead();
}

void	ClapTrap::beRepaired	( unsigned int amount )
{
	if (this->_energyPts > 0) {
		this->_energyPts--;
		this->_hitPts += amount;
	}
}

void	ClapTrap::_announceIsDead( void )
{
	std::cout
		<< this->getName() + " is already dead!"
		<< std::endl;
}

void	ClapTrap::_announceOutOfEnergy( void )
{
	std::cout
		<< this->getName() + " is out of energy!"
		<< std::endl;
}
