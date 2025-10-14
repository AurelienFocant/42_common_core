#include "WrongCat.hpp"

#include "WrongAnimal.hpp"

#include <iostream>

WrongCat::WrongCat( void ) : WrongAnimal()
{
	this->_type = "WrongCat";

	std::cout << "WrongCat Object Constructed" << std::endl;
}

WrongCat::WrongCat( const WrongCat& src ) : WrongAnimal(src)
{
	std::cout << "WrongCat Object Constructed by Copy" << std::endl;
}

WrongCat&	WrongCat::operator=( const WrongCat& rhs )
{
	if (this != &rhs) {
		this->WrongAnimal::operator=(rhs);
	}
	std::cout << "WrongCat Object Copied by Assignment" << std::endl;
	return (*this);
}

WrongCat::~WrongCat( void )
{
	std::cout << "WrongCat Object Destroyed" << std::endl;
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "Meuuuuh" << std::endl;
}
