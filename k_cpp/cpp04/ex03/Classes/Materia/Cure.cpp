#include "Cure.hpp"

#include "AMateria.hpp"
#include "ICharacter.hpp"

#include <iostream>

Cure::Cure( void ) : AMateria()
{
	std::cout << "Cure Object Constructed" << std::endl;

	_type = "cure";
}

Cure::Cure( const Cure& src ) : AMateria(src)
{
	std::cout << "Cure Object Constructed by Copy" << std::endl;

	_type = src.getType();
}

Cure&	Cure::operator=( const Cure& rhs )
{
	std::cout << "Cure Object Copied by Assignment" << std::endl;

	if (this != &rhs) {
		AMateria::operator=(rhs);
	}
	return (*this);
}

Cure::~Cure( void )
{
	std::cout << "Cure Object Destroyed" << std::endl;
}

AMateria*	Cure::clone( void ) const
{
	return (new Cure());
}

void	Cure::use( ICharacter& target )
{
	std::cout
		<< "* heals "
		<< target.getName()
		<< "'s wounds *" << std::endl;
}
