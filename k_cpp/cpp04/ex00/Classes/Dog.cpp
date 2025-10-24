#include "Dog.hpp"

#include "Animal.hpp"

#include <iostream>

Dog::Dog( void ) : Animal()
{
	this->_type = "Dog";

	std::cout << "Dog Object Constructed" << std::endl;
}

Dog::Dog( const Dog& src ) : Animal(src)
{
	std::cout << "Dog Object Constructed by Copy" << std::endl;
}

Dog&	Dog::operator=( const Dog& rhs )
{
	if (this != &rhs) {
		this->Animal::operator=(rhs);
	}
	std::cout << "Dog Object Copied by Assignment" << std::endl;
	return (*this);
}

Dog::~Dog( void )
{
	std::cout << "Dog Object Destroyed" << std::endl;
}

void	Dog::makeSound( void ) const
{
	std::cout << "Woof" << std::endl;
}
