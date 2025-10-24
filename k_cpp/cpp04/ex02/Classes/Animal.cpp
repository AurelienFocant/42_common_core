#include "Animal.hpp"

#include <iostream>

Animal::Animal( void ) :
	_type("default type")
{
	std::cout << "Animal Object Constructed" << std::endl;
}

Animal::Animal( const Animal& src )
{
	this->_type = src._type;

	std::cout << "Animal Object Constructed by Copy" << std::endl;
}

Animal&	Animal::operator=( const Animal& rhs )
{
	if (this != &rhs) {
		this->_type = rhs._type;
	}

	std::cout << "Animal Object Copied by Assignment" << std::endl;
	return (*this);
}

Animal::~Animal( void )
{
	std::cout << "Animal Object Destroyed" << std::endl;
}

std::string	Animal::getType( void ) const
{
	return (this->_type);
}
