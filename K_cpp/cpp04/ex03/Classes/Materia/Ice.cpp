#include "Ice.hpp"

#include "AMateria.hpp"
#include "ICharacter.hpp"

#include <iostream>

Ice::Ice( void ) : AMateria()
{
	std::cout << "Ice Object Constructed" << std::endl;

	_type = "ice";
}

Ice::Ice( const Ice& src ) : AMateria(src)
{
	std::cout << "Ice Object Constructed by Copy" << std::endl;

	_type = src.getType();
}

Ice&	Ice::operator=( const Ice& rhs )
{
	std::cout << "Ice Object Copied by Assignment" << std::endl;

	if (this != &rhs) {
		AMateria::operator=(rhs);
	}
	return (*this);
}

Ice::~Ice( void )
{
	std::cout << "Ice Object Destroyed" << std::endl;
}

AMateria*	Ice::clone( void ) const
{
	return (new Ice());
}

void	Ice::use( ICharacter& target )
{
	std::cout
		<< "* shoots an ice bolt at "
		<< target.getName()
		<< " *" << std::endl;
}
