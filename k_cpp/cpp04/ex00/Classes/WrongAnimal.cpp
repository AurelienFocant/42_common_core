#include "WrongAnimal.hpp"

#include <iostream>

WrongAnimal::WrongAnimal( void ) :
	_type("default type")
{
	std::cout << "WrongAnimal Object Constructed" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& src )
{
	this->_type = src._type;

	std::cout << "WrongAnimal Object Constructed by Copy" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=( const WrongAnimal& rhs )
{
	if (this != &rhs) {
		this->_type = rhs._type;
	}

	std::cout << "WrongAnimal Object Copied by Assignment" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "WrongAnimal Object Destroyed" << std::endl;
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout
		<< "What is this ???"
		<< std::endl;
}

std::string	WrongAnimal::getType( void ) const
{
	return (this->_type);
}
