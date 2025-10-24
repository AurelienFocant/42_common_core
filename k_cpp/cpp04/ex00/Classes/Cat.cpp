#include "Cat.hpp"

#include "Animal.hpp"

#include <iostream>

Cat::Cat( void ) : Animal()
{
	this->_type = "Cat";

	std::cout << "Cat Object Constructed" << std::endl;
}

Cat::Cat( const Cat& src ) : Animal(src)
{
	std::cout << "Cat Object Constructed by Copy" << std::endl;
}

Cat&	Cat::operator=( const Cat& rhs )
{
	if (this != &rhs) {
		this->Animal::operator=(rhs);
	}
	std::cout << "Cat Object Copied by Assignment" << std::endl;
	return (*this);
}

Cat::~Cat( void )
{
	std::cout << "Cat Object Destroyed" << std::endl;
}

void	Cat::makeSound( void ) const
{
	std::cout << "Miiaow" << std::endl;
}
