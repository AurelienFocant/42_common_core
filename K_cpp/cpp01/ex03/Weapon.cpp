#include "Weapon.hpp"

#include <iostream>

Weapon::Weapon( void ) : _type("generic weapon")
{
	std::cout << "Generic Weapon constructor" << std::endl;
}

Weapon::Weapon(std::string type) : _type(type)
{
	std::cout << this->getType() << " Weapon constructor" << std::endl;
}

Weapon::~Weapon( void )
{
	std::cout << "Weapon destroyed" << std::endl;
}

void	Weapon::setType( std::string type )
{
	this->_type = type;
}

std::string const &	Weapon::getType( void ) const
{
	return (this->_type);
}
