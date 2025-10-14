#include "AMateria.hpp"
#include "ICharacter.hpp"

#include <iostream>

AMateria::AMateria( void )
{
	std::cout << "AMateria Object Constructed" << std::endl;

	_type = "default_type";
}

AMateria::AMateria( const AMateria& src )
{
	std::cout << "AMateria Object Constructed by Copy" << std::endl;

	_type = src._type;
}

AMateria&	AMateria::operator=( const AMateria& rhs )
{
	std::cout << "AMateria Object Copied by Assignment" << std::endl;

	if (this != &rhs) {
	}
	return (*this);
}

AMateria::~AMateria( void )
{
	std::cout << "AMateria Object Destroyed" << std::endl;
}

AMateria::AMateria( std::string const & type)
{
	std::cout << "AMateria Object Constructed with type" << std::endl;

	_type = type;
}

std::string const &	AMateria::getType() const
{
	return (_type);
}

void	AMateria::use( ICharacter& target )
{
	std::cout
		<< "Default Materia::use() should never be triggered, even on "
		<< target.getName()
		<< std::endl;
}
